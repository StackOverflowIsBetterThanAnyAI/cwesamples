<?php

$user_name = $argv[1];

function unsafe($user_name) {
    $stmt = $pdo->prepare("SELECT * FROM utilisateurs WHERE user_name = '" + $user_name + "'");
    $stmt->execute();
}

function safe($user_name) {
    $stmt = $pdo->prepare("SELECT * FROM utilisateurs WHERE user_name = :user_name");
    $stmt->bindParam(':user_name', $user_name);
    $stmt->execute();
}

unsafe($user_name);
safe($user_name);
?>
