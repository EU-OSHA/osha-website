cd docroot

    echo "Importing Activity taxonomy"
    call drush migrate-import TaxonomyActivity

    echo "Importing NACE codes taxonomy"
    call drush migrate-import TaxonomyNaceCodes

    rem echo "Importing ESENER taxonomy"
    rem call drush migrate-import TaxonomyEsener

    echo "Importing Wiki articles"
    call drush migrate-import Wiki

    echo "Importing Publication types taxonomy"
    call drush migrate-import TaxonomyPublicationTypes

    echo "Importing multilingual Thesaurus taxonomy"
    call drush migrate-import TaxonomyThesaurus

    rem echo "Importing Tags taxonomy"
    rem call drush migrate-import TaxonomyTags

    echo "Importing Files content"
    call drush migrate-import Files

    rem echo "Importing Images content"
    rem call drush migrate-import Images

    echo "Importing News content"
    call drush migrate-import News

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

