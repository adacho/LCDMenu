#ifndef LCDMenu_h
#define LCDMenu_h
#include <LiquidCrystal.h>
#include "LCDMenuItem.h"

class LCDMenu{
  int Index;
  protected:
    String Name;
	LCDMenuItem *menuFirst;
	LCDMenuItem *menuLast;
	LCDMenuItem *menuCurrent;
    void setName (String);
	void addMenuItem (LCDMenuItem *);
  public: 
    LCDMenu(String);
}; 

#endif