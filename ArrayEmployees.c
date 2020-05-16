#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TAM 5


////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
int menu ()  // no recive nada pero devuelve algo (entero)
{

    int opcion;

    system("cls");

    printf("*****Employee Managements*****\n\n");
    printf("1. Add Employee\n");
    printf("2. Modify Employee\n");
    printf("3. Remove Employee\n");
    printf("4. Informe\n");
    printf("5. Exit\n\n");

    //printf("Enter an option: ");
    //fflush(stdin);
    //scanf("%d", &opcion);
    utn_getEntero(&opcion, 3, "Enter an option: ", "Invalid Option\n", 6, 0);

    return opcion;

}
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
int initEmployees(eEmployee vec[], int tam)
{

    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1; // esta vacio???
    }
    return 0;
}
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
int findFreePlace(eEmployee vec[], int tam)
{
//recoorrer el vector en busca de un lugar libre

    int freeP = -1; // me ahorro en usar un "else" , devuelve un "no" de entrada

    for(int i=0; i < tam; i++)
    {

        if (vec[i].isEmpty == 1)
        {
            freeP = i;//devuelve el lugar vacio para poder dar alta a un empleado, recien ahora paso a "addEmployees"
            break; // ya consegui lo que queria
        }

    }

    return freeP;

}


int addEmployees(int idE, eEmployee vec[], int tam)
{

    int indice = findFreePlace(vec, tam);//se carga el reasultado del indice en "FindFreePlace"
    eEmployee auxEmployee; // usamos esta "estructura auxiliar" para ver que los datos sean validos antes de cargarlos definitivamente
    int flagOk = 0;
    system("cls");

    // limpiamos el menu de opciones

    printf("********AddEmployees********\n");

    if( indice == -1 )//hay lugar?? "indice == -1" entonces NO hay lugar---> indice que se refiere a "FindFreePlace"
    {
        printf("The system is complete\n\n");
    }
    else
    {
        //si el Id no Existe empieza a cargar en un Auxiliar para verificar los datos antes de  cargarlos definitivamente
        auxEmployee.id = idE;// el Id se va a generar automaticamente

        utn_getNombre(auxEmployee.name, "Enter Name: ", "Error ");

        utn_getNombre(auxEmployee.lastName, "Enter LastName: ", "Error, Enter LastName: ");

        utn_getNumeroDecimal(&auxEmployee.salary, 3, "Enter Salary :", "Invalid Option.\n",10000.00,0.00);

        ShowSectors();
        utn_getEntero(&auxEmployee.Sector, 3, "Enter sector :", "Invalid Option.\n", 6, 0);

        auxEmployee.isEmpty = 0; // ya no esta vacia

        vec[indice] = auxEmployee;//COPIO AL VECTOR EL EMPLEADO NUEVO "[indice]" es el lugar vacio que se habia ancontrado al principio
        flagOk = 1;// con el ok en 1 --> PODEMOS AGREGAR OTRO EMPLEADO Y EL ID VA A AUMENTAR COMO CORRESPONDE.
        system("pause");
    }//else INTERIOR

    return flagOk;

}

void ShowSectors()
{


    printf("\n***** Sectors *****\n\n");
    printf(" 1-->(Sistem)\n");
    printf(" 2-->(RR.HH)\n");
    printf(" 3-->(Programming)\n");
    printf(" 4-->(DataBase)\n");
    printf(" 5-->(Hardware)\n");

}
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////

int findEmployeeById(int id, eEmployee vec[], int tam)
{

    int findE = -1; // el empleado todavia no esta cargado segun su id

    for(int i=0; i < tam; i++)
    {

        if(vec[i].id == id && vec[i].isEmpty == 0)  //El empleado ya existe, segun su id
        {
            findE = i;
            break;
        }
    }

    return findE;
}


