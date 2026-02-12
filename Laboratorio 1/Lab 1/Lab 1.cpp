#include <stdio.h>
#include <conio.h>
void main(void)

{
	char A, B, C, D;
	printf("Seleccionar formato de entrada: ");
	printf("\n (D)ecimal");
	printf("\n (O)ctal");
	printf("\n (H)exa");
	printf("\n (A)scii");
	printf("\n (B)inario");
	printf("\n Seleccione una opcion: ");

	A = _getche();
	if (A == 'D' || A == 'd')
	{
		printf("\nDigite el valor decimal:");
		B = _getche();
		C = _getche();
		B = B & 0xF;
		C = C & 0xF;
		D = (B * 10) + C;
	}
	else if (A == 'O' || A == 'o')
	{
		printf("\nDigite el valor octal:");
		B = _getche();
		C = _getche();
		B = B & 0xF;
		C = C & 0xF;
		D = (B * 8) + C;
	}
	else if (A == 'H' || A == 'h')
	{
		printf("\nDigite el valor hexa:");
		B = _getche();
		C = _getche();
		B = B & 0xF;
		C = C & 0xF;
		D = (B * 16) + C;
	}
	else if (A == 'A' || A == 'a')
	{
		printf("\nDigite el valor ascii:");
		B = _getche();
	}
	else if (A == 'B' || A == 'b')
	{
		char E, G, H, I, J, K;
		printf("\nDigite el valor binario:");
		B = _getche();
		C = _getche();
		E = _getche();
		G = _getche();
		H = _getche();
		I = _getche();
		J = _getche();
		K = _getche();
		B = B & 0xF;
		C = C & 0xF;
		D = B & 0xF;
		E = E & 0xF;
		G = G & 0xF;
		H = H & 0xF;
		I = I & 0xF;
		J = J & 0xF;
		K = K & 0xF;
		D = (B * 128) + (C * 64) + (E * 32) + (G * 16) + (H * 8) + (I * 4) + (J * 2) + K;
	}
	printf("\nSeleccionar formato de salida: ");
	printf("\n (D)ecimal");
	printf("\n (O)ctal");
	printf("\n (H)exa");
	printf("\n (A)scii");
	printf("\n (B)inario");
	printf("\nSeleccione una opcion: ");
	A = _getche();
	if (A == 'D' || A == 'd')
	{
		printf("\nEl valor es:%d", D);
	}
	else if (A == 'O' || A == 'o')
	{
		printf("\nEl valor es:%o", D);
	}
	else if (A == 'H' || A == 'h')
	{
		printf("\nEl valor es:%x", D);
	}
	else if (A == 'A' || A == 'a')
	{
		printf("\nEl valor es:%c", D);
	}
	else if (A == 'B' || A == 'b')
	{
		printf("\nEl valor es: ");
		int bin[8]{};
		for (int i = 7; i >= 0; i--)
		{
			bin[i] = D % 2;
			D = D / 2;
		}
		for (int i = 0; i < 8; i++)
		{
			printf("%d", bin[i]);
		}
	}
	_getch;
}