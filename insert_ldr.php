<?php
$host = "localhost"; // Nama host atau IP server
$user = "root"; // Username MySQL
$pass = ""; // Password MySQL
$name = "db_hardwares"; // Nama database MySQL
// Baca parameter get insert_suhu.php?suhu=x
$data_ldr = $_GET['data_ldr'];
// Buat koneksi ke database MySQL
$conn = new mysqli($host, $user, $pass, $name);
// Periksa apakah koneksi sudah berhasil
if ($conn->connect_error) {
    die("Koneksi gagal: " . $conn->connect_error);
}
// Perintah SQL untuk menyimpan data suhu ke tabel sensor
$sql = "INSERT INTO tb_esp (data_ldr) VALUES ('$data_ldr')";
// Jalankan dan periksa apakah perintah berhasil dijalankan
if ($conn->query($sql) === TRUE) {
} else {
}
echo "sukses"; // memberikan informasi bahwa proses insert data berhasil
echo "gagal"; // memberikan informasi bahwa proses insert data gagal
$conn->close();