<?php

  $header = $content['#header'];
  $rows = $content['#rows'];
  $attributes = $content['#attributes'];
  $empty = $content['#empty'];
  $prefix = $content['#prefix'];
  $suffix = $content['#suffix'];

  if(!empty ($prefix)) print $prefix;

  $output = '<table' . drupal_attributes($attributes) . ">\n";


  // Add the 'empty' row message if available.
  if (!count($rows) && $empty) {
    $header_count = 0;
    foreach ($header as $header_cell) {
      if (is_array($header_cell)) {
        $header_count += isset($header_cell['colspan']) ? $header_cell['colspan'] : 1;
      }
      else {
        $header_count++;
      }
    }
    $rows[] = array(array('data' => $empty, 'colspan' => $header_count, 'class' => array('empty', 'message')));
  }

  // Format the table header:

  if (count($header)) {
    // $ts = tablesort_init($header);
    // HTML requires that the thead tag has tr tags in it followed by tbody
    // tags. Using ternary operator to check and see if we have any rows.
    $output .= (count($rows) ? ' <thead>' : ' <tr>');

    // Table header support for multiple rows
    foreach ($header as $number => $row) {
      // Check if we're dealing with a simple or complex row
      if (isset($row['data'])) {
        $cells = $row['data'];
        $no_striping = isset($row['no_striping']) ? $row['no_striping'] : FALSE;

        // Set the attributes array and exclude 'data' and 'no_striping'.
        $attributes = $row;
        unset($attributes['data']);
        unset($attributes['no_striping']);
      }
      else {
        $cells = $row;
        $attributes = array();
        $no_striping = FALSE;
      }
      if (count($cells)) {

        // Build row
        $output .= ' <tr>';
        $i = 0;
        foreach ($cells as $cell) {
          // $cell = tablesort_cell($cell, $header, $ts, $i++);
          $output .= _theme_table_cell($cell, TRUE);
        }
        $output .= " </tr>\n";
      }
    }
  }
  else {
    $ts = array();
  }

  // Format the table rows:
  if (count($rows)) {
    // $output .= "<tbody>\n";
    $flip = array('even' => 'odd', 'odd' => 'even');
    $class = 'even';
    foreach ($rows as $number => $row) {
      // Check if we're dealing with a simple or complex row
      if (isset($row['data'])) {
        $cells = $row['data'];
        $no_striping = isset($row['no_striping']) ? $row['no_striping'] : FALSE;

        // Set the attributes array and exclude 'data' and 'no_striping'.
        $attributes = $row;
        unset($attributes['data']);
        unset($attributes['no_striping']);
      }
      else {
        $cells = $row;
        $attributes = array();
      }
      if (count($cells)) {
        // Build row
        $output .= ' <tr' . drupal_attributes($attributes) . '>';
        $i = 0;
        foreach ($cells as $cell) {
          // $cell = tablesort_cell($cell, $header, $ts, $i++);
          // Render tbody cells as th
          $output .= _theme_table_cell($cell, TRUE);
        }
        $output .= " </tr>\n";
      }
    }
  }
  $output .= (count($rows) ? " </thead>\n" : "</tr>\n");

  $output .= "</table>\n";
  print $output;

  if(!empty ($suffix)) print $suffix;
  ?>