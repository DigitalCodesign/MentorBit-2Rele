# MentorBit2Rele

Librería para el control de módulos de dos relés compatibles con MentorBit.

## Descripción

La librería `MentorBit2Rele` permite controlar módulos de dos relés compatibles con MentorBit. Facilita la activación y desactivación individual de cada relé, ideal para proyectos que requieren el control de múltiples dispositivos.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBit2Rele" e instálala.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBit2Rele.h>

    MentorBit2Rele rele(2, 3); // Inicializa los relés en los pines 2 y 3

    void setup() {
      rele.activarRele(true);  // Activa el relé 1 (pin 2)
      delay(2000);
      rele.desactivarRele(true); // Desactiva el relé 1
      delay(1000);
      rele.activarRele(false); // Activa el relé 2 (pin 3)
      delay(2000);
      rele.desactivarRele(false); // Desactiva el relé 2
    }

    void loop() {
      // Los relés se activan y desactivan secuencialmente una vez en el setup.
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBit2Rele(uint8_t pin_rele1 = 0, uint8_t pin_rele2 = 0)`: Crea un objeto `MentorBit2Rele`.
    * `pin_rele1`: Número de pin al que está conectado el primer relé. Si no se especifica, se asume que no está conectado a ningún pin inicialmente.
    * `pin_rele2`: Número de pin al que está conectado el segundo relé. Si no se especifica, se asume que no está conectado a ningún pin inicialmente.

### Métodos

* `void activarRele(bool rele)`: Activa el relé especificado.
    * `rele`: `true` para activar el primer relé, `false` para el segundo.
* `void desactivarRele(bool rele)`: Desactiva el relé especificado.
    * `rele`: `true` para desactivar el primer relé, `false` para el segundo.
