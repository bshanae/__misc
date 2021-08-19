<?php
class InsertionTools {
    public static function insertScript(string $id) {
        require_once($_SERVER["DOCUMENT_ROOT"] . "/php/scripts/$id.php");
    }

    public static function insertContent(string $id) {
        require_once($_SERVER["DOCUMENT_ROOT"] . "/php/elements/$id.php");
    }
}