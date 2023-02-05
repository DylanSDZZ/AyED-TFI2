//Libreria de estructuras

//[E] Definicion de las estructuras usadas en este archivo

struct user//Se guarda en Usuarios.dat
{
	char apynom[61];//Apellido y Nombre
	char nick[20];//Nombre de Usuario
	char pass[40];//Contraseña
	int  tipo=0;//Determina si es Administrador[1] o Recepcionista[2]
};

struct entrenador//Se guarda en Entrenadores.dat
{
	char apynom[61];//Apellido y Nombre
	int  legajo;//Numero de legajo 
	int  diasAtencion=0;//Cantidad de dias a la semana que trabaja
	char nick[20];//Nombre de Usuario
	char pass[40];//Contraseña

};

struct actividades//Se guarda en Actividades.dat
{
	char cod[5];//Codigo de Actividad
	char tipo;//Tipo de actividad: Z: Zumba, S: Spining y P: Pilates
	int  horario;//Turno en el que se desarolla la actividad- Puede ser del 1 al 6
	int  legEntrenador;//Numero de legajo del entrenador responsable de la actividad
	int  cantParticipantes;//Cantidad de socios que participan en la actividad
};

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct med{  
	char zum ;
	char spin;
	char pil;
};

struct socios//Se guarda en Socios.dat
{
	char  nomyape[61];//Nombre y apellido del socio
	char  direccion[50];//Direccion del socio
	int   tel;//Numero de telefono
	int   numSocio;//Numero univoco de socio
	int   DNI;//Numero de Documento
	int   altura;//Altura en metros
	int   peso;//Peso en kilogramos
	med  indMedicas;//Registra el tipo de actividad que no puede realizar el socio. Se rellena con una T en caso de que no haya restricciones. Tipo de actividad: Z: Zumba, S: Spining y P: Pilates 
	fecha fec_ingreso;//Indica la fecha en que se registro el socio
};

struct rutina//Se guarda en Rutinas.dat
{
	int  CodRut;//Codigo Univoco de la rutina
	char Descripcion[2000];//Descripcion de la rutina en no más de 380 palabras
	int  legEntrenador;//Guarda el numero de legajo del entrenador que creo la rutina
};

struct socioAct//Se guarda en Socio-Act.dat: Este archivo se usa para guardar que actividad realiza cada socio
{
	int  numSocio;//Numero univoco de socio
	char cod[5];//Codigo de Actividad
	int  legajo_Entrenador;//Numero de legajo del entrenador a cargo de la actividad elegida.
};

struct socioRut//Se guarda en Socio-Rut.dat: Este archivo se usa para guardar que rutina realiza cada socio
{
	int  numSocio;//Numero univoco de socio
	int  CodRut;//Codigo Univoco de la rutina
};




