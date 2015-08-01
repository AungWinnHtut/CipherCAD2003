#include<aung.h>
void main(void)
{
	clrscr();
	int h,m,s,d;
	h=0;
	m=0;
	s=0;
	d=0;

	do{
		clrscr();
		cout<<d<<":"<<h<<":"<<m<<":"<<s;
		delay(1000);
		s++;
		if(s>=60)
		{
			s=0;
			m++;
			if(m>=60)
			{
				m=0;
				h++;
				if(h>=24)
				{
					h=0;
					d++;
				}
			}
		}
	}while(!kbhit());
}