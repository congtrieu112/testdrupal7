jQuery(function($){
  /* env_channel */
  if(!Modernizr.touch){
     tc_vars['env_channel'] = 'd';
  }else if(Modernizr.touch && Foundation.utils.is_medium_up()){
     tc_vars['env_channel'] = 't';
  }else if(Modernizr.touch && Foundation.utils.is_small_only()){
     tc_vars['env_channel'] = 'm';
  }

  /* search_results_number && search_results_affichage */
  /* TODO : temporary because result are not the same depending of if we search a bien or a programme */
  var number_result = $('.results__list .results__list__heading .heading__title--sub').text();
  if(number_result == '') {
     if(window.location.pathname.indexOf("/recherche") != -1) {
         number_result = 0;
     }else{
         number_result = '';
     }
  }else{
    number_result = number_result.split(' ');
    number_result = number_result[0];
  }
  tc_vars['search_results_number'] = number_result;

  /* Type block */
  function addTypeBloc(element, css_class){
      var href = element.attr('href');
      if(href.indexOf('?') != -1){
          href = href + "&type_block=" + css_class;
      }else{
          href = href + "?type_block=" + css_class;
      }
      element.attr('href', href);
  }
  var bloc_generique_link = $('.contactUs-mini .contactUs__cta a');
  var bloc_votre_conseiller_link = $('#contact .contactUs__cta a');
  if(bloc_generique_link.length){
      bloc_generique_link.each(function(){
          addTypeBloc($(this), 'bloc_generique');
      });
  }
  if(bloc_votre_conseiller_link.length){
      bloc_votre_conseiller_link.each(function(){
          addTypeBloc($(this), 'bloc_votre_conseiller');
      });
  }

  /* Programme List */
  tc_vars.programme_list = [];
  $('.results__items>ul>li').each(function(index, value){
    var programme_list_data = $(this).data('tracking');
    tc_vars.programme_list.push(programme_list_data);
  });
});
