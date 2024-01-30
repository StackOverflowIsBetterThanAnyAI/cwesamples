<?php

session_start();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $csrfToken = $_POST['csrfToken'];
    if (!empty($csrfToken) && hash_equals($_SESSION['csrfToken'], $csrfToken)) {
        // Le jeton CSRF est valide, procédez au changement de mot de passe
        // ...
        echo "Mot de passe changé avec succès!";
    } else {
        // Le jeton CSRF est invalide, rejetez la requête
        http_response_code(403); // Code d'erreur d'accès interdit
        echo "Erreur de vérification CSRF!";
    }
}
else {
    $csrfToken = bin2hex(random_bytes(32)); // Génération d'un jeton CSRF aléatoire
    $_SESSION['csrfToken'] = $csrfToken;
}


?>

<form method="post" action="changepassword.php">
    <input type="hidden" name="csrfToken" value="<?php echo $csrfToken; ?>">
    <!-- ... autres champs du formulaire ... -->
    <input type="submit" value="Changer le mot de passe">
</form>