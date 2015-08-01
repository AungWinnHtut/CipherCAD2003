#include "aung.h"
void CHANGE(char *dirname);



int CHANGE_DIR()
{
   char dirname[40];
   Window(20,10,60,15,5);
   Label(1,1,1,5,"Change Directory   Programmer< Aung Win Htut >");
   Window(20,11,60,15,3);
   Label(2,2,4,3,"Enter Path(Dir) Name");
   Datafield(2,3,"                                     ");
   gotoxy(2,3);
   gets(dirname);
   _setcursortype(_NOCURSOR);

   CHANGE(dirname);
   getch();
   return 0;
}

void CHANGE(char *dirname)
{
   char CD[100]="CD ";
   strcat(CD,dirname);
   Window(20,18,60,20,3);
   system(CD);
   _setcursortype(_NOCURSOR);

}

