// Ns, number of samples. Ns = samplingWindow / deltaS (see audio-basic-receiver)
#define deltaS 10
#define samplingWindow 1000

void setup() {
    Serial.begin(9600);
    Serial.println("waiting 5s...");
    delay(5000);
}

void loop() {
  String payload = "";
  char *str = new char[2];
  String sub = "";
  int i = 0;
  int value;
  long int startTime;
  startTime = millis();
  // collect data at the given sampling rate
  while ( millis()-startTime < samplingWindow ) {
      //data[i] = analogRead(A0);
      value=random(0,26);
      sprintf(str, "%2d", value);
      payload.concat(str);
      delay(deltaS);
  }
  Serial.println("---");
  Serial.print("payload: ");
  Serial.println(payload);
  Serial.println("---");
  // send data to the cloud
  // Particle.publish(const char *eventName, const char *data);
  // Particle.publish(String eventName, String data);
  Particle.publish("audio", payload);
  Serial.println("Data have been sent to the cloud.");
}
