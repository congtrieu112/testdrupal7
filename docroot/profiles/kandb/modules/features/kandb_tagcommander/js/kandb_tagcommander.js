jQuery(function($){
    /* env_channel */
    if(!Modernizr.touch){
       tc_vars['env_channel'] = 'd';
    }else if(Modernizr.touch && Foundation.utils.is_medium_up()){
       tc_vars['env_channel'] = 't';
    }else if( Modernizr.touch && Foundation.utils.is_small_only()){
       tc_vars['env_channel'] = 'm';
    }

    /* search_results_number && search_results_affichage */
    /* TODO : temporary */
    var number_result = $('.results__list .results__list__heading .heading__title--sub').text();
    if(typeof(number_result) == undefined) {
        number_result = '';
    }
        tc_vars['search_results_number'] = number_result;
        tc_vars['search_results_affichage'] = number_result;
    }elseif(){
        tc_vars['search_results_number'] = number_result;
        tc_vars['search_results_affichage'] = number_result;
    }

});