/**
 * @file
 *
 * Pagerer jquery scripts.
 *
 * All jQuery navigation widgets implemented by pagerer are configured at
 * runtime by a JSON object prepared by the PHP part of the module, and
 * stored in a 'pagererState' object attached to each widget.
 *
 * pagererState properties:
 * - path: drupal *request* path inclusive of querystring fragment, no base
 *   path
 * - element: integer to distinguish between multiple pagers on one page
 * - quantity: number of page elements in the pager list
 * - total: total number of pages in the query
 * - totalItems: total number of items in the query
 * - current: 0-base index of current page
 * - interval: number of elements per page (1 if display = pages, items per
 *   page if display = items/item_ranges)
 * - display: pages|items|item_ranges indicates what is displayed in the page
 *   element
 * - pagerSeparator: Text to fill between contiguous pages.
 * - rangeSeparator: Text to place between first and last item in a range.
 * - pageTag: Text to use to render the target page/item/item range.
 * - widgetResize: (widget) determines if the widget width should be calculated
 *   dynamically based on the width of the string of the last page/item number.
 * - action: (slider) determines how the page relocation should be triggered
 *   after it has been selected through the jQuery slider.
 * - timelapse: (slider) the grace time (in milliseconds) to wait before the
 *   page is relocated, in case "timelapse" action method is selected for
 *   the jQuery slider.
 * - icons: (slider) determines whether to display +/- navigation icons
 *   on the sides of the jQuery slider.
 * - tickmarkTitle: (slider) help text appended to the slider help when user is
 *   expected to click on the tickmark to start page relocation.
 * - pageTitle: (scrollpane) Help text used when hovering a page link.
 * - firstTitle: (scrollpane) Help text used when hovering a first page link.
 * - lastTitle: (scrollpane) Help text used when hovering a last page link.
 */