void modifyEmployeeData(eEmployee vec[], int tam)
{

    int id;
    int indice;
    char sure;//¿Seguro?


    system("cls");
    printf("********Modify Employees********\n");

    printf("Introduce ID of employee you want modify: ");
    scanf("%d", &id);


    indice = findEmployeeById(id, vec, tam);
    if(indice == -1)
    {

        printf("Employee dont exist with this ID : %d\n", id);
        system("pause");
    }
    else
    {

        ShowEmployee(vec[indice]);
        system("pause");

        switch(menuModify())
        {


        case 1:

            printf("Do you want modify Name? y(yes)/n(no)  ");
            fflush(stdin);
            scanf("%c", &sure);

            if (sure == 'y')
            {
                utn_getNombre(vec[indice].name, "Enter New Name: ", "Error, Enter New Name: ");
                printf("Successful modification!!!\n");
            }
            else
            {
                printf("Operation has been cancel \n");
            }

            break;

        case 2:

            printf("Do you want modify Last Name? y(yes)/n(no) ");
            fflush(stdin);
            scanf("%c", &sure);

            if (sure == 'y')
            {
                utn_getNombre(vec[indice].lastName, "Enter New Last Name: ", "Error, Enter New Last Name: ");
                printf("Successful modification!!!\n");
            }
            else
            {
                printf("Operation has been cancel \n");
            }
            break;

        case 3:

            printf("Do you want modify Salary? y(yes)/n(no) ");
            fflush(stdin);
            scanf("%c", &sure);

            if (sure == 'y')
            {
                utn_getNumeroDecimal(&vec[indice].salary, 3, "Enter New Salary :", "Error, Enter New Salary\n",10000.00,0.00);
                printf("Successful modification!!!\n");
            }
            else
            {
                printf("Operation has been cancel \n");
            }
            break;

        case 4:

            printf("Do you want modify Sector? y(yes)/n(no) ");
            fflush(stdin);
            scanf("%c", &sure);

            if (sure == 'y')
            {
                ShowSectors();
                utn_getEntero(&vec[indice].Sector, 3, "Enter New Salary :", "Error, Enter New Salary\n",6,0);
                printf("Successful modification!!!\n");
            }
            else
            {
                printf("Operation has been cancel \n");
            }
            break;

        case 5:

            printf("Do you want cancel? y(yes)/n(no) ");
            fflush(stdin);
            scanf("%c", &sure);

            if (sure == 'y')
            {
                menu();
            }
        default:
            printf("InVaLiD oPtIoN");
            break;


        }//FIN DE SWITCH

    }//fin del else DONDE DEBO MODIFICAR DATOS

}


int menuModify ()  // no recive nada pero devuelve algo (entero)
{

    int option;



    printf("*****Would you like modify ...*****\n\n");
    printf("1. Name \n");
    printf("2. LastName \n");
    printf("3. Salary\n");
    printf("4. Sector\n");
    printf("5. Cancelar\n");

    printf("Enter an option:");
    fflush(stdin);
    scanf("%d", &option);

    return option;

}


int printEmployees(eEmployee vec[], int tam)
{
    int hayEmpleados = 0;
    printf("********Show Employees********\n");
    printf("   Id       Name        LastName      Salary    Sector\n");

    for (int i=0; i< tam; i++)
    {
        if (vec[i].isEmpty == 0)
        {
            ShowEmployee(vec[i]);
            hayEmpleados = 1;
        }
    }

    if ( hayEmpleados == 0)
    {
        printf("\n Do not exist employees \n");
    }
    return 0;
}

void ShowEmployee( eEmployee emp)
{

    printf("\n%d    %10s       %10s       %.2f       %d \n", emp.id, emp.name, emp.lastName, emp.salary, emp.Sector);

}

////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////

int removeEmployee(eEmployee vec[], int tam,int id)
{
    int eliminado = -1;
    int indice;
    char confirma;
    system("cls");
    printf("********Remove Employee********\n");

    //printf("Enter ID of employee you want delete: ");
    //scanf("%d",&id);
    utn_getEntero(&id, 3, "Enter ID of employee you want delete:", "Error, Enter ID of employee you want delete:\n",2001,999);

    indice = findEmployeeById(id, vec, tam);
    if (indice == -1)
    {
        printf("Don't exist a employee with this ID: %d. \n", id);
    }
    else
    {
        ShowEmployee(vec[indice]);
        printf("Do you want remove this employee? y(yes)/n(no) ");
        fflush(stdin);
        scanf("%c", &confirma);
        if (confirma == 'y')
        {
            vec[indice].isEmpty = 1;
            printf("Successful modification!!!\n");
            eliminado = 0;
        }
        else
        {
            printf("Operation has been cancel \n");
        }

    }

    return eliminado;

}

////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////
////////////////////*********************************////////////////////

void reportEmployees(eEmployee vec[], int tam)
{
    char confirma;
    char seguir = 'y';

    do
    {
        switch(menuReport())
        {
        case 'a':
            sortEmployees(vec, tam,1);
            printEmployees(vec, tam);
            system("pause");
            system("cls");
            break;
        case 'b':
            sortEmployees(vec, tam,0);
            printEmployees(vec, tam);
            system("pause");
            system("cls");
            break;
        case 'c':


            break;
        case 'd':
            printf("Do you want Exit? y(yes)/n(no)   ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 'y')
            {
                seguir = 'n';
            }
            break;

        }


    }
    while ( seguir == 'y');

}

char menuReport()
{
    char opcion;


    printf("********Report Employees********\n");
    printf("A.  Employees A-->Z.\n");
    printf("B.  Employees Z-->A.\n");
    printf("C.  Employees by Salary.\n");
    printf("D.  Cancel\n");
    printf("Enter Option: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;

}

int sortEmployees(eEmployee vec[], int tam, int order)
{

    eEmployee auxEmployee;
    int sortOk = -1;

    if(order == 1)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(vec[i].lastName,vec[j].lastName)<0)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                else if((vec[i].lastName == vec[j].lastName) && ((vec[i].Sector > vec[j].Sector)))
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                sortOk = 0;
            }
        }
    }

    if(order == 0)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(vec[i].lastName,vec[j].lastName)>0)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                else if((vec[i].lastName == vec[j].lastName) && ((vec[i].Sector > vec[j].Sector)))
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                sortOk = 0;
            }
        }
    }


    return sortOk;
}
