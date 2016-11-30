#include <allegro.h>

int getMenuSize();

/* Displays the main menu on the screen */
void menu_displayMenu (BITMAP* target); 

/* Performs the correct action regarding the selected menu item */
void menu_itemSelected();

/* Updates the menuSelectedIndex upon key strokes */
void menu_updateMenu();

/* Menu on-select actions functions*/
void menu_newGameAction();
void menu_optionsAction();
void menu_quitAction();
void menu_debugAction();
