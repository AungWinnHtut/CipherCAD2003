#include"aung.h"


void Clrscr()
{
   window(1,1,80,25);
   textbackground(0);
   clrscr();
   system("cls");
}

void Window(int x1,int y1,int x2,int y2,int bkcolor)
{
   window(x1,y1,x2,y2);
   textbackground(bkcolor);
   clrscr();
}


void Label(int tx,int ty,int tcolor,int tbkcolor,char *text)
{
   gotoxy(tx,ty);
   textcolor(tcolor);
   textbackground(tbkcolor);
   cprintf(text);

}


void Datafield(int dx,int dy,char *space)
{
   gotoxy(dx,dy);
   textbackground(BLACK);
   cprintf(space);
}



