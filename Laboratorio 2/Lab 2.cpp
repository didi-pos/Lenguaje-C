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
WCHAR puerto[] = L"COM6";
DWORD length = 1, sizeBuffer = 1;
int main()
{
	char c;
	inicializar();
	do
	{
		printf("Menu:");
		printf("\n1. Efecto Led Individual");
		printf("\n2. Efecto Auto Fantastico");
		printf("\n3. Efecto Dip Switch");
		printf("\n4. Efecto Titilar Led");
		printf("\n5. Salir");
		printf("\nSeleccione una opcion: ");
		c = _getche();
		switch (c)
		{
		case '1': printf("\nEfecto Led Individual: ");
			_1();
			break;
		case '2': printf("\nEfecto Auto Fantastico: ");
			_2();
			break;
		case '3': printf("\nEfecto Dip Switch: ");
			_3();
			break;
		case '4': printf("\nEfecto Titilar Led: ");
			_4();
			break;
		case '5':
			printf("\nSaliendo del programa...");
			break;
		default:
			printf("\nOpcion no valida. Intente de nuevo.");
		}
	} while (c != 5);
	cerrar();
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
	char a = 0, b, c, d, e, f = 0, key;
	int num;
	do {
		b = a & 0xF;
		c = (a >> 4) & 0xF;
		d = 0 << b;
		e = 0 << c;
		f = f ^ (d | e);

		if (_kbhit()) {
			key = _getch();
			if (key >= '0' && key <= '7') {

				num = key - '0';

				f = f ^ (1 << num);
			}
		}
		escribir_leer(f);
		if (f == 255)
		{
			escribir_leer(f);
			Sleep(300);
			escribir_leer(0);
			Sleep(300);
		}
	} while (1);
}
void _2(void)
{
	char a, b;
	do
	{
		a = escribir_leer(0);
		for (b = 0; b <= 8; b++)
		{
			escribir_leer(a << b);
			Sleep(150);
		}
		a = 128;
		for (b = 0; b <= 8; b++)
		{
			escribir_leer(a >> b);
			Sleep(150);
		}
	} while (!_kbhit());
}
void _3(void)
{
	char a = 0, b, c, d, e;
	do
	{
		b = a & 0xF;
		c = (a >> 4) & 0xF0;
		d = 1 << b;
		e = 1 << c;
		a = escribir_leer(d | e);
		Sleep(300);
		a = escribir_leer(0);
		Sleep(300);
	} while (!_kbhit());
}
void _4(void)
{
	char a = 16, b = 'i';
	do
	{
		if (_kbhit())
		{
			b = _getche();

			if (b == 'i' || b == 'I')
			{
				a = a >> 1;
				escribir_leer(a);
				Sleep(300);
			}

			if (b == 'd' || b == 'D')
			{
				a = a << 1;
				escribir_leer(a);
				Sleep(300);
			}
		}
		escribir_leer(a);
		Sleep(300);
		escribir_leer(0);
		Sleep(300);

	} while (b == 'i' || b == 'I' || b == 'd' || b == 'D');
}