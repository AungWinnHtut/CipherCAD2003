#include"aung.h"

void MAINMENU(int s);
void Msgbox();
void menu_h(int pos); //defaultvalue
h_button(int s);
void SOUND();
DEL_WIN();



int D_H;
const int SIZE_H=1;

char LIST_CAP_H[SIZE_H][19]= {  "   O\0"   };
char LIST_H[SIZE_H][19]=     {   "K   \0"   };



void HELP()
{
   AA:
   randomize();
   D_H= random (1);
   window(D_H+7,D_H+5,D_H+67,D_H+21);
   textbackground(0);
   clrscr();

   window(D_H+6,D_H+4,D_H+66,D_H+20);
   textbackground(YELLOW);
   clrscr();


   textcolor(1);
   gotoxy(1,0);
   cprintf(" HELP System                                   Aung Win Htut");


   window(D_H+6,D_H+5,D_H+66,D_H+20);
   textbackground(3);
   clrscr();



   textcolor(1);
   gotoxy(6,2);
   cprintf("This software is written by Programmer Aung Win Htut.It");
   gotoxy(2,3);
   cprintf("is a result of one year experience in study of cryptography");
   gotoxy(2,4);
   cprintf("In this software,plain text are encrypt with two algorithms");
   gotoxy(2,5);
   cprintf("The first technique is Kasiski Method , a prussian military");
   gotoxy(2,6);
   cprintf("officier . He used this technique to encrypt their military");
   gotoxy(2,7);
   cprintf("information.The second algorithm is a simple transformation");
   gotoxy(2,8);
   cprintf("of plain text . Which  rearrange the position  of encrypted");
   gotoxy(2,9);
   cprintf("message in finite sequence . In this way  we  think  we can");
   gotoxy(2,10);
   cprintf("trick our opponet.If you don't beleive our assumption , you");
   gotoxy(2,11);
   cprintf("can test our software any way.");
   gotoxy(45,12);
   cprintf("Good Luck!");
   gotoxy(45,13);
   cprintf("Aung Win Htut");
   gotoxy(45,14);
   cprintf("( President )");
   gotoxy(45,15);
   cprintf("Hyper Generation");

   h_button(1);

}

h_button(int s)
{
     int index = s;
     char ch;




     menu_h(index-1);
     do{
	 _setcursortype(_NOCURSOR);
	 ch = getch();
	 if(ch == char(0))
	    ch = getch();
	 switch(ch){

	      case char(27) : // SOUND();
			       DEL_WIN();
			     //  Clrscr();
			     return(0);
	      //====================================
	      case char(75) : index = (index == 1)    ? SIZE_H : index-1;break;
	      case char(77) : index = (index == SIZE_H) ? 1    : index+1;break;
	      case char(13) : switch(index){
				       case 1 : _setcursortype(_NORMALCURSOR);
					      //	SOUND();
						DEL_WIN();
						return(0);


				       case 2 : _setcursortype(_NORMALCURSOR);
						DEL_WIN();
						return 0;


				}
	 }
	 menu_h(index-1);


     } while ( ch != 13 || ch != 27 || ch != 6 || ch != 3 ||  ch != 27 );
 return 0;
}

void menu_h(int pos) //defaultvalue
{

     int  i;

	 window(D_H+33-10,D_H+19,D_H+42-10,D_H+19);
	 textbackground(1);
	 clrscr();


     for ( i = 0; i<SIZE_H; i++ ) {





	 if ( i == pos )

	    textbackground(1);
	 else
	    textbackground(2);



	 gotoxy(2,1);
	 textcolor(10);
	 cprintf(LIST_CAP_H[i]);
	 textcolor(4);
	 cprintf(LIST_H[i]);

	}
}
DEL_WIN()
{
   window(2,4,77,23);
   textbackground(1);
   clrscr();
   return 0;
}