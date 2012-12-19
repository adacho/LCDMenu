#include <LiquidCrystal.h>
#include "LCDMenu.h"

LCDMenu::LCDMenu(String newName, LiquidCrystal* newLCD)
{
  setName(newName);
  setLCD(newLCD);
  menuFirst = NULL;
  menuLast = NULL;
}

void LCDMenu::setName(String newName)
{
  Name = newName;
}
LCDMenuItem* LCDMenu::next()
{
	menuCurrent=menuCurrent->getNext();
	return menuCurrent;
}

LCDMenuItem* LCDMenu::prev()
{
	menuCurrent=menuCurrent->getPrev();
	return menuCurrent;
}

void LCDMenu::addMenuItem(LCDMenuItem* item)
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

void LCDMenu::setLCD(LiquidCrystal* newLCD)
{
	LCD=newLCD;
}

LiquidCrystal* LCDMenu::getLCD()
{
	return LCD;
}