<?php
include 'koneksi.php';
$data = query("SELECT * FROM tb_monitoring")[0];

?>

<!DOCTYPE html>

<html>

<head>
	<title></title>
</head>

<body>
	<table width=80% align="center">
		<tr>
			<td colspan="5" align="center">
				<font color=white size=20>Dashboard Monitoring
			</td>
		</tr>

		<tr>
			<center>
				<td style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">Nama Device</td>
			</center>
			<center>
				<td style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">WAKTU</td>
			</center>
			<center>
				<td style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">SENSOR 1</td>
			</center>
			<center>
				<td style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">SENSOR 2</td>
			</center>
			<center>
				<td style="font-family:Lucida Console; font-size:22px; padding: 15px; background-color: rgba(255,255,255,0.2); color: #fff; ">SENSOR 3</td>
			</center>
		</tr>

		<tr>
			<center>
				<td style="font-family:Lucida Console; font-size:20px; background-color: rgba(255,255,255,0.2); color: #fff; "><?= $data["namadevice"]; ?></td>
			</center>
			<center>
				<td style="font-family:Lucida Console; font-size:20px; background-color: rgba(255,255,255,0.2); color: #fff;"><?= $data["waktu"]; ?></td>
			</center>
			<center>
				<td style="font-family:Lucida Console; font-size:20px; background-color: rgba(255,255,255,0.2); color: #fff;"><?= $data["sensor1"]; ?></td>
			</center>
			<center>
				<td style="font-family:Lucida Console; font-size:20px; background-color: rgba(255,255,255,0.2); color: #fff;"><?= $data["sensor2"]; ?></td>
			</center>
			<center>
				<td style="font-family:Lucida Console; font-size:20px; background-color: rgba(255,255,255,0.2); color: #fff;"><?= $data["sensor3"]; ?></td>
			</center>
		</tr>
	</table>

	<br> </br>



</body>

</html>