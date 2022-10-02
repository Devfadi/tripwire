<?php
/**
 * @file
 * full_width_carousel.slick_default_preset.inc
 */

/**
 * Implements hook_slick_default_presets().
 */
function full_width_carousel_slick_default_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'clone_of_pre_auth';
  $preset->label = 'Full Width';
  $preset->breakpoints = 1;
  $preset->skin = 'classic';
  $preset->options = array(
    'general' => array(
      'normal' => '',
      'thumbnail' => '',
      'template_class' => 'twcarousel',
      'goodies' => array(
        'arrow-down' => 0,
        'pattern' => 0,
        'random' => 0,
      ),
      'arrow_down_target' => '',
      'arrow_down_offset' => '',
    ),
    'settings' => array(
      'mobileFirst' => FALSE,
      'asNavFor' => '',
      'accessibility' => TRUE,
      'adaptiveHeight' => TRUE,
      'autoplay' => FALSE,
      'autoplaySpeed' => 5000,
      'pauseOnHover' => TRUE,
      'pauseOnDotsHover' => TRUE,
      'arrows' => TRUE,
      'prevArrow' => '<button type="button" data-role="none" class="slick-prev" aria-label="previous">Previous</button>',
      'nextArrow' => '<button type="button" data-role="none" class="slick-next" aria-label="next">Next</button>',
      'centerMode' => FALSE,
      'centerPadding' => '0',
      'dots' => TRUE,
      'dotsClass' => 'slick-dots',
      'appendDots' => '$(element)',
      'draggable' => TRUE,
      'fade' => FALSE,
      'focusOnSelect' => FALSE,
      'infinite' => TRUE,
      'initialSlide' => 0,
      'lazyLoad' => 'progressive',
      'respondTo' => 'window',
      'rtl' => FALSE,
      'rows' => 1,
      'slidesPerRow' => 1,
      'slide' => '',
      'slidesToShow' => 1,
      'slidesToScroll' => 1,
      'speed' => 500,
      'swipe' => TRUE,
      'swipeToSlide' => FALSE,
      'edgeFriction' => 0.34999999999999998,
      'touchMove' => TRUE,
      'touchThreshold' => 5,
      'useCSS' => TRUE,
      'cssEase' => 'ease',
      'cssEaseBezier' => 'cubic-bezier(0.550, 0.085, 0.680, 0.530)',
      'cssEaseOverride' => 'easeInQuad',
      'useTransform' => TRUE,
      'easing' => 'easeInQuad',
      'variableWidth' => FALSE,
      'vertical' => FALSE,
      'verticalSwiping' => FALSE,
      'waitForAnimate' => TRUE,
    ),
    'responsives' => array(
      'responsive' => array(
        0 => array(
          'breakpoint' => 1024,
          'unslick' => FALSE,
          'settings' => array(
            'accessibility' => TRUE,
            'adaptiveHeight' => FALSE,
            'autoplay' => FALSE,
            'autoplaySpeed' => 3000,
            'pauseOnHover' => TRUE,
            'pauseOnDotsHover' => FALSE,
            'arrows' => TRUE,
            'centerMode' => FALSE,
            'centerPadding' => '50px',
            'dots' => FALSE,
            'draggable' => TRUE,
            'fade' => FALSE,
            'focusOnSelect' => FALSE,
            'infinite' => TRUE,
            'initialSlide' => 0,
            'rows' => 1,
            'slidesPerRow' => 1,
            'slidesToShow' => 1,
            'slidesToScroll' => 1,
            'speed' => 500,
            'swipe' => TRUE,
            'swipeToSlide' => FALSE,
            'edgeFriction' => 0.34999999999999998,
            'touchMove' => TRUE,
            'touchThreshold' => 5,
            'useCSS' => TRUE,
            'cssEase' => 'ease',
            'cssEaseBezier' => '',
            'cssEaseOverride' => '',
            'useTransform' => FALSE,
            'easing' => 'linear',
            'variableWidth' => FALSE,
            'vertical' => FALSE,
            'verticalSwiping' => FALSE,
            'waitForAnimate' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['clone_of_pre_auth'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'thumbnav';
  $preset->label = 'Thumbnav';
  $preset->breakpoints = 0;
  $preset->skin = '';
  $preset->options = array(
    'general' => array(
      'normal' => 'carousel_thumbnail',
      'thumbnail' => '',
      'template_class' => '',
      'goodies' => array(
        'arrow-down' => 0,
        'pattern' => 0,
        'random' => 0,
      ),
      'arrow_down_target' => '',
      'arrow_down_offset' => '',
    ),
    'settings' => array(
      'mobileFirst' => FALSE,
      'asNavFor' => '#preauth-slider',
      'accessibility' => TRUE,
      'adaptiveHeight' => FALSE,
      'autoplay' => FALSE,
      'autoplaySpeed' => 3000,
      'pauseOnHover' => TRUE,
      'pauseOnDotsHover' => FALSE,
      'arrows' => FALSE,
      'prevArrow' => '<button type="button" data-role="none" class="slick-prev" aria-label="previous">Previous</button>',
      'nextArrow' => '<button type="button" data-role="none" class="slick-next" aria-label="next">Next</button>',
      'centerMode' => FALSE,
      'centerPadding' => '50px',
      'dots' => FALSE,
      'dotsClass' => 'slick-dots',
      'appendDots' => '$(element)',
      'draggable' => FALSE,
      'fade' => FALSE,
      'focusOnSelect' => TRUE,
      'infinite' => TRUE,
      'initialSlide' => 0,
      'lazyLoad' => 'ondemand',
      'respondTo' => 'window',
      'rtl' => FALSE,
      'rows' => 1,
      'slidesPerRow' => 1,
      'slide' => '',
      'slidesToShow' => 12,
      'slidesToScroll' => 1,
      'speed' => 500,
      'swipe' => TRUE,
      'swipeToSlide' => FALSE,
      'edgeFriction' => 0.34999999999999998,
      'touchMove' => TRUE,
      'touchThreshold' => 5,
      'useCSS' => TRUE,
      'cssEase' => 'ease',
      'cssEaseBezier' => '',
      'cssEaseOverride' => '',
      'useTransform' => FALSE,
      'easing' => 'linear',
      'variableWidth' => FALSE,
      'vertical' => FALSE,
      'verticalSwiping' => FALSE,
      'waitForAnimate' => TRUE,
    ),
  );
  $export['thumbnav'] = $preset;

  return $export;
}
