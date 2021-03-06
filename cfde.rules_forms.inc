<?php

/**
 * @file Rules integration forms
 * Uses Rules module to send notification emails to users (clients)
 * whenever they get a new assigned CFD.
 **/

/**
 * Implementation of 'Send email to assigned user' form
 **/
function cfde_action_mail_assigned_user_form($settings = array(), &$form) {
  $form['settings']['from'] = array(
    '#type' => 'textfield',
    '#title' => t('Sender'),
    '#default_value' => $settings['from'],
    '#description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
  );
  $form['settings']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $settings['subject'],
    '#description' => t("The mail's subject."),
  );
  $form['settings']['message_html'] = array(
    '#type' => 'textarea',
    '#title' => t('HTML message'),
    '#default_value' => $settings['message_html'],
    '#description' => t("The message body in HTML format."),
  );
  $form['settings']['message_plaintext'] = array(
    '#type' => 'textarea',
    '#title' => t('Text message'),
    '#default_value' => $settings['message_plaintext'],
    '#description' => t("Optional plaintext portion of a multipart message."),
  );
}
