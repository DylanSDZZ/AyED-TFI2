//Libreria del Modulo Gimnasio
#include "Estructuras.h"

void registrarRutinas(int legajo){
	system("cls");
	rutina v;
	FILE *rutinas;
	b=0;
	char res;
	char resp;
	int cantpalabras;
	
	rutinas=fopen("rutinas.dat","ab");
	
	do{
		printf("\n\n--------------------------%c REGISTRO DE RUTINAS %c--------------------------\n", 04, 04);
		_flushall();
		v.CodRut=genCod(v.CodRut); // Aca le asigno el valor random generado a la variable CodRut
		
		printf("\n\n\t\t\tCodigo de Rutina:%d",v.CodRut);
		
		do{
		
		 printf("\n\t\t\tDescripcion de Rutina: ");              
		 gets(v.Descripcion);
	     cantpalabras=cantidadPalabras(v.Descripcion); // Llama a la funcion que va a contar la cantidad de palabras mandando como dato el string guardado en la variable
         
		 if(cantpalabras>360){
         	printf("\n La rutina ingresada supera el limite de contenido, intente nuevamente . . .");
		 }
	   }while(cantpalabras>360);
        

	    
		
		fwrite(&v,sizeof(v),1,rutinas);
		
		
		
		printf("\n\n\t\t\tDesea registrar una nueva rutina? [S/N]: ");
		_flushall();
		scanf("%c",&res);
		
		if(res == 'S' or res == 's'){
			b=0;
		}else{
			b=1;
		}
		
		
	}while(b==0);
	
	fclose(rutinas);
	exit(1);
	
}

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

