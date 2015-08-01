//Modified   13-2-2002
#include"AUNG.h"
#include<ctype.h>

void  PASSWORD(void);
void scan (void);
void DOS_SHELL();

void  PASSWORD(void)
{
	int  i,h;
	char   key_input='\0',_Password[6]="cipher";
	static	int count=0;
	char uname[100];

AA:
	window(1,1,80,25);
	textbackground(3);
	clrscr();

	window(21,9,62,18);
	textbackground(0);
	clrscr();
	window(20,8,60,17);
	textbackground(7);
	clrscr();
	textcolor(4);
	cprintf("P");
	textcolor(5);
	cprintf("rogrammer                  Aung Win Htut");

	window(20,9,60,17);
	textbackground(1);
	clrscr();

	gotoxy(2,2);
	textcolor(4);
	cprintf("U");
	gotoxy(3,2);
	textcolor(2);
	cprintf("ser Name");

	gotoxy(2,6);
	textcolor(4);
	cprintf("P");
	gotoxy(3,6);
	textcolor(2);
	cprintf("assword");

	textbackground(0);
	_setcursortype(_NORMALCURSOR);
	textcolor(2);
	gotoxy(15,2);
	cprintf("              ");  //uname

	textbackground(0);
	textcolor(2);
	gotoxy(15,6);
	cprintf("              ");    //pass
//+++++++++++++++++++++++++++++++++
	textbackground(15);
	gotoxy(15,2);
	gets(uname);

	textbackground(15);
	gotoxy(15,6);
//*******************************
	for(i=0;i<=5;i++)
	{
		key_input=tolower(getch());

		if(key_input!=_Password[i]) {
			count++;
			if(count==3)
			  DOS_SHELL();
			PASSWORD();

		}

	textcolor(2);
	textbackground(0);

	cprintf("$");
	}
}

void DOS_SHELL()
{
	char com[100];
	int i;
	window(1,1,80,25);
	textbackground(0);
	clrscr();
	do{
	printf("\n $:\\> ");
	scanf("%s",com);
	system(com);
	system("pause");
	}while(com[0]!='$'||com[0]!='$');
	clrscr();

}

