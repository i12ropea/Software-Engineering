#ifndef _FUNCIONES_HPP_
#define _FUNCIONES_HPP_

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

//Función para mostrar el menú de opciones del sistema
int menu()
{
	int opcion;

	cout<<"=============================================="<<endl;
	cout<<"------------------- MENÚ -------------------\n";
	cout<<"  1: Listar todos los pacientes del sistema.\n";
	cout<<"  2: Insertar un paciente nuevo.\n";
	cout<<"  3: Añadir cita a paciente\n";
	cout<<"  4: Modificar los datos de un paciente.\n";
	cout<<"  5: Borrar un paciente.\n";
	cout<<"  6: Buscar un paciente.\n";
	cout<<endl;
	cout<<"  9: Realizar copia de seguridad.\n";
	cout<<"  0: Apagar sistema.\n\n";
	cout<<"----------------------------------------------"<<endl;

	cout<<"Introduce la opción que desee: ";
	cin>>opcion;
	cout<<endl;
	cout<<"==============================================";

	cout<<endl;

	return opcion;
}

/* El sistema permitirá almacenar los siguientes datos de un paciente: Nombre,
Apellidos, DNI, fecha de nacimiento, teléfono y citas. Citas es un atributo de múltiple valores
compuesto por los siguientes atributos: fecha, hora, motivo.*/

//ESTRUCTURA PARA LAS CITAS DE CADA PACIENTE
typedef struct cita
{
	string fecha;
	string hora;
	string motivo;
}Cita;

//CLASE CONTACTO
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

	void setFechaNac(string fn)
	{
		_fechaNac=fn;
	}

	void setTelefono(int telefono)
	{
		_telefono=telefono;
	}

	void setNumCitas(int num)
	{
		_numCitas=num;
	}

	void setCitas(vector <Cita> aux)
	{
		_citas=aux;
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

//Función para buscar un paciente en el sistema
int buscar(const int dni,const vector <Contacto> contactos)
{
	Contacto aux;
	int encon=-1;

	for (int i=0;i<contactos.size();i++)
	{
		aux=contactos[i];
		if (aux.getDNI()==dni)
		{
			encon=i;
			break;
		}
	}

	return encon;
}

//Función para imprimir los datos de un paciente
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
		cout<<"         Hora: "<<it->hora<<"\n";
		cout<<"         Motivo: "<<it->motivo<<"\n";
	}
}

//Función para volcar los datos del fichero .txt al vector
vector <Contacto> cargarContactosBaseDatos()
{
	vector <Contacto> contactos;
	vector <Cita> citas;
	ifstream fich("agenda.txt");
	string nombre, apell1, apell2, fn;
	int dni,telefono,numeroCitas;
	Contacto aux;
	Cita aux2;

	int x=0;


	while (!fich.eof())
	{
		fich>>nombre;
		aux.setNombre(nombre);

		fich >> apell1;
		aux.setApellido1(apell1);

		fich >> apell2;
		aux.setApellido2(apell2);

		fich >> dni;
		aux.setDNI(dni);

		fich >> fn;
		aux.setFechaNac(fn);

		fich >> telefono;
		aux.setTelefono(telefono);

		fich >> numeroCitas;
		aux.setNumCitas(numeroCitas);

		for (int i=0;i<numeroCitas;i++)
		{
			fich >> aux2.fecha;
			fich >> aux2.hora;
			fich >> aux2.motivo;

			citas.push_back(aux2);
		}

		aux.setCitas(citas);
		citas.clear();

		contactos.push_back(aux);
	}

	fich.close();

	contactos.pop_back();

	return contactos;
}

//Función para listar los pacientes del sistema
void listarContactos(const vector <Contacto> contactos)
{
	cout<<contactos.size();
	for (int i=0;i<contactos.size();i++)
	{
		cout<<endl;
		imprimirContacto(contactos[i]);
		cout<<"=================="<<endl;
	}

}

//Función para realizar una copia de seguridad
void realizarCopiaDeSeguridad(const vector <Contacto> contactos)
{
	Contacto aux;
	vector <Cita> citas;
	ofstream fich("aux.txt");
	if (fich)
	{
		for (int i=0; i<contactos.size();i++)
		{
			aux=contactos[i];

			fich << aux.getNombre()<< " " << aux.getApellido1() << " " << aux.getApellido2() << " " << aux.getDNI() << " " << aux.getFechaNac() << " " << aux.getTelefono() << " " << aux.getNumCitas()<<" ";

			citas=aux.getCitas();

			for (int j=0; j< aux.getNumCitas();j++)
			{


				fich << citas[j].fecha <<" "<< citas[j].hora <<" "<< citas[j].motivo<<" ";
			}

			citas.clear();

			if (i!=contactos.size()-1)
				fich << "\n";
		}

		fich.close();
		remove("agenda.txt");
		rename("aux.txt","agenda.txt");

	}
	else
	{
		cout<<"ERROR al realizar la copia de seguridad!"<<endl;
	}
}

