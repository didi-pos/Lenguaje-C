#include<stdio.h>
#include<conio.h>
void main(void)
{
    char X[10];
    char A;
    for (A=0; A<=9; A++)
    {
        X[A]=A;
    }
    for (A=0; A<=9; A++)
    {
        printf("\nX[%d]=%d",A,X[A]);
    }
    _getch();
}