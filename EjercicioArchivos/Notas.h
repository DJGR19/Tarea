#pragma once

#ifndef NOTAS_H
#define NOTAS_H


class Notas
{
public:
	static  void registrarAlumnos();
	static void consultarAlumnos();
	static void registrarMaterias();
	static void consultarMaterias();

	static void registrarNotas();
	static void consultarNotas();
	static int ObtenerCodigoAlumno(char *);
	static int ObtenerCodigoMateria(char *);
	static char *ObtenerNombreAlumno(const int);
	static char *ObtenerNombreMateria(const int);
	static double ObtenerPromedioAlumno(char *);
	static double promedioMateria();

};

#endif // !NOTAS_H