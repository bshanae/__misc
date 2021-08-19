<?php
class Status {
    public static function makeOk(): Status {
        return new Status(true);
    }

    public static function makeError(string $message): Status {
        return new Status(false, $message);
    }

    private $isOk;
    private $message;

    private function __construct(bool $isOk, ?string $message = null) {
        $this->isOk = $isOk;
        $this->message = $message;
    }

    public function isOk(): bool {
        return $this->isOk;
    }

    public function isError(): bool {
        return !$this->isOk();
    }

    public function getMessage(): ?string {
        return $this->message;
    }
}