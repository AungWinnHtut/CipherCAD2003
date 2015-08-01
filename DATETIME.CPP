#include<aung.h>
void main(void)
{
	//clrscr();
	struct dostime_t t;
	struct dosdate_t d;

	do{
		clrscr();
		_dos_gettime(&t);
		_dos_getdate(&d);
		printf("the current date is %02d-%02d-%02d\n",d.day,d.month,d.year);
		printf("the current time is %02d:%02d:%02d:%02d\n",t.hour,t.minute,t.second,t.hsecond);
		delay(1);
	}while(!kbhit());

}