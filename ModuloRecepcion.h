//Libreria del Modulo Recepcion


void listarSocios(){
	 socios reg;
	 FILE *arch;

		// En caso de ser otro los nombres de la estructura socios o el archivo se deberan modificar ciertas caracteristicas del codigo a continuacion

	   system("cls");

	   arch=fopen("../Base_de_datos/Socios.dat","rb"); // Abro el archivo binario "socios.dat" que contiene los datos de los socios previamente ingresado
	   int cont=1; // Declaro un contador para ver la cantidad de socios que se van a listar
	   rewind(arch); // Coloco el puntero al inicio del archivo binario

	   fread(&reg,sizeof(reg),1,arch);  // Doy la primera lectura dentro del archivo
       
       printf("\n\t\t------------%cSOCIOS REGISTRADOS%c------------\n",04,04);
       
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
	   
	printf("\n\n");system("pause");
	printf("\n\n");
	fclose(arch); // Cierro el archivo "socios.dat"

}

	
int validarCaracter(char aux){
	
	if(aux == 'S' or aux == 's' or aux == 'n' or aux == 'N'){
	   return 1;	
	}else{
		return 0;
	}
}

int validarDia(int dia){
 
 if(dia<1 or dia>30){
		return 0;
	}else{
		return 1;
	 }
}

int validarMes(int mes){
	
	if(mes<1 or mes>12){
		return 0;
	}else{
		return 1;
	 }
	
}


int validarSocio(int soc){
	FILE *arch;
	arch = fopen("../Base_de_datos/Socios.dat","rb");
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
	}
	
   	fclose(arch);
	return 1;	
}

void registrarSocios(){
	system("cls");
	socios reg;
	FILE *arch;
	int b=0;
	arch=fopen("../Base_de_datos/Socios.dat","a+b");
	
	printf("\n\n ----------------------------%c REGISTRO DE SOCIOS %c----------------------------\n", 04, 04);
	do{
		printf("\n\n + Nombre y Apellido: "); _flushall();
		gets(reg.nomyape);
		
		printf("\n + Documento: ");
		scanf("%d",&reg.DNI);
		printf("\n + Direccion: "); _flushall(); gets(reg.direccion);
		
		printf("\n + Telefono: ");
		scanf("%d",&reg.tel);
		
		printf("\n + Peso [KG]: "); scanf("%d",&reg.peso);
		
		do{
		printf("\n + Numero de Socio: ");
		scanf("%d",&reg.numSocio);
		
		if(!(validarSocio(reg.numSocio))){
			printf("\n Este numero de socio ya esta ocupado, intente nuevamente. . .\n");
		}
		
		}while(!(validarSocio(reg.numSocio)));
		 
		/* INDICACIONES MEDICAS */
		
		printf("\n\n -------%c INDICACIONES MEDICAS %c-------\n ",04,04);
		
		printf("Si esta en condiciones de realizar la actividad ingrese [S]. De lo contrario ingrese [N]");
	    
	    do{
		
		printf("\n\n + Zumba: ");
		_flushall();
		scanf("%c",&reg.indMedicas.zum);
		if(!(validarCaracter(reg.indMedicas.zum))){
			printf("Caracter invalido, intente nuevamente . . .\n");
		}
	   }while(!(validarCaracter(reg.indMedicas.zum)));
	    
	    do{
		
		printf("\n + Spining: ");
		_flushall();
		scanf("%c",&reg.indMedicas.spin);
		 if(!(validarCaracter(reg.indMedicas.spin))){
			printf("Caracter invalido, intente nuevamente . . .\n");
		 }
	    }while(!(validarCaracter(reg.indMedicas.spin)));
	    
	    do{
		
		printf("\n + Pilates: ");
		_flushall();
		scanf("%c",&reg.indMedicas.pil);
	      if(!(validarCaracter(reg.indMedicas.pil))){
	      	printf("Caracter invalido, intente nuevamente . . .\n");
		  }
		}while(!(validarCaracter(reg.indMedicas.pil)));
		
		/* ----------------------------------------------------------- */
		
		printf("\n\n -------%c FECHA DE INGRESO %c-------\n ",04,04);
		do{
			printf("+ Dia: ");scanf("%d",&reg.fec_ingreso.dia); 
			if(!(validarDia(reg.fec_ingreso.dia))){
				printf("\n Este Dia es invalido, intente nuevamente. . .\n");
			}
		}while(!(validarDia(reg.fec_ingreso.dia)));
	
		
		do{
		 printf("\n + Mes: ");scanf("%d",&reg.fec_ingreso.mes);
		  if(!(validarMes(reg.fec_ingreso.mes))){
			 printf("\n Este mes es invalido, intente nuevamente. . .\n");
			}
		}while (!(validarMes(reg.fec_ingreso.mes)));
	    
		
		printf("\n + A%co: ",164);scanf("%d",&reg.fec_ingreso.anio);
		
		fwrite(&reg,sizeof(reg),1,arch);
		printf("Si desea ingresar un nuevo socio ingrese [0] de lo contrario ingrese [1]: ");
		scanf("%d",&b);
		
	}while(b==0);
}

