define(function(require){
    // dependencies
    var aden = require('adayana/aden/engine');
    var _S   = require('adayana/utilities/string');
        
    // module
    var clock = aden.clock = aden.clock || {};
    
    /**
     * Array of Months
     * @name month
     */
    var month = [];
        month[0]  = "January";
        month[1]  = "February";
        month[2]  = "March";
        month[3]  = "April";
        month[4]  = "May";
        month[5]  = "June";
        month[6]  = "July";
        month[7]  = "August";
        month[8]  = "September";
        month[9]  = "October";
        month[10] = "November";
        month[11] = "December";
    
    /**
     * Array of Week Days
     * @name weekday
     */
    var weekday = [];
        weekday[0]  = "Sunday";
        weekday[1]  = "Monday";
        weekday[2]  = "Tuesday";
        weekday[3]  = "Wednesday";
        weekday[4]  = "Thursday";
        weekday[5]  = "Friday";
        weekday[6]  = "Saturday";
    
    /**
     * Boolean indicating whether the clock was paused the last time the engine was paused 
     */
    var _wasClockPaused = true;
    var _resetsOnLevel  = false;
    
    /**
     * initializes the engine module
     * @param {Object} mediator - an instance of the Mediator.js object
     */
    clock.initialize = function( mediator ) {
        this.mediator = mediator;
        this.mediator.subscribe('msg:engine:init', this.onInit, null, this);
        
        this._subUpdate = this.mediator.subscribe('msg:engine:update', this.onUpdate, null, this);
        this._subLoad   = this.mediator.subscribe('msg:engine:load',   this.onLoad,   null, this);
        this._subReset = this.mediator.subscribe('msg:engine:reset',  this.onReset,  null, this);
        this._subPause  = this.mediator.subscribe('msg:engine:pause',  this.onPause,  null, this );
        this._subResume = this.mediator.subscribe('msg:engine:resume', this.onResume, null, this);
    };
    
    /**
     * Perform additional initialization of the module after the Adventure Engine has been 
     * initialized. 
     */
    clock.onInit = function( data ) {
        var settings = data.settings.modules.clock;
        _resetsOnLevel = settings.resetsOnLevel;
        this.speed     = settings.speed; // current speed
        this.lastSpeed = settings.speed; // Previous speed used
        this.baseSpeed = settings.speed; // Base or default speed
        
        this.timeEl = $('.aden-time-game');
        this.elapsedEl = $('.aden-time-elapsed');
        this.ranEl = $('.aden-time-ran');
    };
    
    /**
     * Perform the necessary initialization whenever a new level is loaded 
     */
    clock.onLoad = function( levelData ) {
        if ( _resetsOnLevel ) {
            if ( 'state' in levelData && 'modules' in levelData.state && 'clock' in levelData.state.modules ) {
                this.setState(levelData.state.modules.clock);
            }
        }
    };
    
    /**
     * Set the state of the clock 
     */
    clock.setState = function( state ) {        
        // set/reset clock data object
        this.prevRealTime = 0;        // The engine's total elapsed time on the last clock cycle
        this.time         = 0;        // Time Number
        this.isRunning    = false;    // is clock running
        this.isPaused     = false;    // is clock paused
        
        var now = new Date();
        // create a date object using today's date at time 00:00:00.000
        this.date  = new Date(now.getFullYear(), now.getMonth(), now.getDate(), 0,0,0,0);
        // create a copy of this for jumping to specific times 
        this.today = new Date(this.date.getTime());
        // if a start time is defined, add it to the clock's date
        if ( state.time && _.isString(state.time) ) {
            var seconds = _S.parseTime( state.time );
            var ms      = this.date.getTime() + (seconds * 1000);
            this.date.setTime(ms);
        }
        // archive the initial start date/time
        this.initDate = new Date( this.date.getTime() );
        
        clock.setTime();
        
        this.isRunning = true;
        this.isPaused  = !state.autoStart;
    };
    
    /**
     * Updates the Game Clock
     */
    clock.onUpdate = function() {   
        var elapsedTime = aden.elapsedTime;
        
        var nextEventTime = aden.nextEventTime;
        
        var timeDiff = elapsedTime - this.prevRealTime;
        
        this.prevRealTime = elapsedTime;
        
        // update game clock if not paused
        if ( !this.isPaused ) {
            var virtualElapsedTime = timeDiff *  this.speed;
            
            // update date
            var gameTime = this.date.getTime() + virtualElapsedTime;
            this.date.setTime(gameTime);
        }
        
        this.setTime();
        
        // auto correction for when engine jumps too far ahead in time
        if ( this.time > nextEventTime ) {
            this.time = nextEventTime;
        }
        
        this.timeEl.html(this.time);
        this.elapsedEl.html(aden.elapsedTime);
        this.ranEl.html(aden.runTime);
        
        return this.date;
    };
    
    /**
     * Resets the clock by grabbing a new date avalue and setting the time
     */
    clock.onReset = function() {
        this.date = new Date(this.date.valueOf());
        this.setTime();
    };
    
    /**
     * Pauses the clock sequence when the engine pauses 
     */
    clock.onPause = function(){
        _wasClockPaused = this.isPaused;
        this.pause();
    },
    
    /**
     * Resumes the clock sequence when the engine resumes, but only if it was running when the 
     * engine paused
     */
    clock.onResume = function(){
        if ( !_wasClockPaused ) {
            this.unpause();
        }
    },
    
    /**
     * This doubles the current game speed as long as the new speed will not be greater than the 
     * max game speed
     */
    clock.increaseSpeed = function() {
        if ( (  this.speed * 2 ) <=  this.maxSpeed ) {
            this.lastSpeed =  this.speed;
             this.speed =  this.speed * 2;
            return true;
        }
        return false;
    };
    
    /**
     * Resets the game speed to the base speed
     */
    clock.resetSpeed = function() {
        this.lastSpeed =  this.speed;
        this.speed = this.lastSpeed;
    };
    
    /**
     * This halves the current game speed
     */
    clock.decreaseSpeed = function() {
        if ( (  this.speed / 2 ) >=  this.minSpeed ) {
            this.lastSpeed =  this.speed;
             this.speed =  this.speed / 2;
            return true;
        }
        return false;
    };
    
    /**
     * This sets the clock speed
     */
    clock.setSpeed = function( newSpeed ) {
        this.lastSpeed = this.speed;
        this.speed = newSpeed;
    };
    
    /**
     * Forces real speed
     */
    clock.forceRealSpeed = function() {
        this.lastSpeed = this.speed;
        this.setSpeed(1);
    };
    
    /**
     * Resumes the previous speed
     */
    clock.resumeSpeed = function() {
        this.setSpeed(this.lastSpeed);
    };
    
    /**
     * Adds time to the Game Clock;
     */
    clock.addTime = function( time ) {
        var ms, seconds;
        if ( _.isString(time) ) {
            seconds = _S.parseTime( time );
            ms      = seconds * 1000;
        } else if ( _.isNumber(time) ) {
            ms = time;
        } else {
            return;
        }
        // set time
        this.date.setTime( this.date.getTime() + ms );
    };
    
    /**
     * Subtracts time from the game clock;
     */
    clock.subtractTime = function(timeStr) {
        var seconds = _S.parseTime( timeStr );
        var ms      = seconds * 1000;
        
        this.date.setTime( this.date.getTime() - ms );
    };
    
    /**
     * Sets a specific time
     */
    clock.setClock = function(timeStr) {
        var seconds  = _S.parseTime( timeStr );
        var ms       = seconds * 1000;
        var gameTime = this.today.getTime() + ms;
        this.date.setTime(gameTime);
    };
    
    /**
     * Sets Date
     */
    clock.setDate = function(newDate) {
        this.date = newDate;
        clock.setTime();
    };
    
    /**
     * Resets Date
     */
    clock.resetDate = function() {
        this.date = new Date( this.initDate.getTime() );
        clock.setTime();
    };
    
    /**
     * Returns the game date
     */
    clock.getDate = function() {
        return this.date;
    };
    
    /**
     * returns the clock time
     */
    clock.setTime = function() {
        this.time = 1000 * ( this.date.getHours() * 3600 + this.date.getMinutes() * 60 + this.date.getSeconds() ) + this.date.getMilliseconds();
    };
    
    /**
     * Retrieves the current clock time 
     */
    clock.getTime = function() {
        return this.time;
    };
    
    /**
     * Returns the day 
     */
    clock.getToday = function() {
        return ( 1000 * ( this.today.getHours() * 3600 + this.today.getMinutes() * 60 + this.today.getSeconds() ) + this.today.getMilliseconds() );
    };
    
    /**
     * returns the current clock speed
     */
    clock.getSpeed = function() {
        return  this.speed;
    };
    
    /**
     * Pauses clock
     */
    clock.pause = function() {
        this.isPaused = true;
    };
    
    /**
     * Resumes Paused Clock
     */
    clock.resume = function() {
        this.isPaused = false;
    };
    
    /**
     * Resumes Paused Clock 
     */
    clock.start = function() {
        this.isPaused = false;
    };
    
    /**
     * Unpauses clock
     */
    clock.unpause = function() {
        this.isPaused = false;
    };
    
    /**
     * Returns pause status of clock
     */
    clock.isPaused = function() {
        return this.isPaused;
    };
    
});
