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
/**-------------------------------------------
 * ? Main Program
-------------------------------------------**/

//! Implementacion de Constructores

pUno_Jugador_Class::pUno_Jugador_Class()
{

}

//? Implementacion de los metodos pertenecientes a base.2 por tanto, metodos  set y get y de registro de tarjetas

std::string pUno_Jugador_Class::get_nombre_jugador() const
{
    return this->nombre_jugador;
}
void pUno_Jugador_Class::set_nombre_jugador(std::string nuevo_nombre_jugador)
{
    try {
        if (nuevo_nombre_jugador.size() > 0) {
            this->nombre_jugador = nuevo_nombre_jugador;
        }
        else {throw std::invalid_argument("Error Code 0x001 [Raised] - El valor ingresado para @nuevo_nombre_jugador@ es invalido.\n");}
    }
    catch (std::invalid_argument &error)
    {
        std::cerr << "Error en el metodo set_nombre_jugador de la clase Jugador\n";
        std::cerr << error.what() << std::endl;
    }
}

int pUno_Jugador_Class::get_numero_de_victorias_jugador() const
{
    return this->numero_de_victorias_jugador;
}

pUno_Jugador_Class& pUno_Jugador_Class::aumentar_en_uno_las_victorias_del_jugador()
{
    //? Paso base: aumentar victorias en 1;
    this->numero_de_victorias_jugador +=1;

    //? Paso inductivo: retornar referencia a si mismo para contiunar con metodos en cadena
    return *this;
}

int pUno_Jugador_Class::get_cantidad_de_cartas_jugador() const
{
    return this->cantidad_de_cartas_jugador;
}

int pUno_Jugador_Class::get_cantidad_de_puntos_jugador() const
{
    return this->cantidad_de_puntos_jugador;
}

//? Metodo para registrar las tarjetas por nombre y por valor y tipo
pUno_Jugador_Class& pUno_Jugador_Class::aumentar_en_uno_las_cartas_del_jugador(
        std::string nombre_de_tarjeta_ingresada)
{
    //? Paso base: Como sabemos que el programa siempre genera tarjetas aleatorias debemos simplemente alocar
    //? este nombre al vector
    this->holder_para_nombres_de_tarjetas_jugador.push_back(nombre_de_tarjeta_ingresada);

    //? Paso Inductivo: Retornar referencia a si mismo para continuar con metodos en cadena
    return *this;
}

pUno_Jugador_Class& pUno_Jugador_Class::registar_tarjeta_completamente_basada_en_valor_y_tipo(int tipo_de_carta, int clan_de_la_carta)
{
    //? Paso base: como sabemos que el programa no envia tarjetas malas a los jugadores, podemos asumir que los valores van a ser correctos, aunque por
    //? redundanci podemos anadir otro caso de check por si acaso
    try {
        if ((tipo_de_carta >= 1 && tipo_de_carta <= 8) && (clan_de_la_carta >= 0 && clan_de_la_carta < 5))
        {
            //? Paso inductivo: Registrar la tarjeta en el vector de tarjetas del jugador
            this->holder_matriz_para_tarjetas_por_fila_y_columna.at(tipo_de_carta -1).at(clan_de_la_carta) = 1;
            this->cantidad_de_cartas_jugador +=1;
        }
        else if ( tipo_de_carta < 1 || tipo_de_carta > 8)
        {
            throw std::invalid_argument("Error Code 0x001 [Raised] - El valor ingresado para @tipo_de_carta@ es invalido.\n");
        }
        else if (clan_de_la_carta < 0 || clan_de_la_carta > 5)
        {
            throw std::invalid_argument("Error Code 0x001 [Raised] - El valor ingresado para @clan_de_la_carta@ es invalido.\n");
        }
        return *this;
    }
    catch (std::invalid_argument &error)
    {
        std::cerr << "Error en el metodo registar_tarjeta_completamente_basada_en_valor_y_tipo de la clase Jugador\n";
        std::cerr << error.what() << std::endl;
    }
}

//! Implementando metodo para cuantificar los puntos del usuario
void pUno_Jugador_Class::cuantificar_puntos_del_jugador()
{
    //?  Paso base: Llamamos a cada una de las funciones espeficias para cada metodo y cuantificamos su vor en una variable auto (tipo
    //? asignado en ejecucion: int)
     auto puntos_registrados_por_caso_1 =  pUno_Jugador_Class::metodo_busqueda_uno_caso_de_armada_con_igual_valor();
     auto puntos_registrados_por_caso_2 =  pUno_Jugador_Class::metodo_busqueda_dos_caso_de_armada_con_igual_tipo();
    auto puntos_registrados_por_caso_3 =  pUno_Jugador_Class::metodo_busqueda_tres_caso_de_armada_con_rango_consecutivo();

     //? Paso indutivo: sumamos todos los resultados, si hay alguno cero no habria problema porque solo no afecta al resultado, y de esta forma
     //? solo tenemos los valores de los casos que apliquen.
     this->cantidad_de_puntos_jugador = puntos_registrados_por_caso_1 + puntos_registrados_por_caso_2 + puntos_registrados_por_caso_3;
}


//! Implementacion de metodos adicionales para cuantificar por case los puntos del usuario.

