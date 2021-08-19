<?php
require_once($_SERVER["DOCUMENT_ROOT"]."/php/tools/Status.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/NavigationTools.php");

function returnToSignUpPage(string $name, string $email) {
    NavigationTools::redirect("content", "signUp", "name", $name, "email", $email);
}

function returnToSignUpPageWithError(
    string $name,
    string $email,
    string $errorField,
    string $errorMessage
) {
    NavigationTools::redirect(
        "content", "signUp",
        "name", $name,
        "email", $email,
        "errorField", $errorField,
        "errorMessage", $errorMessage
    );
}

if (!isset($_POST["submit"]))
    returnToSignUpPage("", "");

$name = $_POST["name"];
$email = $_POST["email"];
$password = $_POST["password"];

if (!isset($name) or !isset($email) or !isset($password))
    returnToSignUpPage($name ?? "", $email ?? "");

require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserDataValidator.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserManager.php");

$nameStatus = UserDataValidator::validateUserName($name);
if ($nameStatus->isError())
    returnToSignUpPageWithError($name, $email, "name", $nameStatus->getMessage());

$emailStatus = UserDataValidator::validateEmail($email);
if ($emailStatus->isError())
    returnToSignUpPageWithError($name, $email, "email", $emailStatus->getMessage());

$passwordStatus = UserDataValidator::validatePassword($password);
if ($passwordStatus->isError())
    returnToSignUpPageWithError($name, $email, "password", $passwordStatus->getMessage());

UserManager::signUpUser($name, $email, $password);
NavigationTools::redirect("content", "signUpSuccess");