<?php
/**
 * @file
 * profiles_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function profiles_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_analysis_trends'.
  $field_bases['field_analysis_trends'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_analysis_trends',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_description_'.
  $field_bases['field_description_'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_description_',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_ied_profile'.
  $field_bases['field_ied_profile'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ied_profile',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'ied_profiles',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_ied_profile_sub_type'.
  $field_bases['field_ied_profile_sub_type'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ied_profile_sub_type',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'ied_profile_sub_type',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_incident_details'.
  $field_bases['field_incident_details'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_incident_details',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_incidents_location'.
  $field_bases['field_incidents_location'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_incidents_location',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'incidents_location',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_overview'.
  $field_bases['field_overview'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_overview',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_profiles_country'.
  $field_bases['field_profiles_country'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_profiles_country',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'United States' => 'United States',
        'Afghanistan' => 'Afghanistan',
        'Albania' => 'Albania',
        'Algeria' => 'Algeria',
        'American Samoa' => 'American Samoa',
        'Andorra' => 'Andorra',
        'Angola' => 'Angola',
        'Anguilla' => 'Anguilla',
        'Antarctica' => 'Antarctica',
        'Antigua-Barbuda' => 'Antigua-Barbuda',
        'Argentina' => 'Argentina',
        'Armenia' => 'Armenia',
        'Aruba' => 'Aruba',
        'Australia' => 'Australia',
        'Austria' => 'Austria',
        'Azerbaijan' => 'Azerbaijan',
        'Bahamas' => 'Bahamas',
        'Bahrain' => 'Bahrain',
        'Baker Islands' => 'Baker Islands',
        'Bangladesh' => 'Bangladesh',
        'Barbados' => 'Barbados',
        'Bassas Da India' => 'Bassas Da India',
        'Belarus' => 'Belarus',
        'Belgium' => 'Belgium',
        'Belize' => 'Belize',
        'Benin' => 'Benin',
        'Bermuda' => 'Bermuda',
        'Bhutan' => 'Bhutan',
        'Bolivia' => 'Bolivia',
        'Bosnia-Herzegovina' => 'Bosnia-Herzegovina',
        'Botswana' => 'Botswana',
        'Bouvet Island' => 'Bouvet Island',
        'Brazil' => 'Brazil',
        'British Indian Ocean Territories' => 'British Indian Ocean Territories',
        'British Virgin Islands' => 'British Virgin Islands',
        'Brunei' => 'Brunei',
        'Bulgaria' => 'Bulgaria',
        'Burkina Faso' => 'Burkina Faso',
        'Burma (now Myanmar)' => 'Burma (now Myanmar)',
        'Burundi' => 'Burundi',
        'Cameroon' => 'Cameroon',
        'Canada' => 'Canada',
        'Cape Verde' => 'Cape Verde',
        'Cayman Islands' => 'Cayman Islands',
        'Central African Republic' => 'Central African Republic',
        'Chad' => 'Chad',
        'Chile' => 'Chile',
        'China, People\'s Republic Of' => 'China, People\'s Republic Of',
        'Christmas Islands(Australian Ter)' => 'Christmas Islands(Australian Ter)',
        'Cocos Island' => 'Cocos Island',
        'Colombia' => 'Colombia',
        'Comoro Islands' => 'Comoro Islands',
        'Congo(Formerly Zaire)' => 'Congo(Formerly Zaire)',
        'Cook Islands' => 'Cook Islands',
        'Coral Sea Islands' => 'Coral Sea Islands',
        'Costa Rica' => 'Costa Rica',
        'Cote D\'Ivoire(Ivory Coast)' => 'Cote D\'Ivoire(Ivory Coast)',
        'Croatia' => 'Croatia',
        'Cuba' => 'Cuba',
        'Cyprus' => 'Cyprus',
        'Czech Republic' => 'Czech Republic',
        'Denmark' => 'Denmark',
        'Djibouti' => 'Djibouti',
        'Dominica' => 'Dominica',
        'Dominican Republic' => 'Dominican Republic',
        'Ecuador' => 'Ecuador',
        'Egypt' => 'Egypt',
        'El Salvador' => 'El Salvador',
        'Equatorial Guinea' => 'Equatorial Guinea',
        'Eritrea' => 'Eritrea',
        'Estonia' => 'Estonia',
        'Ethiopia' => 'Ethiopia',
        'Europa Island' => 'Europa Island',
        'Falkland Islands' => 'Falkland Islands',
        'Faroe Islands' => 'Faroe Islands',
        'Federal States of Micronesia' => 'Federal States of Micronesia',
        'Fiji' => 'Fiji',
        'Finland' => 'Finland',
        'France' => 'France',
        'French Guiana' => 'French Guiana',
        'French Polynesia' => 'French Polynesia',
        'French Southern and Antarcia Lands' => 'French Southern and Antarcia Lands',
        'Gabon' => 'Gabon',
        'Gambia' => 'Gambia',
        'Gaza Strip' => 'Gaza Strip',
        'Georgia' => 'Georgia',
        'Germany(Unified)' => 'Germany(Unified)',
        'Ghana' => 'Ghana',
        'Gibraltar' => 'Gibraltar',
        'Glorioso Islands' => 'Glorioso Islands',
        'Greece' => 'Greece',
        'Greenland' => 'Greenland',
        'Grenada' => 'Grenada',
        'Guadeloupe' => 'Guadeloupe',
        'Guam(U.S. Territory)' => 'Guam(U.S. Territory)',
        'Guatemala' => 'Guatemala',
        'Guinea' => 'Guinea',
        'Guinea-Bissau' => 'Guinea-Bissau',
        'Guyana' => 'Guyana',
        'Haiti' => 'Haiti',
        'Heard Island and McDonald Islands' => 'Heard Island and McDonald Islands',
        'Honduras' => 'Honduras',
        'Hong Kong (China)' => 'Hong Kong (China)',
        'Hungary' => 'Hungary',
        'Iceland' => 'Iceland',
        'India' => 'India',
        'Indonesia' => 'Indonesia',
        'Iran' => 'Iran',
        'Iraq' => 'Iraq',
        'Ireland' => 'Ireland',
        'Israel' => 'Israel',
        'Italy' => 'Italy',
        'Jamaica' => 'Jamaica',
        'Japan' => 'Japan',
        'Jarvis Island' => 'Jarvis Island',
        'Johnston Atoll(U.S. Territory)' => 'Johnston Atoll(U.S. Territory)',
        'Jordan' => 'Jordan',
        'Juan De Nova Island' => 'Juan De Nova Island',
        'Kampuchea(Cambodia)' => 'Kampuchea(Cambodia)',
        'Kazakhstan' => 'Kazakhstan',
        'Kenya' => 'Kenya',
        'Kingman Reef' => 'Kingman Reef',
        'Kiribati' => 'Kiribati',
        'Korea, North' => 'Korea, North',
        'Korea, South' => 'Korea, South',
        'Kuwait' => 'Kuwait',
        'Kyrgyzstan' => 'Kyrgyzstan',
        'Laos' => 'Laos',
        'Latvia' => 'Latvia',
        'Lebanon' => 'Lebanon',
        'Lesotho' => 'Lesotho',
        'Liberia' => 'Liberia',
        'Libya' => 'Libya',
        'Liechtenstein' => 'Liechtenstein',
        'Lithuania' => 'Lithuania',
        'Luxembourg' => 'Luxembourg',
        'Macau (China)' => 'Macau (China)',
        'Macedonia' => 'Macedonia',
        'Madagascar' => 'Madagascar',
        'Malawi' => 'Malawi',
        'Malaysia' => 'Malaysia',
        'Maldives' => 'Maldives',
        'Mali' => 'Mali',
        'Malta' => 'Malta',
        'Marshall Islands' => 'Marshall Islands',
        'Martinique' => 'Martinique',
        'Mauritania' => 'Mauritania',
        'Mauritius' => 'Mauritius',
        'Mexico' => 'Mexico',
        'Midway Islands' => 'Midway Islands',
        'Moldova' => 'Moldova',
        'Monaco' => 'Monaco',
        'Mongolia' => 'Mongolia',
        'Montenegro' => 'Montenegro',
        'Montserrat' => 'Montserrat',
        'Morocco' => 'Morocco',
        'Mozambique' => 'Mozambique',
        'Namibia' => 'Namibia',
        'Nauru' => 'Nauru',
        'Navassa Island' => 'Navassa Island',
        'Nepal' => 'Nepal',
        'Netherlands' => 'Netherlands',
        'Netherlands Antilles' => 'Netherlands Antilles',
        'New Caledonia' => 'New Caledonia',
        'New Zealand' => 'New Zealand',
        'Nicaragua' => 'Nicaragua',
        'Niger' => 'Niger',
        'Nigeria' => 'Nigeria',
        'Niue' => 'Niue',
        'Norfolk Island' => 'Norfolk Island',
        'Northern Marina Islands' => 'Northern Marina Islands',
        'Norway' => 'Norway',
        'Oman' => 'Oman',
        'Pakistan' => 'Pakistan',
        'Palmyra Atoll' => 'Palmyra Atoll',
        'Panama' => 'Panama',
        'Papua New Guinea' => 'Papua New Guinea',
        'Paracel Islands' => 'Paracel Islands',
        'Paraguay' => 'Paraguay',
        'Peru' => 'Peru',
        'Philippines' => 'Philippines',
        'Pitcairn Islands' => 'Pitcairn Islands',
        'Poland' => 'Poland',
        'Portugal' => 'Portugal',
        'Puerto Rico(U.S. Territory)' => 'Puerto Rico(U.S. Territory)',
        'Qatar' => 'Qatar',
        'Republic of Congo' => 'Republic of Congo',
        'Romania' => 'Romania',
        'Russia' => 'Russia',
        'Rwanda' => 'Rwanda',
        'San Marino' => 'San Marino',
        'Sao Tome and Principe' => 'Sao Tome and Principe',
        'Saudi Arabia' => 'Saudi Arabia',
        'Senegal' => 'Senegal',
        'Serbia' => 'Serbia',
        'Serbia &amp; Montenegro' => 'Serbia &amp; Montenegro',
        'Seychelles' => 'Seychelles',
        'Sierra Leone' => 'Sierra Leone',
        'Singapore' => 'Singapore',
        'Slovak Republic' => 'Slovak Republic',
        'Slovenia' => 'Slovenia',
        'Solomon Islands' => 'Solomon Islands',
        'Somalia' => 'Somalia',
        'South Africa' => 'South Africa',
        'Spain' => 'Spain',
        'Spratly Islands' => 'Spratly Islands',
        'Sri Lanka' => 'Sri Lanka',
        'St. Christopher and Nevis' => 'St. Christopher and Nevis',
        'St. Helena' => 'St. Helena',
        'St. Lucia' => 'St. Lucia',
        'St. Pierre and Miquelon' => 'St. Pierre and Miquelon',
        'St. Vincent and the Grenadines' => 'St. Vincent and the Grenadines',
        'Stateless' => 'Stateless',
        'Sudan' => 'Sudan',
        'Suriname' => 'Suriname',
        'Svalbard and Jan Mayen' => 'Svalbard and Jan Mayen',
        'Swaziland' => 'Swaziland',
        'Sweden' => 'Sweden',
        'Switzerland' => 'Switzerland',
        'Syria' => 'Syria',
        'Taiwan' => 'Taiwan',
        'Tajikistan' => 'Tajikistan',
        'Tanzania' => 'Tanzania',
        'Thailand' => 'Thailand',
        'Togo' => 'Togo',
        'Tokelau Islands' => 'Tokelau Islands',
        'Tonga' => 'Tonga',
        'Trinidad and Tobago' => 'Trinidad and Tobago',
        'Tromelin Island' => 'Tromelin Island',
        'Trust Territory of Pacific Islands' => 'Trust Territory of Pacific Islands',
        'Tunisia' => 'Tunisia',
        'Turkey' => 'Turkey',
        'Turkmenistan' => 'Turkmenistan',
        'Turks and Caicos Islands' => 'Turks and Caicos Islands',
        'Tuvalu' => 'Tuvalu',
        'Uganda' => 'Uganda',
        'Ukraine' => 'Ukraine',
        'United Arab Emirates' => 'United Arab Emirates',
        'United Kingdom (England, Northern Ireland, Scotland, Wales)' => 'United Kingdom (England, Northern Ireland, Scotland, Wales)',
        'United States Pacific Isle' => 'United States Pacific Isle',
        'Uruguay' => 'Uruguay',
        'US Virgin Islands' => 'US Virgin Islands',
        'Uzbekistan' => 'Uzbekistan',
        'Vanuatu' => 'Vanuatu',
        'Vatican City' => 'Vatican City',
        'Venezuela' => 'Venezuela',
        'Vietnam' => 'Vietnam',
        'Wake Island' => 'Wake Island',
        'Wallis and Futuna' => 'Wallis and Futuna',
        'West Indies' => 'West Indies',
        'Western Sahara' => 'Western Sahara',
        'Western Samoa' => 'Western Samoa',
        'Yemen, Republic of (Sanaa)' => 'Yemen, Republic of (Sanaa)',
        'Zambia' => 'Zambia',
        'Zimbabwe' => 'Zimbabwe',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_state_province_region'.
  $field_bases['field_state_province_region'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_state_province_region',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Alabama' => 'Alabama',
        'Alaska' => 'Alaska',
        'American Samoa' => 'American Samoa',
        'Arizona' => 'Arizona',
        'Arkansas' => 'Arkansas',
        'California' => 'California',
        'Colorado' => 'Colorado',
        'Connecticut' => 'Connecticut',
        'Delaware' => 'Delaware',
        'District of Columbia' => 'District of Columbia',
        'Federated States of Micronesia' => 'Federated States of Micronesia',
        'Florida' => 'Florida',
        'Georgia' => 'Georgia',
        'Guam' => 'Guam',
        'Hawaii' => 'Hawaii',
        'Idaho' => 'Idaho',
        'Illinois' => 'Illinois',
        'Indiana' => 'Indiana',
        'Iowa' => 'Iowa',
        'Kansas' => 'Kansas',
        'Kentucky' => 'Kentucky',
        'Louisiana' => 'Louisiana',
        'Maine' => 'Maine',
        'Marshall Islands' => 'Marshall Islands',
        'Maryland' => 'Maryland',
        'Massachussetts' => 'Massachussetts',
        'Michigan' => 'Michigan',
        'Minnesota' => 'Minnesota',
        'Mississippi' => 'Mississippi',
        'Missouri' => 'Missouri',
        'Montana' => 'Montana',
        'Nebraska' => 'Nebraska',
        'Nevada' => 'Nevada',
        'New Hampshire' => 'New Hampshire',
        'New Jersey' => 'New Jersey',
        'New Mexico' => 'New Mexico',
        'New York' => 'New York',
        'North Carolina' => 'North Carolina',
        'North Dakota' => 'North Dakota',
        'Northern Mariana Islands' => 'Northern Mariana Islands',
        'Ohio' => 'Ohio',
        'Oklahoma' => 'Oklahoma',
        'Oregon' => 'Oregon',
        'Palau' => 'Palau',
        'Pennsylvania' => 'Pennsylvania',
        'Puerto Rico' => 'Puerto Rico',
        'Rhode Island' => 'Rhode Island',
        'South Carolina' => 'South Carolina',
        'South Dakota' => 'South Dakota',
        'Tennessee' => 'Tennessee',
        'Texas' => 'Texas',
        'US Virgin Islands' => 'US Virgin Islands',
        'Utah' => 'Utah',
        'Vermont' => 'Vermont',
        'Virginia' => 'Virginia',
        'Washington' => 'Washington',
        'West Virginia' => 'West Virginia',
        'Wisconsin' => 'Wisconsin',
        'Wyoming' => 'Wyoming',
        'Alberta' => 'Alberta',
        'British Columbia' => 'British Columbia',
        'Manitoba' => 'Manitoba',
        'New Brunswick' => 'New Brunswick',
        'Newfoundland and Labrador' => 'Newfoundland and Labrador',
        'Nova Scotia' => 'Nova Scotia',
        'Northwest Territories' => 'Northwest Territories',
        'Nunavut' => 'Nunavut',
        'Ontario' => 'Ontario',
        'Prince Edward Island' => 'Prince Edward Island',
        'Quebec' => 'Quebec',
        'Saskatchewan' => 'Saskatchewan',
        'Yukon' => 'Yukon',
        'Other' => 'Other',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_subject'.
  $field_bases['field_subject'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_subject',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'subject',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}