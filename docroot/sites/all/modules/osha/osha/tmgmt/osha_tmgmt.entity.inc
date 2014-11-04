<?php

/**
* Controller class for the approval workflow.
*
* {@inheritdoc}
*/
class OshaTMGMTValidatorItemController extends EntityAPIController {

/**
* {@inheritdoc}
*/
public function save($entity, DatabaseTransaction $transaction = NULL) {
parent::save($entity, $transaction);
}

/**
* {@inheritdoc}
*/
public function delete($ids, $transaction = NULL) {
parent::delete($ids, $transaction);
}
}