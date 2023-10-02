/**------------------------------------------------------------------------------------------------
 * ?                                           ABOUT
 * @authors        :  Leonardo Olmedo (327960); Santiago Arellano (328370)
 * @clase          :  Programacion Avanzada en C++
 * @createdOn      :  29-09-23
 * @description    :  Archivo de Defincion para funcinoes del menu principal.
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
#include "./../Header Files/pUno_Logica_Basica_Class.h"
/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/


#ifndef PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_FUNCIONES_PRINCIPALES_MENU_H
#define PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_FUNCIONES_PRINCIPALES_MENU_H


struct retorno_valor_e_index_ganador
{
    int index_ganador;
    int valor_ganador;
};

//? Funciones de Impresion y Helpers
void helper_function_one_imprimir_linea_separadora_120_chars();
void helper_function_one_imprimir_titulo_120_chars(std::string titulo);
void helper_functions_one_imrpimir_listado_de_y_estadistica_de_victorias_jugadores(std::vector<pUno_Jugador_Class>& player_array_placeholder);
void helper_functions_one_imprimir_resultados_estadisticos_en_forma_de_diagrama(std::vector<pUno_Jugador_Class>& player_array_placeholder);
void helper_functions_one_imprimir_listado_de_tarjetas_por_jugador(std::vector<pUno_Jugador_Class>& player_array_placeholder);
void helper_functions_one_anadir_un_numero_de_cartas_a_los_jugadores(std::vector<pUno_Jugador_Class>& player_array_placeholder, pUno_Logica_Basica_Class& logica_basica_instance_placeholder,int numero_cartas_a_anadir );
retorno_valor_e_index_ganador helper_functions_one_kadane_approximation_to_find_largest_value_or_equal_values_in_array(std::vector<int>& array_placeholder);

//? Funciones de Juego y Helpers
void helper_menu_functions_opcion_uno_jugar_partida(std::vector<pUno_Jugador_Class>& player_array_placeholder, pUno_Logica_Basica_Class& logica_basica_instance_placeholder);
void helper_menu_functions_opcion_dos_revisar_estadisticas(std::vector<pUno_Jugador_Class>& player_array_placeholder);
void helper_menu_functions_opcion_tres_cambiar_numero_jugadores(std::vector<pUno_Jugador_Class>& player_array_placeholder);
void helper_menu_functions_opcion_cuatro_cambiar_nombres_jugadores(std::vector<pUno_Jugador_Class> & player_array_placeholder);
#endif //PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_FUNCIONES_PRINCIPALES_MENU_H
