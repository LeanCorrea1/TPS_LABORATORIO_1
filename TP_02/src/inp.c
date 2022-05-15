/*
 ============================================================================
 Name        : tp_02.c
 Author      : Correa Leandro - 1H
 Version     :
 Copyright   :
 Description : tp 02
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "out.h"
#define TRUE 1
#define FALSE 0
#define BUFFER_LEN 1000

static int myGets(char* pIngreso, int len)
{
	int status= FALSE;
	int indexFinal;

	if(fgets(pIngreso,len,stdin) != NULL)
	{
		indexFinal = strlen(pIngreso)-1;

		if(pIngreso[indexFinal] == '\n')
		{
			pIngreso[indexFinal] = '\0';
		}

		status = TRUE;
	}

	return status;
}

// VALIDACIONES
int validarEntero(char* pIngreso)
{
	int status = TRUE;

	if(strlen(pIngreso) > 0)
	{
		for(int i = 0;i< strlen(pIngreso);i++)
		{
			if(isdigit(pIngreso[i]) == FALSE)
			{
				if(i == 0)
				{
					if(pIngreso[0] != '-')
					{
						status = FALSE;
						break;
					}
				}
				else
				{
					status = 0;
				}
			}
		}
	}
	else
	{
		status = FALSE;
	}

	return status;
}
int validarFlotante(char* pIngreso)
{
	int sign = 0;
	int digits = 0;
	int status = TRUE;

	if(strlen(pIngreso) > 0)
	{
		for(int i = 0;i < strlen(pIngreso); i++)
		{
			if(pIngreso[i] == '.' || pIngreso[i] == ',')
			{
				sign++;
			}
			else
			{
				if(isdigit(pIngreso[i]) == 0)
				{
					if(i == 0)
					{
						if(pIngreso[0] != '-')
						{
							status = FALSE;
							break;
						}
					}
					else
					{
						status = FALSE;
						break;
					}
				}
			}
			if(isdigit(pIngreso[i]) == 1)
			{
				digits++;
			}
		}

		if(sign > 1 || digits == 0)
		{
			status = FALSE;
		}

	}
	else
	{
		status = FALSE;
	}

	return status;
}
int validarCaracter(char ingreso)
{
	int status = TRUE;

	if(isalpha(ingreso) == FALSE)
	{
		status = FALSE;
	}

	return status;
}
int validarCadena(char ingreso[])
{
	int status = TRUE;

	if(strlen(ingreso) > 0)
	{
		for(int i = 0;i<strlen(ingreso);i++)
		{
			if(isalpha(ingreso[i] == 0))
			{
				status = FALSE;
				break;
			}
		}
	}
	else
	{
		status = FALSE;
	}

	return status;
}

// INGRESOS SIN REINTENTOS
int ingresoInt(char* message, char* errorText)
{
	char buffer[BUFFER_LEN];
	int status;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarEntero(buffer) == FALSE)
		{
			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
		}

		status = atoi(buffer);
	}

	return status;
}
float ingresoFloat(char* message, char* errorText)
{
	char buffer[BUFFER_LEN];
	float status;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarFlotante(buffer) == FALSE)
		{
			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
		}

		status = atof(buffer);
	}

	return status;
}
char ingresoChar(char* message, char* errorText)
{
	char buffer;
	char status;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);
		buffer = getchar();

		while(validarCaracter(buffer) == FALSE)
		{
			printf("%s",errorText);
			fflush(stdin);
			buffer = getchar();
		}

		status = buffer;
	}

	return status;
}
int ingresoCadena(char pIngreso[],int len, char* message, char* errorText)
{
	int status = TRUE;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);

		while(myGets(pIngreso, len) == FALSE)
		{
			printf("%s", errorText);
			fflush(stdin);
		}
	}

	return status;
}


// INGRESOS CON REINTENTOS
int ingresoIntRetry(int* pIngreso, char* message, char* errorText, int retry)
{
	char buffer[BUFFER_LEN];
	int status = FALSE;

	if(pIngreso != NULL && message != NULL && errorText != NULL && retry > 0)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarEntero(buffer) == FALSE)
		{
			if(retry == 0)
			{
				puts("*********************************");
				printf("Se acabaron los intentos. Reinicie el programa");
				status = FALSE;
				break;
			}

			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
			retry--;

		}

		*pIngreso = atoi(buffer);
		status = TRUE;
	}

	return status;
}
int ingresoFloatRetry(float* pIngreso, char* message, char* errorText, int retry)
{
	char buffer[BUFFER_LEN];
	int status = FALSE;

	if(pIngreso != NULL && message != NULL && errorText != NULL && retry > 0)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarFlotante(buffer) == FALSE)
		{
			if(retry == 0)
			{
				puts("*********************************");
				printf("Se acabaron los intentos. Reinicie el programa");
				status = FALSE;
				break;
			}

			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
			retry--;
		}

		*pIngreso = atof(buffer);
		status = TRUE;
	}

	return status;
}
int ingresoCharRetry(char* pIngreso, char* message, char* errorText,int retry)
{
	char buffer;
	char status = TRUE;

	if(message != NULL && errorText != NULL && retry > 0)
	{
		printf("%s",message);
		fflush(stdin);
		buffer = getchar();

		while(validarCaracter(buffer) == FALSE)
		{
			if(retry == 0)
			{
				puts("*********************************");
				printf("Se acabaron los intentos. Reinicie el programa");
				status = FALSE;
				break;
			}

			printf("%s",errorText);
			fflush(stdin);
			buffer = getchar();
			retry--;
		}

		*pIngreso = buffer;
	}

	return status;
}
int ingresoTextoRetry(char pIngreso[],int len, char* message, char* errorText, int retry)
{
	int status = TRUE;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);

		while(myGets(pIngreso,len) == FALSE)
		{
			if(retry == 0)
			{
				status = FALSE;
				break;
			}

			printf("%s", errorText);
			fflush(stdin);
			retry--;
		}

	}

	return status;
}

// INGRESOS CON MIN Y MAX
int ingresoIntMinMax(int* pIngreso, char* message, char* errorText, int min, int max)
{
	char buffer[BUFFER_LEN];
	int status = FALSE;

	if(pIngreso != NULL && message != NULL && errorText != NULL && min < max)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarEntero(buffer) == FALSE || atoi(buffer) > max || atoi(buffer) < min)
		{
			printf("%s", errorText);
			fflush(stdin);
			gets(buffer);
		}

		*pIngreso = atoi(buffer);
		status = TRUE;
	}

	return status;
}
int ingresoFloatMinMax(float* pIngreso, char* message, char* errorText, float min, float max)
{
	char buffer[BUFFER_LEN];
	int status = FALSE;

	if(pIngreso != NULL && message != NULL && errorText != NULL && min < max)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);
		while(validarFlotante(buffer) == FALSE || atof(buffer) > max || atof(buffer) < min)
		{
			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
		}

		*pIngreso = atof(buffer);
		status = TRUE;
	}

	return status;
}
