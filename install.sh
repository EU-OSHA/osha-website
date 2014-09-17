#!/bin/bash

# Setup a clean site in docroot/
cd docroot/
drush site-install -y

# Save configuration to database for later usage
drush php-script ../scripts/drupal_pre_install.php

drush init
drush build

drush php-script ../scripts/drupal_post_install.php

echo "Registering migrations ..."
drush migrate-auto-register

if [ "$1" == "--migrate" ]; then

#    echo "Importing Activity taxonomy"
#    drush migrate-import TaxonomyActivity

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

    echo "Importing Job vacancies content"
    drush migrate-import JobVacancies

    echo "Importing Calls content"
    drush migrate-import Calls
    
    echo "Importing PressRelease content"
    drush migrate-import PressRelease
    

fi

drush cc all
