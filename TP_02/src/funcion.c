/*
 ============================================================================
 Name        : tp_02.c
 Author      : Correa Leandro - 1H
 Version     :
 Copyright   :
 Description : tp 02
 ============================================================================
 */

#include "funcion.h"

/*
brief: Inicializa un contador y lo suma cuando se retorna la función
return: Int incrementado en uno
 */
static int getNuevoId(void)
{
	static int counter = 0;

	return(counter++);
}

/*
brief: Inicializa el menú de la aplicación
 */
void initMenu(void)
{

	int contUsers = 0;
	int option;

	static int nuevoId;
	static char newName[51];
	static char newLastName[51];
	static float newPrice;
	static int newTypePassenger;

	int idFounded;
	int order;

	Passenger passenger[PASSENGER];

	initPassenger(passenger, PASSENGER);

	do
	{
		puts("*********************************");
		puts("         BIENBIENDO           ");
		puts("---------------------------------");
		puts("1. Dar de alta pasajero");
		puts("2. Modificar pasajero");
		puts("3. Dar de baja pasajero");
		puts("4. Informar pasajero");
		puts("5. Salir");
		puts("*********************************");

		fflush(stdin);
		ingresoIntMinMax(&option,"", "Error, ingrese un numero valido: " , 1, 5);

		switch(option)
		{
		case 1:
			system("cls");
			if(contUsers < PASSENGER)
			{
				nuevoId = getNuevoId();
				ingresoCadena(newName, 51, "Ingrese el nombre el pasajero: ", "Error. Ingrese nuevamente: ");
				ingresoCadena(newLastName, 51, "Ingrese el apellido el pasajero: ", "Error. Ingrese nuevamente: ");
				ingresoIntMinMax(&newTypePassenger, "Ingrese el tipo de vuelo: \n 1. Clase Baja \n 2. Clase Media \n 3. Clase Alta \n", "Error. Ingrese un valor válido", 1, 3);
				newPrice = ingresoFloat("Ingrese el precio del vuelo: ", "Error. Ingrese un número válido: ");
				while(newPrice < 0)
				{
					newPrice = ingresoFloat("Ingrese un valor positivo: ", "Error. Ingrese un número válido: ");
				}

				if(addPassenger(passenger, PASSENGER, nuevoId, newName, newLastName, newPrice, newTypePassenger) == FALSE)
				{
					puts("*********************************");
					puts("Error. ¡Algo salió mal!");
					puts("*********************************");
				}
				else
				{
					contUsers++;
					puts("*********************************");
					puts("¡Pasajero creado con éxito!");
					puts("*********************************");
				}
			}
			else
			{
				puts("*********************************");
				puts("Error. ¡Límite de pasajeros alcanzado!");
				puts("*********************************");
			}
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");
			if(contUsers > 0)
			{
				if(printPassenger(passenger, PASSENGER) != FALSE)
				{
					idFounded = ingresoInt("Ingrese el número de ID del pasajero a modificar: ", "Error. Ingrese un número valido: ");
					if(findPassengerById(passenger, PASSENGER, idFounded) != FALSE)
					{
						if(modifyPassenger(passenger, PASSENGER, idFounded) != FALSE)
						{
							puts("*********************************");
							puts("¡Pasajero modificado con éxito!");
							puts("*********************************");
						}
						else
						{
							puts("*********************************");
							puts("Error. ¡Algo salió mal!");
							puts("*********************************");
						}
					}
					else
					{
						puts("*********************************");
						puts("Error. ¡Pasajero no encontrado!");
						puts("*********************************");
					}
				}
			}
			else
			{
				puts("*********************************");
				puts("Error. ¡No existen pasajeros. Debe existir al menos un pasajero para usar esta opción!");
				puts("*********************************");
			}
			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			if(contUsers > 0)
			{
				if(printPassenger(passenger, PASSENGER) != FALSE)
				{

					idFounded = ingresoInt("Ingrese el número de ID del pasajero a eliminar: ", "Error. Ingrese un número valido: ");
					if(findPassengerById(passenger, PASSENGER, idFounded) != FALSE)
					{
						if(removePassenger(passenger, PASSENGER, idFounded) != FALSE)
						{
							contUsers--;
							puts("*********************************");
							puts("1¡Pasajero eliminado con éxito!");
							puts("*********************************");
						}
						else
						{
							puts("*********************************");
							puts("Error. ¡Algo salió mal!");
							puts("*********************************");
						}
					}
					else
					{
						puts("*********************************");
						puts("Error. ¡Pasajero no encontrado!");
						puts("*********************************");
					}
				}
			}
			else
			{
				puts("*********************************");
				puts("Error. ¡No existen pasajeros. Debe existir al menos un pasajero para usar esta opción!");
				puts("*********************************");
			}
			system("pause");
			system("cls");
			break;

		case 4:
			system("cls");
			if(contUsers > 0)
			{
				puts("*********************************");
				puts("Ingrese el orden en el que quieres ordenar los usuarios");
				puts("1. Ascendente");
				puts("2. Descendente");
				puts("*********************************");
				ingresoIntMinMax(&order, "", "Error. Ingrese un número válido: ", 1, 2);

				if(sortPassenger(passenger, PASSENGER, order) != FALSE)
				{
					if(printPassenger(passenger, PASSENGER) == FALSE)
					{
						puts("*********************************");
						puts("Error. ¡Algo salió mal!");
						puts("*********************************");
					}
					else
					{
						puts("¡Muchas grácias!");
						puts("*********************************");
					}

					if(promedioPassenger(passenger, PASSENGER) == FALSE)
					{
						puts("*********************************");
						puts("Error. ¡Algo salió mal!");
						puts("*********************************");
					}
					else
					{
						puts("¡Fin de la impresión!");
						puts("---------------------------------\n");
					}
				}
				else
				{
					puts("*********************************");
					puts("Error. ¡Algo salió mal!");
					puts("*********************************");
				}
			}
			else
			{
				puts("*********************************");
				puts("Error. ¡No existen pasajeros. Debe existir al menos un pasajero para usar esta opción!");
				puts("*********************************");
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			puts("*********************************");
			puts("¡Aplicación cerrada con éxito!");
			puts("*********************************");
			break;
		}

	}while(option != 5);
}
