/**------------------------------------------------------------------------------------------------
 * ?                                           ABOUT
 * @authors        :  Leonardo Olmedo (327960); Santiago Arellano (328370)
 * @clase          :  Programacion Avanzada en C++
 * @createdOn      :  27-09-23
 * @description    :  Archivo Definicion de la Clase Usuario Teatro.
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
#include "../Header Files/pUno_Logica_Basica_Class.h"
#include "../Implementacion Files/pUno_Logica_Basica_Class.cpp"
/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/


int main()
{
    pUno_Logica_Basica_Class pUno_Logica_Basica_Class_Obj;

    //? Escribiendo casos de prueba para obtener tarjetas

    for(size_t index = 0; index < 40; index++)
    {
        std::cout << "Index = " << index << std::endl;
        auto objeto_tarjeta = pUno_Logica_Basica_Class_Obj.seleccionar_una_tarjeta_y_retornar_struct();
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Clan de la Tarjeta: " << objeto_tarjeta.clan_de_la_carta << std::endl;
        std::cout << "Nombre de la Tarjeta: " << objeto_tarjeta.nombre_de_la_carta << std::endl;
        std::cout << "Valor de la Tarjeta: " << objeto_tarjeta.valor_de_carta << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
    pUno_Logica_Basica_Class_Obj.reiniciar_arreglo_de_tarjetas_jugadas();
}