#include <iostream>
#include <stdlib.h>
#include <string>
#include "cita.h"




Cita* crearCita(
	int cedPaciente,
	int codigoDoctor,
	std::string fechaCita,
	std::string horaCita
)
{
	Cita* nueva_cita = new Cita();
	nueva_cita->cedPaciente = cedPaciente;
	nueva_cita->codigoDoctor = codigoDoctor;
	nueva_cita->fechaCita = fechaCita;
	nueva_cita->horaCita = horaCita;
	return nueva_cita;
}



void MostrarCita(Cita* cita)
{
	std::cout << "#################################################\n";	
	std::cout << "Cedula del Paciente: " << cita->cedPaciente << "\n";
	std::cout << "Codigo del Doctor: " << cita->codigoDoctor << "\n";
	std::cout << "Fecha: " << cita->fechaCita << "\n";
	std::cout << "Hora: " << cita->horaCita << " \n\n ";
};



Cita* IngresarDatosDeLaCita()
{
	//Variables de Cita
	
	std::string fechaCita, horaCita;
	int cedulaPaciente, codigoDoctor;

	std::cout << "\tNUEVA DE CITA: \n";
	std::cout << "Digite la cedula del Paciente:\n";
	std::cin >> cedulaPaciente;
	std::cout << "Digite el Codigo de Doctor:\n";
	std::cin >> codigoDoctor;
	std::cout << "Digite la fecha de la cita dd-mm-aaaa:\n";
	std::cin >> fechaCita;
	std::cout << "Digite la hora de la Cita:\n";
	std::cin >> horaCita;	

	Cita* nuevo_cita = crearCita(
		cedulaPaciente,
		codigoDoctor,
		fechaCita,
		horaCita
	);

	return nuevo_cita;
}


