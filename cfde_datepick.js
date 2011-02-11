
/** @file
 * adds datepick
 */

$(document).ready(function() {
  $("#edit-range").datepick({
    rangeSelect: true,
    rangeSeparator: ' -- ',
    minDate: '-5w',
    maxDate: '+0',
    showOtherMonths: true,
    selectOtherMonths: true,
    dateFormat: $.datepick.ISO_8601,
    showAnim: 'fadeIn',
    showSpeed: 'fast',
    showOnFocus: true,
    showTrigger: '#calImg'
  });
});