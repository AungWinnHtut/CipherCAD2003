//EN_1.cpp
//Aung Win Htut
//1-modified 28.2.2001

#include"aung.h"

void MAINMENU(int s);               //Function of TC5.CPP
void Msgbox();                      //Function of MSGBOX1.CPP
void menu_en1(int pos); 	    //defaultvalue
button_en1(int s);                  //Save,Cancel,Exit,Help
putplaintext_en1();		    //1.12.2000  To Encrypt mag

//int    count;                     //KEY LENGTH not necessary
FILE   *fi_en1,                     //Pointer to input file
       *fo_en1,                     //Pointer to output file
       *fk_en1;                     //Pointer to key file

//char   key[30];                   //Array for encryption key
char   ifilename_en1[20],           //Input Plain Text File Name
       ofilename_en1[20],           //Ouput Cipher Text File Name
       keyfilename_en1[20];         //Key File Name
const int size_en1=4;               //No. of Buttons
char list_en1[size_en1][19]= {" Save \0",
			      " Cancel \0",
			      " Exit \0",
			      " Help \0"
			     };
//Main function
EN_1()
{
   Window(20,4,60,17,BROWN);      //Back ground window
   Label(1,1,RED,BROWN,"D");
   Label(2,1,WHITE,BROWN,"ata_Encryption  Programmer Aung Win Htut");

   Window(20,5,60,17,5);          //Fore ground window
   /*labels*/
   Label(2,1,YELLOW,5,"Plain Text Filename");
   Label(2,5,YELLOW,5,"Cipher Text Filename");
   Label(2,9,YELLOW,5,"Key Filename");
   /*fields*/
   Datafield(2, 2,"                                       ");
   Datafield(2, 6,"                                       ");
   Datafield(2,10,"                                       ");
   /*Read filenames and key*/
   gotoxy(2,2);
   gets(ifilename_en1);
   gotoxy(2,6);
   gets(ofilename_en1);
   gotoxy(2,10);
   gets(keyfilename_en1);

   /*open files*/
   fi_en1=fopen(ifilename_en1,"r");
   fo_en1=fopen(ofilename_en1,"w");
   fk_en1=fopen(keyfilename_en1,"r");
   /*encrypt*/
   putplaintext_en1();
   /*choose option*/
   button_en1(1);
   return 0;
}


 button_en1(int s)
{
     int index = s;
     char ch;
     menu_en1(index-1);
     do{
	 _setcursortype(_NOCURSOR);
	 ch = getch();
	 if(ch == char(0))
	    ch = getch();
	 switch(ch){
		 case char(27) :return (0);
		 //====================================
		 case char(75) : index = (index == 1)    ? size_en1 : index-1;break;
		 case char(77) : index = (index == size_en1) ? 1    : index+1;break;
		 case char(13) : switch(index){
					  case 1 : _setcursortype(_NORMALCURSOR);
						return (0);
					      //	break;

					  case 2 : _setcursortype(_NORMALCURSOR);
						EN_1 ();
					      //	break;

					  case 3 : _setcursortype(_NORMALCURSOR);
						 return (0);
					      //	 break;
				}
	 }
	 menu_en1(index-1);
	} while ( ch != 13 || ch != 27 || ch != 6 || ch != 3 ||  ch != 27 );
    return 0;
}



void menu_en1(int pos)
{
     int  i;
     Window(26,20,52,20,2) ;

     for ( i = 0; i<size_en1; i++ ) {
	 if ( i == pos )
	    textbackground(4);
	    else
	    textbackground(2);
	    cprintf(list_en1[i]);
     }
 }
//8888888888888888888888888

putplaintext_en1()
{
	  int c,key_en1,COUNT=0,i=0;
	  int d1=0;

       do{
	   while( (c=fgetc(fi_en1))!=EOF &&  (key_en1=fgetc(fk_en1))!=EOF )
	   {
		  if(c=='\n')
			fprintf(fo_en1,"%c",c);
		  else
			fprintf(fo_en1,"%c",c+key_en1);
		   i++;

	   }
	   if(COUNT>35)COUNT=0;
	   d1++;
       }while(c!=EOF);

       fclose(fi_en1);
       fclose(fk_en1);
       fclose(fo_en1);

       return 0;
 }
