<?php
/**
 * @file
 * Rate widget theme
 *
 * This is the default template for rate widgets. See section 3 of the README
 * file for information on theming widgets.
 *
 * Available variables:
 * - $links: Array with vote links
 *     array(
 *       array(
 *         'text' => 'Button label',
 *         'href' => 'Link href',
 *         'value' => 20,
 *         'votes' => 6,
 *       ),
 *     )
 * - $results: Array with voting results
 *     array(
 *       'rating' => 12, // Average rating
 *       'options' => array( // Votes per option. Only available when value_type == 'options'
 *         1 => 234,
 *         2 => 34,
 *       ),
 *       'count' => 23, // Number of votes
 *       'up' => 2, // Number of up votes. Only available for thumbs up / down.
 *       'down' => 3, // Number of down votes. Only available for thumbs up / down.
 *       'up_percent' => 40, // Percentage of up votes. Only available for thumbs up / down.
 *       'down_percent' => 60, // Percentage of down votes. Only available for thumbs up / down.
 *       'user_vote' => 80, // Value for user vote. Only available when user has voted.
 *     )
 * - $mode: Display mode.
 * - $just_voted: Indicator whether the user has just voted (boolean).
 * - $content_type: "node" or "comment".
 * - $content_id: Node or comment id.
 * - $buttons: Array with themed buttons (built in preprocess function).
 * - $info: String with user readable information (built in preprocess function).
 */
?>

<?php 
  // Print all rate buttons
  $class = '';
  foreach ($links as $link) {
      if (isset($results['user_vote'])) {
        if ($results['user_vote'] == $link['text']) {
            // user has voted
            $class = strtolower($link['text']) . ' voted';
        } else {
            // user has not voted
            $class = strtolower($link['text']) . ' not-voted';
        }
      } else {
          $class = strtolower($link['text']);
      }

    print theme('rate_button', array(
        'text' => $link['text'],
        'href' => $link['href'],
        'class' => "rate-btn " . $class)
      );
      print '<span class="vote-count">' . $link['votes'] . '</span>';
    
}
?>