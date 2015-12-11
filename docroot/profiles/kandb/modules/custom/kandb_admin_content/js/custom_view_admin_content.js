
jQuery(document).ready(function () {
    var field_id_programme = jQuery('#edit-field-id-programme-value-wrapper');
    var field_programme_target = jQuery('#edit-field-programme-target-id-wrapper');
    
    field_id_programme.remove();
    field_id_programme.insertAfter(jQuery("#edit-type-wrapper"));
    field_id_programme.hide();
    field_programme_target.attr('style', 'display:none');

    var field_select_type = jQuery("select#edit-type");
    var type_arr = ['bien', 'programme'];
    if (jQuery.inArray(field_select_type.val(), type_arr) != -1) {
        field_id_programme.show();
    }

    field_select_type.change(function () {
        var type = jQuery(this).val();
        if (jQuery.inArray(type, type_arr) != -1) {
            field_id_programme.show();
        } else {
            jQuery('[name=field_programme_target_id]').attr('value', '');
            jQuery('[name=field_id_programme_value]').attr('value', '');
            field_id_programme.hide();
            field_id_programme.find('input').attr('value', '');
        }
    });

    jQuery('#block-system-main').delegate('[name=field_id_programme_value]', 'keyup', function () {
        jQuery("[name=field_programme_target_id]").val(jQuery(this).val());
    });
});