/**------------------------------------------------------------------------------------------------
 * ?                                           ABOUT
 * @authors        :  Leonardo Olmedo (327960); Santiago Arellano (328370)
 * @clase          :  Programacion Avanzada en C++
 * @createdOn      :  29-09-23
 * @description    :  Archivo Principal para Ejecucion del Juego
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
#include <windows.h>
/**-------------------------------------------
 * ? Includes de clase Logica Basica
-------------------------------------------**/
#include "./../Header Files/pUno_Logica_Basica_Class.h"
#include "./../Implementacion Files/pUno_Logica_Basica_Class.cpp"
/**-------------------------------------------
 * ? Includes de la Clase Jugador
-------------------------------------------**/
#include "./../Header Files/pUno_Jugador_Class.h"
#include "./../Implementacion Files/pUno_Jugador_Class.cpp"
/**-------------------------------------------
 * ? Includes de las funciones principales
-------------------------------------------**/
#include "./../Header Files/pUno_Funciones_Principales_Menu.h"
#include "./../Implementacion Files/pUno_Funciones_Principales_Menu.cpp"





/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/

int main()
{
    //! Paso base.1 Interaccion con el ususario, impresion de Titulos y Demas
    helper_function_one_imprimir_titulo_120_chars("Universidad San Francisco de Quito");
    helper_function_one_imprimir_titulo_120_chars("Programacion Avanzada en C++");
    helper_function_one_imprimir_titulo_120_chars("Leonardo Olmedo & Santiago Arellano");
    Sleep(1000);
    //! Paso base.2: Recopilacion de los datos del numero de jugadores a participar
    int numero_de_jugadores_para_partida{0};
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Bienvenido al juego de Cinco Clanes!");

    do {
        try {
            std::cout << "Ingrese el numero de jugadores a participar: ";
            std::cin >> numero_de_jugadores_para_partida;
            std::cout << std::endl;
        }
        catch(std::exception & error)
        {
            std::cerr << "Error 0x001 [Raised] - El parametro ingresado para el numero de jugadores es incorrecto." << std::endl;
            std::cerr << error.what() << std::endl;
        }
    }
    while (numero_de_jugadores_para_partida < 2 || numero_de_jugadores_para_partida > 5);
    std::cout << std::endl;
    //! Paso base.3: Creacion de objetos necesarimos para el funcionamiento del codigo
    pUno_Logica_Basica_Class logica_basica_alpha;
    std::vector<pUno_Jugador_Class> listado_de_jugadores;

    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Ingresemos los nombres de cada jugador!");
    std::cin.clear();
    std::cin.ignore();
    for(size_t index = 0; index < numero_de_jugadores_para_partida; index++)
    {
        std::string nombre_jugador_placeholder = "Vacio";
        pUno_Jugador_Class generated_player;
        do {
            std::cout << "Ingresemos el nombre del jugador" << index + 1 << " : ";

            try {

                std::getline(std::cin,  nombre_jugador_placeholder);
                std::cout << std::endl;
            }
            catch(std::exception & error)
            {
                std::cerr << "Error 0x001 [Raised] - El parametro ingresado para el numero de jugadores es incorrecto." << std::endl;
                std::cerr << error.what() << std::endl;
            }

        }
        while (nombre_jugador_placeholder.length() == 0);

        generated_player.set_nombre_jugador(nombre_jugador_placeholder);
        listado_de_jugadores.push_back(generated_player);
    }

    for(auto const& player: listado_de_jugadores)
    {
        std::cout << player.get_nombre_jugador() << std::endl;
    }

}