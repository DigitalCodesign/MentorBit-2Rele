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
MentorBit2Rele::MentorBit2Rele(uint8_t pin_rele1, uint8_t pin_rele2){
    _rele_1_pin = pin_rele1;
    _rele_2_pin = pin_rele2;
    pinMode(_rele_1_pin,OUTPUT);
    pinMode(_rele_2_pin,OUTPUT);
}

/*
    Funcion que permite activar la bobina del rele
*/
void MentorBit2Rele::activarRele(bool rele){
    if(rele){
        digitalWrite(_rele_1_pin,HIGH);
    }
    else{
        digitalWrite(_rele_2_pin,HIGH);
    }
}

/*
    Funcion que permite desactivar la bobina del rele
*/
void MentorBit2Rele::desactivarRele(bool rele){
    if(rele){
        digitalWrite(_rele_1_pin,LOW);
    }
    else{
        digitalWrite(_rele_2_pin,LOW);
    }
}