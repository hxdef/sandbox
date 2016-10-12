<?php

/**
 * @file
 * Page callback for ajax links.
 */

/**
 * Ajax page callback.
 */
function ajax_login_ajax_page_callback($form, $type) {
  if ($type == 'ajax') {
    $commands = array();
/*    if ($form == 'password') {
      module_load_include('pages.inc', 'user');
      $form = drupal_get_form('user_pass');
      $form['#action'] = 'user/password/';
      $commands[] = ajax_command_replace('#user-login-form', render($form));
    }*/
    if ($form == 'login') {
      $form = drupal_get_form('user-login_block');
      $commands[] = ajax_command_replace('#user-pass', render($form));
    }

    /*elseif ($form == 'register') {
      $form = drupal_get_form('user-login_form');
      $form['#action'] = 'user/register/';
      $commands[] = ajax_command_replace('#user-login-form', render($form));
    }*/
    print ajax_render($commands);
  }
  else {
    drupal_goto('user/' . $form);
  }
}
