<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/NavigationTools.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/InsertionTools.php");

$registeredContents = [
    "signIn",
    "signUp",
    "signUpSuccess",
    "gallery",
    "createPost",
    "post",
    "error"
];

if (in_array($_GET["content"], $registeredContents))
    InsertionTools::insertContent($_GET["content"]);
else
    InsertionTools::insertContent("error");