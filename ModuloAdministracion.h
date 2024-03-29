//Libreria del Modulo Administracion 

//---------------------------------------SECCION INICIO DE SESION ADMINISTRADORES--------------------------------------------//
int iniciarSesionAdmin()//Inicio de sesion de administradores, ingresa al archivo Usuarios.dat y comprueba la existencia del usuario
{
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Usuarios.dat", "rb");
	user aux;
	
	char nomUsuario[20], contra[40];
	int  cod=1, usuarioPermitido=1;
	
	
	while(cod==1)
	{
		rewind(archivo);
		printf("\n\n---------------------%c INICIO DE SESION - ADMINISTRADORES %c---------------------\n", 04, 04);
		_flushall();
		printf("\n %c Ingrese el nombre de usuario: ", 04); gets(nomUsuario);
		printf("\n %c Ingrese la contrase%ca: ", 04, 164); gets(contra);
		
		fread(&aux, sizeof(user), 1, archivo);
		while(!feof(archivo))
		{
		
			if(strcmp(aux.nick, nomUsuario)==0 and  strcmp(aux.pass, contra)==0)
			{
				if(aux.tipo==1)
				{
				fclose(archivo);
				printf("\n\n %c%c Presione una tecla para ingresar al sistema...", 33, 33); getchar(); system("CLS");
				return 1;//Retorna 1 en caso de que haya coincidencia con la base de datos
				}else
					{
						printf("\n\n %c%c No posee los permisos para entrar a este modulo...\n\n", 33, 33);
						usuarioPermitido=0;
						break;
					}
				
				
			}
			else fread(&aux, sizeof(aux), 1, archivo);
			
		}
		
		if(usuarioPermitido) printf("\n %c%c Nombre de usuario y/o contrase%ca INCORRECTOS\n\n", 33, 33, 164);
	
		
		printf("\n\n %c Ingrese 1 si quiere intentar nuevamente, o ingrese  0 para salir: ", 04); scanf("%d", &cod);
		system("CLS");
	
	}
	
	fclose(archivo);
	return 0;//Retorna 0 en caso de que NO haya coincidencia con la base de datos
}

//---------------------------------------------------------------------------------------------------------------------------//


//-------------------------------------SECCION REGISTRAR ADMINISTRADORES Y RECEPCIONISTAS------------------------------------//

//[!]Funciones que se relacionan con la funcion "regUser"
void crearUsuario(user nuevo);//Guarda el Usuario creado en Usuarios.dat
void mostrarUsuarios();//Muestra los usuarios guardados en Usuarios.dat
void validarNombreUsuarioAdministrador(char nick[20]);//Valida el Nombre de Usuario
void validarPassword(char pass[40]);// Valida la CONTRASEÑA

void regUser()//Funcion para registrar administradores y Recepcionistas
{
	//Inicializacion de Archivo
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Usuarios.dat", "a+b");
	fclose(archivo);
	
	int confirm=0;//Se la utiliza para confirmar la creacion del usuario
	user aux;//Declaramos la variable para guardar los datos en el archivo
	
	//Encabezado
	printf("\n\n - "); system("pause"); system("cls");	
	printf("\n\n----------------------------%c REGISTRO DE USUARIOS %c----------------------------\n", 04, 04);
	
	//Registro del tipo de usuario
	printf("\n - Tipos de usuario: \n\n	[1] ADMINISTRADOR			RECEPCIONISTA [2]\n	");	
	while(!(aux.tipo==1 or aux.tipo==2))
	{
		printf("\n + Ingrese el tipo de usuario (NUMERO): ");
		scanf("%d", &aux.tipo);
		printf("\n + Tipo de usuario seleccionado: ");if(aux.tipo==1)printf("ADMINISTRADOR \n"); if(aux.tipo==2)printf("RECEPCIONISTA \n");
		if(!(aux.tipo==1 or aux.tipo==2)) printf("\n + Tipo de usuario incorrecto, vuelva a intentar ... \n");
	}	
	
	//Ingreso del nombre y apellido de la persona
	_flushall();
	printf("\n\n + Ingrese el nombre y apellido de la persona: ");	gets(aux.apynom);
		

	//Creacion y validacion del nombre de usuario
	printf("\n\n - "); system("pause"); system("cls");	
	
	printf("\n\n----------------------------%c REGISTRO DE USUARIOS %c----------------------------\n", 04, 04);
	printf("\n ** PARA CREAR SU NOMBRE DE USUARIO, TENER EN CUENTA LOS SIGUIENTES CRITERIOS ** ");
	printf("\n * 6 caracteres como MINIMO y 10 como MAXIMO \n\n * Comenzar con una letra minuscula");
	printf("\n\n * Tener al menos 2 letras MAYUSCULAS	    \n\n * Maximo 3 digitos\n\n * Solo poseer caracteres alfanumericos o los siguientes: (+, -, /,*,?,%c,!,%c)\n\n", 168 , 173);
	
	validarNombreUsuarioAdministrador(aux.nick);//Registra y valida el Nombre de Usuario
	
	printf("\n\n----------------------------%c REGISTRO DE USUARIOS %c----------------------------\n", 04, 04);
	printf("\n ** PARA CREAR SU CONTRASE%cA, TENER EN CUENTA LOS SIGUIENTES CRITERIOS ** \n", 165);
	printf("\n * Tener entre 6 y 32 caracteres \n\n * Tener 1 minuscula, 1 mayuscula y 1 numero\n");
	printf("\n * Solo poseer caracteres alfanumericos \n\n * No tener mas de 3 numeros consecutivos (ej. 1234)\n");
	printf("\n * No tener dos letras consecutivas (ejs.: ab, aB, AB)\n\n");
	
	validarPassword(aux.pass);//Registra y valida la Contraseña de Usuario
	
	
	printf("\n\n----------------------------%c REGISTRO DE USUARIOS %c----------------------------\n", 04, 04);
	printf("\n + Ingrese 1 para CONFIRMAR el registro del usuario y 0 para cancelar: "); scanf("%d", &confirm);
	if(confirm==1) 
	{
		crearUsuario(aux);
		printf("\n\n %c Usuario %s registrado exitosamente.\n\n %c No olvide guardar su contrase%ca: %s", 04, aux.nick, 04, 164, aux.pass);
		
	} else printf("\n\n %c%c El usuario NO ha sido registrado...\n", 33, 33);
		
	
	
}


