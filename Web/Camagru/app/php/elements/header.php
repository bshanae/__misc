<header id="header">
    <div id="logo">
        <a href="http://localhost">Camagru</a>
    </div>
    <div id="navigation">
        <ul>
            <?php
            require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/NavigationTools.php");
            require_once($_SERVER["DOCUMENT_ROOT"] . "/php/tools/user/UserSession.php");

            if (UserSession::isSignedIn())
                contentForSignedInUser();
            else
                contentForUnknownUser();

            function contentForSignedInUser() {
                $signInLink = NavigationTools::generateLink("content", "signIn");

                echo "<li>";
                echo "    <a href=\"$signInLink\">";
                echo "        <img src=\"data/images/elements/photo-camera.svg\" alt=\"Take photo\" title=\"Take photo\">";
                echo "    </a>";
                echo "</li>";

                $profileLink = NavigationTools::generateLink("content", "profile");

                echo "<li>";
                echo "    <a href=\"$profileLink\">";
                echo "        <img src=\"data/images/elements/user-profile.svg\" alt=\"Profile\" title=\"Profile\">";
                echo "    </a>";
                echo "</li>";

                $signOutLink = NavigationTools::generateLink("content", "signOut");

                echo "<li>";
                echo "    <a href=\"$signOutLink\">";
                echo "        <img src=\"data/images/elements/sign-out.svg\" alt=\"Log out\" title=\"Sign out\">";
                echo "    </a>";
                echo "</li>";
            }

            function contentForUnknownUser() {
                $signInLink = NavigationTools::generateLink("content", "signIn");

                echo "<li>";
                echo "    <a href=\"$signInLink\">";
                echo "        <img src=\"data/images/elements/sign-in.svg\" alt=\"Log in\" title=\"Sign in\">";
                echo "    </a>";
                echo "</li>";
            }
            ?>
        </ul>
    </div>
</header>