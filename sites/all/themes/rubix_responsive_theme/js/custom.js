/* --------------------------------------------- 

* Filename:     custom.js
* Version:      1.0.0 (2015-03-21)
* Website:      http://www.zymphonies.com
                http://www.freebiezz.com
* Description:  System JS
* Author:       Zymphonies Team
                info@zymphonies.com
                
-----------------------------------------------*/

jQuery(document).ready(function($) {
    jQuery('.views-widget-sort-by').insertAfter(jQuery('#edit-title-wrapper'));
    jQuery('.filter_text').insertAfter(jQuery('#edit-title-wrapper'));
    if ($('#login-message').length > 0) {
        if ($('#login-message').html() == 'You are not logged in.') {
            if (window.location.pathname !== '/user') {
                $('#login-message').html('<p>You must be an authenticated user to view this resource.  Please allow time for registration process to be completed. Please contact the Help Desk with any questions.</p>');
                $('#login-message').addClass('redmessage');
            }
        }
    }

    // TRIP2-126: Adding lock icon if author enables checkbox
    if (typeof Drupal.settings.tripwire !== 'undefined') {
        if (typeof Drupal.settings.tripwire.lock_icon !== 'undefined') {
            if (Drupal.settings.tripwire.lock_icon == 'enabled') {
                $('.not-logged-in h1.page-title').addClass('lock');
                $('.not-logged-in h1.page-title').after('<div class="lock-description">Lock icon indicates restricted content.  Please log in to view content.</div>')
            }
        }
    }

    // TRIP2-159: Showing video download link if author enbables checkbox
    if (typeof Drupal.settings.tripwire !== 'undefined') {
        if (typeof Drupal.settings.tripwire.enable_video_link !== 'undefined') {
            if (Drupal.settings.tripwire.enable_video_link == 'enabled') {
                $('.node-type-video .mediaelement-download-link').css("display", "block");
            }
        }
    }

    $('.nav-toggle').click(function() {
        $('#main-menu div ul:first-child').slideToggle(250);
        return false;
    });

    function hideLoginLinks() {
        $('#block-block-10 a, #block-block-13 a').clone().appendTo('.menu_wrapper #main-menu .menu-navigation-container ul');
        $('.menu_wrapper #main-menu .menu-navigation-container a.login-button').wrap('<li></li>');
        $('.menu_wrapper #main-menu .menu-navigation-container a.register-now').wrap('<li></li>');
        $('.header-right-region #block-block-10, .header-right-region #block-block-13').css('display', 'none');
    }

    if (($(window).width() > 640) || ($(document).width() > 640)) {
        $('#main-menu li').mouseenter(function() {
            $(this).children('ul').css('display', 'none').stop(true, true).slideToggle(250).css('display', 'block').children('ul').css('display', 'none');
        });
        $('#main-menu li').mouseleave(function() {
            $(this).children('ul').stop(true, true).fadeOut(150).css('display', 'block');
        })
    } else {
        $('#main-menu li').each(function() {
            if ($(this).children('ul').length)
                $(this).append('<span class="drop-down-toggle"><span class="drop-down-arrow"></span></span>');
        });

        $('.drop-down-toggle').click(function() {
            $(this).parent().children('ul').slideToggle(250);
        });
    }

    if ($(window).width() <= 640) {
        hideLoginLinks();
    }

    // Glossary index fix
    if ($(".view-tripwire-glossary .attachment").length > 0) {
        $(".view-tripwire-glossary .attachment a").each(function() {
            var anchor = '#' + $(this).text();
            $(this).attr('href', anchor);
        });

        $(".view-tripwire-glossary .view-content .views-row-last").after('<a class="toplink" href="#top">[top of page]</a>');
    }

    // Carousel thumbnail generator for videos
    /*if ($(".view-full-width-carousel .slick__slider").length > 0) {
      var i = 0;
      $('.slick-dots li').each(function() {
        var img = jQuery('.view-full-width-carousel > .attachment .slide--' + i + ' img');
        if (img.length < 1) { var img = '<i class="fa fa-play-circle fakevideo" aria-hidden="true"></i>'; }
        $(this).html(img);
        i++
      });
      $('.view-full-width-carousel .attachment').remove();
    }*/

    // Carousel thumbnail width calc
    /*
    if ($(".view-full-width-carousel .slick__slider").length > 0) {
      $('.view-full-width-carousel .slick__slider').tooltip();
      var thumbcount = $('.slick--view--full-width-carousel .slick-dots li').length;
      var carouselwidth = $('.slick--view--full-width-carousel .slick-dots').width();
      if (thumbcount < 9) {
        var thumbwidth = ((carouselwidth / thumbcount) - 15 -10) / carouselwidth * 100 + '%';
        console.log(thumbwidth);
      } else {
        var thumbwidth = ((carouselwidth / 8) - 15 -10) / carouselwidth * 100 + '%';
        $('.slick--view--full-width-carousel .slick-dots').addClass('scrollbar');
        $('.slick--view--full-width-carousel .slick-dots').css("overflow", "auto");
        $('.slick--view--full-width-carousel .slick-dots').css("min-height", "100px");
      }
      $('.slick--view--full-width-carousel .slick-dots li').each(function() {
        $(this).css("width", thumbwidth);
      });
      var thumbheight = $('.slick--view--full-width-carousel .slick-dots li img').height();
      $('.slick--view--full-width-carousel .slick-dots li .fakevideo').each(function() {
        $(this).css("height", thumbheight);
      });
    }
    */

    // Resizing the height of carousel on smaller resolutions if a non-moving image is in the slider

    function resizeFWC() {
        if ($(".view-full-width-carousel .disablemovement").length > 0) {
            // First, we find the height of the image that cannot move

            $(".view-full-width-carousel .disablemovement").each(function() {
                var disMoveHeight = $(this).parent().parent().find('.right').height();
                console.log(disMoveHeight);

                if (disMoveHeight == '0') {
                    // This is a check for the script executing too quickly. If it does the check too quickly, it comes back as zero. Anywho, we wait a bit and do it again until we get a real value.
                    console.log("hit");
                    //disMoveHeight = $(".view-full-width-carousel .disablemovement").height();
                    setTimeout(resizeFWC, 500);
                } else {
                    $(this).parent().parent().find('.left').css('height', disMoveHeight);
                }
            });

            // Now, we set the height of the right element to ensure all slides have same height, and no weird spacing.
            //$(".slick--view--full-width-carousel .slick__slide .right").css('height', disMoveHeight);
        }
    }
    resizeFWC();

    $(window).on('resize', function() {
        // Call resize function for carousel
        resizeFWC();
    });

    // MyTRIPwire
    if ($('#block-views-my-tripwire-block-1 > h2').length > 0) {
        $('#block-views-my-tripwire-block-1 > h2').html('My TRIP<span>wire</span>');
        $('#block-views-my-tripwire-block-1 .gear-icon').click(function() {
            $('#block-views-my-tripwire-block-1 .view-filters').slideToggle("slow", function() {
                $('#block-views-my-tripwire-block-1').addClass('showFilters');
            });
        });
    }

    $('.front .wn-left').matchHeight({
        target: $('.front .testimonial-left')
    });

    $('.front .wn-grid .views-row .views-field-nothing').matchHeight({});
    $('.front .wn-grid .views-row .wng-title').matchHeight({});

    // Detect IE 11
    var isIE11 = !!navigator.userAgent.match(/Trident.*rv\:11\./);
    if (!isIE11) {} else {
        $('body').addClass('ie11');
    }

    if (!!navigator.userAgent.match(/Edge/)) {
        $('body').addClass('ieEdge');
    }

    // Find and replace TripWIRE to style it
    $("h1.page-title, #main-menu li a, h3.faqfield-question a, #admin-menu li a").html(function() {
        return $(this).html().replace(/wire/g, '<span class="wire">wire</span>');
    });
    $("#breadcrumbs .breadcrumb a").html(function() {
        return $(this).text().replace(/wire/g, '<span class="wire">wire</span>');
    });
    var wirereplace = $('.field-name-body').html();
    if (typeof wireplace !== 'undefined') {
        wirereplace = wirereplace.replace(/wire/g, '<span class="wire">wire</span>');
        $('.field-name-body').html(wirereplace);
    }

    $('.region-sidebar-first .block h2').each(function() {
        $(this).html(function() {
            return $(this).html().replace(/wire/ig, '<span class="wire">wire</span>');
        });
    });

    // Disabling Certification information from changing on user edit
    if ($('.page-user-edit #user-profile-form .field-name-field-certification-name').length > 0) {
        $('.page-user-edit #user-profile-form .field-name-field-certification-name input').addClass("disabled").attr("disabled", "disabled");
        $('.page-user-edit #user-profile-form .field-name-field-certification-expiration-d input').addClass("disabled").attr("disabled", "disabled");
    }

    // Matching height of video blocks
    if (window.location.pathname.indexOf("/video-library") >= 0 || window.location.pathname.indexOf("/videos") >= 0) {
        if (window.location.pathname.indexOf("/video-library") >= 0) {
            $('h1.page-title, nav.breadcrumb').hide();
        }
        $('.view-video-tags .views-row a').each(function() {
            var tagUrl = $(this).attr("href").toLowerCase();
            $(this).attr("href", tagUrl);
        })
        $('.submitted-by').remove();
        $('.view-video-blocks .views-row').matchHeight();
        $('.view-video-blocks .views-field-title').matchHeight();
        $('.view-video-blocks .views-field-view-node a').each(function() {
            $(this).append('<i class="fa fa-caret-right" aria-hidden="true"></i>');
        })
    }

    // metablocks order of widgets
    if ($('.metadata-blocks').length > 0) {
        // Re order sort blocks
        $('.metadata-blocks .views-exposed-widgets #edit-sort-bef-combine-wrapper').insertAfter('.metadata-blocks .views-exposed-widgets #edit-combine-wrapper');
        // Add asc or desc arrows to filter
        $('.metadata-blocks #edit-sort-bef-combine .form-item .form-item').each(function() {
            var direction = $(this).attr("class");
            console.log(direction);
            if (direction.indexOf("selected") !== -1) {
                if (direction.match(/(created|totalcount|filesize|combine-value)/)) {
                    if (direction.indexOf("desc") !== -1) {
                        $(this).prepend('<i class="fa fa-caret-up" aria-hidden="true"></i>');
                    }
                    if (direction.indexOf("asc") !== -1) {
                        $(this).prepend('<i class="fa fa-caret-down" aria-hidden="true"></i>');
                    }
                } else {
                    // Not date field
                    if (direction.indexOf("asc") !== -1) {
                        $(this).prepend('<i class="fa fa-caret-up" aria-hidden="true"></i>');
                    }
                    if (direction.indexOf("desc") !== -1) {
                        $(this).prepend('<i class="fa fa-caret-down" aria-hidden="true"></i>');
                    }
                }
            }
        });
    }

    // T2OM-107: Adding fake iframe to fix pdf going in front of menu
    // First, check if browser is IE.  If not IE, skip this code since it's useless
    if (navigator.userAgent.match(/msie/i) || navigator.userAgent.match(/trident/i)) {
        // Since we are on IE, add fake iframe to each submenu within the menu. 
        // Regular items that are not a submenu parent get their iframe added in template.php in preprocess_menu_link
        jQuery('#main-menu ul.menu li li.expanded').each(function() {
            jQuery(this).append('<iframe class="iframetrick"></iframe>');
        });
    }

    // T2OM-147: Adding class to add simple queue link
    $('a[href$="add/nodequeue"]:first').addClass("addqueue");

    //T2OM-163: Disabling default fed region for user on My TRIPwire Subscriptions
    $('body.page-profile-my-tripwire-subscriptions .field-type-taxonomy-term-reference input.disabled').attr("disabled", "disabled");
    $('body.page-profile-my-tripwire-subscriptions #breadcrumbs').html('<h2 class="element-invisible">You are here</h2><nav class="breadcrumb"><a href="/">Home</a> » <a href="/mytripwire">My TRIP<span class="wire">wire</span></a> » My TRIP<span class="wire">wire</span> Subscriptions</nav>');

    $('.view-osint-map .feed-icon a').html("Export Results");

    // T2OM-357: Deferring leaflet fix from T2OM-198 to later to avoid race condition
    if ($(Drupal.settings.leaflet).length) {
        if ($(Drupal.settings.leaflet[0].lMap).length) {
            var mymap = Drupal.settings.leaflet[0].lMap;
            mymap.setView([39.8283, -98.5795], 4);
        }
    }

});