#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>//Manejo de msj de entrada y salida 
#include <string>//Permite uso de strings
#include <cctype>

#include "listaEnlazada.h"
#include "util.h"

#include "paciente.h"
#include "doctor.h"
#include "cita.h"
#include "usuario.h"

// TODO: 



using namespace std;//Dice a los datos que son de tipo estandar

// Definicion de las listas a usar para la aplicación
Lista* pacientes;
Lista* doctores;
Lista* citas;
Lista* usuarios;
Lista* codigos;

// Definicion del usuario que esta logeado
Usuario* usuarioLogeado;


/* Definiciones */

int RandomEnRango(int minimo, int maximo);
void* ConvertirIntAVoid(int numero);
int ConvertirVoidAInt(void* valor);
int CrearNuevoCodigo();
bool EsAdmin();
void MostrarCodigo(int codigo);

bool MostrarCodigoDeLaLista(int indice, Nodo* nodo);
bool MostrarPacienteDeLaLista(int indice, Nodo* nodo);
bool MostrarDoctorDeLaLista(int indice, Nodo* nodo);
bool MostrarUsuarioDeLaLista(int indice, Nodo* nodo);
bool MostrarCitaDeLaLista(int indice, Nodo* nodo);

bool BuscarPacientePorCedula(void* valor, Nodo* nodo);
bool BuscarDoctorPorCodigo(void* valor, Nodo* nodo);
bool BuscarUsuarioPorCodigo(void* valor, Nodo* nodo);
bool BuscarUsuarioPorCuenta(void* valor, Nodo* nodo);
bool BuscarCitaPorCedula(void* valor, Nodo* nodo);
bool BuscarUsuarioPorCuenta(void* valor, Nodo* nodo);
bool BuscarCodigo(void* valor, Nodo* nodo);
bool BuscarCitaPorFechaYHora(void* valor, Nodo* nodo);


Doctor* BuscarDoctor(int codigo);
Usuario* BuscarUsuario(int codigo);
Paciente* BuscarPaciente(int cedula);
Cita* BuscarCita(int codigoDoctor, int cedula);
Usuario* BuscarUsuarioPorCuenta(string cuenta);
Cita* BuscarCitaPorFechaHoraYDoctor(string fecha, string hora, int codigo);

void MostarTodosLosPacientes();
void MostrarTodosLosDoctores();
void MostrarTodosLosUsuarios();
void MostrarTodosLosCodigos();
void MostrarTodasLasCitasParaDoctor(int codigo);


Paciente* EliminarPaciente(int cedula);
Doctor* EliminarDoctor(int cedula);
Usuario* EliminarUsuario(int codigo);
Cita* EliminarCita(int codigoDoctor, int cedula);

void MenuPacientes_RegistrarPaciente();

void MenuPacientes_MostrarPacientes();

void MenuPacientes_BuscarPaciente();

void MenuPacientes_EliminarPaciente();

void MenuPacientes_EditarPaciente();

void MenuDoctores_RegistraDoctor();

void MenuDoctores_MostrarDoctores();

void MenuDoctores_ModificarDoctor();

void MenuDoctores_EliminarDoctor();

void MenuDoctores_MostrarCitas();


void MenuCitas_RegistrarCita();

void MenuCitas_EliminarCita();

void MenuCitas_EditarCita();

void MenuCitas_MostrarCita();

void MenuUsuarios_RegistrarUsuario();

void MenuUsuarios_MostrarListaDeUsuarios();

void MenuUsuarios_EliminarUsuario();

void MenuUsuarios_ModificarUsuario();

void MenuUsuarios();
void MenuCitas();
void MenuDoctores();
void MenuPacientes();


/* Implementaciones */
int RandomEnRango(int minimo, int maximo)
{
	return (rand() % (minimo - maximo + 1)) + minimo;	
}

void* ConvertirIntAVoid(int numero)
{
	return reinterpret_cast<void*>(static_cast<intptr_t>(numero));
}

int ConvertirVoidAInt(void* valor)
{
	return static_cast<int>(reinterpret_cast<intptr_t>(valor));
}

bool EsAdmin() {
	return usuarioLogeado->tipoDeUsuario == "A";
}

void MostrarCodigo(int codigo)
{
	std::cout << codigo << "\n";
}


bool MostrarCodigoDeLaLista(int indice, Nodo* nodo)
{
	// Se hace "cast" del valor de datos
	// Datos es de tipo void asi que puede ser lo que sea.
	// Mostrar codigo,  imprime el codigo
	MostrarCodigo(ConvertirVoidAInt(nodo->datos));

	// Contesta true porque si contesta false el iterador terimna de iterar.
	return true;
}

// Este método se pasa como argumento al iterador genérico de la lista
// Este metodo recibe como parametro el indice del iterador y el nodo
bool MostrarPacienteDeLaLista(int indice, Nodo* nodo)
{
	// Se hace "cast" del valor de datos datos
	// Datos es de tipo void asi que puede ser lo que sea.
	// Mostrar paciempte imprime los daltos del paciente
	MostrarPaciente((struct Paciente*)nodo->datos);

	// Contesta true porque si contesta false el iterador terimna de iterar.
	return true;
}

// Este método se pasa como argumento al iterador genérico de la lista
// Este metodo recibe como parametro el indice del iterador y el nodo
bool MostrarDoctorDeLaLista(int indice, Nodo* nodo)
{
	// Se hace "cast" del valor de datos datos
	// Datos es de tipo void asi que puede ser lo que sea.
	// Mostrar paciempte imprime los daltos del paciente
	MostrarDoctor((struct Doctor*)nodo->datos);

	// Contesta true porque si contesta false el iterador terimna de iterar.
	return true;
}

