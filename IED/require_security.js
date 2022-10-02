function getCookie(name) {
    var dc = document.cookie;
    var prefix = name + "=";
    var begin = dc.indexOf("; " + prefix);
    if (begin == -1) {
        begin = dc.indexOf(prefix);
        if (begin != 0) return null;
    }
    else
    {
        begin += 2;
        var end = document.cookie.indexOf(";", begin);
        if (end == -1) {
        end = dc.length;
        }
    }
    // because unescape has been deprecated, replaced with decodeURI
    //return unescape(dc.substring(begin + prefix.length, end));
    return decodeURI(dc.substring(begin + prefix.length, end));
} 

function doSomething() {
    var myCookie = getCookie("Drupal.visitor.user_uid");

    if (myCookie == null) {
      window.location = "/user";
    }
    else {
        console.log("do cookie exists stuff");
    }
    if (myCookie == 0) {
      window.location = "/user";
    }
}

doSomething();
