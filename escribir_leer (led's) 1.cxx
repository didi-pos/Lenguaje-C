#include<stdio.h>
#include<conio.h>
#include<windows.h>
void main(void)
{
    char A;
    inicializar();
    do
    {
        A=escribir_leer(0xFF);
        Slerp(300);
        A=escribir_leer(0);
        Sleep(300);
    }while(!_Kbhit());
    cerrar();
    _getch();
}