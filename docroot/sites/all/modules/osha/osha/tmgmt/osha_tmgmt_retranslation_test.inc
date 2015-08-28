<?php

class OshaTMGMTRetranslationTest {

  public static function log($function, $arguments) {
    printf("\n**** Running %s", $function);
    if (!empty($arguments)) {
      print(" with parameters ");
      print_r($arguments);
    }
  }

  public static function run_tests() {

    self::testPrepareText('node1_en_noannotations.txt', 'node1_en.txt');
    self::testGetDOMNodeList();
    self::test_get_changed_ids();
    self::test_get_text_to_retranslate_plain('node1_en.txt', 'node1_en_changed.txt', 'node1_ro.txt', 'change1_en.txt');
    self::test_get_merged_translation('change1_ro.txt', 'node1_ro.txt', 'node1_en_changed.txt', 'node1_ro_changed.txt');
    self::test_get_merged_translation('change2_ro.txt', 'node2_ro.txt', 'node2_en_changed.txt', 'node2_ro_changed.txt');
    self::test_get_text_to_retranslate_plain('node3_en.txt', 'node3_en_changed.txt', 'node3_ro.txt', 'change3_en.txt');
    self::testPrepareText('node4_en_old.txt', 'node4_en_new.txt');
    self::test_get_merged_translation('change5_ro.txt', 'node5_ro.txt', 'node5_en_changed.txt', 'node5_ro_changed.txt');
    self::testPrepareText('node6_en_noannotations.txt', 'node6_en.txt');
    }

  public static function testPrepareText($old, $new) {
    self::log(__FUNCTION__, func_get_args());
    $old_text = self::readDataFromFile($old);
    $new_text = OshaTMGMTRetranslate::prepare_text($old_text);
    $expected = self::readDataFromFile($new);
    assert(strcmp($expected, $new_text) == 0, 'prepare_text');
    //file_put_contents("expected.txt", $new_text);
  }

  public static function testGetDOMNodeList() {
    self::log(__FUNCTION__, func_get_args());
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
    self::log(__FUNCTION__, func_get_args());
    $old_text = self::readDataFromFile('node1_en.txt');
    $new_text = self::readDataFromFile('node1_en_changed.txt');
    $structure = OshaTMGMTRetranslate::get_changed_ids($old_text, $new_text);
    assert(count($structure)==1);
    assert($structure[0] == 'tmgmt-3');
  }

  public static function test_get_text_to_retranslate_plain($src_original, $src_changed, $tgt_original, $src_expected) {
    self::log(__FUNCTION__, func_get_args());
    $clean_source_text = self::readDataFromFile($src_original);
    $source_text = self::readDataFromFile($src_changed);
    $translated_text = self::readDataFromFile($tgt_original);
    $text = OshaTMGMTRetranslate::get_text_to_retranslate_plain($clean_source_text, $source_text, $translated_text);

    $expected = self::readDataFromFile($src_expected);
    //file_put_contents("expected.txt", $text);
    assert(strcmp($expected, $text) == 0);
  }

  public static function test_get_merged_translation($translation, $old_target_lang, $new_source_lang, $expected_target_lang) {
    self::log(__FUNCTION__, func_get_args());
    $new_translation = self::readDataFromFile($translation);
    $old_translation = self::readDataFromFile($old_target_lang);
    $source_text = self::readDataFromFile($new_source_lang);
    $text = OshaTMGMTRetranslate::get_merged_translation($new_translation, $old_translation, $source_text);
    $expected = self::readDataFromFile($expected_target_lang);

    //file_put_contents("expected.txt", $text);
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