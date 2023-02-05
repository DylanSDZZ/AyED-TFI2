//Libreria del Modulo Gimnasio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menuIngreso(int legajo);

void inicioSesion(){
	
	system("cls"); 
	FILE *archivo;   // DECLARA UN ARCHVO
	entrenador aux;   // DECLARA LOS STRUCTS CORRESPONDIENTES A LOS ENTRENADORES
	int b,legajo; 
	
	char USER[20],CLAVE[40];   // VARIABLES DONDE SE GUARDARAN LOS DATOS INGRESADOS PARA EL INICIO DE SESION
	
	archivo=fopen("PruebaEntrenadores.dat","rb");   // ABRE EL ARCHIVO DONDE SE GUARDAN LOS DATOS DE LOS USUARIOS DE ENTRENADORES
	b=0;
	
	printf("\n\n---------------------%c INICIO DE SESION - ENTRENADORES %c---------------------\n", 04, 04);
	
	printf("\n %c Ingrese El nombre de usuario: ",04);
	_flushall();
	gets(USER);   // CONSIGUE EL NICK DEL USUARIO QUE DESEA INICIAR SESION
	printf("\n %c Ingrese la contrase%ca: ",04,164);
	_flushall();
	gets(CLAVE);  // CONSIGUE LA CONTRA DEL USUARIO QUE DESEA INICIAR SESION
	
	
	rewind(archivo);        // COLOCA EL PUNTERO AL INICIO DEL ARCHIVO PARA QUE PUEDA COMPARAR CADA UNO DE LOS DATOS DENTRO DEL ARCHIVO
	fread(&aux,sizeof(aux),1,archivo); // REALIZA LA PRIMERA LECTURA DEL ARCHIVO 
	
	while(!feof(archivo)){  
		if(strcmp(USER,aux.nick) == 0 and strcmp(CLAVE,aux.pass)== 0){
			legajo=aux.legajo; // CREA UNA VARIABLE A LA CUAL SE LE ASIGNA EL NUMERO DE LEGAJO DEL ENTRENADOR QUE INICIO SESION
			menuIngreso(legajo); // LLAMA LA FUNCION DE MENU DEL ENTRENADOR LLEVANDO EL NUMERO DE LEGAJO DEL MISMO
			b=1;   // COLOCA LA BANDERA EN 1 PARA QUE EL CICLO SE ROMPA
		}else{
			fread(&aux,sizeof(aux),1,archivo);  // SI NO ENCONTRO CORRESPONDENCIA ENTRE LOS DATOS INGRESADO EN LA PRIMERA LINEA DEL ARCHIVO, SIGUE BUSCANDO EN LAS PROXIMAS LINEAS
		}
	}
	
	if(b==0){   // SI NUNCA ENCONTRO LA COINCIDENCIA DE DATOS DENTRO DEL ARCHIVO, LOS DATOS INGRESADOS FUERON INCORRECTOS
	   printf("\n\t\tUSUARIO O CLAVE INCORRECTOS.");
       printf("\n\n");
       system("pause");
	}
	
	
}

int validarCod(int codigo){  // FUNCION QUE VALIDA EL CODIGO DE RUTINA 
	rutina v;   // DECLARA EL TIPO DE DATO ESTRUCTURADO RUTINA
	FILE *arch; // DECLARA UN ARCHIVO CON EL CUAL VAMOS  A TRABAJAR
 
	arch = fopen("rutinas.dat","rb");  // ABRE EL ARCHIVO EN MODO LECTURA

	
	fread(&v,sizeof(v),1,arch);  // REALIZA LA PRIMERA LECTURA DEL CICLO
	
	while(feof(arch)){   // SI EL ARCHIVO ESTA VACIO RETORNA UN VALOR QUE PERMITE INGRESAR EL CODIGO
		return 1;
	}
	
	while(!feof(arch)){   // SI EL ARCHIVO NO ESTA VACIO COMIENZA A COMPARAR LOS DATOS
		if(v.CodRut==codigo){  // COMPRUEBA SI EL CODIGO GENERADO YA FUE OCUPADO EN LE ARCHIVO
			fclose(arch);     // SI SE ENCONTRO EL MISMO CODIGO YA REGISTRADO CIERRA EL ARCHIVO 
			return 0;     // RETORNA UN 0 EN SEÑAL DE QUE NO SE PUDO REGISTRAR EL CODIGO YA QUE ESTABA OCUPADO PREVIAMENTE
		}else{
			fread(&v,sizeof(v),1,arch); // REALIZA LA SEGUNDA LECTURA DEL ARCHIVO
		}
		
		fclose(arch); 
		return 1; // RETORNA 1 EN SEÑAL DE QUE EL CODIGO NO FUE OCUPADO PREVIAMENTE
	}
	
}

