<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/NavigationTools.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserSession.php");

function returnToSignInPage(string $name) {
    NavigationTools::redirect("content", "signIn", "name", $name);
}

function returnToSignInPageWithError(string $name, string $errorMessage) {
    NavigationTools::redirect(
        "content", "signIn",
        "name", $name,
        "errorMessage", $errorMessage
    );
}

if (!isset($_POST["submit"]))
    returnToSignInPage("", "");

$name = $_POST["name"];
$password = $_POST["password"];

if (!isset($name) or !isset($password))
    returnToSignInPage($name ?? "");

require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserManager.php");

$userCheckStatus = UserManager::checkUser($name, $password);
if ($userCheckStatus->isError())
    returnToSignInPageWithError($name ?? "", $userCheckStatus->getMessage());

$isVerified = UserManager::isVerified($name);
if ($isVerified === null)
    returnToSignInPageWithError($name ?? "", "User not found");
elseif ($isVerified === false)
    returnToSignInPageWithError($name ?? "", "Email is not verified");

UserSession::signIn($name);
NavigationTools::redirectToHomePage();