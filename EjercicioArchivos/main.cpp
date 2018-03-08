
#include "Notas.h"
#include <conio.h>
#include <iostream>
using namespace std;
//#define getch() _getch()
int main()
{
	
	//getch();
	
	int opcion = 0;
	
	do {
		cout << "***M E N U    P R I N C I P A L*****\n";
		cout << "Elija la opcion que desee: \n1.Registrar Alumnos \n2.Consulte Alumnos \n3.Registrar Materias \n4.Consultar Materia \n5.Registre las notas \n6.Consulte Notas de alumnos \n7.Obtener Promedio Alumnos \n8.Promedio por materias \n9.Salir\n";
		cin >> opcion;


		switch (opcion) {
		case 1:
			Notas::registrarAlumnos();
			break;
		case 2:
			Notas::consultarAlumnos();
			break;
		case 3:
			Notas::registrarMaterias();
			break;
		case 4:
			Notas::consultarMaterias();
			break;
		case 5:
			Notas::registrarNotas();
			break;
		case 6:
			Notas::consultarNotas(); //PENDING...
			break;
		case 7:
			//Notas::ObtenerPromedioAlumno();
			break;
		case 8:
			Notas::promedioMateria();
			break;
		case 9:
			break;
		}
		}while (opcion != 9);


		//system("pause");
};
