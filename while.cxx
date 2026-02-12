#include<stdio.h>
#include<conio.h>
void main(void)
{
    signed char A,B;
    A=0;
    while(A<5)
    {
        B=0;
        while(B<=9)
        {
            printf("%d",B);
            B++;
        }
        B=9;
        while(B>=0)
        {
            printf("%d",B);
            B--;
        }
        printf("\n");
        A++;
    }
    _getch();
}