<?php if ($logo): ?>
  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
<?php endif; ?>

<?php if ($site_name || $site_slogan): ?>
  <div class="header__name-and-slogan" id="name-and-slogan">
    <?php if ($site_name): ?>
      <h1 class="header__site-name" id="site-name">
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
      </h1>
    <?php endif; ?>

    <?php if ($site_slogan): ?>
      <div class="header__site-slogan" id="site-slogan"><?php print $site_slogan; ?></div>
    <?php endif; ?>
  </div>
<?php endif; ?>

<nav class="header__secondary-menu link_web_blog" id="secondary-menu" role="navigation">
  <?php print l(t('Go to EU-OSHA website'), ''); ?>
</nav>

<div id="socialNetworksBlue">
  <div id="icons">
    <a target="_blank" href="https://twitter.com/eu_osha"><img src="/sites/all/themes/osha_frontend/images/twitterTop.png" alt="Twitter"></a>
    <a target="_blank" href="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork"><img src="/sites/all/themes/osha_frontend/images/facebookTop.png" alt="Facebook"></a>
    <a target="_blank" href="http://www.linkedin.com/company/european-agency-for-safety-and-health-at-work"><img src="/sites/all/themes/osha_frontend/images/inTop.png" alt="In"></a>
    <a target="_blank" href="https://www.youtube.com/user/EUOSHA"><img src="/sites/all/themes/osha_frontend/images/youTubeTop.png" alt="YouTube"></a>
    <a href="<?php echo url('tools-and-resources/blog', array('alias' => TRUE)); ?>"><img src="/sites/all/themes/osha_frontend/images/bloggerTop.png" alt="Blogger"></a>
  </div>
</div>
<div id="blogLogo"><img src="/sites/all/themes/osha_frontend/images/logo-blog.png" alt="Blog"></div>
<div id="europeLogoBlog"><img src="/sites/all/themes/osha_frontend/images/europeLogo.png" alt="Europe Flag"></div>
<div id="agencyLogoBlog"><a href="<?php echo url('<front>');?>"><img src="/sites/all/themes/osha_frontend/images/eu-osha-logo/EU-OSHA-<?php global $language;print (in_array($language->language, osha_enabled_language_list()))?$language->language:'en';?>.png" alt="European Agency for Safety and Health at Work"></a></div>