// Este método se pasa como argumento al iterador genérico de la lista
// Este metodo recibe como parametro el indice del iterador y el nodo
bool MostrarUsuarioDeLaLista(int indice, Nodo* nodo)
{
	// Se hace "cast" del valor de datos datos
	// Datos es de tipo void asi que puede ser lo que sea.
	// Se imprime el usuario
	MostrarUsuario((struct Usuario*)nodo->datos);

	// Contesta true porque si contesta false el iterador terimna de iterar.
	return true;
}

// Este método se pasa como argumento al iterador genérico de la lista
// Este metodo recibe como parametro el indice del iterador y el nodo
bool MostrarCitaDeLaLista(int indice, Nodo* nodo)
{
	MostrarCita((struct Cita*)nodo->datos);

	// Contesta true porque si contesta false el iterador terimna de iterar.
	return true;
}

bool BuscarPacientePorCedula(void* valor, Nodo* nodo)
{
	Paciente* paciente = (struct Paciente*)nodo->datos;
	int val = ConvertirVoidAInt(valor);

	return (int)(paciente->cedula) == (int)val;
}

bool BuscarDoctorPorCodigo(void* valor, Nodo* nodo)
{
	Doctor* doctor = (struct Doctor*)nodo->datos;
	int val = ConvertirVoidAInt(valor);

	return (int)(doctor->codigo) == (int)val;
}

bool BuscarUsuarioPorCodigo(void* valor, Nodo* nodo)
{
	Usuario* usuario = (struct Usuario*)nodo->datos;	
	int val = ConvertirVoidAInt(valor);

	return (int)(usuario->codigo) == (int)val;
}

bool BuscarUsuarioPorCuenta(void* valor, Nodo* nodo)
{
	Usuario* usuario = (struct Usuario*)nodo->datos;
	std::string *val = static_cast<std::string*>(valor);
	string simpleValue = *val;
	return usuario->cuentaDeUsuario == simpleValue;
}

bool BuscarCitaPorCedula(void* valor, Nodo* nodo)
{
	Cita* cita = (struct Cita*)nodo->datos;
	int val = ConvertirVoidAInt(valor);

	return (int)(cita->cedPaciente) == (int)val;
}

bool BuscarCodigo(void* valor, Nodo* nodo)
{
	int codigo = ConvertirVoidAInt(nodo->datos);
	int intVal = ConvertirVoidAInt(valor);
	bool sonIguales = codigo == intVal;
	return sonIguales;
}

bool BuscarCitaPorFechaYHora(void* valor, Nodo* nodo)
{
	Cita* cita = (struct Cita*)nodo->datos;
	Cita* citaValor = (struct Cita*)valor;
	bool sonIguales = ( cita->fechaCita == citaValor->fechaCita 
		&& cita->horaCita == citaValor->horaCita);
	return sonIguales;
}






Doctor* BuscarDoctor(int codigo) {
	Nodo* nodo = lista_buscar(
		doctores,
		ConvertirIntAVoid(codigo),
		BuscarDoctorPorCodigo);

	if (nodo != NULL) {
		Doctor* doctor = (struct Doctor*)nodo->datos;
		return (struct Doctor*)nodo->datos;
	}
	else {
		return NULL;
	}
}

Usuario* BuscarUsuario(int codigo) {
	Nodo* nodo = lista_buscar(
		usuarios,
		ConvertirIntAVoid(codigo),
		BuscarDoctorPorCodigo);

	if (nodo != NULL) {
		Usuario* usuario = (struct Usuario*)nodo->datos;
		return (struct Usuario*)nodo->datos;
	}
	else {
		return NULL;
	}
}

Paciente* BuscarPaciente(int cedula) {
	Nodo* nodo = lista_buscar(
		pacientes,
		ConvertirIntAVoid(cedula),
		BuscarPacientePorCedula);

	if (nodo != NULL) {
		Paciente* paciente = (struct Paciente*)nodo->datos;
		return (struct Paciente*)nodo->datos;
	}
	else {
		return NULL;
	}
}

Cita* BuscarCita(int codigoDoctor, int cedula) {
	Doctor* doctor = BuscarDoctor(codigoDoctor);
	Paciente* paciente = BuscarPaciente(cedula);

	if (doctor != NULL && paciente != NULL) {
		// TODO: Validar hora de la cita
		Nodo* nodo = lista_buscar(
			doctor->citas,
			ConvertirIntAVoid(cedula),
			BuscarCitaPorCedula);
		if (nodo != NULL) {
			Cita* cita = (struct Cita*)nodo->datos;
			return (struct Cita*)nodo->datos;
		}
		else {
			return NULL;
		}
	}
	else if (doctor == NULL)
	{
		std::cout << "El Doctor no ha sido encontrado\n";
	}
	else if (paciente == NULL)
	{
		std::cout << "El Paciente no ha sido encontrado\n";
	}

	return NULL;
}

Usuario* BuscarUsuarioPorCuenta(string cuenta) 
{
	Nodo* nodo = lista_buscar(usuarios, &cuenta, BuscarUsuarioPorCuenta);
	if (nodo != NULL) {		
		return (struct Usuario*)nodo->datos;
	}	
	return NULL;
}

Cita* BuscarCitaPorFechaHoraYDoctor(string fecha, string hora, int codigo)
{
	Doctor* doctor = BuscarDoctor(codigo);

	if (doctor != NULL) {
		Cita* citaTemp = new Cita();
		citaTemp->fechaCita = fecha;
		citaTemp->horaCita = hora;
		Nodo* nodo = lista_buscar(doctor->citas, citaTemp, BuscarCitaPorFechaYHora);

		if (nodo != NULL) {
			return (struct Cita*)nodo->datos;
		}
	}
	return NULL;
}






