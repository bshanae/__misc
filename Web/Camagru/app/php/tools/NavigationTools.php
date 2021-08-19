<?php
class NavigationTools {
    public static function redirectToHomePage() {
        NavigationTools::redirect("content", "home");
    }

    public static function redirectToErrorPage() {
        NavigationTools::redirect("content", "error");
    }

    public static function redirect(string ... $params) {
        $link = NavigationTools::generateLink(...$params);
        if ($link == null)
            return;

        header("Location: $link");
        exit();
    }

    public static function generateLink(string ... $params): ?string {
        if (count($params) % 2 != 0) {
            error_log("Invalid params for redirection");
            return null;
        }

        $url = "http://localhost";

        $isFirstParam = true;
        for ($i = 0; $i < count($params); $i += 2) {
            $url .= $isFirstParam ? "?" : "&";

            $url .= urlencode($params[$i]);
            $url .= "=";
            $url .= urlencode($params[$i + 1]);

            $isFirstParam = false;
        }

        return $url;
    }
}