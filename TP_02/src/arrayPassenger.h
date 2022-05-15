/*
 ============================================================================
 Name        : tp_02.c
 Author      : Correa Leandro - 1H
 Version     :
 Copyright   :
 Description : tp 02
 ============================================================================
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "out.h"

#define TRUE 0
#define FALSE -1
#define PASSENGER 2000

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int isEmpty;
}

Passenger;

/*
brief: Recorre el array y establece todas las posiciones como isEmpty == TRUE (Libre)
param: Struct -> Passenger* list || Lista de pasajeros
param: Int len || Longitud de la lista
return: 0 TRUE || -1 FALSE
 */
int initPassenger(Passenger* list, int len);

/*
brief: Recibe los parametros y crea un nuevo Pasajero
param: Struct -> Passenger* list || Lista de pasajeros
param: Int len || Longitud de la lista
param: Int id || ID del usuario
param: Char name[] || Nombre del usuario
param: Char lastName[] || Apellido del usuario
param: Float price || Salario del usuario
param: Int typePassanger || TypePassanger del usuario
return: 0 TRUE || -1 FALSE
 */
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassanger);

/*
brief: Recorre el array y busca la posición donde conincida el id a buscar con el id del usuario
param: Struct -> Passenger* list || Lista de pasajeros
param: Int len || Longitud de la lista
param: Int id || ID del usuario a buscar
return: -1 FALSE || Posición del pasajero dentro del array
 */
int findPassengerById(Passenger* list, int len, int id);

/*
brief: Recorre el array y busca la posición donde conincida el id a buscar con el id del usuario para modificarlo
param: Struct -> Passenger* list || Lista de pasajeros
param: Int len || Longitud de la lista
param: Int id || ID del usuario a modicar
return: -1 FALSE || 0 TRUE
 */
int modifyPassenger(Passenger* list, int len, int id);

/*
brief: Recorre el array y busca la posición donde conincida el id a buscar con el id del usuario para eliminarlo
param: Struct -> Passenger* list || Lista de pasajeros
param: Int len || Longitud de la lista
param: Int id || ID del usuario a eliminar
return: -1 FALSE || 0 TRUE
 */
int removePassenger(Passenger* list, int len, int id);

/*
brief: Recorre el array y lo ordena alfabeticamente
param: Struct -> Passenger* list || Lista de pasajeros
param: Int len || Longitud de la lista
param: Int orden || Orden ascendente o descendente
return: -1 FALSE || 0 TRUE
 */
int sortPassenger(Passenger* list, int len, int orden);

/*
brief: Recorre el array e imprime aquellos usuarios donde isEmpty == FALSE
param: Struct -> Passenger* list || Lista de pasajeros
param: Int len || Longitud de la lista
return: -1 FALSE || 0 TRUE
 */
int printPassenger(Passenger* list, int len);

/*
brief: Recorre el array, acumula los salarios y cuenta los empleados disponibles. Además cuenta cuenta cuantos usuarios pasan el salario promedio y los imprime
param: Struct -> Passenger* list || Lista de pasajeros
param: Int len || Longitud de la lista
return: -1 FALSE || 0 TRUE
 */
int promedioPassenger(Passenger* list, int len);

#endif /* ARRAYPASSENGER_H_ */
