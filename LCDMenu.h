#ifndef LCDMenu_h
#define LCDMenu_h
#include <LiquidCrystal.h>
#include "LCDMenuItem.h"

class LCDMenu{
  int Index;
  protected:
    String Name;
	LCDMenuItem* menuFirst;
	LCDMenuItem* menuLast;
    void setName (String);
	LiquidCrystal* LCD;
  public: 
    LCDMenu(String, LiquidCrystal*);
	LCDMenuItem* next();
	LCDMenuItem* prev();
	void addMenuItem (LCDMenuItem *);
	LCDMenuItem* menuCurrent;
	void setLCD(LiquidCrystal*);
	LiquidCrystal* getLCD();
}; 

#endif