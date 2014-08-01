This module comes as an extension of pdf_to_imagefield and uses functions defined in pdf_to_imagefield module.
It makes us of PDF to Image widget and adds support for other types of files like .ppt, .doc

Installation:
- Apply the patch "pdf_to_imagefield-allow_non_pdf_file.patch" to pdf_to_imagefield module
- Make sure you have a converter installed (ex: OpenOffice "soffice")
- if using soffice make sure apache user has .config folder in it's home folder
- if using another converter, please see configuration interface of the module

If cannot convert file to pdf, check configuration interface of the module for more information
