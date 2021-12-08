<?php
$servername = "localhost";
$dbname = "db_hardwares";
$username = "root";
$password = "";

// connection
$conn = new mysqli($servername, $username, $password, $dbname);
// check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
strtotime("$row_reading_time + 4 hours");
$conn->close();


$sql = "SELECT id, sensor, location, data, reading_time FROM SensorData ORDER BY id DESC";
echo '<table cellspacing="5" cellpadding="5">
        <tr>
            <td>ID</td>
            <td>Sensor</td>
            <td>Location</td>
            <td>Data (cm)</td>
            <td>Timestamp</td>
        </tr>';

if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_sensor = $row["sensor"];
        $row_location = $row["location"];
        $row_distance = $row["data"];
        $row_reading_time = $row["reading_time"];
        echo '<tr>
            <td>' . $row_id . '</td>
            <td>' . $row_sensor . '</td>
            <td>' . $row_location . '</td>
            <td>' . $row_data . '</td>
            <td>' . $row_reading_time . '</td>
        </tr>';
    }
    $result->free();
}