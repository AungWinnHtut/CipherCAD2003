#include<CONIO.H>
#include<STDIO.H>
#include<PROCESS.H>
//This program illustrate the important keyboard features
void main(void)
{
	char key;
	clrscr();
	for(int i=1;i<=200;i++)
	{
		key = getch();
		printf("\n  %d  %c  ",key,key);
		if( key == char(27))
			exit(0);
	}
}