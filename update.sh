#!/bin/bash

# Setup a clean site in docroot/
cd docroot/

drush build

drush cc all
