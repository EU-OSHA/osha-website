This module comes as an extension of pdf_to_imagefield and uses functions defined in pdf_to_imagefield module.
It makes us of PDF to Image widget and adds support for other types of files like .ppt, .doc

Installation:
- Apply the patch "pdf_to_imagefield-allow_non_pdf_file.patch" to pdf_to_imagefield module
- Make sure you have a converter installed (ex: OpenOffice "soffice")
- if using soffice make sure apache user has .config folder in it's home folder
- if using another converter, please see configuration interface of the module

If cannot convert file to pdf, check configuration interface of the module for more information


Q&A:
Q: When I save the node, I get this message: Could not convert @file to .pdf
A: Please go to module's configuration interface and manually check in terminal the shell command

Q: When I run the test line I get similar error to this: mkstemp("/var/www/.execoooMs34pw") failed: Permission denied
A: Apache user home is owned b


Server configuration:
sudo yum install libreoffice-base libreoffice-headless libreoffice-impress
sudo yum install ImageMagick