// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int LED_1 = 2;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
 pinMode (LED_1, OUTPUT);
  
}

void loop() {
 
  
  int distance = sonar.ping_cm();
  // if distance is less than 15cm, turn the flash on. Else, do nothing.
  if(distance <= 15)
  {
      digitalWrite (LED_1 , HIGH);
      delay (100);
      digitalWrite (LED_1 , LOW);
      delay(100);
    
   }
   else{
    digitalWrite(LED_1, LOW);
    }

                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}
