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
            while (std::cout << "Ingrese el numero de jugadores a participar: " && !(std::cin >> numero_de_jugadores_para_partida))
            {
                std::cin.clear();
                std::cout << "Error en el valor ingresado, favor de ingresar un valor numerico" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << std::endl;
        }
        catch(std::exception & error)
        {
            std::cerr << "Error 0x001 [Raised] - El parametro ingresado para el numero de jugadores es incorrecto." << std::endl;
            std::cerr << error.what() << std::endl;
        }
        if (numero_de_jugadores_para_partida < 2 || numero_de_jugadores_para_partida > 5)
        {
            std::cout << "Error en el valor ingresado, solo se permiten jugadores entre 2 y 5" << std::endl;
        }
    }
    while (numero_de_jugadores_para_partida < 2 || numero_de_jugadores_para_partida > 5);
    std::cout << std::endl;
    //! Paso base.3: Creacion de objetos necesarimos para el funcionamiento del codigo
    pUno_Logica_Basica_Class logica_basica_alpha;
    std::vector<pUno_Jugador_Class> listado_de_jugadores;

    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Ingresemos los nombres de cada jugador!");
    std::cout << std::endl;
    std::cin.clear();
    std::cin.ignore();
    for(size_t index = 0; index < numero_de_jugadores_para_partida; index++)
    {
        std::string nombre_jugador_placeholder;
        pUno_Jugador_Class generated_player;

        do {
            std::cout << "Ingresemos el nombre del jugador [" << index + 1 << "] : ";

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

    //! Paso base.4: Ahora que tenemos los valores de la cantidad de jugadores y sus nombres podemos imprimir el menu
    //! principal
    unsigned int opcion_usuario_menu{0};
    helper_function_one_imprimir_linea_separadora_120_chars();
    helper_function_one_imprimir_titulo_120_chars("Menu Principal");
    do {
        std::cout << "1. Jugar una Partida."
                     "\n2. Revisar Estadisticas por Jugador."
                     "\n3. Cambiar el Numero de Jugadores."
                     "\n4. Cambiar el Nombre de los Jugadores."
                     "\n5. Salir del Juego\n";

        //? Paso base.4.1: validacion de ingreso de datos de datos de itpo entero para evitarnos errores graves durante ejecucion
        while (std::cout << "Opcion Elegida: " && !(std::cin >> opcion_usuario_menu)) {
            std::cout << "Tipo de Dato Incorrecto, favor ingresar un numero entero referente al menu anterior\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        //? Paso base.4.2: Difurcacion de casos en base a input numerico del usuario
        std::cout << std::endl;
        switch (opcion_usuario_menu) {
            case 1: {
                helper_function_one_imprimir_linea_separadora_120_chars();
                helper_menu_functions_opcion_uno_jugar_partida(listado_de_jugadores, logica_basica_alpha);
                helper_function_one_imprimir_linea_separadora_120_chars();
                break;
            }
            case 2: {
                helper_function_one_imprimir_linea_separadora_120_chars();
                helper_menu_functions_opcion_dos_revisar_estadisticas(listado_de_jugadores);
                helper_function_one_imprimir_linea_separadora_120_chars();
                break;
            }
            case 3: {
                helper_function_one_imprimir_linea_separadora_120_chars();
                helper_menu_functions_opcion_tres_cambiar_numero_jugadores(listado_de_jugadores);
                helper_function_one_imprimir_linea_separadora_120_chars();
                break;
            }
            case 4: {
                helper_function_one_imprimir_linea_separadora_120_chars();
                helper_menu_functions_opcion_cuatro_cambiar_nombres_jugadores(listado_de_jugadores);
                helper_function_one_imprimir_linea_separadora_120_chars();
                break;
            }
            case 5: {
                helper_function_one_imprimir_linea_separadora_120_chars();
                helper_function_one_imprimir_titulo_120_chars("Gracias por Jugar!");
                helper_function_one_imprimir_linea_separadora_120_chars();
                break;
            }
            default: {
                helper_function_one_imprimir_linea_separadora_120_chars();
                std::cout
                        << "El valor ingresado, no corresponde a ninguna opcion en nuestro menu, favor revisar su input."
                        << std::endl;
                helper_function_one_imprimir_linea_separadora_120_chars();
            }
        }
    }
    while (opcion_usuario_menu != 5);
}