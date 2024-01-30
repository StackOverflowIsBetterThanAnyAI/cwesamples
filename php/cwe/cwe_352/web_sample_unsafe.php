<?php
// Page de changement de mot de passe
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $newPassword = $_POST['newPassword'];
    $userId = $_SESSION['userId'];

    // Change le mot de passe de l'utilisateur
    changePassword($userId, $newPassword);
    echo "Mot de passe changé avec succès!";
}
?>