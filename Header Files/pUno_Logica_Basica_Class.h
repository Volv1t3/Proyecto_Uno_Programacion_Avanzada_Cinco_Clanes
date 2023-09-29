/**------------------------------------------------------------------------------------------------
 * ?                                           ABOUT
 * @authors        :  Leonardo Olmedo (327960); Santiago Arellano (328370)
 * @clase          :  Programacion Avanzada en C++
 * @createdOn      :  27-09-23
 * @description    :  Archivo de Definicion de la estructura de la clase Logica Basica
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



#ifndef PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_LOGICA_BASICA_CLASS_H
#define PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_LOGICA_BASICA_CLASS_H
//! A continuacion esta la definicion del esqueleto de la clase para Logica Basica

struct Tarjeta_Jugada
{
    int valor_de_carta{0};
    std::string nombre_de_la_carta;
    int clan_de_la_carta{0};
};

class pUno_Logica_Basica_Class
{
private:
    //! Paso base.1: Declaracion de las varaibles constantes para la logica funcional del programa
    std::array<int, 40> holder_para_los_numeros_reales_de_cada_tarjeta;
    const std::array<std::string,5>  clanes_definidos_para_el_juego{"Luna","Sol","Agua","Cruz","Espada"};

    //! Paso base.2: Declaraciond e los holders para las tarjetas usadas, por usar y la cantidad de tarjetas que existen en una
    //! partida
    std::array<std::array<int,5>,8> cartas_que_ya_fueron_jugadas;
    std::vector<int> indices_que_ya_fueron_jugados;

    //! Paso base.3: Declaracion de las variables constantes para la ejecucion del juego.
    static const int cantidad_de_tarjetas_por_palo{8}, cantidad_de_tipos_de_tarjetas{5},
    cantidad_de_tarjetas_por_partida{40}, cantidad_de_tarjetas_por_jugador{8};

public:
    //! Constructor para crear objetos con tarjetas al iniicializar
    pUno_Logica_Basica_Class();
    //! Definicion de los metodos para logica basica, no se plantea constructor ya que esta clase no requiere de valores
    //! adicionales para trabajar, solo necesita sus valore estaticos y sus arreglos
    void generar_tarjetas_procedure_generation();
    void mezclar_tarjetas_shuffle_random();
     Tarjeta_Jugada seleccionar_una_tarjeta_y_retornar_struct();
    void reiniciar_arreglo_de_tarjetas_jugadas();

protected: /* Esta seccion se utilizara para definir metodos que solo los archivos publicos necesitan, es decir, funciones
utilitie secundarias*/
    bool revisar_si_la_tarjeta_ya_fue_jugada(int peso_de_la_tarjeta, int palo_de_la_tarjeta);

};

#endif //PROYECTO_UNO_PROGRAMACION_AVANZADA_CINCO_CLANES_PUNO_LOGICA_BASICA_CLASS_H