//[!]Funciones secundarias de la funcion regUser (Registrar Usuario). Las mismas se relacionan con la validacion de USUARIO Y CONTRASEÑA	

//[+]Funciones para que se relacionan con la funcion de validar NOMBRE DE USUARIO:
	
int minuscula(char car)// Funcion que indica si el caracter es miniscula
{
		if(car>96 and car<123)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
}	

int mayuscula(char car)// Funcion que indica si el caracter es mayuscula
{
		if(car>64 and car<91)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
}	

int  caracterPermitido(char car)// Determina si el caracter pertenece a un conjunto valido
{
	char simbolos[]="+-/*?¿!i";
	
	for(int i=0; i<8; i++)
	{
		if(car==simbolos[i])
		{
			return 1;
		}
	}
	
	if(minuscula(car)==1)
	{
		return 1;
	}
	
	if(mayuscula(car)==1)
	{
		return 1;
	}
	
	if(car>47 and car<58)
	{
		return 1;
	}
	
	
	return 0;
}

int cantMayusculas(char cad[20])// Determina si la cadena tiene al menos 2 mayusculas
{
	int contMay=0;
	
	for(int i=0; i<10; i++)
	{
		if(mayuscula(cad[i]))
		{
			contMay++;
		}
	}
	
	if(contMay>1) return 1;
	else return 0;
}

int tresDigitos(char cad[20])// Determina si la cadena tiene como maximo tres digitos
{
	int contDig=0;// Contador de digitos
	
	for(int i=0; i<strlen(cad); i++)
	{
		if(cad[i]>47 and cad[i]<58)
		{
			contDig++;
		}
	}
	
	if(contDig<4) return 1;
	else return 0;
}

int cadPermitida(char cad[20])// Determina si la cadena esta permitida
{
	for(int i=0; i<strlen(cad); i++)
	{
		if(!caracterPermitido(cad[i]))
		{
			return 0;
		}
	}
	
	return 1;
}

int unicidadNombreUsuario(char nomUser[20])//Determina si no existen otros nombres de usuarios iguales dentro de la base de datos
{
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Usuarios.dat", "rb");
	user aux;
	
	fread(&aux, sizeof(aux), 1, archivo);
	while(!feof(archivo))
	{
		if(strcmp(aux.nick, nomUser)==0)
		{
			fclose(archivo);	
			return 0;
		}
		else fread(&aux, sizeof(aux), 1, archivo);
		
	}
	
	fclose(archivo);

	return 1;
}



//[+]Funciones para que se relacionan con el validar contraseñas:

int esNumero(char car)//  Indica si el caracter es un numero
{
	if(car>47 and car<58) return 1;
	else return 0;
}

int priCriterio(char cad[40]) // Indica si la cadena tiene al menos un digito, una minuscula, y una Mayuscula
{
	int d=0, M=0, m=0; //Servira para identificar si se cumplen las condiciones
	
	for(int i=0; i<strlen(cad); i++)
	{
		if(minuscula(cad[i])) m=1; //Pregunta caracter por caracter, si es minuscula, mayuscula o un numero respectivamente
		if(mayuscula(cad[i])) M=1;
		if(esNumero(cad[i])) d=1;
	}
	
	if(d and m and M) return 1;
	else return 0;
	
	
}

int  esAlfanumerico(char car)// Determina si el caracter pertenece al conjunto alfanumerico
{
	
	if(minuscula(car)==1)
	{
		return 1;
	}
	
	if(mayuscula(car)==1)
	{
		return 1;
	}
	
	if(car>47 and car<58)
	{
		return 1;
	}
	
	
	return 0;
}

int alfanumericaPermitida(char cad[40])// Determina si la cadena pertenece al conjunto alfanumerico
{
	for(int i=0; i<strlen(cad); i++)
	{
		if(!esAlfanumerico(cad[i]))
		{
			return 0;
		}
	}
	
	return 1;
}

int tresNumConsecutivos(char cad[40])// Determina si la cadena posee más tres caracteres numericos consecutivos
{
	int numConsecutivos = 0, ant; // Contador de numeros consecutivos
	
	for(int i=0; i<strlen(cad); i++)
	{
		//Comprueba si es numero
		if(esNumero(cad[i])) 
		{
			//Comprueba si es primer numero de la secuencia
			if(numConsecutivos == 0) {
				ant = cad[i];	
				numConsecutivos++;
			}
			else {
				//Comprueba si es el numero siguiente al anterior
				if(  ant + 1 == cad[i] ) 
				{
					 numConsecutivos++;
					 ant = cad[i]; 
				}
				  
				else 
				{
					numConsecutivos == 1;	
					ant=cad[i];
				}
			}
					
			if (numConsecutivos > 3) return 1;
			
		}else numConsecutivos=0;
	}

	return 0;
}

int dosLetConsecutivas(char cad[40])// Determina si la cadena posee dos letras consecutivas (de forma ascendente)
{
	char anterior, aux[40];//Guarda el caracter anterior
	int contLetras=0;
	
	strcpy(aux, cad);
	strupr(aux);
		
	for(int i=0; i<strlen(aux); i++)
	{
		if(mayuscula(aux[i]))
		{
			if(contLetras==0) 
			{
				anterior=aux[i];	
				contLetras++;
			}
			else 
			{
				if(anterior==aux[i]-1) return 1;
				else 
				{
					anterior=aux[i];	
				}
			}
		}else contLetras=0;	
		
	}
	return 0;
}


