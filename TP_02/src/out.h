/*
 ============================================================================
 Name        : tp_02.c
 Author      : Correa Leandro - 1H
 Version     :
 Copyright   :
 Description : tp 02
 ============================================================================
 */

#ifndef OUT_H_
#define OUT_H_

// VALIDACIONES
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es un numero entero
param: se pide un tipo char para validar si es un numero entero
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarEntero(char *pIngreso);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es un numero flotante (Si es entero, no avisa)
param: se pide un tipo char para validar si es un numero flotante
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarFlotante(char *pIngreso);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un char ingresado anteriormente para validar sí es un tipo caracter realmente
param: se pide un tipo char para validar si es un caracter
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarCaracter(char ingreso);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es alfabética
param: se pide un tipo char para validar si es un array de caracteres alfabéticos
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarCadena(char *pIngreso);
/*--------------------------------*/


// INGRESOS SIN REINTENTOS
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres referente al mensaje y otra al mensaje de error
param: La función pide un char, se valida sí es un INT o no. En caso de que no, se vuelve a pedir y sino se retorna el status
return: int que refiere al numero ingresado
/////////////////////////////////////////////////////////////////////
*/
int ingresoInt(char* message, char* errorText);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres referente al mensaje y otra al mensaje de error
param: La función pide un char, se valida sí es un FLOAT o no. En caso de que no, se vuelve a pedir y sino se retorna el status
return: float que refiere al numero ingresado
/////////////////////////////////////////////////////////////////////
*/
float ingresoFloat(char* message, char* errorText);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres referente al mensaje y otra al mensaje de error
param: La función pide un char, se valida sí es un CHAR o no. En caso de que no, se vuelve a pedir y sino se retorna el status
return: char que refiere al caracter ingresado
/////////////////////////////////////////////////////////////////////
*/
char ingresoChar(char* message, char* errorText);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos la cadena de texto, la longitud de la cadena ,una cadena de caracteres referente al mensaje y otra al mensaje de error
param: La función pide una cadena de texto, se valida sí es una cadena o no. En caso de que no, se vuelve a pedir y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoCadena(char pIngreso[],int len, char* message, char* errorText);
/*--------------------------------*/


// INGRESOS CON REINTENTOS
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos el entero, una cadena de caracteres referente al mensaje y otra al mensaje de error, un int de cantidad de intentos
param: La función pide un entero, se valida sí es un entero o no. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoIntRetry(int* pIngreso, char* message, char* errorText, int retry);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos el float, una cadena de caracteres referente al mensaje y otra al mensaje de error, un int de cantidad de intentos
param: La función pide un flotante, se valida sí es un flotante o no. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoFloatRetry(float* pIngreso, char* message, char* errorText, int retry);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos el char, una cadena de caracteres referente al mensaje y otra al mensaje de error, un int de cantidad de intentos
param: La función pide un caracter, se valida sí es un char o no. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoCharRetry(char* pIngreso, char* message, char* errorText,int retry);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos una cadena de texto, el tamaño de la cadena, una cadena de caracteres referente al mensaje y otra al mensaje de error, un int de cantidad de intentos
param: La función pide una cadena de texto, se valida sí es una cadena o no. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoTextoRetry(char pIngreso[],int len, char* message, char* errorText, int retry);

// INGRESOS CON MIN Y MAX
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un entero, una cadena de caracteres referente al mensaje y otra al mensaje de error,minimo y maximo, un int de cantidad de intentos
param: La función pide un int, se valida sí es un entero o no y si esta dentro de los parametros min y max. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoIntMinMax(int* pIngreso, char* message, char* errorText, int min, int max);
/*--------------------------------*/
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un flotante, una cadena de caracteres referente al mensaje y otra al mensaje de error,minimo y maximo, un int de cantidad de intentos
param: La función pide un int, se valida sí es un flotante o no y si esta dentro de los parametros min y max. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoFloatMinMax(float* pIngreso, char* message, char* errorText, float min, float max);
/*--------------------------------*/

#endif /* UTN_OPS_H_ */
