# MentorBit-2Rele

Esta librería está diseñada para que puedas controlar **dos dispositivos eléctricos de forma independiente** usando tu placa MentorBit y el **módulo relé 2 canales**.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit de 2 Relés.](https://github.com/DigitalCodesign/MentorBit-2Rele/blob/main/assets/MentorBit_Relaymodule.png)

Con esta librería, podrás encender o apagar **dos luces, motores, bombas** o cualquier otro par de dispositivos eléctricos, de forma independiente, remota y segura.

---

## Descripción

### ¿Qué es un módulo de 2 relés?

Un relé es como un interruptor controlado electrónicamente. En este caso, tienes **dos interruptores** controlables desde tu placa MentorBit, permitiéndote manejar dos dispositivos distintos desde un mismo módulo. Puedes usarlos para encender o apagar dispositivos que trabajan con voltajes más altos (como 220V AC), mientras tu placa MentorBit trabaja con 5V de forma segura.

Este módulo aísla completamente la parte de potencia de la parte de control, garantizando la protección de tu MentorBit.

---

### ¿Qué hace esta librería?

La librería **MentorBit-2Rele** te permite controlar fácilmente ambos relés del módulo usando funciones independientes para cada canal. Solo necesitas indicar los pines y luego podrás activar o desactivar cada relé por separado con comandos sencillos.

---

### ¿Qué puedes construir con este módulo?

- Un sistema de riego con dos zonas independientes.
- Control de ventiladores o extractores por separado.
- Encendido de luces en diferentes momentos del día.
- Sistemas de seguridad con doble acción (alarma + corte de energía).

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo de 2 relés a uno de los puertos JST de 4 pines de la sección de "Puertos para Módulos" en la placa MentorBit. Usa dos pines digitales distintos para controlar cada canal del relé.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-2Rele*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-1Rele/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Controlar ambos relés

Este ejemplo enciende y apaga los dos relés alternadamente con un retardo de un segundo.

```cpp
#include <MentorBit2Rele.h>

// Definimos los pines para cada relé
#define RELAY1_PIN A4
#define RELAY2_PIN 24

// Creamos el objeto de la clase para dos relés
MentorBit2Rele dobleRele(RELAY1_PIN, RELAY2_PIN);

void setup() {
    Serial.begin(9600);
}

void loop() {
    dobleRele.activarRele1();
    Serial.println("Relé 1 ENCENDIDO.");
    delay(1000);

    dobleRele.desactivarRele1();
    Serial.println("Relé 1 APAGADO.");
    delay(1000);

    dobleRele.activarRele2();
    Serial.println("Relé 2 ENCENDIDO.");
    delay(1000);

    dobleRele.desactivarRele2();
    Serial.println("Relé 2 APAGADO.");
    delay(1000);
}
```

---

## Funciones Principales


Esta librería es muy fácil de usar. Solo necesitas conocer cuatro funciones clave:

- <code>void activarRele1()</code>  
   - **¿Qué hace?** Activa el relé 1 (cierra el circuito).  
   - **¿Cuándo se usa?** Cada vez que quieras encender el circuito de control.

- <code>void activarRele2()</code>  
   - **¿Qué hace?** Activa el relé 2 (cierra el circuito).  
   - **¿Cuándo se usa?** Cada vez que quieras encender el circuito de control.

- <code>void desactivarRele1()</code>  
   - **¿Qué hace?** Desactiva el relé 1 (abre el circuito).  
   - **¿Cuándo se usa?** Cuando quieras apagar el circuito de control.

- <code>void desactivarRele2()</code>  
   - **¿Qué hace?** Desactiva el relé 2 (abre el circuito).  
   - **¿Cuándo se usa?** Cuando quieras apagar el circuito de control.

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial de MentorBit módulo de 2 relés](https://canarias.digitalcodesign.com/shop/00038928-mentorbit-modulo-rele-2-canales-8123?category=230&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1IgPJw0743FHQ9CCuSZd_HdKZG-OnqQ7a/view?usp=drive_link)
- [Modelo 3D del Módulo de 2 Relés en formato .STEP](https://drive.google.com/file/d/1cG8Wpu2K46mxCWLIp_kijiz0fwmHjLWd/view?usp=drive_link)