//[*]Validaciones
void validarNombreUsuarioAdministrador(char nick[20])// Valida el NOMBRE DE USUARIO
{
	int atu=0; //Variable para determinar si el nombre de usuario es correcto o no
	
	while(atu==0)
	{
	_flushall();
	printf("\n\n + Ingrese el Nombre de Usuario: ");gets(nick);
		
		//Comprobacion 1
		if(minuscula(nick[0]))
		{
			//Comprobacion 2
			if(cantMayusculas(nick))
			{
				//Comprobacion 3
				if(tresDigitos(nick))
				{
					//Comprobacion 4
					if(strlen(nick)>5 and strlen(nick)<11)
					{
						//Comprobacion 5
						if(cadPermitida(nick))
						{
							if(unicidadNombreUsuario(nick))
							{
								printf("\n\n + El nombre --  %s  -- esta disponible para su uso...\n\n\n ", nick);
								atu=1;	
								
							}else printf("\n - El Nombre de usuario ya esta en uso, elija otro...\n");
							
						}else printf("\n - El Nombre de Usuario tiene caracteres no permitidos, intente nuevamente... \n");
						
					}else printf("\n - El Nombre de Usuario debe tener entre 6 y 10 caracteres, intente nuevamente.. \n");
					
				}else printf("\n - El Nombre de Usuario debe tener como MAXIMO 3 digitos, intente nuevamente... \n");
					
			}else printf("\n - El Nombre de Usuario debe tener al menos 2 MAYUSCULAS, intente nuevamente... ");
	
		}else printf("\n - El Nombre de Usuario no empieza con minuscula, intente nuevamente... \n");
	
		
	}
	printf(" - "); system("pause"); system("cls");	
}	

void validarPassword(char pass[40])// Valida la CONTRASEÑA
{
	int atu=0; //Variable para determinar si el nombre de usuario es correcto o no
	
	while(atu==0)// Se repite el ciclo mientras no se cumplan con todas las comprobaciones
	{
		_flushall();
		printf("\n\n + Ingrese la contrase%ca del usuario: ", 164);gets(pass);
		
		//Comprobacion 1
		if(priCriterio(pass))
		{
			//Comprobacion 2
			if(alfanumericaPermitida(pass))
			{
				//Comprobacion 3
				if(strlen(pass)>5 and strlen(pass)<33)
				{
					//Comprobacion 4
					if(!tresNumConsecutivos(pass))
					{
						//Comprobacion 5
						if(!dosLetConsecutivas(pass))
						{
							printf("\n\n + La contrase%ca elegida es:   %s   \n ", 164, pass);
							atu=1;
							
						}else printf("\n - La contrase%ca NO debe tener 2 letras ascendentemente consecutivas... \n", 164);
				
					}else printf("\n - La contrase%ca NO debe tener mas de 4 digitos consecutivos... \n", 164);
					
				}else printf("\n - La contrase%ca debe tener entre 6 y 32 caracteres... \n", 164);
					
			}else printf("\n - La contrase%ca solo admite caracteres alfanumericos... \n", 164);
			
		}else printf("\n - La contrase%ca necesita 1 numero, 1 letra mayuscula y 1 minuscula... \n", 164);
	
		
	}
	
		
	
	printf("\n\n - "); system("pause"); system("cls");	
}	

//[*]Manipulacion de archivos
void crearUsuario(user nuevo)//Guarda el Usuario creado en Usuarios.dat
{
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Usuarios.dat", "a+b");
	
	fwrite(&nuevo, sizeof(user), 1, archivo);
	
	fclose(archivo);
	
}

void mostrarUsuarios()//Muestra los usuarios guardados en Usuarios.dat
{
	FILE *arc;
	user aux;
	arc= fopen("../Base_de_datos/Usuarios.dat","rb");
	int i=0;
	
	printf("\n\n\n - "); system("pause"); system("cls");
		
	if(arc==NULL)
	{
		printf ("\nNo se pudo abrir el archivo");
	}
	
	else
	{
		printf("\n--------------------------- %c USUARIOS REGISTRADOS %c ---------------------------\n",04,04);
	
		fread(&aux,sizeof(user),1, arc);	
		while(!feof(arc))
		{
			printf("\n %c Apellido y nombre:  %s\n", 04, aux.apynom);
			
			printf("\n %c Tipo de usuario:  ", 04);
				if(aux.tipo==1) printf("ADMINISTRADOR\n");
				else printf("RECEPCIONISTA\n");
				
			printf("\n %c Nombre de usuario: %s \n", 04, aux.nick);
			
			printf("\n %c Contrase%ca de usuario: %s \n", 04, 164, aux.pass);
			
			printf("\n-------------------------- %c ----------------------- %c -------------------------\n",04,04);
			
			fread(&aux,sizeof(user),1, arc);	
		} 
		
		fclose(arc);
	}
	
	fclose(arc);
}
//---------------------------------------------------------------------------------------------------------------------------//




//-------------------------------------------[3] SECCION REGISTRAR ENTRENADORES ---------------------------------------------//

//[+]Funciones para que se relacionan con la funcion de validar NOMBRE DE USUARIO (del Entrenador):
int unicidadNombreEntrenador(char nomUser[20])//Determina si no existen otros nombres de usuarios (de entrenadores) iguales dentro de la base de datos
{
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Entrenadores.dat", "rb");
	entrenador aux;
	
	fread(&aux, sizeof(aux), 1, archivo);
	while(!feof(archivo))
	{
		if(strcmp(aux.nick, nomUser)==0)
		{
			fclose(archivo);	
			return 0;
		}
		else fread(&aux, sizeof(aux), 1, archivo);
		
	}
	
	fclose(archivo);

	return 1;
}

//[*]Validaciones
int validarLegajoEntrenador(int leg)//Determina si el numero de legajo es unico. Devuelve 1, en caso afirmativo.
{	
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Entrenadores.dat", "rb");
	entrenador aux;
		
	fread(&aux, sizeof(aux), 1, archivo);
	while(!feof(archivo))
	{
		if(aux.legajo==leg)
		{
			fclose(archivo);	
			return 0;
		}
		else fread(&aux, sizeof(aux), 1, archivo);
		
	}
	
	fclose(archivo);

	return 1;

	
}

