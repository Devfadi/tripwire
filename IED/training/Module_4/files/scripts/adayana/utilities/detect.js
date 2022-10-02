/**
 * @file detect.js
 * Contains the Detect Module which detects the sort of environment your code is
 * running on.
 */
define(['jquery', './parseUri'], function ($, parseUri) {
    'use strict';

    /**
     * A module which detects the type of environment the code is running in
     * @module utilities/detect
     */
    var detect = {};

    /**
     * Indicates if code is running in Internet Explorer.
     * this simple means of a necessary evil courtesy Dean Edwards
     */
    detect.isMSIE = /*@cc_on!@*/ false;
    /**
     * Boolean indicating if detect has run all its checks
     */
    detect.isReady = false;
    /**
     * Boolean indicating if the page is running on a server
     */
    detect.isServer = false;
    /**
     * Boolean indicating if the page is running on the local file system
     */
    detect.isStandalone = false;
    /**
     * Boolean indicating if the PhoneGap/Cordova API is available
     */
    detect.isPhoneGap = false;
    /**
     * Boolean indicating if the page is running from a destkop browser
     */
    detect.isDesktop = false;
    /**
     * Boolean indicating if the page is running on a mobile device
     */
    detect.isMobile = false;
    /**
     * Boolean indicating if the page is running from an Android device
     */
    detect.isAndroid = false;
    /**
     * Boolean indicating if the page is running from an iOS Device
     */
    detect.isIOS = false;
    /**
     * Boolean indicating if the script is running on pps.adayana.com
     */
    detect.isPPS = false;
    /**
     * Boolean indicating if the script is running in the JKO M-Learning Suite
     */
    detect.isMLearning = false;
    /**
     * Boolean indicating whether the code is running on localhost
     */
    detect.isLocalServer = false;

    /**
     * Parse the userAgent String for the version of IE
     * @return {Number} represents the version of Internet Explorer
     */
    detect.getInternetExplorerVersion = function () {
        var ua, re, rv = -1;
        if (navigator.appName === 'Microsoft Internet Explorer') {
            ua = navigator.userAgent;
            re = /MSIE ([0-9]{1,}[\.0-9]{0,})/;
            if (re.exec(ua) !== null) {
                rv = parseFloat(RegExp.$1);
            }
        } else if (navigator.appName === 'Netscape') {
            ua = navigator.userAgent;
            re = /Trident\/.*rv:([0-9]{1,}[\.0-9]{0,})/;
            if (re.exec(ua) !== null) {
                rv = parseFloat(RegExp.$1);
            }
        }
        return rv;
    };

    /**
     * Runs all detection checks
     */
    detect.checkAll = function () {
        // run checks
        this.checkPhoneGap();
        this.checkLocal();
        this.checkIOS();
        this.checkAndroid();
        this.checkPPS();
        this.checkMLearning();

        this.isMobile = /Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent);

        // configure additional information based off checks
        this.isServer = !this.isStandalone;
        this.isDesktop = !this.isMobile;
        this.isReady = true;
    };

    /**
     * Detect if the PhoneGap Framework is present.
     * Useful for JKO M-Learning as it adds this dynamically to the package
     */
    detect.checkPhoneGap = function () {
        if (typeof (PhoneGap) !== "undefined") {
            this.isPhoneGap = true;
        }
    };

    /**
     * Detect if the course is running locally or on the server
     */
    detect.checkLocal = function () {
        switch (window.location.protocol) {
        case 'http:':
        case 'https:':
            this.isStandalone = false;
            break;
        case 'file:':
            this.isStandalone = true;
            break;
        default:
            this.isStandalone = true;
        }

        if (window.location.hostname === 'localhost') {
            this.isLocalServer = true;
        }
    };

    /**
     * Detect if running on an Android Device
     */
    detect.checkAndroid = function () {
        if (navigator.appVersion.indexOf("Android") !== -1) {
            this.isAndroid = true;
        }
    };

    /**
     * Detect if running on an iOS Device
     */
    detect.checkIOS = function () {
        if (navigator.userAgent.indexOf("iPhone") !== -1 || navigator.userAgent.indexOf("iPod") !== -1 || navigator.appVersion.indexOf("iPad") !== -1) {
            this.isIOS = true;
        }
    };

    /**
     * Detect if script is running on pps.adayana.com
     * @returns {undefined}
     */
    detect.checkPPS = function () {
        // when this is not hosted locally
        if (!this.isStandalone) {
            // when parent exists and the parent's host is pps.adayana.com
            this.isPPS = (parent && parseUri(parent.location).host === 'pps.adayana.com');
        }
    };

    /**
     * detect if script is running in JKO's M-Learning Suite
     * @returns {undefined}
     */
    detect.checkMLearning = function () {
        if (this.isPhoneGap && window.plugins && window.plugins.clientPlugin) {
            this.isMLearning = true;
        }
    };

    return detect;
});