// Imprime toda la lista de pacientes llamando al iterador de la lista
// Le pasa a la lista la funcion para imprimir un paciente
void MostarTodosLosPacientes()
{
	lista_iterar(pacientes, MostrarPacienteDeLaLista);
}

// Imprime toda la lista de doctores llamando al iterador de la lista
// Le pasa a la lista la funcion para imprimir un doctor
void MostrarTodosLosDoctores()
{
	lista_iterar(doctores, MostrarDoctorDeLaLista);
}

// Imprime toda la lista de usuarios llamando al iterador de la lista
// Le pasa a la lista la funcion para imprimir un usuario
void MostrarTodosLosUsuarios()
{
	lista_iterar(usuarios, MostrarUsuarioDeLaLista);
}

// Imprime toda la lista de codigos llamando al iterador de la lista
// Le pasa a la lista la funcion para imprimir un codigo
void MostrarTodosLosCodigos()
{
	lista_iterar(codigos, MostrarCodigoDeLaLista);
}

// Busca un doctor basado en el codigo e imprime todas sus citas
//  
void MostrarTodasLasCitasParaDoctor(int codigo)
{
	Doctor* doctor = BuscarDoctor(codigo);

	if (doctor != NULL)
	{
		if (doctor->citas->contador > 0)
			lista_iterar(doctor->citas, MostrarCitaDeLaLista);
		else 
			std::cout << "Doctor no tiene citas \n";
	}		
	else
		std::cout << "Doctor no encontrado \n";
}






// Metodo para modificar un Paciente
// Busca un elemento en la lista y lo modifica por referencia
void ModificarPaciente(int cedula) {

	int opcion, edad, ced;
	string nombrePaciente, apellido1Paciente, apellido2Paciente, fechaNecimientoPaciente, sintomas, presion;
	float peso, altura;

	Paciente* actual = BuscarPaciente(cedula);


	if (actual != NULL) {//Si esiste muestra los datos que se pueden editar
		do {
			//Ingresar el numero de lo que desea editar del paciente registrado
			cout << "\tSELECCIONE LO QUE DESEA EDITAR: \n";//Muestra datos hacia el sistema <<
			cout << "1. Nombre del Paciente\n";
			cout << "2. Primer Apellido del Paciente\n";
			cout << "3. Segundo Apellido del Paciente\n";
			cout << "4. Cedula del Paciente\n";
			cout << "5. Fecha de Nacimiento del Paciente\n";
			cout << "6. Edad del Paciente\n";
			cout << "7. Peso del Paciente\n";
			cout << "8. Altura del Paciente\n";
			cout << "9. Presion Arterial del Paciente\n";
			cout << "10. Sintomas del Paciente\n";
			cout << "0. Salir\n";

			cout << "Opcion: ";
			cin >> opcion;

			switch (opcion) {
				//Registra el nombre del paciente
			case 1:
				cout << "Digite el nombre del Paciente:\n";
				cin >> nombrePaciente;
				actual->nombre = nombrePaciente;
				system("pause");//Comandos del SO
				break;
				//Registra el primer apellido del paciente
			case 2:
				cout << "Digite el primer apellido del Paciente:\n";
				cin >> apellido1Paciente;
				actual->apellido1 = apellido1Paciente;
				system("pause");//Comandos del SO
				break;

				//Registra el segundo apellido del paciente	
			case 3:
				cout << "Digite el segundo apellido del Paciente:\n";
				cin >> apellido2Paciente;
				actual->apellido2 = apellido2Paciente;
				system("pause");//Comandos del SO
				break;

				//Registra la cedula del paciente	
			case 4:
				cout << "Digite la cedula del Paciente:\n";
				cin >> ced;
				actual->cedula = ced;
				system("pause");//Comandos del SO
				break;

				//Registra la fecha de nacimiento del paciente	
			case 5:
				cout << "Digite la fecha de nacimiento del Paciente:\n";
				cin >> fechaNecimientoPaciente;
				actual->fechaNacimiento = fechaNecimientoPaciente;
				system("pause");//Comandos del SO
				break;

				//Registra la edad del paciente	
			case 6:
				cout << "Digite la edad del Paciente:\n";
				cin >> edad;
				actual->edad = edad;
				system("pause");//Comandos del SO
				break;

				//Registra el peso del paciente	
			case 7:
				cout << "Digite el peso del Paciente:\n";
				cin >> peso;
				actual->peso = peso;
				system("pause");//Comandos del SO
				break;

				//Registra la altura del paciente	
			case 8:
				cout << "Digite la altura del Paciente:\n";
				cin >> altura;
				actual->altura = altura;
				system("pause");//Comandos del SO
				break;

				//Registra la presion arterial del paciente	
			case 9:
				cout << "Digite presion arterial del Paciente:\n";
				cin >> presion;
				actual->presion = presion;
				system("pause");//Comandos del SO
				break;
				//Registra los sintomas del paciente	
			case 10:
				cout << "Digite los sintomas del Paciente:\n";
				cin >> sintomas;
				actual->sintomas = sintomas;
				system("pause");//Comandos del SO
				break;
			}
			//Limpiar pantalla
			system("cls");
		} while (opcion != 0);

	}
	else {
		cout << "El paciente con la cedula " << ced << " no ha sido encontrado en la lista. \n";
	}
}//************************************Fin editarDatosPAciente

