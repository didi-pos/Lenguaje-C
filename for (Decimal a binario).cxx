#include <stdio.h>
#include <conio.h>
void main(void)
{
    signed char A,B,C,D,E;
    printf("Porfavor digite un valor del decimal del 00-99= ");
    A=_getche();
    B=_getche();
    A=A&0xF;
    B=B&0xF;
    C=(A*10)+B;
    printf("\n");
    for (D=7; D>=0; D--)
    {
        E=(C>>D)&1;
        printf("%d",E);
    }
    _getch();
}