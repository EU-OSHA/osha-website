(function ($) {
    Drupal.behaviors.optAdd = {
        attach: function() {
            var opt_add = {};
            opt_add.Dependent = {};
            opt_add.Dependent.comparisons = {
                'Array': function(reference, value) {
                    //Make sure that value is an array, other wise we end up always evaling to true
                    if(!( typeof (value) == 'object' && ( value instanceof Array))) {
                        return false;
                    }
                    //We iterate through each of the values provided in the reference
                    //and check that they all exist in the value array.
                    //If even one doesn't then we return false. Otherwise return true.
                    var arrayComplies = true;
                    $.each(reference, function(key, val) {
                        if($.inArray(val, value) < 0) {
                            arrayComplies = false;
                        }
                    });
                    return arrayComplies;
                },
            };
            opt_add.Dependent.initializeDependee = function (selector, dependeeStates) {
                var state;
                // Cache for the states of this dependee.
                this.values[selector] = {};

                for (var i in dependeeStates) {
                    if (dependeeStates.hasOwnProperty(i)) {
                        state = dependeeStates[i];
                        // Make sure we're not initializing this selector/state combination twice.
                        if ($.inArray(state, dependeeStates) === -1) {
                            continue;
                        }

                        state = states.State.sanitize(state);

                        // Initialize the value of this state.
                        this.values[selector][state.name] = undefined;

                        // Monitor state changes of the specified state for this dependee.
                        $(selector).bind('state:' + state, $.proxy(function (e) {
                            this.update(selector, state, e.value);
                        }, this));

                        // Make sure the event we just bound ourselves to is actually fired.
                        new states.Trigger({selector: selector, state: state});
                    }
                }
            };

            var states = Drupal.states;
            $.extend(true, states, opt_add);
            Drupal.states = states;
        }
    }
}(jQuery));
