#include <dht.h>

dht DHT;

class Humidity_sensor{
  
   int _dht11_pin;

   public:
      Humidity_sensor(int dht11_pin){
        _dht11_pin = dht11_pin;

        // pin mode for humidity sensor
        pinMode(_dht11_pin, INPUT); 
        
        }
        void get_humidity(){
          int chk = DHT.read11(_dht11_pin);
          delay(3000);
          Serial.println("temp: ");
          Serial.println(DHT.temperature);  // Text or value to print
          delay(3000);
          delay(3000);
          Serial.println("hum: ");
          Serial.println(DHT.humidity);  // Text or value to print
          delay(3000);
          
         }
  };