(function ($) {
Drupal.behaviors.pagerer = {
  attach: function(context, settings) {

    /**
     * Constants.
     */
    var PAGERER_LEFT = -1;
    var PAGERER_RIGHT = 1;

    /**
     * State variables.
     *
     * These variables are reset at every page load, either normal or AJAX.
     */
    var state = {
      timeoutAction: 0,
      intervalAction: 0,
      intervalCount: 0,
      isRelocating: false
    };

     /**
     * 'pagerer-page' input box event binding
     */
    $('.pagerer-page', context)
    .ready().each(function(index) {
      state.isRelocating = false;
      this.pagererState = pagererEvalState($(this).attr('name'));
      // Item ranges do not really work on widget.
      if (this.pagererState.display === 'item_ranges') {
        this.pagererState.display = 'items';
      }
      // Adjust width of the input box.
      if (this.pagererState.widgetResize) {
        $(this).width(String(indexToValue(this.pagererState.total - 1, this.pagererState)).length + 'em');
      }
    })
    .bind('focus', function(event) {
      pagererReset();
      this.select();
      $(this).addClass('pagerer-page-has-focus');
    })
    .bind('blur', function(event) {
      $(this).removeClass('pagerer-page-has-focus');
    })
    .bind('keydown', function(event) {
      switch(event.keyCode) {
        case 13:
        case 10:
          // Return key pressed, relocate.
          var targetPage = valueToIndex($(this).val(), this.pagererState);
          if (targetPage !== this.pagererState.current) {
            pagererRelocate(this, this, targetPage);
          }
          event.stopPropagation();
          event.preventDefault();
          return false;

        case 27:
          // Escape.
          $(this).val(indexToValue(this.pagererState.current, this.pagererState));
          return false;

        case 38:
          // Up.
          widgetOffsetValue(this, -1);
          return false;

        case 40:
          // Down.
          widgetOffsetValue(this, 1);
          return false;

        case 33:
          // Page up.
          widgetOffsetValue(this, -5);
          return false;

        case 34:
          // Page down.
          widgetOffsetValue(this, 5);
          return false;

        case 35:
          // End.
           $(this).val(indexToValue(this.pagererState.total - 1, this.pagererState));
          return false;

        case 36:
          // Home.
           $(this).val(1);
          return false;

      }
    });

    /**
     * 'pagerer-slider' jQuery UI slider event binding.
     */
    $('.pagerer-slider', context)
    .ready().each(function(index) {
      state.isRelocating = false;
      this.pagererState = pagererEvalState($(this).attr('id'));

      // Create slider.
      var sliderBar = $(this);
      sliderBar.slider({
        min: 0,
        max: this.pagererState.total - 1,
        step: 1,
        value: this.pagererState.current,
        range: 'min',
        animate: true
      });

      // Set slider handle dimensions and text.
      var sliderHandle = sliderBar.find('.ui-slider-handle');
      sliderHandle
        .css('width', (String(indexToValue(this.pagererState.total - 1, this.pagererState)).length + 2) + 'em')
        .css('height', Math.max(sliderHandle.height(), 16) + 'px')
        .css('line-height', Math.max(sliderHandle.height(), 16) + 'px')
        .css('margin-left', -sliderHandle.width() / 2)
        .text(indexToValue(this.pagererState.current, this.pagererState))
        .bind('blur', function(event) {
          pagererReset();
          var sliderBar = $(this).parent().get(0);
          if (!sliderBar.pagererState.spinning) {
            sliderBar.pagererState.spinning = true;
            $(sliderBar).slider('option', 'value', sliderBar.pagererState.current);
            $(this).text(indexToValue(sliderBar.pagererState.current, sliderBar.pagererState));
            sliderBar.pagererState.spinning = false;
          }
        });

      // Set slider bar dimensions.
      sliderBar
        .css('width', ((this.pagererState.quantity * 3) + 'em'))
        .css('margin-left', sliderHandle.width() / 2)
        .css('margin-right', sliderHandle.width() / 2);

      var pixelsPerStep = sliderBar.width() / this.pagererState.total;
      // If autodetection of navigation action, determine whether to
      // use tickmark or timelapse.
      if (this.pagererState.action === 'auto') {
        if (pixelsPerStep > 3) {
          this.pagererState.action = 'timelapse';
        } else {
          this.pagererState.action = 'tickmark';
        }
      }
      // If autodetection of navigation icons, determine whether to
      // hide icons.
      if (this.pagererState.icons === 'auto' && pixelsPerStep > 3) {
        $(this).parents('.pager').find('.pagerer-slider-control-icon').parent().hide();
      }
      // Add information to user to click on the tickmark to start page
      // relocation.
      if (this.pagererState.action === 'tickmark') {
        var title = $(this).attr('title');
        $(this).attr('title',  title + ' ' + this.pagererState.tickmarkTitle);
      }
    })
    .bind('slide', function(event, ui) {
      pagererReset();
      $(this).find('.ui-slider-handle').text(indexToValue(ui.value, this.pagererState));
    })
    .bind('slidechange', function(event, ui) {

      var sliderBar = this;
      var sliderHandle = $(this).find('.ui-slider-handle');
      var sliderHandleIcon;

      // Set handle text to widget value.
      sliderHandle.text(indexToValue(ui.value, this.pagererState));

      // If currently sliding the handle via navigation icons,
      // do nothing.
      if (this.pagererState.spinning) {
        return false;
      }

      // Determine target page.
      var targetPage = $(this).slider('option', 'value');

      // Relocate immediately to target page if no
      // tickmark/timelapse confirmation required.
      if (this.pagererState.action === 'timelapse' && this.pagererState.timelapse === 0) {
        sliderHandle.append("<div class='pagerer-slider-handle-icon'/>");
        sliderHandleIcon = sliderHandle.find('.pagerer-slider-handle-icon');
        pagererRelocate(this, sliderHandleIcon, targetPage);
        return false;
      }

      // Otherwise, add a tickmark or clock icon to the handle text,
      // to be clicked to activate page relocation.
      sliderHandle.text(indexToValue(ui.value, this.pagererState) + ' ');
      if (this.pagererState.action === 'timelapse') {
        sliderHandle.append("<div class='pagerer-slider-handle-icon throbber'/>");
      } else {
        sliderHandle.append("<div class='pagerer-slider-handle-icon ui-icon ui-icon-check'/>");
      }

      // Bind page relocation to mouse clicking on the icon.
      sliderHandleIcon = sliderHandle.find('.pagerer-slider-handle-icon');
      sliderHandleIcon.bind('mousedown', function(event) {
        pagererReset();
        // Remove icon.
        $(sliderBar).find('.pagerer-slider-handle-icon').removeClass('throbber');
        // Relocate.
        pagererRelocate(sliderBar, sliderHandleIcon, targetPage);
        return false;
      });

      // Bind page relocation to timeout of timelapse.
      if (this.pagererState.action === 'timelapse') {
        pagererReset();
        state.timeoutAction = setTimeout(function() {
          // Remove icon.
          $(sliderBar).find('.pagerer-slider-handle-icon').removeClass('ui-icon').removeClass('throbber');
          // Relocate.
          pagererRelocate(sliderBar, sliderHandleIcon, targetPage);
          return false;
        }, this.pagererState.timelapse);
      }

    });

    /**
      * pagerer-slider control icons event binding
      *
      * The navigation icons serve as an helper for the slider positioning,
      * to fine-tune the selection. Once mouse is pressed on an icon, the
      * slider handle is moved +/- one value. If mouse is kept pressed, the
      * slider handle will move continuosly. When mouse is released or moved
      * away from the icon, sliding will stop and the handle status will be
      * processed through slider 'slidechange' event triggered by the
      * sliderOffsetValue() function.
      */
    $('.pagerer-slider-control-icon', context)
    .bind('mousedown', function(event) {
      pagererReset();
      var slider = $(this).parents('.pager').find('.pagerer-slider').get(0);
      slider.pagererState.spinning = true;
      var offset = $(this).hasClass('ui-icon-circle-minus') ? PAGERER_LEFT : PAGERER_RIGHT;
      sliderOffsetValue(slider, offset);
      state.intervalAction = setInterval(function(){
        state.intervalCount++;
        if (state.intervalCount > 10) {
          sliderOffsetValue(slider, offset);
        }
      }, 50);
    })
    .bind('mouseup mouseleave', function() {
      var slider = $(this).parents('.pager').find('.pagerer-slider').get(0);
      if (slider.pagererState.spinning) {
        state.intervalCount = 0;
        clearInterval(state.intervalAction);
        slider.pagererState.spinning = false;
        sliderOffsetValue(slider, 0);
        $(slider).find('.ui-slider-handle').focus();
      }
    });

    /**
     * 'pagerer-scrollpane' event binding.
     */
    $('.pagerer-scrollpane', context)
    .ready().each(function(index) {
      state.isRelocating = false;

      // Get the scrollpane components, i.e. the viewport, the
      // pager wrapped within it, and the wrapped pager elements.
      var viewport = $(this).find('.item-list');
      var pager = $(this).find('.pager').get(0);
      var pagerElements = $(pager).find('li');
      var pagerPages = $(pager).find('li:not(.separator)');
      var pagerSeparators = $(pager).find('li.separator');

      // Attach state variables to the wrapped pager.
      pager.pagererState = pagererEvalState($(this).attr('id'));
      $.extend(pager.pagererState, {
        scrollpane: $(this).parent(),
        viewport: viewport,
        pageWidth: 0,
        pageLeftMargin: 0,
        separatorWidth: 0,
        leftOverflow: 0,
        rightOverflow: 0,
        viewsAjaxContext: getViewsAjaxContext(this),
        scrolling: false,
        scrollingDuration: 0,
        fastScrolling: 0
      });

      // Determine pager element width from maximum width possible.
      var pageDupe = $(pagerPages[0]).clone();
      pageDupe.removeClass('pager-current first last');
      pageDupe.addClass('pager-item pagerer-dupe');
      pageDupe.text(indexToValue(pager.pagererState.total - 1, pager.pagererState));
      $(pager).append(pageDupe);
      pager.pagererState.pageWidth = Math.ceil($(pageDupe).outerWidth(true));
      pager.pagererState.pageLeftMargin = parseInt($(pageDupe).css('margin-left'));
      var cellHeight = Math.ceil($(pageDupe).outerHeight(true));
      $(pager).find('.pagerer-dupe').remove();

      // Determine pager separator width, if existing.
      if (pagerSeparators.length > 0) {
        pager.pagererState.separatorWidth = Math.ceil($(pagerSeparators[0]).outerWidth(true));
      }

      // Set dimensions.
      var pagerWidth = (pagerPages.length * pager.pagererState.pageWidth) + (pagerSeparators.length * pager.pagererState.separatorWidth);
      var viewportWidth = Math.min((pager.pagererState.quantity * pager.pagererState.pageWidth) + ((pager.pagererState.quantity - 1) * pager.pagererState.separatorWidth), pagerWidth);
      $(this).css({
        width: viewportWidth + 'px',
        height: cellHeight + 'px'
      });
      $(viewport).css({
        width: viewportWidth + 'px',
        height: cellHeight + 'px'
      });
      $(pager).css({
        width: pagerWidth + 'px',
        height: cellHeight + 'px'
      });

      // Allocate input pager elements to pager.
      var elementLeft = 0;
      var pagerCurrentPage = 0;
      pagerElements.each(function(index) {
        if (!$(this).hasClass('separator')) {
          var pageWidth = $(this).outerWidth(true);
          var pageLeftMargin = pager.pagererState.pageLeftMargin + ((pager.pagererState.pageWidth - pageWidth) / 2);
          $(this).css('left', elementLeft + 'px');
          $(this).css('margin-left', pageLeftMargin + 'px');
          if ($(this).hasClass('pager-current')) {
            pagerCurrentPage = index;
          }
          elementLeft += pager.pagererState.pageWidth;
        } else {
          $(this).css('left', elementLeft + 'px');
          elementLeft += pager.pagererState.separatorWidth;
        }
      });

      // Set current item to the middle of the viewport.
      var pagerLeftPage = pagerCurrentPage - Math.floor(pager.pagererState.quantity / 2);
      if (pagerLeftPage < 0) {
        pagerLeftPage = 0;
      } else if (pagerLeftPage > pagerPages.length - pager.pagererState.quantity) {
        pagerLeftPage = pagerPages.length - pager.pagererState.quantity;
      }
      var pagerLeftOffset = $(pagerPages[pagerLeftPage]).css('left');
      $(pager).css('left', '-' + pagerLeftOffset);

      // Left- and right-most pages.
      var pagerLeftPageIndex = valueToIndex($(pagerPages[0]).text(), pager.pagererState);
      var pagerRightPageIndex = valueToIndex($(pagerPages[pagerPages.length - 1]).text(), pager.pagererState);

      // Add elements to the left.
      pager.pagererState.leftOverflow = scrollpaneAddPagerElements(
        pager,
        PAGERER_LEFT,
        pagerLeftPageIndex - 1,
        pager.pagererState.quantity,
        true
      );

      // Add elements to the right.
      pager.pagererState.rightOverflow = scrollpaneAddPagerElements(
        pager,
        PAGERER_RIGHT,
        pagerRightPageIndex + 1,
        pager.pagererState.quantity,
        true
      );

    });

    /**
      * pagerer-scrollpane buttons event binding
      *
      * The navigation buttons shift the entire pager embedded in the
      * scrollpane viewport.
      * Once mouse is pressed on a prev/next button, the pager is moved
      * right/left by one position. If mouse is kept pressed, the pager will
      * shift continuosly. When mouse is released or moved away from the icon,
      * shifting will stop.
      * If mouse is pressed on a first/last button, the pager is moved to
      * first/last page.
      */
    $('.pagerer-scrollpane-button', context)
    .ready().each(function(index) {
      this.pagererState = {
        scrollpane: $(this).parents('.pager').get(0),
        pager: $(this).parents('.pager').find('.pagerer-scrollpane').find('.item-list').find('.pager').get(0)
      };
      $(this).button();
      $(this)
      .bind('mousedown', function(event) {
        var button = this;
        var pager = button.pagererState.pager;
        var scope;

        // Return immediately if button is disabled.
        if ($(button).button('option', 'disabled')) {
          return false;
        }

        // Determine scope of scroll request.
        if ($(button).hasClass('pagerer-next')) {
          scope = 'next';
        } else if ($(button).hasClass('pagerer-previous')) {
          scope = 'previous';
        } else if ($(button).hasClass('pagerer-first')) {
          scope = 'first';
        } else if ($(button).hasClass('pagerer-last')) {
          scope = 'last';
        }

        // If scrollpane is currently transitioning, and a request for a
        // different scope is received, reset all transitions.
        if (pager.pagererState.scrolling && pager.pagererState.scrolling !== scope) {
          pagererReset();
        }

        // Transition duration based on single click.
        switch (pager.pagererState.scrollingDuration) {
          case 0:
            pager.pagererState.scrollingDuration = 500;
            break;

          case 500:
          case 200:
            pager.pagererState.scrollingDuration = 200;
            break;

        }
        scrollpaneScrollRequestEnqueue(pager, scope, pager.pagererState.scrollingDuration);

        // If button is kept pressed long enough, start fastScrolling mode.
        if ((scope === 'previous' || scope === 'next') && !$(button).button('option', 'disabled')) {
          state.timeoutAction = setTimeout(function() {
            pager.pagererState.fastScrolling = 1;
            scrollpaneScrollRequestEnqueue(pager, scope, scrollpaneGetScrollDuration(pager));
          }, pager.pagererState.scrollingDuration + 20);
        }
      })
      .bind('mouseup mouseleave', function(event) {
        // Stop fastScrolling mode if active.
        var button = this;
        var pager = button.pagererState.pager;
        clearTimeout(state.timeoutAction);
        pager.pagererState.fastScrolling = 0;
      });
    })
    .load().each(function(index) {
      // Aligns viewport border color to button style.
      if ($(this).hasClass('pagerer-first')) {
        this.pagererState.pager.pagererState.viewport.css({
          'border-top-color' : $(this).css('border-top-color'),
          'border-right-color' : $(this).css('border-right-color'),
          'border-bottom-color' : $(this).css('border-bottom-color'),
          'border-left-color' : $(this).css('border-left-color')
        });
      }
      // Set button enable/disabled state.
      scrollpaneSetButtonState(this);
    });

    /**
     * Helper functions
     */

    /**
     * Return page text from zero-based page index number.
     */
    function indexToValue(index, state) {
      switch(state.display) {
        case 'pages':
          return Drupal.formatString(state.pageTag, {'@number': index + 1});

        case 'items':
          return Drupal.formatString(state.pageTag, {'@number': (index * state.interval) + 1});

        case 'item_ranges':
          return Drupal.formatString('@min@separator@max', {
            '@min': Drupal.formatString(state.pageTag, {'@number': (index * state.interval) + 1}),
            '@separator': state.rangeSeparator,
            '@max': Drupal.formatString(state.pageTag, {'@number': Math.min(((index + 1) * state.interval), state.totalItems)})
          });

      }
    }

    /**
     * Return zero-based page index number from textual value.
     */
    function valueToIndex(value, state) {
      switch(state.display) {
        case 'pages':
          if (isNaN(value)) {
            return 0;
          }
          value = parseInt(value);
          if (value < 1) {
            return 0;
          }
          if (value > state.total) {
            value = state.total;
          }
          return value - 1;

        case 'items':
          if (isNaN(value)) {
            return 0;
          }
          value = parseInt(value);
          if (value < 1) {
            return 0;
          }
          if (value > state.totalItems) {
            value = state.totalItems;
          }
          return parseInt((value - 1) / state.interval);

        case 'item_ranges':
          var values = value.split(state.rangeSeparator);
          value = values[0];
          if (isNaN(value)) {
            return 0;
          }
          value = parseInt(value);
          if (value < 1) {
            return 0;
          }
          if (value > state.totalItems) {
            value = state.totalItems;
          }
          return parseInt((value - 1) / state.interval);

      }
    }

    /**
     * Return an element's pagererState from the HTML attribute.
     */
    function pagererEvalState(stringState) {
      var pagererState = eval('(' + stringState + ');');
      return pagererState;
    }

    /**
     * Reset pending transitions.
     *
     * Cancel timeout-bound page relocation and any unprocessed scrollpane
     * transition.
     */
    function pagererReset() {
      if (state.timeoutAction) {
        clearTimeout(state.timeoutAction);
      }
      $('.pagerer-scrollpane').find('.pager').each(function(index) {
        var pager = this;
        $(pager).clearQueue('pagererQueue');
        $(pager).stop(false, true);
        pager.pagererState.scrolling = false;
        pager.pagererState.scrollingDuration = 0;
        pager.pagererState.fastScrolling = 0;
      });
    }

    /**
     * Relocate client browser to target page.
     *
     * Relocation method is decided based on the context of the pager element,
     * being in order of priority:
     *  - a AJAX enabled Views context - AJAX is used
     *  - a Views preview area in a Views settings form - AJAX is used
     *  - a page rendered through the admin overlay - BBQ is used
     *  - a normal page - document.location is used
     */
    function pagererRelocate(element, ajaxAttachElement, targetPage) {
      // Check we are not relocating already.
      if (state.isRelocating) {
        return false;
      }
      state.isRelocating = true;

      // Replace placeholder with page target.
      var path = element.pagererState.path.replace(/pagererpage/, targetPage);

      // Check if element is in Views AJAX context.
      var viewsAjaxContext = getViewsAjaxContext(element);
      if (viewsAjaxContext) {
        // Element is in Views AJAX context.
        attachViewsAjax(ajaxAttachElement, 'doViewsAjax', viewsAjaxContext, path);
        $(ajaxAttachElement).trigger('doViewsAjax');

      } else if ($(element).parents('#views-live-preview').length) {
        // Element is in Views preview context.
        var base = $(element).attr('id');
        var element_settings = {
          'event': 'doViewsAjaxPreview',
          'progress': { 'type': 'throbber' },
          'url': Drupal.settings.basePath + path,
          'method': 'html',
          'wrapper': 'views-live-preview'
        };
        Drupal.ajax[base] = new Drupal.ajax(base, element, element_settings);
        $(element).trigger('doViewsAjaxPreview');

      } else if (window.Drupal.overlayChild) {
        // Drupal admin overlay
        window.parent.jQuery.bbq.pushState({'overlay': path});

      } else {
        // Normal page
        document.location = Drupal.settings.basePath + path;

      }
    }

    /**
     * Widget - Update value based on an offset.
     */
    function widgetOffsetValue(element, offset) {
      var widgetValue = valueToIndex($(element).val(), element.pagererState);
      var newValue = widgetValue + offset;
      if (newValue < 0) {
        newValue = 0;
      } else if (newValue >= element.pagererState.total) {
        newValue = element.pagererState.total - 1;
      }
      $(element).val(indexToValue(newValue, element.pagererState));
    }

    /**
     * Slider - Update value based on an offset.
     */
    function sliderOffsetValue(element, offset) {
      var newValue = $(element).slider('option', 'value') + offset;
      var maxValue = $(element).slider('option', 'max');
      if (newValue >= 0 && newValue <= maxValue) {
        $(element).slider('option', 'value', newValue);
      }
    }

    /**
     * Scrollpane - Enqueue a scrollpane scroll request.
     *
     * Scrolls embedded pager to first/previous/next/last 'scope' in a
     * 'duration' timelapse.
     */
    function scrollpaneScrollRequestEnqueue(pager, scope, duration) {
      $(pager).queue('pagererQueue', function() {
        pager.pagererState.scrolling = scope;

        // In fastScrolling mode, enqueue next iteration straight ahead.
        if (pager.pagererState.fastScrolling) {
          pager.pagererState.fastScrolling++;
          scrollpaneScrollRequestEnqueue(pager, scope, scrollpaneGetScrollDuration(pager));
        }

        var pagerPages = $(pager).find('li:not(.separator)');
        var first = valueToIndex($(pagerPages[0]).text(), pager.pagererState);
        var last = valueToIndex($(pagerPages[pagerPages.length - 1]).text(), pager.pagererState);
        var addedElements;

        switch (scope) {
          // ***** Next - shift left.
          case 'next':
            // Add a pager element on the right.
            addedElements = scrollpaneAddPagerElements(pager, PAGERER_RIGHT, last + 1, 1);
            if (pager.pagererState.leftOverflow < pager.pagererState.quantity) {
              // There's space on the left side to shift pager.
              if (pager.pagererState.rightOverflow > 0) {
                // Pager overflows to the right, so shift pager to the left.
                scrollpaneShiftPager(pager, PAGERER_LEFT, 1, duration);
                return;
              }
            } else {
              // No space on the left side to shift pager.
              if (addedElements || pager.pagererState.rightOverflow > 0) {
                // Remove first element on the left, then shift pager one
                // position to the left.
                scrollpaneRemovePagerElements(pager, PAGERER_LEFT, 1);
                scrollpaneShiftPager(pager, PAGERER_LEFT, 1, duration);
                return;
              }
            }
            break;

          // ***** Previous - shift right.
          case 'previous':
            // Add a pager element on the left.
            addedElements = scrollpaneAddPagerElements(pager, PAGERER_LEFT, first - 1, 1);
            if (pager.pagererState.rightOverflow < pager.pagererState.quantity) {
              // There's space on the right side to shift pager.
              if (pager.pagererState.leftOverflow > 0) {
                // Pager overflows to the left, so shift pager to the right.
                scrollpaneShiftPager(pager, PAGERER_RIGHT, 1, duration);
                return;
              }
            } else {
              // No space on the right side to shift pager.
              if (addedElements || pager.pagererState.leftOverflow > 0) {
                // Remove first element on the right, then shift pager one
                // position to the right.
                scrollpaneRemovePagerElements(pager, PAGERER_RIGHT, 1);
                scrollpaneShiftPager(pager, PAGERER_RIGHT, 1, duration);
                return;
              }
            }
            break;

          // ***** First.
          case 'first':
            var fromEl = Math.min((pager.pagererState.quantity * 2) - 1, first - 1);
            addedElements = scrollpaneAddPagerElements(pager, PAGERER_LEFT, fromEl, pager.pagererState.quantity * 2);
            scrollpaneShiftPager(
              pager,
              PAGERER_RIGHT,
              pager.pagererState.leftOverflow,
              duration,
              function() {
                if (pager.pagererState.rightOverflow > pager.pagererState.quantity) {
                  scrollpaneRemovePagerElements(pager, PAGERER_RIGHT, pager.pagererState.rightOverflow - pager.pagererState.quantity);
                }
              }
            );
            return;

          // ***** Last.
          case 'last':
            var fromEl = Math.max((pager.pagererState.total - (pager.pagererState.quantity * 2)), last + 1);
            addedElements = scrollpaneAddPagerElements(pager, PAGERER_RIGHT, fromEl, pager.pagererState.quantity * 2);
            scrollpaneShiftPager(
              pager,
              PAGERER_LEFT,
              pager.pagererState.rightOverflow,
              duration,
              function() {
                if (pager.pagererState.leftOverflow > pager.pagererState.quantity) {
                  scrollpaneRemovePagerElements(pager, PAGERER_LEFT, pager.pagererState.leftOverflow - pager.pagererState.quantity);
                }
              }
            );
            return;

        }

        // Dequeue next iteration in the queue.
        scrollpaneScrollRequestDequeue(pager);

      });

      // Starts the queue processing.
      if (pager.pagererState.scrolling === false) {
        $(pager).dequeue('pagererQueue');
      }
    }

    /**
     * Scrollpane - Dequeue a scrollpane scroll request.
     *
     * If no more requests in the queue, clear state variables.
     */
    function scrollpaneScrollRequestDequeue(pager) {
      if ($(pager).queue('pagererQueue').length > 0) {
        $(pager).dequeue('pagererQueue');
      } else {
        pager.pagererState.scrolling = false;
        pager.pagererState.scrollingDuration = 0;
        pager.pagererState.fastScrolling = 0;
      }
    }

    /**
     * Scrollpane - Get duration of next scroll transition.
     */
    function scrollpaneGetScrollDuration(pager) {
      var ret = ((pager.pagererState.fastScrolling - 1) * -19.8) + 200;
      return (ret > 2) ? ret : 2;
    }

    /**
     * Scrollpane - Enable/disable scrollpane buttons.
     */
    function scrollpaneSetButtonState(element) {
      if ($(element).hasClass('pagerer-first') || $(element).hasClass('pagerer-previous')) {
        if (element.pagererState.pager.pagererState.leftOverflow === 0) {
          $(element).mouseup().mouseleave();
          $(element).button('disable');
        } else {
          $(element).button('enable');
        }
      }
      if ($(element).hasClass('pagerer-next') || $(element).hasClass('pagerer-last')) {
        if (element.pagererState.pager.pagererState.rightOverflow === 0) {
          $(element).mouseup().mouseleave();
          $(element).button('disable');
        } else {
          $(element).button('enable');
        }
      }
    }

    /**
     * Scrollpane - Add pages to the embedded pager.
     *
     * Add 'count' pages and separators on left/right 'side', starting with
     * page at index 'start'.
     */
    function scrollpaneAddPagerElements(pager, side, start, count, onReady) {

      // onReady will be true if function is invoked at .ready()
      onReady = onReady || false;

      var pagerPages;
      var pagerLeftPage;
      var pagerRightPage;
      var pageWidth;
      var pageLeftMargin;
      var pageDupe;
      var pagerSeparators;
      var separatorWidth = 0;
      var separatorDupe;

      for (var i = 0; i < count; i++) {
        pagerPages = $(pager).find('li:not(.separator)');
        pagerSeparators = $(pager).find('li.separator');

        // If we have separators, prepare dupe and set width.
        if (pagerSeparators.length) {
          separatorDupe = $(pagerSeparators[0]).clone();
          separatorWidth = pager.pagererState.separatorWidth;
        }

        // Add page and separator.
        if (side === PAGERER_RIGHT) {
          pagerRightPage = pagerPages.length - 1;
          if (valueToIndex($(pagerPages[pagerRightPage]).text(), pager.pagererState) >= (pager.pagererState.total - 1)) {
            break;
          }
          pageDupe = $(pagerPages[pagerRightPage]).clone();
          $(pagerPages[pagerRightPage]).removeClass('last');
          scrollpaneSetPagerElementHTML(pageDupe, pager, start + i, onReady);
          if (separatorWidth) {
            $(separatorDupe).css('left', (parseInt($(pageDupe).css('left')) + pager.pagererState.pageWidth) + 'px');
            $(pager).append(separatorDupe);
          }
          $(pageDupe).css('left', (parseInt($(pageDupe).css('left')) + pager.pagererState.pageWidth + separatorWidth) + 'px');
          $(pager).append(pageDupe);
          pageWidth = $(pageDupe).outerWidth(true);
          pageLeftMargin = pager.pagererState.pageLeftMargin + ((pager.pagererState.pageWidth - pageWidth) / 2);
          $(pageDupe).css('margin-left', pageLeftMargin + 'px');
          pager.pagererState.rightOverflow++;
        } else if (side === PAGERER_LEFT) {
          pagerLeftPage = 0;
          if (valueToIndex($(pagerPages[pagerLeftPage]).text(), pager.pagererState) === 0) {
            break;
          }
          pageDupe = $(pagerPages[pagerLeftPage]).clone();
          $(pagerPages[pagerLeftPage]).removeClass('first');
          scrollpaneSetPagerElementHTML(pageDupe, pager, start - i, onReady);
          if (separatorWidth) {
            $(separatorDupe).css('left', (parseInt($(pageDupe).css('left')) - separatorWidth) + 'px');
            $(pager).prepend(separatorDupe);
          }
          $(pageDupe).css('left', (parseInt($(pageDupe).css('left')) - pager.pagererState.pageWidth - separatorWidth) + 'px');
          $(pager).prepend(pageDupe);
          pageWidth = $(pageDupe).outerWidth(true);
          pageLeftMargin = pager.pagererState.pageLeftMargin + ((pager.pagererState.pageWidth - pageWidth) / 2);
          $(pageDupe).css('margin-left', pageLeftMargin + 'px');
          pager.pagererState.leftOverflow++;
        }
      }
      // Resize pager.
      pagerPages = $(pager).find('li:not(.separator)');
      pagerSeparators = $(pager).find('li.separator');
      var pagerWidth = (pagerPages.length * pager.pagererState.pageWidth) + (pagerSeparators.length * pager.pagererState.separatorWidth);
      $(pager).css('width', pagerWidth + 'px');
      // If elements were added on the left side, pager and elements will be
      // misplaced, so reposition the elements.
      if (side === PAGERER_LEFT) {
        $(pager).css({
          left: (parseInt($(pager).css('left')) - (pager.pagererState.pageWidth * i) - (pager.pagererState.separatorWidth * i)) + 'px'
        });
        scrollpaneShiftPagerElements(pager, PAGERER_RIGHT, i);
      }
      return i;
    }

    /**
     * Scrollpane - Remove pages from the embedded pager.
     *
     * Remove 'count' pages and separators on left/right 'side'.
     */
    function scrollpaneRemovePagerElements(pager, side, count) {
      var pagerPages;
      var pagerSeparators;
      for (var i = 0; i < count; i++) {
        pagerPages = $(pager).find('li:not(.separator)');
        pagerSeparators = $(pager).find('li.separator');
        if (side === PAGERER_RIGHT) {
          $(pagerPages[pagerPages.length - 1]).remove();
          $(pagerPages[pagerPages.length - 1]).addClass('last');
          if (pagerSeparators.length) {
            $(pagerSeparators[pagerSeparators.length - 1]).remove();
          }
          pager.pagererState.rightOverflow--;
        } else if (side === PAGERER_LEFT) {
          $(pagerPages[0]).remove();
          $(pagerPages[0]).addClass('first');
          if (pagerSeparators.length) {
            $(pagerSeparators[0]).remove();
          }
          pager.pagererState.leftOverflow--;
        }
      }
      // Resize pager.
      var pagerWidth = ((pagerPages.length - 1) * pager.pagererState.pageWidth) + ((pagerSeparators.length - 1) * pager.pagererState.separatorWidth);
      $(pager).css('width', pagerWidth + 'px');
      // If elements were removed on the left side, the remaining ones will
      // be misplaced wihin the pager, so reposition them.
      if (side === PAGERER_LEFT) {
        $(pager).css({
          left: (parseInt($(pager).css('left')) + ((pager.pagererState.pageWidth + pager.pagererState.separatorWidth) * count)) + 'px'
        });
        scrollpaneShiftPagerElements(pager, PAGERER_LEFT, i);
      }
      return true;
    }

    /**
     * Scrollpane - Shift the embedded pager elements.
     *
     * Shift the elements of the embedded pager by 'count' pages in
     * left/right 'direction'.
     */
    function scrollpaneShiftPagerElements(pager, direction, count) {
      var pagerElements = $(pager).find('li');
      pagerElements.each(function(index) {
        $(this).css({
          left: (parseInt($(this).css('left')) + (direction * (pager.pagererState.pageWidth + pager.pagererState.separatorWidth) * count)) + 'px'
        });
      });
    }

    /**
     * Scrollpane - Shift the embedded pager in the viewport.
     *
     * Shift the entire pager by 'count' pages in left/right 'direction'.
     * If 'duration' is set (msec), the shift will be jQuery animated.
     * A 'complete' callback is executed at completion if set.
     * Overall pager shift is executed in a jQuery queue, so next action is
     * dequeued at the end of the call (for execution after the animation
     * is completed).
     */
    function scrollpaneShiftPager(pager, direction, count, duration, complete) {
      var left = parseInt($(pager).css('left'));
      var offset = direction * count * (pager.pagererState.pageWidth + pager.pagererState.separatorWidth);
      $(pager).animate({
        left: (left + offset) + 'px'
      },
      {
        duration: duration,
        queue: false,
        complete: function() {
          pager.pagererState.leftOverflow -= direction * count;
          pager.pagererState.rightOverflow += direction * count;
          if (typeof complete !== 'undefined') {
            complete();
          }
          if (pager.pagererState.leftOverflow <= 1 || pager.pagererState.rightOverflow <= 1) {
            $(pager.pagererState.scrollpane).find('.ui-button').each(function() {
              scrollpaneSetButtonState(this);
            });
          }
          scrollpaneScrollRequestDequeue(pager);
        }
      });
    }

    /**
     * Scrollpane - Set HTML of a page element in the pager.
     */
    function scrollpaneSetPagerElementHTML(element, pager, targetPage, onReady) {

      // onReady will be true if function is invoked at .ready()
      onReady = onReady || false;

      if (targetPage !== pager.pagererState.current) {
        $(element[0]).removeClass('pager-current').addClass('pager-item');
        var anchor = $(element).find('a');
        if (!anchor.length) {
          $(element).text('');
          $(element).append('<a></a>');
          anchor = $(element).find('a');
        }
        // Format hyperlink.
        var path = pager.pagererState.path.replace(/pagererpage/, targetPage);
        var pageText = indexToValue(targetPage, pager.pagererState);
        anchor[0].href = Drupal.settings.basePath + path;
        $(anchor[0]).text(pageText);
        if (targetPage === 0) {
          anchor[0].title = Drupal.formatString(pager.pagererState.firstTitle, {'@number': pageText});
        } else if (targetPage === pager.pagererState.total - 1) {
          anchor[0].title = Drupal.formatString(pager.pagererState.lastTitle, {'@number': pageText});
        } else {
          anchor[0].title = Drupal.formatString(pager.pagererState.pageTitle, {'@number': pageText});
        }
        // In views, add AJAX where appropriate.
        if (!onReady && pager.pagererState.viewsAjaxContext) {
          // Element is in AJAX enabled view.
          attachViewsAjax(anchor[0], 'click', pager.pagererState.viewsAjaxContext, path);
        }  else if ($(pager).parents('#views-live-preview').length) {
          // Element is in Views preview context.
          var base = $(element).attr('id');
          var element_settings = {
            'event': 'click',
            'progress': { 'type': 'throbber' },
            'url': Drupal.settings.basePath + path,
            'method': 'html',
            'wrapper': 'views-live-preview'
          };
          Drupal.ajax[base] = new Drupal.ajax(base, element, element_settings);
        }
      } else {
        // Current page has its own class, and no href.
        $(element[0]).removeClass('pager-item').addClass('pager-current');
        $(element[0]).text(indexToValue(targetPage, pager.pagererState));
      }
    }

    /**
     * Views - Check if element is part of an AJAX enabled view.
     */
    function getViewsAjaxContext(element) {
      if (Drupal.settings && Drupal.settings.views && Drupal.settings.views.ajaxViews) {
        // Loop through active Views Ajax elements.
        for (var i in Drupal.settings.views.ajaxViews) {
          var view = '.view-dom-id-' + Drupal.settings.views.ajaxViews[i].view_dom_id;
          var viewDiv = $(element).parents(view);
          if (viewDiv.size()) {
            return {
              target: viewDiv.get(0),
              settings: Drupal.settings.views.ajaxViews[i],
              selector: view
            };
          }
        }
      }
      return false;
    }

    /**
     * Views - Attach Views AJAX behaviour to an element.
     */
    function attachViewsAjax(element, event, viewContext, path) {

      // Link to the element.
      var $link = $(element);

      // Retrieve the path to use for views' ajax.
      var ajax_path = Drupal.settings.views.ajax_path;

      // If there are multiple views this might've ended up showing up multiple times.
      if (ajax_path.constructor.toString().indexOf('Array') !== -1) {
        ajax_path = ajax_path[0];
      }

      // Check if there are any GET parameters to send to views.
      var queryString = window.location.search || '';
      if (queryString !== '') {
        // Remove the question mark and Drupal path component if any.
        var queryString = queryString.slice(1).replace(/q=[^&]+&?|&?render=[^&]+/, '');
        if (queryString !== '') {
          // If there is a '?' in ajax_path, clean url are on and & should be used to add parameters.
          queryString = ((/\?/.test(ajax_path)) ? '&' : '?') + queryString;
        }
      }

      // Load view's settings and parse pagerer path.
      var viewData = {};
      $.extend(
        viewData,
        viewContext.settings,
        Drupal.Views.parseQueryString(Drupal.settings.basePath + path),
        Drupal.Views.parseViewArgs(Drupal.settings.basePath + path, viewContext.settings.view_base_path)
      );

      // Load AJAX element_settings object and attach AJAX behaviour.
      var elementAjaxSettings = {
        url: ajax_path + queryString,
        submit: viewData,
        setClick: true,
        event: event,
        selector: viewContext.selector,
        progress: { type: 'throbber' }
      };
      viewContext.pagerAjax = new Drupal.ajax(false, $link, elementAjaxSettings);
    }

  }
};
})(jQuery);
