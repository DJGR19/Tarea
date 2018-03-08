
#include "Notas.h"

#include <fstream>// Contiene toda y cada una de las clases para manipular archivos
#include <iostream>

//CALCULAR PROMEDIO DE NOTAS POR ALUMNO 
//SOLICITAR NOMBRE ALUMNO
//CALCULAR EL PROMEDIO DE NOTAS POR MATERIA
//SOLICITAR NOMBRE MATERIA

using namespace std;

void Notas::registrarAlumnos()
{
	ofstream archivoAlumnos("alumnos.txt", ios::app);//ios indica si un archivo de salida, comienza ingresando los regstros al final del archivo, caso contrario si no se coloca el ios coloca todo de un solo "ofstream" para ingresar dattos  al archivo
	if (!archivoAlumnos)//SI NO ESTÁ CREADO EL ARCHIVO
	{
		cout << "Error al intentar abrir el archivo alumnos.dat\n";
		return;
	}

	int cuenta, edad, cantidad;
	char nombre[50];
	cout << "\n\n ** I N G R E S O  DE  A L U M N O S ** \n\n";
	cout << "Cantidad de alumnos a ingresar: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++)
	{
		cout << "Ingrese numero de cuenta: ";
		cin >> cuenta;
		cout << "Ingrese el nombre de alumno: ";
		cin >> nombre;
		cout << "Ingrese edad: ";
		cin >> edad;

		archivoAlumnos << cuenta << ' ' << nombre << ' ' << edad << "\n";
	}

	archivoAlumnos.close();
	system("pause");
}


void Notas::consultarAlumnos()
{
	ifstream archivoAlumnosIn("alumnos.txt", ios::app);
	if (!archivoAlumnosIn)//Siempre verificar si el archivo tiene problemas como segundo PASO
	{
		cout << "Error al intentar abrir archivo.txt";
	}
	int cuenta, edad;//La lectura tiene que ser ddel mismo formato a como guarda
	//damos el archivo
	char nombre[50];

	cout << "** C O N S U L T A  DE  A L U M N O S **\n\n";

	while (archivoAlumnosIn>>cuenta>>nombre>>edad)
		{
		cout << cuenta <<' '<< nombre << ' ' << edad << "\n";
	    }
	archivoAlumnosIn.close();
	system("pause");

}



void Notas::registrarMaterias()
{
	ofstream archivoMateriasOut("materias.txt", ios::app);

	if (!archivoMateriasOut)
	{
		cout << "Error al intentar abrir el archivo materias.txt\n";
		return;
	}
	int cantidad, codigoM;
	char nombre[30];

	cout << "\n\n *** I N G R E S O  D E  M A T E R I A S ***\n\n";
	cout << "Ingrese la cantidad de materias: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++)
	{
		cout << "Ingrese código: ";
		cin >> codigoM;
		cout << "Ingrese materia: ";
		cin >> nombre;

		archivoMateriasOut << codigoM << ' ' << nombre << ' ' << "\n";
	}
	archivoMateriasOut.close();
	system("pause");

}

void Notas::consultarMaterias()
{
	ifstream  archivoMateriasIn("materias.txt", ios::in);
	if (!archivoMateriasIn)
	{
		cout << "Error al intentar abrir el archivo materias.txt\n";
		return;
	}
	cout << "\n\n *C O N S U L T A  D E  M A T E R I A S*\n";
	archivoMateriasIn.seekg(0, ios::beg);//seekg - sería ver y obtener(seek and get) y ios::beg me posiciona al inicio del archivo, el 0 es debido a que se busca el byte 0 del inicio
	int codigoM;
	char nombre[30];
	while (archivoMateriasIn >> codigoM >> nombre)
	{
		cout << codigoM << ' ' << nombre << "\n";
	}
	archivoMateriasIn.close(); // Si no se coloca un cierre alfinal el archivo puede mostrar valores basuras, es decir, valores extra que no concuerdan con el sentido del texto
	system("pause");
}

