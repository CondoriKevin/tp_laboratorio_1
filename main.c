#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define TAM 5


int main()
{
    int id=0;
    char confirma;
    int triggerAdd = 0;
    char seguir = 'y';
    int proximoId  = 1000;
    eEmployee vec[TAM] ; // vector de estructura



    initEmployees(vec, TAM);

    do
    {

        switch( menu() )
        {

        case 1:

            if (addEmployees(proximoId, vec, TAM))
            {
                proximoId++;
            }

            triggerAdd = 1;
break;
        case 2:
            if(triggerAdd == 1){
            modifyEmployeeData(vec, TAM);
            }else{
            printf("You have to add employes before.\n");
            system("pause");
            }
            break;
        case 3:
            if(triggerAdd == 1){
            removeEmployee(vec, TAM, id);
            }else{
            printf("You have to add employes before.\n");
            system("pause");
            }
            break;
        case 4:
            if(triggerAdd == 1){
            reportEmployees(vec, TAM);
            }else{
            printf("You have to add employes before.\n");
            system("pause");
            }
            break;
        case 5:
            fflush(stdin);
            printf("Are you sure to Exit? y(yes) n(no)\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if ( confirma == 'y')
            {
                seguir = 'n';
            }
            break;

        }
        system ("pause");
    }
    while (seguir =='y');


}

