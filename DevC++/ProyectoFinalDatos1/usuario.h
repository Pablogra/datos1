#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

struct Usuario {
	std::string nombre;
	std::string apellido1;
	std::string apellido2;
	int codigo;
	std::string tipoDeUsuario;
	std::string cuentaDeUsuario;
	std::string contrasena;
	bool activo;
};


// Método contructor de un doctor
Usuario* crearUsuario(
	std::string nombre,
	std::string apellido1,
	std::string apellido2,
	int codigo,
	std::string tipoDeUsuario,
	std::string cuentaDeUsuario,
	std::string contrasena
);

// Este método imprime en la consola la información de un doctor.
void MostrarUsuario(Usuario* usuario);

// Ingresa los datos del Usuario desde la consola.
// Retorna una estructura de typo Usuario
Usuario* IngresarDatosDelUsuario();