//Libreria del Modulo Recepcion
#include "Estructuras.h"







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