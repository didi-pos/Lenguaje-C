#include <stdio.h>
#include <conio.h>
void main(void)
{
    char A,B,C,D,E;
    printf("Porfavor digite un numero del 0000—1111");
    A=_getche();
    B=_getche();
    C=_getche();
    D=_getche();
    A=A&0xF;
    B=B&0xF;
    C=C&0xF;
    D=D&0xF;
    E=(A*8)+(B*4)+(C*2)+D;
    printf("\nEl dato digitado fue: %d",E);
    _getch();
}