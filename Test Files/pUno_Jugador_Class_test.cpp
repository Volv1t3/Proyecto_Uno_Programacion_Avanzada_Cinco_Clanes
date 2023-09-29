/**------------------------------------------------------------------------------------------------
 * ?                                           ABOUT
 * @authors        :  Leonardo Olmedo (327960); Santiago Arellano (328370)
 * @clase          :  Programacion Avanzada en C++
 * @createdOn      :  29-09-23
 * @description    :  Archivo de Implementacion Clase Jugador
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
#include "./../Header Files/pUno_Jugador_Class.h"
#include "./../Implementacion Files/pUno_Jugador_Class.cpp"
#include "./../Header Files/pUno_Logica_Basica_Class.h"
#include "./../Implementacion Files/pUno_Logica_Basica_Class.cpp"
/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/

int main()
{
    std::cout << "entering debug session" << std::endl;
    pUno_Logica_Basica_Class logic_object_alpha;
    //? Primero generamos una serie de objetos de usuario, en general tres como puede ser el primer caso de los usuarios en el juego.
    std::array<std::string,3>  user_names = {"Leonardo","Santiago","Juan"};
    std::array<pUno_Jugador_Class, 3>  ss{};
    for(size_t index = 0; index < user_names.size(); index++)
    {
        ss.at(index).set_nombre_jugador(user_names.at(index));
    }
    //? Ahora generamos una serie de cartas para cada uno de los usuarios.
    for(size_t repetition = 0; repetition < 3; repetition+=1)
    {
        for(size_t index = 0; index < 8; index+=1)
        {
            auto card_genereator_alpha = logic_object_alpha.seleccionar_una_tarjeta_y_retornar_struct();
            ss.at(repetition).aumentar_en_uno_las_cartas_del_jugador(card_genereator_alpha.nombre_de_la_carta);
            ss.at(repetition).registar_tarjeta_completamente_basada_en_valor_y_tipo
            (card_genereator_alpha.valor_de_carta, card_genereator_alpha.clan_de_la_carta);
        }
        ss.at(repetition).cuantificar_puntos_del_jugador();
    }

    //? Ahora imprimimos el resultado de los usuarios.
    for(auto & s : ss)
    {
        std::cout << "Player {" << s.get_nombre_jugador() << "}:" << std::endl;
        s.imprimir_cartas_del_jugador();
        std::cout << "Cartas del Jugador: " << s.get_cantidad_de_cartas_jugador() << std::endl;
        std::cout << "Puntos del Jugador: " << s.get_cantidad_de_puntos_jugador() << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }

}
