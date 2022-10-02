<?php
/**
 * @file
 * sf_profiles_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function sf_profiles_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-ied-profiles-menu_africa:africa.
  $menu_links['menu-ied-profiles-menu_africa:africa'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'africa',
    'router_path' => 'africa',
    'link_title' => 'Africa',
    'options' => array(
      'attributes' => array(
        'title' => 'Africa',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_africa:africa',
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
    'parent_identifier' => 'menu-ied-profiles-menu_incidents:incidents',
  );
  // Exported menu link: menu-ied-profiles-menu_arming-switch:arming-switch.
  $menu_links['menu-ied-profiles-menu_arming-switch:arming-switch'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'arming-switch',
    'router_path' => 'arming-switch',
    'link_title' => 'Arming Switch',
    'options' => array(
      'attributes' => array(
        'title' => 'Arming Switch',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_arming-switch:arming-switch',
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
    'parent_identifier' => 'menu-ied-profiles-menu_switch:switch',
  );
  // Exported menu link: menu-ied-profiles-menu_commercialtoxic-industrial-materials:commercial-toxic-industrial-materials.
  $menu_links['menu-ied-profiles-menu_commercialtoxic-industrial-materials:commercial-toxic-industrial-materials'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'commercial-toxic-industrial-materials',
    'router_path' => 'commercial-toxic-industrial-materials',
    'link_title' => 'Commercial/Toxic Industrial Materials',
    'options' => array(
      'attributes' => array(
        'title' => 'Commercial/Toxic Industrial Materials',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_commercialtoxic-industrial-materials:commercial-toxic-industrial-materials',
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
    'parent_identifier' => 'menu-ied-profiles-menu_enhancements:enhancements',
  );
  // Exported menu link: menu-ied-profiles-menu_east-asia:east-asia.
  $menu_links['menu-ied-profiles-menu_east-asia:east-asia'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'east-asia',
    'router_path' => 'east-asia',
    'link_title' => 'East Asia',
    'options' => array(
      'attributes' => array(
        'title' => 'East Asia',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_east-asia:east-asia',
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
    'parent_identifier' => 'menu-ied-profiles-menu_incidents:incidents',
  );
  // Exported menu link: menu-ied-profiles-menu_electric:electric.
  $menu_links['menu-ied-profiles-menu_electric:electric'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'electric',
    'router_path' => 'electric',
    'link_title' => 'Electric',
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
        'title' => 'Electric',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_electric:electric',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-ied-profiles-menu_initiator:initiator',
  );
  // Exported menu link: menu-ied-profiles-menu_electrical-energy:electrical-energy.
  $menu_links['menu-ied-profiles-menu_electrical-energy:electrical-energy'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
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
      'identifier' => 'menu-ied-profiles-menu_electrical-energy:electrical-energy',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-ied-profiles-menu_power-source:power-source',
  );
  // Exported menu link: menu-ied-profiles-menu_enhancements:enhancements.
  $menu_links['menu-ied-profiles-menu_enhancements:enhancements'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'enhancements',
    'router_path' => 'enhancements',
    'link_title' => 'Enhancements',
    'options' => array(
      'attributes' => array(
        'title' => 'Enhancements',
      ),
      'identifier' => 'menu-ied-profiles-menu_enhancements:enhancements',
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-ied-profiles-menu_europe:europe.
  $menu_links['menu-ied-profiles-menu_europe:europe'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'europe',
    'router_path' => 'europe',
    'link_title' => 'Europe',
    'options' => array(
      'attributes' => array(
        'title' => 'Europe',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_europe:europe',
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
    'parent_identifier' => 'menu-ied-profiles-menu_incidents:incidents',
  );
  // Exported menu link: menu-ied-profiles-menu_firing-switch:firing-switch.
  $menu_links['menu-ied-profiles-menu_firing-switch:firing-switch'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'firing-switch',
    'router_path' => 'firing-switch',
    'link_title' => 'Firing Switch',
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
        'title' => 'Firing Switch',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_firing-switch:firing-switch',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-ied-profiles-menu_switch:switch',
  );
  // Exported menu link: menu-ied-profiles-menu_high-explosives:high-explosives.
  $menu_links['menu-ied-profiles-menu_high-explosives:high-explosives'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'high-explosives',
    'router_path' => 'high-explosives',
    'link_title' => 'High Explosives',
    'options' => array(
      'attributes' => array(
        'title' => 'High Explosives',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_high-explosives:high-explosives',
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
    'parent_identifier' => 'menu-ied-profiles-menu_main-charge:main-charge',
  );
  // Exported menu link: menu-ied-profiles-menu_improvised:improvised.
  $menu_links['menu-ied-profiles-menu_improvised:improvised'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'improvised',
    'router_path' => 'improvised',
    'link_title' => 'Improvised',
    'options' => array(
      'attributes' => array(
        'title' => 'Improvised',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_improvised:improvised',
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
    'parent_identifier' => 'menu-ied-profiles-menu_enhancements:enhancements',
  );
  // Exported menu link: menu-ied-profiles-menu_incidents:incidents.
  $menu_links['menu-ied-profiles-menu_incidents:incidents'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'incidents',
    'router_path' => 'incidents',
    'link_title' => 'Incidents',
    'options' => array(
      'attributes' => array(
        'title' => 'Incidents',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_incidents:incidents',
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
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: menu-ied-profiles-menu_initiator:initiator.
  $menu_links['menu-ied-profiles-menu_initiator:initiator'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'initiator',
    'router_path' => 'initiator',
    'link_title' => 'Initiator',
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
        'title' => 'Initiator',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_initiator:initiator',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-ied-profiles-menu_latin-america:latin-america.
  $menu_links['menu-ied-profiles-menu_latin-america:latin-america'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'latin-america',
    'router_path' => 'latin-america',
    'link_title' => 'Latin America',
    'options' => array(
      'attributes' => array(
        'title' => 'Latin America',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_latin-america:latin-america',
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
    'parent_identifier' => 'menu-ied-profiles-menu_incidents:incidents',
  );
  // Exported menu link: menu-ied-profiles-menu_low-explosives:low-explosives.
  $menu_links['menu-ied-profiles-menu_low-explosives:low-explosives'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'low-explosives',
    'router_path' => 'low-explosives',
    'link_title' => 'Low Explosives',
    'options' => array(
      'attributes' => array(
        'title' => 'Low Explosives',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_low-explosives:low-explosives',
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
    'parent_identifier' => 'menu-ied-profiles-menu_main-charge:main-charge',
  );
  // Exported menu link: menu-ied-profiles-menu_main-charge-configuration:main-charge-configuration.
  $menu_links['menu-ied-profiles-menu_main-charge-configuration:main-charge-configuration'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'main-charge-configuration',
    'router_path' => 'main-charge-configuration',
    'link_title' => 'Main Charge Configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Main Charge Configuration',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_main-charge-configuration:main-charge-configuration',
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
    'parent_identifier' => 'menu-ied-profiles-menu_main-charge:main-charge',
  );
  // Exported menu link: menu-ied-profiles-menu_main-charge:main-charge.
  $menu_links['menu-ied-profiles-menu_main-charge:main-charge'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'main-charge',
    'router_path' => 'main-charge',
    'link_title' => 'Main Charge',
    'options' => array(
      'attributes' => array(
        'title' => 'Main Charge',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_main-charge:main-charge',
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
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-ied-profiles-menu_mechanical-energy:mechanical-energy.
  $menu_links['menu-ied-profiles-menu_mechanical-energy:mechanical-energy'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'mechanical-energy',
    'router_path' => 'mechanical-energy',
    'link_title' => 'Mechanical Energy',
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
        'title' => 'Mechanical Energy',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_mechanical-energy:mechanical-energy',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-ied-profiles-menu_power-source:power-source',
  );
  // Exported menu link: menu-ied-profiles-menu_militaryweaponized:military-weaponized.
  $menu_links['menu-ied-profiles-menu_militaryweaponized:military-weaponized'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'military-weaponized',
    'router_path' => 'military-weaponized',
    'link_title' => 'Military/Weaponized',
    'options' => array(
      'attributes' => array(
        'title' => 'Military/Weaponized',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_militaryweaponized:military-weaponized',
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
    'parent_identifier' => 'menu-ied-profiles-menu_enhancements:enhancements',
  );
  // Exported menu link: menu-ied-profiles-menu_near-east-and-south-asia:near-east-and-south-asia.
  $menu_links['menu-ied-profiles-menu_near-east-and-south-asia:near-east-and-south-asia'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'near-east-and-south-asia',
    'router_path' => 'near-east-and-south-asia',
    'link_title' => 'Near East and South Asia',
    'options' => array(
      'attributes' => array(
        'title' => 'Near East and South Asia',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_near-east-and-south-asia:near-east-and-south-asia',
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
    'parent_identifier' => 'menu-ied-profiles-menu_incidents:incidents',
  );
  // Exported menu link: menu-ied-profiles-menu_non-electric:non-electric.
  $menu_links['menu-ied-profiles-menu_non-electric:non-electric'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'non-electric',
    'router_path' => 'non-electric',
    'link_title' => 'Non-Electric',
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
        'title' => 'Non-Electric',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_non-electric:non-electric',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-ied-profiles-menu_initiator:initiator',
  );
  // Exported menu link: menu-ied-profiles-menu_power-source:power-source.
  $menu_links['menu-ied-profiles-menu_power-source:power-source'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
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
      'identifier' => 'menu-ied-profiles-menu_power-source:power-source',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-ied-profiles-menu_precursor:precursor.
  $menu_links['menu-ied-profiles-menu_precursor:precursor'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'precursor',
    'router_path' => 'precursor',
    'link_title' => 'Precursor',
    'options' => array(
      'attributes' => array(
        'title' => 'Precursor',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_precursor:precursor',
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
  );
  // Exported menu link: menu-ied-profiles-menu_switch:switch.
  $menu_links['menu-ied-profiles-menu_switch:switch'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'switch',
    'router_path' => 'switch',
    'link_title' => 'Switch',
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
        'title' => 'Switch',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_switch:switch',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-ied-profiles-menu_us-and-canada:us-and-canada.
  $menu_links['menu-ied-profiles-menu_us-and-canada:us-and-canada'] = array(
    'menu_name' => 'menu-ied-profiles-menu',
    'link_path' => 'us-and-canada',
    'router_path' => 'us-and-canada',
    'link_title' => 'U.S. and Canada',
    'options' => array(
      'attributes' => array(
        'title' => 'U.S. and Canada',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ied-profiles-menu_us-and-canada:us-and-canada',
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
    'parent_identifier' => 'menu-ied-profiles-menu_incidents:incidents',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Africa');
  t('Arming Switch');
  t('Commercial/Toxic Industrial Materials');
  t('East Asia');
  t('Electric');
  t('Electrical Energy');
  t('Enhancements');
  t('Europe');
  t('Firing Switch');
  t('High Explosives');
  t('Improvised');
  t('Incidents');
  t('Initiator');
  t('Latin America');
  t('Low Explosives');
  t('Main Charge');
  t('Main Charge Configuration');
  t('Mechanical Energy');
  t('Military/Weaponized');
  t('Near East and South Asia');
  t('Non-Electric');
  t('Power Source');
  t('Precursor');
  t('Switch');
  t('U.S. and Canada');

  return $menu_links;
}