void MenuRecepcion(){
	system("cls");
	int op;
	printf("\n\n\t\t--------------------------%c MENU DE RECEPCIONISTAS %c--------------------------\n", 04, 04);
   
    printf("\n\n [1].Registrar Socios.");
    printf("\n\n [2].Listar Socios.");
    
	printf("\n\n [Elija su opcion]: ");
    scanf("%d",&op);
    
    switch(op){
 	case 1: registrarSocios();
 		break;
 	case 2: listarSocios();
 	    break;
 	
 }
}

void SesionRecepcion(){
	system("cls");
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Usuarios.dat", "rb");
	user aux;
	int cod=1;
	char nick[20],contra[40];
	
	while(cod==1)
	{
		rewind(archivo);
		printf("\n\n---------------------%c INICIO DE SESION - RECEPCIONISTAS %c---------------------\n", 04, 04);
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

//---------------------------------------------------------------------------------------------------------------------------------------------//




//--------------------------------------------------- SECCION REGISTRAR SOCIO EN UNA RUTINA --------------------------------------------------//

int validarSocios1(int soc) // Determina si un numero de socio esta registrado- HAY QUE BORRAR ESTA FUNCION
{
	FILE *arch;
	arch = fopen("../Base_de_datos/Socios.dat","rb");
	socios reg;
	
	fread(&reg,sizeof(reg),1,arch);
	
	if(arch==NULL)
	{
		return 0;
	}
	
	if(feof(arch))
	{
		return 0;
	}
	
	while(!feof(arch))
	{
		if(reg.numSocio==soc)
		{
			fclose(arch);
			return 1;
			
		}else{
			fread(&reg,sizeof(reg),1,arch);
		}	
	}
	
	fclose(arch);
	return 0;
	
}

//[*]Validaciones
int validarActividadConEntrenador(int legEntrenador, int numSocio) // Valida que exista una actividad en comun entre entrenador y socio
{
	FILE *arc;
	arc = fopen ("../Base_de_datos/Socio-Act.dat", "rb");
	socioAct aux;
	
	if(arc==NULL)
	{
		fclose(arc);
		return 0;	//Si el archivo no existe, entonces el socio no tiene ninguna actividad en comun con el entrenador
	}
	
	else
	{
		fread(&aux, sizeof(socioAct), 1, arc);
		
		if(feof(arc))
		{
			fclose(arc);
			return 0; // Si el archivo esta vacio, entonces el socio no tiene ninguna actividad en comun con el entrenador
		}
		
		while(!feof(arc))
		{
			if(aux.numSocio==numSocio)
			{
				if(aux.legajo_Entrenador==legEntrenador)
				{
					fclose(arc);
					return 1;
				} else fread(&aux, sizeof(socioAct), 1, arc);
				
			}else fread(&aux, sizeof(socioAct), 1, arc);
		}
	}
	
	fclose(arc); 
	return 0;
	
	
}


int validarRutina(int codRut, int leg)// Valida que la rutina exista y le pertenezca a ese entrenador
{
	FILE *arc;
	arc = fopen ("../Base_de_datos/Rutinas.dat", "rb");
	rutina aux;

	if(arc==NULL)
	{
		fclose(arc); //Retorna 0, ya que el entrenador no tiene registrada ninguna rutina: el archivo no existe.
		return 0;
	}
	
	if(feof(arc))
	{
		fclose(arc); //Retorna 0, ya que el entrenador no tiene registrada ninguna rutina: el archivo esta vacio.
		return 0;	
	}	
	else
	{
		fread(&aux, sizeof(rutina), 1, arc);
		while(!feof(arc))
		{
			if(aux.legajoEntrenador==leg)
			{
				if(aux.CodRut==codRut)
				{
					fclose(arc);
					return 1;
				}else fread(&aux, sizeof(rutina), 1, arc);
				
			}else fread(&aux, sizeof(rutina), 1, arc);
			
		}
	}
	fclose(arc);
	return 0;
	
}


//[*] Impresion 
int mostrarRutinas_Entrenador(int legEntrenador)//Recibe el numero de legajo de un entrenador, e imprime las rutinas que tiene registrada
{
	FILE *arc;
	arc = fopen ("../Base_de_datos/Rutinas.dat", "rb");
	rutina aux;
	int i=0;
	
	if(arc==NULL)
	{
		fclose(arc); //Retorna 0, ya que el entrenador no tiene registrada ninguna rutina: el archivo no existe.
		return 0;
	}
	
	if(feof(arc))
	{
		fclose(arc); //Retorna 0, ya que el entrenador no tiene registrada ninguna rutina: el archivo esta vacio.
		return 0;	
	}	
	else
	{
		fread(&aux, sizeof(rutina), 1, arc);
		
		system("cls");
		printf("\n\n-----------------------%c REGISTRAR ACTIVIDAD DE SOCIO %c-------------------------\n", 04, 04);
				
				
		while(!feof(arc))
		{
			if(aux.legajoEntrenador==legEntrenador)
			{
				if(i==0)
				{
					printf("\n %c Rutinas disponibles para este entrenador: \n\n");
					printf(" > ---------------------------------------------------------- < \n", 04, 04);
				} 
				
			
				printf("\n %c Codigo de la rutina: %d\n\n", 26, aux.CodRut);
				printf("\n %c Tipo de actividad a la que esta destinada la rutina: ", 26);
				if(aux.tipo=='Z') printf(" ZUMBA \n");
				if(aux.tipo=='P') printf(" PILATES \n");
				if(aux.tipo=='S') printf(" SPINING \n");
				
				printf("\n > ---------------------------------------------------------- < \n", 04, 04);
					
				fread(&aux, sizeof(rutina), 1, arc);
				i++;
				
			}else fread(&aux, sizeof(rutina), 1, arc);
		}	
	}
	
	fclose(arc);
	return 1;
	
	
}

void mostrarRutinasDeSocios()//Muestra las rutinas que debe realizar cada socio
{
	FILE *arc;
	arc = fopen ("../Base_de_datos/Socios-Rut.dat", "a+b");
	socioRut nuevo;
		
	system("cls");
	printf("\n\n--------------------------%c RUTINAS DE LOS SOCIOS %c-----------------------------\n", 04, 04);	
	
	fread(&nuevo, sizeof(socioRut), 1, arc);
	while(!feof(arc))
	{
	
		printf("\n %c Numero de socio: %d \n", 04, nuevo.numSocio);
		printf("\n %c Codigo de la rutina: %d \n", 04, nuevo.CodRut);
		fread(&nuevo, sizeof(socioRut), 1, arc);
		printf("\n %c ---------------- %c \n", 04, 04);
	}
	
	printf("\n\n -"); system("pause");
	fclose(arc);
}



//[+] Manipulacion de archivos
void crearSocioRut(socioRut nuevo)//Crea y guarda el dato relacional en Socios-rut.dat
{
	FILE *arc;
	arc = fopen ("../Base_de_datos/Socios-Rut.dat", "a+b");
	
	fwrite(&nuevo, sizeof(socioRut), 1, arc);
	
	fclose(arc);
}


//[1] Funcion principal
int registrarSocio_Rutina() // Registra una rutina para el socio
{
	int numAux, legAux, repeticion=0, rut, confirmacion=0;
	socioRut nuevo;
	
	do
	{
		system("cls");
		printf("\n\n-----------------------%c REGISTRAR ACTIVIDAD DE SOCIO %c-------------------------\n", 04, 04);
		
		
		printf("\n %c Ingrese el numero de socio a registrar: ", 04); scanf("%d", &numAux);
	
		if(validarSocios1(numAux))
		{
			nuevo.numSocio=numAux;
			
			printf("\n\n %c Numero del entrenador que quiere asignar rutina: ", 04); scanf("%d", &legAux);
			if(validarActividadConEntrenador(legAux, numAux))
			{
				if(mostrarRutinas_Entrenador(legAux))
				{
					printf("\n\n\n %c Ingrese el codigo de la rutina seleccionada: ", 04); scanf("%d", &rut);
					
					if(validarRutina(rut, legAux))
					{
						nuevo.CodRut=rut;
						
						system("cls");
						printf("\n\n-----------------------%c REGISTRAR ACTIVIDAD DE SOCIO %c-------------------------\n", 04, 04);
						printf("\n %c Informacion ingresada: \n", 04);
						printf("\n %c Numero de socio: %d \n", 04, nuevo.numSocio);
						printf("\n %c Codigo de la rutina: %d \n", 04, nuevo.CodRut);
						
						printf("\n\n %c Ingrese 1 para confirmar el registro: ", 26); scanf("%d", &confirmacion);
						if(confirmacion) 
						{
							printf("\n %c El registro se realizo exitosamente...\n\n", 33);
							printf("\n\n -"); system("pause");
							crearSocioRut(nuevo);
							return 1;
							
							
						}else printf("\n\n %c No se ha completado el registro...", 33);
						
						
						
					}else printf("\n %c Se ingreso un codigo de rutina incorrecto\n\n", 33); 
					
					
				}else printf("\n %c El entrenador no tiene rutinas creadas...\n", 33);
				
			}else printf("\n\n %c El entrenador no tiene este socio a cargo...\n", 33);
			
		}else printf("\n %c No se ha encontrado un socio con este numero...\n", 33);
		
		printf("\n\n\n %c Ingrese 1 si quiere volver a intentar: ", 04); scanf("%d", &repeticion);
		
	}while(repeticion==1);
	
	return 0;
	
}


//---------------------------------------------------------------------------------------------------------------------------------------------//
