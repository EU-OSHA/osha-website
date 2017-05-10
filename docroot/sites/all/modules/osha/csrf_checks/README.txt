=========================================================
Verifying Same Origin with Standard Headers
=========================================================

The module verifies all POST requests:

1. Origin Header
2. Referer Header

=========================================================
Checking the Origin Header
=========================================================

If the Origin Header is present, and it the same as $base_url, the check continues, otherwise the request is blocked.
It the Origin Header is not present, the check will continue with the Referer Header.

=========================================================
Checking the Referer Header
=========================================================

If the Referer Header is present, and it the same as $base_url, the check continues, otherwise the request is blocked.
It the Referer Header is not present, the request is blocked.


More info: https://www.owasp.org/index.php/Cross-Site_Request_Forgery_(CSRF)_Prevention_Cheat_Sheet#Verifying_Same_Origin_with_Standard_Headers
