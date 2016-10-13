<?php

/**
 * @file
 * Ajax callback login form.
 */

/**
 * Ajax callback for user login form.
 */
function ajax_login_ajax_callback(&$form, &$form_state) {
  module_load_include('pages.inc', 'user  ');
  $commands = array();
  if (user_is_logged_in()) {
    $commands[] = ajax_command_html('#user-login-form', 'Hello! To see the site as a registered user, click on <a href="/">link</a>');
  }
  if (form_set_error()) {
    $commands[] = ajax_command_before('#user-login-form', 'Incorrect login/password!');
  }
  return array('#type' => 'ajax', '#commands' => $commands);
}
