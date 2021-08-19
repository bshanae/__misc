<?php

class UserData
{
    private $name;
    private $email;
    private $password;
    private $verificationToken;
    private $isVerified;

    public function __construct(
        string $name,
        string $email,
        string $password,
        string $verificationToken,
        bool $isVerified
    ) {
        $this->name = $name;
        $this->email = $email;
        $this->password = $password;
        $this->verificationToken = $verificationToken;
        $this->isVerified = $isVerified;
    }

    public function getName(): string {
        return $this->name;
    }

    public function getEmail(): string {
        return $this->email;
    }

    public function getPassword(): string {
        return $this->password;
    }

    public function getVerificationToken(): string {
        return $this->verificationToken;
    }

    public function getIsVerified(): bool {
        return $this->isVerified;
    }
}