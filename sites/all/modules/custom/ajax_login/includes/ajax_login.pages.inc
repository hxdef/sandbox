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
    if ($form == 'login') {
      $form = drupal_get_form('user-login_block');
      $commands[] = ajax_command_replace('#user-pass', render($form));
    }
    print ajax_render($commands);
  }
  else {
    drupal_goto('user/' . $form);
  }
}
