
jQuery(document).ready(function () {
    var field_id_programme = jQuery("#edit-field-id-programme-value-wrapper");
    field_id_programme.remove();
    field_id_programme.insertAfter(jQuery("#edit-type-wrapper"));
    
    field_id_programme.hide();  

    var field_select_type = jQuery("select#edit-type");
    if(field_select_type.val() !== '' && field_select_type.val() === 'programme'){
        field_id_programme.show();
    }
    
    field_select_type.change(function () {
        var type = jQuery(this).val();
        if (type === 'programme') {
            field_id_programme.show();
        }else{
            field_id_programme.hide();
        }
    });
});