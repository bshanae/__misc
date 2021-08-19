<?php
$image = file_get_contents('php://input');
$image = str_replace("data:image/png;base64,", "", $image);
$image = str_replace(" ", "+", $image);

$fileData = base64_decode($image);
$fileId = "" . md5(time());
$filePath = $_SERVER["DOCUMENT_ROOT"]  . "/data/images/posts/" . $fileId . ".png";

$file = fopen($filePath, "w+");
if (!$file) {
    echo "";
    exit();
}

fwrite($file, $fileData);
fclose($file);

echo $fileId;