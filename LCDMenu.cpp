#include <LiquidCrystal.h>
#include "LCDMenu.h"
#include <String>

LCDMenu::LCDMenu(String newName)
{
  LiquidCrystal LCD(8, 9, 4, 5, 6, 7);
  Index = 0;
  setName(newName);
  menuFirst = NULL;
  menuLast = NULL;
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print(Name);
}

void LCDMenu::setName(String newName)
{
  Name = newName;
}

void LCDMenu::addMenuItem(LCDMenuItem *item)
{
	if (item != NULL)
	{
		if 	 (menuFirst == NULL)
		{
			menuFirst = menuLast = menuCurrent = item;
			menuFirst->setPrev(item);
			menuFirst->setNext(item);
		}
		else
		{
			menuLast->setNext(item);
			item->setPrev(menuLast);
			item->setNext(menuFirst);
			menuLast=item;
		}
	}
}