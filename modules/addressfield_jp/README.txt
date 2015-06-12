Add Japanese postal code(postcode) check and address lookup to Address Field.
This module uses the ajaxzip3 library and only works for Japanese.

Requirements
============

Ctools - ctools - http://drupal.org/project/ctools
Address Field - addressfield - http://drupal.org/project/addressfield
ajaxzip3 - https://code.google.com/p/ajaxzip3

Usage
=====

- Install and enable module 'addressfield_jp' as usual.
- Create an addressfield on a entity or edit an existing one.
- Enable setting 'Postcode check and address lookup (JP add-on)' in the
  addresfield widget settings.
- Test your entity and enjoy!

### Locally ajaxzip3

If you want to load ajaxzip3 library on your server,
download them from google code and put into libraries directory.

Next, go to setting page "admin/config/people/addressfield-jp",
update library of "http" and "https" to local path.
For example,
"sites/all/libraries/ajaxzip3/ajaxzip3.js",
"sites/all/libraries/ajaxzip3/ajaxzip3-https.js".

### Enable 3-4 digit format

You can see checkbox 'Enable 3-4 digit format for Japanese postal code'
after enabled setting 'Postcode check and address lookup (JP add-on)'
in the addresfield widget settings. Postal code field form will be
extend as 2 form fields to support xxx-xxxx digit fromat when enabled.

Bugs
====

Please report bugs and issues on drupal.org in the issue queue:
http://drupal.org/project/issues/addressfield_jp

Remember to first search the issue queue and help others where you can!

Credits
=======

The module was built by everright in Ci&T (http://www.ciandt.com).
