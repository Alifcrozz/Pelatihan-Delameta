<?php
require "koneksi.php";	

// sql to delete a record
$sql = "DELETE FROM tb_save";

if ($dbconnect->query($sql) === TRUE) {
  header("location:index.php");
} else {
  echo "Error deleting record: " . $koneksi->error;
}

$dbconnect->close();
// mengalihkan ke halaman index.php
header("location:index.php");
?>