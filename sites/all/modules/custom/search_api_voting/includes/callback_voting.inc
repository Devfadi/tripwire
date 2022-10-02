<?php
/**
 * @file
 * Alter callback class for vote results, so that the users can easily index.
 */

class SearchApiVotingAlterCallback extends SearchApiAbstractAlterCallback {

  /**
   * Implements SearchApiAlterCallbackInterface::supportsIndex().
   *
   * Return TRUE only if the indexing items are entities.
   */
  public function supportsIndex(SearchApiIndex $index) {
    return entity_get_info($index->item_type) ? TRUE : FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $properties = array();

    // Get all of the available metadata for votes.
    $metadata = votingapi_metadata();
    // Create all combination of tag + value_type + function to be able to index all kind of results.
    foreach ($metadata['tags'] as $tag => $tag_data) {
      foreach ($metadata['value_types'] as $value_type => $value_type_data) {
        foreach ($metadata['functions'] as $function => $function_data) {
          // Build property key according to the parameters of the search result.
          $key = search_api_voting_get_property_key($tag, $value_type, $function);
          $name = $tag_data['name'] . ' / ' . $value_type_data['name'] . ' / ' . $function_data['name'];

          // Add voting result related search api property.
          $properties[$key] = array(
            'label' => t('Voting result information (@name)', array('@name' => $name)),
            'description' => t('Voting result information.'),
            'type' => 'integer',
          );
        }
      }
    }
    return $properties;
  }

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    $voting_fields = array();

    // Get voting related fields which should be indexed.
    foreach ($this->index->options['fields'] as $key => $field) {
      if (strpos($key, 'search_api_voting_') === 0) {
        $voting_fields[] = $key;
      }
    }

    // Set the appropriate voting results.
    foreach ($items as $id => $item) {
      foreach ($voting_fields as $field_key) {
        // Get parameters from the property key.
        $tag = search_api_voting_get_param($field_key, 'tag');
        $value_type = search_api_voting_get_param($field_key, 'value_type');
        $function = search_api_voting_get_param($field_key, 'function');

        // Build up criteria array to be able to get the appropriate voting result.
        $criteria = array(
          'entity_type' => $this->index->item_type,
          'entity_id' => $id,
          'value_type' => $value_type,
          'tag' => $tag,
          'function' => $function,
        );
        $items[$id]->$field_key = votingapi_select_single_result_value($criteria);
      }
    }
  }
}
