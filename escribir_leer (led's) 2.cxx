#include<stdio.h>
#include<conio.h>
#include<windows.h>
void main(void)
{
    char A, B;
    inicializar();
    A=escribir_leer(0);
    do
    {
        if(A='a' || A='A')
        {
        B=escribir_leer(0xF0);
        Sleep(300);
        B=escribir_leer(0);
        Sleep(300);
        }
         if(A='b' || A='B')
        {
        B=escribir_leer(0xF);
        Sleep(300);
        B=escribir_leer(0);
        Sleep(300);
        }
        if(_kbhit())
        {
            A=_getche();
        }
    }while(A!='s' && A!='S');
    cerrar();
    _getch();
}