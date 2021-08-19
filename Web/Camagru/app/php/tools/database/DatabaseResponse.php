<?php
class DatabaseResponse {
    private $nativeResult;

    public function __construct($nativeResult) {
        $this->nativeResult = $nativeResult;
    }

    public function checkNumberOfRows($predicate): bool {
        if (!$this->nativeResult)
            return false;

        return $predicate(mysqli_num_rows($this->nativeResult));
    }

    public function getNextRow() {
        return mysqli_fetch_assoc($this->nativeResult);
    }
}