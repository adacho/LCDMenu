#include <LiquidCrystal.h>
#include <LCDMenu.h>
#include <LCDMenuItem.h>
void setup()
{
  LiquidCrystal* LCD;
  LCD = new LiquidCrystal(8, 9, 4, 5, 6, 7);
  LCD->clear();
  LCDMenu menu("Main Menu", LCD);
  LCDMenuItem *newItem;
  newItem = new LCDMenuItem("Ustawienia");
  menu.addMenuItem(newItem);
  newItem = new LCDMenuItem("Pomiar odl.");
  menu.addMenuItem(newItem);
  newItem = new LCDMenuItem("Pomiar wilg.");
  menu.addMenuItem(newItem);
  for (int i=0;i<3;i++)
  {
    menu.getLCD()->setCursor(0,1);
    menu.getLCD()->print(menu.next()->getName());
    delay (1000);
  }
}

void loop()
{
}