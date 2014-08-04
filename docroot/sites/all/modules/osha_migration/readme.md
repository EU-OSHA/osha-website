osha_migration
============

Scripts to migrate data from the old website.
This module is optional and can be safely enabled/disabled separately from other OSHA modules.

Notes:

1. This module is not automatically enabled by other build scripts.
2. This module relies on setting ```osha_data_dir``` Drupal global variable that points to your root data directory


Installation
============

* `drush vset osha_data_dir /path/to/data/directory` - Configure the data source directory where OSHA data is located
* `drush en -y migrate_ui osha_migration` - Enable the osha_migration module
* `drush migrate-import TaxonomyNaceCodes` - To run the NACE codes migration

