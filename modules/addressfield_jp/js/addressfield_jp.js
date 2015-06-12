/**
 * @file
 * JavaScript behaviors for the front-end display of Japanese postal code.
 */

(function ($) {

  "use strict";

  Drupal.behaviors.addressfield_jp = Drupal.behaviors.addressfield_jp || {};

  Drupal.behaviors.addressfield_jp.attach = function (context) {
    Drupal.addressfield_jp.ajaxzip(context);
  };

  Drupal.addressfield_jp = Drupal.addressfield_jp || {};

  Drupal.addressfield_jp.ajaxzip = function (context) {
    $('a.addressfield-jp-lookup').click(function (event) {
      event.preventDefault();
      var h;
      var $h;
      var pre;
      var g;
      var $g;
      var z;
      var $p = $(this).parents('.addressfield-jp-postcode:first');
      if ($(this).hasClass('addressfield-jp-lookup-34digit')) {
        $h = $p.find('.postal-code-prefix:first');
        $g = $p.find('.postal-code-suffix:first');
        h = $h.attr('name');
        g = $g.attr('name');
        z = $h.val() + '-' + $g.val();
        pre = h.substr(0, h.indexOf('[jp_postal_code]'));
      }
      else {
        $h = $p.find('.postal-code:first');
        h = $h.attr('name');
        g = '';
        z = $h.val();
        pre = h.substr(0, h.indexOf('[postal_code]'));
      }

      var k = pre + '[administrative_area]';
      var b = pre + '[locality]';
      var a = pre + '[thoroughfare]';
      var l = pre + '[premise]';
      var m = $p.prev('.addressfield_jp_postal_code_error');
      var exclude_codes = Drupal.settings.ajaxzip.exclude_codes;

      if (m.length > 0) {
        m.hide();
      }
      else {
        m = $('<div class="messages error addressfield_jp_postal_code_error"></div>');
        m.hide().html(Drupal.settings.ajaxzip.error_message).insertBefore($p);
      }

      var re = /^\d{3}(-)?\d{4}$/;
      if (!re.test(z) || exclude_codes.indexOf(z.substr(0, 3)) !== -1) {
        m.show();
        return false;
      }
      // Setting json data path if is set.
      if (Drupal.settings.ajaxzip.data && Drupal.settings.ajaxzip.data !== '') {
        AjaxZip3.JSONDATA = Drupal.settings.ajaxzip.data;
      }
      AjaxZip3.zip2addr(h, g, k, b, a, l, m);
      return false;
    });
  };

})(jQuery);