void validarNombreUsuarioEntrenador(char nick[20])// Valida el NOMBRE DE USUARIO (del Entrenador)
{
	int atu=0; //Variable para determinar si el nombre de usuario es correcto o no
	
	while(atu==0)
	{
	_flushall();
	printf("\n\n + Ingrese el Nombre de Usuario: "); gets(nick);
		
		//Comprobacion 1
		if(minuscula(nick[0]))
		{
			//Comprobacion 2
			if(cantMayusculas(nick))
			{
				//Comprobacion 3
				if(tresDigitos(nick))
				{
					//Comprobacion 4
					if(strlen(nick)>5 and strlen(nick)<11)
					{
						//Comprobacion 5
						if(cadPermitida(nick))
						{
							if(unicidadNombreEntrenador(nick))
							{
								printf("\n\n + El nombre --  %s  -- esta disponible para su uso...\n\n\n ", nick);
								atu=1;	
								
							}else printf("\n - El Nombre de usuario ya esta en uso, elija otro...\n");
							
						}else printf("\n - El Nombre de Usuario tiene caracteres no permitidos, intente nuevamente... \n");
						
					}else printf("\n - El Nombre de Usuario debe tener entre 6 y 10 caracteres, intente nuevamente.. \n");
					
				}else printf("\n - El Nombre de Usuario debe tener como MAXIMO 3 digitos, intente nuevamente... \n");
					
			}else printf("\n - El Nombre de Usuario debe tener al menos 2 MAYUSCULAS, intente nuevamente... ");
	
		}else printf("\n - El Nombre de Usuario no empieza con minuscula, intente nuevamente... \n");
	
		
	}
	printf(" - "); system("pause"); system("cls");	
}	


//[*]Manipulacion de archivos
void crearEntrenador(entrenador nuevo)//Guarda el Entrenador creado en Entrenadores.dat
{
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Entrenadores.dat", "a+b");
	
	fwrite(&nuevo, sizeof(entrenador), 1, archivo);
	
	fclose(archivo);
	
}


void mostrarEntrenadores()//Muestra los Entrenadores guardados en Entrenadores.dat
{
	FILE *arc;
	arc= fopen("../Base_de_datos/Entrenadores.dat","rb");
	int i=0;
	entrenador aux;
	

	system("cls");	
	
	if(arc==NULL)
	{
		printf ("\nNo se pudo abrir el archivo");

	}
	
	else
	{
			printf("\n------------------------- %c ENTRENADORES REGISTRADOS %c -------------------------\n",04,04);
	
		fread(&aux,sizeof(aux),1, arc);	
		while(!feof(arc))
		{
			printf("\n %c Apellido y nombre:  %s\n", 04, aux.apynom);
			
			printf("\n %c Numero de Legajo:  %d\n", 04, aux.legajo);
			
			printf("\n %c Dias que trabaja:  %d\n", 04, aux.diasAtencion);
				
			printf("\n %c Nombre de usuario: %s \n", 04, aux.nick);
			
			printf("\n %c Contrase%ca de usuario: %s \n", 04, 164, aux.pass);
			
				printf("\n-------------------------- %c ---------------------- %c --------------------------\n",04,04);
			
			fread(&aux,sizeof(aux),1, arc);	
		} 
		
		fclose(arc);
	}
	
	fclose(arc);
}


void regEntrenadores()//Funcion para registrar Entrenadores
{
	//Inicializacion de Archivo
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Entrenadores.dat", "a+b");
	fclose(archivo);
	
	int confirm=0;//Se la utiliza para confirmar la creacion del entrenador
	entrenador aux;//Declaramos la variable auxiliar para guardar los datos en el archivo
	
	//Encabezado
	printf("\n "); system("pause"); system("cls");	
	printf("\n\n--------------------------%c REGISTRO DE ENTRENADORES %c--------------------------\n", 04, 04);
	
	//Se ingresa el apellido y el nombre
	_flushall();
	printf("\n + Ingrese el nombre y apellido del entrenador: ");	gets(aux.apynom);
	
	//Se ingresa la cantidad de dias de atencion, entre 1 y 6.
	_flushall();
	while (aux.diasAtencion>6 or aux.diasAtencion<=0)
	{
		printf("\n\n + Ingrese la cantidad de dias que trabaja el entrenador a la semana: ");	scanf("%d", &aux.diasAtencion);
			
		if(aux.diasAtencion>6 or aux.diasAtencion<=0) printf ("\n %c%c Ingrese una cantidad correcta... \n", 33, 33);
			
	}
	
	//Se ingresa el numero de legajo y se valida su unicidad
	do
	{
		printf("\n\n + Ingrese el legajo del entrenador: ");	scanf("%d", &aux.legajo);
			
		if(!(validarLegajoEntrenador(aux.legajo))) printf ("\n %c%c Este numero legajo ya se encuentra registrado, intente nuevamente... \n", 33, 33);		
		
	}while(!(validarLegajoEntrenador(aux.legajo)));
	
	//Creacion y validacion del nombre de usuario del entrenador
	printf("\n\n - "); system("pause"); system("cls");	
	
	printf("\n\n--------------------------%c REGISTRO DE ENTRENADORES %c--------------------------\n", 04, 04);
	printf("\n ** PARA CREAR EL NOMBRE DE USUARIO, TENER EN CUENTA LOS SIGUIENTES CRITERIOS ** \n");
	printf("\n * 6 caracteres como MINIMO y 10 como MAXIMO \n\n * Comenzar con una letra minuscula");
	printf("\n\n * Tener al menos 2 letras MAYUSCULAS	    \n\n * Maximo 3 digitos\n\n * Solo poseer caracteres alfanumericos o los siguientes: (+, -, /,*,?,%c,!,%c)\n\n", 168 , 173);
	
	validarNombreUsuarioEntrenador(aux.nick);//Registra y valida el Nombre de Usuario del Entrenador
	
	//Creacion y validacion de la contraseña
	printf("\n\n--------------------------%c REGISTRO DE ENTRENADORES %c--------------------------\n", 04, 04);
	printf("\n ** PARA CREAR SU CONTRASE%cA, TENER EN CUENTA LOS SIGUIENTES CRITERIOS ** \n", 165);
	printf("\n * Tener entre 6 y 32 caracteres \n\n * Tener 1 minuscula, 1 mayuscula y 1 numero\n");
	printf("\n * Solo poseer caracteres alfanumericos \n\n * No tener mas de 3 numeros consecutivos (ej. 1234)\n");
	printf("\n * No tener dos letras consecutivas (ejs.: ab, aB, AB)\n\n");
	
	validarPassword(aux.pass);//Registra y valida la Contraseña del entrenador
	
	printf("\n\n--------------------------%c REGISTRO DE ENTRENADORES %c--------------------------\n", 04, 04);
	printf("\n + Ingrese 1 para CONFIRMAR el registro del entrenador y 0 para cancelar: "); scanf("%d", &confirm);
	if(confirm==1) 
	{
		crearEntrenador(aux);
		printf("\n\n %c Usuario %s registrado exitosamente.\n\n %c No olvide guardar su contrase%ca: %s", 04, aux.nick, 04, 164, aux.pass);
		
	}else printf("\n\n %c%c El usuario NO ha sido registrado...\n", 33, 33);
	
	

}
//---------------------------------------------------------------------------------------------------------------------------//



