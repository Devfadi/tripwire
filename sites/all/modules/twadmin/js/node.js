jQuery(document).ready(function($) {
   /* TRIP2-585: Adding alert to anonymous user role selection */
   $('.field-name-field-secured-areas .form-item-field-secured-areas-und-4866 label').after('<div class="helptext">Caution! Selection of this role will make<br/>content visible to unregistered TRIPwire users.</div>');
   $('.form-item-field-access-classification-und-3851 label, .form-item-field-access-classification-und-3966 label, .form-item-field-access-classification-und-3071 label').after('<div class="helptext">Selection of this Classification Marking<br/>will add an acronym prefix as displayed<br/>inside the parenthesis to the title field systematically.</div>');
});