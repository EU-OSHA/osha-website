<?php

/**
 * @file
 * Provides the file translator plugin controller.
 */

/**
 * File translator plugin controller.
 */
class OSHATMGMTFileTranslatorPluginController extends TMGMTFileTranslatorPluginController {

  /**
   * {@inheritdoc}
   */
  public function requestTranslation(TMGMTJob $job) {
    $name = 'translation_job_id_' . $job->tjid . '_request';
    $export = tmgmt_file_format_controller($job->getSetting('export_format'));
    $path = $job->getSetting('scheme') . '://tmgmt_file/' . $name . '.' .  $job->getSetting('export_format');
    $dirname = dirname($path);
    if (file_prepare_directory($dirname, FILE_CREATE_DIRECTORY)) {
      if ($file = file_save_data($export->export($job), $path, FILE_EXISTS_REPLACE)) {
        file_usage_add($file, 'osha_tmgmt', 'tmgmt_job', $job->tjid);
        $job->submitted('Translation job file was created. <a href="!link">Click here to download the XML file</a>', array('!link' => file_create_url($path)));
      }
      else {
        $job->addMessage('Error saving translation file. Please contact technical support (cannot save !file)', array('!file' => $path), 'error');
        return FALSE;
      }
    }
    else {
      $job->addMessage('Cannot save XML file. Please contact technical support. (destination directory <strong>!path</strong> is invalid)', array('!path' => $dirname), 'error');
      return FALSE;
    }
    return TRUE;
  }
}
