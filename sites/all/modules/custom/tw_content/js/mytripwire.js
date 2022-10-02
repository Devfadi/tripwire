jQuery(document).ready(function($) {
    if ( typeof Drupal.settings.tw_content.mtw.author !== 'undefined') {
        var publishers = Drupal.settings.tw_content.mtw.author.join(", ");
        $('.las').parent().parent().find('h2').append(' (<span class="tags">' + publishers + '</span>)');
    }
    
    if ( typeof Drupal.settings.tw_content.mtw.fed_region !== 'undefined') {
        var fedregion = Drupal.settings.tw_content.mtw.fed_region.join(", ");
        $('.lasfed').parent().parent().find('h2').append(' (<span class="tags">' + fedregion + '</span>)');
        $('.view-my-tripwire-page .view-header').append(' (<span class="tags">' + fedregion + '</span>)');
    }
    

    if ( typeof Drupal.settings.tw_content.mtw.subject !== 'undefined') {
        var subjects = Drupal.settings.tw_content.mtw.subject.join(", ");
        $('.swts').parent().parent().find('h2').append(' (<span class="tags">' + subjects + '</span>)');
    }
    

    $('.view-my-tripwire-page').matchHeight({
        target: $('body.page-mytripwire #sidebar-second')
    });
});