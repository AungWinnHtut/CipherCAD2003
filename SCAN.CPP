#include<aung.h>
void SCAN(void)
{
   /* request autodetection */
   registerbgidriver(EGAVGA_driver);
   int gdriver = DETECT, gmode, errorcode,q,a;
   void *arrow;
   int x, y, maxx;
   unsigned int size;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

  int sig=4;float R1;
  int z=0;

  char  str1[5];
   setfillstyle(1, 1);
   bar3d(12,12,630,470,2,4);

   bar3d(2,2,638,478,2,4);
   settextstyle(0,0,2);
   setcolor(14);
     outtextxy(30,27,"PROGRAMMER               AUNG WIN HTUT"  );
     setcolor(12);
     outtextxy(30,120,"THIS PROGRAM IS TO ENCRYPT MILITARY"  );
     setcolor(11);

     outtextxy(30,300,"\" PLEASE WAIT A WHILE WHEN THE PROGRAM  "  );
     outtextxy(30,360,"  IS LOADING \""  );
     setcolor(12);
     outtextxy(30,180,"DATA FOR SECURITY PURPOSE "  );
     setcolor(14);

   setcolor(5);
   line(2,42,634,42);
   setcolor(5);
   line(2,432,634,432);
   settextstyle(0,0,2);
   outtextxy(100,445,"% COMPLETE");
   outtextxy(270,445,"±±±±±±±±±±±±±±±±±±±±±±");
   //a=1;
   settextstyle(0,0,1);

   for(q=0;q<=400;q++)
   {

     if(q%4==0)
     z++;
     gcvt(z,sig,str1);
     setcolor(14);
     settextstyle(0,0,2);
     outtextxy(265+q,445,"³");

    outtextxy(50,445,  str1);
    sound(10+q);
    delay(10);
    nosound();

    setcolor(0);
    outtextxy(50,445,  str1);
  }
     setcolor(14);
     outtextxy(50,445,"100"  );
     setcolor(4);
     outtextxy(400,380,  "WE GET IT!");
     getch();
     cleardevice();
     closegraph();

}

