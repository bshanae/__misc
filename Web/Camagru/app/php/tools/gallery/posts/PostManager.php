<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/database/DatabaseManager.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserSession.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/gallery/posts/Post.php");

class PostManager {
    public static function addPost($imageFile, $text): int {
        DatabaseManager::executeWithArgs(
            "INSERT INTO posts (image_file, text) VALUES (?, ?)",
            $imageFile,
            $text
        );

        return DatabaseManager::getLastInsertedId();
    }

    public static function findPost(int $id): ?Post {
        $result = DatabaseManager::executeWithArgs("SELECT * FROM posts WHERE id=?", $id);
        if (!$result->checkNumberOfRows(function($number) { return $number == 1; }))
            return null;

        $row = $result->getNextRow();
        return new Post(
            $row["image_file"],
            $row["text"],
            $row["number_of_likes"],
            PostManager::isPostLikedByCurrentUser()
        );
    }

    public static function getPosts(int $page): ?array {
        $result = DatabaseManager::execute("SELECT * FROM posts ORDER BY time_created DESC");
        if (!$result->checkNumberOfRows(function($number) { return $number > 0; }))
            return null;

        $posts = array();
        while ($row = $result->getNextRow()) {
            $posts[] = new Post(
                $row["image_file"],
                $row["text"],
                $row["number_of_likes"],
                PostManager::isPostLikedByCurrentUser()
            );
        }

        return $posts;
    }

    private static function isPostLikedByCurrentUser(): ?bool {
        if (!UserSession::isSignedIn())
            return null;

        $user_id = UserSession::getUserId();

        $result = DatabaseManager::executeWithArgs(
            "SELECT * FROM likes WHERE user_id=?",
            $user_id
        );

        if (!$result->checkNumberOfRows(function($number) { return $number > 0; }))
            return null;

        $row = $result->getNextRow();
        return $row["total"];
    }
}