#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

// Define a un paciente
struct Paciente{

	std::string nombre;
	std::string apellido1;
	std::string apellido2;
	int cedula;
	int telefono;
	std::string fechaNacimiento;
	int edad;
	float peso;
	float altura;
	std::string presion;
	std::string sintomas;
	std::string fechaIngreso;
};

// Método contructor de un paciente
Paciente* crearPaciente(
	std::string nombre,
	std::string apellido1,
	std::string apellido2,
	int cedula,
	int telefono,
	std::string fechaNacimiento,
	int edad,
	float peso,
	float altura,
	std::string presion,
	std::string sintomas
);

// Este método imprime en la consola la información de un paciente.
void MostrarPaciente(Paciente* paciente);


// Ingresa los datos del Paciente desde la consola.
// Retorna una estructura de typo Paciente
Paciente* IngresarDatosDelPaciente();