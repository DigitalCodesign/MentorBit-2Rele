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

#include <MentorBit2Rele.h>

/**
 * @brief Constructor de la clase MentorBit2Rele.
 * Asigna los pines de control para cada relé. Evalúa cada pin de forma independiente 
 * y asegura que comiencen apagados (LOW) por seguridad.
 * @param pin_rele1 Pin digital para el primer relé (por defecto 0, inactivo).
 * @param pin_rele2 Pin digital para el segundo relé (por defecto 0, inactivo).
 */
MentorBit2Rele::MentorBit2Rele(uint8_t pin_rele1 = 0, uint8_t pin_rele2 = 0)
    : _estado_rele1(false), _estado_rele2(false) {

    _port.gpios[0] = pin_rele1;
    _port.gpios[1] = pin_rele2;

    if(pin_rele1) {
        pinMode(_port.gpios[0],OUTPUT);
        digitalWrite(_port.gpios[0], LOW);
    }

    if(pin_rele2) {
        pinMode(_port.gpios[1],OUTPUT);
        digitalWrite(_port.gpios[1], LOW);
    }

}

/**
 * @brief Configura el puerto de hardware asociado al módulo.
 * Define internamente los pines asignados como salidas (OUTPUT). Por seguridad, 
 * fuerza el estado de ambos relés a apagado inmediatamente después de la configuración.
 * @param port Estructura constante por referencia con la configuración del puerto.
 */
void MentorBit2Rele::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

    pinMode(_port.gpios[0],OUTPUT);
    pinMode(_port.gpios[1],OUTPUT);
    desactivarAmbos();

}

/**
 * @brief Activa la bobina electromagnética del relé especificado.
 * Envía una señal HIGH al pin correspondiente, cerrando el circuito de potencia.
 * @param rele Canal a activar (utilizar RELE_1 o RELE_2).
 */
void MentorBit2Rele::activarRele(Rele rele) {

    if (rele == RELE_1) {
        digitalWrite(_port.gpios[0], HIGH);
        _estado_rele1 = true;
    } else if (rele == RELE_2) {
        digitalWrite(_port.gpios[1], HIGH);
        _estado_rele2 = true;
    }

}

/**
 * @brief Desactiva la bobina electromagnética del relé especificado.
 * Envía una señal LOW al pin correspondiente, abriendo el circuito de potencia.
 * @param rele Canal a desactivar (utilizar RELE_1 o RELE_2).
 */
void MentorBit2Rele::desactivarRele(Rele rele) {

    if (rele == RELE_1) {
        digitalWrite(_port.gpios[0], LOW);
        _estado_rele1 = false;
    } else if (rele == RELE_2) {
        digitalWrite(_port.gpios[1], LOW);
        _estado_rele2 = false;
    }

}

/**
 * @brief Cambia el estado actual del relé especificado al opuesto.
 * Si el relé seleccionado está activado, lo apaga; si está apagado, lo enciende.
 * @param rele Canal a conmutar (utilizar RELE_1 o RELE_2).
 */
void MentorBit2Rele::conmutar(Rele rele) {

    if(rele == RELE_1) {
        _estado_rele1 ? desactivarRele(RELE_1) : activarRele(RELE_1);
    } else if (rele == RELE_2) {
        _estado_rele2 ? desactivarRele(RELE_2) : activarRele(RELE_2);
    }

}

/**
 * @brief Activa simultáneamente ambos relés.
 * Método de conveniencia útil para puentes H o encendido masivo de sistemas.
 */
void MentorBit2Rele::activarAmbos() {

    activarRele(RELE_1);
    activarRele(RELE_2);

}

/**
 * @brief Desactiva simultáneamente ambos relés.
 * Método de seguridad y conveniencia para garantizar un apagado total del módulo.
 */
void MentorBit2Rele::desactivarAmbos() {

    desactivarRele(RELE_1);
    desactivarRele(RELE_2);

}

/**
 * @brief Comprueba si un relé específico se encuentra actualmente activado.
 * Lee una variable de estado interna, optimizando la velocidad de respuesta.
 * @param rele Canal a consultar (utilizar RELE_1 o RELE_2).
 * @return true si el relé consultado está encendido, false si está apagado.
 */
bool MentorBit2Rele::estaActivo(Rele rele) const {

    if(rele == RELE_1) return _estado_rele1;
    else if (rele == RELE_2) return _estado_rele2;

}
