/**------------------------------------------------------------------------------------------------
 * ?                                           ABOUT
 * @authors        :  Leonardo Olmedo (327960); Santiago Arellano (328370)
 * @clase          :  Programacion Avanzada en C++
 * @createdOn      :  29-09-23
 * @description    :  Archivo de Definicion Clase Jugador
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

/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/


#ifndef PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_JUGADOR_CLASS_H
#define PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_JUGADOR_CLASS_H

class pUno_Jugador_Class
{
private:
    //? Definicion de matriz de 8 x 5 para representar las tarjetas del jugador ya asignadas.
    std::array<std::array<int,5>,8> holder_matriz_para_tarjetas_por_fila_y_columna{};

    //? Definicion de contadores para cantidad de cartas y puntos del jugador
    int cantidad_de_puntos_jugador{0};
    int cantidad_de_cartas_jugador{0};

    //? Definicion de vector extra para almacenar las cartas del jugador por nombre
    std::vector<std::string> holder_para_nombres_de_tarjetas_jugador{};

    //? Datos adicionales para funcionamiento e interaccion con el juego
    std::string nombre_jugador;
    int numero_de_victorias_jugador{0};
public:
    //! Paso base.1: Definicion del constructor de la clase, con argumentos, no se puede tener sin argumentos porque el juego
    //! requiere tener el nombre del jugador para impresiones
    pUno_Jugador_Class();

    //! Paso base.2 Definicion de metodos de entrada y salida de datos para los puntos y cantidad de cartas
        //?  Metodo para obtener el nombre del jugador
        [[nodiscard]] std::string get_nombre_jugador() const;
        void set_nombre_jugador(std::string nuevo_nombre_jugador);
        //?  Metodo para obtener el numero de victorias del jugador
        [[nodiscard]] int get_numero_de_victorias_jugador() const;
        pUno_Jugador_Class& aumentar_en_uno_las_victorias_del_jugador();
        //?   Metodo para obtener el numero de cartas del jugador
        [[nodiscard]] int get_cantidad_de_cartas_jugador() const;
        //?   Metodo para obtener el numero de puntos del jugador
        [[nodiscard]] int get_cantidad_de_puntos_jugador() const;
        //? Meotod para aumentar las cartas del jugador basado en su nombre
        pUno_Jugador_Class&  aumentar_en_uno_las_cartas_del_jugador(std::string nombre_de_tarjeta_ingresada);
        pUno_Jugador_Class& registar_tarjeta_completamente_basada_en_valor_y_tipo(int tipo_de_carta, int clan_de_la_carta);

    //! Metodo para trabajar con funciones protected sin exponerlas a abusos por el user o errores en el main.
        //? Metodo general para llamar a cada uno y asignar los valores directamente.
        void cuantificar_puntos_del_jugador();
    //! Metodo para imprimir las cartas del usuario.
    void imprimir_cartas_del_jugador();
    void limpiar_cartas_y_puntos_del_jugador();
protected:
    //! Paso base.2: Definimos Los metodos de busqueda para encontrar cada caso para victoria, lo hacemos dentor de la clase
    //! jugador y nos evitamos tener que sacar informacion privilegiada al main del juego como lo son los arreglos de tarjetas

    //? Metodo para el primer caso (mas de tres tarjetas con igual valor)
    [[nodiscard]] int metodo_busqueda_uno_caso_de_armada_con_igual_valor();
    //? Metodo para el segundo caso (mas de tres tarjetas con igual tipo)
    [[nodiscard]] int  metodo_busqueda_dos_caso_de_armada_con_igual_tipo();
    //? Metodo para el tercer caso (mas de tres tarjetas con rango consecutivo)
    [[nodiscard]] int metodo_busqueda_tres_caso_de_armada_con_rango_consecutivo();
    //? Metodo para limpiar los datos del jugador luego de haber jugado una partida

};
#endif //PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_JUGADOR_CLASS_H