//---------------------------------------[4] SECCION REGISTRO DE ACTIVIDADES ------------------------------------------------//


//[!]Funciones que se relacionan con la funcion regActividad

//[1]Funciones que ingresan y validan los datos
int ingresarTipo_Actividad(char &tipo)//Se ingresa y se valida que el tipo de actividad sea el correcto
{
	char aux;
	//Se ingresa el caracter que representa al tipo de actividad
	printf("\n\n---------------------------%c REGISTRO DE ACTIVIDADES %c--------------------------\n", 04, 04);
	printf("\n %c TIPOS DE ACTIVIDAD: \n\n		%c [Z]: Zumba	%c [S]: Spining	%c [P]: Pilates \n", 26, 04, 04, 04);
	do
	{
		_flushall();
		printf("\n %c Ingrese la inicial (en MAYUSCULAS) correspondiente a la actividad: ", 04); scanf("%c", &tipo);
		
		
		if (tipo!='Z' and tipo!='S' and tipo!='P') 
		{
			printf("\n %c Se ingreso un tipo de actividad incorrecto...\n\n", 33);
		
		}
		else 
		{
			printf("\n\n\n - "); system("PAUSE"); system("CLS");
			return 1;	
		}
	}while (tipo!='Z' and tipo!='S' and tipo!='P');
	
	return 0;
}


int disponibilidadHoraria(char tipo_actividad, int &turno)//Se ingresa y se consulta la disponibilidad de horario para una actividad determinada
{
	FILE *archivo;
	archivo=fopen("../Base_de_datos/Actividades.dat", "rb");
	
	int suma=0, i=0, array[6], valido=0;
	actividades aux;

	for(i=0; i<6; i++)
	{
		array[i]=0;
	}


	
	fread(&aux, sizeof(actividades), 1, archivo);
	while (!feof(archivo))
	{
		if(aux.tipo == tipo_actividad)
		{		
			array[aux.horario-1]=1;
			fread(&aux, sizeof(actividades), 1, archivo);
			
		}else fread(&aux, sizeof(actividades), 1, archivo);
	}
	
	fclose(archivo);
	
	
	for(int i=0; i<6; i++)
	{
		suma+=array[i];
	}
	 
	printf("\n\n---------------------------%c REGISTRO DE ACTIVIDADES %c--------------------------\n", 04, 04);
	
	if(suma<6 and suma>=0)
	{
		printf("\n\n %c TURNOS DISPONIBLES PARA LA ACTIVIDAD SELECCIONADA \n", 26);
		
		for(i=0; i<6; i++)
		{
			if(array[i]==0)
			{
				switch(i+1)
				{
					case 1:		
						printf("\n [1] - PRIMER TURNO:  10:00 A 12:00 HORAS\n");
					break;
						
					case 2:		
						printf("\n [2] - SEGUNDO TURNO: 12:00 A 14:00 HORAS\n");
					break;
					
					case 3:		
						printf("\n [3] - TERCER TURNO:  14:00 A 16:00 HORAS\n");
					break;
					
					case 4:		
						printf("\n [4] - CUARTO TURNO:  16:00 A 18:00 HORAS\n");
					break;
					
					case 5:		
						printf("\n [5] - QUINTO TURNO:  18:00 A 20:00 HORAS\n");
					break;
					
					case 6:		
						printf("\n [6] - SEXTO TURNO:   20:00 A 22:00 HORAS\n");
					break;
						
				}
			}
		}
		
		
		while(valido==0)
		{
			printf("\n\n %c Ingrese el numero de turno elegido: ", 04); scanf("%d", &turno);
			
			if(turno>0 and turno<7)
			{
				if(array[turno-1]==0)
				{
					valido =1;
					printf("\n\n  %c Turno registrado exitosamente ", 26);
					
					printf("\n\n\n - "); system("PAUSE"); system("CLS");
					return 1;
					
				}else printf("\n\n %c TURNO NO DISPONIBLE, ingrese nuevamente...\n", 33);
				
			}else printf("\n\n %c NUMERO DE TURNO INCORRECTO, ingrese nuevamente...\n", 33);
		}
			
	}else
	{
		printf("\n [%c] - NO HAY NUEVOS TURNOS DISPONIBLES PARA ESTA ACTIVIDAD\n");	
		return 0;
	} 
	
	return 0;
}


