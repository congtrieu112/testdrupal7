// $('#edit-field-partenaire-programmes').hide();
// $('input[type=radio]#edit-field-partenaire-export-und-3').on( "click", function() {
//     $('#edit-field-partenaire-programmes').show();
// });
(function ($) {
  Drupal.behaviors.yourBehaviorName = {
    attach: function (context, settings) {
        inputSelectAllPrograms = $('#edit-field-partenaire-programmes');
        inputRadioAllPrograms = $('input[type=radio][name="field_partenaire_export[und]"]:last');

        inputSelectAllPrograms.hide();
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