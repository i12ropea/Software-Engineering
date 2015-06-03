#include "funciones.hpp"

int main()
{
	int opc,opc2,pos,encon;
	int paciente;

	//Al iniciar el sistema se carga la base de datos
	vector <Contacto> contactos=cargarContactosBaseDatos();

	do
	{
		opc=menu();

		switch(opc)
		{
		//APAGAR EL SISTEMA
		//ANTES DE APAGAR ACTUALIZA LA BASE DE DATOS Y APAGA EL PROGRAMA
		case 0:
			cout<<"APAGANDO SISTEMA...\n"<<endl;
			cout<<endl;
			cout<<"REALIZANDO COPIA DE SEGURIDAD..."<<endl;
			cout<<endl;
			realizarCopiaDeSeguridad(contactos);
			cout<<"COPIA DE SEGURDAD REALIZADA CON ÉXITO!"<<endl;
			cout<<endl;
			cout<<"SISTEMA APAGADO"<<endl<<endl;
			break;

		//LISTAR LOS PACIENTES DEL SISTEMA
		case 1:
			cout<<endl;
			cout<<"        CONTACTOS            "<<endl;
			cout<<"============================="<<endl;
			listarContactos(contactos);
			cout<<endl<<endl<<"Pulse enter para volver al menú."<<endl<<endl;
			getchar();
			getchar();
			break;

		//INTRODUCIR UN PACIENTE NUEVO
		case 2:
			cout<<endl;
			introducirPacienteNuevo(contactos);
			cout<<endl<<endl<<"Pulse enter para volver al menú."<<endl<<endl;
			getchar();
			getchar();
			break;

		//AÑADE UNA CITA NUEVA A UN DETERMINADO USUARIO INTRODUCIDO POR EL USUARIO
		//SI EL USUARIO NO EXISTE OFRECE LA OPCION DE AÑADIRLO AL SISTEMA
		case 3:
			cout<<endl;
			do
			{
				cout<<"Introduzca el dni del paciente que desea añadir la cita: ";
				cin >> paciente;
				pos=buscar(paciente,contactos);

				if(pos==-1)
				{
					cout<<"El paciente introducido no se encuentra en el sistema."<<endl;
					cout<<"¿Desea añadirlo al sistema? (SI-->1  || NO-->0 ): ";
					cin >> opc2;
					switch(opc2)
					{
					case 0:
						break;

					case 1:
						encon=1;
						introducirPacienteNuevo(contactos);
						cout<<endl;
						break;

					default:
						cout<<"Opción incorrecta!"<<endl;
					}

					if(opc2==1)
					{
						encon=1;
						pos=buscar(paciente,contactos);
						anadirCitaPaciente(contactos,paciente,pos);
					}
				}
				else
				{
					encon=1;
					anadirCitaPaciente(contactos,paciente,pos);
				}
			}while(encon!=1);
			cout<<endl<<"Cita añadida con éxito!";
			cout<<endl<<endl<<"Pulse enter para volver al menú."<<endl<<endl;
			getchar();
			getchar();
			break;

		//MODIFICAR LOS DATOS DE UN PACIENTE
		//COMPRUEBA QUE EL PACIENTE EXISTE
		case 4:
			cout<<endl;
			do
			{
				cout<<"Introduzca el dni del paciente que desea modificar: ";
				cin >> paciente;
				pos=buscar(paciente,contactos);

				if(pos==-1)
				{
					cout<<"El paciente introducido no se encuentra en el sistema."<<endl;

				}
				else
				{
					modificarDatosPaciente(contactos,pos);
				}
			}while(pos==-1);

			cout<<endl<<"Paciente modificado con éxito!";

			cout<<endl<<endl<<"Pulse enter para volver al menú."<<endl<<endl;
			getchar();
			getchar();
			break;

		//BORRA UN PACIENTE INTRODUCIDO POR EL USUARIO
		//SI EL USUARIO NO EXISTE EL PROGRAMA LO INDICA
		case 5:
			cout<<endl;
			do
			{
				cout<<"Introduzca el dni del paciente que desea borrar: ";
				cin >> paciente;
				pos=buscar(paciente,contactos);

				if(pos==-1)
				{
					cout<<"El paciente introducido no se encuentra en el sistema."<<endl;

				}
				else
				{
					borrarPaciente(contactos,pos);
				}
			}while(pos==-1);

			cout<<endl<<"Paciente modificado con éxito!";
			cout<<endl<<endl<<"Pulse enter para volver al menú."<<endl<<endl;
			getchar();
			getchar();
			break;

		//BUSCAR UN PACIENTE INTRODUCIDO POR EL USUARIO
		//LA FUNCION BUSCAR DEVULVE LA POSICION DEL PACIENTE SI LO ENCUENTRA (PARA USARLO EN OTRAS FUNCIONES DEL PROGRAMA)
		case 6:
			cout<<endl;
			cout<<"Introduzca el dni del paciente que desea buscar: ";
			cin >> paciente;
			pos=buscar(paciente,contactos);
			if(pos!=-1)
			{
				cout<<"El paciente introducido se encuentra en el sistema."<<endl;
			}
			else
				cout<<"El paciente introducido no se encuentra en el sistema."<<endl;

			cout<<endl<<endl<<"Pulse enter para volver al menú."<<endl<<endl;
			getchar();
			getchar();
			break;

		//ACTUALIZA LA BASE DE DATOS
		case 9:
			cout<<endl;
			cout<<"REALIZANDO COPIA DE SEGURIDAD..."<<endl;
			cout<<endl;
			realizarCopiaDeSeguridad(contactos);
			cout<<"COPIA DE SEGURDAD REALIZADA CON ÉXITO!"<<endl;
			cout<<endl<<endl<<"Pulse enter para volver al menú."<<endl<<endl;
			getchar();
			getchar();
			break;

		default:
			cout<<"Opción incorrecta! Intentelo de nuevo\n";
			break;
		}
	}while(opc!=0);

	return 0;
}
