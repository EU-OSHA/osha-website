EU-OSHA
====

Build scripts and source code for the OSHA project

[![Code Climate](https://codeclimate.com/github/EU-OSHA/osha-website/badges/gpa.svg)](https://codeclimate.com/github/EU-OSHA/osha-website)

### Definitions, acronyms and abbreviations

Term	| Description
--------|--------------------------------------------------
EU-OSHA	| European Agency for Safety and Health at Work
CdT	| Translation Centre for the Bodies of the European Union
FOP	| National Focal Point
NCW	| New Corporate Website
HWC	| Healthy Workplaces Campaign
CMW	| Content Management Workflow
HWC18| Healthy Workplaces Campaign (2018-2019)


## Organisation of repository
- ### Repository Layout
Breakdown for what each directory/file is used for. See also readme inside directories.
    
* [conf](https://github.com/EU-OSHA/osha-website/tree/master/conf)
* Project specific configuration files
* [docroot](https://github.com/EU-OSHA/osha-website/tree/master/docroot)
* Drupal root directory
* [drush](https://github.com/EU-OSHA/osha-website/tree/master/drush)
* Contains project specific drush commands, aliases, and configurations.
* [results](https://github.com/EU-OSHA/osha-website/tree/master/results)
* This directory is just used to export test results to. A good example of this<br/> is when running drush test-run with the --xml option. You can export the xml<br/> to this directory for parsing by external tools.
* [scripts](https://github.com/EU-OSHA/osha-website/tree/master/scripts)
* A directory for project-specific scripts.
* [test](https://github.com/EU-OSHA/osha-website/tree/master/tests)
* A directory for external tests. This is great for non drupal specific tests<br>such as selenium, qunit, casperjs.
* [.gitignore](https://github.com/EU-OSHA/osha-website/blob/master/.gitignore)
* Contains the a list of the most common excluded files.
* [modules/contrib](https://github.com/EU-OSHA/osha-website/tree/master/docroot/sites/all/modules/contrib)
* A directory for contributed modules.
* [modules/osha](https://github.com/EU-OSHA/osha-website/tree/master/docroot/sites/all/modules/osha)
* Project specific custom module
* [sites/all/themes/osha_admin](https://github.com/EU-OSHA/osha-website/tree/master/docroot/sites/all/themes/osha_admin)
* Project specific backend theme
* [sites/all/themes/osha_frontend](https://github.com/EU-OSHA/osha-website/tree/master/docroot/sites/all/themes/osha_frontend)
* Project specific frontend theme
     
- ### Custom modules

**All custom modules divided into 3 groups:**

#### Base modules

Name | Description
---------------------| --------------------------
osha_breadcrumbs | Breadcrumbs rules
osha_authentication | LDAP authentication support
osha_blocks | Content Blocks
osha_content | No Translation functionality
osha_menu | Main and Footer Menus
osha_migration | Migrate data from the old website  
osha_search | Search customizations
osha_sitemap | Sitemap for xmlsitemap
osha_sites_migration | Migrating content from other OSHA websites
osha_taxonomies | Project Specific Taxonomies
osha_workflow | Custom Workflow Moderation

#### Content types modules

Name | Description
--------------------- | ---------------------
osha | Article, DVS survey, Page, Twitter Tweet Feed, Twitter User Profile and Webform
osha_blog | Blog articles content type
osha_calls | Calls for contractors
osha_dangerous_substances | Dangerous substances
osha_eguide | eGuide
osha_events | Events
osha_flickr | Flickr gallery
osha_fop_page | Focal Point Page
osha_highlight | News
osha_homepage | Homepage banners
osha_infographics | Infographics
osha_job_vacancies | Job vacancies
osha_legislation | Directive and Guideline
osha_musculoskeletal_disorders | Musculoskeletal Disorders
osha_news | News
osha_newsletter | Newsletter article
osha_note_to_editor | Notes to editor
osha_press_contact | Press Contact
osha_press_release | Press Release
osha_publication | Publication
osha_resources | External URL, Internal files, Flickr photos, Slideshare Presentations and Youtube
osha_seminar | Seminar
osha_wiki | Wiki

#### Helper modules

Name | Description
------------ | -------------
csrf_checks | Cross-Site_Request_Forgery check
search_and_replace | Do Search and Replace on the content of nodes.
eu_captcha | Verifies if user is a human without necessity to solve a captcha
osh_image_gallery | Admin Image Gallery page
osha_admin_reports | Admin Excel Reports
osha_nodequeue | Allows automatic addition of nodes to the queue
osha_short_messages | Generate short messages from nodes
osha_unpublish | Unpublish old content
osha_contact | Extend Core Contact form
osha_lingua_tools | Lingua Tools
osha_alert_service | Alert Service

## Potentially reusable modules
It is possible to use modules from content type and helper groups in other projects.
     

## Technical strategy and chosen solutions

- ### General versioning and release approach

#### Branches

This repo branching model follows the article ["A successful Git branching model"](http://nvie.com/posts/a-successful-git-branching-model)

Summary:

* _develop_ - Main development branch. Tests are performed on this branch
* _release_ - Release branch.
* _master_ - The production branch, updated with each release.

#### Release and deployment:

Release and deployment follows the article ["Release and deployment policy"](https://github.com/EU-OSHA/osha-website/wiki)

Summary:

* We have 2 weeks based (first week staging deploy and second week production deploy) release model.
* New functionality will be added in develop branch.
* After testing develop branch will be merged into release branch using GitHub `Pull requests` and created new release using GitHub `Releases`
* In a week we merge release changes into master branch. The same GitHub `Pull requests` and GitHub `Releases`


- ### Translation Management Tools and Workflow

The Translation Management Tool provides a collection of tools for translating content(nodes), taxonomy terms, literals and menu links.

#### Basic steps of translation proccess:

Step|Description
----|------------
1| select content to be translated
2| add to cart
3| create translation job
4| download translation package (XML file)
5| [external] translation process by 'CDT'
6| upload XML file(s) containing translations
7| preview translation and validate layout for each job item
8| decide if content validation is necessary [optional]. If content validation is required, the list of content validators must be assigend to the job
9| [optional] review and validate translation for each job item
10| accept translation and update node 

* Workflow and Functional specifications [https://github.com/EU-OSHA/drupal.tmgmt/blob/master/docs/functional-specifications.pdf](https://github.com/EU-OSHA/drupal.tmgmt/blob/master/docs/functional-specifications.pdf)
* Module page - [https://www.drupal.org/project/tmgmt](https://www.drupal.org/project/tmgmt)
* FAQs: [https://www.drupal.org/node/1547632](https://www.drupal.org/node/1547632)

- ### Content management workflow
    In short, an editor can add information to the website, a reviewer can check it, and a project manager/administrator can publish it. 
    Each user has a work list with the items he/she has permissions for, and a filter to search for any piece of information.    

    There are six content statuses in the content management workflow: Draft, FinalDraft, ToBeReviewed, Rejected, ToBeApproved, Approved and ReadyToPublish. Each content status is detailed below.
    
    #### User roles involved in the 'Content Management' workflow.
    
    **Editor** 
    
    Users with the 'Editor' role will be allowed to:    
    * Initiate the publish process for a content.
    * Create new contents belonging to assigned section.
    * Edit and modify contents with 'Draft' state introduced by herself.
    * View (but not edit) all the content.
    * Create a content version and introduce comments.
    * Promote their contents to 'FinalDraft' state.

    **Review Manager (Web Team)**
    
    Users with the 'Review Manager' role will be allowed to:
    * Approve or reject contents before the PM performs the corresponding review.
    * Edit and modify contents, belonging to assigned section.
    * View the status of content during the whole review process.
    * Create a content version and introduce comments.
    * Define the steps included in the whole review process.
    * Specify the list of approvers for content.
    * Be notified in each change of status
    * Change the approvers of the workflow in any status
    * Change any status of the workflow
    
    **Project Manager**
    
    Users with the 'Project Manager' role will be allowed to:
    * Set the content state to 'ToBeApproved', if the content requires approval, 'Ready to publish', or to 'FinalDraft' to be redrafted again.
    * Create a content version and introduce comments. The Project Manager is in charge of a specific section (or several). S/he could only review the content related to that section or sections.
    * Be notified when content is approved or rejected by the approvers.
    * Decide if content is ready to publish or not.
    * View (but not edit) all the content.
    
    **Approver/Final Approver**
    
    Users with the 'Approver' role will be allowed to:
    * Create a content version and introduce comments, only with the contents that have been assigned to her/him.
    Users with the 'Final Approver' role will be allowed to:
    * Approve or reject contents, based on the comments received, only with the con-tents that have been assigned to her/him.
    
    **Administrator**
    
    Users with the 'Administrator' role will be allowed to any of the above plus:
    * Specify the list of possible approvers.
    * Change any status of the workflow
    * Change the people involved in the workflow in any status

#### Content review statuses:

Status	| Description
--------|------------
Draft	| Content with this status can be modified by its author (Editor), Review Manager user or by the Administrator. This is the initial status for each content introduced in the system, and the previous status to 'FinalDraft'.
FinalDraft	| The Editor in charge of the content, after modify it as considers, changes the status to 'FinalDraft'. The 'Review Manager' could then review it.
ToBeReviewed | Content with this status is ready to be reviewed by the Project Manager. Only the 'Review Manager' and the 'Administrator' have permissions to change the status of content to 'ToBeReviewed'.
ToBeApproved | Content with this status is ready to be reviewed by the Heads of Unit and/or the director, in the order specified by the Review Manager. As final step, the con-tent results 'Approved' or 'Rejected'.
Rejected | Rejected contents must be checked by the Project Manager. He/she decides if she can implement the required suggestions or if the changes must be implemented or reviewed by the Editor. In this case, the content status is set to 'FinalDraft', and the webteam liaises with the editor. <br/>Only the 'Final Approver' has permission to change the status of content to 'Rejected'.
Approved | The contents with 'Approved' status are ready to be reviewed by the Project Manager again. The PM decides if the content can go on the workflow (in this case the state of the content is 'Ready-ToPublish'). <br/>Only the 'Final Approver' and the 'Administrator' have permission to change the status of content to 'Approved'.
ReadytoPublish | The contents with 'ReadytoPublish' state can be published. Only the 'Project Manager' and the 'Administrator' have permission to change the state of contents to 'ReadytoPublish'. Then the contents can be published or translated. This decision falls on the Web Team.

#### Workflow

In the first diagram below the general content management workflow is shown.There are several steps that could be skipped, as it is reflected in the workflow.
<br/>The second diagram contains the detailed and complete content management workflow, including the content statuses and participant actors.

![Simple Content Management Workflow](https://eu-osha.github.io/docs/images/CMF-1.png)
**Figure 1 - Simple Content Management Workflow**
     
![Detailed Content Management Workflow](https://eu-osha.github.io/docs/images/CMF-2.png)
**Figure 2 - Detailed Content Management Workflow**

#### Brief steps description

Step	| Role	| Description
--------|-------|-------------
1|Editor|Introduces a new content in the website. The status of the content is 'Draft'.
2|Editor|Edit the content and modifies it (optional).
3|Editor|Set the status of the content to 'Final Draft'. From this moment she/he can-not modify it until the content is in 'Draft' status again.
4|Review Manager<br/>(Web Team)|Reviews the introduced content. She/he can:<br/> Accept the content. The workflow carries on step 5.<br/> Reject the content. Thus, the status of the content is set to 'Draft'.<br/>The workflow remains step 2.<br/>In both cases, comments about the content can be introduced and a new version generated.
5|Review Manager<br/>(Web Team)|The user define:<br/><br/>&nbsp;The final list of reviewers for the content. The system proposes a default list of reviewers and the user could select all of them, or change any of them (adding or deleting) and the proposed order.<br/><br/>If the review process is needed or not. In a positive case the content status is set to 'ToBeReviewed' and the workflow goes on step 6. A notification is sent to the PM.<br/><br/>Establish the PM in charge of the review process. The system proposes the responsible of that content as PM, by default. The Review Manager can change it.<br/><br/>If the approval process is needed or not. In a positive case the workflow remains on step 8. 
6|Project Manager|Views and edits the content.<br/>PM introduces comments (optional).
7|Project Manager|Validates the content:<br/><br/>&nbsp;If the content is approved and the approval process is going to take place, the status is set to 'ToBeApproved'. A notification is sent to the next re-viewer (Approver I) and the workflow goes on step 8.<br/><br/>If the content is approved but the approval process is not going to take place, the workflow goes on step 10.<br/><br/>If the content is not approved, the status is set to 'Final Draft' and the workflow remains on step 4.
8|Approver|Views and edits the content. He/she introduces comments and generates a new version of the content.<br/>This step is repeated as many times as approvers have been defined by the Review Manager until the last one, who is in charge of the final validation of the content.
9|Last Approver|Views and edits the content. He/she introduces comments and generates a new version of the content.<br/>The user validates the content:<br/><br/>If the content is validated, the status is set to 'Approved' and the workflows remains with step 10 <br/><br/>If the content is not validated, the status is set to 'Rejected' and the work-flows goes on step 6. <br/><br/>In both cases a notification is send to the 'PM'.
10|Project Manager|The approvers may request some changes or corrections, that is why the PM has to re-approve the contents. <br/>If the PM considers the content can remain with the workflow she/he sets the status to 'ReadyToPublish' and the workflow goes on step 11.<br/>If the PM rejects the content, the workflow goes back to step 4.
11|Web Team|The Web Team decides if the content is published or translated
    
### Our solutions and specific practices
 
* #### Making patches to Drupal core and 3rd party modules
    * Patches used in project to fix errors found in Drupal core or 3rd party modules.
    * Patches can be created manually using _git diff_ command `````git diff filenames > patch.name````` or found on module issue page
    * Each patch should be copied in `patches/module_name` folder
    * Before updating module require to check if module patched. After updating module require to check if patch still required. 
    * To apply patch after module update require to run ```patch -p1 < ../patches/module/file.patch``` 
    * If module patch failed to apply require to merge manually and check if for compatibility.      

* #### Updating custom modules
    * Content type module uses features module to make possible automated import and export of configuration.
    * Any configuration changes related to module updating in module `module_name_update_70XX` hook using `features_revert` or `features_revert_module` functions   

### Data exchange with other websites

#### Export content:

Content type / Terms | Destination
-------| -------------
Wiki page | OiRA 
News | OiRA
Dangerous substances | HWC
Gallery | HWC
Press release, Publication | HWC 
Events | HWC
Infographic | HWC 
News | HWC
Note to editor | HWC
Contacts | HWC
Press release | HWC
Dangerous substances related terms | HWC 

#### Import content:

Source | Content type
-----| -----
HWC | News
HWC | Events
OiRA | News
OSHwiki | Wiki page

### How to set-up a development and a staging environment

#### Pre-requisites
    
1. Install Drush (7.0-dev):

   * Install composer (```curl -sS https://getcomposer.org/installer | php```) somwhere in the PATH, and rename ```composer.phar``` to ```composer```.
   * Clone drush repo in your working directory (i.e. ~/Work) - ```git clone git@github.com:drush-ops/drush.git ~/Work/drush```)
   * ```cd ~/Work/drush```
   * ```composer install``` - install drush w/composer
   * ```sudo ln -s ~/Work/drush/drush /usr/bin/``` - add to PATH

2. Virtual host for your Drupal instance that points to the docroot/ directory from this repo
    
#### Quick start
    
1. Copy [conf/config.template.json](https://github.com/EU-OSHA/osha-website/blob/master/conf/config.template.json)
to `config.json` and customize to suit your environment

    ```json
    {
        "db" : {
            "host": "database server ip or name, ex: localhost",
            "username" : "database username, ex. user1",
            "password" : "database password, ex. password1",
            "port": 3306,
            "database" : "database name, ex. osha_test",
            "root_username": "root",
            "root_password": "s3cr3t"
        },
        "admin" : {
            "username": "admin",
            "password": "admin",
            "email": "your.email@domain.org"
        },
        "uri": "http://you-vh.localhost",
        "solr_server": {
            "name": "Apache Solr server",
            "enabled": 1,
            "description": "",
            "scheme": "http",
            "host": "localhost",
            "port": 8080,
            "path": "/solr",
            "http_user": "",
            "http_password": "",
            "excerpt": 1,
            "retrieve_data": 1,
            "highlight_data": 1,
            "skip_schema_check": null,
            "solr_version": "",
            "http_method": "AUTO",
            "apachesolr_read_only": null,
            "apachesolr_direct_commit": 1,
            "apachesolr_soft_commit": 1
        },
        "variables": {
            "site_mail": "your.email@domain.org",
            "site_name": "OSHA",
            "osha_data_dir": "/home/osha/data",
            "file_temporary_path": "/tmp"
        }
    }
    ```

2. Copy the following code into `~/.drush/drushrc.php` (create if necessary)

    ```php
        <?php
            $repo_dir = drush_get_option('root') ? drush_get_option('root') : getcwd();
            $success = drush_shell_exec('cd %s && git rev-parse --show-toplevel 2> ' . drush_bit_bucket(), $repo_dir);
            if ($success) {
                $output = drush_shell_exec_output();
                $repo = $output[0];
                $options['config'] = $repo . '/drush/drushrc.php';
                $options['include'] = $repo . '/drush/commands';
                $options['alias-path'] = $repo . '/drush/aliases';
            }
    ```

3. Create file drush/aliases/aliases.local.php and define your drush local alias (see example in drush/aliases/osha.aliases.drushrc.php)
  Redefine your osha.staging.sync alias as you need. Default one might not be accessible to you.

4. Run install_from_staging.sh
    
#### Updating an existing instance
    
To update an existing instance without reinstalling (and loosing existing content):
- Update the code repository from Github (`git pull [origin develop]`)
- Run `drush updb -y` which reverts all features in module updates
        
#### Running tests
    
You can use the test.sh script to launch the set of tests designed for the OSHA project.
    
Command usage:
    
- `./test.sh` - Runs all tests from the OSHA group
- `./test.sh ClassNameTest` - Runs all the test methods from the ClassNameTest test class
- `./test.sh ClassNameTest testName1,testName2` - Runs only the two tests from the entire class
