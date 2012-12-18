#include "LCDMenuItem.h"

LCDMenuItem::LCDMenuItem(String newName)
{
	setName(newName);
}

void LCDMenuItem::setName(String newName)
{
	Name = newName;
}

String LCDMenuItem::getName()
{
	return Name;
}

void LCDMenuItem::setNext(LCDMenuItem *item)
{
	Next = item;
}

void LCDMenuItem::setPrev(LCDMenuItem *item)
{
	Prev = item;
}

LCDMenuItem* LCDMenuItem::getNext()
{
	return Next;
}

LCDMenuItem* LCDMenuItem::getPrev()
{
	return Prev;
}