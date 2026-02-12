#include<stdio.h>
#include<conio.h>
#include<windows.h>
void main(void)
{
    char A, B=0;
    inicializar();
    do
    {
        A=escribir_leer(B);
        if (A==0x55)
        {
            B=1;
        }
        else
        {
            B=0;
        }
        Sleep(200);
    }while(!_kbhit());
    cerrar();
    _getch();
}