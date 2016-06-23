(function ($) {
    $(document).ready(function(){
        $('[name="field_start_date_value[value][date]"]').on('change', function(){
            var $end_date = $('[name="field_start_date_value2[value][date]"]');
            if ($end_date.val() == '') {
                $end_date.datepicker("option", { defaultDate: $(this).val() });
            }
        });
    });
})(jQuery);
