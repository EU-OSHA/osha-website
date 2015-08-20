<?php

$site = $_GET['site'];
$urlparts = parse_url($site);
if ($urlparts["scheme"] == "file") {
	exit;
}
$s = curl_init();
curl_setopt($s, CURLOPT_URL, $site);
curl_setopt($s, CURLOPT_RETURNTRANSFER, TRUE);
print curl_exec($s);
