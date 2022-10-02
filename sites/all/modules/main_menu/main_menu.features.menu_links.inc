<?php
/**
 * @file
 * main_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function main_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about-the-office-for-bombing-prevention:node/44.
  $menu_links['main-menu_about-the-office-for-bombing-prevention:node/44'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/44',
    'router_path' => 'node/%',
    'link_title' => 'About the Office for Bombing Prevention',
    'options' => array(
      'attributes' => array(
        'title' => 'About the Office for Bombing Prevention',
      ),
      'fragment' => 'AboutOBP',
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_about-the-office-for-bombing-prevention:node/44',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:<nolink>',
  );
  // Exported menu link: main-menu_about-tripwire:node/44.
  $menu_links['main-menu_about-tripwire:node/44'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/44',
    'router_path' => 'node/%',
    'link_title' => 'About TRIPwire',
    'options' => array(
      'attributes' => array(
        'title' => 'About TRIPwire',
      ),
      'fragment' => 'TRIPwire',
      'identifier' => 'main-menu_about-tripwire:node/44',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:<nolink>',
  );
  // Exported menu link: main-menu_about:<nolink>.
  $menu_links['main-menu_about:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => 'Welcome to TRIPwire',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_about:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_academic-reports:academic-reports.
  $menu_links['main-menu_academic-reports:academic-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'academic-reports',
    'router_path' => 'academic-reports',
    'link_title' => 'Academic Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Academic Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_academic-reports:academic-reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -25,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_africa:africa.
  $menu_links['main-menu_africa:africa'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'africa',
    'router_path' => 'africa',
    'link_title' => 'Africa',
    'options' => array(
      'attributes' => array(
        'title' => 'Africa',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_africa:africa',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_incidents:incidents',
  );
  // Exported menu link: main-menu_arming-switch:taxonomy/term/397.
  $menu_links['main-menu_arming-switch:taxonomy/term/397'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/397',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Arming Switch',
    'options' => array(
      'attributes' => array(
        'title' => 'Arming Switch',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_arming-switch:taxonomy/term/397',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_switch:switch',
  );
  // Exported menu link: main-menu_ask-the-expert:node/94.
  $menu_links['main-menu_ask-the-expert:node/94'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/94',
    'router_path' => 'node/%',
    'link_title' => 'Ask the Expert',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_ask-the-expert:node/94',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'main-menu_contact-us:<nolink>',
  );
  // Exported menu link: main-menu_blast-distance-calculator:node/78.
  $menu_links['main-menu_blast-distance-calculator:node/78'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/78',
    'router_path' => 'node/%',
    'link_title' => 'Blast Distance Calculator',
    'options' => array(
      'attributes' => array(
        'title' => 'Blast Distance Calculator',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
        ),
        'hide' => array(
          2 => 2,
        ),
      ),
      'fragment' => 'calc',
      'identifier' => 'main-menu_blast-distance-calculator:node/78',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_bomb-threat-management:node/14.
  $menu_links['main-menu_bomb-threat-management:node/14'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Bomb Threat Management',
    'options' => array(
      'attributes' => array(
        'title' => 'Bomb Threat Management',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'fragment' => 'threat',
      'identifier' => 'main-menu_bomb-threat-management:node/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_readiness--preparedness:<nolink>',
  );
  // Exported menu link: main-menu_border-reports:border-reports.
  $menu_links['main-menu_border-reports:border-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'border-reports',
    'router_path' => 'border-reports',
    'link_title' => 'Border Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Border Reports',
      ),
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_border-reports:border-reports',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -30,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_civilian-evacuation-distance-calculator:node/135.
  $menu_links['main-menu_civilian-evacuation-distance-calculator:node/135'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/135',
    'router_path' => 'node/%',
    'link_title' => 'Civilian Evacuation Distance Calculator',
    'options' => array(
      'attributes' => array(
        'title' => 'Civilian Evacuation Distance Calculator',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_civilian-evacuation-distance-calculator:node/135',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_commercialtoxic-industrial-materials:commercial-toxic-industrial-materials.
  $menu_links['main-menu_commercialtoxic-industrial-materials:commercial-toxic-industrial-materials'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'commercial-toxic-industrial-materials',
    'router_path' => 'commercial-toxic-industrial-materials',
    'link_title' => 'Commercial/Toxic Industrial Materials',
    'options' => array(
      'attributes' => array(
        'title' => 'Commercial/Toxic Industrial Materials',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_commercialtoxic-industrial-materials:commercial-toxic-industrial-materials',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_enhancements:enhancements',
  );
  // Exported menu link: main-menu_contact-us:<nolink>.
  $menu_links['main-menu_contact-us:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(
        'title' => 'Contact Us',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_contact-us:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_daily-and-weekly-reports:daily-and-weekly-reports.
  $menu_links['main-menu_daily-and-weekly-reports:daily-and-weekly-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'daily-and-weekly-reports',
    'router_path' => 'daily-and-weekly-reports',
    'link_title' => 'Daily and Weekly Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Daily and Weekly Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_daily-and-weekly-reports:daily-and-weekly-reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -36,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_dhs-reports:dhs-reports.
  $menu_links['main-menu_dhs-reports:dhs-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dhs-reports',
    'router_path' => 'dhs-reports',
    'link_title' => 'DHS Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'DHS Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_dhs-reports:dhs-reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -26,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_east-asia:east-asia.
  $menu_links['main-menu_east-asia:east-asia'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'east-asia',
    'router_path' => 'east-asia',
    'link_title' => 'East Asia',
    'options' => array(
      'attributes' => array(
        'title' => 'East Asia',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_east-asia:east-asia',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'parent_identifier' => 'main-menu_incidents:incidents',
  );
  // Exported menu link: main-menu_electric:electric.
  $menu_links['main-menu_electric:electric'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'electric',
    'router_path' => 'electric',
    'link_title' => 'Electric',
    'options' => array(
      'attributes' => array(
        'title' => 'Electric',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_electric:electric',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_initiator:initiator',
  );
  // Exported menu link: main-menu_electrical-energy:electrical-energy.
  $menu_links['main-menu_electrical-energy:electrical-energy'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'electrical-energy',
    'router_path' => 'electrical-energy',
    'link_title' => 'Electrical Energy',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'attributes' => array(
        'title' => 'Electrical Energy',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_electrical-energy:electrical-energy',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_power-source:power-source',
  );
  // Exported menu link: main-menu_enhancements:enhancements.
  $menu_links['main-menu_enhancements:enhancements'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'enhancements',
    'router_path' => 'enhancements',
    'link_title' => 'Enhancements',
    'options' => array(
      'attributes' => array(
        'title' => 'Enhancements',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_enhancements:enhancements',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_explosive-profiles:explosive-profiles',
  );
  // Exported menu link: main-menu_europe:europe.
  $menu_links['main-menu_europe:europe'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'europe',
    'router_path' => 'europe',
    'link_title' => 'Europe',
    'options' => array(
      'attributes' => array(
        'title' => 'Europe',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_europe:europe',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'parent_identifier' => 'main-menu_incidents:incidents',
  );
  // Exported menu link: main-menu_explosive-profiles:explosive-profiles.
  $menu_links['main-menu_explosive-profiles:explosive-profiles'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'explosive-profiles',
    'router_path' => 'explosive-profiles',
    'link_title' => 'Explosive Profiles',
    'options' => array(
      'attributes' => array(
        'title' => 'Explosive Profiles',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_explosive-profiles:explosive-profiles',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -41,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_explosive-profiles:node/78.
  $menu_links['main-menu_explosive-profiles:node/78'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/78',
    'router_path' => 'node/%',
    'link_title' => 'Explosive Profiles',
    'options' => array(
      'attributes' => array(
        'title' => 'Explosive Profiles',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
        ),
        'hide' => array(
          2 => 2,
        ),
      ),
      'fragment' => 'profiles',
      'identifier' => 'main-menu_explosive-profiles:node/78',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_extremist-documents:extremist-documents.
  $menu_links['main-menu_extremist-documents:extremist-documents'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'extremist-documents',
    'router_path' => 'extremist-documents',
    'link_title' => 'Extremist Documents',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'attributes' => array(
        'title' => 'Extremist Documents',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_extremist-documents:extremist-documents',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -33,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_faqs:node/25.
  $menu_links['main-menu_faqs:node/25'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/25',
    'router_path' => 'node/%',
    'link_title' => 'FAQs',
    'options' => array(
      'attributes' => array(
        'title' => 'FAQs',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_faqs:node/25',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_contact-us:<nolink>',
  );
  // Exported menu link: main-menu_fbi-reports:fbi-reports.
  $menu_links['main-menu_fbi-reports:fbi-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'fbi-reports',
    'router_path' => 'fbi-reports',
    'link_title' => 'FBI Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'FBI Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_fbi-reports:fbi-reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -27,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_federal-law-enforcement-training-center-fletc:https://www.fletc.gov/.
  $menu_links['main-menu_federal-law-enforcement-training-center-fletc:https://www.fletc.gov/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://www.fletc.gov/',
    'router_path' => '',
    'link_title' => 'Federal Law Enforcement Training Center (FLETC)',
    'options' => array(
      'attributes' => array(
        'title' => 'Federal Law Enforcement Training Center (FLETC)',
      ),
      'identifier' => 'main-menu_federal-law-enforcement-training-center-fletc:https://www.fletc.gov/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_partners:<nolink>',
  );
  // Exported menu link: main-menu_fema-emergency-management-institute:https://training.fema.gov/is/.
  $menu_links['main-menu_fema-emergency-management-institute:https://training.fema.gov/is/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://training.fema.gov/is/',
    'router_path' => '',
    'link_title' => 'FEMA Emergency Management Institute',
    'options' => array(
      'attributes' => array(
        'title' => 'FEMA Emergency Management Institute',
      ),
      'identifier' => 'main-menu_fema-emergency-management-institute:https://training.fema.gov/is/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_partners:<nolink>',
  );
  // Exported menu link: main-menu_firing-switch:firing-switch.
  $menu_links['main-menu_firing-switch:firing-switch'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'firing-switch',
    'router_path' => 'firing-switch',
    'link_title' => 'Firing Switch',
    'options' => array(
      'attributes' => array(
        'title' => 'Firing Switch',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_firing-switch:firing-switch',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_switch:switch',
  );
  // Exported menu link: main-menu_first-responder-awareness-documents:first-responder-awareness-documents.
  $menu_links['main-menu_first-responder-awareness-documents:first-responder-awareness-documents'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'first-responder-awareness-documents',
    'router_path' => 'first-responder-awareness-documents',
    'link_title' => 'First Responder Awareness Documents',
    'options' => array(
      'attributes' => array(
        'title' => 'First Responder Awareness Documents',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_first-responder-awareness-documents:first-responder-awareness-documents',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -24,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_high-explosives:high-explosives.
  $menu_links['main-menu_high-explosives:high-explosives'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'high-explosives',
    'router_path' => 'high-explosives',
    'link_title' => 'High Explosives',
    'options' => array(
      'attributes' => array(
        'title' => 'High Explosives',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_high-explosives:high-explosives',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_main-charge:main-charge',
  );
  // Exported menu link: main-menu_homeland-security-information-network-hsin:https://hsin.dhs.gov.
  $menu_links['main-menu_homeland-security-information-network-hsin:https://hsin.dhs.gov'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://hsin.dhs.gov',
    'router_path' => '',
    'link_title' => 'Homeland Security Information Network (HSIN)',
    'options' => array(
      'attributes' => array(
        'title' => 'Homeland Security Information Network (HSIN)',
      ),
      'identifier' => 'main-menu_homeland-security-information-network-hsin:https://hsin.dhs.gov',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_partners:<nolink>',
  );
  // Exported menu link: main-menu_ied-awareness:node/24.
  $menu_links['main-menu_ied-awareness:node/24'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/24',
    'router_path' => 'node/%',
    'link_title' => 'IED Awareness',
    'options' => array(
      'attributes' => array(
        'title' => 'IED Awareness',
      ),
      'alter' => TRUE,
      'fragment' => 'training',
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
        ),
        'hide' => array(
          2 => 2,
        ),
      ),
      'identifier' => 'main-menu_ied-awareness:node/24',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_training--education:<nolink>',
  );
  // Exported menu link: main-menu_ied-awareness:node/85.
  $menu_links['main-menu_ied-awareness:node/85'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/85',
    'router_path' => 'node/%',
    'link_title' => 'IED Awareness',
    'options' => array(
      'attributes' => array(
        'title' => 'IED Awareness',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_ied-awareness:node/85',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_training--education:<nolink>',
  );
  // Exported menu link: main-menu_ied-incident-map:node/78.
  $menu_links['main-menu_ied-incident-map:node/78'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/78',
    'router_path' => 'node/%',
    'link_title' => 'IED Incident Map',
    'options' => array(
      'attributes' => array(
        'title' => 'IED Incident Map',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
        ),
        'hide' => array(
          2 => 2,
        ),
      ),
      'fragment' => 'map',
      'identifier' => 'main-menu_ied-incident-map:node/78',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_ied-incident-map:node/81.
  $menu_links['main-menu_ied-incident-map:node/81'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/81',
    'router_path' => 'node/%',
    'link_title' => 'IED Incident Map',
    'options' => array(
      'attributes' => array(
        'title' => 'IED Incident Map',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_ied-incident-map:node/81',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_improvised:improvised.
  $menu_links['main-menu_improvised:improvised'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'improvised',
    'router_path' => 'improvised',
    'link_title' => 'Improvised',
    'options' => array(
      'attributes' => array(
        'title' => 'Improvised',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_improvised:improvised',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_enhancements:enhancements',
  );
  // Exported menu link: main-menu_incident-reports:incident-reports.
  $menu_links['main-menu_incident-reports:incident-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'incident-reports',
    'router_path' => 'incident-reports',
    'link_title' => 'Incident Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Incident Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_incident-reports:incident-reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -23,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_incidents:incidents.
  $menu_links['main-menu_incidents:incidents'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'incidents',
    'router_path' => 'incidents',
    'link_title' => 'Incidents',
    'options' => array(
      'attributes' => array(
        'title' => 'Incidents',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_incidents:incidents',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'main-menu_explosive-profiles:explosive-profiles',
  );
  // Exported menu link: main-menu_initiator:initiator.
  $menu_links['main-menu_initiator:initiator'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'initiator',
    'router_path' => 'initiator',
    'link_title' => 'Initiator',
    'options' => array(
      'attributes' => array(
        'title' => 'Initiator',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_initiator:initiator',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_explosive-profiles:explosive-profiles',
  );
  // Exported menu link: main-menu_jido-reports:jido-reports.
  $menu_links['main-menu_jido-reports:jido-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'jido-reports',
    'router_path' => 'jido-reports',
    'link_title' => 'JIDO Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'JIDO Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_jido-reports:jido-reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -30,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_latin-america:latin-america.
  $menu_links['main-menu_latin-america:latin-america'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'latin-america',
    'router_path' => 'latin-america',
    'link_title' => 'Latin America',
    'options' => array(
      'attributes' => array(
        'title' => 'Latin American',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_latin-america:latin-america',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
    'parent_identifier' => 'main-menu_incidents:incidents',
  );
  // Exported menu link: main-menu_law-enforcement-reports:law-enforcement-reports.
  $menu_links['main-menu_law-enforcement-reports:law-enforcement-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'law-enforcement-reports',
    'router_path' => 'law-enforcement-reports',
    'link_title' => 'Law Enforcement Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Law Enforcement Reports',
      ),
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_law-enforcement-reports:law-enforcement-reports',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -35,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_low-explosives:low-explosives.
  $menu_links['main-menu_low-explosives:low-explosives'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'low-explosives',
    'router_path' => 'low-explosives',
    'link_title' => 'Low Explosives',
    'options' => array(
      'attributes' => array(
        'title' => 'Low Explosives',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_low-explosives:low-explosives',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_main-charge:main-charge',
  );
  // Exported menu link: main-menu_main-charge-configuration:main-charge-configuration.
  $menu_links['main-menu_main-charge-configuration:main-charge-configuration'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'main-charge-configuration',
    'router_path' => 'main-charge-configuration',
    'link_title' => 'Main Charge Configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Main Charge Configuration',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_main-charge-configuration:main-charge-configuration',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_main-charge:main-charge',
  );
  // Exported menu link: main-menu_main-charge:main-charge.
  $menu_links['main-menu_main-charge:main-charge'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'main-charge',
    'router_path' => 'main-charge',
    'link_title' => 'Main Charge',
    'options' => array(
      'attributes' => array(
        'title' => 'Main Charge',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_main-charge:main-charge',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_explosive-profiles:explosive-profiles',
  );
  // Exported menu link: main-menu_mechanical-energy:mechanical-energy.
  $menu_links['main-menu_mechanical-energy:mechanical-energy'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'mechanical-energy',
    'router_path' => 'mechanical-energy',
    'link_title' => 'Mechanical Energy',
    'options' => array(
      'attributes' => array(
        'title' => 'Mechanical Energy',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_mechanical-energy:mechanical-energy',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_power-source:power-source',
  );
  // Exported menu link: main-menu_militaryweaponized:military-weaponized.
  $menu_links['main-menu_militaryweaponized:military-weaponized'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'military-weaponized',
    'router_path' => 'military-weaponized',
    'link_title' => 'Military/Weaponized',
    'options' => array(
      'attributes' => array(
        'title' => 'Military/Weaponized',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_militaryweaponized:military-weaponized',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_enhancements:enhancements',
  );
  // Exported menu link: main-menu_national-counter-ied-and-capability-analysis-database-nccad:https://nccad.dhs.gov.
  $menu_links['main-menu_national-counter-ied-and-capability-analysis-database-nccad:https://nccad.dhs.gov'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://nccad.dhs.gov',
    'router_path' => '',
    'link_title' => 'National Counter-IED and Capability Analysis Database (NCCAD)',
    'options' => array(
      'attributes' => array(
        'title' => 'National Counter-IED and Capability Analysis Database (NCCAD)',
      ),
      'identifier' => 'main-menu_national-counter-ied-and-capability-analysis-database-nccad:https://nccad.dhs.gov',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_partners:<nolink>',
  );
  // Exported menu link: main-menu_near-east-and-south-asia:near-east-and-south-asia.
  $menu_links['main-menu_near-east-and-south-asia:near-east-and-south-asia'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'near-east-and-south-asia',
    'router_path' => 'near-east-and-south-asia',
    'link_title' => 'Near East and South Asia',
    'options' => array(
      'attributes' => array(
        'title' => 'Near East and South Asia',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_near-east-and-south-asia:near-east-and-south-asia',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
    'parent_identifier' => 'main-menu_incidents:incidents',
  );
  // Exported menu link: main-menu_non-electric:non-electric.
  $menu_links['main-menu_non-electric:non-electric'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'non-electric',
    'router_path' => 'non-electric',
    'link_title' => 'Non-Electric',
    'options' => array(
      'attributes' => array(
        'title' => 'Non-Electric',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_non-electric:non-electric',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_initiator:initiator',
  );
  // Exported menu link: main-menu_obp-event-calendar:node/13.
  $menu_links['main-menu_obp-event-calendar:node/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'OBP Event Calendar',
    'options' => array(
      'attributes' => array(
        'title' => 'OBP Event Calendar',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_obp-event-calendar:node/13',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_obp-training-learning-management-system:<front>.
  $menu_links['main-menu_obp-training-learning-management-system:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'OBP Training Learning Management System',
    'options' => array(
      'attributes' => array(
        'title' => 'OBP Training Learning Management System',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_obp-training-learning-management-system:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_training--education:<nolink>',
  );
  // Exported menu link: main-menu_obp-training-learning-management-system:node/24.
  $menu_links['main-menu_obp-training-learning-management-system:node/24'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/24',
    'router_path' => 'node/%',
    'link_title' => 'OBP Training Learning Management System',
    'options' => array(
      'attributes' => array(
        'title' => 'OBP Training Learning Management System',
      ),
      'alter' => TRUE,
      'fragment' => 'learning',
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
        ),
        'hide' => array(
          2 => 2,
        ),
      ),
      'identifier' => 'main-menu_obp-training-learning-management-system:node/24',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_training--education:<nolink>',
  );
  // Exported menu link: main-menu_office-of-state-and-local-law-enforcement-slle:https://www.dhs.gov/office-state-and-local-law-enforcement.
  $menu_links['main-menu_office-of-state-and-local-law-enforcement-slle:https://www.dhs.gov/office-state-and-local-law-enforcement'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://www.dhs.gov/office-state-and-local-law-enforcement',
    'router_path' => '',
    'link_title' => 'Office of State and Local Law Enforcement (SLLE)',
    'options' => array(
      'attributes' => array(
        'title' => 'Office of State and Local Law Enforcement (SLLE)
',
      ),
      'identifier' => 'main-menu_office-of-state-and-local-law-enforcement-slle:https://www.dhs.gov/office-state-and-local-law-enforcement',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'parent_identifier' => 'main-menu_partners:<nolink>',
  );
  // Exported menu link: main-menu_partners:<nolink>.
  $menu_links['main-menu_partners:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Partners',
    'options' => array(
      'attributes' => array(
        'title' => 'Partners',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_partners:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_power-source:power-source.
  $menu_links['main-menu_power-source:power-source'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'power-source',
    'router_path' => 'power-source',
    'link_title' => 'Power Source',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'attributes' => array(
        'title' => 'Power Source',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_power-source:power-source',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_explosive-profiles:explosive-profiles',
  );
  // Exported menu link: main-menu_precursor:precursor.
  $menu_links['main-menu_precursor:precursor'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'precursor',
    'router_path' => 'precursor',
    'link_title' => 'Precursor',
    'options' => array(
      'attributes' => array(
        'title' => 'Precursor',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_precursor:precursor',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_explosive-profiles:explosive-profiles',
  );
  // Exported menu link: main-menu_private-sector-awareness-documents:private-sector-awareness-reports.
  $menu_links['main-menu_private-sector-awareness-documents:private-sector-awareness-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'private-sector-awareness-reports',
    'router_path' => 'private-sector-awareness-reports',
    'link_title' => 'Private Sector Awareness Documents',
    'options' => array(
      'attributes' => array(
        'title' => 'Private Sector Awareness Documents',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_private-sector-awareness-documents:private-sector-awareness-reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -28,
    'customized' => 1,
    'parent_identifier' => 'main-menu_reports:node/86',
  );
  // Exported menu link: main-menu_readiness--preparedness:<nolink>.
  $menu_links['main-menu_readiness--preparedness:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Readiness & Preparedness',
    'options' => array(
      'attributes' => array(
        'title' => 'Readiness & Preparedness',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_readiness--preparedness:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_readygov:https://www.ready.gov.
  $menu_links['main-menu_readygov:https://www.ready.gov'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://www.ready.gov',
    'router_path' => '',
    'link_title' => 'Ready.gov',
    'options' => array(
      'attributes' => array(
        'title' => 'Ready.gov',
      ),
      'identifier' => 'main-menu_readygov:https://www.ready.gov',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -38,
    'customized' => 1,
    'parent_identifier' => 'main-menu_partners:<nolink>',
  );
  // Exported menu link: main-menu_reports:node/86.
  $menu_links['main-menu_reports:node/86'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/86',
    'router_path' => 'node/%',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_reports:node/86',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_resources:<nolink>.
  $menu_links['main-menu_resources:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Resources',
    'options' => array(
      'attributes' => array(
        'title' => 'Resources',
      ),
      'identifier' => 'main-menu_resources:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_see-something-say-something:https://www.dhs.gov/see-something-say-something.
  $menu_links['main-menu_see-something-say-something:https://www.dhs.gov/see-something-say-something'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://www.dhs.gov/see-something-say-something',
    'router_path' => '',
    'link_title' => 'See Something Say Something',
    'options' => array(
      'attributes' => array(
        'title' => 'See Something Say Something',
      ),
      'identifier' => 'main-menu_see-something-say-something:https://www.dhs.gov/see-something-say-something',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_partners:<nolink>',
  );
  // Exported menu link: main-menu_suspicious-activity-reporting:node/14.
  $menu_links['main-menu_suspicious-activity-reporting:node/14'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Suspicious Activity Reporting',
    'options' => array(
      'attributes' => array(
        'title' => 'Suspicious Activity Reporting',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'fragment' => 'report',
      'identifier' => 'main-menu_suspicious-activity-reporting:node/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_readiness--preparedness:<nolink>',
  );
  // Exported menu link: main-menu_switch:switch.
  $menu_links['main-menu_switch:switch'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'switch',
    'router_path' => 'switch',
    'link_title' => 'Switch',
    'options' => array(
      'attributes' => array(
        'title' => 'Switch',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_switch:switch',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_explosive-profiles:explosive-profiles',
  );
  // Exported menu link: main-menu_training--education:<nolink>.
  $menu_links['main-menu_training--education:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Training & Education',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_training--education:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_tripwire-helpdesk:node/25.
  $menu_links['main-menu_tripwire-helpdesk:node/25'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/25',
    'router_path' => 'node/%',
    'link_title' => 'TRIPwire Helpdesk',
    'options' => array(
      'attributes' => array(
        'title' => 'TRIPwire Helpdesk',
      ),
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'fragment' => 'contact',
      'identifier' => 'main-menu_tripwire-helpdesk:node/25',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_contact-us:<nolink>',
  );
  // Exported menu link: main-menu_tripwire-library:node/78.
  $menu_links['main-menu_tripwire-library:node/78'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/78',
    'router_path' => 'node/%',
    'link_title' => 'TRIPwire Library',
    'options' => array(
      'attributes' => array(
        'title' => 'TRIPwire Library',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
        ),
        'hide' => array(
          2 => 2,
        ),
      ),
      'fragment' => 'library',
      'identifier' => 'main-menu_tripwire-library:node/78',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_tripwire-library:tripwire-library.
  $menu_links['main-menu_tripwire-library:tripwire-library'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tripwire-library',
    'router_path' => 'tripwire-library',
    'link_title' => 'TRIPwire Library',
    'options' => array(
      'attributes' => array(
        'title' => 'TRIPwire Library',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_tripwire-library:tripwire-library',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_tripwire-reports:tripwire-reports.
  $menu_links['main-menu_tripwire-reports:tripwire-reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tripwire-reports',
    'router_path' => 'tripwire-reports',
    'link_title' => 'TRIPwire Reports',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'attributes' => array(
        'title' => 'TRIPwire Reports',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_tripwire-reports:tripwire-reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_us-and-canada:us-and-canada.
  $menu_links['main-menu_us-and-canada:us-and-canada'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'us-and-canada',
    'router_path' => 'us-and-canada',
    'link_title' => 'U.S. and Canada',
    'options' => array(
      'attributes' => array(
        'title' => 'U.S. and Canada',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_us-and-canada:us-and-canada',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
    'parent_identifier' => 'main-menu_incidents:incidents',
  );
  // Exported menu link: main-menu_video-library:video-library.
  $menu_links['main-menu_video-library:video-library'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'video-library',
    'router_path' => 'video-library',
    'link_title' => 'Video Library',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'Video Library',
      ),
      'identifier' => 'main-menu_video-library:video-library',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_what-can-tripwire-do-for-me:node/44.
  $menu_links['main-menu_what-can-tripwire-do-for-me:node/44'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/44',
    'router_path' => 'node/%',
    'link_title' => 'What can TRIPwire do for me?',
    'options' => array(
      'attributes' => array(
        'title' => 'What can TRIPwire do for me?',
      ),
      'fragment' => 'WhatsonTRIPwire',
      'identifier' => 'main-menu_what-can-tripwire-do-for-me:node/44',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:<nolink>',
  );
  // Exported menu link: main-menu_whats-new:what-s-new-list.
  $menu_links['main-menu_whats-new:what-s-new-list'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'what-s-new-list',
    'router_path' => 'what-s-new-list',
    'link_title' => 'What\'s New',
    'options' => array(
      'attributes' => array(
        'title' => 'What\'s New list view of pre-authorization approved articles.',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
        ),
        'hide' => array(
          2 => 2,
        ),
      ),
      'identifier' => 'main-menu_whats-new:what-s-new-list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );
  // Exported menu link: main-menu_whats-new:what-s-new-list-view.
  $menu_links['main-menu_whats-new:what-s-new-list-view'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'what-s-new-list-view',
    'router_path' => 'what-s-new-list-view',
    'link_title' => 'What\'s New',
    'options' => array(
      'attributes' => array(
        'title' => 'What\'s New',
      ),
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
          3 => 3,
          4 => 4,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_whats-new:what-s-new-list-view',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -38,
    'customized' => 1,
    'parent_identifier' => 'main-menu_resources:<nolink>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('About TRIPwire');
  t('About the Office for Bombing Prevention');
  t('Academic Reports');
  t('Africa');
  t('Arming Switch');
  t('Ask the Expert');
  t('Blast Distance Calculator');
  t('Bomb Threat Management');
  t('Border Reports');
  t('Civilian Evacuation Distance Calculator');
  t('Commercial/Toxic Industrial Materials');
  t('Contact Us');
  t('DHS Reports');
  t('Daily and Weekly Reports');
  t('East Asia');
  t('Electric');
  t('Electrical Energy');
  t('Enhancements');
  t('Europe');
  t('Explosive Profiles');
  t('Extremist Documents');
  t('FAQs');
  t('FBI Reports');
  t('FEMA Emergency Management Institute');
  t('Federal Law Enforcement Training Center (FLETC)');
  t('Firing Switch');
  t('First Responder Awareness Documents');
  t('High Explosives');
  t('Homeland Security Information Network (HSIN)');
  t('IED Awareness');
  t('IED Incident Map');
  t('Improvised');
  t('Incident Reports');
  t('Incidents');
  t('Initiator');
  t('JIDO Reports');
  t('Latin America');
  t('Law Enforcement Reports');
  t('Low Explosives');
  t('Main Charge');
  t('Main Charge Configuration');
  t('Mechanical Energy');
  t('Military/Weaponized');
  t('National Counter-IED and Capability Analysis Database (NCCAD)');
  t('Near East and South Asia');
  t('Non-Electric');
  t('OBP Event Calendar');
  t('OBP Training Learning Management System');
  t('Office of State and Local Law Enforcement (SLLE)');
  t('Partners');
  t('Power Source');
  t('Precursor');
  t('Private Sector Awareness Documents');
  t('Readiness & Preparedness');
  t('Ready.gov');
  t('Reports');
  t('Resources');
  t('See Something Say Something');
  t('Suspicious Activity Reporting');
  t('Switch');
  t('TRIPwire Helpdesk');
  t('TRIPwire Library');
  t('TRIPwire Reports');
  t('Training & Education');
  t('U.S. and Canada');
  t('Video Library');
  t('What can TRIPwire do for me?');
  t('What\'s New');

  return $menu_links;
}
