@echo off

rem Go to docroot/
cd docroot/

call drush sql-drop -y

rem Sync from edw staging
call drush downsync_sql @osha.staging.sync @osha.local -y -v

rem Devify - development settings
call drush devify --yes
call drush devify_solr
call drush devify_ldap
rem Build the site
rem call drush osha_build -y
