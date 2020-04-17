#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED



#endif // CALCULADORA_H_INCLUDED

/** \brief Nos permite visualizar el menu con las opciones
 *
 * \return Devuelve un valor que hace refencia a la opcion elegida en el menu
 *
 */

int menu();

/** \brief Nos permite visualizar el menu con las opciones con un valor cargado
 *
 * \param Es uno de los valores cargados para realizar las operaciones
 * \return Devuelve un valor que hace refencia a la opcion elegida en el menu
 *
 */

int menu_1(int num1);

/** \brief Nos permite visualizar el menu con las opciones con los dos valores cargados
 *
 * \param num1 es uno de los valores cargados para realizar las operaciones
 * \param num2 es uno de los valores cargados para realizar las operaciones
 * \return Devuelve un valor que hace refencia a la opcion elegida en el menu
 *
 */

int menu_2(int num1, int num2);

/** \brief Nos va a mostrar los resultados de las operaciones
 *
 * \param num1 es uno de los valores con los que se realizo las operaciones
 * \param num2 es uno de los valores con los que se realizo las operaciones
  *
 */

void resultados (int num1, int num2);

/** \brief Va a realizar la suma de dos numeros enteros
 *
 * \param num1 es una variable entera a sumar
 * \param num2 es otra varable entera a sumar
 * \return devuelve el valor de la suma
 *
 */

int sumar(int num1, int num2);

/** \brief Va a realizar la suma de dos numeros enteros
 *
 * \param num1 es una variable entera a restar
 * \param num2 es otra varable entera a restar
 * \return devuelve el valor de la resta
 *
 */

int restar(int num1, int num2);

/** \brief Va a realizar la division de dos numeros enteros
 *
 * \param num1 es una variable entera a dividir
 * \param num2 es otra varable entera a dividir
 * \return devuelve el valor de la division
 *
 */

float dividir(float num1, float num2);

/** \brief Va a realizar la suma de dos numeros enteros
 *
 * \param num1 es una variable entera a multiplicar
 * \param num2 es otra varable entera a multiplicar
 * \return devuelve el valor de la multiplicacion
 *
 */

int multiplicar(int num1, int num2);

/** \brief Realixa el factorial de una variable entera
 *
 * \param num1 es una variable entera a la que realiziremos el factorial
 * \return devuelve el valor del factorial
 *
 */

int factorial_1(int num1);

/** \brief Realixa el factorial de una variable entera
 *
 * \param num2 es una variable entera a la que realiziremos el factorial
 * \return devuelve el valor del factorial
 *
 */

int factorial_2(int num2);
