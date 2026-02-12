#include<stdio.h>
#include<conio.h>
void main(void)
{
    char X[20];
    char A, B=9;
    for (A=0; A<=9; A++)
    {
        X[A]=A;
        printf("\nX[%d]=%d",A,X[A]);
    }
    for (A=10; A<=19; A++)
    {
        X[A]=B;
        B--;
        printf("\nX[%d]=%d",A,X[A]);
    }
    _getch();
}