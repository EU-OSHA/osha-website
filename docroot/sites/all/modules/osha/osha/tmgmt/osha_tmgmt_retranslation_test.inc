<?php

class OshaTMGMTRetranslationTest {

  public static function run_tests() {

    self::testPrepareText();
    self::testGetDOMNodeList();
    self::test_get_changed_ids();
    self::test_get_text_to_retranslate_plain();
    self::test_get_merged_translation();
  }

  public static function testPrepareText() {
    $old_text = self::readDataFromFile('node1_en_noannotations.txt');
    $new_text = OshaTMGMTRetranslate::prepare_text($old_text);
    $expected = self::readDataFromFile('node1_en.txt');
    assert(strcmp($expected, $new_text) == 0, 'prepare_text');
  }

  public static function testGetDOMNodeList() {
    $text = self::readDataFromFile('node1_en.txt');
    $list = OshaTMGMTRetranslate::getDOMNodeList($text);
    assert(count($list)==29);
    $expected = array('p', 'p', 'h3', 'p', 'p', 'p', 'p', 'h3', 'p', 'p', 'p', 'h3', 'p', 'p', 'ul', 'p', 'p', 'h3', 'p', 'ul', 'p', 'p', 'h3', 'p', 'p', 'ul', 'h3', 'p', 'p');
    $idx=0;
    foreach ($list as $id => $item) {
      assert($item->tagName == $expected[$idx], 'getDOMNodeList');
      assert($id == $item->getAttribute('id'));
      assert($id == 'tmgmt-'.($idx+1));
      $idx++;
    }
    $structure = OshaTMGMTRetranslate::getHTMLStructure($text);
    assert(count($structure) == 29, 'getHTMLStructure');
    $idx=0;
    foreach ($structure as $id => $tagName) {
      assert($tagName == $expected[$idx], 'getHTMLStructure');
      assert($id == 'tmgmt-'.($idx+1), 'getHTMLStructure');
      $idx++;
    }
    assert($structure['tmgmt-23'] == 'h3', 'getHTMLStructure');
    assert($structure['tmgmt-26'] == 'ul', 'getHTMLStructure');
    assert($structure['tmgmt-10'] == 'p', 'getHTMLStructure');
  }

  public static function test_get_changed_ids() {
    $old_text = self::readDataFromFile('node1_en.txt');
    $new_text = self::readDataFromFile('node1_en_change1.txt');
    $structure = OshaTMGMTRetranslate::get_changed_ids($old_text, $new_text);
    assert(count($structure)==1);
    assert($structure[0] == 'tmgmt-3');
  }

  public static function test_get_text_to_retranslate_plain() {
    $clean_source_text = self::readDataFromFile('node1_en.txt');
    $source_text = self::readDataFromFile('node1_en_change1.txt');
    $translated_text = self::readDataFromFile('node1_ro.txt');
    $text = OshaTMGMTRetranslate::get_text_to_retranslate_plain($clean_source_text, $source_text, $translated_text);
    $expected = self::readDataFromFile('change1.txt');
    assert(strcmp($expected, $text) == 0);
  }

  public static function test_get_merged_translation() {
    $new_translation = self::readDataFromFile('change1_ro.txt');
    $old_translation = self::readDataFromFile('node1_ro.txt');
    $source_text = self::readDataFromFile('node1_en_change1.txt');
    $text = OshaTMGMTRetranslate::get_merged_translation($new_translation, $old_translation, $source_text);
    $expected = self::readDataFromFile('node1_ro_change1.txt');
    assert(strcmp($expected, $text) == 0);
  }

  static function readDataFromFile($file) {
    $path = drupal_get_path('module', 'osha_tmgmt') . '/tests/'.$file;
    if(file_exists($path)) {
      return file_get_contents($path); 
    }
    return '';
  }
}