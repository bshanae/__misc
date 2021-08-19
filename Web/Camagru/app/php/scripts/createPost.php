<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/gallery/posts/PostManager.php");

$encodedData = file_get_contents('php://input');
$decodedData = json_decode($encodedData);

echo PostManager::addPost($decodedData->image_id, $decodedData->text);