/**
 * @file description
 * @version 0.3.0
 * @author Valerie Burzynski <vburzynski@adayana.com>
 * @author Amanda Palla <apalla@adayana.com>
 * @history 2007.03.26 - JEM - Initial version
 * @history 2007.08.24 - JEM/ALP - Updated per move to iframes.
 * @history 2010.07.06 - ALP - Modified to work with Plateau LMS for DIA courses
 * @history 2010.07.?? - ALP - Modified to allow tracking of page visits via cmi.suspend_data
 * @history 2010.10.08 - ALP - Modified to allow tracking of scored activities via cmi.suspend_data
 * @history 2011.01.07 - VRB - Initial modifications that allowed page loading to be delegated
 * @history 2012.05.22 - VRB - Rewritten Version: placed into namespace, switched to pipwerks SCORM API Wrapper
 * @history 2013.01.XX - ALP - Initial modifications for the JKO mLearning Suite
 * @history 2013.02.15 - VRB - Further modifications for the JKO mLearning Suite
 * @history 2013.09.19 - VRB - Placed into AMD Shim and significant restructuring of code
 * @history 2013.09.19 - VRB - Refactored code so SCORM now only handles retrieving and sending SCO data to/from the LMS
 */

// FIXME - this code prevents further attempts to set completion status in some verions of iOS m-learning; This is an M-Learning Bug
//TODO - needs testing with latest iOS MLearning App.

// In previous versions (JIPS Mobile) we ended up only being able to save completion status once.
// Subsequent attempts to change the completion status would fail.

/**
 * Plugin
 * @module adayana/shell/plugins/SCORM
 */