int existenciaEntrenador(int &legajo_entrenador)//Se valida que el entrenador exista
{
	FILE *archivo;
	archivo=fopen("../Base_de_datos/Entrenadores.dat", "rb");
	
	entrenador entrena_auxiliar;
	int legajo_auxiliar, permiso=1;
	
	printf("\n\n---------------------------%c REGISTRO DE ACTIVIDADES %c--------------------------\n", 04, 04);

	
	while(permiso==1)
	{
		printf("\n %c Ingrese el numero de legajo del entrenador responsable: ", 04); scanf("%d", &legajo_auxiliar);
			
		if(archivo==NULL)
		{
			printf("\n %c No hay entrenadores registrados en la base de datos. Registre uno, e intente nuevamente...", 33);
			return 0;
		}
		else
		{
			fread(&entrena_auxiliar, sizeof(entrenador), 1, archivo);
			while(!feof(archivo))
			{
				if(legajo_auxiliar == entrena_auxiliar.legajo)
				{
					legajo_entrenador=legajo_auxiliar;
					fclose(archivo);
						
					return 1;
					
				}else fread(&entrena_auxiliar, sizeof(entrenador), 1, archivo);	
			}
		}
		
		printf("\n %c Se ingreso un legajo de entrenador incorrecto...\n", 33);
		printf("\n\n   %c Ingrese 1 si quiere volver a intentar con otra legajo: ", 26); 
		scanf("%d", &permiso);
		printf("\n\n");
		
		rewind(archivo);
		
	}
	fclose(archivo);
	return 0;
		
}


int entrenadorDisponible(int legajo_entrenador, int  turno, char tipo)//Se valida que el entrenador este disponible en el horario designado
{
	FILE *archivo;
	archivo=fopen("../Base_de_datos/Actividades.dat", "rb");
	
	actividades auxiliar;
	
	fread(&auxiliar, sizeof(actividades), 1, archivo);	
	while(!feof(archivo))
	{
		if(legajo_entrenador==auxiliar.legEntrenador and turno==auxiliar.horario)
		{
			if(tipo==auxiliar.tipo)
			{
				printf("\n\n %c El entrenador ya tiene registrada ESTE tipo de actividad en este turno...", 33);
				fclose(archivo);
				return 0;
			}
			else 
			{
				printf("\n\n %c El entrenador ya tiene registrada OTRO tipo de actividad en este turno...", 33);
				fclose(archivo);
				return 0;
			}
					
		}else fread(&auxiliar, sizeof(actividades), 1, archivo);
	}
	
	printf("\n\n   %c El entrenador ESTA DISPONIBLE en este turno...", 26);
	fclose(archivo);
	printf("\n\n\n - "); system("PAUSE"); system("CLS");
	return 1;
}


void generarCodigo_Actividad(int horario, char tipo, char cod[5])
{
	char hora=horario+48;
	cod[0]=tipo;
	cod[1]=hora;
	cod[2]='\0';
}

	//[*]Funcion de manipulacion de archivos

void crearActividad(actividades nuevo)//Guarda la Actividad creada en Actividades.dat
{
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Actividades.dat", "a+b");
	
	fwrite(&nuevo, sizeof(actividades), 1, archivo);

		
	fclose(archivo);
	
}

//[**]Funciones de impresion

int buscarNombre_Entrenador(int legajo, char nombre[61])//Busca el nombre de un entrenador por su legajo
{
	FILE *arc;
	arc= fopen("../Base_de_datos/Entrenadores.dat","rb");
	entrenador aux;
	
	fread(&aux,sizeof(aux),1, arc);	
	while(!feof(arc))
	{
		if(aux.legajo==legajo)
		{
			strcpy(nombre, aux.apynom);
			fclose(arc);	
			return 1;
		}
		else fread(&aux, sizeof(aux), 1, arc);	
	} 
		
	fclose(arc);
	return 0;
}


void imprimirActividad(actividades act)//Imprime los datos de la actividad que se envia como parametro
{
	printf("\n %c Codigo de la actividad: %s  \n", 04, act.cod);
	
	printf("\n %c Tipo de actividad: ", 04);
	if(act.tipo=='Z') printf(" Zumba\n");
	if(act.tipo=='S') printf(" Spining\n");
	if(act.tipo=='P') printf(" Pilates\n");
	
	printf("\n %c Horario:  ", 04);
	switch(act.horario)
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
		
	//Busca el nombre del entrenador a partir de su legajo y lo imprime
	char aux_nombre[61];	
	buscarNombre_Entrenador(act.legEntrenador, aux_nombre);
	printf("\n %c Entrenador a cargo: %s\n", 04, aux_nombre); 
	
	printf("\n %c Cantidad de socios registrados: %d \n", 04, act.cantParticipantes);
	
	printf("\n-------------------------- %c ----------------------- %c -------------------------\n",04,04);
}


void mostrarActividades()//Muestra las Actividades guardadas en Actividades.dat
{
	FILE *arc;
	arc= fopen("../Base_de_datos/Actividades.dat","rb");
	actividades aux;
	
	system("cls");	
	
	if(arc==NULL)
	{
		printf ("\n 			       -->>> ERROR <<<-- \n");
		printf ("\n > El archivo no existe, intente registrar una Actividad e intente nuevamente...\n");
	}
	else
	{
		printf("\n\n---------------------------%c ACTIVIDADES REGISTRADAS %c--------------------------\n", 04, 04);
		
		fread(&aux,sizeof(aux),1, arc);	
		while(!feof(arc))
		{
			imprimirActividad(aux);
			fread(&aux,sizeof(aux),1, arc);	
		} 
		
		fclose(arc);
		
	}

	fclose(arc);
}



//[***]Funciones adicionales
void intentarNuevamente(int &autorizacion)//Muestra un mensaje de error, indicando si desea intentar de nuevo
{
	printf("\n\n\n %c Ingrese 1 si quiere volver a intentar con otra Actividad, otro numero en caso contrario: ", 04); 
	scanf("%d", &autorizacion);
	system("cls");
}