int genCod(int num){   // FUNCION QUE GENERA EL CODIGO DE RUTINA ALEATORIAMENTE
	int i,x;
	srand(time(NULL)); 
	
	do{
		for(i=0;i<1;i++){    
			x = 1+rand()%100;  // ASIGNA A LA VARIABLE UN NUMERO ENTRE EL 1 Y EL 100
		}
	}while(!(validarCod(x)));  // COMPRUEBA QUE EL CODIGO GENERADO NO HAYA SIDO OCUPADO PREVIAMENTE 
	return x; // RETORNA EL VALOR DE LA VARIABLE X CON EL CODIGO GENERADO
}



int cantidadPalabras(char *frase){  // FUNCION QUE CUENTA LAS PALABRAS DENTRO DEL ARRAY DE RUTINAS
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
	
	return cont; // RETORNA LA CANTIDAD DE PALABRAS 
}

void registrarRutinas(int legajo){  // FUNCION QUE REGISTRA LAS RUTINAS 
	system("cls");
	rutina v; // DECLARA LA ESTRUCTURA DE RUTINAS
	FILE *rutinas; // DECLARA EL ARCHIVO QUE VAMOS A USAR
	int b=0; // COLOCA LA BANDERA EN 0
	char res;
	char resp;
	int cantpalabras;
	
	rutinas=fopen("rutinas.dat","ab");  // ABRE EL ARCHIVO 
	
	do{
		printf("\n\n--------------------------%c REGISTRO DE RUTINAS %c--------------------------\n", 04, 04);
		_flushall();
		v.CodRut=genCod(v.CodRut); // SE LE ASIGNA UN VALOR GENERADO CON LA FUNCION A EL CODIGO DE RUTINA
	    
	    v.legEntrenador=legajo; // ASIGNA EL LEGAJO AL DATO DE LA ESTRUCTURA 
		printf("\n\n\t\t\tLegajo de Entrenador: %d",v.legEntrenador); // IMPRIME EN PANTALLA EL LEGAJO DEL ENTRENADOR QUE INICIO SESION
		
		printf("\n\n\t\t\tCodigo de Rutina: %d",v.CodRut);  // LO IMPRIME EN PANTALLA
		
		do{
		
		 printf("\n\t\t\tDescripcion de Rutina: ");                  
		 gets(v.Descripcion);
	     cantpalabras=cantidadPalabras(v.Descripcion); // LLAMA LA FUNCION QUE CUENTA LAS PALABRAS Y LE ASIGNA EL VALOR A LA VARIABLE CANTPALABRAS
         
		 if(cantpalabras>360){   
		 	
         	printf("\n La rutina ingresada supera el limite de contenido, intente nuevamente . . .");
		 }
	    }while(cantpalabras>360); // SI LA CANTIDAD DE PALABRAS ES MAYOR A 360 VUELVE A REPETIR EL CICLO YA QUE SUPERA EL LIMITE PERMITIDO
        

	    
		
		fwrite(&v,sizeof(v),1,rutinas); // UNA VEZ REGISTRADA LA RUTINA LA ESCRIBE EN EL ARCHIVO 
		
		
		printf("\n\t\t\tRutina Registrada con exito... Legajo de Entrenador a cargo: %d",legajo); // IMPRIME EL EXITO AL REGISTRAR LA RUTINA JUNTO AL LEGAJO DEL ENTRENADOR QUE LA INGRESO
		printf("\n\t\t\t");system("pause");
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

void menuIngreso(int legajo){   // RECIBE EL NUMERO DE LEGAJO DEL ENTRENADOR QUE INICIO SESION
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
				//listarSocios(legajo); // ENVIA A LA FUNCION LISTAR SOCIOS EL NUMERO DE LEGAJO GUARDADO EN LA VARIABLE LEGAJO  // FUNCION TODAVIA NO CREADA
				break;

			case 2:
				  registrarRutinas(legajo); // ENVIA EL NUMERO DE LEGAJO DEL ENTRENADOR A LA FUNCION REGISTRAR RUTINA 
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

