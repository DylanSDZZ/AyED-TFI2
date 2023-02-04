//Libreria del Modulo Recepcion
#include "Estructuras.h"

void listarSocios(){
	 socios reg;
	 FILE *arch;

		// En caso de ser otro los nombres de la estructura socios o el archivo se deberan modificar ciertas caracteristicas del codigo a continuacion

	   system("cls");

	   arch=fopen("PruebaSocios.dat","rb"); // Abro el archivo binario "socios.dat" que contiene los datos de los socios previamente ingresado
	   int cont=1; // Declaro un contador para ver la cantidad de socios que se van a listar
	   rewind(arch); // Coloco el puntero al inicio del archivo binario

	   fread(&reg,sizeof(reg),1,arch);  // Doy la primera lectura dentro del archivo
       
       printf("\n\t\t------------%cSOCIOS REGISTRADOS%c------------\n",04,04);
	   if(feof(arch)){
          system("cls");
          printf("\n\n\t\t\tEl archivo esta vacio. . ."); // En caso de que el archivo esta vacio saldra esto
	   }else{
	     while(!feof(arch)){
            printf("\nSOCIO NUMERO [%d]\n",cont);  // De lo contrario imprimira los siguientes datos en pantalla
            printf("-------------------------");
            printf("\nNombre: %s\n",reg.nomyape);
            printf("DNI:%d\n",reg.DNI);
            printf("Telefono:%d\n",reg.tel);
            printf("Direccion: %s\n",reg.direccion);
            printf("Numero de Socio:%d\n",reg.numSocio);
            
            printf("\nINDICACIONES MEDICAS\n");
            printf("Zumba:%c \n",reg.indMedicas.zum);
            printf("Spining:%c \n",reg.indMedicas.spin);
            printf("Pilates:%c \n\n",reg.indMedicas.pil);
            
           
            
            printf("\nFECHA DE INGRESO\n");
            printf("Dia:%d\n",reg.fec_ingreso.dia);
            printf("Mes:%d\n",reg.fec_ingreso.mes);
            printf("Anio:%d\n\n",reg.fec_ingreso.anio);
            
            printf("-------------------------");
            cont++; // Aumento el contador
            fread(&reg,sizeof(reg),1,arch); // Doy la segunda lectura que determina si se repite el bucle o ese era el ultimo socio registrado

	     }
	   }
	printf("\n\n");system("pause");
	printf("\n\n");
	fclose(arch); // Cierro el archivo "socios.dat"

}

	
int validarCaracter(char aux){
	FILE *arch;
	arch= fopen("Prueba.Socios.dat","rb");
	socios reg;
	
	fread(&reg,sizeof(reg),1,arch);
	
	while(!feof(arch)){
		if(aux=='s' or aux =='S' or aux=='N' or aux=='n'){
			return 1;
		}else{
			fread(&reg,sizeof(reg),1,arch);
		}
		fclose(arch);
		return 0;
	}
}

int validarDia(int dia){
	FILE *arch;
	arch = fopen("PruebaSocios.dat","rb");
	socios reg;
	
	fread(&reg,sizeof(reg),1,arch);
	
	while(!feof(arch)){
		if(dia<1 or dia>30){
			fclose(arch);
			return 0;
		}else{
			fread(&reg,sizeof(reg),1,arch);
		}
		fclose(arch);
		return 1;
	}
}
int validarMes(int mes){
	FILE *arch;
	arch = fopen("PruebaSocios.dat","rb");
	socios reg;
	
	fread(&reg,sizeof(reg),1,arch);
	
	while(!feof(arch)){
	 if(mes<1 or mes>12){
		fclose(arch);
		return 0;
	}else{
		fread(&reg,sizeof(reg),1,arch);
	}
	fclose(arch);
	return 1;
	}
	
}
int validarSocio(int soc){
	FILE *arch;
	arch = fopen("PruebaSocios.dat","rb");
	socios reg;
	
	fread(&reg,sizeof(reg),1,arch);
	
	while(feof(arch)){
		return 1;
	}
	
	while(!feof(arch)){
		if(reg.numSocio==soc){
			fclose(arch);
			return 0;
		}else{
			fread(&reg,sizeof(reg),1,arch);
		}
		fclose(arch);
		return 1;
	}
	
}

