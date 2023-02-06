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
       
     	printf("\n\n-----------------------------%c SOCIOS REGISTRADOS %c-----------------------------\n", 04, 04);
       
	     while(!feof(arch)){
	     	printf("-------------------------");
            printf("\n     SOCIO NUMERO [%d]\n",cont);  // De lo contrario imprimira los siguientes datos en pantalla
            printf("-------------------------\n");
            printf("\n %c Nombre: %s\n",26,reg.nomyape);
            printf(" %c DNI:%d\n",26 ,reg.DNI);
            printf(" %c Telefono:%d\n",26,reg.tel);
            printf(" %c Direccion: %s\n",26,reg.direccion);
            printf(" %c Numero de Socio:%d\n\n",26,reg.numSocio);
            
            printf("\n %c INDICACIONES MEDICAS\n\n", 04);
            printf(" %c Zumba:%c \n", 04,reg.indMedicas.zum);
            printf(" %c Spining:%c \n", 04,reg.indMedicas.spin);
            printf(" %c Pilates:%c \n\n", 04,reg.indMedicas.pil);
            
           
            
            printf("\n %c FECHA DE INGRESO\n\n", 254 );
            printf(" %c Dia:%d\n", 254, reg.fec_ingreso.dia);
            printf(" %c Mes:%d\n", 254,reg.fec_ingreso.mes);
            printf(" %c A%co:%d\n\n", 254, 164, reg.fec_ingreso.anio);
            
            printf("\n\n---------------------------- %c ------------------ %c ----------------------------\n", 04, 04);
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
	

	if(feof(arch) or arch==NULL)
	{
		fclose(arch);
		return 1;
	}
	
	while(!feof(arch))
	{
		if(reg.numSocio==soc)
		{
			fclose(arch);
			return 0;
		}else
		{
			fread(&reg,sizeof(reg),1,arch);
		}
	}
	
   	fclose(arch);
	return 1;	
}

void registrarSocios()
{
	system("cls");
	socios reg;
	FILE *arch;
	int b=0, cod=1;
	arch=fopen("../Base_de_datos/Socios.dat","a+b");
	
	do{
		printf("\n\n-----------------------------%c REGISTRO DE SOCIOS %c-----------------------------\n", 04, 04);
		printf("\n + Nombre y Apellido: "); _flushall();
		gets(reg.nomyape);
		
		printf("\n + Documento: ");
		scanf("%d",&reg.DNI);
		printf("\n + Direccion: "); _flushall(); gets(reg.direccion);
		
		_flushall();
		printf("\n + Telefono: "); 
		scanf("%d",&reg.tel);
		
		_flushall();
		printf("\n + Peso [KG]: "); scanf("%d",&reg.peso);
		_flushall();
		
		do{
		printf("\n %c Numero de Socio: ", 26);
		scanf("%d",&reg.numSocio);
		
		if(!validarSocio(reg.numSocio))
		{
			printf("\n %c%c Este numero de socio ya esta ocupado, intente nuevamente. . .\n\n",33,33);
		}
		
		}while(!validarSocio(reg.numSocio));
		 
		/* INDICACIONES MEDICAS */
		
		printf("\n\n\n - "); system("pause"); system("cls"); 
		
		printf("\n\n-----------------------------%c REGISTRO DE SOCIOS %c-----------------------------\n", 04, 04);
		
		printf("\n %c INDICACIONES MEDICAS %c \n ", 33,33);
		printf("\n %c Ingrese [S] si puede realizar la actividad. Caso contrario ingrese [N]: \n", 26);
	    
	    do{
		
		printf("\n\n + Zumba: ");
		_flushall();
		scanf("%c",&reg.indMedicas.zum);
		if(!(validarCaracter(reg.indMedicas.zum))){
			printf("\n %c Caracter invalido, intente nuevamente . . .\n",33);
		}
	   }while(!(validarCaracter(reg.indMedicas.zum)));
	    
	    do{
		
		printf("\n + Spining: ");
		_flushall();
		scanf("%c",&reg.indMedicas.spin);
		 if(!(validarCaracter(reg.indMedicas.spin))){
			printf("\n %c Caracter invalido, intente nuevamente . . .\n",33);
		 }
	    }while(!(validarCaracter(reg.indMedicas.spin)));
	    
	    do{
		
		printf("\n + Pilates: ");
		_flushall();
		scanf("%c",&reg.indMedicas.pil);
	      if(!(validarCaracter(reg.indMedicas.pil))){
	      	printf("\n %c Caracter invalido, intente nuevamente . . .\n", 33);
		  }
		}while(!(validarCaracter(reg.indMedicas.pil)));
		
		/* ----------------------------------------------------------- */
		
		printf("\n\n\n - "); system("pause"); system("cls"); 
		printf("\n\n-----------------------------%c REGISTRO DE SOCIOS %c-----------------------------\n", 04, 04);
		
		printf("\n\n %c FECHA DE INGRESO %c \n ",33,33);
		do{
			printf("\n + Dia: ");scanf("%d",&reg.fec_ingreso.dia); 
			if(!(validarDia(reg.fec_ingreso.dia))){
				printf("\n %c Este Dia es invalido, intente nuevamente. . .\n\n", 33);
			}
		}while(!(validarDia(reg.fec_ingreso.dia)));
	
		
		do{
		 printf("\n + Mes: ");scanf("%d",&reg.fec_ingreso.mes);
		  if(!(validarMes(reg.fec_ingreso.mes))){
			 printf("\n %c Este mes es invalido, intente nuevamente. . .\n\n", 33);
			}
		}while (!(validarMes(reg.fec_ingreso.mes)));
	    
		do
		{
			printf("\n + A%co: ",164);scanf("%d",&reg.fec_ingreso.anio);
			if(reg.fec_ingreso.anio>2000 and reg.fec_ingreso.anio<2100) cod=0;
			else printf("\n %c Ingrese un año del siglo 21. . .\n\n", 33); 
		}while (cod==1);
		
		
		fwrite(&reg,sizeof(reg),1,arch);
		printf("\n\n\n %c Si desea ingresar un nuevo socio ingrese [0] de lo contrario ingrese [1]: ", 26);
		scanf("%d",&b);
		system("cls");
		
	}while(b==0);
}

