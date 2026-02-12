#include<stdio.h>
#include<conio.h>
void main(void)
{
    signed char A, B, C;
    for(A=0;A<10;A++)
    {
        printf("\n");
        B='A';
        while(B<='Z')
        {
            printf("%c",B);
            B++;
        }
        C='a';
        do
        {
            printf("%c",C);
            C++;
        }while(C<='z');
    }
    _getch();
}