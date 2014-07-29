#!/bin/bash

# Setup a clean site in docroot/
cd docroot/

drush build

if [ "$1" == "--migrate" ]; then

  echo "Registering migrations ..."
  drush migrate-auto-register

  echo "Updating NACE codes taxonomy"
  drush migrate-import NaceCodes --update

  echo "Updating ESENER taxonomy"
  drush migrate-import EsenerTaxonomy --update

  echo "Updating Publication types taxonomy"
  drush migrate-import PublicationTypesTaxonomy --update

  echo "Updating Multilingual Thesaurus taxonomy"
  drush migrate-import ThesaurusTaxonomy --update

  echo "Importing Categories taxonomy"
  drush migrate-import TagsTaxonomy

  echo "Importing News content"
  drush migrate-import NewsContent

fi

drush cc all
