//msg_en.cpp
//aung win htut
//modified 1.12.2000
#include"aung.h"

void MAINMENU(int s);           //Function of TC5.CPP
void Msgbox();                  //Function of MSGBOX1.CPP
void MENU_2(int pos); 		//defaultvalue
BUTTON4(int s);                 //Save,Cancel,Exit,Help
Getplaintext();   		//22.11.2000

int countdn;
FILE *fidn,
     *fodn;

char keydn[30];
char ifilenamedn[20],
     ofilenamedn[20];

const int size_dn=4;
char list_dn[size_dn][19]= {" Save \0",
			    " Cancel \0",
			    " Exit \0",
			    " Help \0"
			  };
K_DN()
{
//   Window(1,1,80,25,BLACK);
   Window(20,4,60,17,BROWN);
   Label(1,1,RED,BROWN,"D");
   Label(2,1,WHITE,BROWN,"ata_Decryption  Programmer Aung Win Htut");
   Window(20,5,60,17,5);
   Label(2,1,YELLOW,5,"Cipher Text Filename");
   Label(2,5,YELLOW,5,"Plain Text Filename");
   Label(2,9,YELLOW,5,"Decryption Key");
   Datafield(2,2,"                                       ");
   Datafield(2,6,"                                       ");
   Datafield(2,10,"                                       ");

   gotoxy(2,2);
   gets(ifilenamedn);
   gotoxy(2,6);
   gets(ofilenamedn);
   gotoxy(2,10);
   gets(keydn);
   countdn=strlen(keydn)-1;

   fidn=fopen(ifilenamedn,"r");
   fodn=fopen(ofilenamedn,"w");

   Getplaintext();

   BUTTON4(1);
    return 0;
}

  BUTTON4(int s)
{
     int index = s;
     char ch;
	MENU_2(index-1);
     do{
	 _setcursortype(_NOCURSOR);
	 ch = getch();
	 if(ch == char(0))
	    ch = getch();
	 switch(ch){
		 case char(27) : 	return(0);
	      //====================================
		 case char(75) : index = (index == 1)    ? size_dn : index-1;break;
		 case char(77) : index = (index == size_dn) ? 1    : index+1;break;
	      case char(13) : switch(index){
				       case 1 : _setcursortype(_NORMALCURSOR);
						return(0);
					       //	break;

				       case 2 : _setcursortype(_NORMALCURSOR);
						K_DN();
					      //	break;

				       case 3 : _setcursortype(_NORMALCURSOR);
						 return(0);
					      //	 break;

					 case 4 : _setcursortype(_NORMALCURSOR);
						 return(0);
					      //	 break;
				}
	 }
	 MENU_2(index-1);
     } while ( ch != 13 || ch != 27 || ch != 6 || ch != 3 ||  ch != 27 );
    return 0;
}



void MENU_2(int pos)
{
	int  idn;
     Window(26,20,52,20,2) ;

	for ( idn = 0; idn<size_dn; idn++ ) {
	 if ( idn == pos )
	    textbackground(4);
	    else
	    textbackground(2);
	    cprintf(list_dn[idn]);
     }
 }
//8888888888888888888888888

Getplaintext()
{
	int cdn,
	    //COUNT=0,
	    i=0;
	int dn=0;

       do{
	   while( (cdn=fgetc(fidn))!=EOF )
	   {
		  fprintf(fodn,"%c",cdn-keydn[dn]);
		  i++;
	   }
	   //if(COUNT>35)COUNT=0;
	   dn++;
       }while(cdn!=EOF);

       fclose(fidn);
       fclose(fodn);
       return 0;
 }
