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
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
#include <array>
#include "./../Header Files/pUno_Funciones_Principales_Menu.h"
#include "./../Header Files/pUno_Jugador_Class.h"
#include "./../Header Files/pUno_Logica_Basica_Class.h"
#include <algorithm>

/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/

void helper_function_one_imprimir_linea_separadora_120_chars()
{
    for(std::size_t character =0; character < 119; character +=1)
    {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void helper_function_one_imprimir_titulo_120_chars(std::string titulo)
{
    auto cantidad_characteres_libres = 120 - titulo.size();
    for(size_t index = 0; index < cantidad_characteres_libres/2 -2; index +=1)
    {
        std::cout << "=";
    }
    std::cout << "|" << titulo << "|";
    for(size_t index =0; index < cantidad_characteres_libres/2 -2; index +=1)
    {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void helper_functions_one_imrpimir_listado_de_y_estadistica_de_victorias_jugadores(std::vector<pUno_Jugador_Class>& player_array_placeholder)
{
    helper_function_one_imprimir_titulo_120_chars("Listado de Jugadores y sus Estadisticas");
    helper_function_one_imprimir_linea_separadora_120_chars();
    std::cout << "|" << std::setw(3) << "ID" << "|" << std::setw(15) << std::right <<
    "Nombre" << "|" << std::setw(15) << std::right << "Victorias"  << "|" << std::endl;
    for(size_t index = 0; index < player_array_placeholder.size(); index +=1)
    {
        std::cout << std::setw(4) << std::right << index +1 << "|" << std::setw(15) << std::right
        << player_array_placeholder[index].get_nombre_jugador() << "|" << std::setw(15) << std::right
        << player_array_placeholder[index].get_numero_de_victorias_jugador() << "|" << std::endl;
    }
    helper_function_one_imprimir_linea_separadora_120_chars();
}

void helper_functions_one_imprimir_resultados_estadisticos_en_forma_de_diagrama(std::vector<pUno_Jugador_Class>& player_array_placeholder)
{
    helper_function_one_imprimir_titulo_120_chars("Victorias en Diagrama de Barras");
    for(size_t index = 0; index < player_array_placeholder.size(); index +=1)
    {
        std::cout  << std::setw(15) << std::left << player_array_placeholder[index].get_nombre_jugador() << "| ";
        for(size_t vic_index = 0; vic_index < player_array_placeholder[index].get_numero_de_victorias_jugador(); vic_index +=1)
        {
            std::cout << "@ " << " ";
        }
        std::cout << std::endl;
    }
    helper_function_one_imprimir_linea_separadora_120_chars();
}

void helper_functions_one_imprimir_listado_de_tarjetas_por_jugador(std::vector<pUno_Jugador_Class>& player_array_placeholder)
{
    helper_function_one_imprimir_titulo_120_chars("Listado de Tarjetas por Jugador");
    for(size_t player_index = 0; player_index < player_array_placeholder.size(); player_index +=1)
    {
        helper_function_one_imprimir_linea_separadora_120_chars();
        helper_function_one_imprimir_titulo_120_chars(player_array_placeholder.at(player_index).get_nombre_jugador());
        player_array_placeholder.at(player_index).imprimir_cartas_del_jugador();
        helper_function_one_imprimir_linea_separadora_120_chars();
    }
}

bool helper_functions_one_anadir_un_numero_de_cartas_a_los_jugadores
(std::vector<pUno_Jugador_Class>& player_array_placeholder,
 pUno_Logica_Basica_Class& logica_basica_instance_placeholder,int numero_cartas_a_anadir)
{
    for(size_t repetitions_by_player_num = 0; repetitions_by_player_num < player_array_placeholder.size(); repetitions_by_player_num +=1)
    {
        for(size_t carta_repartida = 0; carta_repartida < numero_cartas_a_anadir; carta_repartida +=1)
        {
            auto placeholder_para_carta_repartida = logica_basica_instance_placeholder.seleccionar_una_tarjeta_y_retornar_struct();
            // * Agregamos tarjeta al arreglo interno de cada jugador basado en valor menos 1 y tipo normal

            if (placeholder_para_carta_repartida.valor_de_carta != -1 && placeholder_para_carta_repartida.clan_de_la_carta != -1) {
                player_array_placeholder.
                                at(repetitions_by_player_num)
                        .registar_tarjeta_completamente_basada_en_valor_y_tipo
                                (placeholder_para_carta_repartida.valor_de_carta,
                                 placeholder_para_carta_repartida.clan_de_la_carta);
                // * Agregamos nombre de la tarjeta
                player_array_placeholder.
                        at(repetitions_by_player_num).
                        aumentar_en_uno_las_cartas_del_jugador(placeholder_para_carta_repartida.nombre_de_la_carta);
            }
            else
            {
                std::cout << "El Mazo de Tarjetas se ha terminado" << std::endl;
                return false;
            }
        }
        player_array_placeholder.at(repetitions_by_player_num).cuantificar_puntos_del_jugador();
    }
    return true;
}

retorno_valor_e_index_ganador helper_functions_one_kadane_approximation_to_find_largest_value_or_equal_values_in_array(std::vector<int>& array_placeholder)
{
    retorno_valor_e_index_ganador struct_for_returning_values;
    int max_value = INT_MIN;
    int max_index = -1;
    bool is_duplicate = false;

    for (int index = 0; index < array_placeholder.size(); index++) {
        if (array_placeholder[index] > max_value) {
            max_value = array_placeholder[index];
            max_index = index;
            is_duplicate = false;
        } else if (array_placeholder[index] == max_value) {
            is_duplicate = true;
        }
    }

    if (max_value == 0 || is_duplicate) { // all values are zero or there are duplicate max values
        struct_for_returning_values.valor_ganador = 0;
        struct_for_returning_values.index_ganador = -1;
    } else {
        struct_for_returning_values.valor_ganador = max_value;
        struct_for_returning_values.index_ganador = max_index;
    }

    return struct_for_returning_values;
}


void helper_function_one_imprimir_listado_de_jugadores(std::vector<pUno_Jugador_Class>&  player_array_placeholder)
{
    helper_function_one_imprimir_linea_separadora_120_chars();
    std::cout << std::setw(3) << std::left << "ID" << "|" << std::setw(15) << std::left << "Nombre" << "|" << std::endl;
    for(size_t index = 0; index < player_array_placeholder.size(); index +=1)
    {
        std::cout  << std::setw(3) << std::left << index +1 << "|" << std::setw(15)
        << std::left << player_array_placeholder[index].get_nombre_jugador() << "| " << std::endl;
    }
}











//! Implementacion de las funciones claves para el menu principal
void helper_menu_functions_opcion_uno_jugar_partida(std::vector<pUno_Jugador_Class>& player_array_placeholder, pUno_Logica_Basica_Class& logica_basica_instance_placeholder)
{
    helper_function_one_imprimir_titulo_120_chars("Iniciando Partida!");
    helper_function_one_imprimir_titulo_120_chars("Repartiendo Tres Cartas por Jugador!");
    //? Paso base.1: Repartimos cartas por cada jugador teniendo en cuenta numero de jugadores como numero de iteraciones
    //? primarias y luego el numero de tarjetas como indice secudario.

    //? Paso base.2: Luego de Haber Recibido las cartas, procedemos a imprimirlas para cada usuario junto con su puntaje
    //? asi somos transparentes con cada usuario.

    helper_functions_one_anadir_un_numero_de_cartas_a_los_jugadores(player_array_placeholder, logica_basica_instance_placeholder, 3);
    helper_functions_one_imprimir_listado_de_tarjetas_por_jugador(player_array_placeholder);

    //! Paso inductivo.1: A continuacion de presentar las cartas, podemos presentar los puntajes de cada uno y mostrar
    //! que por lo general nadie gana en la primera corrida y por tanto pasamos el control al usuario.

    std::vector<int> puntaje_actual_de_los_jugadores{};
    helper_function_one_imprimir_titulo_120_chars("Imprimiendo Resultados Parciales");
    for(size_t player_index = 0; player_index < player_array_placeholder.size(); player_index +=1)
    {
        std::cout  << std::setw(15) << std::left << player_array_placeholder
        .at(player_index).get_nombre_jugador() << " tiene :  "
        << player_array_placeholder.at(player_index).get_cantidad_de_puntos_jugador() << " puntos." << std::endl;
        puntaje_actual_de_los_jugadores.push_back(player_array_placeholder.at(player_index).get_cantidad_de_puntos_jugador());
    }

    //! Paso Inductivo.2: En base al conocimiento del puntaje de cada jugador podemos transaldarnos por todo el arreglo y chequear si ha habido un ganador
    bool alguien_ha_ganado_la_partida = false;
    do {
        auto struct_con_datos_de_ganador = helper_functions_one_kadane_approximation_to_find_largest_value_or_equal_values_in_array(puntaje_actual_de_los_jugadores);
        if (struct_con_datos_de_ganador.valor_ganador != 0 && struct_con_datos_de_ganador.index_ganador != -1)
        {
            helper_function_one_imprimir_titulo_120_chars("Ha Habido un Ganador!");
            std::cout << "El ganador es: " << player_array_placeholder.at(struct_con_datos_de_ganador.index_ganador).get_nombre_jugador() << std::endl;
            std::cout << "El puntaje es: " << struct_con_datos_de_ganador.valor_ganador << std::endl;

            //? Registro de Datos para jugador que gano;
            player_array_placeholder.at(struct_con_datos_de_ganador.index_ganador).aumentar_en_uno_las_victorias_del_jugador();
            alguien_ha_ganado_la_partida = true;
        }
        else
        {
            if (struct_con_datos_de_ganador.valor_ganador == 0 && struct_con_datos_de_ganador.index_ganador == -1)
            {
                int user_option{0};
                helper_function_one_imprimir_titulo_120_chars("Ha Habido un Empate!");
                std::cout << "Seleccione una de las siguientes opciones:\n1.Salir de la Partida Sin Ganador.\n2. Repartir Mas Cartas Hasta Encontrar un ganador\n";
                    while (std::cout << "Su opcion: " && !(std::cin >> user_option)) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Favor Ingrese un numero entero para esta opcion de menu." << std::endl;
                    }
                switch(user_option)
                {
                    case 1:
                    {
                        std::cout << std::endl;
                        helper_function_one_imprimir_titulo_120_chars("Terminando Ejecucion del Juego");
                        alguien_ha_ganado_la_partida = true;
                        break;
                    }
                    case 2:
                    {
                        helper_function_one_imprimir_titulo_120_chars("Generando nuevo set de tarjetas para los jugadores");
                        system("cls");
                        auto check_if_cards_ended = helper_functions_one_anadir_un_numero_de_cartas_a_los_jugadores(player_array_placeholder, logica_basica_instance_placeholder, 1);
                        if (check_if_cards_ended) {
                            helper_functions_one_imprimir_listado_de_tarjetas_por_jugador(player_array_placeholder);
                            puntaje_actual_de_los_jugadores.clear();
                            for (size_t player_index = 0;
                                 player_index < player_array_placeholder.size(); player_index += 1) {
                                std::cout << std::setw(15) << std::left << player_array_placeholder
                                        .at(player_index).get_nombre_jugador() << " tiene :  "
                                          << player_array_placeholder.at(player_index).get_cantidad_de_puntos_jugador()
                                          << " puntos." << std::endl;
                                puntaje_actual_de_los_jugadores.push_back(
                                        player_array_placeholder.at(player_index).get_cantidad_de_puntos_jugador());
                            }
                            break;
                        }
                        else
                        {
                            std::cout << "Se ha Acabado el Mazo de Cartas, lastimosamente nadie ha podido ganar la partida" << std::endl;
                            alguien_ha_ganado_la_partida = true;
                            break;
                        }
                    }
                    default:
                    {
                        std::cout << "Caso no encontrado " << std::endl;
                    }
                }
            }
        }
    }
    while (alguien_ha_ganado_la_partida == false);

    for(size_t index = 0; index < player_array_placeholder.size(); index +=1)
    {
        player_array_placeholder.at(index).limpiar_cartas_y_puntos_del_jugador();
    }

    //? Liempieza de la clase logica basica
    logica_basica_instance_placeholder.reiniciar_arreglo_de_tarjetas_jugadas();
}

void helper_menu_functions_opcion_dos_revisar_estadisticas(std::vector<pUno_Jugador_Class>& player_array_placeholder)
{
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Imprimiendo Datos Estadisiticos de Cada Jugador");
    helper_functions_one_imrpimir_listado_de_y_estadistica_de_victorias_jugadores(player_array_placeholder);
    helper_functions_one_imprimir_resultados_estadisticos_en_forma_de_diagrama(player_array_placeholder);
    helper_function_one_imprimir_linea_separadora_120_chars();
}

void helper_menu_functions_opcion_tres_cambiar_numero_jugadores(std::vector<pUno_Jugador_Class>& player_array_placeholder)
{
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Cambiando el Numero de Jugadores");
    //? Paso base.1: vars para ejecucion
    std::vector<pUno_Jugador_Class> copy_of_player_array_placeholder{};
    int numero_jugadores_nuevo{0};

    do {
        std::cout << "Favor Ingrese el nuevo numero de jugadores que participaran en la siguiente partida "
                     "(Recuerda que solo pueden ser entre 2 a 5 jugadores!) : ";
        std::cin >> numero_jugadores_nuevo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
    while (numero_jugadores_nuevo < 2 || numero_jugadores_nuevo > 5);

    if (numero_jugadores_nuevo >=2 && numero_jugadores_nuevo <= 5)
    {
        std::cout << std::endl;
        std::cout << "Gracias por ingresar un valor correcto, a continuacion se cambiara el numero de jugadores \n"
                     "y sus respectivos nombres." << std::endl;
        //? Paso base.2: Limpiamos el arreglo original y lo llenamos de nuevo con el numero nuevo
        player_array_placeholder.clear();
        for(size_t index = 0; index < numero_jugadores_nuevo; index +=1)
        {
            pUno_Jugador_Class jugador_nuevo_placeholder;
            std::string nuevo_nombre_placeholder;
            do {
                std::cout << std::endl;
                std::cout << "Favor Ingrese el nombre del jugador [" << index + 1 << "] : ";
                std::getline(std::cin, nuevo_nombre_placeholder);
                jugador_nuevo_placeholder.set_nombre_jugador(nuevo_nombre_placeholder);
            }
            while (jugador_nuevo_placeholder.get_nombre_jugador().length() == 0);
            player_array_placeholder.push_back(jugador_nuevo_placeholder);
        }
    }
}




void helper_menu_functions_opcion_cuatro_cambiar_nombres_jugadores(std::vector<pUno_Jugador_Class>& player_array_placeholder)
{
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Imprimiendo Nombres de los Jugadores");
    helper_function_one_imprimir_listado_de_jugadores(player_array_placeholder);
    //? Paso base.1: definir variables para loop indefinido por el usuario
    int index_a_cambiar_el_nombre{0};
    std::string nuevo_nombre_de_jugador;
    do {
        std::cout << "Ingrese el indice del Jugador que desea cambiar el nombre (-1 para finalizar el proceso): ";
        std::cin >> index_a_cambiar_el_nombre;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if((index_a_cambiar_el_nombre >= 1  && index_a_cambiar_el_nombre <= player_array_placeholder.size()))
        {
            std::cout << std::endl;
            std::cout << "A continuacion, ingrese el nombre al que desea cambiar al jugador [" <<
            player_array_placeholder.at(index_a_cambiar_el_nombre-1).get_nombre_jugador() << "] a : ";
            std::getline(std::cin, nuevo_nombre_de_jugador);
            player_array_placeholder.at(index_a_cambiar_el_nombre-1).set_nombre_jugador(nuevo_nombre_de_jugador);
            std::cout << std::endl;
        }
    }
    while (index_a_cambiar_el_nombre != -1);
    std::cout << std::endl;
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Imprimiendo Tabla con Jugadores Actuales y sus Nombres");
    helper_function_one_imprimir_listado_de_jugadores(player_array_placeholder);
}

