<?php
$contentToStyle = [
    "signIn" => "sign-in",
    "signUp" => "sign-up",
    "signUpSuccess" => "sign-up",
    "gallery" => "?",
    "createPost" => "create-post",
    "post" => "post"
];

function linkStyle(string $styleName) {
    echo "<link rel=\"stylesheet\" href=\"css/$styleName.css\">";
}

linkStyle("common");
linkStyle("header");

if (isset($_GET["content"])) {
    if ($style = $contentToStyle[$_GET["content"]] ?? null)
        linkStyle($style);
}