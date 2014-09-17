<?php
/**
 * @file
 * osha_content.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function osha_content_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 1,
  'title' => 'Ageing and OSH',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '1ffabe3a-40a1-4a81-9f51-557c80c41087',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859331,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '106bb0f7-5519-42a4-8310-5773d228a335',
  'revision_uid' => 1,
  'body' => array(),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Ageing and OSH',
        'format' => NULL,
        'safe_value' => 'Ageing and OSH',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-05 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'will be sent by Katalin by 12 Sept.',
        'format' => NULL,
        'safe_value' => 'will be sent by Katalin by 12 Sept.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => 'en',
    'data' => array(
      'en' => array(
        'entity_type' => 'node',
        'entity_id' => 1,
        'language' => 'en',
        'source' => '',
        'uid' => 1,
        'status' => 1,
        'translate' => 0,
        'created' => 1410859331,
        'changed' => 1410876971,
      ),
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(
    772 => 772,
  ),
  'path' => array(
    'pid' => 28,
    'source' => 'node/1',
    'alias' => 'articles/ageing-and-osh',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 20,
      'vid' => 21,
      'nid' => 1,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 1,
      'stamp' => 1410876971,
      'published' => 0,
      'current' => 1,
      'title' => 'Ageing and OSH',
      'timestamp' => 1410876971,
    ),
    'published' => array(
      'hid' => 1,
      'vid' => 1,
      'nid' => 1,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 0,
      'title' => 'Ageing and OSH',
      'timestamp' => 1410876971,
    ),
    'my_revision' => array(
      'hid' => 1,
      'vid' => 1,
      'nid' => 1,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 0,
      'title' => 'Ageing and OSH',
      'timestamp' => 1410876971,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:22:11 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Safety and Health legislation',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '97e4ca0a-def6-4a42-b23c-98dccee028c1',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859186,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '18ee1aad-eadb-43f9-b9de-ee47ba5d1be4',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>European Directives set out minimum requirements<a id="_anchor_1" name="_msoanchor_1" href="#_msocom_1"></a> and fundamental principles, such as the principle of prevention and risk assessment, as well as the responsibilities of employers and employees. A series of European guidelines aims to facilitate the implementation of European directives as well as European standards which are adopted by European standardisation organisations.</p><p><strong>The following sections provide information on European legislation, its implementation and other practical documents on safety and health at work arranged by topic.</strong></p><p>Further information on safety and health at work can also be found at the website of the <a href="http://ec.europa.eu/social/main.jsp?catId=148&amp;langId=en" target="_blank"><strong>European Commission, DG Employment and Social Affairs</strong></a>.</p><p>The <a href="http://eur-lex.europa.eu/legal-content/EN/TXT/?uri=COM:2014:332:FIN"><strong>EU Strategic Framework on safety and health at work</strong></a> 2014–2020 defines key strategic objectives with a view to reducing occupational accidents and diseases in the EU.</p><div>&nbsp;</div>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>European Directives set out minimum requirements<a id="_anchor_1" name="_msoanchor_1" href="#_msocom_1"></a> and fundamental principles, such as the principle of prevention and risk assessment, as well as the responsibilities of employers and employees. A series of European guidelines aims to facilitate the implementation of European directives as well as European standards which are adopted by European standardisation organisations.</p>
<p><strong>The following sections provide information on European legislation, its implementation and other practical documents on safety and health at work arranged by topic.</strong></p>
<p>Further information on safety and health at work can also be found at the website of the <a href="http://ec.europa.eu/social/main.jsp?catId=148&amp;langId=en" target="_blank"><strong>European Commission, DG Employment and Social Affairs</strong></a>.</p>
<p>The <a href="http://eur-lex.europa.eu/legal-content/EN/TXT/?uri=COM:2014:332:FIN"><strong>EU Strategic Framework on safety and health at work</strong></a> 2014–2020 defines key strategic objectives with a view to reducing occupational accidents and diseases in the EU.</p>
<div> </div>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Safety and Health legislation',
        'format' => NULL,
        'safe_value' => 'Safety and Health legislation',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'A wide variety of Community measures in the field of safety and health at work have been adopted on the basis of Article 153 of the Treaty on the Functioning of the European Union. European directives are legally binding and have to be transposed into national laws by the Member States. ',
        'format' => NULL,
        'safe_value' => 'A wide variety of Community measures in the field of safety and health at work have been adopted on the basis of Article 153 of the Treaty on the Functioning of the European Union. European directives are legally binding and have to be transposed into national laws by the Member States. ',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 12,
    'source' => 'node/2',
    'alias' => 'articles/safety-and-health-legislation',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 2,
      'vid' => 2,
      'nid' => 2,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Safety and Health legislation',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 2,
      'vid' => 2,
      'nid' => 2,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Safety and Health legislation',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 2,
      'vid' => 2,
      'nid' => 2,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Safety and Health legislation',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:19:46 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Emerging Risks',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '4660d932-20c2-4ef3-a9e8-88c2f4ac5c0b',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859354,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '20e2c054-60f4-41a6-beaf-9c083ff05a63',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>The&nbsp;<strong>European Risk Observatory</strong>&nbsp;monitors safety and health in workplaces across Europe to pick up trends, anticipate change and identify potential new risks. This information allows policy-makers to evaluate changes in technology and society and their likely impact on work. Researchers can then prioritise the emerging risks and develop prevention strategies. This means that OSH policy can adapt quickly.</p><p>Learn more about the work of the&nbsp;<a href="articles/european-risk-observatory">European Risk Observatory</a>.</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>The <strong>European Risk Observatory</strong> monitors safety and health in workplaces across Europe to pick up trends, anticipate change and identify potential new risks. This information allows policy-makers to evaluate changes in technology and society and their likely impact on work. Researchers can then prioritise the emerging risks and develop prevention strategies. This means that OSH policy can adapt quickly.</p>
<p>Learn more about the work of the <a href="articles/european-risk-observatory">European Risk Observatory</a>.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Emerging Risks',
        'format' => NULL,
        'safe_value' => 'Emerging Risks',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'Effective prevention of new and emerging risks requires rapid and reliable identification.',
        'format' => NULL,
        'safe_value' => 'Effective prevention of new and emerging risks requires rapid and reliable identification.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 31,
    'source' => 'node/3',
    'alias' => 'articles/emerging-risks',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 3,
      'vid' => 3,
      'nid' => 3,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Emerging Risks',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 3,
      'vid' => 3,
      'nid' => 3,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Emerging Risks',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 3,
      'vid' => 3,
      'nid' => 3,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Emerging Risks',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:22:34 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Awards',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'b1e4a8ea-5c72-420e-8d74-e2eb56566376',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859325,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '2c1489e8-077b-4b33-8e6b-f842f4363cba',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>Awards Body</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>Awards Body</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Awards',
        'format' => NULL,
        'safe_value' => 'Awards',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'Awards summary',
        'format' => NULL,
        'safe_value' => 'Awards summary',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 27,
    'source' => 'node/4',
    'alias' => 'articles/awards',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 4,
      'vid' => 4,
      'nid' => 4,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Awards',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 4,
      'vid' => 4,
      'nid' => 4,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Awards',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 4,
      'vid' => 4,
      'nid' => 4,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Awards',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:22:05 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Surveys and statistics on OSH',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'adb2c516-bb20-4609-99cf-ed63b1c8e70c',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859177,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '387191b6-0baf-4823-906d-55c6b560c388',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>The surveys are the cornerstone of our work, and the results help policy-makers and researchers to identify emerging trends.</p><p>You will also find useful statistics on safety and health in the workplace in the following sources: [IT WOULD BE BETTER IF THIS 2 PARAGRAPH COULD BE MOVED BELOW THE SUBSECTIONS]</p><ul><li><a href="http://epp.eurostat.ec.europa.eu/portal/page/portal/eurostat/home//portal/page/portal/eurostat/home//portal/page/portal/eurostat/home/" target="_blank">EUROSTAT</a> website and EUROSTAT <a href="http://epp.eurostat.ec.europa.eu/portal/page/portal/eurostat/home//portal/page/portal/eurostat/home//portal/page/portal/product_details/publication?p_product_code=KS-SF-09-063" target="_blank">Labour Force Survey 2007 ad hoc module on accidents at work and work-related health problems</a></li><li>European Foundation for the Improvement of Working and Living Conditions (EUROFUND): <a href="http://www.eurofound.europa.eu/ewco/surveys/index.htm" target="_blank">European Working Conditions Surveys</a> and <a href="http://www.eurofound.europa.eu/surveys/index.htm" target="_blank">other surveys</a></li><li>DG Employment, Social Affairs and Equal Opportunities: <a href="http://ec.europa.eu/social/main.jsp?catId=706&amp;langId=en" target="_blank">improving working conditions</a></li><li><a href="http://www.meadow-project.eu/" target="_blank">MEADOW</a> - a European project (closed in 2010) designed to set out Guidelines for collecting and interpreting harmonised data at the European level on organisational change and its economic and social impacts.</li><li><a href="http://www.ilo.org/global/statistics-and-databases/lang--en/index.htm" target="_blank">ILO International Labour Organisation </a></li><li>Hämäläinen P, Saarela KL, Takala J: <a href="https://osha.europa.eu/en/press/articles/estimates-fatal-work-diseased/view">Global trend according to estimated number of occupational accidents and fatal work-related diseases at region and country level</a></li></ul><p>[LINKS TO BE CHECKED]</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>The surveys are the cornerstone of our work, and the results help policy-makers and researchers to identify emerging trends.</p>
<p>You will also find useful statistics on safety and health in the workplace in the following sources: [IT WOULD BE BETTER IF THIS 2 PARAGRAPH COULD BE MOVED BELOW THE SUBSECTIONS]</p>
<ul><li><a href="http://epp.eurostat.ec.europa.eu/portal/page/portal/eurostat/home//portal/page/portal/eurostat/home//portal/page/portal/eurostat/home/" target="_blank">EUROSTAT</a> website and EUROSTAT <a href="http://epp.eurostat.ec.europa.eu/portal/page/portal/eurostat/home//portal/page/portal/eurostat/home//portal/page/portal/product_details/publication?p_product_code=KS-SF-09-063" target="_blank">Labour Force Survey 2007 ad hoc module on accidents at work and work-related health problems</a></li>
<li>European Foundation for the Improvement of Working and Living Conditions (EUROFUND): <a href="http://www.eurofound.europa.eu/ewco/surveys/index.htm" target="_blank">European Working Conditions Surveys</a> and <a href="http://www.eurofound.europa.eu/surveys/index.htm" target="_blank">other surveys</a></li>
<li>DG Employment, Social Affairs and Equal Opportunities: <a href="http://ec.europa.eu/social/main.jsp?catId=706&amp;langId=en" target="_blank">improving working conditions</a></li>
<li><a href="http://www.meadow-project.eu/" target="_blank">MEADOW</a> - a European project (closed in 2010) designed to set out Guidelines for collecting and interpreting harmonised data at the European level on organisational change and its economic and social impacts.</li>
<li><a href="http://www.ilo.org/global/statistics-and-databases/lang--en/index.htm" target="_blank">ILO International Labour Organisation </a></li>
<li>Hämäläinen P, Saarela KL, Takala J: <a href="https://osha.europa.eu/en/press/articles/estimates-fatal-work-diseased/view">Global trend according to estimated number of occupational accidents and fatal work-related diseases at region and country level</a></li>
</ul><p>[LINKS TO BE CHECKED]</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Surveys and statistics on OSH',
        'format' => NULL,
        'safe_value' => 'Surveys and statistics on OSH',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'Here you will find the results of our European surveys and opinion polls. These provide a snapshot of how workplace risks are managed and how people feel about their work environment. 
',
        'format' => NULL,
        'safe_value' => 'Here you will find the results of our European surveys and opinion polls. These provide a snapshot of how workplace risks are managed and how people feel about their work environment. 
',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 11,
    'source' => 'node/5',
    'alias' => 'articles/surveys-and-statistics-osh',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 5,
      'vid' => 5,
      'nid' => 5,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Surveys and statistics on OSH',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 5,
      'vid' => 5,
      'nid' => 5,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Surveys and statistics on OSH',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 5,
      'vid' => 5,
      'nid' => 5,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Surveys and statistics on OSH',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:19:37 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'National legislation',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '66b0577e-0019-4e05-a95e-ed17c10f085c',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859193,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '4e4c748b-77be-443c-843e-194de4e7a3c1',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>Member States may adopt stricter rules to protect workers — but their legislation must comply with the minimum standards. As a result, national safety and health legislation varies across Europe.</p><p class="Textfo">A list of the <strong>national implementation measures</strong> can be found at the end of each directive’s abstract<a id="_anchor_1" name="_msoanchor_1" href="#_msocom_1"></a> in the EU-OSHA section on European directives [LINK]. For example, if you select the OSH framework directive (LINK<a id="_anchor_2" name="_msoanchor_2" href="#_msocom_2"></a>) you will find at the bottom of the page a link to the EUR-Lex website listing the national implementing laws for this directive.</p><p class="Textfo">More information on national occupational safety and health laws is also available in the <strong><a href="http://oshwiki.eu/wiki/Category:Main_OSH_players_-_organisations">OSHwiki articles on national systems</a></strong>.</p><p class="Textfo">Find out more about national legislation by <strong>contacting the relevant EU-OSHA Focal Point</strong> of the Member State you are interested in.</p><p class="Textfo">&nbsp;</p><p class="Textfo"><strong>&gt;&gt;&gt; create LINKs to FOPs, directives, OSH framework directive</strong></p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>Member States may adopt stricter rules to protect workers — but their legislation must comply with the minimum standards. As a result, national safety and health legislation varies across Europe.</p>
<p class="Textfo">A list of the <strong>national implementation measures</strong> can be found at the end of each directive’s abstract<a id="_anchor_1" name="_msoanchor_1" href="#_msocom_1"></a> in the EU-OSHA section on European directives [LINK]. For example, if you select the OSH framework directive (LINK<a id="_anchor_2" name="_msoanchor_2" href="#_msocom_2"></a>) you will find at the bottom of the page a link to the EUR-Lex website listing the national implementing laws for this directive.</p>
<p class="Textfo">More information on national occupational safety and health laws is also available in the <strong><a href="http://oshwiki.eu/wiki/Category:Main_OSH_players_-_organisations">OSHwiki articles on national systems</a></strong>.</p>
<p class="Textfo">Find out more about national legislation by <strong>contacting the relevant EU-OSHA Focal Point</strong> of the Member State you are interested in.</p>
<p class="Textfo"> </p>
<p class="Textfo"><strong>&gt;&gt;&gt; create LINKs to FOPs, directives, OSH framework directive</strong></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'National legislation',
        'format' => NULL,
        'safe_value' => 'National legislation',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'European directives set out the minimum standards for safety and health in the workplace. The EU directives are implemented through the national legislation of Member States.',
        'format' => NULL,
        'safe_value' => 'European directives set out the minimum standards for safety and health in the workplace. The EU directives are implemented through the national legislation of Member States.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 13,
    'source' => 'node/6',
    'alias' => 'articles/national-legislation',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 6,
      'vid' => 6,
      'nid' => 6,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'National legislation',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 6,
      'vid' => 6,
      'nid' => 6,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'National legislation',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 6,
      'vid' => 6,
      'nid' => 6,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'National legislation',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:19:53 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'European Standards',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '05fef34c-3d05-421c-8cad-edfafd9093e8',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859239,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '57d9e0dc-976e-4e5d-b792-ba007ccb98a9',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>Migrate here this content</p><p>https://osha.europa.eu/en/legislation/standards</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>Migrate here this content</p>
<p><a href="https://osha.europa.eu/en/legislation/standards">https://osha.europa.eu/en/legislation/standards</a></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'European Standards',
        'format' => NULL,
        'safe_value' => 'European Standards',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 18,
    'source' => 'node/7',
    'alias' => 'articles/european-standards',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 7,
      'vid' => 7,
      'nid' => 7,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Standards',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 7,
      'vid' => 7,
      'nid' => 7,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Standards',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 7,
      'vid' => 7,
      'nid' => 7,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Standards',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:20:39 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Mainstreaming OSH into education',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '14a0aee0-bc68-4f6d-be8f-6ff0bcba30cf',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859208,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '5845537c-3225-403e-af90-55814b352b65',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<h2>Start young, stay safe</h2><p class="Textfo">If children start learning about safety and health as they learn to read and write, it becomes a natural part of how they work, play and live. They develop a good attitude to safety and health that will stay with them throughout their working lives.</p><div class="wysiwyg_accordion"><h3>Successful OSH education</h3><p class="Textfo">OSH is best integrated into individual subjects rather than taught as a stand-alone topic. Activity-based learning and real-life examples will help bring the message home to children and young people. Key messages can be repeated in different ways for different age-groups, whether in primary schools or vocational training colleges.</p><p class="Textfo">The <a href="publications/reports/occupational-safety-and-health-and-education-a-whole-school-approach">whole-school approach</a> is the ideal model.</p><h3>Integrating OSH into school life</h3><p class="Textfo">The whole-school approach combines education and school management. Pupils and staff work together to make the school a safe and healthy place to work and learn through:</p><ul><li>Risk education and OSH management, e.g. involving pupils in hazard spotting</li><li>Health education and promotion, e.g. healthy schools initiatives</li><li>Promoting dignity and respect for all, e.g. anti-bullying campaigns</li><li>Caring for the environment, e.g. reusing and recycling</li></ul><h3>Tips for successful integration</h3><p class="Textfo">From case studies we know what helps to make the whole-school approach work:</p><ul><li>Leadership from the head teacher to motivate staff and pupils</li><li>Involving pupils, parents and staff</li><li>Providing practical support and tools;&nbsp; the ‘<a href="http://www.napofilm.net/en/napo-for-teachers">Napo for teachers</a>’ resource has been helpful here</li><li><a href="publications/factsheets/103">Training for teachers</a></li><li>Networking between schools</li><li>Cooperation between OSH and education authorities</li><li>Being practical and linking &nbsp;risk education to subjects being taught</li></ul></div><h2>Beyond school</h2><p class="Textfo">The integration of OSH into further education is more difficult and less well developed, particularly in <a href="https://osha.europa.eu/en/publications/factsheets/91/view">universities</a>. However, the same ‘whole-institute’ model applies. Networking and working in partnership with OSH authorities are key contributors to successful integration.</p><h2>Resources</h2><p class="Textfo"><a href="http://oshwiki.eu/wiki/Mainstreaming_OSH_into_education">Read more about mainstreaming OSH into education</a>.</p><p class="Textfo"><a href="https://osha.europa.eu/en/publications/factsheets/82/view">Read our report on mainstreaming OSH into the school curriculum programmes</a></p><p class="Textfo"><a href="http://www.enetosh.net/">Network with other professionals through ENETOSH</a>.</p><p class="Textfo"><a href="http://www.napofilm.net/en/napo-for-teachers">Use Napo for teachers</a></p><p>&nbsp;</p><p><span style="font-size: large;"><strong>&gt;&gt;&gt; THE LAST PARAGRAPH SHOULD DISAPPEAR AS IT WILL BE DISPLAYED</strong></span></p><p><span style="font-size: large;"><strong>IN THE RIGHT HAND PORTLET,</strong></span></p><p><span style="font-size: large;"><strong>TO BE CONFIRMED BY PROJECT MANAGER</strong></span></p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<h2>Start young, stay safe</h2>
<p class="Textfo">If children start learning about safety and health as they learn to read and write, it becomes a natural part of how they work, play and live. They develop a good attitude to safety and health that will stay with them throughout their working lives.</p>
<div class="wysiwyg_accordion">
<h3>Successful OSH education</h3>
<p class="Textfo">OSH is best integrated into individual subjects rather than taught as a stand-alone topic. Activity-based learning and real-life examples will help bring the message home to children and young people. Key messages can be repeated in different ways for different age-groups, whether in primary schools or vocational training colleges.</p>
<p class="Textfo">The <a href="publications/reports/occupational-safety-and-health-and-education-a-whole-school-approach">whole-school approach</a> is the ideal model.</p>
<h3>Integrating OSH into school life</h3>
<p class="Textfo">The whole-school approach combines education and school management. Pupils and staff work together to make the school a safe and healthy place to work and learn through:</p>
<ul><li>Risk education and OSH management, e.g. involving pupils in hazard spotting</li>
<li>Health education and promotion, e.g. healthy schools initiatives</li>
<li>Promoting dignity and respect for all, e.g. anti-bullying campaigns</li>
<li>Caring for the environment, e.g. reusing and recycling</li>
</ul><h3>Tips for successful integration</h3>
<p class="Textfo">From case studies we know what helps to make the whole-school approach work:</p>
<ul><li>Leadership from the head teacher to motivate staff and pupils</li>
<li>Involving pupils, parents and staff</li>
<li>Providing practical support and tools;  the ‘<a href="http://www.napofilm.net/en/napo-for-teachers">Napo for teachers</a>’ resource has been helpful here</li>
<li><a href="publications/factsheets/103">Training for teachers</a></li>
<li>Networking between schools</li>
<li>Cooperation between OSH and education authorities</li>
<li>Being practical and linking  risk education to subjects being taught</li>
</ul></div>
<h2>Beyond school</h2>
<p class="Textfo">The integration of OSH into further education is more difficult and less well developed, particularly in <a href="https://osha.europa.eu/en/publications/factsheets/91/view">universities</a>. However, the same ‘whole-institute’ model applies. Networking and working in partnership with OSH authorities are key contributors to successful integration.</p>
<h2>Resources</h2>
<p class="Textfo"><a href="http://oshwiki.eu/wiki/Mainstreaming_OSH_into_education">Read more about mainstreaming OSH into education</a>.</p>
<p class="Textfo"><a href="https://osha.europa.eu/en/publications/factsheets/82/view">Read our report on mainstreaming OSH into the school curriculum programmes</a></p>
<p class="Textfo"><a href="http://www.enetosh.net/">Network with other professionals through ENETOSH</a>.</p>
<p class="Textfo"><a href="http://www.napofilm.net/en/napo-for-teachers">Use Napo for teachers</a></p>
<p> </p>
<p><span style="font-size: large;"><strong>&gt;&gt;&gt; THE LAST PARAGRAPH SHOULD DISAPPEAR AS IT WILL BE DISPLAYED</strong></span></p>
<p><span style="font-size: large;"><strong>IN THE RIGHT HAND PORTLET,</strong></span></p>
<p><span style="font-size: large;"><strong>TO BE CONFIRMED BY PROJECT MANAGER</strong></span></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Mainstreaming OSH into education',
        'format' => NULL,
        'safe_value' => 'Mainstreaming OSH into education',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-05 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'Mainstreaming — or integrating — OSH into education means including it systematically in classroom lessons. Ideally it become part of everyday life for pupils, students and staff. ',
        'format' => NULL,
        'safe_value' => 'Mainstreaming — or integrating — OSH into education means including it systematically in classroom lessons. Ideally it become part of everyday life for pupils, students and staff. ',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 15,
    'source' => 'node/8',
    'alias' => 'articles/mainstreaming-osh-education',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 8,
      'vid' => 8,
      'nid' => 8,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Mainstreaming OSH into education',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 8,
      'vid' => 8,
      'nid' => 8,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Mainstreaming OSH into education',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 8,
      'vid' => 8,
      'nid' => 8,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Mainstreaming OSH into education',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:20:08 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'European Directives ',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '925c228d-f81a-4fc6-b0ad-1f3b25d95d6b',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859279,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '6f6f90f0-e453-40af-b0bd-593af4da286f',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>Article&nbsp;153 of the <a href="http://eur-lex.europa.eu/collection/eu-law/treaties.html" target="_blank">Treaty on the Functioning of the European Union</a> gives the EU the authority to adopt directives in the field of safety and health at work. The Framework Directive [LINK]<strong>,</strong> with its wide scope of application, and further directives focusing on specific aspects of safety and health at workare the fundamentals of European safety and health legislation.</p><p>Member States are free to adopt stricter rules for the protection of workers when transposing EU directives into national law. Therefore, legislative requirements in the field of safety and health at work can vary across EU Member States.</p><p>Information about EU directives in this section is arranged by topic. To read a specific EU directive, please click on one of the categories below.</p><p><strong>The OSH Framework Directive</strong></p><p><strong>Workplaces, equipment, signs, personal protective equipment</strong></p><p><strong>Exposure to chemical agents and chemical safety</strong></p><p><strong>Exposure to physical hazards</strong></p><p><strong>Exposure to biological agents</strong></p><p><strong>Provisions on workload, ergonomical and psychosocial risks</strong></p><p><strong>Sector specific and worker related provisions</strong></p><p><strong>Directive summaries are available only in English, </strong>but links at the end of each summary lead to the full text of the directive in all EU languages.</p><p>In addition to the Framework Directive [link], a series of <strong>individual directives</strong> focusing on specific aspects of safety and health at work were adopted. Nevertheless, the Framework Directive continues to apply to all areas covered by the individual directives. Where individual directives contain more stringent and specific provisions, these special provisions prevail. Individual directives tailor the principles of the Framework Directive to:</p><ul type="disc"><li>specific tasks (e.g. manual handling of loads)</li><li>specific hazards at work (e.g. exposure to dangerous substances or physical agents)</li><li>specific workplaces and sectors (e.g. temporary work sites, extractive industries, fishing vessels)</li><li>specific groups of workers (e.g. pregnant women, young workers, workers with a fixed duration employment contract)</li><li>certain work-related aspects (e.g. organisation of working time)</li></ul><p>The individual directives define how to assess these risks and, in some instances, set limit values for certain substances or agents.</p><p>In addition, a series of EU directives based on Article&nbsp;114 of the Treaty on the Functioning of the European Union relate to safety and health aspects. On that legal basis, a series of technical directives under the so-called ‘New Approach’ were adopted whereby the European standardisation organisations — European Committee for Standardization (CEN), European Committee for Electrotechnical Standardization (CENELEC) and European Telecommunications Standards Institute (ETSI) — set and update European standards on a regular basis.</p><div class="wysiwyg_accordion"><h3>European Legislative Process&nbsp;</h3><p>The <a href="http://eur-lex.europa.eu/legal-content/EN/TXT/?uri=COM:2014:332:FIN" target="_blank"><strong>EU Strategic Framework on Health and Safety at Work 2014–2020</strong></a> sets out the political framework for European safety and health policy. The starting point for legislative initiatives at European level is a legislative proposal drafted by the <a href="http://ec.europa.eu/social/main.jsp?catId=148&amp;langId=en" target="_blank">European Commission</a>. Under the ‘ordinary legislative procedure’, it is the European Council and the European Parliament that adopt EU directives. In some cases, they delegate the legislative power to adapt directives to technical progress to the European Commission.</p><p>The <a href="http://ec.europa.eu/social/main.jsp?catId=329&amp;langId=en" target="_blank">European Social Partners</a> play a vital role in the European decision-making process in the field of safety and health at work, as they have to be consulted at various stages. The Treaty on the Functioning of the European Union also foresees the possibility of concluding autonomous agreements. So far, European social dialogue has resulted in the adoption of several autonomous agreements.</p><h3>Historical background on safety and health legislation</h3><p>The first European directives on safety and health at work were adopted on the basis of the general market harmonisation provisions. This was due to a lack of an explicit legislative competence in the Treaty in the field of safety and health at work until the mid-1980s. Before this occupational safety and health was seen as an annex to market harmonisation and the economic policies of the European Economic Community. For example, Directive 77/576/ EEC on the harmonisation of national laws on safety signs at the workplace and Directive 78/610/ EEC on the harmonisation of occupational exposure limits to vinyl chloride monomers were adopted on this basis.</p><p>The Single European Act 1987 was a major step forward in that it introduced a new legal provision on social policy to the Treaty aiming for ‘improvements, especially in the working environment, as regards the health and safety of workers’. By inserting this provision into the Treaty, the importance of safe working conditions was made evident. Moreover, the new Social Chapter authorised the European Commission to promote social dialogue between employers and labour representatives at European level.</p><p>With the Treaty of Amsterdam in 1997, the legislative competence in the field of European social policies was further strengthened by the incorporation of the social agreement into the Treaty. The Treaty of Lisbon — apart from the renumbering of the Articles on social policy — kept the substance of the provisions of ex Articles&nbsp;136 ff TEC (now Articles&nbsp;151 ff of the Treaty on the Functioning of the European Union).</p></div><p>&nbsp;</p><div><div>&nbsp;</div></div>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>Article 153 of the <a href="http://eur-lex.europa.eu/collection/eu-law/treaties.html" target="_blank">Treaty on the Functioning of the European Union</a> gives the EU the authority to adopt directives in the field of safety and health at work. The Framework Directive [LINK]<strong>,</strong> with its wide scope of application, and further directives focusing on specific aspects of safety and health at workare the fundamentals of European safety and health legislation.</p>
<p>Member States are free to adopt stricter rules for the protection of workers when transposing EU directives into national law. Therefore, legislative requirements in the field of safety and health at work can vary across EU Member States.</p>
<p>Information about EU directives in this section is arranged by topic. To read a specific EU directive, please click on one of the categories below.</p>
<p><strong>The OSH Framework Directive</strong></p>
<p><strong>Workplaces, equipment, signs, personal protective equipment</strong></p>
<p><strong>Exposure to chemical agents and chemical safety</strong></p>
<p><strong>Exposure to physical hazards</strong></p>
<p><strong>Exposure to biological agents</strong></p>
<p><strong>Provisions on workload, ergonomical and psychosocial risks</strong></p>
<p><strong>Sector specific and worker related provisions</strong></p>
<p><strong>Directive summaries are available only in English, </strong>but links at the end of each summary lead to the full text of the directive in all EU languages.</p>
<p>In addition to the Framework Directive [link], a series of <strong>individual directives</strong> focusing on specific aspects of safety and health at work were adopted. Nevertheless, the Framework Directive continues to apply to all areas covered by the individual directives. Where individual directives contain more stringent and specific provisions, these special provisions prevail. Individual directives tailor the principles of the Framework Directive to:</p>
<ul type="disc"><li>specific tasks (e.g. manual handling of loads)</li>
<li>specific hazards at work (e.g. exposure to dangerous substances or physical agents)</li>
<li>specific workplaces and sectors (e.g. temporary work sites, extractive industries, fishing vessels)</li>
<li>specific groups of workers (e.g. pregnant women, young workers, workers with a fixed duration employment contract)</li>
<li>certain work-related aspects (e.g. organisation of working time)</li>
</ul><p>The individual directives define how to assess these risks and, in some instances, set limit values for certain substances or agents.</p>
<p>In addition, a series of EU directives based on Article 114 of the Treaty on the Functioning of the European Union relate to safety and health aspects. On that legal basis, a series of technical directives under the so-called ‘New Approach’ were adopted whereby the European standardisation organisations — European Committee for Standardization (CEN), European Committee for Electrotechnical Standardization (CENELEC) and European Telecommunications Standards Institute (ETSI) — set and update European standards on a regular basis.</p>
<div class="wysiwyg_accordion">
<h3>European Legislative Process </h3>
<p>The <a href="http://eur-lex.europa.eu/legal-content/EN/TXT/?uri=COM:2014:332:FIN" target="_blank"><strong>EU Strategic Framework on Health and Safety at Work 2014–2020</strong></a> sets out the political framework for European safety and health policy. The starting point for legislative initiatives at European level is a legislative proposal drafted by the <a href="http://ec.europa.eu/social/main.jsp?catId=148&amp;langId=en" target="_blank">European Commission</a>. Under the ‘ordinary legislative procedure’, it is the European Council and the European Parliament that adopt EU directives. In some cases, they delegate the legislative power to adapt directives to technical progress to the European Commission.</p>
<p>The <a href="http://ec.europa.eu/social/main.jsp?catId=329&amp;langId=en" target="_blank">European Social Partners</a> play a vital role in the European decision-making process in the field of safety and health at work, as they have to be consulted at various stages. The Treaty on the Functioning of the European Union also foresees the possibility of concluding autonomous agreements. So far, European social dialogue has resulted in the adoption of several autonomous agreements.</p>
<h3>Historical background on safety and health legislation</h3>
<p>The first European directives on safety and health at work were adopted on the basis of the general market harmonisation provisions. This was due to a lack of an explicit legislative competence in the Treaty in the field of safety and health at work until the mid-1980s. Before this occupational safety and health was seen as an annex to market harmonisation and the economic policies of the European Economic Community. For example, Directive 77/576/ EEC on the harmonisation of national laws on safety signs at the workplace and Directive 78/610/ EEC on the harmonisation of occupational exposure limits to vinyl chloride monomers were adopted on this basis.</p>
<p>The Single European Act 1987 was a major step forward in that it introduced a new legal provision on social policy to the Treaty aiming for ‘improvements, especially in the working environment, as regards the health and safety of workers’. By inserting this provision into the Treaty, the importance of safe working conditions was made evident. Moreover, the new Social Chapter authorised the European Commission to promote social dialogue between employers and labour representatives at European level.</p>
<p>With the Treaty of Amsterdam in 1997, the legislative competence in the field of European social policies was further strengthened by the incorporation of the social agreement into the Treaty. The Treaty of Lisbon — apart from the renumbering of the Articles on social policy — kept the substance of the provisions of ex Articles 136 ff TEC (now Articles 151 ff of the Treaty on the Functioning of the European Union).</p>
</div>
<p> </p>
<div>
<div> </div>
</div>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'European Directives ',
        'format' => NULL,
        'safe_value' => 'European Directives ',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'A directive is a legal act provided for in the EU Treaty. It is binding in its entirety and obliges Member States to transpose it into national law within the a set deadline. ',
        'format' => NULL,
        'safe_value' => 'A directive is a legal act provided for in the EU Treaty. It is binding in its entirety and obliges Member States to transpose it into national law within the a set deadline. ',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 22,
    'source' => 'node/9',
    'alias' => 'articles/european-directives',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 9,
      'vid' => 9,
      'nid' => 9,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Directives ',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 9,
      'vid' => 9,
      'nid' => 9,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Directives ',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 9,
      'vid' => 9,
      'nid' => 9,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Directives ',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:21:19 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Mission and vision',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '0d81232d-ac7e-4687-af33-a901ae69d7df',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859202,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '857d1fbe-f8cc-4359-8cd7-8a2ebcfdd17c',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p class="Textfo">The mission statement defines what the Agency does. The vision statement explains what the Agency aims to achieve. It also provides a benchmark against which results can be assessed.</p><h2>Our mission</h2><p class="Textfo">We develop, gather and provide reliable and relevant information, analysis and tools to advance knowledge, raise awareness and exchange occupational safety and health (OSH) information and good practice which will serve the needs of those involved in OSH.</p><h2>Our vision</h2><p class="Textfo">To be a recognised leader promoting healthy and safe workplaces in Europe based on tripartism, participation and the development of an OSH risk prevention culture, to ensure a smart, sustainable, productive and inclusive economy.</p><h2>The framework<a id="_anchor_1" name="_msoanchor_1" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/New%20contents/45-Mission%20and%20vision.docx#_msocom_1"><br /></a></h2><p class="Textfo">EU-OSHA is the European Union information agency for occupational safety and health. Our work contributes to the European Commission’s Occupational Safety and Health (OSH) Strategic Framework 2014-2020 and other relevant EU strategies and programmes.</p><div><div><div id="_com_1"><p>&nbsp;</p><p>Read our:</p><ul><li><span style="line-height: 1.538em;">Funding regulations</span></li><li><a href="publications/corporate/eu-osha-multi-annual-strategic-programme-2014-2020">Multi-annual Strategic Programme</a> and <a href="publications/corporate/2014-annual-management-plan">annual management plan</a></li></ul></div></div></div>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p class="Textfo">The mission statement defines what the Agency does. The vision statement explains what the Agency aims to achieve. It also provides a benchmark against which results can be assessed.</p>
<h2>Our mission</h2>
<p class="Textfo">We develop, gather and provide reliable and relevant information, analysis and tools to advance knowledge, raise awareness and exchange occupational safety and health (OSH) information and good practice which will serve the needs of those involved in OSH.</p>
<h2>Our vision</h2>
<p class="Textfo">To be a recognised leader promoting healthy and safe workplaces in Europe based on tripartism, participation and the development of an OSH risk prevention culture, to ensure a smart, sustainable, productive and inclusive economy.</p>
<h2>The framework<a id="_anchor_1" name="_msoanchor_1" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/New%20contents/45-Mission%20and%20vision.docx#_msocom_1"><br /></a></h2>
<p class="Textfo">EU-OSHA is the European Union information agency for occupational safety and health. Our work contributes to the European Commission’s Occupational Safety and Health (OSH) Strategic Framework 2014-2020 and other relevant EU strategies and programmes.</p>
<div>
<div>
<div id="_com_1">
<p> </p>
<p>Read our:</p>
<ul><li><span style="line-height: 1.538em;">Funding regulations</span></li>
<li><a href="publications/corporate/eu-osha-multi-annual-strategic-programme-2014-2020">Multi-annual Strategic Programme</a> and <a href="publications/corporate/2014-annual-management-plan">annual management plan</a></li>
</ul></div>
</div>
</div>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Mission and vision',
        'format' => NULL,
        'safe_value' => 'Mission and vision',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-08 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'EU-OSHA’s mission and vision statements explain its role within the mandate provided in the founding regulation. These statements are adopted by the Governing Board as part of the Agency’s Multi-annual Strategic Programme and annual management plan. They express how the Board wants the Agency to implement its mandate.',
        'format' => NULL,
        'safe_value' => 'EU-OSHA’s mission and vision statements explain its role within the mandate provided in the founding regulation. These statements are adopted by the Governing Board as part of the Agency’s Multi-annual Strategic Programme and annual management plan. They express how the Board wants the Agency to implement its mandate.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(
    'en' => array(
      'en' => array(
        'en' => array(
          'en' => array(
            'title' => array(
              'value' => 'Mission and vision of EU-OSHA',
            ),
          ),
        ),
      ),
    ),
  ),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 14,
    'source' => 'node/10',
    'alias' => 'articles/mission-and-vision',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 10,
      'vid' => 10,
      'nid' => 10,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Mission and vision',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 10,
      'vid' => 10,
      'nid' => 10,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Mission and vision',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 10,
      'vid' => 10,
      'nid' => 10,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Mission and vision',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:20:02 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Inside EU-OSHA',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '42303b8f-5d07-4596-ab91-6eb31931919b',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859538,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'a065ac76-7af7-4164-b44a-596287e6eb65',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>Of course, a huge part of our mission is raising awareness of OSH issues. Our <strong>press office</strong> offers all the support you need to cover OSH issues. Get in touch or <strong>read the latest stories</strong>.&nbsp;</p><p>You can also find out more about the<strong> national Focal Points w</strong>ho work with us to achieve our goals.</p><p>Or maybe you’re interested in working with us yourself? Whether you want to <strong>tender for a contract</strong> or <strong>apply for a job</strong> with us, you can find the information you need in the section.</p><p>&nbsp;</p><p><strong>&gt;&gt; create LINKS to press office, press releases, FOPs, procurement, vacancies</strong></p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>Of course, a huge part of our mission is raising awareness of OSH issues. Our <strong>press office</strong> offers all the support you need to cover OSH issues. Get in touch or <strong>read the latest stories</strong>. </p>
<p>You can also find out more about the<strong> national Focal Points w</strong>ho work with us to achieve our goals.</p>
<p>Or maybe you’re interested in working with us yourself? Whether you want to <strong>tender for a contract</strong> or <strong>apply for a job</strong> with us, you can find the information you need in the section.</p>
<p> </p>
<p><strong>&gt;&gt; create LINKS to press office, press releases, FOPs, procurement, vacancies</strong></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Inside EU-OSHA',
        'format' => NULL,
        'safe_value' => 'Inside EU-OSHA',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'At EU-OSHA, we aim to be open and transparent. Here, you can discover who we are, how we are organised and what our vision is.',
        'format' => NULL,
        'safe_value' => 'At EU-OSHA, we aim to be open and transparent. Here, you can discover who we are, how we are organised and what our vision is.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 32,
    'source' => 'node/11',
    'alias' => 'articles/inside-eu-osha',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 11,
      'vid' => 11,
      'nid' => 11,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Inside EU-OSHA',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 11,
      'vid' => 11,
      'nid' => 11,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Inside EU-OSHA',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 11,
      'vid' => 11,
      'nid' => 11,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Inside EU-OSHA',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:25:38 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'European Risk Observatory',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'd9156f3f-ba95-4a1c-a558-9a9a82597fbf',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859247,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'a940a49d-3ea0-4dee-b487-d301ce495610',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p><strong>Objectives</strong></p><p>As our society evolves under the <strong>influence of new technology and shifting economic and social conditions</strong>, so our workplaces, work practices and processes are constantly changing. These new situations bring with them new risks and challenges for workers and employers which in turn demand <strong>political, administrative and technical approaches </strong>that ensure high levels of safety and health at work.</p><p>The <a href="http://eur-lex.europa.eu/smartapi/cgi/sga_doc?smartapi%21celexplus%21prod%21DocNumber&amp;lg=en&amp;type_doc=COMfinal&amp;an_doc=2002&amp;nu_doc=118" target="_blank">Community Strategy on health and safety at work 2002-2006</a> identified the need to prepare for these new circumstances, and emphasised that</p><p align="center"><em>\'<strong>anticipating </strong>new and emerging risks, whether they be linked to <strong>technical innovation </strong>or caused by <strong>social change</strong>, is vital if the risks are to be brought under control.</em><br /> <em>This requires, first and foremost, <strong>ongoing observation</strong> of the risks themselves, based on the <strong>systematic collection of information and scientific opinions</strong>\'.</em></p><p>The Strategy, therefore, asked the EU-OSHA to set up an European Risk Observatory to carry out these tasks. The <a href="http://eur-lex.europa.eu/LexUriServ/LexUriServ.do?uri=COM:2007:0062:FIN:en:PDF" target="_blank">Community Strategy 2007-2012</a> reiterated the importance of risk anticipation, and asked the Agency’s Observatory to take on a range of initiatives.<br /> &nbsp;</p><p><strong>How the European Risk Observatory works</strong></p><p>The ERO adds value by <strong>gathering and analysing information</strong>, putting it in context (in particular in relation to the European social agenda and the Community Strategy), <strong>looking for trends in order to \'anticipate change\'</strong>, and communicating the key issues effectively to our <strong>target audience</strong>: <strong>policy-makers</strong> and <strong>researchers</strong>. We also aim to stimulate debate and reflection among EU-OSHA\'s stakeholders and to provide a <strong>platform for debate</strong> between experts and policy-makers at various levels.</p><p>The information need to identify new and emerging risks may come from a variety of sources, such as <strong>data from official registers</strong>, the <strong>research literature</strong>, <strong>expert forecasts </strong>or <strong>survey data</strong>. To cover all these potential sources of information, we organise our activities around four basic areas.</p><ul><li>Anticipating new and emerging risks [link]</li><li>Enterprise survey (ESENER) [link]</li><li>Fostering OSH research coordination in the EU [this text has to be confirmed, maybe to be expanded]<a id="_anchor_1" name="_msoanchor_1" href="#_msocom_1"><br /></a></li></ul><p align="left">&nbsp;</p><p align="left">&nbsp;</p><div><hr align="left" size="1" width="33%" /></div>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p><strong>Objectives</strong></p>
<p>As our society evolves under the <strong>influence of new technology and shifting economic and social conditions</strong>, so our workplaces, work practices and processes are constantly changing. These new situations bring with them new risks and challenges for workers and employers which in turn demand <strong>political, administrative and technical approaches </strong>that ensure high levels of safety and health at work.</p>
<p>The <a href="http://eur-lex.europa.eu/smartapi/cgi/sga_doc?smartapi%21celexplus%21prod%21DocNumber&amp;lg=en&amp;type_doc=COMfinal&amp;an_doc=2002&amp;nu_doc=118" target="_blank">Community Strategy on health and safety at work 2002-2006</a> identified the need to prepare for these new circumstances, and emphasised that</p>
<p align="center"><em>\'<strong>anticipating </strong>new and emerging risks, whether they be linked to <strong>technical innovation </strong>or caused by <strong>social change</strong>, is vital if the risks are to be brought under control.</em><br /><em>This requires, first and foremost, <strong>ongoing observation</strong> of the risks themselves, based on the <strong>systematic collection of information and scientific opinions</strong>\'.</em></p>
<p>The Strategy, therefore, asked the EU-OSHA to set up an European Risk Observatory to carry out these tasks. The <a href="http://eur-lex.europa.eu/LexUriServ/LexUriServ.do?uri=COM:2007:0062:FIN:en:PDF" target="_blank">Community Strategy 2007-2012</a> reiterated the importance of risk anticipation, and asked the Agency’s Observatory to take on a range of initiatives.<br />  </p>
<p><strong>How the European Risk Observatory works</strong></p>
<p>The ERO adds value by <strong>gathering and analysing information</strong>, putting it in context (in particular in relation to the European social agenda and the Community Strategy), <strong>looking for trends in order to \'anticipate change\'</strong>, and communicating the key issues effectively to our <strong>target audience</strong>: <strong>policy-makers</strong> and <strong>researchers</strong>. We also aim to stimulate debate and reflection among EU-OSHA\'s stakeholders and to provide a <strong>platform for debate</strong> between experts and policy-makers at various levels.</p>
<p>The information need to identify new and emerging risks may come from a variety of sources, such as <strong>data from official registers</strong>, the <strong>research literature</strong>, <strong>expert forecasts </strong>or <strong>survey data</strong>. To cover all these potential sources of information, we organise our activities around four basic areas.</p>
<ul><li>Anticipating new and emerging risks [link]</li>
<li>Enterprise survey (ESENER) [link]</li>
<li>Fostering OSH research coordination in the EU [this text has to be confirmed, maybe to be expanded]<a id="_anchor_1" name="_msoanchor_1" href="#_msocom_1"><br /></a></li>
</ul><p align="left"> </p>
<p align="left"> </p>
<div>
<hr align="left" size="1" width="33%" /></div>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'European Risk Observatory',
        'format' => NULL,
        'safe_value' => 'European Risk Observatory',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'The aim of EU-OSHA’s European Risk Observatory (ERO) is to identify new and emerging risks in occupational safety and health, in order to improve the timeliness and effectiveness of preventive measures. To achieve this aim, the ERO provides an overview of safety and health at work in Europe, describes the trends and underlying factors, and anticipates changes in work and their likely impact on occupational safety and health',
        'format' => NULL,
        'safe_value' => 'The aim of EU-OSHA’s European Risk Observatory (ERO) is to identify new and emerging risks in occupational safety and health, in order to improve the timeliness and effectiveness of preventive measures. To achieve this aim, the ERO provides an overview of safety and health at work in Europe, describes the trends and underlying factors, and anticipates changes in work and their likely impact on occupational safety and health',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 19,
    'source' => 'node/12',
    'alias' => 'articles/european-risk-observatory',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 12,
      'vid' => 12,
      'nid' => 12,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Risk Observatory',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 12,
      'vid' => 12,
      'nid' => 12,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Risk Observatory',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 12,
      'vid' => 12,
      'nid' => 12,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'European Risk Observatory',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:20:47 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Themes',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '80b12e6a-00b6-42cc-9979-960e3faa7b6f',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859337,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'bf53c93b-3db2-40dc-9f76-79de045897d2',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>The subjects covered are fast-changing areas of OSH, so sign up to our <strong>alert service</strong> if you would like to be kept up to date.</p><p>You can also find more OSH-themed information on <strong><a href="http://oshwiki.eu/wiki/" target="_blank">OSHwiki</a></strong>.</p><p>&nbsp;</p><p>&gt;&gt;&gt; LINK to alert service</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>The subjects covered are fast-changing areas of OSH, so sign up to our <strong>alert service</strong> if you would like to be kept up to date.</p>
<p>You can also find more OSH-themed information on <strong><a href="http://oshwiki.eu/wiki/" target="_blank">OSHwiki</a></strong>.</p>
<p> </p>
<p>&gt;&gt;&gt; LINK to alert service</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Themes',
        'format' => NULL,
        'safe_value' => 'Themes',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'Browse our current OSH themes. Each section brings together useful information on a particular topic, making finding what you need quick and easy.',
        'format' => NULL,
        'safe_value' => 'Browse our current OSH themes. Each section brings together useful information on a particular topic, making finding what you need quick and easy.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 29,
    'source' => 'node/13',
    'alias' => 'articles/themes',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 13,
      'vid' => 13,
      'nid' => 13,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Themes',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 13,
      'vid' => 13,
      'nid' => 13,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Themes',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 13,
      'vid' => 13,
      'nid' => 13,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Themes',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:22:17 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Campaigns',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '45edc132-03c8-40e6-84d7-1cf2b22bc984',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859311,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'd5745241-8849-44c4-8adb-2a07d1407afb',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>That message is — good management of OSH is good for business. We help you to promote it by making practical guides and tools freely available. Each campaign also features the Good Practice Awards and the Healthy Workplaces Film Award. The campaigns are now the largest of their kind in the world. Why not join us and use our online Campaign Toolkit to run your own campaign?</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>That message is — good management of OSH is good for business. We help you to promote it by making practical guides and tools freely available. Each campaign also features the Good Practice Awards and the Healthy Workplaces Film Award. The campaigns are now the largest of their kind in the world. Why not join us and use our online Campaign Toolkit to run your own campaign?</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Campaigns',
        'format' => NULL,
        'safe_value' => 'Campaigns',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'The Healthy Workplaces Campaigns are our flagship awareness-raising activity. They are the main way of getting our message to workplaces, particularly small organisations, across Europe.',
        'format' => NULL,
        'safe_value' => 'The Healthy Workplaces Campaigns are our flagship awareness-raising activity. They are the main way of getting our message to workplaces, particularly small organisations, across Europe.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 25,
    'source' => 'node/14',
    'alias' => 'articles/campaigns',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 14,
      'vid' => 14,
      'nid' => 14,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Campaigns',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 14,
      'vid' => 14,
      'nid' => 14,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Campaigns',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 14,
      'vid' => 14,
      'nid' => 14,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Campaigns',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:21:51 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Leadership and worker participation',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '1e41fd01-fcdc-486b-a1b4-95259964a563',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859214,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'dc21d794-563b-4ef2-aaac-d0e2dcdfb18f',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<div class="wysiwyg_accordion"><h3>Reducing risk from the top down</h3><p class="Textfo">An enterprise’s leaders — senior management, directors and/or the board — are in a position to prevent accidents and ill health in the workplace. They can do this by:</p><ul><li>Committing to and communicating an effective OSH management strategy</li><li>Developing robust safety and health management systems</li><li>Monitoring the performance of those systems</li><li>Setting a good example by following all safety procedures at all times</li><li>Motivating staff to participate in ensuring good safety and health</li></ul><h3>Paying the price for poor leadership</h3><p class="Textfo">Ineffective or non-existent leadership on OSH can result in accidents or even fatalities as well as poor mental and physical health among workers. It can damage a company’s reputation. Poor leadership can, in fact, have significant financial costs as a result of, for example, sick days, wasted time and compensation payments.</p><p class="Textfo">Good OSH leadership, on the other hand:</p><ul><li>Prevents accidents and illness</li><li>Increases productivity and efficiency</li><li>Improves employee morale</li><li>Helps the business to win new contracts and attract high-quality employees</li></ul><h3>Taking the lead on safety and health</h3><p class="Textfo">There are some simple steps you can take to make sure that your organisation benefits from good OSH leadership. Here are some practical tips, based on <a href="http://www.hse.gov.uk/pubns/indg417.pdf" target="_blank">a guide developed by the British Health and Safety Executive</a>:</p><ul><li>Carry out regular risk assessments and act on the results</li><li>Always consider the safety and health implications of introducing new members of staff, processes and working methods</li><li>Visible leadership is effective leadership. Make sure leaders make regular visits to the ‘shop floor’ of your organisation to talk to employees about OSH problems and solutions</li><li>Demonstrate commitment by making sure that safety and health issues are always on the agenda at board meetings</li><li>Provide safety and health training to all leaders, promoting a greater awareness of the value of OSH</li></ul><h3>Working together — getting employees involved</h3><p class="Textfo">One of the keys to good OSH leadership is getting workers involved. Employers have a legal duty to consult employees on safety and health issues. But there are benefits to going beyond the minimum requirements. OSH management will be more likely to succeed if it encourages the active participation of workers and sets up a dialogue between employees and management.</p><p class="Textfo">In 2012, the Agency run a two year campaign on this topic, called Workplaces Campaign 2012–2013, Working Together for Risk Prevention<span style="font-size: large;"> [LINK]</span>.</p><p class="Textfo">This campaign concluded with a benchmarking event where campaign partners exchanged examples of good practice, with workshops on topics such as ‘Leadership training’ and ‘The safety and health culture of an organisation’. Read a summary of the event<span style="font-size: large; line-height: 1.538em;">&nbsp;</span><span style="font-size: large; line-height: 1.538em;">[LINK]</span><span style="line-height: 1.538em;">.</span></p><p class="Textfo">&nbsp;</p><p class="Textfo"><span style="font-size: x-large;">ADD LINK TO CAMPAIGN RISK PREV. SECTION AND SOS&nbsp;https://osha.europa.eu/en/seminars/benchmarking-event-summary.pdf</span></p></div><p>&gt;&gt; <strong>Link summary of the event</strong> to the migrated content of https://osha.europa.eu/en/seminars/benchmarking-event-summary.pdf</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<div class="wysiwyg_accordion">
<h3>Reducing risk from the top down</h3>
<p class="Textfo">An enterprise’s leaders — senior management, directors and/or the board — are in a position to prevent accidents and ill health in the workplace. They can do this by:</p>
<ul><li>Committing to and communicating an effective OSH management strategy</li>
<li>Developing robust safety and health management systems</li>
<li>Monitoring the performance of those systems</li>
<li>Setting a good example by following all safety procedures at all times</li>
<li>Motivating staff to participate in ensuring good safety and health</li>
</ul><h3>Paying the price for poor leadership</h3>
<p class="Textfo">Ineffective or non-existent leadership on OSH can result in accidents or even fatalities as well as poor mental and physical health among workers. It can damage a company’s reputation. Poor leadership can, in fact, have significant financial costs as a result of, for example, sick days, wasted time and compensation payments.</p>
<p class="Textfo">Good OSH leadership, on the other hand:</p>
<ul><li>Prevents accidents and illness</li>
<li>Increases productivity and efficiency</li>
<li>Improves employee morale</li>
<li>Helps the business to win new contracts and attract high-quality employees</li>
</ul><h3>Taking the lead on safety and health</h3>
<p class="Textfo">There are some simple steps you can take to make sure that your organisation benefits from good OSH leadership. Here are some practical tips, based on <a href="http://www.hse.gov.uk/pubns/indg417.pdf" target="_blank">a guide developed by the British Health and Safety Executive</a>:</p>
<ul><li>Carry out regular risk assessments and act on the results</li>
<li>Always consider the safety and health implications of introducing new members of staff, processes and working methods</li>
<li>Visible leadership is effective leadership. Make sure leaders make regular visits to the ‘shop floor’ of your organisation to talk to employees about OSH problems and solutions</li>
<li>Demonstrate commitment by making sure that safety and health issues are always on the agenda at board meetings</li>
<li>Provide safety and health training to all leaders, promoting a greater awareness of the value of OSH</li>
</ul><h3>Working together — getting employees involved</h3>
<p class="Textfo">One of the keys to good OSH leadership is getting workers involved. Employers have a legal duty to consult employees on safety and health issues. But there are benefits to going beyond the minimum requirements. OSH management will be more likely to succeed if it encourages the active participation of workers and sets up a dialogue between employees and management.</p>
<p class="Textfo">In 2012, the Agency run a two year campaign on this topic, called Workplaces Campaign 2012–2013, Working Together for Risk Prevention<span style="font-size: large;"> [LINK]</span>.</p>
<p class="Textfo">This campaign concluded with a benchmarking event where campaign partners exchanged examples of good practice, with workshops on topics such as ‘Leadership training’ and ‘The safety and health culture of an organisation’. Read a summary of the event<span style="font-size: large; line-height: 1.538em;"> </span><span style="font-size: large; line-height: 1.538em;">[LINK]</span><span style="line-height: 1.538em;">.</span></p>
<p class="Textfo"> </p>
<p class="Textfo"><span style="font-size: x-large;">ADD LINK TO CAMPAIGN RISK PREV. SECTION AND SOS <a href="https://osha.europa.eu/en/seminars/benchmarking-event-summary.pdf">https://osha.europa.eu/en/seminars/benchmarking-event-summary.pdf</a></span></p>
</div>
<p>&gt;&gt; <strong>Link summary of the event</strong> to the migrated content of <a href="https://osha.europa.eu/en/seminars/benchmarking-event-summary.pdf">https://osha.europa.eu/en/seminars/benchmarking-event-summary.pdf</a></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Leadership and worker participation',
        'format' => NULL,
        'safe_value' => 'Leadership and worker participation',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-05 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'Strong, effective and visible leadership is vital to good workplace safety and health. And, in turn, good safety and health is essential to the success of a business. Protecting employees from accidents and ill health is not only a legal and ethical duty — it’s a sign of a business that is likely to grow and thrive.',
        'format' => NULL,
        'safe_value' => 'Strong, effective and visible leadership is vital to good workplace safety and health. And, in turn, good safety and health is essential to the success of a business. Protecting employees from accidents and ill health is not only a legal and ethical duty — it’s a sign of a business that is likely to grow and thrive.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(
    'en' => array(
      'en' => array(
        'en' => array(
          'en' => array(
            'title' => array(
              'value' => 'Leadership and worker participation',
            ),
            'description' => array(
              'value' => 'Good leadership is vital for effective safety and health management. Find out how strong and effective management can benefit your business and safeguard your employees ',
            ),
          ),
        ),
      ),
    ),
  ),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 16,
    'source' => 'node/15',
    'alias' => 'articles/leadership-and-worker-participation',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 15,
      'vid' => 15,
      'nid' => 15,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Leadership and worker participation',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 15,
      'vid' => 15,
      'nid' => 15,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Leadership and worker participation',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 15,
      'vid' => 15,
      'nid' => 15,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Leadership and worker participation',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:20:14 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Green Jobs and OSH',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '70aec553-0bcd-470f-9bdc-ae76312edc26',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859343,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'e454a870-6856-42df-9fe9-dba700f05282',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<div class="wysiwyg_accordion"><h3>What are green jobs?</h3><p>Green jobs covers a wide range of different jobs in different sectors, and involves a diverse workforce. There are many different definitions of the term, such as the ones by the <a href="http://www.unep.org/PDF/UNEPGreenjobs_report08.pdf" target="_blank">United Nations Environment Programme</a>, the <a href="http://eur-lex.europa.eu/LexUriServ/LexUriServ.do?uri=SWD:2012:0092:FIN:EN:PDF" target="_blank">European Commission</a>&nbsp;or <a href="http://epp.eurostat.ec.europa.eu/cache/ITY_OFFPUB/KS-RA-09-012/EN/KS-RA-09-012-EN.PDF" target="_blank">Eurostat</a>. But green jobs can be understood as contributing, in some way, to the preservation or restoration of the environment. They can include jobs that help to protect ecosystems and biodiversity, or reduce consumption of energy and raw materials, or reduce waste and pollution. Our purpose at EU-OSHA is to raise awareness of the need for good occupational safety and health (OSH) in these jobs.</p><p>Green jobs need to provide safe, healthy and decent working conditions in order to contribute to a truly smart, sustainable and inclusive growth and meet the objectives of the <a href="http://eur-lex.europa.eu/LexUriServ/LexUriServ.do?uri=COM:2010:2020:FIN:EN:PDF" target="_blank">European Commission\'s Europe 2020 Strategy</a>.</p><h3>How is the \'green economy\' growing?</h3><p>The Europe 2020 Strategy stresses the need for growth to be sustainable, building a low-carbon, resource-efficient economy. To help make this happen, the EU has set itself targets for reducing greenhouse gas emissions, increasing the share of renewable sources in meeting Europe\'s energy needs, and increasing energy efficiency. Meeting these objectives will result in rapid growth in the \'green economy\' – for example, the targets to increase renewable energy and energy efficency by 20%, compared to 1990 levels, is expected to lead to over 1 million new jobs in the EU. Solar power, wind energy, biomass technology and waste recycling are the areas of the green economy that are experiencing the most rapid growth.</p><h3>Why is it important to consider OSH in green jobs?</h3><p>We tend to associate the word \'green\' with safety – but what is good for the environment is not necessarily good for the health and safety of workers who are employed in green jobs. In some cases already, we have seen new legislation and technologies, designed to protect the environment, resulting in workers being put at greater risk. Reducing the amount of waste being sent to landfill, for example, has resulted in higher rates of accidents and illnesses among workers whose job it is to process it.</p><p>The new technologies or working processes associated with green jobs can lead to new hazards, which call for new combinations of skills to deal with them: the \'old\' OSH knowledge cannot simply be transferred to them. Installing a solar water heater, for example, involves combining the skills of a roofer, a plumber and an electrician.</p><p>The speed at which the green economy is expected to expand could lead to skills gaps, with inexperienced workers involved in processes that they have not been trained for, and who therefore put their safety and health at risk. There may also be a stronger polarisation of the workforce towards skills, with low skilled workers pushed to accept poorer working conditions. Last but not least, economic and political pressure could lead to OSH concerns being overlooked.</p><p>If green jobs are to be truly sustainable we need to make sure that they are to the benefit of workers\' safety and health, as well as of the environment. In the green economy, as elsewhere, good OSH plays a vital role in increasing competitiveness and productivity. In this fast-developing area, we need to ensure that what is good for the environment is good for workers too.</p><h3>What is EU-OSHA doing to prevent new and emerging OSH risks in green jobs?</h3><p>Given how quickly the green economy is expected to grow, it is important that we anticipate any new or emerging OSH risks in relation to green jobs before they appear. That is why EU-OSHA has carried out a detailed foresight study, looking at how work in green jobs is likely to develop by 2020, and what future OSH challenges this may bring. The study has identified a number of possible future scenarios, given developments in green technologies, under different economic and social conditions.</p><p>The aim is to draw attention to potential OSH risks in this area, and to provide EU policymakers, in particular, with tools to help them shape the workplaces of tomorrow, and keep Europe\'s workers safe and healthy.</p></div>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<div class="wysiwyg_accordion">
<h3>What are green jobs?</h3>
<p>Green jobs covers a wide range of different jobs in different sectors, and involves a diverse workforce. There are many different definitions of the term, such as the ones by the <a href="http://www.unep.org/PDF/UNEPGreenjobs_report08.pdf" target="_blank">United Nations Environment Programme</a>, the <a href="http://eur-lex.europa.eu/LexUriServ/LexUriServ.do?uri=SWD:2012:0092:FIN:EN:PDF" target="_blank">European Commission</a> or <a href="http://epp.eurostat.ec.europa.eu/cache/ITY_OFFPUB/KS-RA-09-012/EN/KS-RA-09-012-EN.PDF" target="_blank">Eurostat</a>. But green jobs can be understood as contributing, in some way, to the preservation or restoration of the environment. They can include jobs that help to protect ecosystems and biodiversity, or reduce consumption of energy and raw materials, or reduce waste and pollution. Our purpose at EU-OSHA is to raise awareness of the need for good occupational safety and health (OSH) in these jobs.</p>
<p>Green jobs need to provide safe, healthy and decent working conditions in order to contribute to a truly smart, sustainable and inclusive growth and meet the objectives of the <a href="http://eur-lex.europa.eu/LexUriServ/LexUriServ.do?uri=COM:2010:2020:FIN:EN:PDF" target="_blank">European Commission\'s Europe 2020 Strategy</a>.</p>
<h3>How is the \'green economy\' growing?</h3>
<p>The Europe 2020 Strategy stresses the need for growth to be sustainable, building a low-carbon, resource-efficient economy. To help make this happen, the EU has set itself targets for reducing greenhouse gas emissions, increasing the share of renewable sources in meeting Europe\'s energy needs, and increasing energy efficiency. Meeting these objectives will result in rapid growth in the \'green economy\' – for example, the targets to increase renewable energy and energy efficency by 20%, compared to 1990 levels, is expected to lead to over 1 million new jobs in the EU. Solar power, wind energy, biomass technology and waste recycling are the areas of the green economy that are experiencing the most rapid growth.</p>
<h3>Why is it important to consider OSH in green jobs?</h3>
<p>We tend to associate the word \'green\' with safety – but what is good for the environment is not necessarily good for the health and safety of workers who are employed in green jobs. In some cases already, we have seen new legislation and technologies, designed to protect the environment, resulting in workers being put at greater risk. Reducing the amount of waste being sent to landfill, for example, has resulted in higher rates of accidents and illnesses among workers whose job it is to process it.</p>
<p>The new technologies or working processes associated with green jobs can lead to new hazards, which call for new combinations of skills to deal with them: the \'old\' OSH knowledge cannot simply be transferred to them. Installing a solar water heater, for example, involves combining the skills of a roofer, a plumber and an electrician.</p>
<p>The speed at which the green economy is expected to expand could lead to skills gaps, with inexperienced workers involved in processes that they have not been trained for, and who therefore put their safety and health at risk. There may also be a stronger polarisation of the workforce towards skills, with low skilled workers pushed to accept poorer working conditions. Last but not least, economic and political pressure could lead to OSH concerns being overlooked.</p>
<p>If green jobs are to be truly sustainable we need to make sure that they are to the benefit of workers\' safety and health, as well as of the environment. In the green economy, as elsewhere, good OSH plays a vital role in increasing competitiveness and productivity. In this fast-developing area, we need to ensure that what is good for the environment is good for workers too.</p>
<h3>What is EU-OSHA doing to prevent new and emerging OSH risks in green jobs?</h3>
<p>Given how quickly the green economy is expected to grow, it is important that we anticipate any new or emerging OSH risks in relation to green jobs before they appear. That is why EU-OSHA has carried out a detailed foresight study, looking at how work in green jobs is likely to develop by 2020, and what future OSH challenges this may bring. The study has identified a number of possible future scenarios, given developments in green technologies, under different economic and social conditions.</p>
<p>The aim is to draw attention to potential OSH risks in this area, and to provide EU policymakers, in particular, with tools to help them shape the workplaces of tomorrow, and keep Europe\'s workers safe and healthy.</p>
</div>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(
    'en' => array(
      0 => array(
        'fid' => NULL,
        'uid' => 1,
        'filename' => 'green-jobs-details[1].jpg',
        'uri' => 'public://pages/green-jobs-details[1].jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 100355,
        'status' => 1,
        'timestamp' => NULL,
        'type' => 'image',
        'uuid' => 'e7a1d2d0-84be-4459-9f7a-5e180b70bfcf',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'field_file_description' => array(),
        'field_language' => array(),
        'field_nace_codes' => array(),
        'field_tags' => array(),
        'field_thesaurus' => array(),
        'metatags' => array(),
        'rdf_mapping' => array(),
        'metadata' => array(
          'height' => 178,
          'width' => 560,
        ),
        'alt' => '',
        'title' => '',
        'width' => 560,
        'height' => 178,
        'uuid_features_file_data' => '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AAAQAAAAAQAAAAAAEnByaW50T3V0cHV0T3B0aW9ucwAAABIAAAAAQ3B0bmJvb2wAAAAAAENsYnJib29sAAAAAABSZ3NNYm9vbAAAAAAAQ3JuQ2Jvb2wAAAAAAENudENib29sAAAAAABMYmxzYm9vbAAAAAAATmd0dmJvb2wAAAAAAEVtbERib29sAAAAAABJbnRyYm9vbAAAAAAAQmNrZ09iamMAAAABAAAAAAAAUkdCQwAAAAMAAAAAUmQgIGRvdWJAb+AAAAAAAAAAAABHcm4gZG91YkBv4AAAAAAAAAAAAEJsICBkb3ViQG/gAAAAAAAAAAAAQnJkVFVudEYjUmx0AAAAAAAAAAAAAAAAQmxkIFVudEYjUmx0AAAAAAAAAAAAAAAAUnNsdFVudEYjUHhsQFIAAAAAAAAAAAAKdmVjdG9yRGF0YWJvb2wBAAAAAFBnUHNlbnVtAAAAAFBnUHMAAAAAUGdQQwAAAABMZWZ0VW50RiNSbHQAAAAAAAAAAAAAAABUb3AgVW50RiNSbHQAAAAAAAAAAAAAAABTY2wgVW50RiNQcmNAWQAAAAAAADhCSU0D7QAAAAAAEABIAAAAAQACAEgAAAABAAI4QklNBCYAAAAAAA4AAAAAAAAAAAAAP4AAADhCSU0EDQAAAAAABAAAAHg4QklNBBkAAAAAAAQAAAAeOEJJTQPzAAAAAAAJAAAAAAAAAAABADhCSU0nEAAAAAAACgABAAAAAAAAAAI4QklNA/UAAAAAAEgAL2ZmAAEAbGZmAAYAAAAAAAEAL2ZmAAEAoZmaAAYAAAAAAAEAMgAAAAEAWgAAAAYAAAAAAAEANQAAAAEALQAAAAYAAAAAAAE4QklNA/gAAAAAAHAAAP////////////////////////////8D6AAAAAD/////////////////////////////A+gAAAAA/////////////////////////////wPoAAAAAP////////////////////////////8D6AAAOEJJTQQAAAAAAAACAAc4QklNBAIAAAAAABAAAAAAAAAAAAAAAAAAAAAAOEJJTQQwAAAAAAAIAQEBAQEBAQE4QklNBC0AAAAAAAYAAQAAAAo4QklNBAgAAAAAABAAAAABAAACQAAAAkAAAAAAOEJJTQQeAAAAAAAEAAAAADhCSU0E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ZSA1LjAtYzA2MSA2NC4xNDA5NDksIDIwMTAvMTIvMDctMTA6NTc6MDEgICAgICAgICI+IDxyZGY6UkRGIHhtbG5zOnJkZj0iaHR0cDovL3d3dy53My5vcmcvMTk5OS8wMi8yMi1yZGYtc3ludGF4LW5zIyI+IDxyZGY6RGVzY3JpcHRpb24gcmRmOmFib3V0PSIiIHhtbG5zOnhtcD0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wLyIgeG1sbnM6cGhvdG9zaG9wPSJodHRwOi8vbnMuYWRvYmUuY29tL3Bob3Rvc2hvcC8xLjAvIiB4bWxuczpkYz0iaHR0cDovL3B1cmwub3JnL2RjL2VsZW1lbnRzLzEuMS8iIHhtbG5zOnhtcE1NPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvbW0vIiB4bWxuczpzdEV2dD0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL3NUeXBlL1Jlc291cmNlRXZlbnQjIiB4bWxuczpzdFJlZj0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL3NUeXBlL1Jlc291cmNlUmVmIyIgeG1wOkNyZWF0b3JUb29sPSJBZG9iZSBQaG90b3Nob3AgQ1M1LjEgTWFjaW50b3NoIiB4bXA6TW9kaWZ5RGF0ZT0iMjAxNC0wNy0xNFQxMTozMzoxOCswMjowMCIgeG1wOkNyZWF0ZURhdGU9IjIwMTQtMDctMTBUMTQ6MDI6MTgrMDI6MDAiIHhtcDpNZXRhZGF0YURhdGU9IjIwMTQtMDctMTRUMTE6MzM6MTgrMDI6MDAiIHBob3Rvc2hvcDpDb2xvck1vZGU9IjMiIHBob3Rvc2hvcDpJQ0NQcm9maWxlPSJBZG9iZSBSR0IgKDE5OTgpIiBkYzpmb3JtYXQ9ImltYWdlL2pwZWciIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6RDcwOTk3M0EwQTIwNjgxMUI1NjA4OTIwOUEzQkFGOTEiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6QTk0MzE4QzIyNzIwNjgxMThBNkQ4QkJDMkY0ODExNTEiIHhtcE1NOk9yaWdpbmFsRG9jdW1lbnRJRD0ieG1wLmRpZDpBOTQzMThDMjI3MjA2ODExOEE2RDhCQkMyRjQ4MTE1MSI+IDxwaG90b3Nob3A6RG9jdW1lbnRBbmNlc3RvcnM+IDxyZGY6QmFnPiA8cmRmOmxpPjRkNTA4YmE1MmQ0OTg2YjU0NTM2ODBmZjdkOTFjODdNZjwvcmRmOmxpPiA8cmRmOmxpPjczM0Q2ODExREEyRDA2NjI2RUREMzdEQUEzOEMzNUJBPC9yZGY6bGk+IDxyZGY6bGk+ODg5NzE5NGFlMTk5MWE4YWI0NmU0ZTJlN2RhYjQwNU1mPC9yZGY6bGk+IDxyZGY6bGk+QUYzRDQzQkJFMjE1RUNCQTU0QUNBNDE3Q0ZEQjJEOUQ8L3JkZjpsaT4gPHJkZjpsaT5iOWYzNzgxZGNmNTlhYWQxMjNiZTJlMTg5M2RkZWY0TWY8L3JkZjpsaT4gPHJkZjpsaT54bXAuZGlkOjVBMTA5MzMzNDYyMDY4MTE4REJCRDk4NUM4NUY0OUQ4PC9yZGY6bGk+IDwvcmRmOkJhZz4gPC9waG90b3Nob3A6RG9jdW1lbnRBbmNlc3RvcnM+IDx4bXBNTTpIaXN0b3J5PiA8cmRmOlNlcT4gPHJkZjpsaSBzdEV2dDphY3Rpb249ImNyZWF0ZWQiIHN0RXZ0Omluc3RhbmNlSUQ9InhtcC5paWQ6QTk0MzE4QzIyNzIwNjgxMThBNkQ4QkJDMkY0ODExNTEiIHN0RXZ0OndoZW49IjIwMTQtMDctMTBUMTQ6MDI6MTgrMDI6MDAiIHN0RXZ0OnNvZnR3YXJlQWdlbnQ9IkFkb2JlIFBob3Rvc2hvcCBDUzUuMSBNYWNpbnRvc2giLz4gPHJkZjpsaSBzdEV2dDphY3Rpb249InNhdmVkIiBzdEV2dDppbnN0YW5jZUlEPSJ4bXAuaWlkOkY3N0YxMTc0MDcyMDY4MTFCNTYwODkyMDlBM0JBRjkxIiBzdEV2dDp3aGVuPSIyMDE0LTA3LTE0VDExOjEyOjQ1KzAyOjAwIiBzdEV2dDpzb2Z0d2FyZUFnZW50PSJBZG9iZSBQaG90b3Nob3AgQ1M1LjEgTWFjaW50b3NoIiBzdEV2dDpjaGFuZ2VkPSIvIi8+IDxyZGY6bGkgc3RFdnQ6YWN0aW9uPSJzYXZlZCIgc3RFdnQ6aW5zdGFuY2VJRD0ieG1wLmlpZDpENjA5OTczQTBBMjA2ODExQjU2MDg5MjA5QTNCQUY5MSIgc3RFdnQ6d2hlbj0iMjAxNC0wNy0xNFQxMTozMzoxOCswMjowMCIgc3RFdnQ6c29mdHdhcmVBZ2VudD0iQWRvYmUgUGhvdG9zaG9wIENTNS4xIE1hY2ludG9zaCIgc3RFdnQ6Y2hhbmdlZD0iLyIvPiA8cmRmOmxpIHN0RXZ0OmFjdGlvbj0iY29udmVydGVkIiBzdEV2dDpwYXJhbWV0ZXJzPSJmcm9tIGFwcGxpY2F0aW9uL3ZuZC5hZG9iZS5waG90b3Nob3AgdG8gaW1hZ2UvanBlZyIvPiA8cmRmOmxpIHN0RXZ0OmFjdGlvbj0iZGVyaXZlZCIgc3RFdnQ6cGFyYW1ldGVycz0iY29udmVydGVkIGZyb20gYXBwbGljYXRpb24vdm5kLmFkb2JlLnBob3Rvc2hvcCB0byBpbWFnZS9qcGVnIi8+IDxyZGY6bGkgc3RFdnQ6YWN0aW9uPSJzYXZlZCIgc3RFdnQ6aW5zdGFuY2VJRD0ieG1wLmlpZDpENzA5OTczQTBBMjA2ODExQjU2MDg5MjA5QTNCQUY5MSIgc3RFdnQ6d2hlbj0iMjAxNC0wNy0xNFQxMTozMzoxOCswMjowMCIgc3RFdnQ6c29mdHdhcmVBZ2VudD0iQWRvYmUgUGhvdG9zaG9wIENTNS4xIE1hY2ludG9zaCIgc3RFdnQ6Y2hhbmdlZD0iLyIvPiA8L3JkZjpTZXE+IDwveG1wTU06SGlzdG9yeT4gPHhtcE1NOkRlcml2ZWRGcm9tIHN0UmVmOmluc3RhbmNlSUQ9InhtcC5paWQ6RDYwOTk3M0EwQTIwNjgxMUI1NjA4OTIwOUEzQkFGOTEiIHN0UmVmOmRvY3VtZW50SUQ9InhtcC5kaWQ6QTk0MzE4QzIyNzIwNjgxMThBNkQ4QkJDMkY0ODExNTEiIHN0UmVmOm9yaWdpbmFsRG9jdW1lbnRJRD0ieG1wLmRpZDpBOTQzMThDMjI3MjA2ODExOEE2RDhCQkMyRjQ4MTE1MSIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAg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',
      ),
    ),
  ),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Green Jobs and OSH',
        'format' => NULL,
        'safe_value' => 'Green Jobs and OSH',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'The EU is working hard to balance economic growth with the need to protect the environment, and has set itself challenging targets for reducing greenhouse gas emissions, increasing energy efficiency and promoting renewable energy, and reducing waste. This has given rise to a wide range of green jobs – jobs which contribute to preserving the environment, or restoring it to what it was. If they are to be truly sustainable, though, we need to make sure that these jobs provide safe, healthy and decent working conditions. Green jobs need to be good for workers, as well as good for the environment.
',
        'format' => NULL,
        'safe_value' => 'The EU is working hard to balance economic growth with the need to protect the environment, and has set itself challenging targets for reducing greenhouse gas emissions, increasing energy efficiency and promoting renewable energy, and reducing waste. This has given rise to a wide range of green jobs – jobs which contribute to preserving the environment, or restoring it to what it was. If they are to be truly sustainable, though, we need to make sure that these jobs provide safe, healthy and decent working conditions. Green jobs need to be good for workers, as well as good for the environment.
',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 30,
    'source' => 'node/16',
    'alias' => 'articles/green-jobs-and-osh',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 16,
      'vid' => 16,
      'nid' => 16,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Green Jobs and OSH',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 16,
      'vid' => 16,
      'nid' => 16,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Green Jobs and OSH',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 16,
      'vid' => 16,
      'nid' => 16,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Green Jobs and OSH',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:22:23 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Tools and resources',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'b0c112cf-71c2-4902-a1d4-1b5dd6ad8b3a',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859172,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'f3fc72f9-56f7-4026-a707-9b45dccef67a',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p>OiRA and the online tools simplify the assessment and management of safety and health risks in the workplace. OSHwiki and our publications are rich sources of information on all aspects of OSH. And Napo is an OSH champion and makes everyone smile!</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>OiRA and the online tools simplify the assessment and management of safety and health risks in the workplace. OSHwiki and our publications are rich sources of information on all aspects of OSH. And Napo is an OSH champion and makes everyone smile!</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Tools and resources',
        'format' => NULL,
        'safe_value' => 'Tools and resources',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-04 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'Here you will find key resources for raising awareness and managing risks: OiRA, OSHwiki, Napo films and Napo for teachers, Publications and online tools.
',
        'format' => NULL,
        'safe_value' => 'Here you will find key resources for raising awareness and managing risks: OiRA, OSHwiki, Napo films and Napo for teachers, Publications and online tools.
',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 10,
    'source' => 'node/17',
    'alias' => 'articles/tools-and-resources',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 17,
      'vid' => 17,
      'nid' => 17,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Tools and resources',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 17,
      'vid' => 17,
      'nid' => 17,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Tools and resources',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 17,
      'vid' => 17,
      'nid' => 17,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Tools and resources',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:19:32 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Careers',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '311308b9-d339-4ddb-98b6-214551417744',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859305,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'f4afeb3b-6a7f-4e28-ac56-0d1b9746c5b3',
  'revision_uid' => 1,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<p class="Textfo"><span style="line-height: 1.538em;">Find out more about a career with the European Union at </span><a style="line-height: 1.538em;" href="http://europa.eu/epso/index_en.htm">the European Personnel Selection Office (EPSO) website</a><span style="line-height: 1.538em;">.</span></p><h1><span style="font-size: medium;">Who we employ</span></h1><p class="Textfo">Careers at EU-OSHA are open to nationals of the 28 European Union (EU) member states plus Iceland, Liechtenstein and Norway (parties of the EEA agreement).</p><p class="Textfo">EU-OSHA is an equal opportunities employer. We consider candidates for employment without distinction on the grounds of age, race, political, philosophical or religious conviction, gender or sexual orientation and regardless of disabilities, marital status or family situation.&nbsp;</p><h1 style="line-height: 20.0063037872314px;"><span style="font-size: medium;">Job vacancies</span></h1>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p class="Textfo"><span style="line-height: 1.538em;">Find out more about a career with the European Union at </span><a style="line-height: 1.538em;" href="http://europa.eu/epso/index_en.htm">the European Personnel Selection Office (EPSO) website</a><span style="line-height: 1.538em;">.</span></p>
<h1><span style="font-size: medium;">Who we employ</span></h1>
<p class="Textfo">Careers at EU-OSHA are open to nationals of the 28 European Union (EU) member states plus Iceland, Liechtenstein and Norway (parties of the EEA agreement).</p>
<p class="Textfo">EU-OSHA is an equal opportunities employer. We consider candidates for employment without distinction on the grounds of age, race, political, philosophical or religious conviction, gender or sexual orientation and regardless of disabilities, marital status or family situation. </p>
<h1 style="line-height: 20.0063037872314px;"><span style="font-size: medium;">Job vacancies</span></h1>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Careers',
        'format' => NULL,
        'safe_value' => 'Careers',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-16 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'At EU-OSHA, our staff enjoy a stimulating and multinational work environment. Our offices are located in the culturally vibrant city of Bilbao. There are all kinds of posts at EU-OSHA, but all our employees — from project managers to communications officers and administrators — have the skills, passion and enthusiasm we need to help us make Europe a safer, healthier and more productive place to work.',
        'format' => NULL,
        'safe_value' => 'At EU-OSHA, our staff enjoy a stimulating and multinational work environment. Our offices are located in the culturally vibrant city of Bilbao. There are all kinds of posts at EU-OSHA, but all our employees — from project managers to communications officers and administrators — have the skills, passion and enthusiasm we need to help us make Europe a safer, healthier and more productive place to work.',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(
    'en' => array(
      'en' => array(
        'en' => array(
          'en' => array(
            'title' => array(
              'value' => 'Jobs',
            ),
            'description' => array(
              'value' => 'All job vacancies at EU-OSHA',
            ),
          ),
        ),
      ),
    ),
  ),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => 'en',
    'data' => array(
      'en' => array(
        'entity_type' => 'node',
        'entity_id' => 18,
        'language' => 'en',
        'source' => '',
        'uid' => 1,
        'status' => 1,
        'translate' => 0,
        'created' => 1410876981,
        'changed' => 1410876981,
      ),
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 24,
    'source' => 'node/18',
    'alias' => 'articles/careers',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 21,
      'vid' => 18,
      'nid' => 18,
      'from_state' => 'draft',
      'state' => 'published',
      'uid' => 1,
      'stamp' => 1410876981,
      'published' => 1,
      'current' => 1,
      'title' => 'Careers',
      'timestamp' => 1410876981,
    ),
    'published' => array(
      'hid' => 21,
      'vid' => 18,
      'nid' => 18,
      'from_state' => 'draft',
      'state' => 'published',
      'uid' => 1,
      'stamp' => 1410876981,
      'published' => 1,
      'current' => 1,
      'title' => 'Careers',
      'timestamp' => 1410876981,
    ),
    'my_revision' => array(
      'hid' => 21,
      'vid' => 18,
      'nid' => 18,
      'from_state' => 'draft',
      'state' => 'published',
      'uid' => 1,
      'stamp' => 1410876981,
      'published' => 1,
      'current' => 1,
      'title' => 'Careers',
      'timestamp' => 1410876981,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:21:45 +0000',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Benefits of OSH and cost of poor OSH',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'e6618f05-2486-403d-9d03-b95992471f20',
  'type' => 'article',
  'language' => 'en',
  'created' => 1410859318,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'fd81ac64-3deb-4118-b4aa-b499e0e2e576',
  'revision_uid' => 0,
  'body' => array(
    'en' => array(
      0 => array(
        'value' => '<div class="wysiwyg_accordion"><h3>The big picture</h3><p class="Textfo">Everyone from individual workers to national health systems loses out when OSH is neglected. But this means that everyone can benefit from better policies and practices.</p><p class="Textfo">Countries with poor workplace safety and health systems use valuable resources dealing with avoidable injuries and illnesses. A strong national strategy leads to numerous benefits, such as:</p><ul><li>improved productivity through less sickness absence</li><li>cutting healthcare costs</li><li>keeping older workers in employment</li><li>stimulating more efficient working methods and technologies</li><li>reducing the number of people who have to cut their hours to care for a family member</li></ul><h3>Getting a clearer view</h3><p class="Textfo">It’s vital that policy-makers understand the costs of poor or non-existent OSH. Some are obvious — lost working days and compensation payments, for example. Some, though, are harder to estimate, such as the cost for human suffering. The economic effects on society of workplace accidents and work-related injuries can be hidden, like lower staff morale or lost clients and contracts.</p><p class="Textfo">Estimates vary — which is one reason why more research is needed — but typically, for most countries, the costs of accidents at work and occupational ill health range from 2.6% to 3.8% of GDP.</p><p class="Textfo">EU-OSHA wants policy-makers to have access to the most accurate figures possible. That’s why we have recently published <a href="/publications/reports/executive-summary-estimating-the-cost-of-accidents-and-ill-health-at-work">a report comparing the best national studies</a> on the costs of poor OSH. The report is the starting point for a large-scale project on estimating the costs of poor OSH across Europe.</p><h3>The benefits for business</h3><p class="Textfo">Not only does poor safety and health cost companies money, but good OSH pays dividends. Business with higher safety and health standards are more successful and more sustainable.</p><p class="Textfo">Studies estimate that for every euro invested in OSH, there is a return of 2.2 euros <a id="_anchor_1" name="_msoanchor_1" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/Already%20online/06-Benefits-of-OSH-SEP.docx#_msocom_1">[link to an external report that keeps on being moved - <span style="font-size: x-large;">SHALL WE SAVE IT IN OUR WEBSITE????</span></a><a id="_anchor_2" name="_msoanchor_2" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/Already%20online/06-Benefits-of-OSH-SEP.docx#_msocom_2">]</a>&nbsp;and that the cost–benefit ratio of improving safety and health is favourable</p><p class="Textfo">The costs of poor OSH can be a particular burden for small enterprises. Our recent report&nbsp;<a id="_anchor_1" style="line-height: 1.538em;" name="_msoanchor_1" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/Already%20online/06-Benefits-of-OSH-SEP.docx#_msocom_1">[STILL TO BE PUBLISHED</a><a id="_anchor_2" style="line-height: 1.538em;" name="_msoanchor_2" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/Already%20online/06-Benefits-of-OSH-SEP.docx#_msocom_2">]</a><span style="line-height: 1.538em;">&nbsp;</span><span style="line-height: 1.538em;">shows how good OSH can play a major role enhancing the performance of SMEs</span></p><p class="Textfo">The economic advantages of good OSH for businesses large and small are significant. To give just a few examples, good workplace safety and health:</p><ul><li>improves workers’ productivity</li><li>cuts down on absenteeism</li><li>reduces compensation payments</li><li>meets the requirements of public and private sector contractors</li></ul><p class="Textfo">Taking action could bring significant benefits to your business. Find out more about <a href="node/570">implementing improvements and managing risks</a>.</p><h3>Economic incentives</h3><p class="Textfo">Across Europe, schemes have been put in place to reward organisations financially for having safe and healthy workplaces. These include:</p><ul><li>lower insurance premiums</li><li>tax breaks</li><li>state subsidies and grants</li></ul><p class="Textfo">One example is the German butchery sector. Participating companies had their premiums reduced if they promoted safety, for example by buying safety knives or giving safety training to drivers. The scheme resulted in:</p><ul><li>1,000 fewer reportable accidents per year for the sector in Germany</li><li>a reduction in costs valued at 40&nbsp;million euros in six years</li><li>a saving of 4.81 euros for every euro invested</li></ul><p class="Textfo">For insurers, offering such schemes can help to reduce the number, severity and cost of claims.</p></div><p class="Textfo">Find out more about economic incentives and how they can be introduced:</p><ul><li><a href="https://osha.europa.eu/en/publications/literature_reviews/guide-economic-incentives/view?searchterm=">How to create economic incentives in occupational safety and health: A practical guide </a></li><li><a href="https://osha.europa.eu/en/publications/reports/economic_incentives_TE3109255ENC/view?searchterm=">Economic incentives to improve occupational safety and health: a review from the European perspective </a></li><li><a href="http://oshwiki.eu/wiki/External_economic_incentives_for_prevention">OSHwiki: economic incentives</a></li></ul><p><span style="font-size: x-large;"><strong>THE LAST PARAGRAPH SHOULD DISAPPEAR AS IT WILL BE DISPLAYED </strong></span></p><p><span style="font-size: x-large;"><strong>IN THE RIGHT HAND PORTLET, </strong></span></p><p><span style="font-size: x-large;"><strong>TO BE CONFIRMED BY PROJECT MANAGER</strong></span></p><p>&nbsp;</p><p><span style="font-size: x-large;"><strong>check link to OiRA (migrated content) &gt;&gt;&gt; for BM (or shall we rentranslate?)</strong></span></p><p>&nbsp;</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<div class="wysiwyg_accordion">
<h3>The big picture</h3>
<p class="Textfo">Everyone from individual workers to national health systems loses out when OSH is neglected. But this means that everyone can benefit from better policies and practices.</p>
<p class="Textfo">Countries with poor workplace safety and health systems use valuable resources dealing with avoidable injuries and illnesses. A strong national strategy leads to numerous benefits, such as:</p>
<ul><li>improved productivity through less sickness absence</li>
<li>cutting healthcare costs</li>
<li>keeping older workers in employment</li>
<li>stimulating more efficient working methods and technologies</li>
<li>reducing the number of people who have to cut their hours to care for a family member</li>
</ul><h3>Getting a clearer view</h3>
<p class="Textfo">It’s vital that policy-makers understand the costs of poor or non-existent OSH. Some are obvious — lost working days and compensation payments, for example. Some, though, are harder to estimate, such as the cost for human suffering. The economic effects on society of workplace accidents and work-related injuries can be hidden, like lower staff morale or lost clients and contracts.</p>
<p class="Textfo">Estimates vary — which is one reason why more research is needed — but typically, for most countries, the costs of accidents at work and occupational ill health range from 2.6% to 3.8% of GDP.</p>
<p class="Textfo">EU-OSHA wants policy-makers to have access to the most accurate figures possible. That’s why we have recently published <a href="/publications/reports/executive-summary-estimating-the-cost-of-accidents-and-ill-health-at-work">a report comparing the best national studies</a> on the costs of poor OSH. The report is the starting point for a large-scale project on estimating the costs of poor OSH across Europe.</p>
<h3>The benefits for business</h3>
<p class="Textfo">Not only does poor safety and health cost companies money, but good OSH pays dividends. Business with higher safety and health standards are more successful and more sustainable.</p>
<p class="Textfo">Studies estimate that for every euro invested in OSH, there is a return of 2.2 euros <a id="_anchor_1" name="_msoanchor_1" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/Already%20online/06-Benefits-of-OSH-SEP.docx#_msocom_1">[link to an external report that keeps on being moved - <span style="font-size: x-large;">SHALL WE SAVE IT IN OUR WEBSITE????</span></a><a id="_anchor_2" name="_msoanchor_2" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/Already%20online/06-Benefits-of-OSH-SEP.docx#_msocom_2">]</a> and that the cost–benefit ratio of improving safety and health is favourable</p>
<p class="Textfo">The costs of poor OSH can be a particular burden for small enterprises. Our recent report <a id="_anchor_1" style="line-height: 1.538em;" name="_msoanchor_1" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/Already%20online/06-Benefits-of-OSH-SEP.docx#_msocom_1">[STILL TO BE PUBLISHED</a><a id="_anchor_2" style="line-height: 1.538em;" name="_msoanchor_2" href="file:///I:/PROJECTS/Website%20%E2%80%93%20online%20communication/EU-OSHA%20online%20strategy%202013-2014/09%20-%20Content%20preparation/00%20-%20Final%20contents/Already%20online/06-Benefits-of-OSH-SEP.docx#_msocom_2">]</a><span style="line-height: 1.538em;"> </span><span style="line-height: 1.538em;">shows how good OSH can play a major role enhancing the performance of SMEs</span></p>
<p class="Textfo">The economic advantages of good OSH for businesses large and small are significant. To give just a few examples, good workplace safety and health:</p>
<ul><li>improves workers’ productivity</li>
<li>cuts down on absenteeism</li>
<li>reduces compensation payments</li>
<li>meets the requirements of public and private sector contractors</li>
</ul><p class="Textfo">Taking action could bring significant benefits to your business. Find out more about <a href="node/570">implementing improvements and managing risks</a>.</p>
<h3>Economic incentives</h3>
<p class="Textfo">Across Europe, schemes have been put in place to reward organisations financially for having safe and healthy workplaces. These include:</p>
<ul><li>lower insurance premiums</li>
<li>tax breaks</li>
<li>state subsidies and grants</li>
</ul><p class="Textfo">One example is the German butchery sector. Participating companies had their premiums reduced if they promoted safety, for example by buying safety knives or giving safety training to drivers. The scheme resulted in:</p>
<ul><li>1,000 fewer reportable accidents per year for the sector in Germany</li>
<li>a reduction in costs valued at 40 million euros in six years</li>
<li>a saving of 4.81 euros for every euro invested</li>
</ul><p class="Textfo">For insurers, offering such schemes can help to reduce the number, severity and cost of claims.</p>
</div>
<p class="Textfo">Find out more about economic incentives and how they can be introduced:</p>
<ul><li><a href="https://osha.europa.eu/en/publications/literature_reviews/guide-economic-incentives/view?searchterm=">How to create economic incentives in occupational safety and health: A practical guide </a></li>
<li><a href="https://osha.europa.eu/en/publications/reports/economic_incentives_TE3109255ENC/view?searchterm=">Economic incentives to improve occupational safety and health: a review from the European perspective </a></li>
<li><a href="http://oshwiki.eu/wiki/External_economic_incentives_for_prevention">OSHwiki: economic incentives</a></li>
</ul><p><span style="font-size: x-large;"><strong>THE LAST PARAGRAPH SHOULD DISAPPEAR AS IT WILL BE DISPLAYED </strong></span></p>
<p><span style="font-size: x-large;"><strong>IN THE RIGHT HAND PORTLET, </strong></span></p>
<p><span style="font-size: x-large;"><strong>TO BE CONFIRMED BY PROJECT MANAGER</strong></span></p>
<p> </p>
<p><span style="font-size: x-large;"><strong>check link to OiRA (migrated content) &gt;&gt;&gt; for BM (or shall we rentranslate?)</strong></span></p>
<p> </p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_tags' => array(),
  'field_image' => array(),
  'title_field' => array(
    'en' => array(
      0 => array(
        'value' => 'Benefits of OSH and cost of poor OSH',
        'format' => NULL,
        'safe_value' => 'Benefits of OSH and cost of poor OSH',
      ),
    ),
  ),
  'field_activity' => array(),
  'field_nace_codes' => array(),
  'field_publication_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-05 00:00:00',
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_related_oshwiki_articles' => array(),
  'field_summary' => array(
    'en' => array(
      0 => array(
        'value' => 'In tough economic times, it’s important to remember that poor workplace safety and health costs money. What’s more, case studies show that good OSH management in a business is linked to improved performance and profitability. ',
        'format' => NULL,
        'safe_value' => 'In tough economic times, it’s important to remember that poor workplace safety and health costs money. What’s more, case studies show that good OSH management in a business is linked to improved performance and profitability. ',
      ),
    ),
  ),
  'field_thesaurus' => array(),
  'field_workflow_status' => array(),
  'metatags' => array(),
  'rdf_mapping' => array(
    'field_image' => array(
      'predicates' => array(
        0 => 'og:image',
        1 => 'rdfs:seeAlso',
      ),
      'type' => 'rel',
    ),
    'field_tags' => array(
      'predicates' => array(
        0 => 'dc:subject',
      ),
      'type' => 'rel',
    ),
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'workbench_access' => array(),
  'path' => array(
    'pid' => 26,
    'source' => 'node/19',
    'alias' => 'articles/benefits-osh-and-cost-poor-osh',
    'language' => 'en',
  ),
  'workbench_moderation' => array(
    'current' => array(
      'hid' => 19,
      'vid' => 19,
      'nid' => 19,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Benefits of OSH and cost of poor OSH',
      'timestamp' => 1410874857,
    ),
    'published' => array(
      'hid' => 19,
      'vid' => 19,
      'nid' => 19,
      'from_state' => NULL,
      'state' => 'published',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Benefits of OSH and cost of poor OSH',
      'timestamp' => 1410874857,
    ),
    'my_revision' => array(
      'hid' => 19,
      'vid' => 19,
      'nid' => 19,
      'from_state' => 'draft',
      'state' => 'draft',
      'uid' => 0,
      'stamp' => 1410874857,
      'published' => 0,
      'current' => 1,
      'title' => 'Benefits of OSH and cost of poor OSH',
      'timestamp' => 1410874857,
    ),
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-09-16 09:21:58 +0000',
);
  return $nodes;
}
