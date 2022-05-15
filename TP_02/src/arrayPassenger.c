/*
 ============================================================================
 Name        : tp_02.c
 Author      : Correa Leandro - 1H
 Version     :
 Copyright   :
 Description : tp 02
 ============================================================================
 */

#include "arrayPassenger.h"

int initPassenger(Passenger* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		status = TRUE;

		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
	}

	return status;
}
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && price >= 0 && typePassenger > 0 && typePassenger < 6)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				list[i].isEmpty = FALSE;
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				status = TRUE;
				break;
			}
		}
	}

	return status;
}
int findPassengerById(Passenger* list, int len, int id)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				status = i;
			}
		}
	}

	return status;
}
int modifyPassenger(Passenger* list, int len, int id)
{
	int status = FALSE;
	int option;
	int idModify;

	if(list != NULL && len > 0 && id != FALSE)
	{

		idModify = findPassengerById(list, len, id);

		puts("*********************************");
		puts("¿Que deseas modificar?");
		puts("1. Nombre del pasajero");
		puts("2. Apellido del pasajero");
		puts("3. Tipo de vuelo");
		puts("4. Precio de vuelo");
		puts("*********************************");
		ingresoIntMinMax(&option, "", "Error. Ingrese valor valido: ", 1, 4);

		if(idModify != FALSE)
		{
			switch(option)
			{
			case 1:
				system("cls");
				ingresoCadena(list[idModify].name, 51, "Ingrese el nuevo nombre: ", "Error. Intente nuevamente: ");
				system("cls");
				system("pause");
				break;
			case 2:
				system("cls");
				ingresoCadena(list[idModify].lastName, 51, "Ingrese el nuevo apellido: ", "Error. Intente nuevamente: ");
				system("cls");
				system("pause");
				break;
			case 3:
				system("cls");
				ingresoIntMinMax(&list[idModify].typePassenger, "Ingrese el nuevo tipo de vuelo: ", "Error. Ingrese un tipo válido: ", 1, 3);
				system("cls");
				system("pause");
				break;
			case 4:
				system("cls");
				list[idModify].price = ingresoFloat("Ingrese el nuevo precio: ", "Error. Intente nuevamente: ");
				while(list[idModify].price < 0)
				{
					list[idModify].price = ingresoFloat("El precio no puede ser negativo. Ingrese nuevamente: ", "Error. Intente nuevamente: ");
				}
				system("cls");
				system("pause");
				break;
			}
			status = TRUE;
		}
	}

	return status;
}
int removePassenger(Passenger* list, int len, int id)
{
	int status = FALSE;
	int idModify;

	if(list != NULL && len > 0 && id != FALSE)
	{
		idModify = findPassengerById(list, len, id);

		if(idModify != FALSE)
		{
			list[idModify].isEmpty = TRUE;
			status = TRUE;
		}
	}

	return status;
}
int sortPassenger(Passenger* list, int len, int orden)
{
	int status = FALSE;
	int i;
	int j;
	Passenger* listAux;

	printf("\n\nOrden establecido: %d\n\n", orden);
	system("cls");

	if(list != NULL && len > 0)
	{
		status = TRUE;
		if(orden == 1)
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName) > 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
					{
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								*listAux=list[i];
								list[i]=list[j];
								list[j]=*listAux;
							}
						}
					}
				}
			}
		}
		else
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName) < 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
					{
						printf("\n\nValidación 1\n\n");
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
						{
							printf("\n\nValidación 2\n\n");
							if(list[i].typePassenger > list[j].typePassenger)
							{
								printf("\n\nValidación 3\n\n");
								*listAux=list[i];
								list[i]=list[j];
								list[j]=*listAux;
							}
						}
					}
				}
			}
		}
	}

	return status;
}
int printPassenger(Passenger* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		status = TRUE;
		puts("*********************************");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("ID: %d || %s, %s || Tipo de vuelo: %d || Precio de vuelo: %2.f \n ", list[i].id, list[i].lastName, list[i].name,list[i].typePassenger, list[i].price);
			}
		}
		puts("*********************************");
	}

	return status;
}
int promedioPassenger(Passenger* list, int len)
{
	int status = FALSE;
	int i;
	float acum = 0;
	int cont = 0;
	float prom;
	int contProm = 0;

	if(list != NULL && len > 0)
	{
		status = TRUE;
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acum += list[i].price;
				cont++;
			}
		}

		prom = acum / cont;

		puts("*********************************");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price > prom)
			{
				printf("ID: %d || %s, %s || Tipo de vuelo: %d || Precio de vuelo: %2.f \n ", list[i].id, list[i].lastName, list[i].name,list[i].typePassenger, list[i].price);
				contProm++;
			}
		}
		puts("*********************************");
		printf("Cantidad de vuelos con un precio superior al promedio: %d\n", contProm);
		puts("*********************************");

	}

	return status;
}
