#include <LiquidCrystal.h>
#include <LCDMenu.h>
#include <LCDMenuItem.h>
void setup()
{
  LCDMenu menu("Main Menu");
  LCDMenuItem *newItem;
  newItem = new LCDMenuItem("Ustawienia");
  menu.addMenuItem(newItem);
  newItem = new LCDMenuItem("Pomiar odl.");
  menu.addMenuItem(newItem);
  newItem = new LCDMenuItem("Pomiar wilg.");
  menu.addMenuItem(newItem);
  LiquidCrystal* LCD;
  LCD = new LiquidCrystal(8, 9, 4, 5, 6, 7);
  LCD->clear();
  for (int i=0;i<3;i++)
  {
    LCD->setCursor(0,0);
    LCD->print(menu.next()->getName());
    delay (1000);
  }
}

void loop()
{
}
