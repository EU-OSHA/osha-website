<?php

class MigrateOshaNews extends Migration {

  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('OSHA Content'));

    $import_root = $import_root = osha_migration_get_data_dir();
    $source_file = sprintf('%s/news/news.json', $import_root);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'unassigned' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->source = new MigrateSourceJSON($source_file, 'id', $this->fields());
    $this->destination = new MigrateDestinationNode('news');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'text');
    $this->addFieldMapping('body:summary', 'description');
    $this->addFieldMapping('field_news_tags', 'subject')->separator(',');
    $this->addFieldMapping('field_news_tags:create_term')->defaultValue(TRUE);

    $this->addFieldMapping('field_news_image', 'image_link');
    $this->addFieldMapping('field_news_image:alt')->defaultValue('Something');
    $this->addFieldMapping('field_news_image:title')->defaultValue('Title custom');
    $this->addFieldMapping('comment', NULL)->defaultValue(COMMENT_NODE_CLOSED);
  }

  protected function generateMachineName() {
    return 'News';
  }

  /**
   * @return array Fields present in the source file
   */
  function fields() {
    return array(
      "id" => "unique ID for each source row",
      "description" => "the summary of each news node",
      "text" => "the content of each news node",
      "title" => "the title of the news",
      "subject" => "news tags",
      "image_link" => "the link to the image"
    );
  }
}
