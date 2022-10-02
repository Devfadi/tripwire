/**
 * Adds functionality to each a tag on the page with a rel="external" 
 * to open the link in a new window.  Avoids the need to use invalid 
 * XHTML of target="_blank".
 * 
 * @history 2007.06.07 ALP - Initial Version
 * @history 2013.06.10 VRB - Wrapped in AMD Module 
 * @history 2013.07.01 VRB - Changed to Modified AMD format
 */
(function(root, factory) {
    if (typeof define === 'function' && define.amd) {
        define(factory);
    } else {
        root.externalLinks = factory();
    }
}(this, function() {

    function externalLinks() {
        function openHref(){
            window.open(this.href);
            return false;
        }
        if (document.getElementsByTagName) {
            var anchors = document.getElementsByTagName("a");
            for (var i = 0, j = anchors.length; i < j; i++) {
                var anchor = anchors[i];
                if (anchor.getAttribute("href") && anchor.getAttribute("rel") === "external") {
                    anchor.onclick = openHref;
                }
            }
        }
    }

    return externalLinks;
}));