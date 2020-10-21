var generateExcel = function (pLanguage)
{
	var res = jQuery.ajax({
		url: "/admin/content/thesaurus-excel-generation/" + pLanguage,		
		dataType: "script",
		success: function (data) {
			console.log(data);
			alert("Excel File generated");
			location.reload();
		},
		async: true,
		error: function (err) {
			console.log(err);
			alert("An error has occurred, please try again");
		}
	}).responseText;
}

