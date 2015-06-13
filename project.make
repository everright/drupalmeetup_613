api = 2
core = 7.x

; Drupal core.
projects[drupal][type] = core
projects[drupal][version] = 7.37
; Drush make allows a default sub directory for all contributed projects.
defaults[projects][subdir] = contrib
; Devel Modules
projects[devel][subdir] = devel
projects[devel][version] = "1.5"
projects[devel_themer][subdir] = devel
projects[devel_themer][version] = "1.x-dev"
projects[simplehtmldom][subdir] = "devel"
projects[simplehtmldom][version] = "2.1"
projects[drupalforfirebug][subdir] = devel
projects[drupalforfirebug][version] = "1.4"
projects[xhprof][subdir] = devel
projects[xhprof][version] = "1.0-beta3"
; Admin modules
projects[admin_menu][version] = "3.0-rc4"
projects[admin_views][version] = "1.3"
projects[module_filter][version] = "2.0"
; Commonly used modules
projects[ctools][version] = "1.7"
projects[context][version] = "3.6"
projects[panels][version] = "3.5"
projects[token][version] = "1.6"
projects[views][version] = "3.10"
projects[rules][version] = "2.9"
projects[date][version] = "2.8"
projects[libraries][version] = "2.2"
projects[uuid][version] = "1.0-alpha6"
projects[variable][version] = "2.5"
projects[pathauto][version] = "1.2"
projects[entity][version] = "1.6"
projects[entityreference][version] = "1.1"
projects[entitycache][version] = "1.2"
; SEO modules
projects[page_title][version] = "2.7"
projects[metatag][version] = "1.4"
projects[xmlsitemap][version] = "2.2"
;projects[seotools][version] = "1.0-alpha6"
projects[google_analytics][version] = "2.1"
; This project related modules
projects[addressfield][version] = "1.0-beta5"
projects[i18n][version] = "1.12"
projects[l10n_update][version] = "2.0"
projects[permission_select][version] = "1.2"
projects[jquery_update][version] = "2.5"
projects[admin_menu_source][version] = "1.0"
projects[role_theme_switcher][version] = "1.1"
projects[ife][version] = "2.0-alpha2"
projects[memcache_storage][version] = "1.4"
projects[memcache_status][version] = "1.2"
projects[seckit][version] = "1.9"
projects[security_review][version] = "1.2"

;This project related patch
projects[date][patch][] = "https://www.drupal.org/files/issues/date-default-value-2074457-3.patch"
projects[i18n][patch][] = "https://www.drupal.org/files/issues/i18n-php_notice_i18n_taxonomy-206327-10-D7.patch"

;Memcache status library
;libraries[memcache][download][type]= "get"
;libraries[memcache][download][url] = "http://git.php.net/?p=pecl/caching/memcache.git;a=blob_plain;f=memcache.php;hb=HEAD"
;libraries[memcache][download][filename] = "memcache.php.inc"
;libraries[memcache][directory_name] = "memcache"

