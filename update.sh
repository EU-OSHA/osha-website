#!/bin/bash

# Setup a clean site in docroot/
cd docroot/

drush build

echo "Registering migrations ..."
drush migrate-auto-register

if [ "$1" == "--migrate" ]; then

#    echo "Importing Activity taxonomy"
#    drush migrate-import TaxonomyActivity

    echo "Importing NACE codes taxonomy"
    drush migrate-import --update TaxonomyNaceCodes

    echo "Importing ESENER taxonomy"
    drush migrate-import --update TaxonomyEsener

    echo "Importing Publication types taxonomy"
    drush migrate-import --update TaxonomyPublicationTypes

    echo "Importing multilingual Thesaurus taxonomy"
    drush migrate-import --update TaxonomyThesaurus

    echo "Importing Tags taxonomy"
    drush migrate-import --update TaxonomyTags

    echo "Importing Files content"
    drush migrate-import --update Files

    #echo "Importing Images content"
    #drush migrate-import --update Images

    echo "Importing News content"
    drush migrate-import --update News

    echo "Importing Highlight content"
    drush migrate-import --update Highlight

    echo "Importing Publications content"
    drush migrate-import --update Publication

    echo "Importing Articles content"
    drush migrate-import --update Article

    echo "Importing Blog content"
    drush migrate-import --update Blog

    echo "Importing Case Study content"
    drush migrate-import --update CaseStudy

    echo "Importing Job vacancies content"
    drush migrate-import --update JobVacancies

    echo "Importing Calls content"
    drush migrate-import --update Calls
    
    echo "Importing PressRelease content"
    drush migrate-import --update PressRelease

fi

drush cc all
