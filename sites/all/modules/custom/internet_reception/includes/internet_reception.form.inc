<?php

/**
 * @file
 * Check the fields and send mail.
 */

/**
 * Comment.
 *
 * @return array
 *    Returned form elements.
 */
function internet_reception_content_form() {
  $form = array();
  $form['full_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Full name'),
    '#required' => TRUE,
  );
  $form['age'] = array(
    '#type' => 'textfield',
    '#title' => t('Age'),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['theme'] = array(
    '#type' => 'textfield',
    '#title' => t('Theme message'),
    '#required' => TRUE,
  );
  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Your message'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send!'),
  );
  return $form;
}

/**
 * Submit function for internet_reception_form.
 *
 * @param array $form
 *    Form elements.
 * @param array $form_state
 *    Stories information about the form.
 */
function internet_reception_content_form_submit($form, &$form_state) {
  $form_values = $form_state['values'];
  $module = 'internet_reception';
  $key = 'internet_reception';
  $to = variable_get('site_mail', ini_get('sendmail_from'));
  /*$from = variable_get('site_mail', ini_get('sendmail_from'));*/
  $params = $form_values;
  $language = language_default();

  $send = TRUE;
  $result = drupal_mail($module, $key, $to, $language, $params/*, $from*/, $send);
  if ($result['result'] == TRUE && $send == TRUE) {
    drupal_set_message(t('Your message has been sent.'));
  }
  else {
    drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
  }
}

