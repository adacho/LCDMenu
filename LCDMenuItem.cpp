#include "LCDMenuItem.h"
#include <stdio.h>

LCDMenuItem::LCDMenuItem(String newName)
{
	setName(newName);
}

void LCDMenuItem::setName(String newName)
{
	char buffer[16];
	newName.toCharArray(buffer,16);
	snprintf(buffer, 15, "%s               ", buffer);
	Name=String(buffer);
	//Name=newName;
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