define(function (require) {
    'use strict';

    var $ = require('jquery'),
        detect = require('adayana/utilities/detect'),
        pipwerks = require('pipwerks');

    // Default settings for SCORM Plugin
    var defaults = {
        version: "2004", // Specify the SCORM version "1.2" or "2004"
        isPPS: false, // SCO is deployed to the Adayana Project Presentation System
        isJKOMobile: false, // SCO is deployed to the JKO Mobile learning LMS
        isAgile: false, // (unimplemented) SCO is deployed on Agile
        isPlateau: false, // (unimplemented) SCO is deployed on Plateau
        isMoodle: false // (unimplemented) SCO is deployed on Moodle
    };

    // Data Model Reference: http://scorm.com/scorm-explained/technical-scorm/run-time/run-time-reference/

    // SCORM 2004 Data Model
    var model2004 = {
        completion: "cmi.completion_status", // (“completed”, “incomplete”, “not attempted”, “unknown”, RW) Indicates whether the learner has completed the SCO
        success: "cmi.success_status", // (“passed”, “failed”, “unknown”, RW) Indicates whether the learner has mastered the SCO 
        userid: "cmi.learner_id", // (long_identifier_type (SPM: 4000), RO) Identifies the learner on behalf of whom the SCO was launched
        username: "cmi.learner_name", // (localized_string_type (SPM: 250), RO) Name provided for the learner by the LMS
        data: "cmi.suspend_data", // (characterstring (SPM: 64000), RW) Provides space to store and retrieve data between learner sessions
        location: "cmi.location", // (characterstring (SPM: 1000), RW) The learner’s current location in the SCO
        exit: "cmi.exit", // (timeout, suspend, logout, normal, “”, WO) Indicates how or why the learner left the SCO)
        entry: "cmi.entry", // (ab_initio, resume, “”, RO) Asserts whether the learner has previously accessed the SCO
        credit: "cmi.credit", // (“credit”, “no-credit”, RO) Indicates whether the learner will be credited for performance in the SCO
        time: "cmi.total_time", // (timeinterval (second,10,2), RO) Sum of all of the learner’s session times accumulated in the current learner attempt
        score: "cmi.score.raw", // (real (10,7), RW) Number that reflects the performance of the learner relative to the range bounded by the values of min and max
        scoremax: "cmi.score.max", // (real (10,7), RW) Maximum value in the range for the raw score
        scoremin: "cmi.score.min" // (real (10,7), RW) Minimum value in the range for the raw score

        // other run-time data model stuff:

        // cmi._version                                   (characterstring, RO) Represents the version of the data model
        // cmi.completion_threshold                       (real(10,7) range (0..1), RO) Used to determine whether the SCO should be considered complete
        // cmi.launch_data                                (characterstring (SPM: 4000), RO) Data provided to a SCO after launch, initialized from the dataFromLMS manifest element
        // cmi.max_time_allowed                           (timeinterval (second,10,2), RO) Amount of accumulated time the learner is allowed to use a SCO
        // cmi.mode                                       (“browse”, “normal”, “review”, RO) Identifies one of three possible modes in which the SCO may be presented to the learner
        // cmi.progress_measure                           (real (10,7) range (0..1), RW) Measure of the progress the learner has made toward completing the SCO
        // cmi.scaled_passing_score                       (real(10,7) range (-1 .. 1), RO) Scaled passing score required to master the SCO
        // cmi.score._children                            (scaled,raw,min,max, RO) Listing of supported data model elements
        // cmi.score.scaled                               (real (10,7) range (-1..1), RW) Number that reflects the performance of the learner
        // cmi.session_time                               (timeinterval (second,10,2), WO) Amount of time that the learner has spent in the current learner session for this SCO
        // cmi.time_limit_action                          (“exit,message”, “continue,message”, “exit,no message”, “continue,no message”, RO) Indicates what the SCO should do when cmi.max_time_allowed is exceeded        

        // cmi.comments_from_learner._children            (comment,location,timestamp, RO) Listing of supported data model elements
        // cmi.comments_from_learner._count               (non-negative integer, RO) Current number of learner comments
        // cmi.comments_from_learner.n.comment            (localized_string_type (SPM: 4000), RW) Textual input
        // cmi.comments_from_learner.n.location           (characterstring (SPM: 250), RW) Point in the SCO to which the comment applies
        // cmi.comments_from_learner.n.timestamp          (time (second,10,0), RW) Point in time at which the comment was created or most recently changed
        // cmi.comments_from_lms._children                (comment,location,timestamp, RO) Listing of supported data model elements
        // cmi.comments_from_lms._count                   (non-negative integer, RO) Current number of comments from the LMS
        // cmi.comments_from_lms.n.comment                (localized_string_type (SPM: 4000), RO) Comments or annotations associated with a SCO
        // cmi.comments_from_lms.n.location               (characterstring (SPM: 250), RO) Point in the SCO to which the comment applies
        // cmi.comments_from_lms.n.timestamp              (time(second,10,0), RO) Point in time at which the comment was created or most recently changed

        // cmi.interactions._children                     (id,type,objectives,timestamp,correct_responses,weighting,learner_response,result,latency,description, RO) Listing of supported data model elements
        // cmi.interactions._count                        (non-negative integer, RO) Current number of interactions being stored by the LMS
        // cmi.interactions.n.id                          (long_identifier_type (SPM: 4000), RW) Unique label for the interaction
        // cmi.interactions.n.type                        (“true-false”, “choice”, “fill-in”, “long-fill-in”, “matching”, “performance”, “sequencing”, “likert”, “numeric” or “other”, RW) Which type of interaction is recorded
        // cmi.interactions.n.objectives._count           (non-negative integer, RO) Current number of objectives (i.e., objective identifiers) being stored by the LMS for this interaction
        // cmi.interactions.n.objectives.n.id             (long_identifier_type (SPM: 4000), RW) Label for objectives associated with the interaction
        // cmi.interactions.n.timestamp                   (time(second,10,0), RW) Point in time at which the interaction was first made available to the learner for learner interaction and response
        // cmi.interactions.n.correct_responses._count    (non-negative integer, RO) Current number of correct responses being stored by the LMS for this interaction
        // cmi.interactions.n.correct_responses.n.pattern (format depends on interaction type, RW) One correct response pattern for the interaction
        // cmi.interactions.n.weighting                   (real (10,7), RW) Weight given to the interaction relative to other interactions
        // cmi.interactions.n.learner_response            (format depends on interaction type, RW) Data generated when a learner responds to an interaction
        // cmi.interactions.n.result                      (“correct”, “incorrect”, “unanticipated”, “neutral”) or a real number with values that is accurate to seven significant decimal figures real. , RW) Judgment of the correctness of the learner response
        // cmi.interactions.n.latency                     (timeinterval (second,10,2), RW) Time elapsed between the time the interaction was made available to the learner for response and the time of the first response
        // cmi.interactions.n.description                 (localized_string_type (SPM: 250), RW) Brief informative description of the interaction

        // cmi.learner_preference._children               (audio_level,language,delivery_speed,audio_captioning, RO) Listing of supported data model elements
        // cmi.learner_preference.audio_level             (real(10,7), range (0..*), RW) Specifies an intended change in perceived audio level
        // cmi.learner_preference.language                (language_type (SPM 250), RW) The learner’s preferred language for SCOs with multilingual capability
        // cmi.learner_preference.delivery_speed          (real(10,7), range (0..*), RW) The learner’s preferred relative speed of content delivery
        // cmi.learner_preference.audio_captioning        (“-1″, “0″, “1″, RW) Specifies whether captioning text corresponding to audio is displayed

        // cmi.objectives._children                       (id,score,success_status,completion_status,description, RO) Listing of supported data model elements
        // cmi.objectives._count                          (non-negative integer, RO) Current number of objectives being stored by the LMS
        // cmi.objectives.n.id                            (long_identifier_type (SPM: 4000), RW) Unique label for the objective
        // cmi.objectives.n.score._children               (scaled,raw,min,max, RO) Listing of supported data model elements
        // cmi.objectives.n.score.scaled                  (real (10,7) range (-1..1), RW) Number that reflects the performance of the learner for the objective
        // cmi.objectives.n.score.raw                     (real (10,7), RW) Number that reflects the performance of the learner, for the objective, relative to the range bounded by the values of min and max
        // cmi.objectives.n.score.min                     (real (10,7), RW) Minimum value, for the objective, in the range for the raw score
        // cmi.objectives.n.score.max                     (real (10,7), RW) Maximum value, for the objective, in the range for the raw score
        // cmi.objectives.n.success_status                (“passed”, “failed”, “unknown”, RW) Indicates whether the learner has mastered the objective
        // cmi.objectives.n.completion_status             (“completed”, “incomplete”, “not attempted”, “unknown”, RW) Indicates whether the learner has completed the associated objective
        // cmi.objectives.n.progress_measure              (real (10,7) range (0..1), RW) Measure of the progress the learner has made toward completing the objective
        // cmi.objectives.n.description                   (localized_string_type (SPM: 250), RW) Provides a brief informative description of the objective

        // adl.nav.request                                (request(continue, previous, choice, jump, exit, exitAll, abandon, abandonAll, suspendAll _none_), RW) Navigation request to be processed immediately following Terminate()
        // adl.nav.request_valid.continue                 (state (true, false, unknown), RO) Used by a SCO to determine if a Continue navigation request will succeed.
        // adl.nav.request_valid.previous                 (state (true, false, unknown), RO) Used by a SCO to determine if a Previous navigation request will succeed.
        // adl.nav.request_valid.choice.{target=}         (state (true, false, unknown), RO) Used by a SCO to determine if a Choice navigation request for the target activity will succeed.
        // adl.nav.request_valid.jump.{target=}           (state (true, false, unknown), RO) Used by a SCO to determine if a Jump navigation request for the target activity will succeed.
    };

    // SCORM 1.2 Data Model
    var model1_2 = {
        completion: "cmi.core.lesson_status", // (“passed”, “completed”, “failed”, “incomplete”, “browsed”, “not attempted”, RW) Indicates whether the learner has completed and satisfied the requirements for the SCO
        success: "cmi.core.lesson_status", // (“passed”, “completed”, “failed”, “incomplete”, “browsed”, “not attempted”, RW) Indicates whether the learner has completed and satisfied the requirements for the SCO
        username: "cmi.core.student_name", // (CMIString (SPM: 255), RO) Name provided for the student by the LMS
        data: "cmi.suspend_data", // (CMIString (SPM: 4096), RW) Provides space to store and retrieve data between learner sessions
        location: "cmi.core.lesson_location", // (CMIString (SPM: 255), RW) The learner’s current location in the SCO
        exit: "cmi.core.exit", // (“time-out”, “suspend”, “logout”, “”, WO) Indicates how or why the learner left the SCO
        credit: "cmi.core.credit", // (“credit”, “no-credit”, RO) Indicates whether the learner will be credited for performance in the SCO
        time: "cmi.core.total_time", // (CMITimespan, RO) Sum of all of the learner’s session times accumulated in the current learner attempt
        score: "cmi.core.score.raw", // (CMIDecimal, RW) Number that reflects the performance of the learner relative to the range bounded by the values of min and max
        scoremin: "cmi.core.score.min", // (CMIDecimal, RW) Minimum value in the range for the raw score
        scoremax: "cmi.core.score.max", // (CMIDecimal, RW) Maximum value in the range for the raw score
        // not used ...
        userid: "cmi.core.student_id", // (CMIString (SPM: 255), RO) Identifies the student on behalf of whom the SCO was launched
        entry: "cmi.core.entry" // (“ab-initio”, “resume”, “”, RO) Asserts whether the learner has previously accessed the SCO                

        // other run-time data model stuff:
        // cmi.core._children                             (student_id, student_name, lesson_location, credit, lesson_status, entry, score, total_time, lesson_mode, exit, session_time, RO) Listing of supported data model elements
        // cmi.core.score_children                        (raw,min,max, RO) Listing of supported data model elements
        // cmi.core.lesson_mode                           (“browse”, “normal”, “review”, RO) Identifies one of three possible modes in which the SCO may be presented to the learner
        // cmi.core.session_time                          (CMITimespan, WO) Amount of time that the learner has spent in the current learner session for this SCO
        // cmi.launch_data                                (CMIString (SPM: 4096), RO) Data provided to a SCO after launch, initialized from the dataFromLMS manifest element
        // cmi.comments                                   (CMIString (SPM: 4096), RW) Textual input from the learner about the SCO
        // cmi.comments_from_lms                          (CMIString (SPM: 4096), RO) Comments or annotations associated with a SCO

        // cmi.objectives._children                       (id,score,status, RO) Listing of supported data model elements
        // cmi.objectives._count                          (non-negative integer, RO) Current number of objectives being stored by the LMS
        // cmi.objectives.n.id                            (CMIIdentifier, RW) Unique label for the objective
        // cmi.objectives.n.score._children               (raw,min,max, RO) Listing of supported data model elements
        // cmi.objectives.n.score.raw                     (CMIDecimal, RW) Number that reflects the performance of the learner, for the objective, relative to the range bounded by the values of min and max
        // cmi.objectives.n.score.max                     (CMIDecimal, Rw) Maximum value, for the objective, in the range for the raw score
        // cmi.objectives.n.score.min                     (CMIDecimal, RW) Minimum value, for the objective, in the range for the raw score
        // cmi.objectives.n.status                        (“passed”, “completed”, “failed”, “incomplete”, “browsed”, “not attempted”, RW) Indicates whether the learner has completed or satisfied the objective

        // cmi.student_data._children                     (mastery_score, max_time_allowed, time_limit_action, RO) Listing of supported data model elements
        // cmi.student_data.mastery_score                 (CMIDecimal, RO) Passing score required to master the SCO
        // cmi.student_data.max_time_allowed              (CMITimespan, RO) Amount of accumulated time the learner is allowed to use a SCO
        // cmi.student_data.time_limit_action             (exit,message,” “exit,no message”,” continue,message”, “continue, no message”, RO) Indicates what the SCO should do when max_time_allowed is exceeded

        // cmi.student_preference._children               (audio,language,speed,text, RO) Listing of supported data model elements
        // cmi.student_preference.audio                   (CMISInteger, RW) Specifies an intended change in perceived audio level
        // cmi.student_preference.language                (CMIString (SPM: 255), RW) The student’s preferred language for SCOs with multilingual capability
        // cmi.student_preference.speed                   (CMISInteger, RW) The learner’s preferred relative speed of content delivery
        // cmi.student_preference.text                    (CMISInteger, RW) Specifies whether captioning text corresponding to audio is displayed

        // cmi.interactions._children                     (id,objectives,time,type,correct_responses,weighting,student_response,result,latency, RO) Listing of supported data model elements
        // cmi.interactions._count                        (CMIInteger, RO) Current number of interactions being stored by the LMS
        // cmi.interactions.n.id                          (CMIIdentifier, WO) Unique label for the interaction
        // cmi.interactions.n.objectives._count           (CMIInteger, RO) Current number of objectives (i.e., objective identifiers) being stored by the LMS for this interaction
        // cmi.interactions.n.objectives.n.id             (CMIIdentifier, WO) Label for objectives associated with the interaction
        // cmi.interactions.n.time                        (CMITime, WO) Point in time at which the interaction was first made available to the student for student interaction and response
        // cmi.interactions.n.type                        (“true-false”, “choice”, “fill-in”, “matching”, “performance”, “sequencing”, “likert”, “numeric”, WO) Which type of interaction is recorded
        // cmi.interactions.n.correct_responses._count    (CMIInteger, RO) Current number of correct responses being stored by the LMS for this interaction
        // cmi.interactions.n.correct_responses.n.pattern (format depends on interaction type, WO) One correct response pattern for the interaction
        // cmi.interactions.n.weighting                   (CMIDecimal, WO) Weight given to the interaction relative to other interactions
        // cmi.interactions.n.student_response            (format depends on interaction type, WO) Data generated when a student responds to an interaction
        // cmi.interactions.n.result                      (“correct”, “wrong”, “unanticipated”, “neutral”, “x.x [CMIDecimal]“, WO) Judgment of the correctness of the learner response
        // cmi.interactions.n.latency                     (CMITimespan, WO) Time elapsed between the time the interaction was made available to the learner for response and the time of the first response
    };

    // -- Helper Functions --

    /**
     * Pad digits
     */
    function padDigits(n, totalDigits) {
        n = n.toString();
        var i, pd = '';
        if (totalDigits > n.length) {
            for (i = 0; i < (totalDigits - n.length); i++) {
                pd += '0';
            }
        }
        return pd + n.toString();
    }

    /**
     * Retrive a value from M-Learning
     */
    function getMLearning(key, defer) {
        try {
            console.log('attempting to retrieve ' + key);
            console.log('calling window.plugins.clientPlugin.getValue();');
            window.plugins.clientPlugin.getValue(MFStoreType.SPECIFIC, key, function (value) {
                console.log('retrieved ' + key + ': ' + value);
                defer.resolve(key, value);
            });
        } catch (e) {
            console.log('there was an error trying to retrive ' + key + ' from M-Learning\n' + e);
            alert('there was an error trying to retrive ' + key + ' from M-Learning\n' + e);
        }
    }

    /**
     * Set a value in M-Learning
     */
    function setMLearning(key, value, defer) {
        try {
            console.log('attempting to set ' + key + ' to ' + value);
            console.log('calling window.plugins.clientPlugin.setValue();');
            window.plugins.clientPlugin.setValue(MFStoreType.SPECIFIC, key, value, function () {
                console.log('successfully set ' + key + ' to ' + value);
                defer.resolve();
            });
        } catch (e) {
            console.log('there was an error trying to save the ' + key + ' to M-Learning\n' + e);
            alert('there was an error trying to save ' + key + ' to M-Learning\n' + e);
        }
    }

    /**
     * Forces an M-Learning Sync
     */
    function syncToMlearning(defer) {
        try {
            // stop timer (CTIP does this);
            console.log('calling window.plugins.clientPlugin.terminate(); (stops timer)');
            window.plugins.clientPlugin.terminate();

            // Force M-Learning synchronization
            console.log('attempting window.plugins.clientPlugin.sync()');
            window.plugins.clientPlugin.sync(function () {
                console.log('sync method successfully called');
                defer.resolve();
            });
        } catch (e) {
            console.log("there was an error trying to sync to M-Learning\n" + e);
            alert("there was an error trying to sync to M-Learning\n" + e);
        }
    }

    /**
     * Generate a sessiont time for cmi.core.session_time
     * @history 2007.03.26 JEM - Adapted from Army SCORM Best Practices.
     * @history 2013.09.19 VRB - Modified to just generate the session time
     */
    function generateSessionTime(startTime, endTime) {
        var calculatedTime = endTime - startTime;
        // get hour string
        var totalHours = Math.floor(calculatedTime / 1000 / 60 / 60);
        calculatedTime = calculatedTime - totalHours * 1000 * 60 * 60;
        totalHours = padDigits(totalHours, 4);
        // get minute string
        var totalMinutes = Math.floor(calculatedTime / 1000 / 60);
        calculatedTime = calculatedTime - totalMinutes * 1000 * 60;
        totalMinutes = padDigits(totalMinutes, 2);
        // get second string
        var totalSeconds = Math.floor(calculatedTime / 1000);
        totalSeconds = padDigits(totalSeconds, 2);
        // get time string
        var sessionTime = totalHours + ":" + totalMinutes + ":" + totalSeconds;
        return sessionTime;
    }

    /**
     * Return whether the completion status is valid for the scorm version
     * @history 2013.09.19 - VRB - modified for 2004 and 1.2 values
     */
    function validCompletionStatus(status, version) {
        if (version === "1.2") {
            // 1.2   = “passed”, “completed”, “failed”, “incomplete”, “browsed”, “not attempted”
            return (status === 'passed' || status === 'completed' || status === 'failed' || status === 'incomplete' || status === 'browsed' || status === 'not attempted');
        } else {
            // 2004  = “completed”, “incomplete”, “not attempted”, “unknown”
            return (status === 'completed' || status === 'incomplete' || status === 'not attempted' || status === 'unknown');
        }
    }

    /**
     * Given a potential cmi.core.exit value, return whether it is an acceptable value.
     * @history 2007.03.26 - JEM - Initial version
     * @history 2012.05.22 - VRB - modified for namespace vesion
     * @history 2013.09.19 - VRB - modified for 2004 and 1.2 values
     */
    function validExitValue(value, version) {
        // 1.2  cmi.core.exit (“time-out”, “suspend”, “logout”, “”, WO)
        if (version === "1.2") {
            return (value === 'time-out' || value === 'suspend' || value === 'logout' || value === '');
        } else {
            // 2004 cmi.exit (timeout, suspend, logout, normal, “”, WO)
            return (value === 'timeout' || value === 'suspend' || value === 'logout' || value === 'normal' || value === '');
        }
    }

    /**
     * Return whether the success status is valid for the scorm version
     */
    function validSuccessStatus(status, version) {
        // 1.2  = “passed”, “completed”, “failed”, “incomplete”, “browsed”, “not attempted”
        if (version === "1.2") {
            return (status === 'passed' || status === 'completed' || status === 'failed' || status === 'incomplete' || status === 'browsed' || status === 'not attempted');
        } else {
            // 2004 = “passed”, “failed”, “unknown”
            return (status === 'passed' || status === 'failed' || status === 'unknown');
        }
    }

    /**
     * SCORM Plugin for communicating with an LMS
     * @constructor
     */
    var SCORM = function (options) {
        // merge options and defaults into settings
        this.settings = $.extend({}, defaults, options);

        // Set the SCORM version in the SCORM API
        pipwerks.SCORM.version = this.settings.version;
        // when on JKO M-Learning, force 2004 model
        if (this.settings.isJKOMobile) {
            this.settings.version = "2004";
        }

        this.isStandalone = (this.settings.isPPS) ? true : detect.isStandalone;
        this.isConnected = false;
        this.completion = 'not attempted';
        this.model = (this.settings.version === '2004') ? model2004 : model1_2;
        this.success = (this.settings.version === '2004') ? 'incomplete' : 'unknown';
        this.username = '';
        this.location = '';
        this.credit = 'credit';
        this.startTime = new Date().getTime();
        this.score = 0;
        this.scoreMin = 0;
        this.scoreMax = 0;
    };

    // Inherit
    SCORM.prototype = {};
    SCORM.prototype.constructor = SCORM;

    // extend prototype with new/overwritten methods
    $.extend(SCORM.prototype, {

        /**
         * Start the SCORM interface
         */
        start: function () {
            if (this.isStandalone) {
                // do nothing
                return;
            } else {
                var defer = $.Deferred();
                // initialize connection
                if (this.settings.isJKOMobile) {
                    this.isConnected = true;
                    var deferProxy = $.proxy(defer.resolve, this);
                    window.plugins.clientPlugin.initialize(deferProxy);
                } else {
                    this.isConnected = pipwerks.SCORM.init();
                    defer.resolve();
                }
                // connect to LMS, and when connected load data
                defer.promise().done($.proxy(this._loadData, this));
            }
        },

        /**
         * Load Data from the LMS if connected
         */
        _loadData: function () {
            // FIXME - When Tribal fixes the iOS Bug, we can retrieve initial completion status... (remove first if statement and code within)
            if (this.settings.isJKOMobile) {
                this.completion = 'not started';
                this.success = 'unknown';
                this.username = '';
                this.location = '';
                window.setTimeout($.proxy(this._processData, this), 1);
                return;
            }
            // when Connected, get all the appropriate data from the LMS
            if (this.isConnected) {
                // every get method returns a jquery promise object, push into an array
                // http://stackoverflow.com/questions/9926624/jquery-javascript-nested-asynchronous-functions-callback
                // http://api.jquery.com/category/deferred-object/
                var promiseArr = [];
                promiseArr.push(this._getLMS(this.model.completion, 'completion', true));
                promiseArr.push(this._getLMS(this.model.success, 'success', true));
                promiseArr.push(this._getLMS(this.model.username, 'username', true));
                promiseArr.push(this._getLMS(this.model.location, 'location', true));
                // when every promise reports it is done, process the data...
                var completeFn = $.proxy(this._processData, this);
                $.when.apply($, promiseArr).done(function () {
                    completeFn();
                });
            }
        },

        /**
         * Process the data from the LMS.
         */
        _processData: function () {
            // when not attempted or status is invalid
            if (this.completion === 'not attempted' || !validCompletionStatus(this.completion, this.settings.version)) {
                // FIXME - When Tribal fixes the iOS Bug, we can save initial completion status...
                //TODO - test setting the initial completion status on MLearning.
                // -- Old Version of iOS App would mess up if you saved more than once
                if (!this.settings.isJKOMobile) {
                    this.setCompletion('incomplete').done($.proxy(function () {
                        this.save();
                    }, this));
                }
            } else if (this.completion === 'complete' || this.completion === 'passed') {
                // when course was completed or passed last time
            } else if (this.completion === 'incomplete') {
                // when resuming an incomplete course
                //TODO - set
                //TODO - implement method of returning to bookmarked location
                /*
                 var lastpage = getLessonLocation();// pipwerks.SCORM.get returns an object rather than a string, so we add "" to make this var a string.
                 console.log('last page: ' + lastpage );
                 if ( lastpage !== undefined && lastpage !== "null" && lastpage !== "" && lastpage.length > 0  ) {
                 if (lastpage !== startingPage) { // don't prompt if that's where they're going, anyway
                 if ( promptGoToBookmark(lastpage) ) {
                 goToPageInDirectory(lastpage);
                 atDestination = true;
                 }
                 }
                 }
                 //...
                 if (!atDestination) {
                 goToPageInDirectory(startingPage);
                 }
                 */
            }
        },

        getSuspendData: function (callback) {
            if (this.isConnected) {
                var defer = $.Deferred();
                if (this.settings.isJKOMobile) {
                    var deferProxy = $.proxy(defer.resolve, this);
                    getMLearning(this.model.data, deferProxy);
                } else {
                    var str = pipwerks.SCORM.get(this.model.data);
                    if (str === "" || str === "undefined" || str === "null") {
                        defer.resolve('');
                    } else {
                        defer.resolve(str);
                    }
                }
                defer.promise().done(function (str) {
                    callback(str);
                });
            } else {
                callback(null);
            }
        },

        /**
         * retrieve the completion status
         */
        getCompletion: function () {
            return this._getLMS(this.model.completion, 'completion', true);
        },

        /**
         * Retrieve the success status from the LMS
         */
        getSuccess: function () {
            return this._getLMS(this.model.success, 'success', true);
        },

        /**
         * Retrieve the User's name or pin from the LMS
         */
        getUser: function () {
            return this._getLMS(this.model.username, 'username', true);
        },

        /**
         * Get last known location
         */
        getLocation: function () {
            return this._getLMS(this.model.location, 'location', true);
        },

        /**
         * Get last known location
         */
        getExit: function () {
            return this._getLMS(this.model.exit, 'exitValue', false);
        },

        /**
         * Retreive whether the course is being take for credit
         */
        getCredit: function () {
            return this._getLMS(this.model.credit, 'credit', false);
        },

        setSuspendData: function (str, callback) {
            if (this.isConnected) {
                /*
                 Character Limits for Suspend_Data:
                 SCORM 1.2                4,096
                 SCORM 2004 2nd Edition   4,000
                 SCORM 2004 3rd Edition  64,000
                 SCORM 2004 4th Edition  64,000
                 */
                if ((this.settings.version === '1.2' && str.length > 4096) && (this.settings.version === '2004' && str.length > 64000)) {
                    throw ('Error! Attempted to store too much save data.');
                }
                this._setLMS(this.model.data, null, str).done(function () {
                    if (callback) {
                        callback();
                    }
                });
            } else if (callback) {
                callback();
            }
        },

        /**
         * Set Score Value in LMS.
         * @param {Number|String} [score] - uses value passed in if defined, otherwise uses value already stored in SCORM instance
         */
        setScore: function (value) {
            if (value) {
                return this._setLMS(this.model.score, 'score', value);
            } else {
                return this._setLMS(this.model.score, null, this.score);
            }
        },

        setScoreMin: function (value) {
            if (value) {
                return this._setLMS(this.model.scoremin, 'scoreMin', value);
            } else {
                return this._setLMS(this.model.scoremin, null, this.scoreMin);
            }
        },

        setScoreMax: function (value) {
            if (value) {
                return this._setLMS(this.model.scoremax, 'scoreMax', value);
            } else {
                return this._setLMS(this.model.scoremax, null, this.scoreMax);
            }
        },

        /**
         * Set Completion Value
         * @param {Object} value
         */
        setCompletion: function (value) {
            if (value) {
                return this._setLMS(this.model.completion, 'completion', value);
            } else {
                return this._setLMS(this.model.completion, null, this.completion);
            }
        },

        /**
         * Set Success Status
         */
        setSuccess: function (value) {
            if (value) {
                return this._setLMS(this.model.success, 'success', value);
            } else {
                return this._setLMS(this.model.success, null, this.success);
            }
        },

        setLocation: function (value) {
            if (value) {
                return this._setLMS(this.model.location, 'location', value);
            } else {
                return this._setLMS(this.model.location, null, this.location);
            }
        },

        setExit: function (value) {
            if (value) {
                return this._setLMS(this.model.exit, 'exitStatus', value);
            } else {
                return this._setLMS(this.model.exit, null, this.exitStatus);
            }
        },

        /**
         * Suspend SCO
         */
        suspend: function () {
            if (this.isConnected) {
                // save the current location
                this.setLocation().done($.proxy(function () {
                    // set the exit status to suspend
                    this.setExit('suspend').done($.proxy(function () {
                        this.save();
                    }, this));
                }, this));
            }
        },

        /**
         * Bookmark SCO's location
         */
        bookmark: function (location) {
            if (this.isConnected) {
                // set the location location
                this.setLocation(location).done($.proxy(function () {
                    // set the exit status to suspend
                    this.setExit('suspend').done($.proxy(function () {
                        // SCORM save
                        this.save();
                    }, this));
                }, this));
            }
        },

        getBookmark: function (callback) {
            return this.location;
        },

        /**
         * Set the SCO's completion status to completed/passed
         * @history 2007.08.27  JEM - Initial version.
         * @history 2010.07.06  ALP - Updated to set status to "passed" to work with Plateau LMS
         * @history 2013.09.19  VRB - Implemented credit check to determine if passed or complete should be sent
         */
        recordCompletion: function (callback) {
            if (this.isConnected) {
                // SCORM 2004
                if (this.settings.version === "2004") {
                    this.setCompletion('completed').done($.proxy(function () {
                        this.setSuccess('passed').done($.proxy(function () {
                            this.save().done($.proxy(function () {
                                if (callback) {
                                    callback();
                                }
                            }, this));
                        }, this));
                    }, this));
                } else {
                    // otherwise when on SCORM 1.2
                    if (this.credit === "credit") {
                        this.setCompletion('passed').done($.proxy(function () {
                            this.save().done($.proxy(function () {
                                if (callback) {
                                    callback();
                                }
                            }, this));
                        }, this));
                    } else {
                        this.setCompletion('completed').done($.proxy(function () {
                            this.save().done($.proxy(function () {
                                if (callback) {
                                    callback();
                                }
                            }, this));
                        }, this));
                    }
                }
            }
        },

        /**
         * Set the completion status to incomplete/failed
         */
        recordFail: function (callback) {
            if (this.isConnected) {
                // SCORM 2004
                if (this.settings.version === "2004") {
                    this.setCompletion('incomplete').done($.proxy(function () {
                        this.setSuccess('failed').done($.proxy(function () {
                            this.save().done($.proxy(function () {
                                if (callback) {
                                    callback();
                                }
                            }, this));
                        }, this));
                    }, this));
                } else {
                    // otherwise when on SCORM 1.2
                    if (this.credit === "credit") {
                        this.setCompletion('failed').done($.proxy(function () {
                            this.save().done($.proxy(function () {
                                if (callback) {
                                    callback();
                                }
                            }, this));
                        }, this));
                    } else {
                        this.setCompletion('incomplete').done($.proxy(function () {
                            this.save().done($.proxy(function () {
                                if (callback) {
                                    callback();
                                }
                            }, this));
                        }, this));
                    }
                }
            }
        },

        /**
         * Record the current time
         */
        recordTime: function () {
            if (this.isConnected && !this.settings.isJKOMobile) {
                var timeStr = generateSessionTime(this.startTime, new Date().getTime());
                pipwerks.SCORM.set(this.model.time, timeStr);
                pipwerks.SCORM.save();
            }
        },

        /**
         * Record the current course location
         */
        recordLocation: function (str) {
            if (this.isConnected && !this.settings.isJKOMobile) {
                pipwerks.SCORM.set(this.model.location, str);
                pipwerks.SCORM.save();
            }
        },

        /**
         * record the score
         */
        recordScore: function (value, min, max, callback) {
            if (this.isConnected) {
                this.setScore(value).done($.proxy(function () {
                    this.setScoreMin(min).done($.proxy(function () {
                        this.setScoreMax(max).done($.proxy(function () {
                            this.save().done($.proxy(function () {
                                if (callback) {
                                    callback();
                                }
                            }, this));
                        }, this));
                    }, this));
                }, this));
            }
        },

        /**
         * Sync SCORM LMS Data
         */
        save: function () {
            var defer = $.Deferred();
            if (this.settings.isJKOMobile) {
                syncToMlearning(defer);
            } else {
                pipwerks.SCORM.save();
                defer.resolve();
            }
            return defer.promise();
        },

        /**
         * Sync SCORM LMS Data
         */
        sync: function () {
            return this.save();
        },

        /**
         * Quit SCO
         */
        quit: function () {
            if (this.isConnected) {
                if ((this.completion !== 'completed') && (this.completion !== 'passed') && (this.completion !== 'failed')) {
                    this.completion = 'incomplete';
                    this.setCompletion().done($.proxy(function () {
                        this.save().done($.proxy(function () {
                            if (!this.settings.isJKOMobile) {
                                pipwerks.SCORM.quit();
                            }
                        }, this));
                    }, this));
                } else {
                    this.save().done($.proxy(function () {
                        if (!this.settings.isJKOMobile) {
                            pipwerks.SCORM.quit();
                        }
                    }, this));
                }
            }
        },

        /**
         * Retrieve some key on the lms
         * @param   {String}  lmsKey           lms key
         * @param   {String}  varName          name
         * @param   {Boolean} getFromMLearning when true, retrieve value from m-learning lms
         * @returns {Object}  jQuery Promise Object
         */
        _getLMS: function (lmsKey, varName, getFromMLearning) {
            var defer = $.Deferred();
            if (this.settings.isJKOMobile) {
                if (getFromMLearning) {
                    var deferProxy = $.proxy(defer.resolve, this);
                    getMLearning(lmsKey, deferProxy);
                } else {
                    defer.resolve('', null);
                }
            } else {
                defer.resolve(varName, pipwerks.SCORM.get(lmsKey));
            }
            defer.done($.proxy(function (key, value) {
                if (key && key !== '') {
                    this[key] = value;
                }
            }, this));

            return defer.promise();
        },

        /**
         * Set some key on the lms to the passed in value
         * @param {String}  lmsKey - scorm key to store value to on LMS
         * @param {String}  varName - name of local var to set
         * @param {Object}  value - value to set/store
         * @param {Boolean} sendToMLearning - when true, value is sent to m-Learning
         * @returns {Object}  jQuery Promise Object
         */
        _setLMS: function (lmsKey, varName, value, sendToMLearning) {
            if (varName) {
                this[varName] = value;
            }
            var defer = $.Deferred();
            if (this.settings.isJKOMobile) {
                if (sendToMLearning) {
                    var deferProxy = $.proxy(defer.resolve, this);
                    setMLearning(lmsKey, value, deferProxy);
                }
            } else {
                pipwerks.SCORM.set(lmsKey, value);
                defer.resolve();
            }
            return defer.promise();
        }
    });

    return SCORM;
});

// JKO Mobile Learning Notes:
// window.clientPlugin.getValue( type, key, value, callback );
// window.clientPlugin.setValue( type, key, value, callback );
// window.clientPlugin.openMenuItem( menuItemId, callback );                    // as named in the package’s package.xml file
// window.clientPlugin.openResource( resourceId, callback );                    // as named in the package’s package.xml file
// window.clientPlugin.getUsername( callback );
// window.clientPlugin.track( info, callback );                                 // info is a string;
// window.clientPlugin.sync( callback );                                        // force a sync
// window.clientPlugin.initialize( callback );                                  // start timer or set to 0
// window.clientPlugin.terminate( callback );                                   // stop the timer if running
// window.clientPlugin.getCurrentCourseLocalPathRoot (callback, errorCallback)
// window.clientPlugin.initalizeCurrentCourseLocalTempFolder (callbacak, errorCallback)
// window.clientPlugin.clearCurrentCourseLocalTempFolder(callback, errorCallback)
// cmi.completion_status
// cmi.success_status
// cmi.total_time
// cmi.suspend_data