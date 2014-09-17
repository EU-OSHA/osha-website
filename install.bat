@echo off
rem Setup a clean site in docroot/
cd docroot/
call drush site-install -y

rem Save configuration to database for later usage
call drush php-script ../scripts/drupal_pre_install.php

call drush init
call drush build

call drush php-script ../scripts/drupal_post_install.php

echo "Registering migrations ..."
call drush migrate-auto-register

IF NOT "%1"=="--migrate" GOTO DONE

:MIGRATE
    rem echo "Importing Activity taxonomy"
    rem,call drush migrate-import TaxonomyActivity

    echo "Importing NACE codes taxonomy"
    call drush migrate-import TaxonomyNaceCodes

    echo "Importing ESENER taxonomy"
    call drush migrate-import TaxonomyEsener

    echo "Importing Publication types taxonomy"
    call drush migrate-import TaxonomyPublicationTypes

    echo "Importing multilingual Thesaurus taxonomy"
    call drush migrate-import TaxonomyThesaurus

    echo "Importing Tags taxonomy"
    call drush migrate-import TaxonomyTags

    echo "Importing Files content"
    call drush migrate-import Files

    rem echo "Importing Images content"
    rem call drush migrate-import Images

    echo "Importing News content"
    call drush migrate-import News

    echo "Importing Highlight content"
    call drush migrate-import Highlight

    echo "Importing Publications content"
    call drush migrate-import Publication

    echo "Importing Articles content"
    call drush migrate-import Article

    echo "Importing Blog content"
    call drush migrate-import Blog

    echo "Importing Case Study content"
    call drush migrate-import CaseStudy

    echo "Importing Job vacancies content"
    call drush migrate-import JobVacancies

    echo "Importing Calls content"
    call drush migrate-import Calls

    echo "Importing PressRelease content"
    call drush migrate-import PressRelease

:DONE
call drush cc all
cd ..
