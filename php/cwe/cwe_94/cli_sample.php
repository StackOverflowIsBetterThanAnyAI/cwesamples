<?php

/*
Source :
https://cwe.mitre.org/data/definitions/94.html
*/

$file = $argv[1];

function unsafe($action, $name, $message) {
    $MessageFile = "messages.out";
    if ($action == "NewMessage") {
        $handle = fopen($MessageFile, "a+");
        fwrite($handle, "<b>$name</b> says '$message'<hr>\n");
        fclose($handle);
        echo "Message Saved!<p>\n";
    }
    else if (action == "ViewMessages") {
        include($MessageFile);
    }
}

function safe($file) {
}


unsafe($file);
safe($file);
?>
