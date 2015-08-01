//msg_en.cpp
//Aung Win Htut
//1-modified 1.12.2000
//2-modified 26.2.2001
#include"aung.h"

void MAINMENU(int s);           //Function of TC5.CPP
void Msgbox();                  //Function of MSGBOX1.CPP
void menu_2(int pos); 		//defaultvalue
BUTTON1(int s);                 //Save,Cancel,Exit,Help
Putplaintext();			//1.12.2000  To Encrypt mag
//Getplaintext();   		//22.11.2000
//char *Strrev(char *string);	//15.1.2001

int    count;                   //KEY KENGTH not necessary
FILE   *fi,                     //Pointer to input file
       *fo;                     //Pointer to output file

char   key[30];                 //Array for encryption key
char   ifilename[20],           //Input Plain Text File Name
       ofilename[20];           //Ouput Cipher Text File Name

const int size_1=4;             //No. of Buttons
char list_2[size_1][19]= {" Save \0",
			  " Cancel \0",
			  " Exit \0",
			  " Help \0"
			 };
//Main function
K_EN()
{
   Window(20,4,60,17,BROWN);      //Back ground window
   Label(1,1,RED,BROWN,"D");
   Label(2,1,WHITE,BROWN,"ata_Encryption  Programmer Aung Win Htut");

   Window(20,5,60,17,5);          //Fore ground window
   /*labels*/
   Label(2,1,YELLOW,5,"Plain Text Filename");
   Label(2,5,YELLOW,5,"Cipher Text Filename");
   Label(2,9,YELLOW,5,"Decryption Key");
   /*fields*/
   Datafield(2,2,"                                       ");
   Datafield(2,6,"                                       ");
   Datafield(2,10,"                                       ");
   /*Read filenames and key*/
   gotoxy(2,2);
   gets(ifilename);
   gotoxy(2,6);
   gets(ofilename);
   gotoxy(2,10);
   gets(key);
   count=strlen(key)-1;
   /*open files*/
   fi=fopen(ifilename,"r");
   fo=fopen(ofilename,"w");
   /*encrypt*/
   Putplaintext();
   /*choose option*/
   BUTTON1(1);
   return 0;
}


 BUTTON1(int s)
{
     int index = s;
     char ch;
     menu_2(index-1);
     do{
	 _setcursortype(_NOCURSOR);
	 ch = getch();
	 if(ch == char(0))
	    ch = getch();
	 switch(ch){
		 case char(27) :return (0);
		 //====================================
		 case char(75) : index = (index == 1)    ? size_1 : index-1;break;
		 case char(77) : index = (index == size_1) ? 1    : index+1;break;
		 case char(13) : switch(index){
					  case 1 : _setcursortype(_NORMALCURSOR);
						return (0);
					      //	break;

					  case 2 : _setcursortype(_NORMALCURSOR);
						K_EN ();
					      //	break;

					  case 3 : _setcursortype(_NORMALCURSOR);
						 return (0);
					      //	 break;
				}
	 }
	 menu_2(index-1);
	} while ( ch != 13 || ch != 27 || ch != 6 || ch != 3 ||  ch != 27 );
    return 0;
}



void menu_2(int pos)
{
     int  i;
     Window(26,20,52,20,2) ;

     for ( i = 0; i<size_1; i++ ) {
	 if ( i == pos )
	    textbackground(4);
	    else
	    textbackground(2);
	    cprintf(list_2[i]);
     }
 }
//8888888888888888888888888

Putplaintext()
{
	  int c,COUNT=0,i=0;
	  int d1=0;

       do{
	   while( (c=fgetc(fi))!=EOF )
	   {
		   fprintf(fo,"%c",c+key[d1]);
		   i++;

	   }
	   if(COUNT>35)COUNT=0;
	   d1++;
       }while(c!=EOF);

       fclose(fi);
       fclose(fo);

       return 0;
 }
