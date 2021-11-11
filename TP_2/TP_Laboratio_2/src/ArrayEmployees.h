/*
 * ArrayEmployees.h
 *
 *  Created on: 1 nov. 2021
 *      Author: MartinGonzalez
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "Biblioteca.h"
#define FALSE 0
#define TRUE 1

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;

}Employee;



/** \brief Para indicar que todas las posiciones del array están vacías,
 * esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
 * \param list Employee* Puntero al array de empleados
 * \param len int longitud del array
 * \return int Retorna (-1) si hubo error [Longitud invalida o Puntero a NULL] - (0) si salio Ok
 *
 */
int initEmployees(Employee* list, int len);


/// Busca un lugar libre en una lista dada
///
/// @param list Employee* Puntero al array de empleados
/// @param len int longitud del array
/// @return int retorna el indice libre
int BuscarEmployeeLibre(Employee* list, int len);

/// Busca un ID y devuelve el siguiente de este.
///
/// @param list Employee* Puntero al array de empleados
/// @param len int longitud del array
/// @return int retorna el ID siguiente
int SiguienteId(Employee* list, int len);

/// Pide al usuario los datos del empleado
///
/// @param list Employee* Puntero al array de empleados
/// @param len int longitud del array
/// @return int Retorna (-1) si hubo error - (0) si salio Ok
int CargarEmployee(Employee* list, int len);




/** \brief Agrega en un array de empleados existente los valores recibidos
 *como parámetro en la primerposición libre.
 * \param list Employee* Puntero al array de empleados
 * \param len int longitud del array
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/// Muestra un solo cliente por pantalla
///
/// @param unEmployee el empleado que vamos a mostrar
void MostrarUnEmployee(Employee unEmployee);

/** \brief Imprime el array de empleados de forma encolumnada.
 *
 * \param list Employee* Puntero al array de empleados
 * \param len int longitud del array
 * \return int
 *
 */
int printEmployees(Employee* list, int len);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 *\param list Employee* Puntero al array de empleados
 * \param len int longitud del array
 * \param id int id del empleado a buscar
 * \return Return retorna el la posición del empleado o (-1) si [la longitud es invalida
o puntero a NULL o No encontramos al empleado]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 *
 *\param list Employee* Puntero al array de empleados
 * \param len int longitud del array
 * \param id int id del empleado a buscar
 * \return int retorna (-1) si hubo un error [la longitud es invalida
o puntero a NULL o No encontramos al empleado] - (0) si todo esta OK
 *
 */
int removeEmployee(Employee* list, int len);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente
 *
 *\param list Employee* Puntero al array de empleados
 * \param len int longitud del array
 * \param order int [1] ascendente - [0] descendente
 * \return int Return (-1) si hubo un error [la longitud es invalidao puntero a NULL] - (0) si salio todo OK
 *
 */
int sortEmployees(Employee* list, int len, int order);


/// Pide ID al usuario y pregunta que desea modificar del Empleado de la lista si su ID es igual al ingresado.
///
/// @param list Employee* Puntero al array de empleados
/// @param len int longitud del array
/// @return retorna -1 si hubo un error, 0 si el cliente se modificó correctamente
int ModificarEmployee(Employee* list, int len);


/// Suma todos los salarios y devuelve la suma total
///
/// @param list Employee* Puntero al array de empleados
/// @param len int longitud del array
/// @return float retorna la suma total de salarios
float SumarSalarios(Employee* list, int len);

/// Calcula el promedio de todos los salarios
///
/// @param list Employee* Puntero al array de empleados
/// @param len int longitud del array
/// @return float retorna el promedio de los salarios
float PromedioSalarios(Employee* list, int len);

/// Devuelve la cantidad de salarios que superan el promedio
///
/// @param list Employee* Puntero al array de empleados
/// @param len int longitud del array
/// @return int retorna la cantidad de salarios que superan el promedio
int CantidadSalariosSuperandoPromedio(Employee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
