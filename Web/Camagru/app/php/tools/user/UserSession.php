<?php
class UserSession {
    public static function getUserId(): string {
        return $_SESSION["user"];
    }

    public static function isSignedIn(): bool {
        return isset($_SESSION["user"]);
    }

    public static function signIn(string $name) {
        $_SESSION["user"] = $name;
    }
}