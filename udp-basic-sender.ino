UDP Udp;

unsigned int Ns = 4; // Ns=100
unsigned int deltaT = 1000;
unsigned int localPort = 8888;
unsigned char msg[4] = { 65, 125, 'a', 'B'};

void setup() {
    Serial.begin(9600);
    Udp.begin(localPort);
}

void loop() {
  // open connection and send data
  if ( WiFi.ready() ) {
    Udp.beginPacket(IPAddress(192,168,0,198),localPort);
    Udp.write(msg, Ns);
    Udp.endPacket();
    Serial.print("Sender: packet has been sent, msg[0]=");
    Serial.println(msg[0]);
  }
  delay(deltaT);
}
