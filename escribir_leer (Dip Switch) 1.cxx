#include<stdio.h>
#include<conio.h>
#include<windows.h>
void bin (char X);
void main(void)
{
    char A;
    printf("\nDato leido= ");
    inicializar();
    do
    {
        A=escribir_leer(0);
        printf("%x",A);
        printf("\nValor leido Binario= ");
        bin(A);
        Sleep(300);
    }while(!_kbhit());
    cerrar();
    _getch();
}
   void bin (char X)
    {
        char A, B;
        for (A=7; A>=0; A--)
        {
            B=(X>>A)&1;
            printf("%d",B);
        }
    }