<?php

/**
 * @file
 * Admin page callbacks for the addressfield_jp module.
 */

/**
 * Menu callback for admin/config/people/addressfield_jp.
 */
function addressfield_jp_settings(array $form, array &$form_state) {
  $form = array();

  $form['ajaxzip'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ajaxzip settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Library for postcode check and address lookup of Japanese.') . ' ' . l(t('Ajaxzip on github'), 'https://github.com/ajaxzip3/ajaxzip3.github.io'),
  );

  $form['ajaxzip']['addressfield_jp_ajaxzip_http'] = array(
    '#type' => 'textfield',
    '#title' => t('Http'),
    '#required' => TRUE,
    '#default_value' => variable_get('addressfield_jp_ajaxzip_http', ADDRESSFIELD_JP_AJAXZIP_HTTP),
    '#description' => t('Library on github') . ': ' . ADDRESSFIELD_JP_AJAXZIP_HTTP,
  );

  $form['ajaxzip']['addressfield_jp_ajaxzip_json_http'] = array(
    '#type' => 'textfield',
    '#title' => t('JSON data path of HTTP'),
    '#default_value' => variable_get('addressfield_jp_ajaxzip_json_http', ''),
    '#description' => t('It will be using the default setting of ajaxzip3 library if left empty. Please check the json data exist if you want use special path.'),
  );

  $form['ajaxzip']['addressfield_jp_ajaxzip_https'] = array(
    '#type' => 'textfield',
    '#title' => t('Https'),
    '#required' => TRUE,
    '#default_value' => variable_get('addressfield_jp_ajaxzip_https', ADDRESSFIELD_JP_AJAXZIP_HTTPS),
    '#description' => t('Library on github') . ': ' . ADDRESSFIELD_JP_AJAXZIP_HTTPS,
  );

  $form['ajaxzip']['addressfield_jp_ajaxzip_json_https'] = array(
    '#type' => 'textfield',
    '#title' => t('JSON data path of HTTPS'),
    '#default_value' => variable_get('addressfield_jp_ajaxzip_json_https', ''),
    '#description' => t('It will be using the default setting of ajaxzip3 library if left empty. Please check the json data exist if you want use special path.'),
  );

  $form['postal_code'] = array(
    '#type' => 'fieldset',
    '#title' => t('Postal code settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['postal_code']['addressfield_jp_invalid_postal_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Message of invalid postal code'),
    '#required' => TRUE,
    '#default_value' => variable_get('addressfield_jp_invalid_postal_code', t('Invalid postal code format.')),
    '#description' => t('The message will be display when user input invalid postal code.'),
  );

  $form['postal_code']['addressfield_jp_lookup_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text of address lookup link'),
    '#required' => TRUE,
    '#default_value' => variable_get('addressfield_jp_lookup_link_text', t('Address lookup')),
    '#description' => t('The text will be use for address lookup link.'),
  );

  return system_settings_form($form);
}
