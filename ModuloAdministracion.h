//Libreria del Modulo Administracion 

//---------------------------------------SECCION INICIO DE SESION ADMINISTRADORES--------------------------------------------//

int iniciarSesionAdmin()//Inicio de sesion de administradores, ingresa al archivo Usuarios.dat y comprueba la existencia del usuario
{
	FILE *archivo;
	archivo = fopen("../Base_de_datos/Usuarios.dat", "rb");
	user aux;
	
	char nomUsuario[20], contra[40];
	int  cod=1;
	
	
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
				fclose(archivo);
				printf("\n\n %c%c Presione una tecla para ingresar al sistema...", 33, 33); getchar(); system("CLS");
				return 1;//Retorna 1 en caso de que haya coincidencia con la base de datos
			}
			else fread(&aux, sizeof(aux), 1, archivo);
			
		}
		
		printf("\n %c%c Nombre de usuario y/o contrase%ca INCORRECTOS\n\n", 33, 33, 164);
		printf("\n\n %c Ingrese 1 si quiere intentar nuevamente, o ingrese  0 para salir: ", 04); scanf("%d", &cod);
		system("CLS");
	
	}
	
	fclose(archivo);
	return 0;//Retorna 0 en caso de que NO haya coincidencia con la base de datos
}

//---------------------------------------------------------------------------------------------------------------------------//