void registrarSocios(){
	system("cls");
	socios reg;
	FILE *arch;
	int b=0;
	arch=fopen("PruebaSocios.dat","a+b");
	
	printf("\n\n\t\t----------------------------%c REGISTRO DE SOCIOS %c----------------------------\n", 04, 04);
	do{
		printf("\n\n + Nombre y Apellido: "); _flushall();
		gets(reg.nomyape);
		
		printf("\n + Documento: ");
		scanf("%d",&reg.DNI);
		printf("\n + Direccion: "); _flushall(); gets(reg.direccion);
		
		printf("\n + Telefono: ");
		scanf("%d",&reg.tel);
		
		printf("\n + Peso: "); scanf("%d",&reg.peso);
		
		do{
		printf("\n + Numero de Socio: ");
		scanf("%d",&reg.numSocio);
		
		if(!(validarSocio(reg.numSocio))){
			printf("\n Este numero de socio ya esta ocupado, intente nuevamente. . .\n");
		}
		
		}while(!(validarSocio(reg.numSocio)));
		 
		/* INDICACIONES MEDICAS */
		
		printf("\n\n -------%c INDICACIONES MEDICAS &c-------\n ",04,04);
		
		printf("Si esta en condiciones de realizar la actividad ingrese [S]. De lo contrario ingrese [N]");
	    
	    do{
		
		printf("\n\nZumba: ");
		_flushall();
		scanf("%c",&reg.indMedicas.zum);
		if(!(validarCaracter(reg.indMedicas.zum))){
			printf("Caracter invalido, intente nuevamente . . .\n");
		}
	   }while(!(validarCaracter(reg.indMedicas.zum)));
	    
	    do{
		
		printf("\nSpining: ");
		_flushall();
		scanf("%c",&reg.indMedicas.spin);
		 if(!(validarCaracter(reg.indMedicas.spin))){
			printf("Caracter invalido, intente nuevamente . . .\n");
		 }
	    }while(!(validarCaracter(reg.indMedicas.spin)));
	    
	    do{
		
		printf("\nPilates: ");
		_flushall();
		scanf("%c",&reg.indMedicas.pil);
	      if(!(validarCaracter(reg.indMedicas.pil))){
	      	printf("Caracter invalido, intente nuevamente . . .\n");
		  }
		}while(!(validarCaracter(reg.indMedicas.pil)));
		
		/* ----------------------------------------------------------- */
		
		printf("\n\n -------%c FECHA DE INGRESO &c-------\n ",04,04);
		do{
			printf("Dia: ");scanf("%d",&reg.fec_ingreso.dia); 
			if(!(validarDia(reg.fec_ingreso.dia))){
				printf("\n Este Dia es invalido, intente nuevamente. . .\n");
			}
		}while(!(validarDia(reg.fec_ingreso.dia)));
	
		
		do{
		 printf("\nMes: ");scanf("%d",&reg.fec_ingreso.mes);
		  if(!(validarMes(reg.fec_ingreso.mes))){
			 printf("\n Este mes es invalido, intente nuevamente. . .\n");
			}
		}while (!(validarMes(reg.fec_ingreso.mes)));
	    
		
		printf("\nA%co: ",164);scanf("%d",&reg.fec_ingreso.anio);
		
		fwrite(&reg,sizeof(reg),1,arch);
		printf("Si desea ingresar un nuevo socio ingrese [0] de lo contrario ingrese [1]: ");
		scanf("%d",&b);
		
	}while(b==0);
}

void MenuRecepcion(){
	system("cls");
	int op;
	printf("\n\n\t\t--------------------------%c MENU DE RECEPCIONISTAS %c--------------------------\n", 04, 04);
   
    printf("\n\n\t\t[1].Registrar Socios.");
    printf("\n\n\t\t[2].Listar Socios.");
    printf("\n\n\t\t[3].Volver al Menu Principal.");
    
	printf("\n\n\t\t[Elija su opcion]:");
    scanf("%d",&op);
    
    switch(op){
 	case 1: registrarSocios();
 		break;
 	case 2: listarSocios();
 	    break;
 	case 3: MenuPrincipal();
 	    break;
 }
}

void SesionRecepcion(){
	system("cls");
	FILE *archivo;
	archivo = fopen("PruebaUsuarios.dat", "rb");
	user aux;
	int cod=1;
	char nick[20],contra[40];
	
	while(cod==1)
	{
		rewind(archivo);
		printf("\n\n\t\t---------------------%c INICIO DE SESION - RECEPCIONISTAS %c---------------------\n", 04, 04);
		_flushall();
		printf("\n %c Ingrese el nombre de usuario: ", 04); gets(nick);
		printf("\n %c Ingrese la contrase%ca: ", 04, 164); gets(contra);

		fread(&aux, sizeof(user), 1, archivo);
		while(!feof(archivo))
		{

			if(aux.tipo==2 and strcmp(aux.nick, nick)==0 and  strcmp(aux.pass, contra)==0)
			{
				fclose(archivo);
				printf("\n\n %c%c Presione una tecla para ingresar al sistema...", 33, 33); getchar(); system("CLS");
				MenuRecepcion();//Retorna 1 en caso de que haya coincidencia con la base de datos
			}
			else fread(&aux, sizeof(aux), 1, archivo);

		}

		printf("\n %c%c Nombre de usuario y/o contrase%ca INCORRECTOS\n\n", 33, 33, 164);
		printf("\n\n %c Ingrese 1 si quiere intentar nuevamente, o ingrese  0 para salir: ", 04); scanf("%d", &cod);
		system("CLS");

	 }
    

	fclose(archivo);
	
	
}