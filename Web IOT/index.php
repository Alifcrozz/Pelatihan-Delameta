<?php

//Simpan dengan nama file panel.php
require "koneksi.php";
$sql = mysqli_query($dbconnect, "SELECT * FROM tb_control");
while ($row = mysqli_fetch_assoc($sql)) {
?>

	<!doctype html>
	<html lang="en">
	<link rel="stylesheet" type="text/css" href="css/button.css">
	<link rel="stylesheet" type="text/css" href="css/bg.css">

	<head>
		<!-- Required meta tags -->
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

		<!-- Bootstrap CSS -->
		<title>Dashboard IOT</title>
	</head>

	<body align="center">
		<div id="mainCoantiner">
			<!--dust particel-->
			<div class="margin-body">

				<div>
					<div class="starsec"></div>
					<div class="starthird"></div>
					<div class="starfourth"></div>
					<div class="starfifth"></div>
				</div>
				<!--Dust particle end--->


			</div>
		</div>

		<center><img src="img/icon.png"></center>

		<br></br>

		<div class="load-data"></div>
		<table width=80% align="center" style="border-collapse: collapse; overflow:hidden; box-shadow: 0 0 20px rgba(0,0,0,0.1);">
			<tr>

			<tr>
				<td align="center" style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">CONTROL 1 | <?php if ($row['control1'] == '0') {
																																												$state = 'OFF';
																																											} else {
																																												$state = 'ON';
																																											}
																																											echo "STATUS = " . $state; ?></td>
				<td align="center" style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">CONTROL 2 | <?php if ($row['control2'] == '0') {
																																												$state = 'OFF';
																																											} else {
																																												$state = 'ON';
																																											}
																																											echo "STATUS = " . $state; ?></td>
				<td align="center" style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">CONTROL 3 | <?php if ($row['control3'] == '0') {
																																												$state = 'OFF';
																																											} else {
																																												$state = 'ON';
																																											}
																																											echo "STATUS = " . $state; ?></td>
			</tr>

			<tr>
				<td align="center">
					<a class="btn" href="aksikontrol.php?channel=1&state=1"><img src="img/nyala.png" height="100" width="100"></a>
					<a class="btn" href="aksikontrol.php?channel=1&state=0"><img src="img/mati.png" height="100" width="100"></a>
				</td>

				<td align="center">
					<a class="btn" href="aksikontrol.php?channel=2&state=1"><img src="img/nyala.png" height="100" width="100"></a>
					<a class="btn" href="aksikontrol.php?channel=2&state=0"><img src="img/mati.png" height="100" width="100"></a>
				</td>

				<td align="center">
					<a class="btn" href="aksikontrol.php?channel=3&state=1"><img src="img/nyala.png" height="100" width="100"></a>
					<a class="btn" href="aksikontrol.php?channel=3&state=0"><img src="img/mati.png" height="100" width="100"></a>
				</td>
			</tr>
			</tr>
		</table>
		<br></br>

	<?php
}
	?>

	<a href="data-tampil.php"><button class="button-48" role="button"><span class="text" style="font-family:Lucida Console; font-size:22px;">Log Data</span></button></a>

	<script src="js/jquery-3.3.1.min.js"></script>
	<script src="js/script.js"></script>
	</body>

	</html>