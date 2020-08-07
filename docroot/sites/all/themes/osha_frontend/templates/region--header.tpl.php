<div id="socialNetworksBlue">
	<div id="icons">
		<a target="_blank" href="https://twitter.com/eu_osha"><img src="/sites/all/themes/osha_frontend/images/twitter-icon.png" alt="EU OSHA in Twitter" title="Twitter"></a>
		<a target="_blank" href="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork"><img src="/sites/all/themes/osha_frontend/images/facebook-icon.png" alt="EU OSHA Facebook Page" title="Facebook"></a>
		<a target="_blank" href="http://www.linkedin.com/company/european-agency-for-safety-and-health-at-work"><img src="/sites/all/themes/osha_frontend/images/linkedin-icon.png" alt="Follow EU OSHA in LinkedIn" title="LinkedIn"></a>
		<a target="_blank" href="https://www.youtube.com/user/EUOSHA"><img src="/sites/all/themes/osha_frontend/images/youtube-icon.png" alt="EU OSHA channel in Youtube" title="Youtube"></a>
		<a target="_blank" href="https://www.flickr.com/photos/euosha/albums"><img src="/sites/all/themes/osha_frontend/images/flickr-icon.png" alt="EU OSHA Flickr photos" title="Flickr"></a>
        <a target="_blank" href="https://www.slideshare.net/EUOSHA"><img src="/sites/all/themes/osha_frontend/images/footer-slideshare-new.png" alt="EU OSHA Slideshare " title="Slideshare"></a>
        <a href="<?php echo url('tools-and-resources/blog', array('alias' => TRUE)); ?>"><img src="/sites/all/themes/osha_frontend/images/blogger-icon.png" alt="EU OSHA Blog with more information in workplace safety and health" title="Blog"></a>
	</div>
</div>
<div id="languagesAndSearch">
	<div id="contact"><span class="a_small"><a title="<?php print t('Smaller text'); ?>" onclick="zoomSmall()">a</a></span><span class="a_medium"><a title="<?php print t('Optimised defaults'); ?>" onclick="zoomMedium()">a</a></span><span class="a_big"><a title="<?php print t('Bigger text'); ?>" onclick="zoomBig()">a</a></span><a href="#" onclick="if(window.print)window.print();" class="printfriendly" title="<?php print t('Print page'); ?>"><span class="glyphicon glyphicon-print"></span></a><?php print l(t('News & Events'), 'news-events') ?><?php print l(t('Press'), 'about-eu-osha/press-room') ?><!-- <?php print l(t('Contact us'), 'contact-us') ?>  --></div>
	<div>
		<img src="/sites/all/themes/osha_frontend/images/languageico.png" alt="Select language">
	</div>
</div>
<?php
global $language;
$url = "/" . $language->language . "/about-eu-osha/our-story";
?>

<div id="agencyLogo"><a title="<?php print t('EU-OSHA corporate website')?>" href="<?php echo url('<front>');?>"><img src="/sites/all/themes/osha_frontend/images/eu-osha-logo/EU-OSHA-<?php print (in_array($language->language, osha_enabled_language_list()))?$language->language:'en';?>.png" alt="<?php echo t('European Agency for Safety and Health at Work');?>"></a></div>
<div id="europeLogo"><img src="/sites/all/themes/osha_frontend/images/europeLogo.png" alt="Europe Flag"></div>
<?php print render($content); ?>
