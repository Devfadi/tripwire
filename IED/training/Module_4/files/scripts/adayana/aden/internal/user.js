define(function (require) {
    'use strict';

    var CryptoJS = require('crypto'),
        _S = require('adayana/utilities/string');
    
    
    var user = window.user = {};
    
    user.date = new Date();
    user.dateCode = user.date.getFullYear() + _S.padDigits(user.date.getMonth(), 2) + _S.padDigits(user.date.getDate(), 2);
    user.dateStr = _S.padDigits(user.date.getMonth(), 2) + "/" + _S.padDigits(user.date.getDate(), 2) + "/" + user.date.getFullYear();
    user.key = "cowabunga";
    user.hash = CryptoJS.AES.encrypt(user.user + user.dateCode, user.key);
    
    return user;
});