void ModificarCita(int codigo, int cedula) {

	Cita* actual = BuscarCita(codigo, cedula);

	if (actual != NULL)
	{
		int opcion;
		do {
			int  codigoDoctor;
			string fechaCita, horaCita;

			cout << "\tSELECCIONE LO QUE DESEA EDITAR: \n";//Muestra datos hacia el sistema <<
			//cout <<"1. Paciente\n";
			cout << "1. Doctor\n";
			cout << "2. Fecha de la Cita dd-mm-aaaa:\n";
			cout << "3. Hora de la Cita\n";
			cout << "0. Salir\n";

			cout << "Opcion: ";
			cin >> opcion;

			switch (opcion) 
			{
				case 1:
					cout << "Digite el Codigo del Nuevo Doctor:\n";

					cin >> codigoDoctor;
					actual->codigoDoctor = codigoDoctor;
					system("pause");//Comandos del SO
					break;
				case 2:
					cout << "Digite la nueva Fecha de a Cita:\n";
					cin >> fechaCita;
					actual->fechaCita = fechaCita;
					system("pause");//Comandos del SO
					break;
				case 3:
					cout << "Digite la nueva hora de la Cita:\n";
					cin >> horaCita;
					actual->horaCita = horaCita;
					system("pause");//Comandos del SO
					break;
				case 4:

					break;
			}
			//Limpiar pantalla
			system("cls");
		} while (opcion != 0);
	}
	
}
//**************************************************************************************





Paciente* EliminarPaciente(int cedula) {
	Nodo* nodo = lista_borrar(
		pacientes,
		ConvertirIntAVoid(cedula),
		BuscarPacientePorCedula);

	if (nodo != NULL) {
		Paciente* paciente = (struct Paciente*)nodo->datos;
		return (struct Paciente*)nodo->datos;
	}
	else {
		return NULL;
	}
}

Doctor* EliminarDoctor(int cedula) {
	Nodo* nodo = lista_borrar(
		doctores,
		ConvertirIntAVoid(cedula),
		BuscarPacientePorCedula);

	if (nodo != NULL) {
		Doctor* paciente = (struct Doctor*)nodo->datos;
		return (struct Doctor*)nodo->datos;
	}
	else {
		return NULL;
	}
}

Usuario* EliminarUsuario(int codigo) {
	Nodo* nodo = lista_borrar(
		usuarios,
		ConvertirIntAVoid(codigo),
		BuscarUsuarioPorCodigo);

	if (nodo != NULL) {
		Usuario* usuario = (struct Usuario*)nodo->datos;
		return (struct Usuario*)nodo->datos;
	}
	else {
		return NULL;
	}
}
//***********************************************************************************************


Cita* EliminarCita(int codigoDoctor, int cedula) {
	Doctor* doctor = BuscarDoctor(codigoDoctor);
	Paciente* paciente = BuscarPaciente(cedula);

	if (doctor != NULL && paciente != NULL) {
		// TODO: Validar hora de la cita
		Nodo* nodo = lista_borrar(
			doctor->citas,
			ConvertirIntAVoid(cedula),
			BuscarCitaPorCedula);
		if (nodo != NULL) {
			Cita* cita = (struct Cita*)nodo->datos;
			return (struct Cita*)nodo->datos;
		}
		else {
			return NULL;
		}
	}
	else if (doctor == NULL)
	{
		std::cout << "El Doctor no ha sido encontrado\n";
	}
	else if (paciente == NULL)
	{
		std::cout << "El Paciente no ha sido encontrado\n";
	}

	return NULL;
}


//*************************************************************************************

int CrearNuevoCodigo()
{
	int tentativo = RandomEnRango(1000, 10000000);
	void* tentativoVoid = ConvertirIntAVoid(tentativo);
	bool yaExiste = lista_contiene(codigos, tentativoVoid, BuscarCodigo);
	if (!yaExiste)
	{
		lista_insertar(codigos, tentativoVoid);
		return tentativo;
	}
	else
	{
		return CrearNuevoCodigo();
	}
}



void MenuPaciente()
{
	system("cls");
	int opcion;
	
	do {
		opcion = -1;
		cout << "\tMENU PACIENTE: \n";//Muestra datos hacia el sistema <<
		cout << "1. Registrar Paciente\n";
		cout << "2. Mostrar Lista de Pacientes\n";
		cout << "3. Buscar Paciente\n";
		cout << "4. Eliminar Paciente\n";
		cout << "5. Editar datos del Paciente\n";
		cout << "0. Salir\n";

		cout << "Opcion: ";
		cin >> opcion;//Captura datos de consola >>
		//Limpiar pantalla
		system("cls");


		switch (opcion) 
		{
		case 1:		
			//Ingresar los Datos del Paciente
			MenuPacientes_RegistrarPaciente();
			system("pause");//Comandos del SO
			break;
		case 2:		
			//Mostrar la lista de los Pacientes
			MenuPacientes_MostrarPacientes();
			system("pause");//Comandos del SO
			break;
		case 3:		
			// Buscar paciente por cedula
			MenuPacientes_BuscarPaciente();
			system("pause");//Comandos del SO		
			break;
		case 4:
			//Eliminar los datos de los Pacientes por numero de cedula
			MenuPacientes_EliminarPaciente();
			system("pause");//Comandos del SO		
			break;

		
		case 5:
			//Editar los datos de los Pacientes por nuemro de cedula		
			MenuPacientes_EditarPaciente();
			system("pause");//Comandos del SO		
			break;
		}

		//Limpiar pantalla
		system("cls");
		//Cuando opcion sea distinto o igual a 0 se sale del sistema de Paciente
	} while (opcion != 0);
}
//*******************************************************************************************


void MenuPacientes_EditarPaciente()
{
	int cedula;
	cout << "\tEDITAR PACIENTE: \n";//Muestra datos hacia el sistema <<
	cout << "Digite la cedula del Paciente a Editar:\n";
	cin >> cedula;

	ModificarPaciente(cedula);
	cout << "\n\n";
}

