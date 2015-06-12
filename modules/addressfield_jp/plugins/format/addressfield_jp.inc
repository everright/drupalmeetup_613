<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Postcode check and address lookup (Japan)'),
  'format callback' => 'addressfield_jp_generate',
  'type' => 'addressfield_jp',
  'weight' => 0,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_jp_generate(&$format, &$address, $context = array()) {
  if ($address['country'] != 'JP' || $context['mode'] != 'form') {
    return;
  }

  $html_id = '';
  $addition = FALSE;
  // Webofrm component.
  if (isset($context['component'])) {
    $html_id = drupal_html_id("{$context['component']['form_key']}-{$context['component']['nid']}-{$context['component']['cid']}");
    $addition = empty($context['component']['extra']['addressfield_jp_34digit']) ? FALSE : TRUE;
  }
  else {
    $html_id = drupal_html_id("{$context['field']['field_name']}-{$context['langcode']}-{$context['delta']}");
    $addition = empty($context['instance']['widget']['settings']['addressfield_jp_34digit']) ? FALSE : TRUE;
  }
  $lookup_class = array('addressfield-jp-lookup');

  // The postal code block.
  $format['postal_code_block'] = array(
    '#type' => 'addressfield_container',
    '#attributes' => array(
      'id' => 'postal-code-block-' . $html_id,
      'class' => array('postal-code-block', 'addressfield-jp-postcode'),
    ),
    '#weight' => -1,
    '#attached' => array('js' => _addressfield_jp_js_data()),
  );

  $postal_code = $format['locality_block']['postal_code'];
  unset($format['locality_block']['postal_code']);

  if ($addition) {
    $lookup_class[] = 'addressfield-jp-lookup-34digit';
    $format['postal_code_block']['jp_postal_code'] = array(
      '#type' => 'addressfield_jp_postal_code',
      '#title' => $postal_code['#title'],
      '#required' => $postal_code['#required'],
      '#default_value' => $address['postal_code'],
      '#id' => $html_id,
      '#field_sub_suffix' => _addressfield_jp_render_lookup($html_id, $lookup_class),
    );
    $postal_code['#access'] = FALSE;
  }
  else {
    unset($postal_code['#attributes']['x-autocompletetype'], $postal_code['#attributes']['autocomplete']);
    $postal_code['#size'] = $postal_code['#maxlength'] = 8;
    $postal_code['#id'] = $html_id;
    $postal_code['#field_suffix'] = _addressfield_jp_render_lookup($html_id, $lookup_class);
  }

  $format['postal_code_block']['postal_code'] = $postal_code;
}
