@echo off

rem Setup a clean site in docroot/
cd docroot/

call drush build

call drush cc all

cd ..
