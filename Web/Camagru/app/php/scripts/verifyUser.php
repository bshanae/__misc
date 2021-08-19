<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserManager.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/InsertionTools.php");

if (!isset($_GET["token"])) {
    error_log("Token is not present");
    InsertionTools::insertContent("error");
}

if (UserManager::verifyUser($_GET["name"], urldecode($_GET["token"])) === false) {
    error_log("Invalid verification token");
    InsertionTools::insertContent("error");
}

InsertionTools::insertContent("gallery");