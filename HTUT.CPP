#include<stdlib.h>
#include<conio.h>




void HTUT()
{
   int D_H;
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
   cprintf("About Programmer Aung Win Htut");



   window(D_H+6,D_H+5,D_H+66,D_H+20);
   textbackground(3);
   clrscr();



   textcolor(1);
   gotoxy(6,2);

   cprintf("Aung Win Htut was born in 19-2-78.His mother is primary");
   gotoxy(2,3);

   cprintf("school teacher and his father is a clerk.He is third intake");
   gotoxy(2,4);

   cprintf("cadet of D.S.T.A. His major is Electrical Power. He studied");
   gotoxy(2,5);

   cprintf("the theory of Cryptography and design this software as  his");
   gotoxy(2,6);

   cprintf("project paper.");
   gotoxy(2,7);

   gotoxy(2,8);

   gotoxy(2,9);

   gotoxy(2,10);

   gotoxy(2,11);

   gotoxy(45,12);

   gotoxy(45,13);

   gotoxy(45,14);

   gotoxy(45,15);

   getch();
}