//------------------------------------------------------- MENU PRINCIPAL -------------------------------------------------------------------//

void registrarActividad_Socio();
void imprimirFechasDePago_Socios();
int registrarSocio_Rutina();
void mostrarRutinasDeSocios();

void MenuRecepcion(){
	system("cls");
	int op;
	printf("\n\n---------------------------%c MENU DE RECEPCIONISTAS %c---------------------------\n", 04, 04);
   
    printf("\n [1].Registrar Socios. ");
    printf("\n\n [2].Listar Socios. ");
    printf("\n\n [3].Registrar Socio en una Actividad. ");
    printf("\n\n [4].Fecha de Pago Socios. ");
    printf("\n\n [5].Agregar una Rutina a un Socio. ");
    printf("\n\n [6].Mostrar rutinas de los socios. ");
    
    printf("\n\n [0].Salir. ");
    
	printf("\n\n\n\n [Elija su opcion]: ");
    scanf("%d",&op);
    
    switch(op){
    	
    case 0: system("cls"); exit(1);	
    	
 	case 1: registrarSocios();
 		break;
 		
 	case 2: listarSocios();
 	    break;
 	    
 	case 3: registrarActividad_Socio();
 		break;
 		
 	case 4: imprimirFechasDePago_Socios();
 		break;
 		
 	case 5: registrarSocio_Rutina();
	 	break;	
	 	
	case 6: mostrarRutinasDeSocios();
		break;
 	
 }
}


