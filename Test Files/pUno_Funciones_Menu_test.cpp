/**------------------------------------------------------------------------------------------------
 * ?                                           ABOUT
 * @authors        :  Leonardo Olmedo (327960); Santiago Arellano (328370)
 * @clase          :  Programacion Avanzada en C++
 * @createdOn      :  29-09-23
 * @description    :  Archivo de Testeo para Funciones Menu
------------------------------------------------------------------------------------------------**/


/**-------------------------------------------
 * ? Preprocessing Directives
-------------------------------------------**/
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
#include <array>
#include "./../Header Files/pUno_Funciones_Principales_Menu.h"
#include "./../Implementacion Files/pUno_Funciones_Principales_Menu.cpp"
#include <windows.h>
/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/

int main()
{
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Bienvenidos al Juego de Cinco Clanes");
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Favor Ingrese el numero de Jugadores");

}
