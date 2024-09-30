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
        Este sketch muestra un ejemplo sencillo de como programar el MentorBit para energizar
        la bobina del rele y por consiguiente cerrar o abrir los contactos del rele. Para este
        modulo es necesario indicar que rele se desea accionar.

*/

// Se incluye la libreria MentorBitRele
#include <MentorBit2Rele.h>

// Se define el pin al cual se va a conectar el modulo rele
#define PIN_RELE_1 24
#define PIN_RELE_2 A4

// Se crea el objeto Rele de la clase MentorBitRele
MentorBit2Rele rele(PIN_RELE_1,PIN_RELE_2);

void setup(){
    // Se inicializa el monitor serial a una velocidad de 9600 baudios
    Serial.begin(9600);
}

void loop(){
    Serial.println("Activando bobina del rele");
    rele.activarRele(rele.RELE_1);
    delay(5000);
    Serial.println("Desactivando bobina del rele");
    rele.desactivarRele(rele.RELE_1);
    delay(5000);
}