//Libreria de estructuras

//[E] Definicion de las estructuras usadas en este archivo

struct user
{
	char apynom[61];//Apellido y Nombre
	char nick[20];//Nombre de Usuario
	char pass[40];//Contraseña
	int  tipo=0;//Determina si es Administrador[1] o Recepcionista[2]
};

struct entrenador
{
	char apynom[61];//Apellido y Nombre
	int  legajo;//Numero de legajo 
	int  diasAtencion=0;//Cantidad de dias a la semana que trabaja
	char nick[20];//Nombre de Usuario
	char pass[40];//Contraseña

};

struct actividades
{
	char cod[5];//Codigo de Actividad
	char tipo;//Tipo de actividad: Z: Zumba, S: Spining y P: Pilates
	int  horario;//Turno en el que se desarolla la actividad- Puede ser del 1 al 6
	int  legEntrenador;//Numero de legajo del entrenador responsable de la actividad
	int  cantParticipantes;//Cantidad de socios que participan en la actividad
};

