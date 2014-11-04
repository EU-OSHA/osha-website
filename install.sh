#!/bin/bash

# Setup a clean site in docroot/
cd docroot/
drush site-install -y

drush en -y search_api search_api_solr

# Save configuration to database for later usage
drush php-script ../scripts/drupal_pre_install.php

#drush --debug-modules init
drush init
drush build

drush php-script ../scripts/drupal_post_install.php

# Fix settings for OSHA in the media block (created in post_install)
drush fr osha_press_release.fe_block_settings -y --force

echo "Registering migrations ..."
drush migrate-auto-register

for var in "$@"
do
    if [ "$var" == "--content" ]; then

        echo "Installing osha_content and osha_taxonomies_uuid"
        drush en -y osha_taxonomies_uuid
        drush cc all
        drush en -y osha_content_edw
        drush en -y osha_content
        echo "Reverting osha_menu"
        drush fr osha_menu -y

    elif [ "$var" == "--migrate" ]; then

    #   echo "Importing Activity taxonomy"
    #   drush migrate-import TaxonomyActivity

        echo "Importing NACE codes taxonomy"
        drush migrate-import TaxonomyNaceCodes

    #   echo "Importing ESENER taxonomy"
    #   drush migrate-import TaxonomyEsener

    #   echo "Importing Publication types taxonomy"
    #   drush migrate-import TaxonomyPublicationTypes

    #   echo "Importing legislation category taxonomy"
    #   drush migrate-import TaxonomyLegislationCategories

        echo "Importing multilingual Thesaurus taxonomy"
        drush migrate-import TaxonomyThesaurus

    #   echo "Importing Tags taxonomy"
    #   drush migrate-import TaxonomyTags

        echo "Importing Wiki articles"
        drush migrate-import Wiki

        echo "Importing Files content"
        drush migrate-import Files

        #echo "Importing Images content"
        #drush migrate-import Images

        echo "Importing News content"
        drush migrate-import News

        echo "Importing Highlight content"
        drush migrate-import Highlight

        echo "Importing Publications content"
        drush migrate-import Publication

        echo "Importing Articles content"
        drush migrate-import Article

        echo "Importing Blog content"
        drush migrate-import Blog

        echo "Importing Case Study content"
        drush migrate-import CaseStudy

        echo "Importing Calls content"
        drush migrate-import Calls

        echo "Importing Notes to editors for press releases"
        drush migrate-import NoteToEditor

        echo "Importing PressRelease content"
        drush migrate-import PressRelease

        echo "Importing Seminar content"
        drush migrate-import Seminar

        echo "Importing Job vacancies content"
        drush migrate-import JobVacancies

        echo "Importing Calls content"
        drush migrate-import Calls

        echo "Importing PressRelease content"
        drush migrate-import PressRelease
    fi

done

drush cc all
