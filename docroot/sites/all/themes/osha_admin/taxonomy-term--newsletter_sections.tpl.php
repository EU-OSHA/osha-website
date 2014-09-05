<div style="font: 12px Verdana,Helvetica,'Lucida Grande',Lucida,Arial,sans-serif;">
	<h1 style="color: #191919; font: 18px/35px Verdana,Helvetica,'Lucida Grande',Lucida,Arial,sans-serif; letter-spacing: 2px; margin: 34px 0 11px; text-shadow: 2px 2px 5px #dddddd; text-transform: uppercase;">
		<?php
			if (isset($name_field[$language])) {
				print($name_field[$language][0]['safe_value']);
			} else {
				print($name_field[0]['safe_value']);
			}
		?>
	</h1>
</div>
