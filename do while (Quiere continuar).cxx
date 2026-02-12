#include<stdio.h>
#include<conio.h>
void main(void)
{
    signed char A, B;
    do
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
    }while(A=='S'||A=='s');
    _getch();
}