Tweet Feed v3.0 - Overview
--------------------------
The Tweet Feed module is an advanced importing, displaying and data association module that allows you to pull in tweets by search, user, or list. The parameters of what is pulled in falls under the guidelines of [Twitter's REST API](https://dev.twitter.com/rest/public/rate-limiting)  

Tweets can be displayed as nodes or in views as well as displayed by hash tag or user mention. All hash tags and user mentions are stored as references im the tweet nodes to their corresponding taxonomy term. This gives you great power in terms of displaying tweets with specific content in specific places by leveraging the power of contextual filters and taxonomies.  

Additional documentation and example use cases can be found on the Help Pages after the module has been installed. For additional installation including some important information on uninstalling previous versions of Tweet Feed, please see the Installation section.  

Highlights include:  

* ability to import multiple tweet feeds
* tweets and tweet data are saved as nodes
* option to delete existing data when new tweets are imported
* option to import a node for each user in your tweet feed
* creates linked URLs from URLs, hash tags, and usernames inside the feed itself
* views integration
* contextual filters integration for views

This module exists thanks to the generous support of HighWire Press and Stanford University.

Contextual views inspiration and refinement compliments of Ashley Hall in conjunction with the development of the Symposiac conference platform, supported by the Institute for the Arts and Humanities and UNC.

** Dependencies **
* entityreference
* oauth
* date

There are other dependencies based on these.

* ctools
* date_api
* entity_api

** Highly Recommended **
* views
* views ui (only for setting up your views)

The following access tokens from Twitter are also required:

* API Key
* API Secret Key
* Access Token
* Access Token Secret
* Install

For complete documentation on this module, please visit the Tweet Feed module Wiki located at: 

https://github.com/ElusiveMind/tweet_feed/wiki