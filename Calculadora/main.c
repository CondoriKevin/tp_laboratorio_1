#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

int main()
{
    int opcion_1;
    int numero_1;
    int numero_2;
    int triggerPrimerNum = 0;
    int triggerSegundoNum = 0;
    int triggerOperaciones = 0;
    char seguir = 's';

    opcion_1 = menu();
    do{
    switch( opcion_1){

        case 1:
        printf("\nIngrese el primer numero\n");
        scanf("%d",&numero_1);
        triggerPrimerNum = 1;
        opcion_1 = menu_1(numero_1);
        break;

        case 2:
        printf("\nIngrese el segundo numero\n");
        scanf("%d",&numero_2);
        triggerSegundoNum = 1;
        opcion_1 = menu_2(numero_1, numero_2);
        break;

        case 3:
            if( triggerPrimerNum == 1 && triggerSegundoNum == 1){

            sumar(numero_1, numero_2);
            restar(numero_1, numero_2);
            dividir(numero_1, numero_2);
            multiplicar(numero_1, numero_2);
            factorial_1(numero_1);
            factorial_2(numero_2);
            printf("\nOperaciones realizadas con exito\n");
            system("pause");
            opcion_1 = menu_2(numero_1, numero_2);
            triggerOperaciones = 1;
            }else{
            printf("Debe ingresar Ambos numeros antes de realizar las operaciones");
            system("pause");
            opcion_1 = menu();
            }
            triggerPrimerNum = 0;
            triggerSegundoNum = 0;

        break;

        case 4:
            if(triggerOperaciones == 1){

        resultados(numero_1, numero_2);
        system("pause");
        opcion_1 = menu_2(numero_1, numero_2);


            }else{
            printf("\nDebe realizar las operaciones primero\n\n");//suponiedno que los numeros fueron ingresados correctamente
            system("pause");
            opcion_1 = menu_2(numero_1, numero_2);
            }
            triggerOperaciones = 0;

        break;

        case 5:
        seguir = 'n';
        break;

        default:
        printf("Opcion invalida\n\n");
        system("pause");

    }

    system("pause");

    }while(seguir == 's');

    printf("Saliste del Programa");

    return 0;
}
