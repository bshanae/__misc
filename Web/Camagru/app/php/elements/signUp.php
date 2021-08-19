<div id="container">
    <h1>Create an account in Camagru!</h1>

    <hr>

    <form action="php/scripts/signUp.php" method="POST">
        <label id="name">
            Name
            <br>
            <?php
            echo "<input type=\"text\" name=\"name\" placeholder=\"Your cool name\"";

            if (isset($_GET["errorField"]) and $_GET["errorField"] == "name")
                echo " class=error-input";

            if (isset($_GET["name"]))
                echo " value=\"" . urldecode($_GET["name"]) . "\"";

            echo ">";
            ?>

        </label>

        <label id="email">
            eMail
            <br>
            <?php
            echo "<input type=\"text\" name=\"email\" placeholder=\"Your amazing email\"";

            if (isset($_GET["errorField"]) and $_GET["errorField"] == "email")
                echo " class=error-input";

            if (isset($_GET["email"]))
                echo " value=" . urldecode($_GET["email"]);

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

        <button type="submit" name="submit">Sign up</button>
    </form>
</div>
<script>
    const nameInput = document.getElementById("name").children[1];
    const emailInput = document.getElementById("email").children[1];

    nameInput.addEventListener('input', () => { nameInput.classList.remove("error-input"); });
    emailInput.addEventListener('input', () => { emailInput.classList.remove("error-input"); });
</script>