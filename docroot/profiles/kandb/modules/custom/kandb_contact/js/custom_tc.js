(function ($, Drupal) {
    Drupal.ajax.prototype.commands.tag_document_download = function (ajax, response, status) {
        console.log(response.page_name); // For debug tc_event_x().
        tc_events_1(this, 'PAGE', {'page_level': response.page_level, 'page_name': response.page_name});
    }
})(jQuery, Drupal);