jQuery(document).ready(function($) {
    if ($('body').hasClass('not-logged-in')) {
        // do whatever you want for anon users
        var drupalmessage = decodeURI(getCookieValue("Drupal.visitor.tripwire.jsmessage"));
        if (drupalmessage !== ''){
            $('#post-content').prepend('<div class="messages status">' + decodeURI(getCookieValue("Drupal.visitor.tripwire.jsmessage")) + '</div>');
            deleteCookie('Drupal.visitor.tripwire.jsmessage');
        }
      }
});

function getCookieValue(a) {
    var b = document.cookie.match('(^|;)\\s*' + a + '\\s*=\\s*([^;]+)');
    return b ? b.pop() : '';
}

function deleteCookie(name, path, domain) {
    if (getCookieValue(name)) document.cookie = name + '=' +
        ((path) ? ';path=' + path : '') +
        ((domain) ? ';domain=' + domain : '') +
        ';expires=Thu, 01-Jan-1970 00:00:01 GMT';
}