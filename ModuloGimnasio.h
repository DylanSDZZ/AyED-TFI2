//Libreria del Modulo Gimnasio
#include "Estructuras.h"

void menuIngreso(int legajo){
	entrenador aux;
	system("cls");
	int op;
	char res;
	
	printf("\n\n--------------------------%c MENU DE ENTRENADORES %c--------------------------\n", 04, 04);
	
		printf("\n\t\t\t[1].Listar Socios.\n");
		printf("\n\t\t\t[2].Registrar Rutinas.\n");
		printf("\n\t\t\t[0].Salir.\n");
		
	printf("\n\n\n\t\t\t[Elija Su Opcion]:");
	scanf("%d",&op);
	
		switch(op){

			case 1:
				//listarSocios(legajo); // Envia el legajo del entrenador a la funcion listarSocios
				break;

			case 2:
				  registrarRutinas(legajo); // Envia el valor de la variable legajo a la funcion registrar rutina
				break;
			case 0: 
			     system("cls");
			     break;

			default:
				system("cls");
				printf("\n\n\n\t\t\t[Opcion Invalida. . .]");
				printf("\n\n");
				printf("\t\t");system("pause"); printf("\n\n");
				printf("\t\t\tDesea regresar al Menu? [S/N]: ");
				_flushall();
				scanf("%c",&res);

				if(res == 'S' or res == 's'){
				  menuIngreso(legajo);
				}else{
					printf("\n\n\t\t");system("pause");
					exit(1);
				}
				break;


		}
	
	
	
}

