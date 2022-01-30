
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
#define FIREBASE_HOST "jeevanrekhaiot-default-rtdb.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "7UbMIBX6uJeWpQZHvERn4c8uZSjTalecGVUmHGGx" //Your Firebase Database Secret goes here


#define WIFI_SSID "Yuvraj singh deora"                                               //WiFi SSID to which you want NodeMCU to connect
#define WIFI_PASSWORD "6376179619001"  //Password of your wifi network
#define ONE_WIRE_BUS 12
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

 
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int sensorPin = A0;                                // select the input pin for LDr
int sensorValue = 0;                               // variable to store the value coming from the sensor
int sensor1_data()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  return distance;
}

int sensor2_data(){
sensorValue = analogRead(sensorPin);                           // read the value from the sensor
Serial.println(sensorValue);                                    //prints the values coming from the sensor on the screen

delay (10);
return String(sensorValue);                                     // LDR DATA 
}
int sensor_4_data()
{
  int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 

if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
 Serial.println("  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 return myBPM;                        // Print the value inside of myBPM. 
}

  delay(20);                
}
// Declare global variable to store value
String val1=getsensor1_data();
String val2=getsensor2_data();
String val3=sensors.requestTemperatures(); // Send the command to get temperatures
String val4=getsensor4_data();
String val5=random(1,100);


void setup() {

Serial.begin(9600);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  delay(1000);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}
Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);           
}

void loop() { 

 Firebase.pushString("Sensor1", val1);                                  //setup path and send readings
 Serial.println(val1);
 if (Firebase.failed()) 
    {
 
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
  }
 Firebase.pushString("Sensor2", val2); 
 Serial.println(val2);
 Firebase.pushString("Sensor3", val3); 
 Serial.println(val3);//setup path and send readings
 Firebase.pushString("Sensor4", val4); 
 Serial.println(val4);
 Firebase.pushString("Sensor5", val5);      
 Serial.println(val5);//setup path and send readings

}

       
