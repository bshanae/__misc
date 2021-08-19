<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/NavigationTools.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/InsertionTools.php");

switch ($_GET["script"]) {
    case "verifyUser" :
        InsertionTools::insertScript("verifyUser");
        break;
}