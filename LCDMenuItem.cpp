#include "LCDMenuItem.h"

LCDMenuItem::LCDMenuItem(String newName)
{
	setName(newName);
}

void LCDMenuItem::setName(String newName)
{
	Name = newName;
}

void LCDMenuItem::setNext(LCDMenuItem *item)
{
	Next = item;
}

void LCDMenuItem::setPrev(LCDMenuItem *item)
{
	Prev = item;
}