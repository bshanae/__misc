<?php
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/database/DatabaseTools.php");
require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/database/DatabaseResponse.php");

class DatabaseManager {
    private static $serverName = "mysql";
    private static $userName = "root";
    private static $userPassword = "root";
    private static $dbName = "camagru";

    private static $connection;

    public static function connect() {
        DatabaseManager::$connection = mysqli_connect(
            DatabaseManager::$serverName,
            DatabaseManager::$userName,
            DatabaseManager::$userPassword,
            DatabaseManager::$dbName
        );

        if (DatabaseManager::$connection == false)
            error_log("[DatabaseManager] Can't connect to database. Error: " . mysqli_connect_error());
    }

    public static function execute(string $statement): DatabaseResponse {
        DatabaseManager::checkConnection();

        $result = mysqli_query(DatabaseManager::$connection, $statement);

        DatabaseManager::checkResult($result, $statement);
        return new DatabaseResponse($result);
    }

    public static function executeWithArgs(string $template, &$argument, &...$moreArguments): DatabaseResponse {
        DatabaseManager::checkConnection();

        $statement = mysqli_stmt_init(DatabaseManager::$connection);

        if (!mysqli_stmt_prepare($statement, $template)) {
            DatabaseManager::logError($template);
            return new DatabaseResponse(null);
        }

        mysqli_stmt_bind_param(
            $statement,
            DatabaseTools::collectArgumentsTypes($argument, ...$moreArguments),
            $argument,
            ...$moreArguments
        );

        mysqli_stmt_execute($statement);
        return new DatabaseResponse(mysqli_stmt_get_result($statement));
    }

    public static function getLastInsertedId(): int {
        return mysqli_insert_id(DatabaseManager::$connection);
    }

    private static function isConnected(): bool {
        return DatabaseManager::$connection instanceof mysqli;
    }

    private static function checkConnection() {
        if (!DatabaseManager::isConnected()) {
            error_log("[DatabaseManager] Connection is not set, fixing");
            DatabaseManager::connect();
        }
    }

    private static function logError(string $statement) {
        error_log("Couldn't execute sql request '$statement' : " . mysqli_error(DatabaseManager::$connection));
    }
}

DatabaseManager::connect();