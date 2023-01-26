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
		printf("\n------------%cUSUARIOS REGISTRADOS%c------------\n",04,04);
	
		fread(&aux,sizeof(user),1, arc);	
		while(!feof(arc))
		{
			printf("\n %c Apellido y nombre:  %s\n", 04, aux.apynom);
			
			printf("\n %c Tipo de usuario:  ", 04);
				if(aux.tipo==1) printf("ADMINISTRADOR\n");
				else printf("RECEPCIONISTA\n");
				
			printf("\n %c Nombre de usuario: %s \n", 04, aux.nick);
			
			printf("\n %c Contrase%ca de usuario: %s \n", 04, 164, aux.pass);
			
			printf("\n------------%c ------------------ %c------------\n",04,04);
			
			fread(&aux,sizeof(user),1, arc);	
		} 
		
		fclose(arc);
	}
	
	fclose(arc);

	printf("\n\n");
	system("PAUSE");
	system("CLS");
}
//---------------------------------------------------------------------------------------------------------------------------//
