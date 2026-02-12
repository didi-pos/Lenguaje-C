#include<stdio.h>
#include<conio.h>
int suma(int X, int Y);
void main(void)
{
    int A, B, C;
    A=5;
    B=10;
    C=suma(A,B);
    printf("La suma de %d y %d = %d",A,B,C);
    _getch();
}
int suma(int X, int Y)
{
    int Z;
    Z=X+Y;
    return(Z);
}