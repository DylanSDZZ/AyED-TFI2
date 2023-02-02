//Libreria del Modulo Gimnasio
#include "Estructuras.h"

void inicioSesion(){
	system("cls");
	FILE *archivo;
	entrenador aux;
	int b,legajo;
	
	char USER[20],CLAVE[40];
	
	archivo=fopen("PruebaEntrenadores.dat","rb");
	b=0;
	
	printf("\n\n---------------------%c INICIO DE SESION - ENTRENADORES %c---------------------\n", 04, 04);
	
	printf("\n %c Ingrese El nombre de usuario: ",04);
	_flushall();
	gets(USER);
	printf("\n %c Ingrese la contrase%ca: ",04,164);
	_flushall();
	gets(CLAVE);
	
	
	rewind(archivo);
	fread(&aux,sizeof(aux),1,archivo);
	
	while(!feof(archivo)){
		if(strcmp(USER,aux.nick) == 0 and strcmp(CLAVE,aux.pass)== 0){
			legajo=aux.legajo; // Crea una variable a la cual se le asigna el legajo del entrenador que inicio sesion.
			menuIngreso(legajo); // Llama a la funcion MENU mandando como dato el valor del legajo
			b=1
		}else{
			fread(&aux,sizeof(aux),1,archivo);
		}
	}
	
	if(b==0){
	   printf("\n\t\tUSUARIO O CLAVE INCORRECTOS.");
       printf("\n\n");
       system("pause");
	}
	
	
}

int validarCod(int codigo){
	rutina v;
	FILE *arch;

	arch = fopen("rutinas.dat","rb");

	
	fread(&v,sizeof(v),1,arch);
	
	while(feof(arch)){
		return 1;
	}
	
	while(!feof(arch)){
		if(v.CodRut==codigo){  // COMPRUEBA SI EL CODIGO GENERADO YA FUE OCUPADO EN LE ARCHIVO
			fclose(arch);
			return 0;
		}else{
			fread(&v,sizeof(v),1,arch);
		}
		fclose(arch);
		return 1;
	}
	
}

int genCod(int num){
	int i,x;
	srand(time(NULL));
	
	do{
		for(i=0;i<1;i++){
			x = 1+rand()%100;
		}
	}while(!(validarCod(x)));
	return x;
}



int cantidadPalabras(char *frase){
	char caracterActual;
	char caracterPrevio = ' ';
	int cont=0;
	
	while(*frase != '\0'){
		caracterActual = *frase;
		
		if(caracterActual == ' ' and caracterPrevio != ' '){
			
			cont++;
		}
		
		caracterPrevio = caracterActual;
		
		frase++;
		
	}
	
	if(caracterActual != ' '){
		cont++;
	}
	
	return cont;
}

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

