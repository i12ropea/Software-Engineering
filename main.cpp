#include "funciones.hpp"

int main()
{
	int opc,opc2,pos,encon;
	int paciente;
	vector <Contacto> contactos=cargarContactosBaseDatos();

	do
	{
		opc=menu();

		switch(opc)
		{
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
						introducirPacienteNuevo(contactos);
						cout<<endl;
						break;

					default:
						cout<<"Opción incorrecta!"<<endl;
					}

					if(opc2==1)
					{
						encon=1;
						anadirCitaPaciente(contactos,paciente,pos);
					}
				}
				else
				{
					opc2=0;
					encon=1;
					anadirCitaPaciente(contactos,paciente,pos);
				}
			}while(opc2!=0 or encon!=1);
			cout<<endl<<"Cita añadida con éxito!";
			cout<<endl<<endl<<"Pulse enter para volver al menú."<<endl<<endl;
			getchar();
			getchar();
			break;

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
