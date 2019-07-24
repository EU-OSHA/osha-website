<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any.
 *
 * @ingroup views_templates
 */
?>
<table <?php if ($classes): ?> class="<?php print $classes; ?>"<?php endif ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)): ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
 
    <thead>
      <tr>
        <th scope="col">
          Date start
        </th>
        <th scope="col">
          Finished
        </th>
        <th scope="col">
          Last Question
        </th>
        
      </tr>
    </thead>
 
   <tbody>


    <?php 
    $number_questionnaires=0;
    $number_finished = 0;
    $number_not_finished = 0;
    $sum_nf = 0;

    foreach ($rows as $row_count => $row): ?>
      <tr scope="row">
        <?php 
        $time_start = $row['time_start'];
        $finished = $row['time_end'];
        $retrieve = "";
        $last_question = "-";

        $query = db_select('quiz_node_results', 'a');
        $query->join('quiz_node_results_answers', 'b', 'a.result_id = b.result_id');
        $query->fields('b', array('question_nid','question_vid'));
        $query->addExpression('MAX(number)','last_question');
        $query->addExpression('MAX(question_nid)','last_nid');
        $query->condition('b.result_id', $row['result_id']);
        $query->condition('b.answer_timestamp', 'NULL','<>');
        $res_ans = $query->execute();

        foreach ($res_ans as $resp) {
          //$resp_id = $resp->id;
        	$number_questionnaires = $number_questionnaires +1;
        	
          	if ($resp->last_question<>NULL){
            	$last_question = $resp->last_question; 
            	if ($last_question==12){
              		$last_question = 'Finished';
              		$number_finished =  $number_finished + 1;
            	}else{
	            	$number_not_finished = $number_not_finished +1;
	            	$sum_nf = $sum_nf + $resp->last_question;

	            	//Buscar la pregunta
	            	$nodo = node_load($resp->last_nid);
	            	$last_question = $resp->last_question . '-' .$nodo->title;     
	        	}    
	    	}
        }  
        ?>
          <td ><?php print $time_start?></td>
          <td ><?php print  $finished?></td>
          <td ><?php print $last_question?></td>
      </tr>
    <?php endforeach; 
    if (is_numeric($sum_nf) && $sum_nf >0){
    	$exit_average = $sum_nf / $number_not_finished;
    }
    else{
    	$exit_average = '';		
    }

    ?>
    <!--TOTALS-->
    <tr scope="row">	
    	<td ><b><?php print 'Totals: ' . $number_questionnaires?></b></td>
        <td ><b><?php print 'Finished: ' . $number_finished?></b></td>
        <td ><b><?php print 'Exit average: ' . round($exit_average,2) ?></b></td>
    </tr>
  </tbody>
</table>


