<?php

$file = $argv[1];

function unsafe($file) {
}

function safe($file) {
    $userInput = $_GET['user_input'];

    // Échapper les caractères spéciaux pour éviter les séquences CRLF
    $safeInput = str_replace(["\r", "\n"], '', $userInput);

    // Utiliser $safeInput dans les en-têtes HTTP
}


unsafe($file);
safe($file);
?>