//[1]Funcion Principal
void regActividad()//Registra una actividad
{
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Actividades.dat", "a+b");
	fclose(archivo);
	 
	int autorizacion =1, confirmar=0;
	
	system("cls");
	
	
	while(autorizacion==1)
	{	
		actividades nueva;
		
		//Primera Comprobacion: Se ingresa el tipo de Actividad
		if(ingresarTipo_Actividad(nueva.tipo))
		{
		
			//Segunda Comprobacion: Se verifica si hay nuevo turnos disponibles y se lo ingresa, en caso positivo
			if(disponibilidadHoraria(nueva.tipo, nueva.horario))
			{
				//Tercera Comprobacion: Verifica que el legajo del entrenador que se quiere asignar, exista
			 	if(existenciaEntrenador(nueva.legEntrenador))
			 	{
			 		//Cuarta Comprobacion: Se determina que el entrenador que se quiere asignar, este disponible en este horario
				 	if(entrenadorDisponible(nueva.legEntrenador, nueva.horario, nueva.tipo))
				 	{
				 		//Generamos el codigo de la actividad, a partir del tipo(inicial) y horario(turno) que se elijió para la misma
						generarCodigo_Actividad(nueva.horario, nueva.tipo, nueva.cod);
						
						//Definimos el parametro cantidad de participantes en 0, para que luego sea incrementado
				 		nueva.cantParticipantes=0;
				
						//Imprimimos los datos de la actividad recien ingresados
						printf("\n\n---------------------------%c REGISTRO DE ACTIVIDADES %c--------------------------\n", 04, 04);
						printf("\n %c Informacion de la actividad a registrar: \n");
						imprimirActividad(nueva);
						
						printf("\n %c Ingrese 1 para confirmar el registro: ", 04); scanf("%d", &confirmar);
						if(confirmar==1)
						{	
								printf("\n %c La actividad se ha registrado exitosamente...");
								crearActividad(nueva);
								
						}else   printf("\n %c La actividad NO se ha registrado...");
						
						
				 		autorizacion=0;
				 		
				 		
					}else intentarNuevamente(autorizacion);
				 	
				}else intentarNuevamente(autorizacion);
				
			}else intentarNuevamente(autorizacion);
			
		}
	}
	
	
}


//---------------------------------------------------------------------------------------------------------------------------//
	



//------------------------------------------[5] SECCION PAGO AL ENTRENADOR --------------------------------------------------//


void PagoEnt() //Realiza el calculo del pago al entrenador con respecto a la cantidad de socios que entrena
{
	FILE *arc;
	int leg, ac, op = 1;
	float val, pago;
	actividades reg;
	
	arc = fopen ("../Base_de_datos/Actividades.dat", "rb");
	
	while(op==1)
	{
		ac = 0;
		system("CLS");
		
		printf("\n\n--------------------------%c CALCULAR PAGO ENTRENADOR %c--------------------------\n", 04, 04);
		printf("\n %c Ingrese el legajo del entrenador: ", 04);	scanf("%d",&leg);
	
		fread(&reg, sizeof(actividades), 1, arc);
	
		while (!feof(arc))
		{
			if (leg == reg.legEntrenador)
			{
				ac = ac + reg.cantParticipantes;
				fread(&reg, sizeof(actividades), 1, arc);
			}
			else
			{
				fread(&reg, sizeof(actividades), 1, arc);
			}
		}
		
		if(ac == 0)
		{
			
			printf("\n %c El entrenador no existe o no tiene participantes en sus actividades", 26);
		}
		else
		{
			printf("\n %c Ingrese el valor que se debe abonar por cada socio: ", 04); scanf("%f",&val);
	
			pago = val * ac;
			printf("\n\n %c El pago del entrenador es de: %.2f \n", 26, pago);
		}
	
		printf("\n\n\n %c Presione 1 si desea ingresar otro legajo: ", 04); scanf("%d",&op);
		rewind(arc);
		
	}
	fclose(arc);
}


//---------------------------------------------------------------------------------------------------------------------------//




//----------------------------------------------[6] SECCION MAYOR CARGA HORARIA --------------------------------------------//

//[*]Funciones secundarias de las
int legajoEntrenadores(int arrayDeLegajos[50], int arrayDeDias[50], int &i)//Recibe un array donde guardara los legajos de todos los entrenadores registrados en la base de datos
{
	FILE *archivo;
	archivo=fopen("../Base_de_datos/Entrenadores.dat", "rb");
	
	entrenador aux;
	i=0;
	
	if(archivo==NULL)//Pregunta si el archivo no se pudo abrir 
	{
		printf("\n %c%c No existen entrenadores registrados en la base de datos...", 33, 33);
		fclose(archivo);
		return 0;
	}
	
	else
	{
		fread(&aux, sizeof(entrenador), 1, archivo);
		if(feof(archivo)) 
		{
			printf("\n %c%c No existen entrenadores registrados en la base de datos...", 33, 33);
			fclose(archivo);
			return 0;
			
		}else
			{
				while(!feof(archivo))
				{
					arrayDeLegajos[i]=aux.legajo;
					arrayDeDias[i]=aux.diasAtencion;
					i++;
					fread(&aux, sizeof(entrenador), 1, archivo);
				}
				
				fclose(archivo);
			}	
	}
	
	fclose(archivo);
	return 1;
	
	
}


int cargaHoraria_Entrenador(int legajo)//Recibe el legajo de un entrenador y devuelve la cantidad de turnos en los que trabaja
{
	FILE *archivo;
	archivo=fopen("../Base_de_datos/Actividades.dat", "rb");
	actividades aux; 
	int contador=0;
	
	fread(&aux, sizeof(actividades), 1, archivo);
	while(!feof(archivo))
	{
		if(legajo==aux.legEntrenador)
		{	
			contador++;
			fread(&aux, sizeof(actividades), 1, archivo);
		}fread(&aux, sizeof(actividades), 1, archivo);
		
	}
	
	fclose(archivo);
	return contador;

	

}


