#include "aung.h"
void SAVE_(char *filename_1,char *filename_2);

int SAVE()
{
   char filename_1[40];
   char filename_2[40];

   Window(20,10,60,15,5);
   Label(1,1,1,5,"SAVE_FILE   Programmer< Aung Win Htut >");
   Window(20,11,60,15,3);
   Label(2,2,4,3,"File Name1");
   Label(22,2,4,3,"File Name2");
   Datafield(2,3,"                 ");
   Datafield(22,3,"                 ");
   gotoxy(2,3);
   gets(filename_1);
   gotoxy(22,3);
   gets(filename_2);
   _setcursortype(_NOCURSOR);

   SAVE_(filename_1,filename_2);
   getch();
   return 0;
}

void SAVE_(char *filename_1,char *filename_2)
{
   char COPY__[100]="COPY  ";
   strcat(COPY__,filename_1);
   strcat(COPY__," ");
   strcat(COPY__,filename_2);
   Window(1,1,80,25,3);
   system(COPY__);
   _setcursortype(_NOCURSOR);
}

