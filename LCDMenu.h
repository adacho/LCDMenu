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

  public: 
    LCDMenu(String);
	LCDMenuItem* next();
	LCDMenuItem* prev();
	void addMenuItem (LCDMenuItem *);
	LCDMenuItem* menuCurrent;
}; 

#endif