void SesionRecepcion(){
	system("cls");
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Usuarios.dat", "rb");
	user aux;
	int cod=1, athu=0;
	char nick[20],contra[40];
	
	while(cod==1)
	{
		if(athu==0)
		{
			rewind(archivo);
			printf("\n\n----------------------%c INICIO DE SESION - RECEPCIONISTAS %c---------------------\n", 04, 04);
			_flushall();
			printf("\n %c Ingrese el nombre de usuario: ", 04); gets(nick);
			printf("\n %c Ingrese la contrase%ca: ", 04, 164); gets(contra);	
		}

		fread(&aux, sizeof(user), 1, archivo);
		while(!feof(archivo))
		{

			if(aux.tipo==2 and strcmp(aux.nick, nick)==0 and  strcmp(aux.pass, contra)==0)
			{
				fclose(archivo);
				printf("\n\n %c%c Presione una tecla para ingresar al sistema...", 33, 33); getchar(); system("CLS");
				athu=1;
				MenuRecepcion();//Retorna 1 en caso de que haya coincidencia con la base de datos
			}
			else fread(&aux, sizeof(aux), 1, archivo);

		}
		
		if(athu==0)
		{
			printf("\n %c%c Nombre de usuario y/o contrase%ca INCORRECTOS\n\n", 33, 33, 164);
			printf("\n\n %c Ingrese 1 si quiere intentar nuevamente, o ingrese  0 para salir: ", 04); scanf("%d", &cod);
			system("CLS");	
		}
		

	 }
    

	fclose(archivo);
	
	
}

//---------------------------------------------------------------------------------------------------------------------------------------------//




//--------------------------------------------------- SECCION REGISTRAR SOCIO EN UNA RUTINA --------------------------------------------------//

int validarSocios1(int soc) // Determina si un numero de socio esta registrado
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
		printf("\n\n-------------------------%c REGISTRAR RUTINA DE SOCIO %c--------------------------\n", 04, 04);
		
		
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
							printf("\n\n-------------------------%c REGISTRAR RUTINA DE SOCIO %c--------------------------\n", 04, 04);
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



//--------------------------------------------------- SECCION REGISTRAR SOCIOS EN UNA ACTIVIDAD ----------------------------------------------//

//[*]Validaciones y adicionales
int comprobarActividad_Socio(char tipo, int numSocio) //Comprueba si el socio puede desarrollar una actividad
{
	FILE *arch;
	arch = fopen("../Base_de_datos/Socios.dat","rb");
	socios reg;
	
	fread(&reg,sizeof(reg),1,arch);
	
	if(feof(arch))
	{
		return 1;
	}
	
	while(!feof(arch))
	{
		if(reg.numSocio==numSocio)
		{
			if(tipo=='Z' or tipo=='z')
			{	
				if(reg.indMedicas.zum=='S' or reg.indMedicas.zum=='s')
				{
					fclose(arch);
					return 1;
					
				}else
				{
					fclose(arch);
					return 0;	
				} 
			}	
			
			
			if(tipo=='P' or tipo=='p')
			{	
				if(reg.indMedicas.pil=='S' or reg.indMedicas.pil=='s')
				{
					fclose(arch);
					return 1;
					
				}else
				{
					fclose(arch);
					return 0;	
				} 
			}	
			
			
			if(tipo=='S' or tipo=='s')
			{	
				if(reg.indMedicas.spin=='S' or reg.indMedicas.spin=='s')
				{
					fclose(arch);
					return 1;
					
				}else
				{
					fclose(arch);
					return 0;	
				} 
			}		
			
		}else 	fread(&reg,sizeof(reg),1,arch);
		
	}
	
	fclose(arch);
	return 0;
	
}


