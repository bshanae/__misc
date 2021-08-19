<?php
require_once($_SERVER["DOCUMENT_ROOT"]."/php/tools/Status.php");
require_once($_SERVER["DOCUMENT_ROOT"]."/php/tools/database/DatabaseManager.php");

class UserDataValidator
{
    // If username is valid, returns null. Otherwise, returns error string.
    public static function validateUserName(string $name): Status {
        if (empty($name))
            return Status::makeError("Name can't be empty");

        if (!ctype_alnum($name))
            return Status::makeError("Name contains invalid characters");

        if (strlen($name) > 10)
            return Status::makeError("Name is too long");

        $result = DatabaseManager::executeWithArgs("SELECT * FROM users WHERE name = ?", $name);
        if (!$result->checkNumberOfRows(function($number){ return $number == 0; }))
            return Status::makeError("This name is occupied by another user");

        return Status::makeOk();
    }

    // If email is valid, returns null. Otherwise, returns error string.
    public static function validateEmail(string $email): Status {
        if (empty($email))
            return Status::makeError("Email can't be empty");

        if (!filter_var($email, FILTER_VALIDATE_EMAIL))
            return Status::makeError("Email is invalid");

        $result = DatabaseManager::executeWithArgs("SELECT * FROM users WHERE email = ?", $email);

        if (!$result->checkNumberOfRows(function($number){ return $number == 0; }))
            return Status::makeError("This email is occupied by another user");
        return Status::makeOk();
    }

    // If password is valid, returns null. Otherwise, returns error string.
    public static function validatePassword(string $password): Status {
        if (empty($password))
            return Status::makeError("Password can't be empty");

        if (strlen($password) < 4)
            return Status::makeError("Password should be at least 4 characters long");

        if (strlen($password) > 16)
            return Status::makeError("Password should be up to 16 characters long");

        return Status::makeOk();
    }
}