void MenuPacientes_EliminarPaciente()
{
	int cedula;
	cout << "\tELIMINAR PACIENTE: \n";//Muestra datos hacia el sistema <<
	cout << "Digite la cedula del Paciente a Eliminar:\n";
	cin >> cedula;

	Paciente* aEliminar = EliminarPaciente(cedula);
	if (aEliminar != NULL) {
		cout << "Paciente eliminado\n";
	}
	else {
		cout << "Paciente no encontrado";
	}

	cout << "\n\n";
}
//**********************************************************************************************




void MenuPacientes_BuscarPaciente()
{
	int cedula;
	cout << "\tBUSCAR PACIENTE: \n";
	cout << "Digite la cedula del Paciente a Buscar:\n";
	cin >> cedula;

	Paciente* aBuscar = BuscarPaciente(cedula);
	if (aBuscar != NULL) {
		MostrarPaciente(aBuscar);
	}
	else {
		cout << "Paciente no encontrado";
	}
	cout << "\n\n";
}

void MenuPacientes_MostrarPacientes()
{
	cout << "\tLISTA DE PACIENTES: \n";
	MostarTodosLosPacientes();
	cout << "\n";
}

void MenuPacientes_RegistrarPaciente()
{
	Paciente* nuevo_paciente;
	nuevo_paciente = IngresarDatosDelPaciente();
	//Inseratar los datos del Paciente 
	
	bool existe = lista_contiene(
		pacientes, 
		ConvertirIntAVoid(nuevo_paciente->cedula),
		BuscarPacientePorCedula);
	
	if (!existe) 
	{
		lista_insertar(pacientes, nuevo_paciente);	
	}
	else
	{
		cout << "\nPaciente ya existe\n";
	}	
	cout << "\n";
}



//*******************************************************************************************


void MenuDoctores()
{
	int opcion;
	do {
		//Variables de Doctor
		string nombreDoctor, apellido1Doctor, apellido2Doctor, especialidadDoctor;

		opcion = -1;

		cout << "\tMENU DOCTORES: \n";//Muestra datos hacia el sistema <<
		cout << "1. Registrar Doctor\n";
		cout << "2. Mostrar Lista de Doctores\n";
		cout << "3. Eliminar Doctor\n";
		cout << "4. Editar datos del Doctor\n";
		cout << "5. Mostrar las citas del Doctor\n";
		cout << "0. Salir\n";

		cout << "Opcion: ";
		cin >> opcion;//Captura datos de consola >>
		//Limpiar pantalla
		system("cls");

		switch (opcion) {			
			case 1:
				//Ingresar los datos del Doctor		
				MenuDoctores_RegistraDoctor();
				system("pause");//Comandos del SO		
				break;		
			case 2:
				//Muestra los datos de los Doctores		
				MenuDoctores_MostrarDoctores();
				system("pause");//Comandos del SO		
				break;		
			case 3:
				// Elimina los datos de los Doctores por numero de codigo			
				MenuDoctores_EliminarDoctor();
				system("pause");//Comandos del SO			
				break;
			case 4:		
				//Edita la lista d elos Doctores por nuemro de codigo	
				MenuDoctores_ModificarDoctor();//Edita los datos del doctor			
				system("pause");//Comandos del SO		
				break;
			case 5:
				// Muestra todas las citas del doctor
				MenuDoctores_MostrarCitas();
				system("pause");//Comandos del SO		
				break;
		}
		//Limpiar pantalla
		system("cls");
		//Cuando opcion sea distinto o igual a 0 se sale del sistema
	} while (opcion != 0);
}

//*************************************************************************************************



void MenuDoctores_MostrarCitas()
{
	int codigoDoctor;
	std::cout << "\tEDITAR DOCTOR: \n";//Muestra datos hacia el sistema <<
	std::cout << "Digite el Codigo del Doctor:\n";
	std::cin >> codigoDoctor;
	MostrarTodasLasCitasParaDoctor(codigoDoctor);//Edita los datos del doctor			
}

//*********************************************************************************************


void MenuDoctores_EliminarDoctor()
{
	if (EsAdmin())
	{
		int codigoDoctor;
		std::cout << "\tELIMINAR DOCTOR: \n";//Muestra datos hacia el sistema <<
		std::cout << "Digite el codigo del Doctor a Eliminar:\n";
		std::cin >> codigoDoctor;

		EliminarDoctor(codigoDoctor);//Elimina el doctor

		std::cout << "\n\n";
	}
	else
		std::cout << "No authorizado \n";
}

//*********************************************************************************************


void MenuDoctores_MostrarDoctores()
{
	cout << "\tLISTA DE DOCTORES: \n";//Muestra datos hacia el sistema <<

	MostrarTodosLosDoctores();//Mustra la lista de doctores

	cout << "\n\n";
}


void MenuDoctores_RegistraDoctor()
{
	if (EsAdmin())
	{
		Doctor* nuevo_doctor = IngresarDatosDelDoctor();
		nuevo_doctor->codigo = CrearNuevoCodigo();

		lista_insertar(doctores, nuevo_doctor);
		cout << "\n\n";
	}
	else
		cout << "No authorizado \n";
}



