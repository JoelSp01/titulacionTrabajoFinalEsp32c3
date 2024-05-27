/*   Multiple Serial test for XIAO ESP32C3 */
HardwareSerial MySerial(0);  //Create a new HardwareSerial class.

int data_h;
int data_l;
int temp_h;
int temp_l;


char buffer[20];

int Star;
int Data_h;
int Data_l;
int Temp_h;
int Temp_l;
int Rssi_h;
int Rssi_l;
int Angle_h;
int Angle_l;
int Sum;

void setup() {
  // initialize both serial ports:
  Serial.begin(115200);
  MySerial.begin(115200, SERIAL_8N1, RX, TX);  // at CPU Freq is 40MHz, work half speed of defined.
  Serial.println("Hola");
}

void loop() {

  //MySerial.readBytes()
  //Serial.println(a);

  if (MySerial.available()) {

    int bytesLeidos = MySerial.read();
    if (bytesLeidos == 0xFF) {
      Data_h = MySerial.read();
      Data_l = MySerial.read();
      Temp_h = MySerial.read();
      Temp_l = MySerial.read();
      Rssi_h = MySerial.read();
      Rssi_l = MySerial.read();
      Angle_h = MySerial.read();
      Angle_l = MySerial.read();
      Sum = MySerial.read();
    }
    //datos[i] = str;
    Serial.println(bytesLeidos);
    //  Serial.println(buffer);
    // Serial.println(datos);


    /* int data_h=datos[0];
  int data_l=datos[1];
  float temp_h=datos[2];
  float temp_l=datos[3];
*/
  }
  Serial.println("Data_h: ");
  Serial.println(Data_h);
  Serial.println("Data_l: ");
  Serial.println(Data_l);
  Serial.println(Temp_h);
  Serial.println(Temp_l);
  Serial.println(Rssi_h);
  Serial.println(Rssi_l);
  Serial.println(Angle_h);
  Serial.println(Angle_l);
  Serial.println(Sum);

  int level = Data_h * 256 + Data_l;
  float temp = (Temp_h * 256 + Temp_l) / 10;
  Serial.print("level = ");
  Serial.println(level);

  Serial.print("temp = ");
  Serial.println(temp);
  delay(9000);
}