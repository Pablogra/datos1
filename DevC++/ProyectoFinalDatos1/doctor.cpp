#include <iostream>
#include <stdlib.h>
#include <string>
#include "doctor.h"
#include "cita.h"
#include "listaEnlazada.h"



Doctor* crearDoctor(
	std::string nombre,
	std::string apellido1,
	std::string apellido2,
	int codigo,
	std::string especialidad
)
{
	Doctor* nuevo_doctor = new Doctor();
	nuevo_doctor->nombre = nombre;
	nuevo_doctor->apellido1 = apellido1;
	nuevo_doctor->apellido2 = apellido2;
	nuevo_doctor->codigo = codigo;
	nuevo_doctor->especialidad = especialidad;
	nuevo_doctor->citas = lista_crear(sizeof(Cita));
	return nuevo_doctor;
};


void MostrarDoctor(Doctor* doctor)
{
	std::cout << "#################################################\n";
	std::cout << "Nombre: " << doctor->nombre << " ";
	std::cout << doctor->apellido1 << " ";
	std::cout << doctor->apellido2 << ", ";
	std::cout << "Codigo: " << doctor->codigo << ". \n";
	std::cout << "Especialidad: " << doctor->especialidad << ". \n";

};

Doctor* IngresarDatosDelDoctor()
{
	//Variables de Doctor
	std::string nombreDoctor, apellido1Doctor, apellido2Doctor, especialidadDoctor;	

	std::cout << "\tDATOS DEL DOCTOR: \n";//Muestra datos hacia el sistema <<
	std::cout << "Digite el nombre del Doctor:\n";
	std::cin >> nombreDoctor;
	std::cout << "Digite el primer apellido del Doctor:\n";
	std::cin >> apellido1Doctor;
	std::cout << "Digite el segundo apellido del Doctor:\n";
	std::cin >> apellido2Doctor;
	std::cout << "Digite la Especialidad del Doctor:\n";
	std::cin >> especialidadDoctor;	

	Doctor* nuevo_doctor = crearDoctor(
		nombreDoctor,
		apellido1Doctor,
		apellido2Doctor,
		0,
		especialidadDoctor
	);

	return nuevo_doctor;
}

