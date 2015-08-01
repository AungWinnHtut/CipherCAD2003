#include"aung.h"
void Dosshell()
{    char common[100];
    Window(1,1,80,25,0);
    textcolor(15);
    clrscr();
    printf("\n type  EXIT  to return to my softwre. . .\n\n");
    printf(" Hyper Generation Group(R) Window(98)");
    printf("\n\t(C)Copyright  Hyper Generation Group  2000-2001\n\tProgrammer     Aung Win Htut\n\n");
    do{
	  printf("C:\\>");
	  gets(common);
	  system(common);

    }while(strcmpi(common,"exit"));
}