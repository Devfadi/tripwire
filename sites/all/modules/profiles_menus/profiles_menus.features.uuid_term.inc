<?php
/**
 * @file
 * profiles_menus.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function profiles_menus_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Main Charge',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '03130978-05c2-4253-aa79-cbc58ced4d13',
    'vocabulary_machine_name' => 'ied_profiles',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Improvised',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '0593f41c-3ec0-45f2-9cf0-92db9faf2ead',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Firing Switch',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => '1753d21c-403e-460e-948f-02ebd4b58c3b',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Near East and South Asia',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2c2b42c1-e8a7-477f-bc8d-f56370f147bf',
    'vocabulary_machine_name' => 'incidents_location',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Europe',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '339bcb2b-bab5-4acf-8737-6e7831a67e50',
    'vocabulary_machine_name' => 'incidents_location',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Africa',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '34968362-db9a-4246-b736-c2c0a8c8cc0a',
    'vocabulary_machine_name' => 'incidents_location',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'East Asia',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '46889eae-af01-4274-ab2c-1980ce533cbc',
    'vocabulary_machine_name' => 'incidents_location',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Main Charge Configuration',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '47285be5-1c29-4d2e-831f-59c231a9ab3b',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Precursor',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '604c838d-6075-47ea-b5d6-18e54bba5e95',
    'vocabulary_machine_name' => 'ied_profiles',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Commercial/Toxic Industrial Materials',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '7190f8ea-3347-4d5e-8073-d3d1261a5e68',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Latin America',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7e0d3574-2a84-4ee3-b4cf-99b163aa4a1d',
    'vocabulary_machine_name' => 'incidents_location',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Power Source',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '7e1aa087-5254-4b32-b317-3c2ff9f11a24',
    'vocabulary_machine_name' => 'ied_profiles',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Non-Electric',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8f1eb0f6-35f3-4af9-a7ab-f5565872be02',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Mechanical Energy',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '914558cb-a65c-440a-b77d-078f0ea158e3',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Military/Weaponized',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '9b980a40-6766-4fea-8559-d4a0f9d88a1c',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Electric',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '9dc61520-9118-4bf4-8d6f-36a383f436b7',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Enhancements',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '9fc05f31-0a80-4e87-b8d6-0219d3c7d4c7',
    'vocabulary_machine_name' => 'ied_profiles',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Low Explosives',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => 'b2bef4ad-f630-40d6-8a4c-b1b9eb56071d',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Incidents',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b62979c8-76d9-4eda-9959-66611df5f6b8',
    'vocabulary_machine_name' => 'ied_profiles',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'High Explosives',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => 'b923b1e3-2316-49c7-a4b2-388e35e0dd1f',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Arming Switch',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => 'd04aa47b-b66d-4f18-90ab-2a3684b2f4cb',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Switch',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'd156adfd-e1e1-4a84-abf0-0c1a9580c294',
    'vocabulary_machine_name' => 'ied_profiles',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'U.S. and Canada',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e87bac3f-d509-447e-9b7a-083cc216c135',
    'vocabulary_machine_name' => 'incidents_location',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Electrical Energy',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'eb0d37b9-3131-4bae-a0dc-b6c85a26de39',
    'vocabulary_machine_name' => 'ied_profile_sub_type',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Initiator',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'efeafb0e-3f4c-4234-b0db-84bfcb68dbe4',
    'vocabulary_machine_name' => 'ied_profiles',
    'url_alias' => array(),
  );
  return $terms;
}
