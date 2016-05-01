unsigned int localPort = 8888;
unsigned int deltaT = 1000;

UDP Udp;

void setup() {
  Udp.begin(localPort);
  Serial.begin(9600);
}

void loop() {
    if (Udp.parsePacket() > 0) {
        // going to receive 4 samples from the trasmitter
        // Read first char of data received
        char c1 = Udp.read();
        char c2 = Udp.read();
        char c3 = Udp.read();
        char c4 = Udp.read();
        Serial.printlnf("%d %d %d %d",c1,c2,c3,c4);
    }
    delay(deltaT);
}
