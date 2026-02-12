#include<stdio.h>
#include<conio.h>
void main(void)
{
    signed char A,B;
        B=0;
        do
        {
            A=0;
            do 
            {
                printf("%d",A);
                A++;
            } while(A<=9);
            A=9;
            do
            {
                printf("%d",A);
                A--;
            } while(A>=0);
            printf("\n");
            B++;
        } while(B<5);
    _getch();
}