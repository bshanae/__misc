<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/gallery/Gallery.php");

foreach (PostManager::getPosts(0) as $post) {
    $image = "data/images/posts/" . $post->getImageFile();
    $text = $post->getText();
    $numberOfLikes = $post->getNumberOfLikes();

    echo "<img src=\"$image\" alt=\"Where is image?...\">";
}