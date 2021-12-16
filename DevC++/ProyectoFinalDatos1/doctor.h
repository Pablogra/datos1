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


// Método contructor de un doctor
Doctor* crearDoctor(
	std::string nombre,
	std::string apellido1,
	std::string apellido2,
	int codigo,
	std::string especialidad
);

// Este método imprime en la consola la información de un doctor.
void MostrarDoctor(Doctor* doctor);

// Ingresa los datos del Doctor desde la consola.
// Retorna una estructura de typo Doctor
Doctor* IngresarDatosDelDoctor();