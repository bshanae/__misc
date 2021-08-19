<div id="container">
    <h1>Sign in into Camagru</h1>

    <hr>

    <form action="php/scripts/signIn.php" method="POST">
        <label id="name">
            Name
            <br>
            <?php
            echo "<input type=\"text\" name=\"name\" placeholder=\"Your awesome name\"";

            if (isset($_GET["name"]))
                echo " value=" . urldecode($_GET["name"]);

            echo ">";
            ?>

        </label>

        <label id="password">
            Password
            <br>
            <input type="password" name="password" placeholder="Your super safe (maybe not) password">
        </label>

         <?php
            echo "<p id=\"error-message\">";

         if (isset($_GET["errorMessage"]))
             echo urldecode($_GET["errorMessage"]);

            echo "</p>";
         ?>

        <button type="submit" name="submit">Sign in</button>
    </form>

    <hr>

    <?php
    $signUpLink = NavigationTools::generateLink("content", "signUp");
    echo "<p id=\"sign-up-link\">Have no account? Sign up <a href=\"$signUpLink\">here</a>.</p>"
    ?>
</div>