//***********************************************************************************************
// Metodo para modificar un Doctor
// Busca un elemento en la lista y lo modifica por referencia
void MenuDoctores_ModificarDoctor() {
	if (EsAdmin())
	{
		int codigoDoctor;
		std::cout << "\tEDITAR DOCTOR: \n";//Muestra datos hacia el sistema <<
		std::cout << "Digite el Codigo del Doctor a Editar:\n";
		std::cin >> codigoDoctor;

		// Busca un elemento y si lo encuentra retorna su referencia
		Doctor* actual = BuscarDoctor(codigoDoctor);

		// Si actual es nulo es que no encontró al doctor
		if (actual != NULL) {
			int opc;
			do {
				string nombreDoctor, apellido1Doctor, apellido2Doctor, especialidadDoctor;
				int codigo;

				std::cout << "\tSELECCIONE LO QUE DESEA MODIFICAR: \n";
				std::cout << "1. Nombre del Doctor\n";
				std::cout << "2. Primer Apellido del Doctor\n";
				std::cout << "3. Segundo Apellido del Doctor\n";
				std::cout << "4. Especialidad del Doctor\n";;
				std::cout << "0. Salir\n";

				std::cout << "Opcion: ";
				std::cin >> opc;//espera opc que ingrese el usuario

				switch (opc) {
					//
				case 1:
					std::cout << "Digite el nombre del Doctor:\n";
					std::cin >> nombreDoctor;
					actual->nombre = nombreDoctor;
					break;
				case 2:
					std::cout << "Digite el primer apellido del Doctor:\n";
					std::cin >> apellido1Doctor;
					actual->apellido1 = apellido1Doctor;
					break;
				case 3:
					std::cout << "Digite el segundo apellido del Doctor:\n";
					std::cin >> apellido2Doctor;
					actual->apellido2 = apellido2Doctor;
					break;
				case 4:
					std::cout << "Digite la especialidad del Doctor:\n";
					std::cin >> especialidadDoctor;
					actual->especialidad = especialidadDoctor;
					break;
				}
				system("cls");
			} while (opc != 0);

		}
		else {
			std::cout << "El Doctor con el codigo: " << codigoDoctor << " no a sido encontrado en la lista. \n";
		}

		std::cout << "\n\n";
	}
	else
		std::cout << "No authorizado \n";
}






void MenuUsuarios()
{
	int opcion;
	do {
		cout << "\tMENU USUAIOS: \n";
		cout << "1. Registrar Usuario\n";
		cout << "2. Mostrar Lista de Usuarios\n";
		cout << "3. Eliminar Usuario\n";
		cout << "4. Editar datos del Usuario\n";
		cout << "0. Salir\n";

		cout << "Opcion: ";
		cin >> opcion;

		//Limpiar pantalla
		system("cls");

		switch (opcion) {
			//Ingresar los datos del Usuario
			case 1:
				MenuUsuarios_RegistrarUsuario();
				system("pause");//Comandos del SO
				break;				
			case 2:
				//Muestra los datos de los Usuario
				MenuUsuarios_MostrarListaDeUsuarios();
				system("pause");//Comandos del SO
				break;			
			case 3:
				// Elimina los datos de los Usuarios por numero de codigo
				MenuUsuarios_EliminarUsuario();
				system("pause");//Comandos del SO
				break;			
			case 4:
				//Editar Usuario por nuemro de codigo			
				MenuUsuarios_ModificarUsuario();
				system("pause");//Comandos del SO			
				break;
			}
			//Limpiar pantalla
			system("cls");
		//Cuando opcion sea distinto o igual a 5 se sale del sistema
	} while (opcion != 0);
}

void MenuUsuarios_EliminarUsuario()
{
	if (EsAdmin())
	{
		int codigo;
		cout << "\tELIMINAR USUARIO: \n";//Muestra datos hacia el sistema <<
		cout << "Digite el codigo del Usuario a Eliminar:\n";
		cin >> codigo;

		EliminarUsuario(codigo);//Elimina el doctor

		cout << "\n\n";
		system("pause");//Comandos del S`O
	}
	else
		cout << "No authorizado \n";
}

void MenuUsuarios_MostrarListaDeUsuarios()
{
	MostrarTodosLosUsuarios();
	cout << "\n\n";
	system("pause");//Comandos del SO
}

void MenuUsuarios_RegistrarUsuario()
{
	if (EsAdmin())
	{

		Usuario* nuevo_usuario = IngresarDatosDelUsuario();
		nuevo_usuario->codigo = CrearNuevoCodigo();
		lista_insertar(usuarios, nuevo_usuario);
		cout << "\n\n";
		system("pause");//Comandos del SO
	}
	else
		cout << "No authorizado \n";	
}

