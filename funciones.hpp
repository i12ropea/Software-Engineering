#ifndef _FUNCIONES_HPP_
#define _FUNCIONES_HPP_

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int menu()
{
	int opcion;

	cout<<"------ MENÚ ------\n";
	cout<<"  1: Listar todos los pacientes del sistema.\n";
	cout<<"  2: Insertar un paciente nuevo.\n";
	cout<<"  3: Modificar los datos de un paciente.\n";
	cout<<"  4: Borrar un paciente.\n";
	cout<<"  5: Buscar un paciente.\n";
	cout<<"  0: Apagar sistema.\n\n";

	cout<<"Introduce la opción que desee: ";
	cin>>opcion;

	return opcion;
}

/* El sistema permitirá almacenar los siguientes datos de un paciente: Nombre,
Apellidos, DNI, fecha de nacimiento, teléfono y citas. Citas es un atributo de múltiple valores
compuesto por los siguientes atributos: fecha, hora, motivo.*/

typedef struct cita
{
	string fecha;
	string hora;
	string motivo;
}Cita;


class Contacto
{
private:
	string _nombre;
	string _apellido1;
	string _apellido2;
	int _dni;
	string _fechaNac;
	int _telefono;
	int _numCitas;
	vector <Cita> _citas;

public:
	string getNombre()
	{
		return _nombre;
	}

	string getApellido1()
	{
		return _apellido1;
	}

	string getApellido2()
	{
		return _apellido2;
	}

	int getDNI()
	{
		return _dni;
	}

	string getFechaNac()
	{
		return _fechaNac;
	}

	int getTelefono()
	{
		return _telefono;
	}

	int getNumCitas()
	{
		return _numCitas;
	}

	vector <Cita> getCitas()
	{
		return _citas;
	}

	void setNombre(string nombre)
	{
		_nombre=nombre;
	}

	void setApellido1(string apellido1)
	{
		_apellido1=apellido1;
	}

	void setApellido2(string apellido2)
	{
		_apellido2=apellido2;
	}

	void setDNI(int dni)
	{
		_dni=dni;
	}

	void setTelefono(int telefono)
	{
		_telefono=telefono;
	}

	void setNumCitas(int num)
	{
		_numCitas=num;
	}

	//modificador del vector citas
	void insertarCita(string fecha,string hora,string motivo)
	{
		Cita aux;

		aux.fecha=fecha;
		aux.hora=hora;
		aux.motivo=motivo;

		_citas.push_back(aux);

		_numCitas++;
	}

};

void imprimirContacto(Contacto aux)
{
	vector<Cita> citas;

	cout<<"Datos del paciente "<<aux.getNombre()<<" "<<aux.getApellido1()<<" "<<aux.getApellido2()<<":\n";
	cout<<"DNI: "<<aux.getDNI()<<"\n";
	cout<<"Fecha de naciemiento: "<<aux.getFechaNac()<<"\n";
	cout<<"Teléfono de contacto: "<<aux.getTelefono()<<"\n";
	cout<<"Historial de citas: \n";

	vector<Cita>::const_iterator it;

	citas=aux.getCitas();

	for (it =citas.begin(); it != citas.end(); ++it)
	{
		cout<<"    Fecha: "<<it->fecha<<"\n";
		cout<<"    Hora: "<<it->hora<<"\n";
		cout<<"    Motivo: "<<it->motivo<<"\n";
	}
}

void listarContactos()
{
	cout << "hola5" <<endl;

	ifstream fich("agenda.txt");
	vector <Cita> aux_citas;
	string fecha,hora,motivo,nombre,apell1,apell2,nacimiento;
	int dni,telefono,numeroCitas;

	Contacto aux;

	cout << "hola3" <<endl;

	while(!fich.eof())
	{
		fich >> nombre;
		aux.setNombre(nombre);

		fich >> apell1;
		aux.setApellido1(apell1);

		fich >> apell2;
		aux.setApellido2(apell2);

		fich >> dni;
		aux.setDNI(dni);

		fich >> telefono;
		aux.setTelefono(telefono);

		fich >> numeroCitas;
		aux.setNumCitas(numeroCitas);

		cout << "hola4" <<endl;

		for (int i=0;i<numeroCitas;i++)
		{
			cout<<"bucle 1"<<endl;

			fich >> fecha;
			fich >> hora;
			fich >> motivo;

			cout<<"antes insertar"<<endl;

			aux.insertarCita(fecha,hora,motivo);
		}
		cout << "hola" <<endl;

		imprimirContacto(aux);

		cout << "hola2" <<endl;
	}

	fich.close();

}

#endif