int pUno_Jugador_Class::metodo_busqueda_uno_caso_de_armada_con_igual_valor()
{
   //? Paso base: Definimos una variable contadora que inicie en 0 y se translado usualmente desde 0,1,2 a 3 , si en
   //? una fila la cuenta no es de tres la reiniciamos y continuamos para la siguiente fila
    int counter_de_cartas_igual_valor{0};
    //? Paso inductivo: Movimiento a traves del arreglo por columnas actualizando el contador
    for(size_t fila_index = 0; fila_index < holder_matriz_para_tarjetas_por_fila_y_columna.size(); fila_index+=1)
    {
        int contador_de_cartas_por_igual_valor_movimiento_por_fila{0};
        for(size_t columna_index = 0; columna_index < holder_matriz_para_tarjetas_por_fila_y_columna.at(fila_index).size(); columna_index+=1)
        {
            if (holder_matriz_para_tarjetas_por_fila_y_columna.at(fila_index).at(columna_index) == 1)
            {contador_de_cartas_por_igual_valor_movimiento_por_fila +=1;}
        }
        if (contador_de_cartas_por_igual_valor_movimiento_por_fila >= 3) {counter_de_cartas_igual_valor += contador_de_cartas_por_igual_valor_movimiento_por_fila;}

    }
    return 7 * counter_de_cartas_igual_valor;
}

int pUno_Jugador_Class::metodo_busqueda_dos_caso_de_armada_con_igual_tipo()
{
    //? Paso base: definimos un contador que se va  a mover de 0,1,2,3 ... mientras haya tarjetas del mismo tipo en la misma
    //? columna, si se llega a mayor o igual que tres en esa misma columna se retorna el total * 5, si no continuamos con
    //? la siguiente columna.
    int counter_de_valores_igual_clan{0};

    //?  Paso inductivo: Movimiento a traves del arreglo por columnas
    for(size_t columna_index = 0; columna_index < holder_matriz_para_tarjetas_por_fila_y_columna.at(0).size(); columna_index+=1)
    {
        int contador_de_cartas_por_igual_tipo_movimiento_por_columna{0};
        for(size_t fila_index = 0; fila_index < holder_matriz_para_tarjetas_por_fila_y_columna.size(); fila_index+=1)
        {
            if (pUno_Jugador_Class::holder_matriz_para_tarjetas_por_fila_y_columna.at(fila_index).at(columna_index) == 1)
            {
                contador_de_cartas_por_igual_tipo_movimiento_por_columna +=1;
            }
        }
        if (contador_de_cartas_por_igual_tipo_movimiento_por_columna >= 3) { counter_de_valores_igual_clan +=contador_de_cartas_por_igual_tipo_movimiento_por_columna;}
    }
    return 5 * counter_de_valores_igual_clan;
}

int pUno_Jugador_Class::metodo_busqueda_tres_caso_de_armada_con_rango_consecutivo()
{
    //? Paso base: Para el tercer caso tenemos que mantener el mismo metodo de busqueda, pero tenemos que contabilizar
    //? las cartas iguales y ademas de esto notar su posicion en las columnas.
    int counter_tarjetas_con_valores_consecutivos{0};
    bool existe_continuidad_en_los_valores = true;
    int temp_for_holding_continuity{0};
    //? Paso inductivo:  Movimiento a traves del arreglo por filas chequeando valores en cada columna
    for(size_t fila_index = 0; fila_index < holder_matriz_para_tarjetas_por_fila_y_columna.size(); fila_index+=1)
    {
        bool hay_un_valor_en_la_fila = false;
        for(size_t columna_index = 0; columna_index < holder_matriz_para_tarjetas_por_fila_y_columna.at(fila_index).size(); columna_index+=1)
        {
            if (pUno_Jugador_Class::holder_matriz_para_tarjetas_por_fila_y_columna.at(fila_index).at(columna_index) == 1)
            {
                hay_un_valor_en_la_fila = true;
            }
        }
        if (hay_un_valor_en_la_fila) {counter_tarjetas_con_valores_consecutivos +=1;}
        else  if (hay_un_valor_en_la_fila == false && counter_tarjetas_con_valores_consecutivos !=0){
            temp_for_holding_continuity = counter_tarjetas_con_valores_consecutivos;
            counter_tarjetas_con_valores_consecutivos =0;}
    }

    //? Paso Inductivo.2: Debemos utilizar logica entre el temp de la continuidad y el valor que puede existir en la variable
    //? counter
    if ((counter_tarjetas_con_valores_consecutivos > temp_for_holding_continuity)
    && counter_tarjetas_con_valores_consecutivos >= 3)
    {
        return 3 * counter_tarjetas_con_valores_consecutivos;
    }
    else if ((temp_for_holding_continuity > counter_tarjetas_con_valores_consecutivos) && temp_for_holding_continuity >= 3)
    {
        return 3 * temp_for_holding_continuity;
    }

    return 0;
}


void pUno_Jugador_Class::imprimir_cartas_del_jugador()
{
    for(size_t index = 0; index < pUno_Jugador_Class::holder_para_nombres_de_tarjetas_jugador.size(); index+=1)
    {
        std::cout << pUno_Jugador_Class::holder_para_nombres_de_tarjetas_jugador.at(index) << std::endl;
    }
}