//Función para introducir un paciente nuevo en el sistema
void introducirPacienteNuevo(vector <Contacto> &contactos)
{
	Contacto aux;
	string nombre,ap1,ap2,fn;
	int dni,tlf;

	cout<<"Introducir los datos:"<<endl;
	cout<<"Introduce el nombre: ";
	cin>>nombre;
	cout<<"Introduce el primer apellido: ";
	cin>>ap1;
	cout<<"Introduce el segundo apellido: ";
	cin>>ap2;
	cout<<"Introduce el dni: ";
	cin>>dni;
	cout<<"Introduce la fecha de nacimiento (formato dd/mm/aaaa): ";
	cin>>fn;
	cout<<"Introduce el teléfono de contacto: ";
	cin>>tlf;

	aux.setNombre(nombre);
	aux.setApellido1(ap1);
	aux.setApellido2(ap2);
	aux.setDNI(dni);
	aux.setFechaNac(fn);
	aux.setTelefono(tlf);
	aux.setNumCitas(0);

	contactos.push_back(aux);

	cout<<endl<<"Guardando contacto en la base de datos..."<<endl;
	realizarCopiaDeSeguridad(contactos);
	cout<<"Contacto guardado en la base de datos con éxito!"<<endl<<endl;;
}

//Función para añadir un cita nueva a un paciente
void anadirCitaPaciente(vector <Contacto> &contactos,const int paciente,const int pos)
{
	vector <Cita> aux;
	Cita aux2;
	string f,h,m;

	aux=contactos[pos].getCitas();

	cout<<"La cita será añadida al paciente: "<<endl;
	cout<<"		Nombre: "<<contactos[pos].getNombre()<<endl;
	cout<<"		Apellidos: "<<contactos[pos].getApellido1()<<" "<<contactos[pos].getApellido2()<<endl;
	cout<<" 	DNI: "<<contactos[pos].getDNI()<<endl<<endl<<endl;


	cout<<"Introduzca la fecha de la cita: ";
	cin>>f;
	cout<<"Introduzca la hora de la cita: ";
	cin>>h;
	cout<<"Introduzca el motivo de la cita: ";
	cin>>m;

	aux2.fecha=f;
	aux2.hora=h;
	aux2.motivo=m;

	aux.push_back(aux2);

	contactos[pos].setCitas(aux);
	contactos[pos].setNumCitas(contactos[pos].getNumCitas()+1);
}

//Funcion para modificar los datos de un paciente
void modificarDatosPaciente(vector <Contacto> &aux,const int pos)
{
	string nombre,ap1,ap2,fn;
	int dni,tlf;
	char opc;

	cout<<"Estos son los datos del paciente que desea modificar:"<<endl;
	imprimirContacto(aux[pos]);
	cout<<endl;

	cout<<"Introducir los datos nuevos:"<<endl<<endl;
	cout<<"¿Desea modificar el nombre? (S-->SI; N-->NO)";
	cin>>opc;
	if (opc=='S')
	{
		cout<<"Introduce el nombre: ";
		cin>>nombre;
	}
	else
	{
		nombre=aux[pos].getNombre();
	}

	cout<<"¿Desea modificar el primer apellido? (S-->SI; N-->NO)";
	cin>>opc;
	if (opc=='S')
	{
		cout<<"Introduce el primer apellido: ";
		cin>>ap1;
	}
	else
	{
		ap1=aux[pos].getApellido1();
	}

	cout<<"¿Desea modificar el segundo apellido? (S-->SI; N-->NO)";
	cin>>opc;
	if (opc=='S')
	{
		cout<<"Introduce el segundo apellido: ";
		cin>>ap2;
	}
	else
	{
		ap2=aux[pos].getApellido2();
	}

	cout<<"¿Desea modificar el DNI? (S-->SI; N-->NO)";
	cin>>opc;
	if (opc=='S')
	{
		cout<<"Introduce el DNI: ";
		cin>>dni;
	}
	else
	{
		dni=aux[pos].getDNI();
	}

	cout<<"¿Desea modificar la fecha de nacimiento? (S-->SI; N-->NO)";
	cin>>opc;
	if (opc=='S')
	{
		cout<<"Introduce la fecha de nacimiento (formato dd/mm/aaaa): ";
		cin>>fn;
	}
	else
	{
		fn=aux[pos].getFechaNac();
	}

	cout<<"¿Desea modificar el teléfono de contacto? (S-->SI; N-->NO)";
	cin>>opc;
	if (opc=='S')
	{
		cout<<"Introduce el teléfono de contacto: ";
		cin>>tlf;
	}
	else
	{
		tlf=aux[pos].getTelefono();
	}

	aux[pos].setNombre(nombre);
	aux[pos].setApellido1(ap1);
	aux[pos].setApellido2(ap2);
	aux[pos].setDNI(dni);
	aux[pos].setFechaNac(fn);
	aux[pos].setTelefono(tlf);

}

//Funcion para borrar un paciente
void borrarPaciente(vector <Contacto> &contactos,const int pos)
{
	for(int i=0;i<contactos.size()-1;i++)
	{
		if(i>=pos)
		{
			contactos[i]=contactos[i+1];
		}
	}

	contactos.pop_back();
}

#endif
