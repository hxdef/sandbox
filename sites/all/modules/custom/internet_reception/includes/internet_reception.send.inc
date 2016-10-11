<?php

/**
 * @file
 * Check the fields and send mail.
 */

/**
 * Send email function for internet reception.
 * @param array $form_values
 *    The constructed form values array of the submitted form.
 */
function internet_reception_mail_send($form_values) {
  global $user;
  $module = 'internet_reception';
  $key = 'internet_reception';
  $to = 'feedback@form.com';
  $from = variable_get('site_mail', ini_get('sendmail_from'));
  $params = $form_values;
  $language = language_default();

  $send = TRUE;
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);
  if ($result['result'] == TRUE) {
    drupal_set_message(t('Your message has been sent.'));
  }
  else {
    drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
  }
}

/**
 * Submit function for internet_reception_form.
 * @param array $form
 *    Form elements.
 * @param array $form_state
 *    Stories information about the form.
 */
function internet_reception_form_submit($form, &$form_state) {
  internet_reception_mail_send($form_state['values']);
}
