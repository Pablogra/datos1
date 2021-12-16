#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include "cita.h"
#include "listaEnlazada.h"


struct Doctor{
	std::string nombre;
	std::string apellido1;
	std::string apellido2;
	int codigo;
	std::string especialidad;
	Lista* citas;
};


// M�todo contructor de un doctor
Doctor* crearDoctor(
	std::string nombre,
	std::string apellido1,
	std::string apellido2,
	int codigo,
	std::string especialidad
);

// Este m�todo imprime en la consola la informaci�n de un doctor.
void MostrarDoctor(Doctor* doctor);

// Ingresa los datos del Doctor desde la consola.
// Retorna una estructura de typo Doctor
Doctor* IngresarDatosDelDoctor();