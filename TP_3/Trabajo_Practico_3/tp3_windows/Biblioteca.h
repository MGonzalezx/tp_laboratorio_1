/*
 * Biblioteca.h
 *
 *  Created on: 3 nov. 2021
 *      Author: RocioGonzalez
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int PedirEntero(int* pEntero, char mensaje[], char mensajeError[], int minimo, int maximo);

int ComprobarArrayNumericaEntero(char cadenaNumerica[], int tamanio);

int PedirFlotante(float* pNumero, char mensaje[], char mensajeError[], float minimo, float maximo);

int ComprobarStringNumeroFlotante(char cadenaNumerica[], int tamanio);

int PedirStringDeNumerosPositivo(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

int PedirStringCaracteresAlfabeticos(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

int PedirStringCaracteresAlfabeticosEspaciados(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

int PedirAlfanumericaConEspacio(char arrayAlfanumerica[], int tamanio, char mensaje[], char mensajeError[]);

int ComprobarStringNumericoPositivo(char cadenaNumerica[], int tamanio);

int ComprobarStringCaracteresAlfabeticos(char stringLetras[], int tamanio);

int ComprobarStringCaracteresAlfabeticosEspaciados(char stringLetras[], int tamanio);

char PedirRespuestaSN(char mensaje[]);

#endif /* BIBLIOTECA_H_ */
