#include "funciones.hpp"

int main()
{
	int opc;

	do
	{
		opc=menu();

		switch(opc)
		{
		case 0:
			cout<<"APAGANDO SISTEMA...\n";
			break;

		case 1:
			cout<<"HOLA"<<endl;
			listarContactos();
			break;

		default:
			cout<<"Opción incorrecta! Intentelo de nuevo\n";
			break;
		}
	}while(opc!=0);

	return 0;
}
