#!/bin/bash

# Setup a clean site in docroot/
cd docroot/
drush site-install -y

# Save configuration to database for later usage
drush php-script ../scripts/drupal_pre_install.php

drush init
drush build

drush php-script ../scripts/drupal_post_install.php

if [ "$1" == "--migrate" ]; then

	echo "Registering migrations ..."
	drush migrate-auto-register

	echo "Importing NACE codes taxonomy"
	drush migrate-import TaxonomyNaceCodes

	echo "Importing ESENER taxonomy"
	drush migrate-import TaxonomyEsener

	echo "Importing Publication types taxonomy"
	drush migrate-import TaxonomyPublicationTypes

	echo "Importing multilingual Thesaurus taxonomy"
	drush migrate-import TaxonomyThesaurus

	echo "Importing Tags taxonomy"
	drush migrate-import TaxonomyTags

	echo "Importing News content"
	drush migrate-import News

	echo "Importing Publications content"
	drush migrate-import Publication
fi

drush cc all
