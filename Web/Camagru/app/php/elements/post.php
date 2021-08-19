<?php
require_once($_SERVER["DOCUMENT_ROOT"]."/php/tools/InsertionTools.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/gallery/posts/PostManager.php");

function returnError() {
    InsertionTools::insertContent("error");
    exit();
}

$postId = $_GET["post_id"];
if (!isset($postId))
    returnError();

$post = PostManager::findPost($postId);
if ($postId == null)
    returnError();

$imageId = $post->getImageFile();
$text = $post->getText();

echo "<div class=\"responsive-content\">";
echo "<img id=\"image\" src=\"http://localhost/data/images/posts/$imageId.png\">";
echo "<textarea readonly id=\"text\" class=\"bottom-offset\">$text</textarea>";
echo "</div>";