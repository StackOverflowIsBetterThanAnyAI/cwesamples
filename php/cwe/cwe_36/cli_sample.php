<?php

$file = $argv[1];

function unsafe($file) {
    $filePath = 'cwe/cwe_36/' . $file;
    $content = file_get_contents($filePath);
    echo $content;
}

function safe($file) {
    $filePath = 'cwe/cwe_36/' . $file;

    $normalizedPath = realpath($filePath);

    if ($normalizedPath !== false && strpos($normalizedPath, 'cwe/cwe_36/') === 0) {
        // Le chemin est valide et sécurisé
        $content = file_get_contents($normalizedPath);
        echo $content;
        return;
    }
    // Gestion de l'erreur
    echo "Accès non autorisé.";
}


unsafe($file);
safe($file);
?>