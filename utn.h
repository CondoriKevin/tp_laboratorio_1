#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/**
    utn_menu: Muestra un menu de opciones y utiliza el getEntero para seleccionar una
    @param numero1: guarda el numero 1 ingresado
    @param numero2: guarda el numero 2 ingresado
    @return : retorna la opcion del menu que seleccionada
*/
int utn_menu(float numero1,float numero2);
/**
    utn_getNumeroDecimal: pide un numero con coma y utiliza a getFloat para validarlo
    @param pNum: puntero a numero
    @param reint: cantidad de reintentos al fallar
    @param msg: mensaje a mostrar
    @param msgError: mensaje de error
    @return return 0 OK, -1 error.
*/
int utn_getNumeroDecimal(float* pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
/**
    utn_getEntero: pide un numero entero y utiliza getInt para validarlo
    @param pNum: puntero a numero
    @param reint: cantidad de reintentos
    @param msg: mensaje a mostrar
    @param msgError: mensaje de error
    @param maximo: el numero maximo
    @param minimo: el numero minimo
    @return return 0 OK, -1 error.
*/
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
/**
    utn_suma: realiza una suma entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la suma del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int utn_suma(float *pResultado,float numero1, float numero2);
/**
    utn_resta: realiza una resta entre 2 numeros flotantes
    @param numero1: guarda el numero 1 ingresado
    @param numero2: guarda el numero 2 ingresado
    @param *pResultado: guarda la resta del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int utn_resta(float *pResultado,float numero1, float numero2);
/**
    utn_multiplicacion: realiza una multiplicacion entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la multiplicacion del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int utn_multiplicacion(float *pResultado,float numero1, float numero2);
/**
    utn_division: realiza una division entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la division del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int utn_division(float *pResultado,float numero1, float numero2);
/**
    utn_factoreo: realiza el factoreo de un numero utilizando un for para ir multiplicandolo
    @param numero: guarda el numero recibido
    @return return devuelve la respuesta del numero factoreado
*/
int utn_factoreo(float  numero);
/**
    utn_texto: recibe una variable para mostrar y un mensaje
    @param resultado: numero con coma
    @param mensaje: que se debe mostrar con printf
*/
void utn_texto(float resultado, char* msg);
/**
    utn_getNombre:recibe una cadera de caracteres con un mensaje y un mensaje de error para pedirle al usuario que ingrese un nombre
    @param *pNombre: guarda el Array o cadena de caracteres recibida
    @param msg: mensaje a mostrar antes de ingresar el nombre
    @param msgError: mensaje a mostrar si se ingresa un dato no deseado
*/
int utn_getNombre(char* pNombre,char* msg,char* msgError);


#endif // UTN_H_INCLUDED
