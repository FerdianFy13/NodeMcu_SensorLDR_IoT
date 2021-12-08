#include <ESP8266WiFi.h>

const char* ssid = "SYKRNDPFF"; //nama wifi
const char* password = "bayardulu"; //password
const char* host = "192.168.0.102"; //IP PC server
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
delay(1);
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() !=WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}
void loop() {
  //put your main code here, to run repeatedly:
  int ldr=analogRead(A0);
  Serial.println("Koneksi ke SERVER dimulai ");
  Serial.print("IP Server : ");
  Serial.println(host);
  WiFiClient client;
  Serial.print("LDR : ");
  Serial.println(ldr);
  delay(5000);
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("Koneksi GAGAL");
    return;
  }
    //membuat URL untuk koneksi ke server
    String url = "/hardware/insert_ldr.php?";
    url += "data_ldr="; url += ldr;
    Serial.print("URL: ");
    Serial.println(url);
    //This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" +"connection: close\r\n\r\n");
    // memberi batas waktu
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Batas waktu koneksi HABIS ! <<<<");
        Serial.println(">>> koneksi dihentikan ! <<<<");
        client.stop();
        return;
      }
    }
        // membaca balasan server dan menampilkan ke monitor menggunakan Serial
        while (client.available()) {
          String line = client.readStringUntil('r');
          //Serial.print(line);
          if (line.indexOf("sukses") != -1) {
            Serial.println();
            Serial.println("INSERT DATA BERHASIL");
          } else if (line.indexOf("gagal") != -1) {
            Serial.println();
            Serial.print("Maaf, INSERT data tidak berhasil");
          }
        }
        Serial.println();
        Serial.println("Koneksi database dihentikan");
        delay(10000);
      }
        
