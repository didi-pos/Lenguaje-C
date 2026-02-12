#include <stdio.h>
#include <conio.h>
void main(void)
{
    signed char A,B,C,D,E;
    printf("Porfavor digite un valor 00-99");
    A=_getche();
    B=_getche();
    A=A&0xF;
    B=B&0xF;
    C=(A*10)+B;
    printf("\nEl valor binario: ");
    for (E=7;E>=0;E--)
    {
        D=C&(1<<E);
        if(D!=0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    _getch();
}