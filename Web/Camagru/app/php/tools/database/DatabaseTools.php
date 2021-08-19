<?php
class DatabaseTools {
    public static function collectArgumentsTypes($argument, ...$moreArguments) : string {
        $argumentsTypes = DatabaseTools::getArgumentType($argument);

        foreach ($moreArguments as $anotherArguments)
            $argumentsTypes .= self::getArgumentType($anotherArguments);

        return $argumentsTypes;
    }

    private static function getArgumentType($argument) : string {
        if (is_int($argument)) {
            return "i";
        } elseif (is_string($argument)) {
            return "s";
        }  else {
            error_log("Error parsing argument of type " . gettype($argument));
            return "";
        }
    }
}
