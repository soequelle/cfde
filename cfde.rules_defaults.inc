<?php

/**
 * @file Defines default action for Rules module
 **/

/**
 * Implementation of hook_rules_defaults()
 *
 **/
function cfde_rules_defaults() {
  return array(
    'rules' => array(
      'rules_cfde_mail_notification' => array(
        '#version' => 6003,
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => t('Send email to assigned user'),
        '#active' => 0,
        '#weight' => '0',
        '#categories' => array(
          0 => 'cfde',
        ),
        '#status' => 'default',
        '#conditions' => array(
          0 => array(
            '#weight' => 0,
            '#type' => 'condition',
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'module' => 'Node',
              'label' => 'Contenido creado es Factura Electronica (FE) Emitida',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Contenido',
                ),
              ),
            ),
            '#settings' => array(
              'type' => array(
                'cfde' => 'cfde',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
          ),
          1 => array(
            '#weight' => 1,
            '#type' => 'condition',
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'module' => 'Node',
              'label' => 'Contenido Creado esta publicado',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Contenido',
                ),
              ),
            ),
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
          ),
        ),
        '#actions' => array(
          0 => array(
            '#type' => 'action',
            '#name' => 'cfde_action_mail_assigned_user',
            '#settings' => array(
              'from' => '',
              'subject' => 'Su Factura Electronica [node:title] del [node:fecha_cfd]',
              'message_html' => '<h1><a href="[node:node-path]">[node:title]</a> <span class="description">del [node:fecha_cfd]</span></h1><p>Descargar (requiere iniciar sesión en la página): [node:cfde_dl_links]</p>',
              'message_plaintext' => '[node:title] del [node:fecha_cfd-full]
Ver y descargar (requiere iniciar sesión en la página): [node:node-url]',
              'attachments' => '',
              '#argument map' => array(
                'node' => 'node',
              ),
              'to' => NULL,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    0 => 'node',
                  ),
                  'message_html' => array(
                    0 => 'node',
                  ),
                  'message_plaintext' => array(
                    0 => 'node',
                  ),
                ),
              ),
            ),
            '#info' => array(
              'label' => 'Enviar email al usuario asignado',
              'module' => 'FE',
              'arguments' => array(
                'node' => array(
                  'label' => 'Contenido',
                  'type' => 'node',
                  'description' => 'Nodo tipo FE Emitida',
                ),
              ),
              'eval input' => array(
                0 => 'from',
                1 => 'to',
                2 => 'subject',
                3 => 'message_html',
                4 => 'message_plaintext',
                5 => 'attachments',
              ),
            ),
            '#weight' => 0,
          ),
        ),
      ),
    ),
  );
}
