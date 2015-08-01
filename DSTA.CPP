#include"aung.h"
void Dsta(void)
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

   cleardevice();
     setfillstyle(1,1 );
     bar3d(12,12,630,470,2,4);

     bar3d(2,2,638,478,2,4);
     setfillstyle(1,10 );
     bar3d(12,12,630,50,4,4);
     settextstyle(0,0,2);
     setcolor(4);
     outtextxy(20,27,"PROGRAMMER               AUNG WIN HTUT"  );
     setcolor(12);
     outtextxy(30,120,"THIS PROGRAM IS TO ENCRYPT MILITARY"  );
     setcolor(12);
     outtextxy(30,180,"DATA FOR SECURITY PURPOSE "  );
     setcolor(11);
     settextstyle(4,0,19);
     setfillstyle(1,3 );
     bar3d(100,230,540,350,0,4);
     outtextxy(100,200,"D.S.T.A "  );
     setcolor(14);
     settextstyle(4,0,8);
     outtextxy(30,350,"Hyper Generation "  );
     getch();
     cleardevice();
     closegraph();

}