int turnoInscripto_Socio(int nSocio, char cod[5]) //Devuelve un 1 si el socio esta inscripto en esa actividad, 0 en caso contrario
{
	int i=0;
	FILE *arc;
	socioAct aux;
	
	arc = fopen ("../Base_de_datos/Socio-Act.dat", "rb");

	if(arc==NULL)
	{
		fclose(arc);
		return 0;	//Si el archivo no existe, entonces el socio no esta inscripto a ninguna actividad
	}
	
	else
	{
		fread(&aux, sizeof(socioAct), 1, arc);
		
		if(feof(arc))
		{
			fclose(arc);
			return 0; // Si el archivo esta vacio, entonces el socio no esta inscripto a ninguna actividad
		}
		
		while(!feof(arc))
		{
			if(aux.numSocio==nSocio)
			{
				if (strcmp(cod, aux.cod)==0)
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


int validarActividad_Socio(char cod[5], char tipo) //Devuelve 1 si la actividad existe, 0 en caso contrario
{
	FILE *arc;
	arc= fopen("../Base_de_datos/Actividades.dat","rb");
	actividades aux; 
	
	fread(&aux, sizeof(aux), 1, arc);	
	while(!feof(arc))
	{
		
		if(tipo==aux.cod[0])
		{
			if(strcmp(aux.cod,cod)==0)
			{
				fclose(arc);
				return 1;
				
			}else fread(&aux, sizeof(aux), 1, arc);	
			
		}else fread(&aux, sizeof(aux), 1, arc);	
	
	}
	fclose(arc);
	return 0;
	
}


int entrenadorACargo_Actividad(char cod[5]) //Recibe el codigo de una actividad y retorna el legajo del entrenador encargado
{
	FILE *arc;
	arc= fopen("../Base_de_datos/Actividades.dat","rb");
	actividades aux; 
	
	fread(&aux, sizeof(aux), 1, arc);	
	while(!feof(arc))
	{
		
		if(strcmp(cod, aux.cod)==0)
		{
		 	fclose(arc);			
			return aux.legEntrenador;		
				
		}else fread(&aux, sizeof(aux), 1, arc);	
	
	}
	fclose(arc);
	return 0;	
	
}



//[+]Funciones de impresion
int mostrarTipo_Actividad(char inicial) //Muestra las actividades de un solo tipo
{
	FILE *arc;
	arc= fopen("../Base_de_datos/Actividades.dat","rb");
	actividades aux;
	int i=0;
	
	system("cls");	
	
	if(arc==NULL)
	{
		printf ("\n 			       -->>> ERROR <<<-- \n");
		printf ("\n > El archivo no existe, intente registrar una Actividad e intente nuevamente...\n");
		return 0;
	}
	
	else
	{
		printf("\n\n-----------------------%c REGISTRAR ACTIVIDAD DE SOCIO %c-------------------------\n", 04, 04);
		
		
		
		fread(&aux,sizeof(aux),1, arc);	
		while(!feof(arc))
		{
			if(aux.cod[0]==inicial)
			{
				if(i==0)
				{
					printf("\n %c TURNOS DISPONIBLES PARA LA ACTIVIDAD SELECCIONADA: \n", 04);
				}
				
				printf("\n > -------------------------------------------------- <\n");
				
				printf("\n %c Codigo de la actividad: %s  \n", 26, aux.cod);
			
				printf("\n %c Horario:  ", 04);
				switch(aux.horario)
				{
					case 1:		
						printf("10:00 A 12:00 HORAS\n");
					break;
						
					case 2:		
						printf("12:00 A 14:00 HORAS\n");
					break;
					
					case 3:		
						printf("14:00 A 16:00 HORAS\n");
					break;
					
					case 4:		
						printf("16:00 A 18:00 HORAS\n");
					break;
					
					case 5:		
						printf("18:00 A 20:00 HORAS\n");
					break;
					
					case 6:		
						printf("20:00 A 22:00 HORAS\n");
					break;					
								
				}
				char aux_nombre[61];	
				buscarNombre_Entrenador(aux.legEntrenador, aux_nombre);
				printf("\n %c Entrenador a cargo: %s\n", 04, aux_nombre); 
	
				
				fread(&aux,sizeof(aux),1, arc);	
				i++;
						
			}else fread(&aux,sizeof(aux),1, arc);
		}
		
	}
	
	if(i<=0)
	{
		printf("\n %c NO HAY TURNOS DISPONIBLES PARA LA ACTIVIDAD SELECCIONADA... \n", 04);
	}
	
	if(i>0)
	{
		printf("\n > -------------------------------------------------- <\n");	
		fclose(arc);
		return 1;
	}	
	
	return 0;

}





//[2] Funciones secundarias de la funcion registrarActividad_Socio
int ingresarTipo_Actividades(char &tipo) // Se ingresa y se valida que el tipo de actividad sea el correcto
{
	char aux;
	printf("\n\n-----------------------%c REGISTRAR ACTIVIDAD DE SOCIO %c-------------------------\n", 04, 04);
	
	//Se ingresa el caracter que representa al tipo de actividad
	printf("\n %c Tipos de actividades a Registrar: \n\n		%c [Z]: Zumba	%c [S]: Spining	%c [P]: Pilates \n", 26, 04, 04, 04);
	do
	{
		_flushall();
		printf("\n\n %c Ingrese la inicial (en MAYUSCULAS) correspondiente a la actividad: ", 04); scanf("%c", &tipo);
		
		
		if (tipo!='Z' and tipo!='S' and tipo!='P') 
		{
			printf("\n %c Se ingreso un tipo de actividad incorrecto, intente nuevamente...\n\n", 33);
			
		}
		else 
		{
			return 1;	
		}
		
	}while (tipo!='Z' and tipo!='S' and tipo!='P');
	
	return 0;
}


int buscarNombre_Socio1(int numeroSocio) //Realiza la busqueda del nombre del socio y lo imprime
{
	FILE *arc;
	socios reg;
	
	arc = fopen ("../Base_de_datos/Socios.dat", "rb");

	
	fread(&reg, sizeof(socios), 1, arc);
	
	while (!feof (arc))
	{
		if (numeroSocio == reg.numSocio)
		{
			_flushall();
			printf("\n %c Nombre del socio selccionado: %s\n\n", 04, reg.nomyape);
			printf("\n - "); system("pause"); system("cls");
			
			fclose(arc);
			return 1;
		}
		else
		{
			fread(&reg, sizeof(socios), 1, arc);
		}
	}
	fclose(arc);
	return 0;
}


int seleccionarTurno_Socio(char cod[5], char tipo) //Se selecciona el turno que desea el socio y se comprueba que no este inscripto anteriormente
{
	char codAux[5];
	do
	{
		printf("\n\n %c Ingrese el codigo del turno seleccionado: ", 26); scanf("%s", &codAux);
		if(validarActividad_Socio(codAux, tipo))
		{
			strcpy(cod, codAux);	
			return 1;
			
		}else printf("\n %c Se ha ingresado un codigo de actividad incorrecto, intente nuevamente... \n", 33);
	}	
	while(!validarActividad_Socio(cod, tipo));
	
	return 0;
}


//[*]Manipulacion de archivos
void crearSocioAct(socioAct nuevo) //Guarda el la actividad del socio en Socios-Act.dat
{
	FILE *arc;
	arc=fopen ("../Base_de_datos/Socio-Act.dat", "a+b");
	
	fwrite(&nuevo, sizeof(socioAct),1, arc);
	
	fclose(arc);
	
}


int aumentarSocios_Actividad(char cod[5]) //Recibe el codigo de una actividad y aumenta en 1 la cantidad de socios
{
	FILE *arc;
	arc = fopen("../Base_de_datos/Actividades.dat","r+b");
	actividades aux;
	
	fread(&aux,sizeof(aux),1, arc);	
	while(!feof(arc))
	{
		if(strcmp(aux.cod, cod)==0)
		{
			aux.cantParticipantes++;
			fseek(arc, -sizeof(actividades),1);
			fwrite(&aux,sizeof(aux),1, arc);
				
			fclose(arc);
			return 1;
			
		} else fread(&aux,sizeof(aux),1, arc);
	}
	
	fclose(arc);
	return 0;
	
}



//[1]Funcion Principal
void registrarActividad_Socio()
{
	int numAux, confirmacion;
	char tipoAux;
	socioAct nuevo;
	
	system("cls");
	printf("\n\n-----------------------%c REGISTRAR ACTIVIDAD DE SOCIO %c-------------------------\n", 04, 04);
	
	printf("\n %c Ingrese el numero de socio a registrar: ", 04); scanf("%d", &numAux);

	if(validarSocios1(numAux))
	{
		buscarNombre_Socio1(numAux);
		nuevo.numSocio=numAux;
		
		//[1] Se valida que se ingrese un tipo de actividad valida
		if(ingresarTipo_Actividades(tipoAux))
		{
			//[2] Se valida que el socio pueda desarrollar la actividad
			if(comprobarActividad_Socio(tipoAux, nuevo.numSocio))
			{
				//[3] Se muestran los turnos de la actividad seleccionada
				if(mostrarTipo_Actividad(tipoAux))
				{
					//[4] Se valida que se seleccione un turno correcto
					if(seleccionarTurno_Socio(nuevo.cod, tipoAux))
					{
						//[5] Se valida que el socio no este inscripto en ese turno
						if(!turnoInscripto_Socio(nuevo.numSocio, nuevo.cod))
						{
							//Se guarda el legajo del entrenador que esta a cargo de la actividad
							nuevo.legajo_Entrenador= entrenadorACargo_Actividad(nuevo.cod);
							
							printf("\n\n - "); system("pause"); system("cls");
							
							printf("\n\n-----------------------%c REGISTRAR ACTIVIDAD DE SOCIO %c-------------------------\n", 04, 04);
							
							printf("\n %c Numero del socio que se adhiere a la actividad: %d\n", 04, nuevo.numSocio);
							printf("\n %c Legajo del entrenador a cargo de la actividad: %d\n", 04, nuevo.legajo_Entrenador);
							printf("\n %c Codigo de la actividad seleccionada: %s\n", 04, nuevo.cod);
							
							
							//[6] Una vez validado, se guarda el dato en el archivo y se incrementa la cantidad de socios que desarrollan la actividad
							printf("\n\n %c Ingrese 1 para confirmar el registro: ", 26); scanf("%d", &confirmacion);
							if(confirmacion) 
							{
								printf("\n\n %c El registro se realizo exitosamente...", 33);
								printf("\n\n -"); system("pause");
								aumentarSocios_Actividad(nuevo.cod);
								crearSocioAct(nuevo);
								
							}else {printf("\n\n %c No se ha completado el registro...", 33); printf("\n\n\n - "); system("pause"); system("cls");}
							
							
							
						}else {printf("\n %c El socio ya se encuentra inscripto en este turno...\n\n", 33);printf("\n\n\n - "); system("pause"); system("cls");}
						
					}
					
				}else {printf("\n\n\n - "); system("pause"); system("cls"); exit(1);}
				
				
			}else {printf("\n %c El socio no puede realizar esta actividad por orden medica...\n\n", 33);  printf("\n\n\n - "); system("pause"); system("cls");}
		}
		
	}else
	{
		printf("\n\n %c El numero de socio no se encuentra registrado...\n", 33); printf("\n\n\n - "); system("pause"); system("cls");
	} 


	
}


//--------------------------------------------------------------------------------------------------------------------------------------------//




//--------------------------------------------------- SECCION FECHA DE PAGO DE LOS SOCIOS ----------------------------------------------------//

void calcularFechaDePago_Socio(fecha aux, char nomyape[61], int numSocio)
{
	int dia, mes, anio;
	
	anio=aux.anio;
	mes=aux.mes;
	dia=aux.dia;
	
	if(aux.mes>=1 or aux.mes<=11)
	{
		mes++;
		if(mes==2)
		{
			dia--;
		}
	}
	if(aux.mes==12)
	{
		mes=1;
		anio++;
	}
	printf("\n %c Numero de socio: %d \n\n %c Nombre del socio: %s \n",04, numSocio, 04, nomyape);
	printf("\n %c La fecha de pago del socio  es : %d-%d-%d\n", 04, dia, mes, anio);
	printf("\n---------------------%c ---------------------------------- %c---------------------", 04, 04);
	
	
}

void imprimirFechasDePago_Socios()
{
	FILE *arch;
	arch = fopen("../Base_de_datos/Socios.dat","rb");
	socios reg;
	
	system("cls");
	
	fread(&reg, sizeof(reg), 1, arch);
	
	printf("\n--------------------------%c FECHAS DE PAGO DE SOCIOS %c--------------------------", 04, 04);
	
	if(arch==NULL)
	{
		printf("\n %%c No hay socios registrados en la base de datos...");
	}
	if(feof(arch))
	{
		printf("\n %%c No hay socios registrados en la base de datos...");
	}
	
	while(!feof(arch))
	{
		calcularFechaDePago_Socio(reg.fec_ingreso, reg.nomyape, reg.numSocio);
		fread(&reg, sizeof(reg), 1, arch);	
	}
	
	fclose(arch);
	
	printf("\n\n - ");	system("pause"); system("cls");
}

//--------------------------------------------------------------------------------------------------------------------------------------------//