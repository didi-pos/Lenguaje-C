#include<stdio.h>
#include<conio.h>
char decimal(void);
void main(void)
{
    char A;
    A=decimal();
    printf("\nA=%X",A);
    _getch();
}
char decimal(void)
{
    char X, Y, Z;
    printf("\nPorfavor digite"
           "un valor decimal= ");
    X=_getche();
    Y=_getche();
    X=X&0XF;
    Y=Y&0XF;
    Z=(X*10)+Y;
    return(Z);
}