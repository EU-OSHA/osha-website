@echo off

rem Setup a clean site in docroot/
cd docroot/

call drush build

echo "Registering migrations ..."
call drush migrate-auto-register

IF NOT "%1"=="--migrate" GOTO DONE

:MIGRATE
    rem echo "Importing Activity taxonomy"
    rem call drush migrate-import TaxonomyActivity

    echo "Importing NACE codes taxonomy"
    call drush migrate-import --update TaxonomyNaceCodes

    echo "Importing ESENER taxonomy"
    call drush migrate-import --update TaxonomyEsener

    echo "Importing Publication types taxonomy"
    call drush migrate-import --update TaxonomyPublicationTypes

    echo "Importing multilingual Thesaurus taxonomy"
    call drush migrate-import --update TaxonomyThesaurus

    echo "Importing Tags taxonomy"
    call drush migrate-import --update TaxonomyTags

    echo "Importing Files content"
    call drush migrate-import --update Files

    rem echo "Importing Images content"
    rem call drush migrate-import --update Images

    echo "Importing News content"
    call drush migrate-import --update News

    echo "Importing Highlight content"
    call drush migrate-import --update Highlight

    echo "Importing Publications content"
    call drush migrate-import --update Publication

    echo "Importing Articles content"
    call drush migrate-import --update Article

    echo "Importing Blog content"
    call drush migrate-import --update Blog

    echo "Importing Case Study content"
    call drush migrate-import --update CaseStudy

    echo "Importing Job vacancies content"
    call drush migrate-import JobVacancies

    echo "Importing Calls content"
    call drush migrate-import Calls
    
    echo "Importing PressRelease content"
    call drush migrate-import PressRelease

fi

:DONE
call drush cc all
cd ..