// Metodo para modificar un Usuario
// Busca un elemento en la lista y lo modifica por referencia
void MenuUsuarios_ModificarUsuario() 
{
	int codigo;
	cout << "\tEDITAR Usuario: \n";//Muestra datos hacia el sistema <<
	cout << "Digite el Codigo del usuario:\n";
	cin >> codigo;

	int opc;
	string nombre, apellido1, apellido2, cuenta, contrasena;

	Usuario* actual = BuscarUsuario(codigo);

	if (actual != NULL) {
		do {
			cout << "\tSELECCIONE LO QUE DESEA MODIFICAR: \n";
			cout << "1. Nombre del Usuario\n";
			cout << "2. Primer Apellido del Usuario\n";
			cout << "3. Segundo Apellido del Usuario\n";
			cout << "4. Cuenta del Usuario\n";
			cout << "5. Contrasena del Usuario\n";
			cout << "6. Tipo del Usuario\n";
			cout << "7. Estado del usuario\n";
			cout << "0. Salir\n";

			cout << "Opcion: ";
			cin >> opc;//espera opc que ingrese el usuario

			switch (opc) {

				case 1:
					cout << "Digite el nombre del usuario:\n";
					cin >> nombre;
					actual->nombre = nombre;
					break;
				case 2:
					cout << "Digite el primer apellido del usuario:\n";
					cin >> apellido1;
					actual->apellido1 = apellido1;
					break;
				case 3:
					cout << "Digite el segundo apellido del usuario:\n";
					cin >> apellido2;
					actual->apellido2 = apellido2;
					break;
				case 4:
					cout << "Digite la cuenta del usuario:\n";
					cin >> cuenta;
					actual->cuentaDeUsuario = cuenta;
					break;
				case 5:
					cout << "Digite la contrasena del usuario:\n";
					cin >> contrasena;
					actual->contrasena = contrasena;
					break;
				case 6:
					if (EsAdmin())
					{
						std::cout << "Ingrese tipo de usuario:\n\n";
						std::cout << "1. Administrador\n";
						std::cout << "2. Estandar\n";

						int opcionTipoDeUsuario;
						std::cin >> opcionTipoDeUsuario;
						do {

							switch (opcionTipoDeUsuario) {
							case 1:
								actual->tipoDeUsuario = "A";
								break;
							case 2:
								actual->tipoDeUsuario = "E";
								break;
							}
						} while (!(opcionTipoDeUsuario == 1 || opcionTipoDeUsuario == 2));
					}
					else
						cout << "No authorizado \n";
					break;

				case 7:
					if (EsAdmin())
					{
						std::cout << "Ingrese estado de usuario:\n\n";
						std::cout << "1. Activo\n";
						std::cout << "2. Inactivo\n";

						int opcionEstadoDeUsuario;
						std::cin >> opcionEstadoDeUsuario;
						do {

							switch (opcionEstadoDeUsuario) {
							case 1:
								actual->activo = true;
								break;
							case 2:
								actual->activo = false;
								break;
							}
						} while (!(opcionEstadoDeUsuario == 1 || opcionEstadoDeUsuario == 2));
					}
					else
						cout << "No authorizado \n";
					break;
			}
			system("cls");
		} while (opc != 0);

	}
	else {
		cout << "El Usuario con el codigo: " << codigo << " no ha sido encontrado en la lista. \n";
	}
	cout << "\n\n";
}

void MenuCitas()
{
	system("cls");
	int opcion;
	do {
		cout << "\tMENU DE CITAS: \n";//Muestra datos hacia el sistema <<
		cout << "1. Registrar una nueva Cita\n";
		cout << "2. Eliminar Cita\n";
		cout << "3. Editar datos de la Cita\n";
		cout << "4. Mostrar informacion de la Cita\n";
		cout << "0. Salir\n";

		cout << "Opcion: ";
		//esperara la opcion a ingresar
		cin >> opcion;//Captura datos de consola >>
		//Limpiar pantalla
		system("cls");

		switch (opcion) {

		case 1:
			// Registrar una nueva cita
			MenuCitas_RegistrarCita();
			system("pause");//Comandos del SO
			break;

		case 2:
			//Eliminar una cita
			MenuCitas_EliminarCita();			
			system("pause");//Comandos del SO
			break;

		case 3:
			//Editar una cita
			MenuCitas_EditarCita();
			system("pause");//Comandos del SO
			break;
		case 4:
			//Mostrar una cita
			MenuCitas_MostrarCita();			
			system("pause");//Comandos del SO
			break;
		}
	} while (opcion != 0);
}

void MenuCitas_MostrarCita()
{
	int cedula, codigo;
	cout << "\tEditar CITAS: \n";
	cout << "Digite la cedula del Paciente:\n";
	cin >> cedula;

	cout << "Digite el codigo del Doctor que tiene la Cita:\n";
	cin >> codigo;

	MostrarCita(BuscarCita(codigo, cedula));

	cout << "\n\n";
}

void MenuCitas_EditarCita()
{
	int cedula, codigo;
	cout << "\tEditar CITAS: \n";
	cout << "Digite la cedula del Paciente que tiene la Cita a editar:\n";
	cin >> cedula;

	cout << "Digite el codigo del Doctor que tiene la Cita a editar:\n";
	cin >> codigo;

	Cita* cita = BuscarCita(codigo, cedula);


	if (cita != NULL)
	{
		int opcion;
		do {
			
			cout << "\tSELECCIONE LO QUE DESEA EDITAR: \n";//Muestra datos hacia el sistema <<
														   //cout <<"1. Paciente\n";
			cout << "1. Doctor\n";
			cout << "2. Fecha de la Cita dd-mm-aaaa:\n";
			cout << "3. Hora de la Cita\n";
			cout << "4. Salir\n";

			cout << "Opcion: ";
			cin >> opcion;

			int codigoDoctor;
			string fechaCita;
			string horaCita;

			switch (opcion) {
			case 1:

				cout << "Digite el Codigo del Nuevo Doctor:\n";

				cin >> codigoDoctor;
				cita->codigoDoctor = codigoDoctor;
				system("pause");//Comandos del SO
				break;
			case 2:

				cout << "Digite la nueva Fecha de a Cita:\n";
				cin >> fechaCita;
				cita->fechaCita = fechaCita;
				system("pause");//Comandos del SO
				break;
			case 3:

				cout << "Digite la nueva hora de la Cita:\n";
				cin >> horaCita;
				cita->horaCita = horaCita;
				system("pause");//Comandos del SO
				break;
			case 4:
				//Editar una cita
				int cedula, codigo;
				cout << "\tEditar CITAS: \n";
				cout << "Digite la cedula del Paciente que tiene la Cita:\n";
				cin >> cedula;

				cout << "Digite el codigo del Doctor que tiene la Cita:\n";
				cin >> codigo;

				Cita* cita = BuscarCita(codigo, cedula);
				MostrarCita(cita);
				break;

			}
			//Limpiar pantalla
			system("cls");
		} while (opcion != 4);

	}
	cout << "\n\n";

	system("pause");//Comandos del SO
}

