#include<stdio.h>
#include<conio.h>
void fun(char X);
void fun1(char X);
void main(void)
{
    char A, B;
    A=0;
    fun(A);
    A=1;
    fun(A);
    A=2;
    fun(A);
    A=3;
    fun(A);
    A=4;
    fun(A);
    A=5;
    fun(A);
    A=6;
    fun(A);
    A=7;
    fun(A);
    A=8;
    fun(A);
    A=9;
    fun(A);
    for(B=9; B>=0; B--)
    {
        fun1(B);
    }
    _getch();
}
void fun(char X)
{
    switch(X)
    {
        case 0: printf("\nCero");
                   break;
        case 1: printf("\nUno");
                   break;
        case 2: printf("\nDos");
                   break;
        case 3: printf("\nTres");
                   break;
        case 4: printf("\nCuatro");
                   break;
        case 5: printf("\nCinco");
                   break;
        case 6: printf("\nSeis");
                   break;
        case 7: printf("\nSiete");
                   break;
        case 8: printf("\nOcho");
                   break;
        case 9: printf("\nNueve");
                   break;
    }
}
void fun1(char X)
{
    switch(X)
    {
        case 9: printf("\nNueve");
                   break;
        case 8: printf("\nOcho");
                   break;
        case 7: printf("\nSiete");
                   break;
        case 6: printf("\nSeis");
                   break;
        case 5: printf("\nCinco");
                   break;
        case 4: printf("\nCuatro");
                   break;
        case 3: printf("\nTres");
                   break;
        case 2: printf("\nDos");
                   break;
        case 1: printf("\nUno");
                   break;
        case 0: printf("\nCero");
                   break;
    }
}