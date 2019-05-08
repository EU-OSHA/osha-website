/* globals jQuery */
(function ($) {
    'use strict';

    $.fn.charactersRemaining = function (options) {
        var self = this,
            settings = $.extend({
                // defaults
                className: 'charRemaining',
                singleCharacterText: '## character remaining',
                multipleCharacterText: '## characters remaining'
            }, options);

        function charactersRemaining(textarea) {
            var textContent = textarea.val(),
                newLines = textContent.match(/(\r\n|\n|\r)/g),
                maxCharacters = parseInt(textarea.attr('maxlength'), 10),
                characters = textContent.length,
                charMessage = textarea.next('.' + settings.className),
                remaining;
            if (newLines !== null) {
                characters += newLines.length;
            }

            remaining = maxCharacters - characters;

            if (remaining === 1) {
                charMessage.text(settings.singleCharacterText.replace('##', remaining));
            } else {
                charMessage.text(settings.multipleCharacterText.replace('##', remaining));
            }

        }

        (function init() {

            self.bind('input selectionchange propertychange', function (event) {
                var that = $(event.currentTarget);
                charactersRemaining(that);
            });

            self.each(function (index, value) {
                var element = $("<span></span>").addClass(settings.className);

                if (!self.next('.' + settings.className).length) {
                    self.after(element);
                }
                self.attr('placeholder', 'Title. Max ' + parseInt(self.attr('maxlength')) + ' characters.') ;
                charactersRemaining($(value));
            });
        }());
        
        // Chainable
        return self;
    };
}(jQuery));


