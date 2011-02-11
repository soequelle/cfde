<?php

/*
 * @file Provies functionality for importing CFDs as zipped XMLs files.
 */

function cfde_import_form() {
  $form['#attributes']['enctype'] = 'multipart/form-data';
  $form['zip_file'] = array(
    '#type' => 'file',
    '#title' => t('Select a @type file', array('@type' => 'ZIP')),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $form['#redirect'] = 'admin/content/node';

  return $form;
}

function cfde_import_form_validate($form, &$form_state) {
  $upload_size = $_FILES['files']['size']['zip_file'];
  $file_type = $_FILES['files']['type']['zip_file'];
//  dvm($file_type);
  if ($upload_size <= 0 || $file_type != 'application/x-zip-compressed')
    form_set_error('zip_file', t('You must submit a @type file', array('@type' => 'ZIP')));
}

function cfde_import_form_submit($form, &$form_state) {
  global $user;
  $file_name = $_FILES['files']['tmp_name']['zip_file'];
  $zip_file_name = $_FILES['files']['name']['zip_file'];

  $zip = zip_open($file_name);
  if ($zip) {
    $count = 0;
    while ($zip_entry = zip_read($zip)) {
      // check for .xml files
      if (substr(zip_entry_name($zip_entry), -4) == '.xml') {
        zip_entry_open($zip, $zip_entry);
        $xml = zip_entry_read($zip_entry, zip_entry_filesize($zip_entry));
        zip_entry_close($zip_entry);
        
        $node = new stdClass();
        $node->type = 'cfde';
        //Sets the creator of these nodes to something.
        $node->uid = $user->uid;
        $node->xml_file = $xml;
        node_save($node);
        $count++;
        drupal_set_message(t('@node saved', array('@node' => $node->title)));
      }
    }
  }
  zip_close($zip);
  watchdog('cfde', t('@num CFDs imported from @filename', array('@num' => $count, '@filename' => $zip_file_name)));
}
