#include"AUNG.H"

void menu(char CAP[19][19],char menu[19][19],int size,int pos=0) //defaultvalue
{
     int col=1;         //Initial defult value for ROW
     int i;             //Local LOOPING COUNTER

     Window(1,1,80,1,7);//Creat WINDOW
     //MENU WRITE ROUTING
     for ( i = 0; i<size; i++ ) {
	 //HELIGHT THE SELECTED MENU{Choose green background color}
	 //Other MENU white color as text color
	 if ( i == pos )
	    {textbackground(2);}
	 else
	    {textbackground(7);}
	 //goto required menu location
	 //IMPORTANT!!! it is not by row position it is by col
	 gotoxy(1,col*i+1);
	 //choose text color
	 textcolor(4);
	 cprintf(CAP[i]);
	 textcolor(0);
	 cprintf(menu[i]);
     }
}