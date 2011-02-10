<?php
// $Id$

/**
 * @file 
 * Uses Rules module to send notification emails to users (clients)
 * whenever they get a new assigned CFD.
 **/

/**
 * Implementation of hook_rules_action_info()
 * Defines an action to email assigned user
 **/
function cfde_rules_action_info() {
  return array(
    'cfde_action_mail_assigned_user' => array(
      'label' => t('Send email to assigned user'),
      'module' => 'FE',
      'arguments' => array(
        'node' => array(
          'label' => t('Content'),
          'type' => 'node',
          'description' => t('Node of type Emitted FE'),
        ),
      ),
      'eval input' => array('from', 'to', 'subject', 'message_html', 'message_plaintext', 'attachments'),
      'help' => t('Sends a notification email to the user (client) who is the reciptient of the FE'),
    ),
  );
}

/**
 * Implementation of 'Send email to assigned user' action
 **/
function cfde_action_mail_assigned_user($node, $settings) {
  $nid = $node->cliente_uid;
  // if user isn't admin or anonymous then
  if ($nid > 1) {
    // $user = user_load($nid);
    $user = new stdClass();
    $user->mail = 'webmaster@casabaltazar.com';
    mimemail_rules_action_mail_to_user($user, $settings);
  }
}
