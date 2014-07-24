#!/bin/sh

# This script allows you to run OSHA related tests on your existing instance (created with install.sh, btw)
#
# Usage patterns
#    * run specific test method: ./test.sh ClassNameTest testFunctionName1,testFunctionName2
#    * run all tests from a class: ./test.sh ClassNameTest
#    * run all tests from specific group: ./test.sh OSHA
#    * run all tests from OSHA group: ./test.sh

cd docroot/

drush en -y simpletest > /dev/null 2>&1
drush dis -y apache-solr > /dev/null 2>&1

if [ "$1" == "" ]; then
	echo "Stand back! I'm running ALL tests from the OSHA group ..."
	drush test-run OSHA
else
	if [ "$2" != "" ]; then
		drush test-run $1 --methods=$2
	else
		drush test-run $1
	fi
fi
