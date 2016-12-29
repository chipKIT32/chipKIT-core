$('#markdown-toc > li a').hover(function() {
    $(this).parent().find('ul').toggle();
});
