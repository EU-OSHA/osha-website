#!/bin/sh

# Setup a clean site in docroot/
cd docroot/
drush site-install -y

# Save configuration to database for later usage
drush php-script ../scripts/drupal_pre_install.php

drush init
drush build

drush php-script ../scripts/drupal_post_install.php

if [ "$1" != "--skip-migrations" ]; then

	echo "Registering migrations ..."
	drush migrate-auto-register

	echo "Importing NACE codes taxonomy"
	drush migrate-import NaceCodes

	echo "Importing ESENER taxonomy"
	drush migrate-import EsenerTaxonomy

	echo "Importing Publication types taxonomy"
	drush migrate-import PublicationTypesTaxonomy

	echo "Importing Multilingual Thesaurus taxonomy"
	drush migrate-import ThesaurusTaxonomy

	echo "Importing Categories taxonomy"
    drush migrate-import CategoriesTaxonomy

fi

drush cc all
