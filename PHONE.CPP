#include"aung.h"
void SOUND()
//void main(void)
{

 for(int tring=1;tring<=2;tring++){
  for(int i=1;i<=30;i++){
    sound(600);
    delay(30);
    nosound();
    sound(1500);
    delay(30);
    nosound();
   }
   delay(2000);
 }

}