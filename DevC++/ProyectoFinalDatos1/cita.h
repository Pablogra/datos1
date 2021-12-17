#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>


struct Cita {
	int cedPaciente;
	int codigoDoctor;
	std::string fechaCita;
	std::string horaCita;
};


// M�todo contructor de una cita
Cita* crearCita(
	int cedPaciente,
	int codigoDoctor,
	std::string fechaCita,
	std::string horaCita
);

// Este m�todo imprime en la consola la informaci�n de una cita
void MostrarCita(Cita* cita);

Cita* IngresarDatosDeLaCita();

