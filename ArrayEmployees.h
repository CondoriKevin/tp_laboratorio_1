#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct  // HAY OTRA FORMA DE DECLARAR Y USAR UNA ESTRUTURA PERO ES MUY TEDIOSA
{
    //las variables que tenemos aca son "los campos de un estrucutra"
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int Sector;
    int isEmpty; // " ES VACIA"

} eEmployee; // como nos vamos a referir a esta estructura

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int menu(void);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int initEmployees(eEmployee vec[], int tam);
////NECESITAMOS de "FindFreePlace" para realizar "addEmployees"
/** \brief
 *
 * \param vec[] eEmployee
 * \param tam int
 * \return int
 *
 */
int findFreePlace(eEmployee vec[], int tam); //busca un lugar en un vector para dar el alta de un empleado
/** \brief
 *
 * \param idE int
 * \param vec[] eEmployee
 * \param tam int
 * \return int
 *
 */
int addEmployees(int idE, eEmployee vec[], int tam);
/** \brief
 *
 * \param void
 * \return void
 *
 */
void ShowSectors(void);
/////////FUNCIONES PARA MODIFICAR EMPLEADO/////////////////
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int menuModify (void);
/** \brief
 *
 * \param id int
 * \param vec[] eEmployee
 * \param tam int
 * \return int
 *
 */
int findEmployeeById(int id, eEmployee vec[], int tam);//devuelve el indice en donde YA existe el empleado, o el indice indicando que no existe
/** \brief
 *
 * \param vec[] eEmployee
 * \param tam int
 * \return void
 *
 */
void modifyEmployeeData(eEmployee vec[], int tam);
/** \brief
 *
 * \param vec[] eEmployee
 * \param tam int
 * \return int
 *
 */
int printEmployees(eEmployee vec[], int tam);
/** \brief
 *
 * \param emp eEmployee
 * \return void
 *
 */
void ShowEmployee( eEmployee emp);
////////////////////////FUNCIONES PARA ELIMINAR EMPLEADO//////////////////
/** \brief
 *
 * \param vec[] eEmployee
 * \param tam int
 * \param id int
 * \return int
 *
 */
int removeEmployee(eEmployee vec[], int tam, int id);
//////////////////////INFORMAR EMPLEADOS/////////////////////////////////////
/** \brief
 *
 * \param vec[] eEmployee
 * \param tam int
 * \return void
 *
 */
void reportEmployees(eEmployee vec[], int tam);
/** \brief
 *
 * \param vec[] eEmployee
 * \param tam int
 * \param order int
 * \return int
 *
 */
int sortEmployees(eEmployee vec[], int tam, int order);
/** \brief
 *
 * \return char
 *
 */
char menuReport();
