<?php

/**
 *
 */

/**
 * Submit function for internet_reception_page_form.
 */
/*function internet_reception_form_submit($form, &$form_state) {
  internet_reception_mail_send($form_state['values']);
}*/

/**
 * Validate function for internet_reception_page_form.
 */
/*function internet_reception_form_validate($form, $form_state) {
  switch (gmp_sign($form_state['values']['age'])) {
    case '0':
      form_set_error('age', t('Age is not equal to 0'));
      break;

    case '-1':
      form_set_error('age', t('Age can not be negative'));
      break;
  }
  if (is_numeric($form_state['value']['full_name'])) {
    form_set_error('full_name', 'Not numbers');
  }
}*/

/**
 * Send email function for internet reception.
 * @param $form_values
 */
/*function internet_reception_mail_send($form_values) {
  global $user;
  $module = 'internet_reception';
  $key = 'internet_reception';
  $to = variable_get('site_mail', ini_get('sendmail_from'));
  $from = $user->mail;
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
}*/