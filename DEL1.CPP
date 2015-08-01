#include "aung.h"
void DEL_OPT(char *filename_del);

/* deletes file name; returns 0 on success, nonzero on failure */
int delete_file(char  *filename)
{
   union REGS regs;
   int ret;
   regs.h.ah = 0x41;
/* delete file */
   regs.x.dx = (unsigned) filename;
   ret = intdos(&regs, &regs);

   /* if carry flag is set, there was an error */
   return(regs.x.cflag ? ret : 0);
}

int DEL1(int flag)
{
   char filename_del[40];
   int err;
   Window(20,10,60,15,5);
   Label(1,1,1,5,"DELETE_FILE   Programmer< Aung Win Htut >");
   Window(20,11,60,15,3);
   Label(2,2,4,3,"Enter File Name");
   Datafield(2,3,"                                     ");
   gotoxy(2,3);
   gets(filename_del);
   _setcursortype(_NOCURSOR);
   if(flag==1)
	{
		err = delete_file(filename_del);
		gotoxy(2,4);
		if (!err)
			printf("Able to delete %s\n",filename_del);
		else
			printf("Not Able to delete %s\n",filename_del);
		getch();
		_setcursortype(_NORMALCURSOR);
	}
   else
       DEL_OPT(filename_del);
   getch();
   return 0;
}

void DEL_OPT(char *filename_del)
{
   char DEL_[100]="DEL ";
   strcat(DEL_,filename_del);
   Window(20,17,60,18,2);
   system(DEL_);
   _setcursortype(_NOCURSOR);
}

