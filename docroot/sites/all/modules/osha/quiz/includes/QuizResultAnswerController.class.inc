<?php

/**
 * Controller for a single quiz question response.
 */
class QuizResultAnswerController extends EntityAPIController {

  /**
   * Build the response content with feedback.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $out = parent::buildContent($entity, $view_mode, $langcode, $content);
    $node = node_load($entity->question_nid, $entity->question_vid);
    $entity_info = entity_get_info('node');
    // @kludge
    // We check for an instance first. This is probably not the best way to do
    // this but we need to sometimes show feedback for an answer not stored.
    // For example when taking quizzes with "repeat until correct".
    if (!isset($entity->instance)) {
      $instance = _quiz_question_response_get_instance($entity->result_id, $node);
    }
    else {
      $instance = $entity->instance;
    }
    foreach ($entity_info['view modes'] as $view_mode => $info) {
      if ($instance->canReview("quiz_question_view_" . $view_mode)) {
        $build = node_view($node, $view_mode);
        unset($build['#theme']);
        unset($build['answers']);
        unset($build['links']);

        $out["quiz_question_view_" . $view_mode] = $build;
      }
    }

    $rows = array();

    $labels = array(
      'attempt' => t('Your answer'),
      'choice' => t('Answers'),
      'correct' => t('Is Correct?'),
      'solution' => t('Correct answer'),
    );
    drupal_alter('quiz_feedback_labels', $labels);

    foreach ($instance->getFeedbackValues() as $idx => $row) {
      foreach ($labels as $reviewType => $label) {
        if ((isset($row[$reviewType]) && $instance->canReview($reviewType))) {
          $rows[$idx][$reviewType] = $row[$reviewType];
          if (!empty($row[$reviewType])) {
            $out[$reviewType] = array(
              '#title' => $label,
              '#type' => 'item',
              '#markup' => $row[$reviewType],
            );
          }
        }
      }
    }

    if ($instance->isEvaluated()) {
      $score = $instance->getScore();
      if ($instance->isCorrect()) {
        $class = 'q-correct';
      }
      else {
        $class = 'q-wrong';
      }
    }
    else {
      $score = t('?');
      $class = 'q-waiting';
    }

    $quiz_result = quiz_result_load($entity->result_id);

    if ($rows) {
      $headers = array_intersect_key($labels, $rows[0]);
      $type = $instance->getQuizQuestion()->node->type;
      $tema = theme('quiz_question_feedback__' . $type, array('labels' => $headers, 'data' => $rows));
      $tema = str_replace('<table class="sticky-enabled">', "<table  style='width:100%' class='quiz-feedback-table sticky-enabled'>", $tema);
      
      $out['table']['#markup'] = $tema;
    }

   

    return $out;
  }

}
