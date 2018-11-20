window.scroll({
    top: 0,
    left: 0
});

(function ($) {
$( document ).ready(function() {
    $('.block-region-center .views-row').each(function () {
        $(this).find('.big-number-chart, .elab, .link, .progress-graph').each(function (index, element) {
            $(this).data('delay', index * 200);
        });
    });

    $('.line-chart').each(function () {
        if ($(this).find('.line-chart-progress').length == 0) {
            $(this).prepend('<span class="line-chart-progress" style="width:0%">&nbsp;</span>');
        }
    });

    $('.postCenter').each(function (i) {
        $(this).addClass("hiddenClass").data('delay', i * 500);
    });

    window.myDoughnut = [];
    $('.progress-graph').each(function (index, element) {
        var progress = $(this).data('progress');

        Chart.pluginService.register({
            beforeDraw: function (chart) {
                if (chart.config.options.elements.center) {
                    //Get ctx from string
                    var ctx = chart.chart.ctx;

                    //Get options from the center object in options
                    var centerConfig = chart.config.options.elements.center;
                    var fontStyle = centerConfig.fontStyle || 'Arial';
                    var fontStyle = 'Open Sans';
                    var txt = centerConfig.text;
                    var color = centerConfig.color || '#000';
                    var sidePadding = centerConfig.sidePadding || 20;
                    var sidePaddingCalculated = (sidePadding / 100) * (chart.innerRadius * 2)
                    //Start with a base font of 30px
                    //ctx.font = "30px " + fontStyle;

                    //Get the width of the string and also the width of the element minus 10 to give it 5px side padding
                    var stringWidth = ctx.measureText(txt).width;
                    var elementWidth = (chart.innerRadius * 2) - sidePaddingCalculated;

                    // Find out how much the font can grow in width.
                    var widthRatio = elementWidth / stringWidth;
                    var newFontSize = Math.floor(30 * widthRatio);
                    var elementHeight = (chart.innerRadius * 2);

                    // Pick a new font size so it will not be larger than the height of label.
                    var fontSizeToUse = Math.min(newFontSize, elementHeight);

                    //Set font settings to draw it correctly.
                    ctx.textAlign = 'center';
                    ctx.textBaseline = 'middle';
                    var centerX = ((chart.chartArea.left + chart.chartArea.right) / 2);
                    var centerY = ((chart.chartArea.top + chart.chartArea.bottom) / 2);
                    ctx.font = "100 30px " + fontStyle;
                    ctx.fillStyle = color;

                    //Draw text in center
                    ctx.fillText(txt, centerX, centerY);
                }
            }
        });

        var config = {
            type: 'doughnut',
            data: {
                datasets: [{
                        data: [0, 100],
                        backgroundColor: ['#FFFFFF', '#062B60'],
                        hoverBorderColor: 'rgba(0, 0, 0, 0.1)',
                        borderColor: 'rgba(0, 0, 0, 0)',
                        label: 'Dataset 1'
                    }]
            },
            options: {
                responsive: true,
                cutoutPercentage: 85,
                maintainAspectRatio: false,
                legend: {display: false},
                tooltips: {enabled: false},
                title: {display: false},
                animation: {
                    animateScale: false,
                    animateRotate: true,
                }
            }
        };

        $(this).html('<canvas class="chart-area"></canvas>');
        $(this).append('<span class="number">' + progress + '%</span>');
        $(this).find('canvas').data('progress', progress);
        var ctx = $(this).find('canvas');
        window.myDoughnut[index] = new Chart(ctx, config);
    });

    $('.big-list li').not('.elab').wrapInner('<span>').addClass('elab');

    $('.close-icon').click(function (event) {
        $('.center-region').removeClass('visible');
        $('#infogrphics').removeClass('expanded');
        $('.views-row').removeClass('active');
    });

    $('#infogrphics .click-region .views-row *,#infogrphics  .click-region .views-row').click(function (event) {
        event.preventDefault();
        event.stopPropagation();
        var id = $(this).data('id');
        var infografica = $('#infogrphics');
        var blocco = $('#infogrphics  .block-region-center .nid-' + id);
        var bloccoEetichette = $('#infogrphics  .block-region-center .nid-' + id);

        if (id == undefined) {
            var id = $(this).parents('.views-row').data('id');
        }

        if (!$('#infogrphics  .block-region-center .nid-' + id).is('.active')) {
            $('#infogrphics').addClass('expanded');
            $('#infogrphics  .views-row').removeClass('active');
            $('#infogrphics  .nid-' + id).addClass('active');

            $('#infogrphics  .center-region').addClass('visible');

            if ($('#infogrphics .center-region .nid-' + id).find('.line-chart').length > 0) {
                $('#infogrphics .center-region .nid-' + id + ' .line-chart').each(function () {
                    var prec = $(this).find('.number').html();
                    $(this).find('.line-chart-progress').css({width: prec + '%'});
                });
            } else {
                $('.line-chart-progress').css({width: '0%'});
            }

            if ($('#infogrphics .center-region .nid-' + id).find('.progress-graph').length > 0) {
                $('#infogrphics .center-region .nid-' + id + ' .progress-graph').each(function (index, element) {
                    var progresss = $(this).data('progress');
                    var data = [progresss, (100 - progresss)];
                    var del = $(this).data('delay');

                    window.myDoughnut[index].config.data.datasets[0].data = data;

                    //console.log(del);
                    $(this).delay(del).queue(function () {
                        window.myDoughnut[index].update();
                        //console.log(index);
                        $(this).dequeue();
                    });
                });
            } else {
                $('#infogrphics .center-region .progress-graph').each(function (index, element) {
                    window.myDoughnut[index].config.data.datasets[0].data = [0, 100];
                    window.myDoughnut[index].update();
                });
            }

            if ($('#infogrphics .center-region .nid-' + id).find('.big-number-chart, .elab, .link').length > 0) {
                $('#infogrphics .center-region .nid-' + id).find('.big-number-chart, .elab, .link').each(function (index, element) {
                    var del = $(this).data('delay');

                    $(this).delay(del).queue(function () {
                        $(this).addClass('in');
                    });
                });
            }
        }
    });


    $('#infogrphics2 .content-region .views-row').fadeOut(0);
    $('#infogrphics2 .click-region .views-row').on('click', function (e) {
        e.preventDefault();
        e.stopPropagation();

        var id = $(this).data('id');

        $('.active').removeClass('active');
        $(this).addClass('active');

        $('#infogrphics2 .content-region .views-row').animate({height: "hide"}, 500);
        $('#infogrphics2 .content-region .nid-' + id).animate({height: "show"}, 500);
    });

    var aud = document.getElementById("intro-video");
    aud.onended = function () {
        $('#close-overlay').addClass('show');
    };


    $('#close-overlay').click(function () {
        $('#overlay').addClass('hide').delay(1000).queue(function () {
            $('#overlay').remove();
            $('body').addClass('unlock');
        })
    });


    /**************************************/


    window.addEventListener("orientationchange", function () {
        if ($(window).width() < 992) {
            $('#discaimer').addClass('visible');
            $('body').removeClass('unlock');
        } else {
            $('#discaimer').removeClass('unlock');
            $('body').addClass('unlock');
        }
    }, false);


    window.addEventListener("resize", function () {
        if ($(window).width() < 992) {
            $('#discaimer').addClass('visible');
            $('body').removeClass('unlock');
            window.scroll({
                top: 0,
                left: 0
            });
        } else {
            $('#discaimer').removeClass('visible');
            $('body').addClass('unlock');
        }
    }, false);

    if ($(window).width() < 992) {
        $('#discaimer').addClass('visible');
    }

});
})(jQuery);