#include <ESP8266WiFi.h>
#define DIM(arr) (sizeof (arr) / sizeof (arr)[0])

const char* ssids[] = { "Never gonna give you up", "Never gonna let you down", "Never gonna run around", "Never gonna make you cry", "Never gonna say goodbye", "Never gonna tell a lie" };
const char* pass = "pass_goes_here";
int currentssidno = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  const char* ssid = ssids[currentssidno];
  Serial.print("SSID: ");
  Serial.println(ssid);
  WiFi.softAP(ssid, pass);
  delay(5000);
  WiFi.softAPdisconnect(false);
  currentssidno = (currentssidno + 1) % DIM(ssids);
}
