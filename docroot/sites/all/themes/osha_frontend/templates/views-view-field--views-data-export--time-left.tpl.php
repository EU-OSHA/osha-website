<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
*/

  $last_question = "-";

        $query = db_select('quiz_node_results', 'a');
        $query->join('quiz_node_results_answers', 'b', 'a.result_id = b.result_id');
        $query->fields('b', array('question_nid','question_vid'));
        $query->addExpression('MAX(number)','last_question');
        $query->addExpression('MAX(question_nid)','last_nid');
        $query->condition('b.result_id', $output);
        $query->condition('b.answer_timestamp', 'NULL','<>');
        $res_ans = $query->execute();

        foreach ($res_ans as $resp) {
          //$resp_id = $resp->id;
            
            if ($resp->retrieve_string<>NULL){
                $retrieve ='Yes';
            }

            if ($resp->last_question<>NULL){
                $last_question = $resp->last_question; 
                $last = $resp->last_question; 
                if ($last_question==12){
                    $last_question = 'Finished';
                }else{
                    //Buscar la pregunta
                    $nodo = node_load($resp->last_nid);
                    $last_question = "";
                    $last_question = $resp->last_question . '-' .$nodo->title;     
                }    
            }
        }  


?>
<?php print $last_question ?>