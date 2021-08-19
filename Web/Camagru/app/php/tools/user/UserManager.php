<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/Status.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/database/DatabaseManager.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserData.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserDataValidator.php");

class UserManager {
    public static function signUpUser(string $name, string $email, string $password): bool {
        if (UserDataValidator::validateUserName($name)->isError())
            return false;

        if (UserDataValidator::validateEmail($email)->isError())
            return false;

        if (UserDataValidator::validatePassword($password)->isError())
            error_log("Password is invalid");

        $verificationToken = md5(time() . $name);

        DatabaseManager::executeWithArgs(
            "INSERT INTO users (name, email, password, verification_token) values(?, ?, ?, ?)",
            $name,
            $email,
            $password,
            $verificationToken
        );

        self::sendVerificationEmail($name, $email, $verificationToken);
        return true;
    }

    private static function sendVerificationEmail(string $name, string $email, string $token) {
        $to = $email;

        $subject = "Camagru verification";

        $link = UserManager::generateVerificationLink($name, $token);
        $message = "Follow <a href='$link'>this link</a> to finish registration!";

        $headers = "From: Sender Name <admin@camagry.com>\r\n";
        $headers .= "Content-type: text/html\r\n";

        error_log("Sending email to " . $email);

        if (!mail($to, $subject, $message, $headers))
            error_log("Failed to send email to " . $email);
    }

    private static function generateVerificationLink(string $name, string $token): string {
        return "http://localhost/index.php?script=verifyUser&name=$name&token=$token";
    }

    public static function findUser(string $name): ?UserData {
        $result = DatabaseManager::executeWithArgs("SELECT * FROM users WHERE name = ?", $name);
        if (!$result->checkNumberOfRows(function($number){ return $number == 1; }))
            return null;

        $row = $result->getNextRow();
        return new UserData(
            $row["name"],
            $row["email"],
            $row["password"],
            $row["verification_token"],
            (bool)$row["isVerified"]
        );
    }

    public static function checkUser(string $name, string $password): Status {
        $user = UserManager::findUser($name);
        if ($user == null)
            return Status::makeError("User not found");

        if ($user->getPassword() != $password)
            return Status::makeError("Invalid password");

        return Status::makeOk();
    }

    public static function verifyUser(string $name, string $token): bool {
        $user = self::findUser($name);
        if ($user == null)
            return false;

        if ($user->getVerificationToken() != $token)
            return false;

        DatabaseManager::executeWithArgs("UPDATE users SET is_verified=1 WHERE name=?", $name);
        return true;
    }

    public static function isVerified(string $name): ?bool {
        $result = DatabaseManager::executeWithArgs("SELECT * FROM users WHERE name=?", $name);
        if (!$result->checkNumberOfRows(function($number){ return $number == 1; }))
            return null;

        $row = $result->getNextRow();
        return $row["is_verified"];
    }
}