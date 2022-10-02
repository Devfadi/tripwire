<?php
/**
 * @file
 * carousel_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function carousel_content_type_taxonomy_default_vocabularies() {
  return array(
    'allow_for_pre_auth_carousel' => array(
      'name' => 'Allow for Pre-Auth Carousel',
      'machine_name' => 'allow_for_pre_auth_carousel',
      'description' => 'Check "YES" to allow this article to be viewed by non-authenticated users',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
