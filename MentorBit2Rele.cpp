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
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Septiembre de 2024
    Fecha de version: Septiembre de 2024
    Repositorio: https://github.com/DigitalCodesign/MentorBit-2Rele
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit Rele de dos canales.
    Metodos principales:
        MentorBitRele -> constructor de la clase
        activarRele -> activa la bobina del rele seleccionado
        desactivarRele -> apaga la bobina del rele seleccionado
    Atributos:
        RELE_1 -> selecciona el rele 1 en los metodos
        RELE_2 -> selecciona el rele 2 en los metodos

*/

#include <MentorBit2Rele.h>

/*  
    Constructor, se debe indicar el pin al cual se esta conectando el modulo rele
*/
MentorBit2Rele::MentorBit2Rele(uint8_t pin_rele1 = 0, uint8_t pin_rele2 = 0) {
    _port.gpios[0] = pin_rele1;
    _port.gpios[1] = pin_rele2;
    if(pin_rele1 && pin_rele2) {
        pinMode(_port.gpios[0],OUTPUT);
        pinMode(_port.gpios[1],OUTPUT);
    }
}

/*
    Funcion que permite activar la bobina del rele
*/
void MentorBit2Rele::activarRele(bool rele) {
    if(rele){
        digitalWrite(_port.gpios[0],HIGH);
    }
    else{
        digitalWrite(_port.gpios[1],HIGH);
    }
}

/*
    Funcion que permite desactivar la bobina del rele
*/
void MentorBit2Rele::desactivarRele(bool rele) {
    if(rele){
        digitalWrite(_port.gpios[0],LOW);
    }
    else{
        digitalWrite(_port.gpios[1],LOW);
    }
}

void MentorBit2Rele::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

    pinMode(_port.gpios[0],OUTPUT);
    pinMode(_port.gpios[1],OUTPUT);

}