void Notas::registrarNotas()
{
	/*
	ofstream archivoNotasOut("notas.txt", ios::app);
	if (!archivoNotasOut)
	{
		cout << "Error al intentar abrir archivo notas.txt";
			return;
	}

	int opcion = 0;
	cout << "INGRESO DE NOTAS\n";
	do
	{
		//archivoNotasOut.open("notas.txt", ios::app);
		char nombreM[30];
		char nombreA[50];
		int codigoM, codigoA, nota;
		//codigoA = 0;
		//MATERIAS
		do
		{
			cout << "Ingrese Materia: ";
			cin >> nombreM;
			codigoM = ObtenerCodigoMateria(nombreM);

		} while (codigoM != -1);

		//ALUMNOS
		do
		{
			cout << "Ingrese Alumno: ";
			cin >> nombreA;
			codigoA = ObtenerCodigoAlumno(nombreA);

		} while (codigoA != -1);

		cout << "Ingrese Nota: ";
		cin >> nota;

		archivoNotasOut << codigoM<<' '<<codigoA<<' '<<nota << "\n";

		cout << "Desea ingresar una nueva nota? -1 para salir.";
		cin >> opcion;


	} while (opcion != -1);
	archivoNotasOut.close();
	*/
	ofstream archivoNotasOut("notas.txt", ios::app);

	if (!archivoNotasOut) {
		cout << "Error al intentar abrir el archivo notas.dat\n";
		return;
	}

	int opcion = 0;

	cout << "\n\n * I N G R E S O  D E  N O T A S *\n\n";

	do {
		char nombreM[30];
		char nombreA[50];
		int codigoM, codigoA, nota;

		do {
			cout << "Ingrese Materia: ";
			cin >> nombreM;
			codigoM = ObtenerCodigoMateria(nombreM);
		} while (codigoM != -1);

		do {
			cout << "Ingrese Alumno: ";
			cin >> nombreA;
			codigoA = ObtenerCodigoAlumno(nombreA);
		} while (codigoA != -1);

		cout << "Ingrese Nota: ";
		cin >> nota;

		archivoNotasOut << codigoM << ' ' << codigoA << ' ' << nota << "\n";

		cout << "Desea ingresar una nueva nota? -1 para salir.";
		cin >> opcion;

	} while (opcion != -1);

	archivoNotasOut.close();



	system("pause");

}

int Notas::ObtenerCodigoMateria(char *nombreM)
{
	ifstream archivoMateria("materias.txt", ios::in);
	if (!archivoMateria)
	{
		cout << "Error al intentar abrir el archivo materias.txt";
		return -1;//En este caso retorna un valor debido a que está declarado con "int" es decir, se espera que retorne un número caso contrario con las otras funciones que tienen definición  void
	}
	archivoMateria.seekg(0, ios::beg);
	int codigo;
	char nombre[30];

	while (archivoMateria >> codigo >> nombre);
	{
		if (strcmp(nombre, nombreM) == 0)//Utilizamos la función strcmp para hacer la comparación de si los datos son iguales el que buscamos con el que obtenemos
			return codigo;
	}
	return -1;
	system("pause");
}

int Notas::ObtenerCodigoAlumno(char *nombreA)
{
	ifstream archivoAlumnos("alumnos.txt", ios::in);
	//ifstream archivoMateria("materias.txt", ios::in);
	if (!archivoAlumnos)
	{
		cout << "Error al intentar abrir el archivo materias.txt";
		return -1;//En este caso retorna un valor debido a que está declarado con "int" es decir, se espera que retorne un número caso contrario con las otras funciones que tienen definición  void
	}
	archivoAlumnos.seekg(0, ios::beg);
	int codigo, edad;
	char nombre[50];

	while (archivoAlumnos >> codigo >> nombre);
	{
		if (strcmp(nombre, nombreA) == 0)//Utilizamos la función strcmp para hacer la comparación de si los datos son iguales el que buscamos con el que obtenemos será ==0
			return codigo;
	}
	return -1;
	system("pause");

}

//Leer Notas - 
//IMPRIMIR-> Nombre_materia, nombre alumno, nota


