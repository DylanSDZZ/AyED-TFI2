#include <stdio.h>
#include <stdlib.h>

main()
{	
	int x=0, autorizacion=1;
	
	while(autorizacion==1)
	{
		autorizacion=0;
		
		printf("\n\n---------------------%c SISTEMA DE GESTION: GYMSIS 1.0 %c---------------------\n", 04, 04);
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
				break;
				
			case 3:
				system("cls");
				break;
				
			default:
				printf("\n\n\n %c%c Se ha ingresado una opcion incorrecta, presione enter para reintentar...", 33, 33);getchar();system("CLS");
				autorizacion=1;	 
				break;
		}
		
	}
	
}