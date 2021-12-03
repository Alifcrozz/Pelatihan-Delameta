
<?php 	

//Simpan dengan nama file koneksidb.php

$server       = "localhost";
$user         = "root";
$password     = "";
$database     = "db_dzikry"; //Nama Database di phpMyAdmin

$dbconnect      = mysqli_connect($server, $user, $password, $database);

function query($query) {
    global $dbconnect;
    $result = mysqli_query($dbconnect, $query );
    $box = [];
    while( $sql = mysqli_fetch_assoc($result) ){
    $box[] = $sql;
    }
    return $box;
}

  

 ?>