void MenuCitas_EliminarCita()
{	
	int cedula, codigo;
	cout << "\tELIMINAR CITAS: \n";//Muestra datos hacia el sistema <<
	cout << "Digite la cedula del Paciente que tiene la Cita a eliminar:\n";
	cin >> cedula;

	cout << "Digite el codigo del Doctor que tiene la Cita a eliminar:\n";
	cin >> codigo;

	EliminarCita(codigo, cedula);

	cout << "\n\n";
}

void MenuCitas_RegistrarCita()
{		
	Cita* nueva_cita = IngresarDatosDeLaCita();
	Doctor* doctor = BuscarDoctor(nueva_cita->codigoDoctor);
	Paciente* paciente = BuscarPaciente(nueva_cita->cedPaciente);

	if (doctor != NULL && paciente != NULL) {
		
		Cita* existente = BuscarCitaPorFechaHoraYDoctor(
			nueva_cita->fechaCita,
			nueva_cita->horaCita,
			nueva_cita->codigoDoctor
		);

		if (!existente)
			lista_insertar(doctor->citas, nueva_cita);
		else
			cout << "Horario no disponible\n";

	}
	else if (doctor == NULL)
	{
		cout << "El Doctor no ha sido encontrado\n";
	}
	else if (paciente == NULL)
	{
		cout << "El Paciente no ha sido encontrado\n";
	}

	cout << "\n\n";	
}

void MenuPrincipal()
{
	//Limpiar pantalla
	system("cls");

	//Variables de Opcion de menu;
	int opcion;

	//Citas
	//int  editarCitaPoD, mostrarCitaPoD;//Por Doctor o Paciente
	string fechaCita, horaCita;//Doctor o paciente

	do {
		cout << "\tMENU PRINCIPAL: \n";//Muestra datos hacia el sistema <<
		cout << "1. Acceder al memu de Pacientes\n";
		cout << "2. Acceder al menu de Doctores\n";
		cout << "3. Acceder al menu de Citas\n";
		cout << "4. Acceder al menu de Usuarios\n";
		//cout << "5. Acceder al menu de Reportes\n";
		cout << "0. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;//Captura datos de consola >>


		switch (opcion) {
		case 1:
			system("cls");
			MenuPaciente();
			break;//Fin case1

		case 2:
			//Menu de doctores
			system("cls");
			MenuDoctores();
			break;

		case 3:
			//Menu de doctores
			system("cls");
			MenuCitas();
			break;

		case 4:
			//Menu de Usuarios
			system("cls");			
			MenuUsuarios();			
			break;
		}

		//Limpiar pantalla
		system("cls");
	} while (opcion != 0);
}

void MenuLogin()
{	
	//Limpiar pantalla
	system("cls");
	//Login de usuarios
	string cuenta, contrasena;

	cout << "\tACCESO DE USUARIOS \n\n";

	cout << "Cuenta de usuario:\n";
	cin >> cuenta;

	cout << "Contrasena:\n";
	cin >> contrasena;

	Usuario* usuario = BuscarUsuarioPorCuenta(cuenta);

	if (usuario != NULL)
	{
		if (usuario->contrasena == contrasena) 
		{
			usuarioLogeado = usuario;
			MenuPrincipal();
		}
		else 
		{
			std::cout << "Credenciales erroneas\n";
		}
	}
	else
	{
		std::cout << "Usuario invalido\n";
	}
}

void MenuInicial()
{
	int opcion;
	do {
		cout << "\tInicio: \n";
		cout << "1. Login\n";		
		cout << "0. Salir\n";

		cout << "Opcion: ";
		
		//esperara la opcion a ingresar
		cin >> opcion;//Captura datos de consola >>
		
		//Limpiar pantalla
		system("cls");

		switch (opcion)	{
		case 1:
			MenuLogin();
			system("pause");//Comandos del SO
			system("cls");
			break;
		}
	} while (opcion != 0);
}





int main(int argc, char* argv[]) {
	
	pacientes = lista_crear(sizeof(Paciente));
	doctores = lista_crear(sizeof(Doctor));	
	usuarios = lista_crear(sizeof(Usuario));
	codigos = lista_crear(sizeof(int));

	Paciente* nuevo_paciente = crearPaciente(
		"Pablo", "Granados", "Vargas", 123456789, 88462599, "19790602", 42, 80, 170, "120/80", "Dolor de cabeza"
	);

	Paciente* nuevo_paciente2 = crearPaciente(
		"STEVE", "Vai", "Awesome", 111, 88462599, "19790602", 42, 80, 170, "120/80", "Dolor de espalda"
	);

	Usuario* administrador = crearUsuario("Pablo", "Granados", "Vargas", CrearNuevoCodigo(), "A", "admin", "password");
	
	Usuario* clerk = crearUsuario("Clerk", "Apellido1", "Apellido2", CrearNuevoCodigo(), "E", "clerk", "asdfqwer");

	Doctor* doctor = crearDoctor("Muelitas", "Colgate", "Closeup", CrearNuevoCodigo(), "Dentista");
	Doctor* doctor2 = crearDoctor("Broken", "Arrow", "Lost", CrearNuevoCodigo(), "Cardiologo");


	lista_insertar(pacientes, nuevo_paciente);
	lista_insertar(pacientes, nuevo_paciente2);
	lista_insertar(usuarios, administrador);
	lista_insertar(usuarios, clerk);	
	lista_insertar(doctores, doctor);
	lista_insertar(doctores, doctor2);
	

	MenuInicial();

	return 0;
}



