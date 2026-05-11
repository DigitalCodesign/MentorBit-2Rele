/*


            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    @author Digital Codesign
    @version 1.1.0
    @date Fecha de creación: Septiembre de 2024
    @date Fecha de versión: Mayo de 2026
    @see Repositorio: https://github.com/DigitalCodesign/MentorBit-2Rele
    * @brief Descripción: 
    Esta librería está específicamente diseñada para ser utilizada junto con 
    el módulo MentorBit Relé de dos canales. Se ha optimizado para garantizar 
    una inicialización de hardware segura e independiente para cada canal, 
    evitando arranques indeseados y mejorando la legibilidad del código.
    * @details Métodos principales:
        - MentorBit2Rele  -> Constructor de la clase.
        - activarRele     -> Activa la bobina del relé seleccionado.
        - desactivarRele  -> Apaga la bobina del relé seleccionado.
    * Métodos extendidos y de control (Quality of Life):
        - conmutar        -> Invierte el estado actual del relé seleccionado.
        - activarAmbos    -> Activa simultáneamente ambos relés (ideal para control de motores).
        - desactivarAmbos -> Apaga de forma segura y simultánea ambos relés.
        - estaActivo      -> Consulta el estado lógico interno de un relé sin leer el hardware.
    * Atributos (Enumeradores):
        - RELE_1          -> Selecciona el primer relé (conectado al primer GPIO).
        - RELE_2          -> Selecciona el segundo relé (conectado al segundo GPIO).

*/

#ifndef MentorBit2Rele_h
#define MentorBit2Rele_h

#include <Arduino.h>
#include <MentorPort.h>

class MentorBit2Rele : public MentorPort {

    public: 

        enum Rele { RELE_1, RELE_2 };

        MentorBit2Rele(uint8_t pin_rele1 = 0, uint8_t pin_rele2 = 0);

        void configPort(const Port& port) override;

        void activarRele(Rele rele);
        void desactivarRele(Rele rele);
        void conmutar(Rele rele);
        void activarAmbos();
        void desactivarAmbos();
        bool estaActivo(Rele rele) const;

    private:

        Port _port;
        bool _estado_rele1;
        bool _estado_rele2;

};

#endif