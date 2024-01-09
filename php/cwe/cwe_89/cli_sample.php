<?php

$user_name = $argv[1];

function unsafe($user_name) {
    $pdo = new PDO('sqlite:'.dirname(__FILE__).'/primtuxmenu.db');
    $select = "SELECT * FROM utilisateurs WHERE user_name = '" . $user_name . "'";
    echo $select;
    $stmt = $pdo->prepare($select);
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
