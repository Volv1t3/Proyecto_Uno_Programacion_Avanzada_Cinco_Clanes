/**------------------------------------------------------------------------------------------------
 * ?                                           ABOUT
 * @authors        :  Leonardo Olmedo (327960); Santiago Arellano (328370)
 * @clase          :  Programacion Avanzada en C++
 * @createdOn      :  29-09-23
 * @description    :  Archivo de Implementacion para las funciones del menu principal
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

/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/

void helper_function_one_imprimir_linea_separadora_120_chars()
{
    for(std::size_t character =0; character < 120; character +=1)
    {
        std::cout << "=";
    }
    std::cout << "\n";
}

void helper_function_one_imprimir_titulo_120_chars(std::string titulo)
{
    auto cantidad_characteres_libres = 120 - titulo.size();
    for(size_t index = 0; index < cantidad_characteres_libres/2 -1; index +=1)
    {
        std::cout << "=";
    }
    std::cout << "|" << titulo << "|";
    for(size_t index =0; index < cantidad_characteres_libres/2 -1; index +=1)
    {
        std::cout << "=";
    }
    std::cout << std::endl;
}