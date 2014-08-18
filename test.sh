#!/bin/bash

# This script allows you to run OSHA related tests on your existing instance (created with install.sh, btw)
#
# Usage patterns
#    * run specific test method: ./test.sh ClassNameTest testFunctionName1,testFunctionName2
#    * run all tests from a class: ./test.sh ClassNameTest
#    * run all tests from specific group: ./test.sh OSHA
#    * run all tests from OSHA group: ./test.sh

uri=`drush php-script scripts/get_config_param.php uri | tr -d ' '`

cd docroot/

drush en -y simpletest > /dev/null 2>&1
drush dis -y apachesolr > /dev/null 2>&1

if [ "$1" == "" ]; then
	echo "Stand back! I'm running ALL the tests from group OSHA ..."
	drush test-run --uri=${uri} OSHA
else
	if [ "$2" != "" ]; then
		drush test-run --uri=${uri} $1 --methods=$2
	else
		drush test-run --uri=${uri} $1
	fi
fi
