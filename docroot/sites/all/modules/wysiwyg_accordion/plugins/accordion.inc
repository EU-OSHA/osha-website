<?php
function wysiwyg_accordion_accordion_plugin() {
    return array(
        'accordion' => array(
            'path' => drupal_get_path('module', 'wysiwyg_accordion') . '/plugins',
            'js file' => 'accordion.js',
            'js path' => drupal_get_path('module', 'wysiwyg_accordion') . '/plugins',
            'css path' => drupal_get_path('module', 'wysiwyg_accordion') . '/plugins',
            'css file' => 'accordion.css',
            'icon title' => 'Accordion',
            'icon path' => drupal_get_path('module', 'wysiwyg_accordion') . '/plugins/icons',
            'icon file' => 'accordion.png',
            'buttons' => array('accordion' => t('Accordion')),
            'load' => TRUE,
            'internal' => FALSE,
            'settings' => array(),
        ),
        'accordion_header' => array(
            'path' => drupal_get_path('module', 'wysiwyg_accordion') . '/plugins',
            'js file' => 'accordion_header.js',
            'js path' => drupal_get_path('module', 'wysiwyg_accordion') . '/plugins',
            'css file' => 'accordion.css',
            'icon title' => 'Accordion Header',
            'icon path' => drupal_get_path('module', 'wysiwyg_accordion') . '/plugins/icons',
            'icon file' => 'accordion_header.png',
            'buttons' => array('accordion_header' => t('Accordion Header')),
            'load' => TRUE,
            'internal' => FALSE,
            'settings' => array(),
        ),
    );
}
