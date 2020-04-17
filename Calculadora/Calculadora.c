#include <stdio.h>
#include <stdlib.h>

int menu(){

    int opcion;

    system("cls");
    printf("----Menu de opciones----\n\n");
    printf("1.Ingresar 1er Operando (A = x)\n");
    printf("2.Ingresar 2do Operando (B = y)\n");
    printf("3.Calcular todas las operaciones\n");
    printf("4.Informe de Resultados\n");
    printf("5.Salir\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int menu_1(int num1){

    int opcion;

    system("cls");
    printf("----Menu de opciones----\n\n");
    printf("1.Ingresar 1er Operando (A = %d)\n", num1);
    printf("2.Ingresar 2do Operando (B = y)\n");
    printf("3.Calcular todas las operaciones\n");
    printf("4.Informe de Resultados\n");
    printf("5.Salir\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menu_2(int num1, int num2){

    int opcion;

    system("cls");
    printf("----Menu de opciones----\n\n");
    printf("1.Ingresar 1er Operando (A = %d)\n", num1);
    printf("2.Ingresar 2do Operando (B = %d)\n", num2);
    printf("3.Calcular todas las operaciones\n");
    printf("4.Informe de Resultados\n");
    printf("5.Salir\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



int sumar(int num1, int num2){

    return num1 + num2;
}

int restar(int num1, int num2){

    return num1 - num2;
}

float dividir(float num1, float num2){


    return (num1/num2);
}

int multiplicar(int num1, int num2){

    return num1*num2;
}

int factorial_1(int num1){

    int facto1;

    if (num1 == 1){
        facto1 = 1;
    }else{
    facto1 = num1 * factorial_1(num1 - 1);
    }

    return facto1;
}

int factorial_2(int num2){

    int facto2;

    if (num2 == 1){
        facto2 = 1;
    }else{
    facto2 = num2 * factorial_2(num2 - 1);
    }

    return facto2;
}

void resultados(int num1, int num2){

        printf("\nResultado de la suma (A+B) es : %d\n",sumar(num1, num2));
        printf("\nResultado de la resta  (A-B) es : %d\n",restar(num1, num2));
        if (num2 == 0){
            printf("\nNO es posible dicidir por 0\n");
        }else{
            printf("\nResultado de la diviion (A/B) es : %f\n",dividir(num1, num2));
        }
        printf("\nResultado de la multiplicacion (A*B) es : %d\n",multiplicar(num1, num2));
        printf("\nEl factorial de A es : %d y El de B es : %d\n",factorial_1(num1), factorial_2(num2));

}

