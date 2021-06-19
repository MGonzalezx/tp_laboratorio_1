/*
 * Biblioteca.h
 *
 *  Created on: 10 jun. 2021
 *      Author: MartinGonzalez
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int pedirEntero(int* pEntero, char mensaje[], char mensajeError[], int minimo, int maximo);

int pedirStringDeNumerosPositivo(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

int pedirStringSoloLetras(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

int comprobarStringNumericoPositivo(char cadenaNumerica[], int tamanio);

int comprobarArrayNumericaEntero(char cadenaNumerica[], int tamanio);

int comprobarStringSoloLetras(char stringLetras[], int tamanio);

char pedirRespuestaSN(char mensaje[]);


#endif /* BIBLIOTECA_H_ */
