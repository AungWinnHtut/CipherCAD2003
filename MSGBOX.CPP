#include"aung.h"


void MAINMENU(int s);
void Msgbox();
void menu_1(int pos); //defaultvalue
void BUTTON(int s);
void SOUND();



int d;
const int size_1=3;
char list_1[size_1][19]= {"es  \0",
			  "o  \0",
			  "ancel \0"};

char list_Cap_1[size_1][19]= {"  Y\0",
			      "  N\0",
			      " C\0"
			    };











void Msgbox()

{
   //system("del cipher.exe");
   AA:
   randomize();
   d= random (15);
   window(d+21,d+6,d+46,d+9);
   textbackground(0);
   clrscr();

   window(d+20,d+5,d+45,d+8);
   textbackground(YELLOW);
   clrscr();


   textcolor(4);
   gotoxy(1,0);
   cprintf("WARNING");


    window(d+20,d+6,d+45,d+8);
   textbackground(5);
   clrscr();



   gotoxy(2,1);
   textcolor(1);
   cprintf("Are you sure to exit ?:");
   BUTTON(1);





}

void BUTTON(int s)
{
     int index = s;
     char ch;




     menu_1(index-1);
     do{
	 _setcursortype(_NOCURSOR);
	 ch = getch();
	 if(ch == char(0))
	    ch = getch();
	 switch(ch){

	      case char(27) :  SOUND();
			       Clrscr();
			       exit(0);
	      //====================================
	      case char(75) : index = (index == 1)    ? size_1 : index-1;break;
	      case char(77) : index = (index == size_1) ? 1    : index+1;break;
	      case char(13) : switch(index){
				       case 1 :
						SOUND();
						Clrscr();
						_setcursortype(_NOCURSOR);
						exit(0);
						break;

				       case 2 :
						MAINMENU(1);
						break;
				       case 3 :
						MAINMENU(1);
						break;

				}
	 }
	 menu_1(index-1);


     } while ( ch != 13 || ch != 27 || ch != 6 || ch != 3 ||  ch != 27 );

}

void menu_1(int pos) //defaultvalue
{

     int row=7, i;

	 window(d+20,d+7,d+45,d+8);
	 textbackground(5);
	 clrscr();


     for ( i = 0; i<size_1; i++ ) {





	 if ( i == pos )

	    textbackground(2);
	 else
	    textbackground(5);



	 gotoxy(row*i+3,1);
	 textcolor(10);
	 cprintf(list_Cap_1[i]);
	 textcolor(0);
	 cprintf(list_1[i]);

}
    }


