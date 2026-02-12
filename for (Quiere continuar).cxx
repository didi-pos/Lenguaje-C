#include<stdio.h>
#include<conio.h>
void main(void)
{
    signed char A, B;
    for(A='S';A=='S'||A=='s';A=A)
    {
        printf("\n");
        B=0;
        do
        {
            printf("%d",B);
            B++;
        } while(B<=9);
        printf("\nQuiere Continuar? (S)i o (N)o: ");
        A=_getche();
    }
    _getch();
}