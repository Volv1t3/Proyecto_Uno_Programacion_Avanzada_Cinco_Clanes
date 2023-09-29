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
#include <algorithm>
#include <random>
#include "./../Header Files/pUno_Logica_Basica_Class.h"

/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/

pUno_Logica_Basica_Class::pUno_Logica_Basica_Class()
{
    pUno_Logica_Basica_Class::generar_tarjetas_procedure_generation();
    pUno_Logica_Basica_Class::mezclar_tarjetas_shuffle_random();
}

//! Implementacion de los Metodos Protected primero ya que otras funciones de public dependeran de ellos

bool pUno_Logica_Basica_Class::revisar_si_la_tarjeta_ya_fue_jugada(int peso_de_la_tarjeta, int palo_de_la_tarjeta)
{
    //? Paso Inductivo.2: Enviamos los resultados independientenmente de que hayan todas las tarjetas o de que solo sea el caso, la funcion decide
    //? cual de los casos se aplica a traves de un ||

    if (pUno_Logica_Basica_Class::cartas_que_ya_fueron_jugadas.at(peso_de_la_tarjeta).at(palo_de_la_tarjeta) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pUno_Logica_Basica_Class::reiniciar_arreglo_de_tarjetas_jugadas() {
    //? Paso Base: Inicializamos un for loop para limpar todo el arreglo de Tarjetas ya usadas, volviendolos a cero, que es su valor de
   //? no utilizacion.

   for (std::size_t fila = 0; fila < pUno_Logica_Basica_Class::cantidad_de_tarjetas_por_palo; fila +=1)
   {
       for(std::size_t columna = 0; columna < pUno_Logica_Basica_Class::cantidad_de_tipos_de_tarjetas; columna +=1)
       {
        pUno_Logica_Basica_Class::cartas_que_ya_fueron_jugadas.at(fila).at(columna) = 0;
       }
   }
    //? Paso Inductivo: Limpiamos el vector de indices que ya fueron jugados.
   pUno_Logica_Basica_Class::indices_que_ya_fueron_jugados.clear();
}

//! Implementacion de los metodos publicos para la Clase Logica Basica

void pUno_Logica_Basica_Class::generar_tarjetas_procedure_generation()
{
    //? Como tenemos que trabajar con valores de peso de cartas basados en la localizacion en el arreglo tenemos que generar
    //? un arreglo que nos permite encontrar  simplemente el valor teniendo en cuenta el modulo y el tipo basado en la division

    for(std::size_t index = 0; index < pUno_Logica_Basica_Class::cantidad_de_tarjetas_por_partida; index +=1)
    {
        pUno_Logica_Basica_Class::holder_para_los_numeros_reales_de_cada_tarjeta.at(index) = index;
    }

    //? En base a este metodo simplemente creamos tarjetascon valores desde 0 a 40, y con el modulo 5 obtendremos valores desde 0 hasta 7 con
    // ?retorno normal y solo le sumamos 1 para obtener el valor real.
}

void pUno_Logica_Basica_Class::mezclar_tarjetas_shuffle_random()
{
    //? Paso base: Para organizar las tarjetas aleatoriamente podemos utilizar la libreria random y la libreria algorithm,
    //? las cualaes presentan metodos para generar aleatoriedad con funciones matematicas complejas independientes del tiempo como
    //? rand.

    std::random_device random_device_para_shuffle_de_tarjetas;
    std::mt19937 generador_mt_de_tarjetas_random(random_device_para_shuffle_de_tarjetas());

    //? Paso Inductivo: Para mezclar las tarjetas utilizamos la funcion shuffle de la libreria algorithm.

    std::shuffle(pUno_Logica_Basica_Class::holder_para_los_numeros_reales_de_cada_tarjeta.begin(),
                 pUno_Logica_Basica_Class::holder_para_los_numeros_reales_de_cada_tarjeta.end(),
                 generador_mt_de_tarjetas_random);
}


Tarjeta_Jugada pUno_Logica_Basica_Class::seleccionar_una_tarjeta_y_retornar_struct()
{
    //? Paso base.1: Definimos un struct para retornar el valor de la tarjeta elegida.
    Tarjeta_Jugada objeto_tarjeta_de_retorno_a_user;

    //? Paso base.2: Definimos de nuevo un metodo de random para poder generar indices aleatorios y obtener  tarjetas diferentes
    //? cada vez

    std::random_device random_device_para_seleccion_de_tarjetas;
    std::mt19937 generador_mt_de_tarjetas_random(random_device_para_seleccion_de_tarjetas());
    std::uniform_int_distribution<int> distribution_de_tarjetas_random(0, 39);
    int index_de_tarjeta_random = distribution_de_tarjetas_random(generador_mt_de_tarjetas_random);
    int tarjeta_en_index_obtenido_a_anadir = pUno_Logica_Basica_Class::holder_para_los_numeros_reales_de_cada_tarjeta.at(index_de_tarjeta_random);
    pUno_Logica_Basica_Class::indices_que_ya_fueron_jugados.push_back(tarjeta_en_index_obtenido_a_anadir);



    //? Paso base.3:  Chequeo de Redundancia base, que pasa si los indices usados ya son cuarenta?
    if (pUno_Logica_Basica_Class::indices_que_ya_fueron_jugados.size() == 40)
    {
        pUno_Logica_Basica_Class::reiniciar_arreglo_de_tarjetas_jugadas();
        objeto_tarjeta_de_retorno_a_user.clan_de_la_carta = -1;
        objeto_tarjeta_de_retorno_a_user.valor_de_carta = -1;
        objeto_tarjeta_de_retorno_a_user.nombre_de_la_carta = "40 Tarjetas Jugadas";

        return objeto_tarjeta_de_retorno_a_user;
    }


    //? Paso Inductivo.1: Definimos variables base para generar el struct, y luego
    int valor_de_la_carta{0};
    std::string nombre_calculado_de_la_carta;
    int peso_de_la_carta_calculado = {tarjeta_en_index_obtenido_a_anadir % pUno_Logica_Basica_Class::cantidad_de_tarjetas_por_palo};
    switch(peso_de_la_carta_calculado)
    {
        case 0: {valor_de_la_carta = 1; break;}
        case 1: {valor_de_la_carta = 2; break;}
        case 2: {valor_de_la_carta = 3; break;}
        case 3: {valor_de_la_carta = 4; break;}
        case 4:  {valor_de_la_carta = 5; break;}
        case 5: {valor_de_la_carta = 6; break;}
        case 6: {valor_de_la_carta = 7; break;}
        case 7: {valor_de_la_carta = 8; break;}
        default: {valor_de_la_carta = -1; break; /*Aqui no deberia entrar [[debug]]*/}
    }

    //? Paso Inductivo.2: Definimos el nombre de la carta basada en la division por cantidad de cartas
    int indicador_de_tipo_de_carta_basado_en_numero{0};
    int tipo_de_carta_calculado{tarjeta_en_index_obtenido_a_anadir / pUno_Logica_Basica_Class::cantidad_de_tarjetas_por_palo};
    switch(tipo_de_carta_calculado)
    {
        case 0:
        {
            nombre_calculado_de_la_carta = std::to_string(valor_de_la_carta) + " de Luna";
            indicador_de_tipo_de_carta_basado_en_numero = 0;
            break;
        }
        case 1:
        {
            nombre_calculado_de_la_carta = std::to_string(valor_de_la_carta) + " de Sol";
            indicador_de_tipo_de_carta_basado_en_numero = 1;
            break;
        }
        case 2:
        {
            nombre_calculado_de_la_carta = std::to_string(valor_de_la_carta) + " de Agua";
            indicador_de_tipo_de_carta_basado_en_numero = 2;
            break;
        }
        case 3:
        {
            nombre_calculado_de_la_carta = std::to_string(valor_de_la_carta) + " de Cruz";
            indicador_de_tipo_de_carta_basado_en_numero = 3;
            break;
        }
        case 4:
        {
            nombre_calculado_de_la_carta = std::to_string(valor_de_la_carta) + " de Espada";
            indicador_de_tipo_de_carta_basado_en_numero = 4;
            break;
        }
        default: [[debug]]
        {
            nombre_calculado_de_la_carta = "Aqui no se debe llegar";
            indicador_de_tipo_de_carta_basado_en_numero = -1;
            break;
        }

    }

    // ? Paso Inductivo.3: Revisamos por cuarta vez: que pasa si todo lo generado y las seguridades fallan, acaso mandamos
    //? otra tarjeta mala?

    auto flow_control = pUno_Logica_Basica_Class::
            revisar_si_la_tarjeta_ya_fue_jugada(peso_de_la_carta_calculado, tipo_de_carta_calculado);

    if (flow_control == false)
    {
        pUno_Logica_Basica_Class::cartas_que_ya_fueron_jugadas
        .at(peso_de_la_carta_calculado).at(tipo_de_carta_calculado) = 1;
        objeto_tarjeta_de_retorno_a_user.nombre_de_la_carta = nombre_calculado_de_la_carta;
        objeto_tarjeta_de_retorno_a_user.valor_de_carta = valor_de_la_carta;
        objeto_tarjeta_de_retorno_a_user.clan_de_la_carta = tipo_de_carta_calculado;
        return objeto_tarjeta_de_retorno_a_user;
    }
    else if (flow_control == true)
    {
        pUno_Logica_Basica_Class::indices_que_ya_fueron_jugados.pop_back();
        return pUno_Logica_Basica_Class::seleccionar_una_tarjeta_y_retornar_struct();
    }
}