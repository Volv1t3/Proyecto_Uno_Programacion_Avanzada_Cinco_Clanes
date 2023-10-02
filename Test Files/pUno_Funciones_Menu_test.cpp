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
#include "./../Header Files/pUno_Logica_Basica_Class.h"
#include "./../Header Files/pUno_Jugador_Class.h"
#include "./../Implementacion Files/pUno_Logica_Basica_Class.cpp"
#include "./../Implementacion Files/pUno_Jugador_Class.cpp"
#include <windows.h>
/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/

int main()
{
    pUno_Logica_Basica_Class logic_base_alpha;
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Bienvenidos al Juego de Cinco Clanes");
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Favor Ingrese el numero de Jugadores");

    std::vector<pUno_Jugador_Class> jugadores;
    std::array<std::string, 5> nombres_jugadores{"Santiago", "Emmanuel", "Leonardo", "Juan", "Jorge"};
    for(size_t index = 0; index < 5; index++)
    {
        pUno_Jugador_Class player_holder;
        player_holder.set_nombre_jugador(nombres_jugadores[index]);
        player_holder.aumentar_en_uno_las_victorias_del_jugador();
        player_holder.aumentar_en_uno_las_victorias_del_jugador();
        jugadores.push_back(player_holder);
    }

    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_functions_one_imrpimir_listado_de_y_estadistica_de_victorias_jugadores(jugadores);
    helper_functions_one_imprimir_resultados_estadisticos_en_forma_de_diagrama(jugadores);
    helper_menu_functions_opcion_uno_jugar_partida(jugadores, logic_base_alpha);
    helper_menu_functions_opcion_dos_revisar_estadisticas(jugadores);
    helper_menu_functions_opcion_tres_cambiar_numero_jugadores(jugadores);
    helper_menu_functions_opcion_cuatro_cambiar_nombres_jugadores(jugadores);
}
