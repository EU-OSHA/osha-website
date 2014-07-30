This module comes as extension of pdf_to_imagefield and uses functions defined in the module.
It uses PDF to Image widget and other types of files like .ppt, .doc

Installation:
- Apply the patch "pdf_to_imagefield-allow_non_pdf_file.patch" to pdf_to_imagefield module
- Make sure to have OpenOffice "soffice" command installed

Issues:
    1. If cannot convert file to pdf:
        - Make sure apache user has .config folder in it's home folder