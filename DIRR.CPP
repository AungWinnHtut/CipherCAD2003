#include"aung.h"

void MAINMENU(int s);
void Msgbox();
void menu_dirr(int pos); //defaultvalue
int  button_dirr(int s);
void HELP();
char *current_directory(char *path);


struct ffblk ffblk;
int done;
char fname_dirr[100];




const int size_dirr=4;
char list_dirr[size_dirr][19]= {"    OK    \0",
			  "   CANCEL   \0",
			  "   HELP  \0",
			  "  EXIT   \0"
			 };



void DIRR()
{
   clrscr();
   char curdir[MAXPATH];
   int i=1,j=1;

   Window(1,1,80,25,BLACK);
   Window(20,4,60,8,BLUE);
   Label(1,1,RED,BLUE,"D");
   Label(2,1,WHITE,BLUE,"irectory       Programmer Aung Win Htut ");
   Window(20,5,60,8,5);
   Label(4,1,YELLOW,5,"Filename");
   menu_dirr(0);

   Window(20,6,60,7,5);
   Datafield(3,1,"                                      ");

   gotoxy(3,1);
   gets(fname_dirr);


   button_dirr(1);
   _setcursortype(_NOCURSOR);
   Window(15,12,65,25,1);
   current_directory(curdir);
   gotoxy(1,1);
   printf("Directory listing of %s",fname_dirr);
   gotoxy(1,2);
   printf("Current Directory is  %s",curdir);

   Label(15,14,4,3,"Press any key to EXIT");
   done = findfirst(fname_dirr,&ffblk,0);
   Window(15,14,65,25,1);
   while (!done&&!kbhit())
   {
      gotoxy(1,i);
      textcolor(3);
      textbackground(1);
      cprintf("%d   %s\n",j, ffblk.ff_name);
      done = findnext(&ffblk);
      delay(400);
      i++;
      j++;
      if(i==11)
       {
	 i=1;
	 Window(15,14,65,25,1);
	 Label(15,12,4,2,"Press any key to EXIT");
       }
       Label(15,12,4,2,"Press any key to EXIT");
   }
   gotoxy(15,12);
   textcolor(1);
   textbackground(3);
   cprintf("Total Files ==> %d  files",j-1);
   _setcursortype(_NOCURSOR);
   getch();


}

int button_dirr(int s)
{
     int index = s,n;
     char ch;




     menu_dirr(index-1);
     do{
	 _setcursortype(_NOCURSOR);
	 ch = getch();
	 if(ch == char(0))
	    ch = getch();
	 switch(ch){

	      case char(27) :  return 0;

	      //====================================
	      case char(75) : index = (index == 1)    ? size_dirr : index-1;break;
	      case char(77) : index = (index == size_dirr) ? 1    : index+1;break;
	      case char(13) : switch(index){
				       case 1 : _setcursortype(_NORMALCURSOR);
						 return(0);

				       case 2 : _setcursortype(_NORMALCURSOR);
						DIRR();

				       case 3 : _setcursortype(_NORMALCURSOR);
						HELP();
						MAINMENU(2);
						break;

				       case 4 : _setcursortype(_NORMALCURSOR);
						exit(0);

				}
	 }
	 menu_dirr(index-1);


     } while ( ch != 13 || ch != 27 || ch != 6 || ch != 3 ||  ch != 27 );
 return 0;
}







void menu_dirr(int pos)
{


     int  i;

     Window(20,19,60,19,1);



     for ( i = 0; i<size_dirr; i++ ) {
	 if ( i == pos )
	    textbackground(4);
	    else
	    textbackground(1);
	    cprintf(list_dirr[i]);
     }
 }



char *current_directory(char *path)
{
   strcpy(path, "X:\\");      /* fill string with form of response: X:\ */
   path[0] = 'A' + getdisk();    /* replace X with current drive letter */
   getcurdir(0, path+3);  /* fill rest of string with current directory */
   return(path);
}


