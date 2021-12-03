<?php
	if(isset($_GET['channel']) && isset($_GET['state'])){
		include 'koneksi.php';
		$state = $_GET['state'];
		$channel = $_GET['channel'];

		if($channel == '1'){
			mysqli_query($dbconnect, "UPDATE tb_control SET control1='$state'");
		}if($channel == '2' ){
			mysqli_query($dbconnect, "UPDATE tb_control SET control2='$state'");
		}
  
  	header ('location: index.php');
		exit;                                                                       
	}
 ?>