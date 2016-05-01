// Ns, number of samples. Ns = samplingWindow / deltaS (see audio-basic-sender)
#define Ns 4

int *msg = new int[Ns];
bool analyze;

void setup() {
    Serial.begin(9600);
    Particle.subscribe("audio", readData);
}


void loop() {
}

void readData(const char *event, const char *data) {
    Serial.println("Collected data.");
    // decode
    char *str = new char[2*Ns];
    // convert char* to const char*
    strcpy(str,data);
    // convert char* to String
    String data_c = str;
    String sub = "";
    int j = 0;
    for ( int i=0; i<(2*Ns); i+=2 ) {
        sub = data_c.substring(i,i+2);
        char *subc = new char[2];
        // convert const char* to char*
        strcpy(subc,sub);
        msg[j++] = atoi(subc);
    }
    // print data
    Serial.printf("%d ", millis());
    for ( int k=0; k<j; k++ ) {
        Serial.printf("%d_", msg[k]);
    }
    Serial.println();
    Serial.println("---");
    analyze = true;
}
