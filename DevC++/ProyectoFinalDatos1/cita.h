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


// Método contructor de una cita
Cita* crearCita(
	int cedPaciente,
	int codigoDoctor,
	std::string fechaCita,
	std::string horaCita
);

// Este método imprime en la consola la información de una cita
void MostrarCita(Cita* cita);

Cita* IngresarDatosDeLaCita();