char *Notas::ObtenerNombreAlumno(const int codigoAlumno)
{
	ifstream archivoAlumnos("alumnos.txt",ios::in);
	if (!archivoAlumnos)
	{
		cout << "Error al intentar abrir el archivo alumnos.txt";
		return nullptr; //Se puede retornar "0", "NULL" todos son valores nulos
	}
	int codigo, edad;
	char nombre[50];
	archivoAlumnos.seekg(0, ios::beg);

	while (archivoAlumnos >> codigo >> nombre >> edad)
	{
		if (codigoAlumno == codigo)
		{
			char* retorno = new char[strlen(nombre)];
			strcpy_s(retorno,strlen(nombre), nombre);
			retorno[strlen(nombre)] = '\0';
			archivoAlumnos.close();
			return retorno;
		}

	}
	archivoAlumnos.close();
	return NULL;
	system("pause");
}

char* Notas::ObtenerNombreMateria(const int codigoMateria)
{
	ifstream archivoMaterias("alumnos.txt", ios::in);
	
	if (!archivoMaterias)
	{
		cout << "Error al intentar abrir el archivo alumnos.txt";
		return nullptr; //Se puede retornar "0", "NULL" todos son valores nulos
	}
	int codigo, edad;
	char nombre[30];
	archivoMaterias.seekg(0, ios::beg);

	while (archivoMaterias >> codigo >> nombre >> edad)
	{
		if (codigoMateria == codigo)
		{
			char* retorno = new char[strlen(nombre)];
			strcpy_s(retorno,strlen(nombre), nombre);
			retorno[strlen(nombre)] = '\0';
			archivoMaterias.close();
			return retorno;
		}

	}
	archivoMaterias.close();
	return NULL;

	system("pause");





}

void Notas::consultarNotas()
{
	
	ifstream archivoNotas("notas.txt", ios::app);
	if (!archivoNotas)
	{
		cout << "Error al intentar abrir archivo";
		return;
	}

	cout << "\n\n *CONSULTAR NOTAS\n\n";

	int codigoM, codigoA, nota;

	archivoNotas.seekg(0, ios::beg);

	while (archivoNotas >> codigoM >> codigoA >> nota)
	{
		cout << ObtenerNombreMateria(codigoM) << ' ' <<ObtenerNombreAlumno(codigoA)<< ' ' <<nota << "\n";
	}

	archivoNotas.close();

	system("pause");
}
/////////////////////////////////////////////////////////HOMEWORK!!!!!!!!!
double Notas::ObtenerPromedioAlumno(char *nombreA)
{
	ifstream archivoAlumnosPromedio("alumnos.txt", ios::app);
	//NEW ONES THAT I JUST ADDED
	
	int codigo, edad;
	char nombre[50];
	//ifstream archivoMateria("materias.txt", ios::in);
	if (!archivoAlumnosPromedio)
	{
		cout << "Error al intentar abrir el archivo materias.txt";
		return -1;//En este caso retorna un valor debido a que está declarado con "int" es decir, se espera que retorne un número caso contrario con las otras funciones que tienen definición  void
	}

	cout << "\n\n *PROMEDIO ALUMNOS*\n\n";
	archivoAlumnosPromedio.seekg(0, ios::beg);
	
	while (archivoAlumnosPromedio >> codigo >> nombre >> edad) {
		if (strcmp(nombre, nombreA) == 0) {
			ifstream archivoNotas("notas.txt", ios::app);

			int codigoMateria = 0;
			int codigoAlumno = 0;
			int nota = 0;

			double promedio = 0;
			int contador = 0;

			archivoNotas.seekg(0, ios::beg);
			while (archivoNotas >> codigoMateria >> codigoAlumno >> nota) {
				if (codigoAlumno == codigo) {
					promedio = promedio + nota;
					contador++;
				}
			}
			return promedio / contador;

		}


		return -1;

	}

	system("pause");

}

double Notas::promedioMateria()
{
	ifstream archivoNotas("notas.txt", ios::app);

	if (!archivoNotas) {

		cout << "No se pudo abrir el archivo" << endl;
		return -1;
	}

	cout << "\n\n *PROMEDIO MATERIA*\n\n";
	int codigoMateria = 0, codigoAlumno = 0, nota = 0;
	int promedio = 0;
	int Numero_materias = 0;

	while (archivoNotas >> codigoMateria >> codigoAlumno >> nota) {
		promedio = promedio + nota;
		Numero_materias++;
	}
	return promedio / Numero_materias;

}




