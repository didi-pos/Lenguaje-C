//Didier Posse y Juan Pablo Serrano
#include <stdio.h>
#include <conio.h>
#include <windows.h>
char escribir_leer(char transmitir);
void inicializar(void);
void cerrar(void);
void _1(void);
void _2(void);
void _3(void);
void _4(void);
HANDLE handlePort_;
WCHAR puerto[] = L"COM4";
DWORD length = 1, sizeBuffer = 1;
void main(void)
char c;
inicializar();
do
{
	printf("Menu:");
	printf("\n1. Contador 0-9-0");
	printf("\n2. Contador 0-9-0 segmento a segmento");
	printf("\n3. Contador de 0-9-0, (U)p el contador incrementa con (D)own decrementa");
	printf("\n4. Encender segmentos a-g");
	printf("\n5. Salir");
	printf("\nSeleccione una opcion: ");
	c = _getche();
	switch (c)
	{
	case '1': printf("\nContador 0-9-0: ");
		_1();
		break;
	case '2': printf("\nContador 0-9-0 segmento a segmento: ");
		_2();
		break;
	case '3': printf("\nContador de 0-9-0, (U)p el contador incrementa con (D)own decrementa: ");
		_3();
		break;
	case '4': printf("\nEncender segmentos a-g: ");
		_4();
		break;
	case '5':
		printf("\nSaliendo del programa...");
		break;
	default:
		printf("\nOpcion no valida. Intente de nuevo: ");
	}
} while (c != 5);
cerrar();
}
char Convert(char X)
{
	char siete[10] = { 0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x7, 0x6f };
	return(siete[X]);
}
char escribir_leer(char transmitir)
{
	char outputData[2];
	char inputData[2];
	outputData[0] = transmitir;
	if (WriteFile(handlePort_,
		outputData,
		sizeBuffer,
		&length, NULL) == 0)
	{
		printf("Error Escritura Puerto Serial.");
	}
	//Sleep(1);
	if (ReadFile(handlePort_,
		inputData,
		sizeBuffer,
		&length,
		NULL) == 0)
	{
		printf("Error Lectura Puerto Serial");
	}
	return(inputData[0]);
}
void inicializar(void)
{
	handlePort_ = CreateFile(puerto,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);
	DCB config_;
	if (GetCommState(handlePort_, &config_) == 0)
	{
		printf("Puerto Serial Error");
	}
	config_.BaudRate = 115200;
	config_.StopBits = 2;
	config_.Parity = 0;
	config_.ByteSize = 8;
	if (SetCommState(handlePort_, &config_) == 0)
	{
		printf("Error Configuracion de Puerto Serial");
	}
	COMMTIMEOUTS comTimeOut;
	comTimeOut.ReadIntervalTimeout = 3;
	comTimeOut.ReadTotalTimeoutMultiplier = 3;
	comTimeOut.ReadTotalTimeoutConstant = 2;
	comTimeOut.WriteTotalTimeoutMultiplier = 3;
	comTimeOut.WriteTotalTimeoutConstant = 2;
	SetCommTimeouts(handlePort_, &comTimeOut);
}
void cerrar(void)
{
	if (CloseHandle(handlePort_) == 0)
	{
		printf("Cerrar puerto error");
	}
}
void _1(void)
{
	char a, siete[] = { 0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x7, 0x6f };
	do
	{
		for (a = 0; a <= 9; a++)
		{
			escribir_leer(~siete[a]);
			Sleep(600);
		}
		for (a = 8; a >= 0; a--)
		{
			escribir_leer(~siete[a]);
			Sleep(600);
		}
	} while (!_kbhit());
	_getch();
}
void _2(void)
{
	char a, b, c = 0, siete[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
	do
	{
		for (a = 0; a < 10; a++)
		{
			for (b = 0; b < 7; b++)
			{
				c = ~(siete[a] & (1 << b)) + c;
				escribir_leer(c);
				Sleep(200);
			}
			Sleep(400);
		}
		for (a = 9; a >= 0; a--)
		{
			for (b = 0; b < 7; b++)
			{
				c = ~(siete[a] & (1 << b)) + c;
				escribir_leer(c);
				Sleep(200);
			}
			Sleep(400);
		}
	} while (!_kbhit());
	_getch();

}
void _3(void)
{
	char a = 0, b, siete[] = { 0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x7, 0x6f };
	do
	{
		escribir_leer(~siete[a]);
		printf("\nCon (U)p el contador incrementa con (D)own decrementa: ");
		b = _getche();
		if (b == 'U' || b == 'u')
		{
			a++;
		}
		if (b == 'D' || b == 'd')
		{
			a--;
		}
		if (a < 0)
		{
			a = 9;
		}
		if (a > 9)
		{
			a = 0;
		}
	} while (d != 'U' || d != 'u' || d != 'D' || d != 'd');
	_getch();
}
void _4(void)
{
	char a, b, c, d = 0, siete[] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40 };
	do
	{
		c = 0;
		printf("\nIngrese un segmento a-g: ");
		a = _getche();
		if (a >= 'a' && a <= 'g')
		{
			if (a == d)
			{
				escribir_leer(~c);
			}
			else
			{
				for (b = 'a'; b < a; b++)
				{
					c++;
				}
				escribir_leer(~siete[c]);
			}
			d = a;
		}
	} while (a >= 'a' && a <= 'g');
	_getch();
}