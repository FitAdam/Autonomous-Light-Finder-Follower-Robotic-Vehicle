#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display

Adafruit_SSD1306 display(128, 64);  // Create display

#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font

class Screen{
  public:
   Screen(){
    
    }
    void init(){
       // set up for the screen
      delay(3000);  // This delay is needed to let the display to initialize
    
      display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
    
      display.clearDisplay();  // Clear the buffer
    
      display.setTextColor(WHITE);  // Set color of the text
    
      display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3
    
      display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
      // To override this behavior (so text will run off the right side of the display - useful for
      // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
      // with setTextWrap(true).
    
      display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)
      
      }
    // function for display values from Temperature and Humidity Sensor
    void display_hum_temp(int hum, int temp)
    {
      display.clearDisplay();  // Clear the display so we can refresh
      display.setFont(&FreeMono9pt7b);  // Set a custom font
      display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0
      display.setCursor(0, 15);  // (x,y)
      display.println("Temp=");  // Text or value to print
      display.drawRoundRect(79, 0, 49, 27, 8, WHITE);  // Draw rectangle (x,y,width,height,color)
      display.setCursor(83, 20);  // (x,y)
      display.println(temp);
      display.setCursor(0, 50);  // (x,y)
      display.println("Hum=");
      display.drawRoundRect(79, 37, 49, 27, 8, WHITE);
      display.setCursor(83, 57); 
      display.println(hum);  // Text or value to print
      display.display();  // Print everything we set previously
    }

    void display_hello(){
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,28); // (x,y)
      display.println("H3ll0 Robots!");
      display.display();
      
    }
    
    void display_distance(int distance){
      // Display 
    display.clearDisplay();  // Clear the display so we can refresh
    display.setFont(&FreeMono9pt7b);  // Set a custom font
    display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0
     // Print text:
    display.setCursor(0, 15);  // (x,y)
    display.println("Distance: ");  // Text or value to print
    // Print variable with left alignment:
    display.setCursor(75, 40);  // (x,y)
    display.println(distance);  // Text or value to print
    display.display();  // Print everything we set previously
    }

    void display_looking_for_light(){
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,28); // (x,y)
      display.println("I am looking for light!");
      display.display();
      
    }
    void display_got_the_light(){
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,28); // (x,y)
      display.println("GOT THE LIGHT!");
      display.display();
      
    }
    void light_calibration(int level){
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,10); // (x,y)
      display.println("level of the light:");
      display.setCursor(0,35); // (x,y)
      display.println(level);
      display.setCursor(0,55); // (x,y)
      display.println("Press button when finished");
      display.display();
    }
    void speed_calibration(int tempo){
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,10); // (x,y)
      display.println("set up your speed:");
      display.setCursor(0,35); // (x,y)
      display.println(tempo);
      display.setCursor(0,55); // (x,y)
      display.println("Press button when finished");
      display.display();
    }
    
  };
