#include <LiquidCrystal.h>
#include <LCDMenu.h>
#include <LCDMenuItem.h>

/*  
  This section of #define's as well as function read_LCD_buttons is copied (with one small change) from example
  available here: http://www.dfrobot.com/wiki/index.php?title=Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009)
*/

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5


int read_LCD_buttons()
{
  int adc_key_in = analogRead(0);      // read the value from the sensor 
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  if (adc_key_in < 50)   return btnRIGHT;  
  if (adc_key_in < 195)  return btnUP; 
  if (adc_key_in < 380)  return btnDOWN; 
  if (adc_key_in < 555)  return btnLEFT; 
  if (adc_key_in < 790)  return btnSELECT;   
  return btnNONE;  // when all others fail, return this...
}

LiquidCrystal* LCD;  //LCDMenu class requires LiquidCrystal to work, but can be easily modified to work with other libraries
LCDMenu* menu;       
int lastButton = 0;  // used in loop() to debounce reading from LCD shield's keypad (in my case Arduino LCD KeyPad Shield SKU: DFR0009)

void settingsAction()  //this function will be executed if you choose "Settings option".
{
  menu->getLCD()->clear();
  menu->getLCD()->setCursor(0,1);
  menu->getLCD()->print("Some settings...");
  
}

void setup()
{
  LCD = new LiquidCrystal(8, 9, 4, 5, 6, 7);
  LCD->clear();
  menu = new LCDMenu("Main Menu", LCD);        //menu gets created
  LCDMenuItem *newItem;
  newItem = new LCDMenuItem("Settings");       //lets define some menu entries
  newItem->setAction(&settingsAction);         //here function gets assigned to menu entry - it will be executed if you select this option (Settings)
  menu->addMenuItem(newItem);
  newItem = new LCDMenuItem("Distance");
  menu->addMenuItem(newItem);
  newItem = new LCDMenuItem("Humidity");
  menu->addMenuItem(newItem);
  newItem = new LCDMenuItem("Temperature");
  menu->addMenuItem(newItem);
}

void loop()
{
  int buttonState = read_LCD_buttons();
  if (buttonState != lastButton)
  {
    menu->getLCD()->setCursor(0,1); 
    switch (buttonState)
    {
    case btnUP : 
      menu->getLCD()->print(menu->next()->getName());
      break;
    case btnDOWN : 
      menu->getLCD()->print(menu->prev()->getName());
      break;
    case btnRIGHT : 
      menu->selectOption();
      break;  
    }
    lastButton = buttonState;
  }
}

