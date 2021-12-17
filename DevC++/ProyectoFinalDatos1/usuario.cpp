#include <iostream>
#include <stdlib.h>
#include <string>
#include "usuario.h"

//Define usuario
Usuario* crearUsuario(
	std::string nombre,
	std::string apellido1,
	std::string apellido2,
	int codigo,
	std::string tipoDeUsuario,
	std::string cuentaDeUsuario,
	std::string contrasena
)

//Constructor del usuario
{
	Usuario* nuevo_usuario = new Usuario();
	nuevo_usuario->nombre = nombre;
	nuevo_usuario->apellido1 = apellido1;
	nuevo_usuario->apellido2 = apellido2;
	nuevo_usuario->codigo = codigo;
	nuevo_usuario->tipoDeUsuario = tipoDeUsuario;
	nuevo_usuario->cuentaDeUsuario = cuentaDeUsuario;
	nuevo_usuario->contrasena = contrasena;
	nuevo_usuario->activo = true;
	return nuevo_usuario;
};

//Para imprimir informacion del usuario
void MostrarUsuario(Usuario* usuario)
{
	std::cout << "#################################################\n";
	std::cout << "Nombre: " << usuario->nombre << " ";
	std::cout << usuario->apellido1 << " ";
	std::cout << usuario->apellido2 << ", ";
	std::cout << "Codigo: " << usuario->codigo << ". \n";
	std::cout << "Tipo: " << usuario->tipoDeUsuario<< ". \n";
	std::cout << "Cuenta: " << usuario->cuentaDeUsuario << ". \n";	
	std::cout << "Activo: " << usuario->activo << ". \n";
};

//Solicita datos del usuario
Usuario* IngresarDatosDelUsuario()
{
	//Variables de Usuario
	std::string nombre, apellido1, apellido2, tipoDeUsuario, cuentaDeUsuario, contrasena;
	int codigo, opcionTipoDeUsuario;

	std::cout << "\tDATOS DEL Usuario: \n";
	std::cout << "Digite el nombre del usuario:\n";
	std::cin >> nombre;
	std::cout << "Digite el primer apellido del usuario:\n";
	std::cin >> apellido1;
	std::cout << "Digite el segundo apellido del usuario:\n";
	std::cin >> apellido2;
	
	std::cout << "Ingrese tipo de usuario:\n\n";
	std::cout << "1. Admin\n";
	std::cout << "2. User\n";
	std::cout << "Opcion: ";
	
	//Solicita tipo de usuario que debe crearse

	std::cin >> opcionTipoDeUsuario;
	
	do {
		switch (opcionTipoDeUsuario) {
			case 1:
				tipoDeUsuario = "A";
				break;
			case 2:
				tipoDeUsuario = "E";
				break;
		}
	} while (!(opcionTipoDeUsuario == 1 || opcionTipoDeUsuario == 2));

	std::cout << "Digite la cuenta de usuario:\n";
	std::cin >> cuentaDeUsuario;
	

	int contrasenaValida = false;
	do 
	{
		std::cout << "Digite la contrasena del usuario:\n";
		std::cin >> contrasena;

		if (contrasena.length() > 7)
		{
			//TODO: otras validaciones
			contrasenaValida = true;
		}
		else
			std::cout << "Contrasena invalida, debe tener al menos 8 caracteres\n\n";

	} 
	while (!contrasenaValida);

//Crea el usuario
	Usuario* nuevo_usuario = crearUsuario(
		nombre,
		apellido1,
		apellido2, 
		0,
		tipoDeUsuario, 
		cuentaDeUsuario, 
		contrasena
	);

	return nuevo_usuario;
}

