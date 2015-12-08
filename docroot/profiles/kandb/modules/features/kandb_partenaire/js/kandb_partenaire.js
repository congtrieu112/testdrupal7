(function ($) {
  Drupal.behaviors.yourBehaviorName = {
    attach: function (context, settings) {
        inputSelectAllPrograms = $('#edit-field-partenaire-programmes');
        inputRadioAllPrograms = $('input[type=radio][name="field_partenaire_export[und]"]:last');
        inputSelectAllPrograms.hide();

        if (inputRadioAllPrograms.attr('checked')) {
            inputSelectAllPrograms.show();
        }

        $('input[type=radio][name="field_partenaire_export[und]"').change(function(){
            if($(this).attr("id") === inputRadioAllPrograms.attr("id")){
                inputSelectAllPrograms.show();
            } else {
                inputSelectAllPrograms.hide();
            }
        });
    }
  };
})(jQuery);
