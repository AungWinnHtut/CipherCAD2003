//msg_en.cpp
//aung win htut
//modified 1.12.2000
#include"aung.h"

void MAINMENU(int s);           //Function of TC5.CPP
void Msgbox();                  //Function of MSGBOX1.CPP
void menu_dn1(int pos); 	//defaultvalue
button_dn1(int s);              //Save,Cancel,Exit,Help
Getplaintext_dn1();   		//22.11.2000

//int countdn;
FILE *fi_dn1,
     *fk_dn1,
     *fo_dn1;

//char keydn[30];
char ifilename_dn1[20],
     keyfilename_dn1[20],
     ofilename_dn1[20];

const int size_dn1=4;
char list_dn1[size_dn1][19]= {" Save \0",
			    " Cancel \0",
			    " Exit \0",
			    " Help \0"
			  };
DN_1()
{
//   Window(1,1,80,25,BLACK);
   Window(20,4,60,17,BROWN);
   Label(1,1,RED,BROWN,"D");
   Label(2,1,WHITE,BROWN,"ata_Decryption  Programmer Aung Win Htut");
   Window(20,5,60,17,5);
   Label(2,1,YELLOW,5,"Cipher Text Filename");
   Label(2,5,YELLOW,5,"Plain Text Filename");
   Label(2,9,YELLOW,5,"Key File Name");
   Datafield(2,2,"                                       ");
   Datafield(2,6,"                                       ");
   Datafield(2,10,"                                       ");

   gotoxy(2,2);
   gets(ifilename_dn1);
   gotoxy(2,6);
   gets(ofilename_dn1);
   gotoxy(2,10);
   gets(keyfilename_dn1);
   //countdn=strlen(keydn)-1;

   fi_dn1=fopen(ifilename_dn1,"r");
   fo_dn1=fopen(ofilename_dn1,"w");
   fk_dn1=fopen(keyfilename_dn1,"r");

   Getplaintext_dn1();

   button_dn1(1);
    return 0;
}

  button_dn1(int s)
{
     int index = s;
     char ch;
	menu_dn1(index-1);
     do{
	 _setcursortype(_NOCURSOR);
	 ch = getch();
	 if(ch == char(0))
	    ch = getch();
	 switch(ch){
		 case char(27) : 	return(0);
	      //====================================
		 case char(75) : index = (index == 1)    ? size_dn1 : index-1;break;
		 case char(77) : index = (index == size_dn1) ? 1    : index+1;break;
		 case char(13) : switch(index){
				       case 1 : _setcursortype(_NORMALCURSOR);
						return(0);


				       case 2 : _setcursortype(_NORMALCURSOR);
						DN_1();


				       case 3 : _setcursortype(_NORMALCURSOR);
						 return(0);


					 case 4 : _setcursortype(_NORMALCURSOR);
						 return(0);

				}
	 }
	 menu_dn1(index-1);
     } while ( ch != 13 || ch != 27 || ch != 6 || ch != 3 ||  ch != 27 );
    return 0;
}



void menu_dn1(int pos)
{
	int  idn;
     Window(26,20,52,20,2) ;

	for ( idn = 0; idn<size_dn1; idn++ ) {
	 if ( idn == pos )
	    textbackground(4);
	    else
	    textbackground(2);
	    cprintf(list_dn1[idn]);
     }
 }
//8888888888888888888888888

Getplaintext_dn1()
{
	int cdn,key_dn1,
	    //COUNT=0,
	    i=0;
	int dn=0;

       do{
	   while( (cdn=fgetc(fi_dn1))!=EOF  &&  (key_dn1=fgetc(fk_dn1))!=EOF )
	   {
		  if(cdn=='\n')
			fprintf(fo_dn1,"%c",cdn);
		  else
			fprintf(fo_dn1,"%c",cdn-key_dn1);
		  i++;
	   }
	   //if(COUNT>35)COUNT=0;
	   dn++;
       }while(cdn!=EOF);

       fclose(fi_dn1);
       fclose(fk_dn1);
       fclose(fo_dn1);
       return 0;
 }
