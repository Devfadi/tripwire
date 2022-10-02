<?php
/**
 * @file
 * taxonomy_lists.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function taxonomy_lists_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Classification of Incident',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/classification-incident',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Secondary High Explosive',
    'description' => ' An explosive relatively insensitive to heat and shock, and usually initiated by a primary high explosive. It requires a relatively long distance and time to build up from a deflagration to detonation and will not propagate in extremely small diameter columns. Used for boosters and bursting charges. Sometimes called non-initiating high explosives.  Examples include dynamite, TNT, RDX, PETN, and HMX.  *Note  - The use of the terms "secondary high explosive" and "non-initiating high explosive" is not accepted by all authorities.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '02a9f30a-575f-4098-b9eb-51a14e506e0d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/secondary-high-explosive',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Main Charge',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '03130978-05c2-4253-aa79-cbc58ced4d13',
    'vocabulary_machine_name' => 'ied_profiles',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-type/main-charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Nitrostarch',
    'description' => ' Explosive used in some blasting compositions. It has been used during emergencies as a substitute for TNT. Manufactured from starch by nitration.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '03465d24-1547-4ff7-aa20-38862b8f51b0',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/nitrostarch',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Main Charge',
    'description' => ' The main explosive component of a device, as opposed to primary or booster elements. Generally the least sensitive and most powerful element.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '042f06b3-2e07-43d6-b77c-bd9f6f1f6032',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/main-charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Improvised',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 12,
    'uuid' => '0593f41c-3ec0-45f2-9cf0-92db9faf2ead',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'field_ied_profile_sub_type' => array(),
    'field_ied_profile' => array(),
    'field_incidents_location' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-sub-type/improvised',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'UVIED',
    'description' => ' An acronym for under-vehicle improvised explosive device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '05dedc39-1bde-4573-a477-d651dccdef50',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/uvied',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Mechanical Fuzing',
    'description' => ' Fuze that depends primarily upon events of a mechanical or physical nature for arming and functioning. Most mechanical bomb fuzes utilize an arming vane that rotates in the air stream to provide arming energy.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '08355e2b-acdd-4697-bd3e-135e3126beab',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/mechanical-fuzing',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Chemical Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '09b24ec5-35ed-4d39-b469-5f187958739d',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/chemical-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ordnance',
    'description' => ' Explosive chemicals, pyrotechnics, and similar stores such as bombs, guns and ammunition, flares, smoke, and napalm.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0a747c0c-821e-4ced-a0f2-214c9eb65d16',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/ordnance',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'DTMF',
    'description' => ' Dual-tone Multifrequency Decoder.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0a95cc25-415d-4de3-ab11-1b7534d74b42',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/dtmf',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bomb-Making Materials Found',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '0af5fe73-0b6d-494b-b900-593ed76230ed',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/bomb-making-materials-found',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Hoax-IED',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '0b912c31-8b9d-47a3-a428-dba57629e483',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/hoax-ied',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Radiography',
    'description' => ' Non-destructive examination of matter by means of x-rays or gamma rays. Used by EOD to examine IEDs or other suspicious items.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0c1d83ef-12d9-4e18-8f35-a9bc9e472abc',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/radiography',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Low  Explosive',
    'description' => ' An explosive which deflagrates or burns rather than detonates; that is, the rate of advance of the reaction zone into the unreacted material is less than the velocity of sound in the unreacted material. An explosive may react as a low explosive or as a high explosive depending on how it is initiated and confined. For example, a double base propellant when initiated in the usual manner is a low explosive, but can be made to detonate if it is initiated by an intense shock. Conversely, a high explosive like TNT can be ignited by flame and will burn without detonating  under certain conditions. Low explosives include propellants, certain primer mixtures, black powder, photoflash powders, and delay compositions.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0c8b8da2-13b0-48d4-aa04-e23ff7006ec2',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/low-explosive',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Squib',
    'description' => ' A small pyrotechnic device which may be used to fire the igniter in a rocket or for some similar purpose. Not to be confused with a detonator, which explodes.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0cbdad4d-a9ba-4e3c-a82a-59147221876a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/squib',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Government Only',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => '0d430414-c810-4339-8257-25748b4a3f8a',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/government-only',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'PBIED',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => '0d7a2001-4ba2-4217-84c4-1b978c02da00',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/pbied',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'Container',
    'description' => ' A term used to describe the package within which an explosive charge is stored.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0f2350b8-8e71-457c-85c9-a28d8528f346',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/container',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Fuel Air Bomb',
    'description' => ' This explosive disperses an aerosol cloud of fuel which is ignited by an embedded detonator. The rapidly expanding wave front due to overpressure flattens all objects within close proximity of the epicenter of the aerosol fuel cloud and produces debilitating damage well beyond the flattened area. This type of explosive is most often deployed against soft targets.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0f3f1d83-f348-4cb2-a503-007322ef53e5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/fuel-air-bomb',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hollow Charge',
    'description' => ' Designates a shaped charge (especially in British usage). Term derives from the fact that the explosive charge is hollowed out. When the hollowed out portion is conical, the charge is sometimes called "hollow cone charge," "beehive," or "beehive shaped charge."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0f4aa0cb-a5ca-4931-915e-63b9479b8276',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/hollow-charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Projectile High Explosive Plastic (HEP)',
    'description' => ' A thin-walled projectile, filled with plastic explosive. The projectile is designed to squash against an armored target before detonation, and to defeat the armor by producing spalls which are detached with considerable velocity from the back of the target plate. Also called a "squash" head.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0f5769db-48ba-45a5-9bee-748b91a8de74',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/projectile-high-explosive-plastic-hep',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Propellant Powder',
    'description' => ' A low explosive of fine granulation which, through burning, produces gases at a controlled rate to provide the energy for propelling a projectile. Restricted to small grain size, in larger grain form it is called "propellant" or "propellant grain."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '10d3ac12-f868-41cd-a68b-6572f690ab8d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/propellant-powder',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bomb',
    'description' => ' Explosives or other lethal agents together with its container or holder which is planted or thrown by hand, dropped from an aircraft, or projected by some other slow-speed device (lobbing it from a mortar), and used to destroy, damage, distract, injure, or kill.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1168cb7b-48c3-4a4c-9eab-0de107017144',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/bomb',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Prill',
    'description' => ' A small compressed pellet normally associated with ammonium nitrate that can be made porous and capable of absorption.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '125ebde7-b033-457f-9d7e-e3e94c0da6be',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/prill',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Stabilizer',
    'description' => ' Material added to a propellant to inhibit or reduce decomposition in storage.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '12aef94c-4776-4724-af97-4817af2dfd4a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/stabilizer',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'All International Countries',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '13adb661-5162-4d91-ab1e-edb62cc6fa36',
    'vocabulary_machine_name' => 'international',
    'url_alias' => array(
      0 => array(
        'alias' => 'international/all-international-countries',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'After Action Report (AAR)',
    'description' => ' The principal post-exercise document developed in partnership with exercise evaluators, sponsoring agencies, and key participants. It provides a historical record of findings and forms the basis for refinements to plans, policies, procedures, training, equipment, and overall preparedness of an entity to respond to a critical event.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '13fca59a-aaf1-4363-b410-ae200cb75f36',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/after-action-report-aar',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OBP',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => '14685e02-f61b-4196-b9a3-47cd4489460d',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/obp',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'What\'s New',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '1520034d-68d2-450d-b54e-1c8dff0fa996',
    'vocabulary_machine_name' => 'document_types',
    'url_alias' => array(
      0 => array(
        'alias' => 'document-types/whats-new',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Munitions',
    'description' => ' Any and all supplies and equipment required to conduct offensive and defensive war, including ammunition, transportation, fuel, food and clothing, but excluding personnel, supplies and equipment for purpose other than direct military operations.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '154046dd-e61f-4ea1-91ce-eb6aba9f52ee',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/munitions',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Accelerant',
    'description' => ' A substance that accelerates the ignition of a fire.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1705a762-b8d4-4dd5-9308-b50ed80bf0cc',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/accelerant',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Critical Diameter',
    'description' => ' The minimum diameter for propagation of a detonation wave at a stable velocity. Critical diameter may be affected by conditions of confinement, temperature, and pressure.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '171ddf4a-1622-449e-8cd0-7a2422b88322',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/critical-diameter',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Neumann Effect',
    'description' => ' Term sometimes used by Europeans for the more common British-American term of Monroe effect.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '193134ad-95b8-4c1e-96c9-e00b77069113',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/neumann-effect',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electric Detonator',
    'description' => ' A detonator designed for, and capable of, initiation by means of an electric current.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '193fcbdc-b87a-465f-87c3-2625762913f5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/electric-detonator',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Water and Wastewater Systems Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '19b9ece5-a8e4-49c1-ab12-06b65bf1fcb8',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/water-and-wastewater-systems-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Emplaced IED',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '1a6b1b3b-3f75-4e4a-aae2-d5201522e95f',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/emplaced-ied',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'International Included',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => '1c4e0ffb-c3d4-47b7-a288-517555f3a906',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/international-included',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Threat',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '1c7691f9-caa0-4870-b35c-92541844cc8f',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/threat',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Detonation Wave',
    'description' => ' Shock wave that precedes the advancing reaction zone in a high-order detonation.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1cb332cd-fe6a-4af1-bbea-8f7668156af5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/detonation-wave',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bimetallic Switch',
    'description' => ' Switch made up of a bimetallic strip, designed to function when exposed to changes in temperature.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1fe6d375-0929-4694-b601-6d9663e2df70',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/bimetallic-switch',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Alert',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => '1ff11514-bf2d-446f-aa31-854ae7aecb84',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/alert',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Lessons Learned',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 13,
    'uuid' => '232cbf8e-b05f-4671-b8ef-569e688f269e',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/lessons-learned',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hydrophobic',
    'description' => ' Having little or no affinity to water.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2493f0cc-a96e-4c07-a5d7-ebe6f223a429',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/hydrophobic',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Branch Line',
    'description' => ' An undetermined length of detonating cord of which one end is attached to the main line and the other end to an explosive charge.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '24c3a36c-1921-4d74-9767-af0c22f417e7',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/branch-line',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Propaganda',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => '2559c973-5c17-4802-a1fa-6393353700d6',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/propaganda',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Incendiary',
    'description' => ' Any flammable material that is used as a filler in ordnance intended to destroy a target by fire.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2564bbc8-92f1-4530-a0c3-e0be32c9bac5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/incendiary',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Firing System',
    'description' => ' A device designed primarily to detonate the main charge of explosives.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '25df95e7-3791-4258-b01d-d63a358fa1b1',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/firing-system',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Desensitize',
    'description' => ' Reduces the sensitivity of an explosive.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '25e9571a-d2ec-4e72-b457-e009125cf69f',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/desensitize',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Non-electric',
    'description' => ' In the case of a blasting cap, functioning is initiated by means other than electric.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '29235c9b-3a80-44fb-aab2-1dbfaec22039',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/non-electric',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'TTP',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2995896d-92ed-4162-9359-858022c8de9a',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/ttp',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Render Safe',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => '2a0603ae-85e8-4a18-a421-8659f9a3aa0e',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/render-safe',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Bomb Threat',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2b06533b-59c0-42eb-a8a6-ddcd5a91d0ce',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/bomb-threat',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'I',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2b309a38-7633-4a18-988d-3a23cd81ffaa',
    'vocabulary_machine_name' => 'federal_region',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'federal-region/i',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Near East and South Asia',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '2c2b42c1-e8a7-477f-bc8d-f56370f147bf',
    'vocabulary_machine_name' => 'incidents_location',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'incident-locations/near-east-and-south-asia',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Phlegmatizer',
    'description' => ' Material used to desensitize explosives, also to reduce erosion effect of gases in gun barrels.  It also serves as a lubricant and a binder.  Some explosives, like PETN and RDX, cannot be pressed unless they contain a phlegmatizer.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2e5de2a5-139c-4a42-b1a8-7e17f5853a1c',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/phlegmatizer',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ordnance, unexploded',
    'description' => ' Ordnance that fails to explode on impact or immediately thereafter, or which did not function as intended. It is considered to have a delayed action until the contrary is proved.  *Note - See UXO.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2ef21272-715d-490d-894f-fa13bd34f512',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/ordnance-unexploded',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Sensitive Security Information (SSI)',
    'description' => '<p>A TSA marking.</p>',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2fd92d21-bdb1-4a94-b396-6b7c80693d7a',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(
      'und' => array(
        0 => array(
          'value' => '(SSI)',
          'format' => NULL,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/sensitive-security-information-ssi',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Setback',
    'description' => ' The relative rearward movement of component parts in ordnance undergoing forward acceleration during its launching. These movements, and the setback force which causes them, are used to promote events which participate in the arming and eventual functioning of the ordnance.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2fdc6dd7-e434-4807-8d4a-c96043da4670',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/setback',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'JIDA',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => '3053379d-9072-46bb-98cc-cdb4cebb44e9',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/jida',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bomb Threat',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '311e395c-f9d8-4fe0-b8e0-082d5f6a0297',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/bomb-threat-0',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Hoax Device',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '32bfdd56-e0d4-4919-83ed-e6101f694e45',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/hoax-device',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'Incendiary Device',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '32c6dba6-8045-4f26-8053-fbaaacd13eb2',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/incendiary-device',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Europe',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '339bcb2b-bab5-4acf-8737-6e7831a67e50',
    'vocabulary_machine_name' => 'incidents_location',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'incident-locations/europe',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Africa',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '34968362-db9a-4246-b736-c2c0a8c8cc0a',
    'vocabulary_machine_name' => 'incidents_location',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'incident-locations/africa',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'YES',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '351211b4-a147-41f7-be41-89ba2d42cd4b',
    'vocabulary_machine_name' => 'allow_for_pre_auth_carousel',
    'url_alias' => array(
      0 => array(
        'alias' => 'allow-pre-auth-carousel/yes',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Capacitor',
    'description' => ' An item consisting of two or more electrodes, separated by a dielectric, the primary purpose of which is to store electrical energy when connected to a power source.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '355b640f-6fbb-4df3-b4fa-1bf8dec21cc5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/capacitor',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Training',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '35a2f9cd-e72c-450a-b637-abedcdc3bbc2',
    'vocabulary_machine_name' => 'training_education',
    'url_alias' => array(
      0 => array(
        'alias' => 'training-education/training',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Extremist Group',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '36faf77c-a54c-45e3-bf12-3f12dec3a9ae',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/extremist-group',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'CBRNE',
    'description' => ' An acronym for Chemical, Biological, Radiological, Nuclear, and Explosive
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '37bd3fc8-7a4c-43af-a1af-9d5774a5b047',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/cbrne',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explosion (Chemical)',
    'description' => ' A chemical reaction or change of state that is effected in an exceedingly short space of time with the generation of high temperatures and generally a large quantity of gas. An explosion produces a shock wave in the surrounding medium. The term includes both deflagration and detonation.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '37d5d5ec-d117-40d9-a20c-271d56053b6b',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/explosion-chemical',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Soldering Iron',
    'description' => ' A device used for applying heat to melt solder in order to solder, or fuse, two metal parts together.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '393fda53-038f-4217-a9dd-cf836eeb7934',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/soldering-iron',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Silicon controlled rectifier (SCR)',
    'description' => ' A four-layer, semiconductor device that, when in its normal state, blocks a voltage applied in either direction until an appropriate signal is applied to the gate electrode. The SCR is the solid-state equivalent of the thyratron tube.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3991a8ed-3bb0-4c68-9783-7c25848775e9',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/silicon-controlled-rectifier-scr',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explode',
    'description' => ' Changing in chemical and physical state usually from a solid or liquid to a gas, by sudden chemical decomposition or vaporization.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3b04f5b7-1fac-4009-8a9b-f1a10ba3e37c',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/explode',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Private Sector Included',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '3b4b506e-ea58-48de-8157-8de2efdfdff4',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/private-sector-included',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hypergolic',
    'description' => ' A substance capable of igniting spontaneously upon contact.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3c9a7568-2ef4-4f1a-8635-a334c7773593',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/hypergolic',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Striker',
    'description' => ' An extension of a firing pin, which strikes a primer or other charge to initiate an arming, but not a firing or explosive train.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3caa5ba0-49b5-4689-a4bd-d495f87eedf9',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/striker',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Sensitizer',
    'description' => ' A substance that increases the sensitivity of an explosive.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3e8ff291-82fe-43a9-af4d-e07330bf0252',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/sensitizer',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'No Foreign',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '41111b92-0dee-4e76-b68d-0814992f0612',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/no-foreign',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Academic Reports',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 12,
    'uuid' => '4205db01-d2e9-464a-b4d6-dc249848a4e2',
    'vocabulary_machine_name' => 'reports',
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/academic-reports',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Integrated Circuit (IC)',
    'description' => ' A circuit whose output waveform is the time integral of one or more input waveforms.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '42ad69e7-5fa6-4271-97f9-484a648c5bc2',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/integrated-circuit-ic',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Relay',
    'description' => ' An element of a fuze\'s explosive train which augments an outside or otherwise inadequate output of a prior explosive component so as to reliably initiate a succeeding train component. Also, a protective or control device that completes or breaks into an electrical circuit in response to electrical changes in an external circuit.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '43410e4d-41e9-40cc-a68f-0cc3623e22f9',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/relay',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Briefing',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4432597e-1161-4a35-8274-664efcbe0f9e',
    'vocabulary_machine_name' => 'training_education',
    'url_alias' => array(
      0 => array(
        'alias' => 'training-education/briefing',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'WBIED',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => '450ac0fd-191f-4c44-ae3c-738c37d7d5f3',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/wbied',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'Slug',
    'description' => ' (1) As pertains to shaped-charge ammunition, a massive and relatively slow-moving remnant of the collapsed metal liner as distinguished from the jet. (2) A solid cast iron projectile. (3) Small arms ammunition up to and including .50 caliber and shotguns.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '45512f63-24a3-4dd0-b7f7-236def05f1b7',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/slug',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Emplace',
    'description' => ' To put in place or position.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '45d15958-38c1-47db-b655-b949933d430a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/emplace',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explosive',
    'description' => ' A substance or mixture of substances, which may be made to undergo a rapid chemical change without an outside supply of oxygen, with the liberation of large quantities of energy generally accompanied by the evolution of hot gases. Explosives are divided into two classes, high explosives and low explosives, according to their rate of reaction in normal usage. Certain mixtures of fuels and oxidizers can be made to explode and these are considered to be explosives. However, a substance such as a fuel that requires an outside source of oxygen or an oxidizer that requires an outside source of fuel to explode is not considered an explosive.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '45f6a7cd-120a-4221-827d-98b31a1c127d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/explosive',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'East Asia',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '46889eae-af01-4274-ab2c-1980ce533cbc',
    'vocabulary_machine_name' => 'incidents_location',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'incident-locations/east-asia',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NCTC',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '468f444e-4b1a-4d8d-a96a-b0952fd98a27',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/nctc',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Solder',
    'description' => ' A metal alloy with a low melting point that is melted in order to fuse metal objects together.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '46df5a4a-e756-4dce-8d5d-ad0d98e225a2',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/solder',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Blast Wave',
    'description' => ' A sharply defined wave of increased pressure rapidly propagated through a surrounding medium from a center of detonation or similar disturbance.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '47d3a7f1-6306-4227-8de8-2904a6480602',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/blast-wave',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Pyrotechnic',
    'description' => ' A mixture of chemicals which, when ignited, is capable of reacting exothermically to produce light, heat, smoke, sound or gas, and may also be used to introduce a delay into an explosive train because of its known burning time. The term excludes propellants and explosives.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '49082f86-df2a-48f1-8fd0-52c8c2722452',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/pyrotechnic',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Federal Joint Product',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '492a4c17-f0bb-4af0-9980-55d6c816f148',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/federal-joint-product',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Polystyrene',
    'description' => ' A rigid clear thermoplastic polymer that can be molded into objects or made into foam used to insulate refrigerator.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4a881cdf-3527-408a-bc4b-d35ed0e6950b',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/polystyrene',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Awareness',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '4b5c39c9-5769-48c2-8e9a-ad7eebae9458',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/awareness',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Food and Agriculture Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4b5dda30-4aa9-483c-b699-fadd120c7d31',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/food-and-agriculture-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'II',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '4b6318e4-624e-40dd-836e-a912f64145bb',
    'vocabulary_machine_name' => 'federal_region',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'federal-region/ii',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Extremist Source Derived',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '4cb7fc3b-46dd-4582-b73f-73d359761d2a',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/extremist-source-derived',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Primer',
    'description' => ' A relatively small and sensitive component of an explosive train. Upon actuation it initiates functioning of the explosive train. However, It will not reliably initiate a main high explosive charge. In general, primers are classified by method of initiation, e.g. percussion, electric, friction, etc. The term is also used to refer to the assembly that ignites propelling charges.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4ee852bd-50d1-4bb1-8a3f-403c6f4b0cac',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/primer',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Low-order Detonation',
    'description' => ' Chemical reaction in a detonable material in which the reaction front advances with a velocity that is appreciably lower than that which is the characteristic detonation velocity for the material in question. In a low-order detonation, the ordnance case usually breaks into several large fragments rather than many small ones.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4fc0af0a-dd88-4705-bd68-03d4fddb08fd',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/low-order-detonation',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Presentation',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5097aedd-7025-4fab-8e3c-9f3f90007af9',
    'vocabulary_machine_name' => 'training_education',
    'url_alias' => array(
      0 => array(
        'alias' => 'training-education/presentation',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'IED Profile',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '50f57fde-3d67-4e37-bdc5-e7fee78521de',
    'vocabulary_machine_name' => 'document_types',
    'url_alias' => array(
      0 => array(
        'alias' => 'document-types/ied-profile',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Nuclear Reactor, Materials, and Waste Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '516bdf73-17dd-4abe-aecb-7ab02df27a91',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/nuclear-reactor-materials-and-waste-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Chemical Agents',
    'description' => ' Poisonous gases, liquids or solids that have toxic effects on people, animals, or plants. Severity of injury depends on the type and amount of the chemical agent used and the duration of exposure.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '520d6942-b543-474f-ae0c-84de5ecd37e4',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/chemical-agents',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'TRIPwire Weekly and Monthly Reports',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '523aaf1a-6d82-4450-ba74-4199bb0db5a7',
    'vocabulary_machine_name' => 'reports',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/tripwire-weekly-and-monthly-reports',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Border Reports',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '534948cb-953f-49c2-8b42-82c2ec241f2d',
    'vocabulary_machine_name' => 'reports',
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/border-reports',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Pressure Plate',
    'description' => ' A component of, or addition to, an item of ordnance especially a landmine to enlarge the pressure-sensitive area of the item.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '53b2ed78-c2ae-4cee-a850-3a572a5ddc1a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/pressure-plate',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'TATP',
    'description' => ' An acronym for triacetone triperoxide.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5430f47b-d035-4f9c-aa57-c0e2996c31c1',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/tatp',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Device Description',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/device-description',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Exploding Bridge Wire',
    'description' => ' A term used to describe an initiator or system in which a very high energy electrical impulse is passed through a bridge wire, literally exploding the bridge wire and releasing thermal and shock energy capable of initiating a relatively insensitive explosive in contact with the bridge wire.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '566cffac-0d2c-4550-aab2-a6f70277abfa',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/exploding-bridge-wire',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electric Switch',
    'description' => ' A device component that provides for the transfer of an electrical signal input from one component to another by means of electron tube or solid-state circuits.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '57754141-49c9-4baa-81ea-108d8042fb3e',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/electric-switch',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Defense Industrial Base Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5781082f-a92b-4404-8419-4ede7df3387b',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/defense-industrial-base-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hydroscopic',
    'description' => ' A substance having the tendency to absorb and hold water, particularly moisture from the air.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '57cf2ab0-dd0d-4549-9ba1-59e2eced4ce1',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/hydroscopic',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Private Sector Awareness Documents',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '5abfcb85-6d40-4393-b1fd-8978c9463190',
    'vocabulary_machine_name' => 'reports',
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/private-sector-awareness-documents',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Sensitivity',
    'description' => ' An explosive\'s susceptibility to initiation by externally applied energy.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5b8c0e98-b148-4351-979c-633afd2509d3',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/sensitivity',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'PDF, DOC, DOCX',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '5bc6ed3a-ca29-4c1a-b37a-211def218e17',
    'vocabulary_machine_name' => 'document_types',
    'url_alias' => array(
      0 => array(
        'alias' => 'document-types/pdf-doc-docx',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Cook-off Time',
    'description' => ' The time required for a weapon to explode or deflagrate (to low order) when exposed to heat or fire.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5cdcd5dd-ef5c-482c-b830-0733e00e5e91',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/cook-time',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Anti-lift Device',
    'description' => ' A device or switch arranged to detonate the landmine or explosive device to which it is attached, or to detonate another mine or charge nearby if the mine is disturbed.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5e1c1f2f-78e0-4325-8ceb-78e5031abd44',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/anti-lift-device',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Composition C-4',
    'description' => ' C-4 contains RDX and has a greater shattering effect than its predecessor.  It is the successor to C-3 and has replaced it.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5e58c4b3-453f-4bad-b29d-5572bc832326',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/composition-c-4',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Booster',
    'description' => ' A high explosive element, sufficiently sensitive to be actuated by small explosive elements and powerful enough to cause detonation of the main explosive filler.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5f4316db-76b2-4f33-bde3-e294ea37f26e',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/booster',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'ANAL',
    'description' => ' An acronym for ammonium nitrate and aluminum powder.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '601d4db6-5741-411b-80d8-2db2f047c3fa',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/anal',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Precursor',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '604c838d-6075-47ea-b5d6-18e54bba5e95',
    'vocabulary_machine_name' => 'ied_profiles',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-type/precursor',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'HME',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => '629c0358-db31-46c4-82ef-762252fae927',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/hme',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Water Cannon',
    'description' => ' A unique explosive ordnance disposal (EOD) tool designed to project a stream of water at high velocity.  Used to remotely disrupt IED\'s and open containers.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '636aa7bd-15de-4b19-bc44-9114a9ff963b',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/water-cannon',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Transportation Systems Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '64931096-2f1f-4a44-96c8-00afd4024d74',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/transportation-systems-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Arrest',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '649b4b4a-e8be-4abc-99ef-3edf3ba57c0c',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/arrest',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Disrupter',
    'description' => ' An explosively powered tool used to enter a container of an lED and disrupt fuzing and fuzing system components.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '67ca95eb-2433-4cd9-bde9-28524b62afe2',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/disrupter',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Extremists Threat Reports (ETRs)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '69acaa4d-bea9-49fb-9203-136af0b8c1f0',
    'vocabulary_machine_name' => 'reports',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/extremists-threat-reports-etrs',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Semiconductor',
    'description' => ' An electrical conductor having a resistance between that of metals and insulators; neither a good conductor nor a good insulator.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6ad1857a-b8fe-4271-87c9-4373261d2eaa',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/semiconductor',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Render Safe Procedure (RSP)',
    'description' => ' The portion of an explosive ordnance disposal procedure designed to preclude the detonation or functioning of explosive ordnance or IEDs usually by application of specialized tools and techniques to interrupt functions or separate essential components of the explosive ordnance item or IED.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6ad4c4f5-b8a2-48f0-878d-44b6a0c4bb82',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/render-safe-procedure-rsp',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explosive Material',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '6c48b408-cadd-438c-a1b9-85df15964bc7',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/explosive-material',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'Shock Wave',
    'description' => ' The continuously propagated pressure pulse formed by the blast from an explosion in air, under water, or under ground.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6cbd42a0-bc53-42ad-9dfb-7564f186a37c',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/shock-wave',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Blasting Machine',
    'description' => ' A key or hand-operated machine which is used to generate an electrical impulse (may be a generator or capacitor discharge system).
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6d6623b9-e4dc-47e1-ab14-a55a91044221',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/blasting-machine',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Fusing, blasting time',
    'description' => ' A flexible, water-resistant, fabric-covered cord containing a black powder core that burns at a known rate from one end to the other, providing a time delay proportional to the length of fuse.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6e19d9d8-6c13-496b-ade8-ab90c72c92db',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/fusing-blasting-time',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'CBRNE',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '6e6dd29c-b87d-4841-8c88-9d6a2ef91a78',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/cbrne',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Deflagration',
    'description' => ' The rapid burning of an explosive, at subsonic speed, along the surface of the explosive.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6ec6e680-cf50-4eff-a7cb-146ed015c153',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/deflagration',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Armature',
    'description' => ' A moving element in an electromechanical device such as the rotating part of a generator or motor, the movable part of a relay, or the spring-mounted, iron portion of a bell or buzzer.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6f174dc7-e293-47a7-99e2-c782503e4ea9',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/armature',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Standoff',
    'description' => ' The distance between the base of the charge or liner of shaped-charged ordnance and the target at the time of initiation.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '700f3fba-727d-48ed-bd53-6fe372f04ff3',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/standoff',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Mild Detonating Cord',
    'description' => ' An explosive cord consisting of a multi-layer (coaxial) arrangement with a central core of high explosive. The outer layer consists of an inner lead sheath, a pyrotechnic material, an outer lead sheath, and an external polyethylene sheath. It is used for transferring explosive waves from one explosive component to another. Boosters are located on each end of mild detonating cord.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7033c336-6011-4bf9-833e-58d27188a343',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/mild-detonating-cord',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Nitration',
    'description' => ' The process of treating or combining with nitric acid or a nitrate; the conversion of an organic compound into a nitro compound or a nitrate.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '706e8f8f-c035-4039-bbe0-f8dfacd675dc',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/nitration',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Private Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '70baf5ea-6b61-4249-949b-e59b57d0f2d1',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/private-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explosive Incendiary Device',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '7171cdb4-1016-44ab-accb-4e796dd2e580',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/explosive-incendiary-device',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'Commercial/Toxic Industrial Materials',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 13,
    'uuid' => '7190f8ea-3347-4d5e-8073-d3d1261a5e68',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'field_ied_profile_sub_type' => array(),
    'field_ied_profile' => array(),
    'field_incidents_location' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-sub-type/commercialtoxic-industrial-materials',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Nitroglycerin',
    'description' => ' A colorless liquid at ordinary temperatures. It is a very powerful and sensitive high explosive used in dynamite and in some propellant mixtures. Also spelled "nitroglycerine."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '72b8e6c6-e7db-4b50-9005-bf1ec0804a74',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/nitroglycerin',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Distillation',
    'description' => ' (1) The volatilization or evaporation and subsequent condensation of a liquid, as when water is boiled in a retort and the steam is condensed in a cool receiver. (2) The purification or concentration of a substance, the obtaining of the essence or volatile properties contained in it, or the separation of one substance from another, by such a process.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7691b8ab-9970-4d5b-96fa-939e92b5fff1',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/distillation',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Academia',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => '785ea456-012a-4635-8fa8-a582e6356a45',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/academia',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Entropy',
    'description' => ' A measure of the spontaneous dispersal of energy at the molecular level.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '78e0f595-7dfd-4d14-9c16-d10d6d672573',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/entropy',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Blast Effect',
    'description' => ' Damage to structures and personnel by the force of an explosion on or above the surface of the ground. Blast effect may be contrasted with the catering and the ground-shock effect of a projectile or charge which goes off beneath the ground.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7983029e-4cb7-4aad-a022-5a545b1988ce',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/blast-effect',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Schematic Drawing',
    'description' => ' A line drawing showing the Interconnection of the various circuits within a component using conventional symbols to represent the detail parts.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7a9e1196-f318-4657-8a6f-c3b64d5c1971',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/schematic-drawing',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Critical Manufacturing Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7c24bb1a-3409-4bbb-b620-6782a3f8b75b',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/critical-manufacturing-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Charge, Shaped inhibited',
    'description' => ' A shaped charge with a conical liner normally having a slightly thicker apex than the sidewall material and constructed of copper and some aluminum. The inhibitor, normally Lucite, is machine fitted into the liner to approximately one-half of the cone\'s depth.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7d81b3b7-aabc-4c76-8df0-fb7ae1d0c412',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/charge-shaped-inhibited',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'PETN',
    'description' => ' An acronym for pentaerythritol tetranitrate.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7d861383-9cb4-40b8-9d99-c98b1bbcd183',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/petn',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Main Line',
    'description' => ' An undetermined length of detonating cord laid out in a straight line or a ring, which permits branch line attachment. One end attaches to the initiation point (blasting cap) and the other end may attach to an explosive charge.  Sometimes referred to as a trunk-line.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7da23c86-4f0a-4659-9a6d-e9042fb1ed7e',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/main-line',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Dynamite',
    'description' => ' Dynamite was the first name introduced for a commercial explosive that is a mixture of nitroglycerin and Guhr dynamite or nitroglycerin and nitrocellulose.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7da4dd3f-d5ae-41df-b0e0-ffe61efb2dff',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/dynamite',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Latin America',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '7e0d3574-2a84-4ee3-b4cf-99b163aa4a1d',
    'vocabulary_machine_name' => 'incidents_location',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'incident-locations/latin-america',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Power Source',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '7e1aa087-5254-4b32-b317-3c2ff9f11a24',
    'vocabulary_machine_name' => 'ied_profiles',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-type/power-source',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Shock Tube',
    'description' => ' A modern initiation system that communicates a high-energy wave through a tube dusted with high explosives designed to initiate detonators.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7e268c4f-3bf3-4092-b83f-949d0bc02d0a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/shock-tube',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Oxidize',
    'description' => ' To combine with oxygen or make into an oxide.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7ee6b181-13f1-4d4c-83ef-b29401d63c08',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/oxidize',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Igniter Train',
    'description' => ' Step by step arrangement of charges in pyrotechnics by which the initial fire from the primer is transmitted and intensified until it reaches and sets off the main charge, also called "burning train."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7fe77f90-1698-4bf6-9ae8-21faeb12ba0f',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/igniter-train',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'ANNIE',
    'description' => ' An acronym for ammonium nitrate and nitrobenzene.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '804ebba5-8ec4-46f8-9c54-86aa31b21915',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/annie',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explosive Ordnance Disposal (EOD)',
    'description' => ' The detection, identification, field evaluation, safe rendering, recovery, evacuation, and disposal of explosive ordnance which has been fired, dropped, launched, projected, or placed. It also includes the rendering safe and/or disposal of ordnance that has become hazardous or unserviceable by damage or deterioration when the disposal of such ordnance is beyond the capabilities of personnel normally assigned the responsibility for routine disposition.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '81e42726-4b9f-4969-97b3-a8b3de1c0415',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/explosive-ordnance-disposal-eod',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Library',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '8220e667-712a-4019-8557-41177a59d189',
    'vocabulary_machine_name' => 'document_types',
    'url_alias' => array(
      0 => array(
        'alias' => 'document-types/library',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Financial Services Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '844faf59-ff48-43ae-83c9-6933e3dce84f',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/financial-services-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Anonymous Included',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '84a84a7e-ea00-460d-95e6-4c21db7ea360',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/anonymous-included',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Deflagration-to-Detonation Transfer (DDT)',
    'description' => ' A detonation that begins with a deflagration initiated by some relatively weak energy source that accelerates through interactions with its surroundings into a coupled shock-wave reaction zone structure characteristic of a detonation.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8543da0a-ad88-471c-8dbf-8934b2239ff1',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/deflagration-detonation-transfer-ddt',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'VBIED',
    'description' => ' An acronym for vehicle-borne improvised explosive device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '85a57720-35a6-44c8-87a5-ce2170b96791',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/vbied',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Trend',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '85b8ca1d-4206-4bbe-a436-43e0c20ee783',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/trend',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Intermediate Charge',
    'description' => ' The second charge inside an electric or non-electric blasting cap, detonated by the ignition charge.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '87b6476d-71e9-4703-b578-ae5dc5a60256',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/intermediate-charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Delay',
    'description' => ' A mechanical, electronic, chemical or explosive train component that introduces a controlled time delay in some phase of the arming or functioning of a fuze.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '87f265a5-c748-4a41-900a-a448c3d1ee52',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/delay',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Short Circuit',
    'description' => ' An abnormal connection of relatively low resistance between two points of a circuit. The result is a flow of excess current between these points.  Also called a "short."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '886b1621-5f76-40d0-a033-82c07b6061c8',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/short-circuit',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Charge, Shaped Linear',
    'description' => ' A semi-rigid, metal-clad container fabricated in various lengths and widths filled with explosive and used for linear cutting of metallic items of various thickness.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '892c87c0-6100-42eb-b6b5-9466fc369846',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/charge-shaped-linear',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Base Charge',
    'description' => ' Secondary high explosives that are sometimes added in small amounts to blasting caps to boost their power.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '898f4ce6-a750-4b28-bc35-8145558d97fe',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/base-charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Exudation',
    'description' => ' The emission of any substance (usually oily, tarry, or gaseous) from an explosive item, generally, the results of chemical reaction or pressure due to thermal changes.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '89aaa556-03bd-409d-b0da-56c080594c6c',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/exudation',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'ANS',
    'description' => ' An acronym for ammonium nitrate and sugar.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8a2c6f57-c804-495d-9859-c3e541bdf986',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/ans',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'ANFO',
    'description' => ' An acronym for ammonium nitrate and fuel oil.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8b3547a6-615a-4d81-822f-b14f9406d971',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/anfo',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Plasticizer',
    'description' => ' An additive to a propellant or high explosive that makes the finished product less brittle.  They soften the substance so that it can be molded or cut into different shapes.  They also reduce the substance\'s ability to absorb water.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8c1842e5-885d-418b-b717-c8632c06db2e',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/plasticizer',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Shrapnel',
    'description' => ' Fragments, usually of metal, from an exploded artillery shell, mine, or bomb.  Bomb makers will add small lead or steel balls to an IED in order to increase the lethality of a device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8c2cf45e-d6b8-4625-9f5b-985e5cd20aba',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/shrapnel',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Information Technology Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8c71f85a-d0e2-4aba-8a5a-3bdb2c357c76',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/information-technology-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Transistor',
    'description' => ' An electronic device for amplification and/or control. Consists of a semi-conducting material to which contact is made by two or more electrodes which are usually metal points or surfaces soldered to the semiconductor. It has the capability of performing many of the functions of a vacuum tube, but is itself a non-vacuum device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8d101a32-a0a0-4976-802d-fd900aae36f0',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/transistor',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Arming Delay',
    'description' => ' A mechanical, pyrotechnic, or electrical device designed for attachment to a fuze to delay the start of fuze arming.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8d83ee27-3f4f-43a8-9994-37488b50eaec',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/arming-delay',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Sector-Specific Agencies',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8da97873-208c-42c0-b600-1bdfcd9771ff',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/sector-specific-agencies',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Fluted Liner',
    'description' => ' Shaped charge ordnance, a liner with grooves (flutes) on one or both of the surfaces.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8dba80ce-01d4-4bfb-ae62-b1107a2de005',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/fluted-liner',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'TNT',
    'description' => ' An acronym for trinitrotoluene.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8de0bf60-69fa-4741-9137-6c94a6cf12b7',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/tnt',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Chemical Weapons',
    'description' => ' A chemical substance whose use is intended to cause temporary loss of performance, permanent injury, or death in living processes.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8e4f8bf4-6624-4956-8df8-4827923c9a79',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/chemical-weapons',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Non-Electric',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '8f1eb0f6-35f3-4af9-a7ab-f5565872be02',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'field_ied_profile_sub_type' => array(),
    'field_ied_profile' => array(),
    'field_incidents_location' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-sub-type/non-electric',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Delay Arming',
    'description' => ' The interval expressed in time or distance between the instant the ordnance carrying a fuze is initiated and the instant the fuze becomes armed.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '901cec71-c8b8-4032-b466-7921e24770cf',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/delay-arming',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Dams Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '910766aa-6a7b-4dc5-9f81-502043939cfa',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/dams-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Mechanical Energy',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => '914558cb-a65c-440a-b77d-078f0ea158e3',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'field_ied_profile_sub_type' => array(),
    'field_ied_profile' => array(),
    'field_incidents_location' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'mechanical-energy',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Incident',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '9313921f-238d-4a2c-8c19-312e76476c5d',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/incident',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Switch',
    'description' => ' A device that opens or closes an electrical current. Explosive devices may utilize multiple sophisticated switching systems.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9383a14a-19c9-4c1b-8f2b-1cdbae473ad8',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/switch',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Fuze',
    'description' => ' (1) A device with explosive components designed to initiate a train of fire or detonation in ordnance by an action such as hydrostatic pressure, electrical energy, chemical, impact, mechanical time, or a combination of these. (2) A nonexplosive device designed to initiate an explosion in ordnance by an action such as continuous or pulsating electromagnetic waves, acceleration or deceleration forces, or piezoelectric action. *Note - For uniformity, the Department of Defense has prescribed the spelling "fuze" for the above senses; however, the spelling "fuse" is preferred in all senses by the British and by some nonmilitary authorities in the United States.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '951aa14a-4607-4c14-95f9-f56bb70194fa',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/fuze',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'JIDO Reports',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '953df48d-3d15-455a-b94d-d2abafc1d065',
    'vocabulary_machine_name' => 'reports',
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/jido-reports',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Material Fatigue',
    'description' => ' Method employed in certain fuzes to achieve a long-delay functioning feature by subjecting such components as metal or plastic wires or disks to continuous stress (usually spring pressure) to cause the component to weaken slowly at a predictable rate. After a predetermined time, the component yields, usually releasing a spring-loaded firing pin.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '957178e7-4385-46eb-91d9-222cf64150c5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/material-fatigue',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Detonating Cord',
    'description' => ' Flexible fabric tube containing a filler of high explosive intend to be initiated by a blasting cap. Also called "Primacord."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '96a3ee60-77a6-4b51-8da8-0b386fb2e9bc',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/detonating-cord',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Cordite',
    'description' => ' A smokeless, slow-burning powder composed of 30 to 58 percent nitroglycerin, 37 to 65 percent nitrocellulose, and 5 to 6 percent mineral jelly.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '970e4679-4225-445b-921e-101194039e6b',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/cordite',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ground',
    'description' => ' A metallic connection to establish ground potential in order to not disturb the operation of an electrical circuit. It is also the voltage reference point in a circuit.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '97181746-52bf-4048-b18c-3c80b7a4413b',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/ground',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'UXO',
    'description' => ' An acronym for unexploded ordnance. Unexploded explosive ordnance which has been fired, dropped, projected, placed or launched but remains unexploded by malfunction, design or other cause and has become a hazard to operations, personnel or infrastructure.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9790a925-df9c-464e-8ce7-62ad12eae1cb',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/uxo',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'CBRN',
    'description' => ' An acronym for Chemical, Biological, Radiological, and Nuclear
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '98127f70-7bdd-443d-ba63-de4060ceab55',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/cbrn',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Booby Trap',
    'description' => ' A device, with an explosive or non-explosive element, deliberately placed to cause casualties when an unsuspecting victim disturbs an apparently harmless object or performs a normally safe act.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '986aeb34-e5f2-42f0-8165-9a9aee0f3086',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/booby-trap',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Baroswitch',
    'description' => ' Performs electrical switching functions by mechanical actuation triggered by changes in atmospheric pressure. It generally consists of an aneroid diaphragm mechanically linked either to a contact point which opens and/or closes electrical circuits, or to a contact arm which slides over a conunutator whose separate segments are connected to signal circuits used in radio signal modulations.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '98948d6b-6578-4c41-bf4b-d4d059108ae8',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/baroswitch',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'LVBIED',
    'description' => ' An acronym for large vehicle-borne improvised explosive device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '98b2adc9-50d3-4fe2-b746-8389a26954db',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/lvbied',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'HMTD',
    'description' => ' An acronym for hexamethylene triperoxide diamine.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9a9e6c72-a665-4fec-b8c1-4ba25bcd3649',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/hmtd',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Military/Weaponized',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 14,
    'uuid' => '9b980a40-6766-4fea-8559-d4a0f9d88a1c',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'field_ied_profile_sub_type' => array(),
    'field_ied_profile' => array(),
    'field_incidents_location' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-sub-type/militaryweaponized',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Brisance',
    'description' => ' Property of an explosive which characterizes its shattering (shock force) effect.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9bbf0378-b246-45a8-84ce-d9f0de6d4400',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/brisance',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Safety Fuse',
    'description' => ' A pyrotechnic contained in a flexible and weatherproof sheath burning at a timed and constant rate, used to transmit a flame to the detonator.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9be5fa5a-9eb2-403d-80fc-62a56683970a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/safety-fuse',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Overpressure',
    'description' => ' The pressure resulting from the blast wave of an explosion. It is referred to as "positive" when it exceeds atmospheric pressure and "negative" during the passage of the wave when resulting pressures are less than atmospheric pressure.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9cc30ded-6aea-4ba3-acd3-c5676fbfb8d7',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/overpressure',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electric',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '9dc61520-9118-4bf4-8d6f-36a383f436b7',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'field_ied_profile_sub_type' => array(),
    'field_ied_profile' => array(),
    'field_incidents_location' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-sub-type/electric',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explosive Slurry',
    'description' => ' Thick liquid solution of oxidizers and fuels, blended with solid oxidizers and fuels with sensitizers.  They are safer to use than dynamite, and some may be cap sensitive, while others are blasting agents.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9e9c7346-1734-4c7e-b4d3-a2b04ab0df9b',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/explosive-slurry',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Powder Train',
    'description' => ' The train, usually of compressed black powder, is used to obtain time action in older fuze types.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9f68e647-515e-46e7-8d8f-b56e4f342b58',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/powder-train',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Catalyst',
    'description' => ' A substance that increases the speed of a chemical reaction.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9f7a7a9c-b102-4e75-a99c-d3d8560e836d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/catalyst',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Enhancements',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '9fc05f31-0a80-4e87-b8d6-0219d3c7d4c7',
    'vocabulary_machine_name' => 'ied_profiles',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-type/enhancements',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Impact Sensitivity',
    'description' => ' The susceptibility of an explosive to initiation by externally applied energy in the form of impact.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9fd3318f-cccb-4907-ad29-ee99416f70a1',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/impact-sensitivity',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'ANNM',
    'description' => ' An acronym for ammonium nitrate and nitromethane.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a07e280d-936b-47bc-8e70-79144f743e1d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/annm',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Detonator',
    'description' => ' An explosive train component that can be activated by either a non-explosive impulse or the action of a primer.  Should be capable of reliably initiating high-order detonations in a subsequent high explosive component of an explosive train. Detonators are classified in accordance with the method of initiation, such as percussion, stab, electric, and flash.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a333e862-0c92-41a6-9a9e-af2becc176db',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/detonator',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Other DOD',
    'description' => '<p>Non-JIDA</p>',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'a4f5661b-b234-4e4d-8875-331ff25f1ea5',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/other-dod',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Arming',
    'description' => ' As applied to weapons and ammunition; the changing from a safe condition to a state of readiness for initiation. Fuzes are generally caused to arm by such means as acceleration, rotation, clock mechanisms, chemical action, electrical action, air travel, pressure, or a combination of these.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a5d0be8b-153a-486e-b1e0-e1f3e9f48de9',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/arming',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Delay Train',
    'description' => ' An explosive train incorporating a delay.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a6c9438d-cdff-4b3e-a8a6-7ea37fcd7659',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/delay-train',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Precursor',
    'description' => ' A precursor is a material or substance used as an ingredient in a mixture to create an explosive.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a6f84335-dc9d-4304-9bcf-42b089f8cdde',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/precursor',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'TNT Equivalence',
    'description' => ' A standard unit of measure for explosives based on standard TNT.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a84309e6-21f2-4363-86b7-54e3bd10f11b',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/tnt-equivalence',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Secondary Device',
    'description' => ' A tactic in which a second device follows an initial bomb, real or hoax, targeting responding forces or other entities.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a9e921f6-1711-45a7-b6ee-4af8f737c7ce',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/secondary-device',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'IED',
    'description' => ' An acronym for improvised explosive device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'aa3da8ef-c45c-402d-a9e2-fb34e40f9476',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/ied',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Trembler Switch',
    'description' => ' A delicately balanced, often spring-mounted switch, usually electromechanical, designed to close when disturbed in any direction.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'aa7cbbd2-2b57-4913-83ce-4b500d879f5a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/trembler-switch',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Monroe Effect',
    'description' => ' The effect produced by a shaped charge. In Europe, sometimes called "Neumann effect."  When a liner shaped charge is used, the effect is termed "Mohaupt effect."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'aaf89b8e-00e9-46d9-98f0-78b7b6637aee',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/monroe-effect',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Detonation',
    'description' => ' A detonation is a chemical reaction that propagates with such rapidity that the rate of advance of the reaction zone into the material exceeds the velocity of sound in the material. The rate of advance of the reaction zone is termed "detonation rate" or "detonation velocity."  When this rate of advance attains such a value that it will continue without diminution through the entire material it is termed the "stable detonation velocity."  When the detonation rate is equal to or greater than the stable detonation velocity of the explosive, the reaction is termed a "high-order detonation." When the detonation rate is lower than the stable detonation velocity of the explosive the reaction is called a "low-order detonation."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ab650df8-4a14-4142-a958-f5735c3b841a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/detonation',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'DHS I&A Reports',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => 'abd66712-1509-451b-97de-d2e04922f406',
    'vocabulary_machine_name' => 'reports',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/dhs-ia-reports',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'DHS',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => 'ac13d12f-b9ad-4b75-9010-809388cf2244',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/dhs',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Weapons of Mass Destruction (WMD)',
    'description' => ' Weapons capable of producing mass casualties and/or extensive damage by use of nuclear, chemical/biological, or radiological means.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ad007d7b-48e8-4edb-83e1-13582b7c8ef6',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/weapons-mass-destruction-wmd',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Alternating Current (AC)',
    'description' => ' A flow of electric current in which charged particles making up the current alternately change their direction of flow.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'aff21a3f-874e-4e6a-922f-7d6e808ca442',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/alternating-current-ac',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Law Enforcement Sensitive (LES)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => 'b0c4b0a2-d5df-4a0e-bfa2-fb5f6056409e',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(
      'und' => array(
        0 => array(
          'value' => '(LES)',
          'format' => NULL,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/law-enforcement-sensitive-les',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Suspicious Package',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => 'b1769432-560f-4a25-9c62-3baca25373e1',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/suspicious-package',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Commercial Facilities Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b2440e15-eabf-44f9-be10-4625d88d7b66',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/commercial-facilities-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Charge, Shaped',
    'description' => ' An explosive charge shaped and designed as to concentrate a blast wave in one direction. Sometimes called "cavity charge."  Called "hollow charge" in United Kingdom.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b2a96af5-cc1f-445d-8b40-1adea1da4525',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/charge-shaped',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Closed Circuit',
    'description' => ' An electrical circuit that is continuously providing a complete path for the flow of current.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b2ecc94d-f10e-40ac-8097-d74364bfb8b2',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/closed-circuit',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'RCIED',
    'description' => ' An acronym for remote-controlled improvised explosive device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b382f761-b408-4eb3-8c81-29c7ccbc9e8d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/rcied',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Primer-detonator',
    'description' => ' A unit which consists of a primer, a detonator, and in some types an intervening delay.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b3e664f6-befc-4d66-b4a1-b1a8629ec2a5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/primer-detonator',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Igniter',
    'description' => ' Specially arranged charge of ready-burning composition used to assist the initiation of a propelling charge.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b49f8fd2-d12e-409f-807b-7e862c69daa4',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/igniter',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Incidents',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => 'b62979c8-76d9-4eda-9959-66611df5f6b8',
    'vocabulary_machine_name' => 'ied_profiles',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-type/incidents',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Primary High Explosive',
    'description' => ' An explosive which is extremely sensitive to heat and shock that is normally used to initiate a secondary high explosive. The term is generally used to refer to a pure compound rather than to an explosive mixture. A primary high explosive is capable of proceeding from deflagration to detonation in an extremely short distance and time, it can also propagate a detonation wave in an extremely small diameter column. Upon slow heating primary high explosives will generally decompose explosively while still in the solid state, while secondary high explosives will melt before undergoing an explosive reaction. This characteristic of primary high explosives is true for mercury fulminate, lead azide, lead styphnate, and tertracene. However, data are not available for all primary high explosives.  *Note - Some authorities recognize the term as "primary explosive" but not as "primary high explosive" maintaining that "high explosive" is an entirely separate entity.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b68f67b0-7009-4105-ba72-111086a20fa0',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/primary-high-explosive',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Charge',
    'description' => ' A given quantity of explosive either by itself or contained in a bomb, projectile, mine, etc. Also called "fill", "filler", or "filling."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b7edccfd-7d87-4d8f-9989-15a951db30fc',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Clock Delay',
    'description' => ' Safety device designed to delay the arming or firing of ordnance.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b8b5cefa-5f21-43ab-ac28-05b15be4f5de',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/clock-delay',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Federal Only',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'b8ef23af-074c-4ec4-aa27-4fd1ab19f79e',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/federal-only',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Emergency Services Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'baa45eee-ba0b-4e2b-a772-a5e5a60a81b7',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/emergency-services-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Thyristor',
    'description' => ' A bi-stable device comprising three or more junctions. At least one of the junctions can switch between reverse and forward voltage polarity within a single quadrant of the anode-to-cathode voltage-current characteristics.  Used in a generic sense to include silicon-controlled rectifiers and gate-control switches, as well as multi-layer two-terminal devices.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bc4007f3-dd23-485a-935c-ff49f752d338',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/thyristor',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Other Federal',
    'description' => '<p>Other Federal, non-DHS and/or non-FBI</p>',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'bc75f378-ea15-43c2-945a-cf96dfe1bf31',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/other-federal',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Biological Agents',
    'description' => ' Organisms or toxins that have illness-producing effects on people, livestock, and crops. A person affected by a biological agent requires the immediate attention of professional medical personnel.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bc795355-399f-4676-93fb-ce968ebde05d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/biological-agents',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Initiaton',
    'description' => ' (1) As applied to an explosive, the beginning of the deflagration or detonation of the explosive. (2) The first action in a fuze that occurs as the direct result of the action of the functioning medium or switch.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bca7c8c4-0376-43e4-8247-bc76783b990a',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/initiaton',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Filament',
    'description' => ' A fine wire heated electrically to incandescence in an electric lamp; a high-resistance wire or ribbon forming the cathode in some thermionic tubes.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bd0b1c47-6022-4534-907f-7278373f9a1e',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/filament',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Resistor',
    'description' => ' A device which opposes the flow of current in an electrical circuit.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bd854b5e-6df7-4ec9-a6f5-9b700df0a20e',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/resistor',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Arming Device',
    'description' => ' A device designed to perform the electrical and/or mechanical alignment necessary to permit the initiation of an explosive train.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'be5d8243-f89e-44ef-aaad-e9cb42a5ad9d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/arming-device',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'VOIED',
    'description' => ' An acronym for victim-operated improvised explosive device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bfe04585-3134-426b-8c4b-4771ad6dd3ee',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/voied',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ignition Charge',
    'description' => ' The most sensitive explosive material of an electrical or non-electrical blasting cap, which is initiated by a spark or flame.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c04c3dae-177d-4a38-92f0-8b43e1b75598',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/ignition-charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Spall',
    'description' => ' Fragment or fragments torn from either surface of armor plate resulting from the impact of kinetic energy ordnance, or the functioning of chemical energy ordnance.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c106d5a8-bbe8-412e-9da8-ca6fbc621bd2',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/spall',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'For Official Use Only (FOUO)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => 'c109443d-0440-48e0-8278-cde643dc8d48',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(
      'und' => array(
        0 => array(
          'value' => '(FOUO)',
          'format' => NULL,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/official-use-only-fouo',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'International',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => 'c25b667c-088e-45f8-b697-c1cf071f082f',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/international',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Energy Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c2da89bd-f847-410d-b064-12a6a0a7ae6b',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/energy-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bomb-Making Materials Stolen',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'c5362e55-edad-425e-a13e-b12c558653e4',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/bomb-making-materials-stolen',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Tamping',
    'description' => ' The process of tightly packing mud, wet sand, clay or other dense material on and around an explosive charge that has been placed on the surface of an obstacle, ordnance, etc.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c580d335-06fa-4024-a8da-10b7b03256a9',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/tamping',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Combustible Material',
    'description' => ' Substances that can be burned to provide heat and power.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c6be331e-76e1-4313-a9c9-009863b7fd53',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/combustible-material',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Misznay-Schardin Effect',
    'description' => ' The acceleration of a solid end plate (usually metal) from the face of an explosive charge under detonation, such that the end plate remains a solid and is usable as a missile.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c77a9adb-11cd-48f5-9f9e-70b778bf46b0',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/misznay-schardin-effect',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Initiator',
    'description' => ' A chemical compound or electric device that initiates a chain reaction.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c7f64652-0a24-4eaa-9e8b-a1ca89230421',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/initiator',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Composition C-3',
    'description' => ' A plastic military-grade explosive composed of RDX and plasticizers.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c8510231-908d-42ae-b9b4-2675a5f27805',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/composition-c-3',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'VBIED',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => 'c9a62a22-fce3-4691-9108-0211d0dd6a27',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/vbied',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'News',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 12,
    'uuid' => 'c9d05477-395e-4e96-9c5f-53184a8a3ce1',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/news',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Transformer',
    'description' => ' An electrical device having no continuously moving parts, which by electromagnetic induction transfers electrical energy from one or more circuits to one or more other circuits at the same frequency, usually with changed values of voltage and current.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c9e5cf65-b4d5-44e1-a1a5-b463e69bd2c5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/transformer',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'N/A',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => 'ca129cd5-3219-40fa-9c57-2eb2b25ded72',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/na',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'Flexilinear Shaped Charge (FLSC)',
    'description' => ' A flexible, linear shaped charge. The sheathing material may be lead, aluminum, copper, silver or other materials.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cb0e9ee1-5520-472d-84e1-4d15b736f6d5',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/flexilinear-shaped-charge-flsc',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Melt Loading',
    'description' => ' Process of melting solid explosive by heat, then pouring the explosive into bombs, projectiles, etc. Also called "cast loading."
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cb1cd74f-b37f-44d7-b998-67dcc01c7e08',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/melt-loading',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Solenoid',
    'description' => ' A current-carrying coil of wire that acts like a magnet when a current passes through it.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cb62b2a4-a6f7-44b2-ae01-ba257e10d8d3',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/solenoid',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'RC Timer',
    'description' => ' An electronic timing circuit consisting of a resistor and capacitor.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cc6a9325-8b86-44c7-9740-9cb75290d0cc',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/rc-timer',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Government Facilities Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cd0f8cf2-32c4-4799-853e-7fe5bf16c6ef',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/government-facilities-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'N/A',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cda1f7e5-e8be-43b9-bb75-fadc009f1bf2',
    'vocabulary_machine_name' => 'international',
    'url_alias' => array(
      0 => array(
        'alias' => 'international/na',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Triggering Device',
    'description' => ' An electrical device used in guided missiles to connect the fuze firing circuit to the detonators and detonate the warhead.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ce7b729b-ef4f-48c2-9e7b-25ca1f53c6e4',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/triggering-device',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Detonation Velocity',
    'description' => ' The velocity at which a detonation progresses through an explosive.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ceff24bf-ecfc-4a86-8616-011119f9f69d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/detonation-velocity',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explosive Ordnance',
    'description' => ' All munitions containing explosives, propellants, nuclear fission, fusion, or radiological materials, and chemical or biological agents.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cf22cfbd-491f-423a-9e79-0e69135bd633',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/explosive-ordnance',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Simultaneous detonation',
    'description' => ' The detonation of two or more charges at the same time.  Examples include using equal lengths of detonating cord and electric caps connected in series to explosive charges.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cf7b0574-5bcd-418c-9a77-bdf033e6c3fd',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/simultaneous-detonation',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'State and Local',
    'description' => '<p>State, Local, Tribal, Territorial (SLTT)</p>',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd01f2b90-fd66-4e26-a293-2f8ad0c8a153',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/state-and-local',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'All U.S. States and Territories',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd146c879-bf0a-42f6-a37f-54faeca3de8d',
    'vocabulary_machine_name' => 'state_territory',
    'url_alias' => array(
      0 => array(
        'alias' => 'stateterritory/all-us-states-and-territories',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Switch',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'd156adfd-e1e1-4a84-abf0-0c1a9580c294',
    'vocabulary_machine_name' => 'ied_profiles',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-type/switch',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bomb Techs Only',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => 'd16232ac-d174-4fd9-946e-1eff453e6d2a',
    'vocabulary_machine_name' => 'access_classification',
    'field_marking' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'classification/bomb-techs-only',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Mine',
    'description' => ' (1) Generally, a military-effect-producing device, usually explosive, which is placed in position and is subsequently fired in the proximity of a suitable target. It may be fired by some action of its target, by the passage of time, or by controlled means. (2) A landmine; designed for land or shallow-water use to destroy or damage vehicles, boats, or aircraft or to wound, kill, or otherwise incapacitate personnel. (3) A sea mine; intended for use in a water environment and designed to be effective against ships or other waterborne targets. (4) Acoustic mine; designed to be actuated by the sounds emitted by its target. (5) Clearance mine; the process of detecting and/or removing landmines by manual or mechanical means.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd18bf98d-8a4c-4f0a-81bc-575d8b7b22bb',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/mine',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Blasting Agent',
    'description' => ' An insensitive chemical composition or mixture which will detonate when initiated by high explosive primers or boosters.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd4f678c1-d00c-4d1e-a249-8b1cfac4e365',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/blasting-agent',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Training',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'd583f618-feaa-4bb4-8d4a-415c410449fb',
    'vocabulary_machine_name' => 'subject',
    'url_alias' => array(
      0 => array(
        'alias' => 'subject/training',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Slurry',
    'description' => ' Suspended particles in a viscuous liquid.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd6bdbe87-f58d-46ec-9ab8-df3400adcf7f',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/slurry',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electronic Countermeasures (ECM)',
    'description' => ' The division of electronic warfare involving actions taken to prevent or reduce an enemy\'s effective use of the electromagnetic spectrum.  In terms of IEDs, it is used to prevent the use of certain initiators.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd92065bd-07ca-4859-9efb-870e1964d8f1',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/electronic-countermeasures-ecm',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Schematic Diagram',
    'description' => ' A presentation of the element-by-element relationship of all parts of a system.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd9b205c8-2bac-44f6-b9c3-40160d4cd9cb',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/schematic-diagram',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Priming Composition',
    'description' => ' A physical mixture of material that is very sensitive to impact or percussion. When exploded, it undergoes very rapid auto-combustion, the products of which are hot gases and incandescent solid particles. Priming compositions are used to ignite primary high explosives, black powder igniter charges, etc.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd9b59c25-3142-41e1-8a57-a1c52db72d76',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/priming-composition',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'High Explosive',
    'description' => ' An explosive which normally detonates rather than deflagrates or burns, that is, the rate of advance of the reaction zone into the unreacted material exceeds the velocity of sound in the unreacted material. High explosives are divided into two classes according to their sensitivity to heat and shock: primary high explosives and secondary high explosives.  *Note - Some authorities maintain that high explosives and primary explosives are entirely separate entities.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'da8e88a1-5e60-4802-b903-2661948bf4df',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/high-explosive',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Communications Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'dad95ae2-ec8d-4a61-9b2b-493ce9c65fd7',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/communications-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'IED Attack',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => 'db5ddb44-bcde-4a5a-949c-d6981c23013c',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/ied-attack',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '019cc0a8-6abe-4827-9b3a-e4f256426f15',
    ),
  );
  $terms[] = array(
    'name' => 'Chemical Pressure Bomb',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => 'dbc04a46-aabe-46a0-b0a6-b2f015e9c029',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/chemical-pressure-bomb',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'Firing Circuit',
    'description' => ' The electrical circuit, by which a fuze, rocket, missile, etc. is fired.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dd8e5192-107a-4cbd-acdb-30dd7ea944b9',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/firing-circuit',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Spit-back Tube',
    'description' => ' As pertains to shaped-charge ordnance, a tube attached to the truncated apex of a liner, ordinarily extending through the explosive charge. Through this tube the detonating impulse is transmitted from the point of initiation to a detonator at the base of the explosive charge.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ddb69c4c-40d4-49fd-87bd-d518141f88e4',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/spit-back-tube',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Sympathetic Detonation',
    'description' => ' Explosion caused by the transmission of a detonation wave through any medium from another explosion.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ded011d0-b4ed-4833-bf7c-5bef58c8c1dc',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/sympathetic-detonation',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electrolyte',
    'description' => ' A conducting medium in which the flow of current is accompanied by the movement of matter in the form of ions.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'df79c77a-01a3-4bd1-a959-c4db0eeda140',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/electrolyte',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Shunt',
    'description' => ' A device that connects loose leg or lead wires from a detonator to protect against static electricity.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dffe92c6-939d-453f-a263-c48ccd60a77c',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/shunt',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Mohaupt Effect',
    'description' => ' The effect of a metal liner introduced in a shaped charge to increase penetration.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e005d14d-98b2-473c-adab-64c5799cb68f',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/mohaupt-effect',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Transducer',
    'description' => ' A device that converts the energy of one transmission system into the energy of another transmission system, such as mechanical energy into electrical energy.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e0269500-b0c5-458a-a7e1-42f2308642b8',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/transducer',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Delay Element',
    'description' => ' A component that provides a specified delay between actuation and ignition or detonation.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e05d02fb-f926-4dcd-9e18-ee28962db979',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/delay-element',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Module',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e06fc9f2-54ff-41e1-98a2-27ef46b5c8d1',
    'vocabulary_machine_name' => 'training_education',
    'url_alias' => array(
      0 => array(
        'alias' => 'training-education/module',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Initiating Agent',
    'description' => ' An explosive which has the necessary sensitivity to heat, friction, or percussion to make it suitable for use as the initial element in an explosive train.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e0b536d2-3633-48c6-97a8-8e2dfd4f826b',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/initiating-agent',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Fuse',
    'description' => ' An igniting or explosive cord, consisting of a flexible fabric tube and a core of low or high explosive.  Fuse with black powder or other low explosive cores are also known as blasting time fuse. Other names are "safety fuse," "Bickford fuse," and "blasting fuse." Fuse with PETN or other high explosive cores are called "detonating cord" or "Primacord" (a trade name). *Note - For uniformity, the Department of Defense has prescribed the spelling "fuze" for the above senses; however, the spelling "fuse" is preferred in all senses by the British and by some nonmilitary authorities in the United States.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e193dba6-e5f4-424c-9ceb-2a21019f2916',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/fuse',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Platter Charge',
    'description' => ' A type of shape charge that delivers a less-concentrated explosion than traditional shaped charges.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e2ce0ec3-4c61-436a-bab3-fcd1b86063eb',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/platter-charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bridge Wire',
    'description' => ' A resistance wire connecting the ends of the leg wires inside an electric detonator and which is embedded in the ignition charge of the detonator.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e38d6a45-dcde-49b0-b211-1784ed84aa84',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/bridge-wire',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Law Enforcement Awareness Reports',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => 'e47ae67a-e95e-43c6-bfcd-d7e550348ffe',
    'vocabulary_machine_name' => 'reports',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/law-enforcement-awareness-reports',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Healthcare and Public Health Sector',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e5dc6db4-6a57-4171-a90b-3a9107d2242f',
    'vocabulary_machine_name' => 'critical_infrastructure_category',
    'url_alias' => array(
      0 => array(
        'alias' => 'critical-infrastructure-category/healthcare-and-public-health-sector',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'FBI',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'e5ede93b-3a71-443f-bb4a-0af039696619',
    'vocabulary_machine_name' => 'author_publisher',
    'url_alias' => array(
      0 => array(
        'alias' => 'authorpublisher/fbi',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Shaped Charge',
    'description' => ' An explosive charge shaped so as to concentrate its explosive force in a particular direction.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e7986ef8-cf96-49db-96ab-cd549097e9d2',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/shaped-charge',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'U.S. and Canada',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e87bac3f-d509-447e-9b7a-083cc216c135',
    'vocabulary_machine_name' => 'incidents_location',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'incident-locations/us-and-canada',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Powder',
    'description' => ' An explosive in powder form, that is, in small granules or grains, such as black powder or smokeless propellant. No longer accepted as a general term for propellant or propelling charge.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e9fbfd4a-5a2e-40d4-9fd1-9bab4ec494d8',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/powder',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Delayed Arming',
    'description' => ' Classification term applicable to fuzes containing components such as a clockwork mechanism, powder train, reduction gear assembly, or capacitor-resistor network that functions extending the fuze arming period for a predetermined time following arming initiation.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ea0f20eb-96a8-436f-8c10-c6872c3a519d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/delayed-arming',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Binary Explosive',
    'description' => ' A high explosive derived from the reaction of two non-explosive or non-detonable constituents. Purpose of the mixture is to provide an explosive which is superior to its components in regard to sensitivity, fragmentation, blast, or loadability.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ead7304d-9cef-40df-82bb-b0f073d2cfc0',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/binary-explosive',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electrical Energy',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => 'eb0d37b9-3131-4bae-a0dc-b6c85a26de39',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'field_ied_profile_sub_type' => array(),
    'field_ied_profile' => array(),
    'field_incidents_location' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-sub-type/electrical-energy',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electrode',
    'description' => ' A conductor through which a current enters or leaves a nonmetallic medium.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ebb52265-9369-4a3b-9af7-71cd9f0b340d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/electrode',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electrical schematic',
    'description' => ' A drawing which shows the electrical circuit of an item with the parts indicated by symbols so placed that the circuit may be traced from part to part in the sequence of their respective functions, but which makes no attempt to indicate the actual physical location of the parts in the item.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ebe35b84-1013-44e5-a7b8-fc85aa97d432',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/electrical-schematic',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Electro-explosive',
    'description' => ' Term used to describe an initiator or a system that uses an electrical impulse for initiation of an explosive.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ec2f9c7e-3f74-4928-b03f-f94a2143d53f',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/electro-explosive',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'FBI Reports',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => 'ec81dd61-e388-481c-9d2c-97b2f638265d',
    'vocabulary_machine_name' => 'reports',
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/fbi-reports',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Plastic Explosive',
    'description' => ' Explosive that within normal ranges of atmospheric temperature is capable of being molded into desired shapes.  Some plastics, such as polyurethane or polybutadine, can be embedded in high-brissance crystalline explosives such as PETN.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ed3de011-0e9c-49a4-b4b2-f254c1eca414',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/plastic-explosive',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Exothermic',
    'description' => ' A chemical reaction that releases heat
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ee516b9f-c587-4491-b142-88c243d4db02',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/exothermic',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Initiator',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'efeafb0e-3f4c-4234-b0db-84bfcb68dbe4',
    'vocabulary_machine_name' => 'ied_profiles',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'ied-profile-type/initiator',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Blasting Cap',
    'description' => ' A small tube, usually copper or aluminum, closed at one end and loaded with a charge or charges of sensitive high explosives. They contain three separate charges: an ignition charge, an intermediate charge, and a base charge.  Non-electric blasting caps are detonated by the spit of flame or sparks from a time blasting fuse, electric blasting caps are provided with a means for firing by an electric current.  Most blasting caps contain a primary high explosive and may also contain a booster (considered more reliable for detonating secondary high explosives).
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f011a425-3e74-4ffa-931b-6384cf20d71c',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/blasting-cap',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Fuse Igniter',
    'description' => ' A device used to apply sparks or flame to manufactured or improvised safety fuse.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f0d7b7d1-9f97-4986-9adf-d7065f499223',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/fuse-igniter',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'TPU',
    'description' => ' An acronym for time/power unit.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f1728dc7-05e1-4092-b559-dba81b6ae603',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/tpu',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Stability',
    'description' => ' The property of an explosive to resist detonation or deterioration under normal storage conditions.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f175436e-c52f-45dc-9c9a-04a3ac38bb0e',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/stability',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Propellant',
    'description' => ' Provides the energy for propelling something: specifically explosive powder charges for propelling a bullet, shell, or the like. Also a fuel, either powder or liquid, for propelling a rocket or missile. It is specifically a low explosive substance or mixture of substances which, through burning, can be made to produce gases at controlled rates and to provide the energy necessary to propel ordnance.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f1d88b93-6c6f-4886-a8fb-44205220d69e',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/propellant',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'ATF',
    'description' => ' The Bureau of Alcohol, Tobacco and Firearms (ATF) enforces federal laws and regulations relating to alcohol, tobacco, firearms, explosives, and arson.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f5725b40-983d-4f88-affa-5a21d7ce1f72',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/atf',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'N/A',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f6fcd291-c0db-4c4a-81c2-d5a29a8602ba',
    'vocabulary_machine_name' => 'state_territory',
    'url_alias' => array(
      0 => array(
        'alias' => 'stateterritory/na',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Explosive Train (aka Explosive Chain)',
    'description' => ' A train of combustible and explosive elements arranged in the order of decreasing sensitivity inside a fuze, projectile, bomb, etc. The function of the explosive train is to accomplish the controlled augmentation of a small impulse into one of suitable energy to cause the main charge to function.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f7cb12c1-41aa-4785-b65d-37c8b34a3f0d',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/explosive-train-aka-explosive-chain',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Tripwire',
    'description' => ' A wire stretched across a footpath, connected to an explosive device and when pulled or tripped, functions the explosive device.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f9cc9e18-5f49-4b95-9486-45d200646a28',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/tripwire',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Emergency Responder Awareness Documents',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => 'faa04d2b-a496-4439-8f6c-79c3da27a9f1',
    'vocabulary_machine_name' => 'reports',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'library-report-type/emergency-responder-awareness-documents',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Dirty Bomb',
    'description' => ' An unconventional weapon that combines conventional explosives, such as dynamite, with radioactive materials. A dirty bomb is designed to spread radioactive material and contaminate a small area.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fb36d11f-ce20-4381-8930-ebdb02754518',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/dirty-bomb',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ordnance',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => 'fd7f6adc-76ad-4bbb-9644-142ba69a378e',
    'vocabulary_machine_name' => 'osint_map',
    'url_alias' => array(
      0 => array(
        'alias' => 'osint-map/ordnance',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '55d09b00-04a8-4db3-a2be-cede49f961ae',
    ),
  );
  $terms[] = array(
    'name' => 'Oxidizer',
    'description' => ' In an explosive or other chemical mixture (such as a propellant), a substance that provides the oxygen for the burning of a fuel.
							',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ff602cd3-e071-4bb3-9c19-9d34fbfe3f18',
    'vocabulary_machine_name' => 'glossary',
    'url_alias' => array(
      0 => array(
        'alias' => 'glossary/oxidizer',
        'language' => 'und',
      ),
    ),
  );
  return $terms;
}
