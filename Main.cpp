#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <wincon.h>
#include "Estructuras.h"
#include "ModuloAdministracion.h"
#include "ModuloRecepcion.h"
#include "ModuloGimnasio.h"

inline void setFontSize(int a, int b);


main()
{	

	system ("mode con cols=80");
	system("COLOR 0C");
	SetConsoleTitle("GYMSIS 1.0"); 
	setFontSize(13,21);
	
	int x=0, autorizacion=1;
	
	while(autorizacion==1)
	{
		autorizacion=0;
		
		printf("\n\n-----------------------%c SISTEMA DE GESTION: GYMSIS 1.0 %c-----------------------\n", 04, 04);
		printf("\n [1] - Modulo de Administracion \n");
		printf("\n [2] - Modulo de Recepcion \n");
		printf("\n [3] - Modulo Gym \n");
		
		printf("\n\n %c - Ingrese el numero del modulo al que se desea ingresar:  "); scanf("%d", &x); _flushall();
		
		switch(x)
		{
			case 1: 
				system("cls");	
				moduloAdmin();
				break;
				
			case 2:
				system("cls");
				SesionRecepcion();
				break;
				
			case 3:
				system("cls");
				inicioSesion();
				break;
				
			default:
				printf("\n\n\n %c%c Se ha ingresado una opcion incorrecta, presione enter para reintentar...", 33, 33);getchar();system("CLS");
				autorizacion=1;	 
				break;
		}
		
	}
	
}


inline void setFontSize(int a, int b) 
{

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

    GetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

    lpConsoleCurrentFontEx->dwFontSize.X = a;

    lpConsoleCurrentFontEx->dwFontSize.Y = b;

    SetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

}