<?php

//Simpan dengan nama file panel.php
require "koneksi.php";

?>

<!doctype html>
<html lang="en">
<link rel="stylesheet" type="text/css" href="css/button.css">
<link rel="stylesheet" type="text/css" href="css/bg.css">
<link rel="stylesheet" type="text/css" href="css/tabel.css">

<head>
	<!-- Required meta tags -->
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<title>Data Tables</title>
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

	<a href="index.php"><button class="button-48" role="button"><span class="text" style="font-family:Lucida Console; font-size:22px;">Kembali</span></button></a>

	<a href="data-hapus.php"><button class="button-48" role="button"><span class="text" style="font-family:Lucida Console; font-size:22px;">Hapus Data</span></button></a>
	<table width=80% align="center">
		<tr>
			<td colspan="5" align="center">
				<font color=white size=15>LOG DATA TERSIMPAN
			</td>
		</tr>
	</table>
	<table width=80% align="center" style="border-collapse: collapse; overflow:hidden; box-shadow: 0 0 20px rgba(0,0,0,0.1);">
		<thead>
			<tr colspan="5" align="center" style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">
				<th style="font-family:Lucida Console; font-size:20px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">ID</th>
				<th style="font-family:Lucida Console; font-size:20px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">Waktu</th>
				<th style="font-family:Lucida Console; font-size:20px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">Nama Device</th>
				<th style="font-family:Lucida Console; font-size:20px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">Sensor 1</th>
				<th style="font-family:Lucida Console; font-size:20px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">Sensor 2</th>
				<th style="font-family:Lucida Console; font-size:20px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">Sensor 3</th>
			</tr>
		</thead>
		<tbody>
			<?php
			$datatampil = mysqli_query($dbconnect, "SELECT * from tb_save ORDER BY id DESC");
			$id = 1;
			foreach ($datatampil as $row) {
				echo "<tr class= bg-white >
					<td>$id</td>
					<td>" . $row['waktu'] . "</td>
					<td>" . $row['namadevice'] . "</td>
					<td>" . $row['sensor1'] . "</td>
					<td>" . $row['sensor2'] . "</td>
					<td>" . $row['sensor3'] . "</td>
					</tr>";
				$id++;
			}
			$dbconnect->close();
			?>
		</tbody>

	</table>

</body>

</html>