#include<stdio.h>
#include<conio.h>
void main(void)
{
    signed char A,B;
    for(A=0;A<=4;A=A+1)
    {
        for(B=0;B<=9;B=B+1)
    {
        printf("%d",B);
    }
        for(B=9;B>=0;B=B-1)
    {
        printf("%d",B);
    }
    printf("\n");
    }
    _getch();
    
}