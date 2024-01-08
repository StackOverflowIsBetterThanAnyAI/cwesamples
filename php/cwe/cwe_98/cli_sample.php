<?php

/*
Source :
https://cwe.mitre.org/data/definitions/98.html
*/

$file = $argv[1];

function unsafe($file) {
    $dir = $_GET['module_name'];
    include($dir . "/function.php");
}

function safe($file) {
}


unsafe($file);
safe($file);
?>
