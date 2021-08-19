<?php
class Post {
    private $imageFile;
    private $text;
    private $numberOfLikes;
    private $isLikedByUser;

    public function __construct(
        string $imageFile,
        string $text,
        int $numberOfLikes,
        ?bool $isLikedByUser
    ) {
        $this->imageFile = $imageFile;
        $this->text = $text;
        $this->numberOfLikes = $numberOfLikes;
        $this->isLikedByUser = $isLikedByUser;
    }

    public function getImageFile(): string {
        return $this->imageFile;
    }

    public function getText(): string {
        return $this->text;
    }

    public function getNumberOfLikes(): int {
        return $this->numberOfLikes;
    }

    public function isLikedByUser(): ?bool {
        return $this->isLikedByUser;
    }
}