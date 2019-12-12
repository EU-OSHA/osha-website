<?php

/**
 * @file
 * Contains Drupal_SolrDevel_Documentation.
 */

/**
 * Returns documentation resources based on various criteria, such as params.
 */
class Drupal_SolrDevel_Documentation {

  /**
   * An instance of this class.
   *
   * @var Drupal_SolrDevel_Documentation
   */
  protected static $_singleton;

  /**
   * Links to param documentation.
   *
   * @var array
   */
  protected $_params;

  /**
   * Constructs a Drupal_SolrDevel_Documentation object.
   */
  protected function __construct() {
    $this->_params = array(

      // CoreQueryParameters
      'qt' => 'http://wiki.apache.org/solr/CoreQueryParameters#qt',
      'wt' => 'http://wiki.apache.org/solr/CoreQueryParameters#wt',
      'echoHandler' => 'http://wiki.apache.org/solr/CoreQueryParameters#echoHandler',
      'echoParams' => 'http://wiki.apache.org/solr/CoreQueryParameters#echoParams',

      // CommonQueryParameters
      'q' => 'http://wiki.apache.org/solr/CommonQueryParameters#q',
      'sort' => 'http://wiki.apache.org/solr/CommonQueryParameters#sort',
      'start' => 'http://wiki.apache.org/solr/CommonQueryParameters#start',
      'rows' => 'http://wiki.apache.org/solr/CommonQueryParameters#rows',
      'pageDoc' => 'http://wiki.apache.org/solr/CommonQueryParameters#pageDoc_and_pageScore',
      'pageScore' => 'http://wiki.apache.org/solr/CommonQueryParameters#pageDoc_and_pageScore',
      'fq' => 'http://wiki.apache.org/solr/CommonQueryParameters#fq',
      'fl' => 'http://wiki.apache.org/solr/CommonQueryParameters#fl',
      'debugQuery' => 'http://wiki.apache.org/solr/CommonQueryParameters#debugQuery',
      'debug' => 'http://wiki.apache.org/solr/CommonQueryParameters#debug',
      'explainOther' => 'http://wiki.apache.org/solr/CommonQueryParameters#explainOther',
      'debug.explain.structured' => 'http://wiki.apache.org/solr/CommonQueryParameters#debug.explain.structured',
      'defType' => 'http://wiki.apache.org/solr/CommonQueryParameters#defType',
      'timeAllowed' => 'http://wiki.apache.org/solr/CommonQueryParameters#timeAllowed',
      'omitHeader' => 'http://wiki.apache.org/solr/CommonQueryParameters#omitHeader',

      // HighlightingParameters
      'hl' => 'http://wiki.apache.org/solr/HighlightingParameters#hl',
      'hl.q' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.q',
      'hl.fl' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.fl',
      'hl.snippets' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.snippets',
      'hl.fragsize' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.fragsize',
      'hl.mergeContiguous' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.mergeContiguous',
      'hl.requireFieldMatch' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.requireFieldMatch',
      'hl.maxAnalyzedChars' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.maxAnalyzedChars',
      'hl.alternateField' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.alternateField',
      'hl.maxAlternateFieldLength' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.maxAlternateFieldLength',
      'hl.formatter' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.formatter',
      'hl.simple.pre' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.simple.pre.2BAC8-hl.simple.post',
      'hl.simple.post' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.simple.pre.2BAC8-hl.simple.post',
      'hl.fragmenter' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.fragmenter',
      'hl.fragListBuilder' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.fragListBuilder',
      'hl.fragmentsBuilder' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.fragmentsBuilder',
      'hl.boundaryScanner' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.boundaryScanner',
      'hl.bs.maxScan' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.bs.maxScan',
      'hl.bs.chars' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.bs.chars',
      'hl.bs.type' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.bs.type',
      'hl.bs.language' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.bs.language',
      'hl.bs.country' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.bs.country',
      'hl.useFastVectorHighlighter' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.useFastVectorHighlighter',
      'hl.usePhraseHighlighter' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.usePhraseHighlighter',
      'hl.highlightMultiTerm' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.highlightMultiTerm',
      'hl.regex.slop' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.regex.slop',
      'hl.regex.pattern' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.regex.pattern',
      'hl.regex.maxAnalyzedChars' => 'http://wiki.apache.org/solr/HighlightingParameters#hl.regex.maxAnalyzedChars',

      // MoreLikeThis
      'mlt.fl' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt.mintf' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt.mindf' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt.minwl' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt.maxwl' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt.maxqt' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt.maxntp' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt.boost' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt.qf' => 'http://wiki.apache.org/solr/MoreLikeThis#Common_Parameters',
      'mlt' => 'http://wiki.apache.org/solr/MoreLikeThis#MoreLikeThisComponent',
      'mlt.count' => 'http://wiki.apache.org/solr/MoreLikeThis#MoreLikeThisComponent',

      // Result Grouping / Field Collapsing
      'group' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.field' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.func' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.query' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.limit' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.offset' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.sort' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.format' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.main' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.ngroups' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.truncate' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.facet' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',
      'group.cache.percent' => 'http://wiki.apache.org/solr/FieldCollapsing#Request_Parameters',

      // SimpleFacetParameters
      'facet' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet',
      'facet.query' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.query_:_Arbitrary_Query_Faceting',
      'facet.field' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.field',
      'facet.prefix' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.prefix',
      'facet.sort' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.sort',
      'facet.limit' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.limit',
      'facet.offset' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.offset',
      'facet.mincount' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.mincount',
      'facet.missing' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.missing',
      'facet.method' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.method',
      'facet.enum.cache.minDf' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.enum.cache.minDf',
      'facet.date' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.date',
      'facet.date.start' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.date.start',
      'facet.date.end' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.date.end',
      'facet.date.gap' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.date.gap',
      'facet.date.hardend' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.date.hardend',
      'facet.date.other' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.date.other',
      'facet.date.include' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.date.include',
      'facet.range' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.range',
      'facet.range.start' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.range.start',
      'facet.range.end' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.range.end',
      'facet.range.gap' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.range.gap',
      'facet.range.hardend' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.range.hardend',
      'facet.range.other' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.range.other',
      'facet.range.include' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.range.include',
      'facet.pivot' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.pivot',
      'facet.pivot.mincount' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.pivot.mincount',
      'facet.zeros' => 'http://wiki.apache.org/solr/SimpleFacetParameters#facet.zeros',

      // SpatialSearch
      'pt' => 'http://wiki.apache.org/solr/SpatialSearch#Query',
      'd' => 'http://wiki.apache.org/solr/SpatialSearch#Query',
      'sfield' => 'http://wiki.apache.org/solr/SpatialSearch#Query',
    );
  }

  /**
   * Factory method for this class, implements the singleton pattern.
   *
   * @return Drupal_SolrDevel_Documentation
   *   An instance of the documentation class.
   */
  public static function getInstance() {
    if (!isset(self::$_singleton)) {
      self::$_singleton = new Drupal_SolrDevel_Documentation();
    }
    return self::$_singleton;
  }

  /**
   * Returns the URL to the parameter documentation.
   *
   * @param string $param
   *   The parameter passed to the Solr instance.
   *
   * @return string
   *   The URL to the documentation.
   */
  public function getParamDocumentation($param) {
    return isset($this->_param[$param]) ? $this->_param[$param] : FALSE;
  }
}
