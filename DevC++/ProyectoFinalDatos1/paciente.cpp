#include <iostream>
#include <stdlib.h>
#include <string>
#include "paciente.h"


Paciente* crearPaciente(
	std::string  nombre,
	std::string  apellido1,
	std::string  apellido2,
	int cedula,
	int telefono,
	std::string  fechaNacimiento,
	int edad,
	float peso,
	float altura,
	std::string  presion,
	std::string  sintomas
)
{
	Paciente* nuevo_paciente = new Paciente();
	nuevo_paciente->nombre = nombre;
	nuevo_paciente->apellido1 = apellido1;
	nuevo_paciente->apellido2 = apellido2;
	nuevo_paciente->cedula = cedula;
	nuevo_paciente->telefono = telefono;
	nuevo_paciente->fechaNacimiento = fechaNacimiento;
	nuevo_paciente->edad = edad;
	nuevo_paciente->peso = peso;
	nuevo_paciente->altura = altura;
	nuevo_paciente->presion = presion;
	nuevo_paciente->sintomas = sintomas;	
	return nuevo_paciente;
}


void MostrarPaciente(Paciente* paciente)
{
	std::cout << "#################################################";
	std::cout<<"Nombre: "<<paciente->nombre<<"\n";
	std::cout<<"Primer apellido: "<<paciente-> apellido1 <<"\n";
	std::cout<<"Segundo apellido: "<<paciente-> apellido2 <<"\n";
	std::cout<<"Cedula: "<<paciente-> cedula <<"\n";
	std::cout<<"Fecha de Nacimiento: "<<paciente-> fechaNacimiento <<"\n";
	std::cout<<"Edad: "<<paciente-> edad <<"\n";
	std::cout<<"Peso: "<<paciente-> peso <<"\n";
	std::cout<<"Altura "<<paciente -> altura <<"\n";
	std::cout<<"Presion Arterial: "<<paciente-> presion <<"\n";
	std::cout<<"Sintomas: "<<paciente-> sintomas <<"\n";
}



Paciente* IngresarDatosDelPaciente()
{
	int telefono, edad, cedula;
	std::string nombrePaciente, apellido1Paciente, apellido2Paciente, fechaNecimientoPaciente, sintomas, presion;
	float peso, altura;

	std::cout << "\tDATOS DEL PACIENTE: \n";//Muestra datos hacia el sistema <<
	std::cout << "Digite el nombre del Paciente:\n";
	std::cin >> nombrePaciente;
	std::cout << "Digite el primer apellido del Paciente:\n";
	std::cin >> apellido1Paciente;
	std::cout << "Digite el segundo apellido del Paciente:\n";
	std::cin >> apellido2Paciente;
	std::cout << "Digite la cedula del Paciente en formato x0xxx0xxx:\n";
	std::cin >> cedula;
	std::cout << "Digite el telefono del Paciente:\n";
	std::cin >> telefono;
	std::cout << "Digite la fecha de nacimiento del Paciente dd-mm-aaaa:\n";
	std::cin >> fechaNecimientoPaciente;
	std::cout << "Digite la edad del Paciente:\n";
	std::cin >> edad;
	std::cout << "Digite el Peso del Paciente:\n";
	std::cin >> peso;
	std::cout << "Digite la altura del Paciente:\n";
	std::cin >> altura;
	std::cout << "Digite la Presion Arterial del Paciente:\n";
	std::cin >> presion;
	std::cout << "Digite los Sintomas del Paciente:\n";
	std::cin >> sintomas;

	Paciente* nuevo_paciente = crearPaciente(
		nombrePaciente,
		apellido1Paciente,
		apellido2Paciente,
		cedula,
		telefono,
		fechaNecimientoPaciente,
		edad,
		peso,
		altura,
		presion,
		sintomas
	);

	return nuevo_paciente;
}