void mayorCarga_Entrenador()//Imprime el entrenador con la mayor carga horaria. 
{
	int arrayDeLegajos[50], arrayDeDias[50], cantidad, mayor_Carga=0, mayor_Entrenador;// Las variables "Mayor" guardan informacion sobre el entrenador con mayor carga horaria
	int actual_Carga;
	char nombre_Entrenador[61];
	
	printf("\n\n---------------------%c ENTRENADOR CON MAYOR CARGA HORARIA %c---------------------\n", 04, 04);
	
	if(legajoEntrenadores(arrayDeLegajos, arrayDeDias, cantidad))
	{	
		for(int i=0; i<cantidad; i++)
		{
			actual_Carga=cargaHoraria_Entrenador(arrayDeLegajos[i])*arrayDeDias[i];// La carga horaria semanal se obtiene multiplicando la cantidad de dias que trabaja, por la cantidad de actividades que posee.
			
			if(actual_Carga>mayor_Carga)
			{
				mayor_Carga=actual_Carga;
				mayor_Entrenador=arrayDeLegajos[i];
			}
		}
	}
	buscarNombre_Entrenador(mayor_Entrenador, nombre_Entrenador);
	printf("\n %c El entrenador con mayor carga horaria es: %s \n", 04, nombre_Entrenador);
}


//---------------------------------------------------------------------------------------------------------------------------//




//--------------------------------------------FUNCION PRINCIPAL: MODULO ADMINISTRACION-----------------------------------------//

//[0]Funcion para iniciar sesion
int iniciarSesionAdmin();

//[1]Funcion para registrar usuarios (Administradores o Recepcionistas)
void regUser();

//[2]Funcion para registrar entrenadores
void regEntrenadores();

//[3]Funcion para registrar actividades
void regActividad();

//[4]Funcion para calcular el pago de un entrenador
void PagoEnt();

//[5]Funcion para calcular el entrenador con mayor carga horaria
void mayorCarga_Entrenador();


//[*]Funciones de validacion
int validarExistenciaArchivo()//Valida si el archivo existe, o  esta vacio o no: de esta forma, se define si hay al menos un ADMINISTRADOR registrado
{
	FILE *archivo;
	archivo=fopen("../Base_de_datos/Usuarios.dat", "rb");
	user aux;
	
	if(archivo==NULL)//Si no existe el archivo: lo crea, registra un administrador y luego lo cierra
	{		
		printf("\n\n %c%c Es necesario que cree una cuenta de ADMINISTRADOR antes de usar el sistema..", 04, 04);

		archivo=fopen("../Base_de_datos/Usuarios.dat", "a+b");
		regUser();
		fclose(archivo);
		return 1;
		
	}else//Si existe el archivo: busca un usuario tipo administrador en el, si hay por lo menos uno, cierra el archivo y devuelve 1.
		{
			fread(&aux, sizeof(user), 1, archivo);
			while(!feof(archivo))
			{
				if(aux.tipo == 1)
				{
					fclose(archivo);
					return 1;
				}else fread(&aux, sizeof(user), 1, archivo);
			}	
			
			//Si existe el archivo, pero no hay ningun administrador: registra uno y cierra el archivo
			
			printf("\n\n %c%c Es necesario que cree una cuenta de ADMINISTRADOR antes de usar el sistema..", 33, 33);
			regUser();
			fclose(archivo);
			return 1;
			
		}
	
	
}



void moduloAdmin()//Funcion de administracion, a llamarse en el programa principal
{
	int x=0, autorizacion=1, reintentar=0;
	
	if(validarExistenciaArchivo())
	{
		if(iniciarSesionAdmin())
		{
			while(autorizacion==1)
			{
			
				printf("\n\n---------------------------%c MENU DE ADMINISTRACION %c---------------------------\n", 04, 04);
				printf("\n [1] - Registrar Usuarios: Administradores o Recepcionistas \n");
				printf("\n [2] - Registrar Entrenadores \n");
				printf("\n [3] - Registrar Actividades \n");
				printf("\n [4] - Calcular pago de un entrenador \n");
				printf("\n [5] - Calcular entrenador con mayor carga horaria \n");
				printf("\n [6] - Mostrar usuarios registrados en la base de datos \n");
				printf("\n [7] - Mostrar entrenadores registrados en la base de datos \n");
				printf("\n [8] - Mostrar actividades registradas en la base de datos \n");
				printf("\n [9] - Salir \n");
				
				
				
				printf("\n\n %c - Ingrese una opcion:  "); scanf("%d", &x);
				
				switch(x)
				{
					case 1:
						regUser();
						break;
						
					case 2:
						regEntrenadores();	
						break;
						
					case 3:
						regActividad();	
						break;	
						
					case 4:
						system("CLS");
						PagoEnt();	
						break;	
						
					case 5:
						system("CLS");
						mayorCarga_Entrenador();	
						break;	
						
					case 6:
						mostrarUsuarios();
						break;
					
					case 7:
						mostrarEntrenadores();
						break;
						
					case 8:
						mostrarActividades();
						break;
						
					case 9:
						system("CLS");
						autorizacion=0;
						break;
						
					default: 
						printf("\n %c Se ha ingresado una opcion incorrecta...", 33);
						reintentar=1;	
						printf("\n\n - "); system("PAUSE");system("CLS");
						break;		
				}
				
				if(autorizacion==1)
				{
					if (reintentar==0)
					{
						printf("\n\n\n %c Ingrese [1] para volver al menu pricipal, [0] para salir: ", 26); scanf("%d", &autorizacion);
						system("CLS");
					}
				}
				reintentar=0;
			}
			
		}
	
	}
	
	printf("\n\n - ");	system("pause");
	
}


//---------------------------------------------------------------------------------------------------------------------------//	