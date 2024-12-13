

# MentorBit 2 Rele

## Descripción

Esta librería está específicamente diseñada para ser utilizada junto con el módulo **MentorBit Rele de dos canales**.

El módulo **MentorBit Rele de dos canales** permite controlar dos relés independientemente. Puedes activar o desactivar cada relé según sea necesario utilizando los métodos proporcionados.

## Modo de Empleo

Una vez que tengas la librería instalada desde el Arduino IDE, inclúyela en tu proyecto con la siguiente línea:

```cpp
#include <MentorBit2Rele.h>
```

### Constructor

Una vez incluida la librería, usamos el constructor para crear el objeto del módulo de relé de dos canales, y definir los pines a los que están conectados los dos relés:

```cpp
MentorBit2Rele rele(PIN_RELE1, PIN_RELE2);
```

Donde `PIN_RELE1` es el pin al que está conectado el primer relé y `PIN_RELE2` es el pin al que está conectado el segundo relé.

### Métodos Principales

#### `activarRele(bool rele)`

Activa la bobina del relé seleccionado:

- `rele == true` → Activa el primer relé.
- `rele == false` → Activa el segundo relé.

```cpp
rele.activarRele(true);  // Activa el primer relé
rele.activarRele(false); // Activa el segundo relé
```

#### `desactivarRele(bool rele)`

Desactiva la bobina del relé seleccionado:

- `rele == true` → Desactiva el primer relé.
- `rele == false` → Desactiva el segundo relé.

```cpp
rele.desactivarRele(true);  // Desactiva el primer relé
rele.desactivarRele(false); // Desactiva el segundo relé
```

#### `configPort(const Port& port)`

Configura los puertos y pines de los relés. Se pueden especificar los pines para ambos relés.

```cpp
Port port;
port.gpios[0] = 7;  // Pin del primer relé
port.gpios[1] = 8;  // Pin del segundo relé
rele.configPort(port);
```

##### Parámetros

- `port`: Estructura que contiene la configuración del puerto, tipo, ubicación y pines de los relés.

## Atributos

- `RELE_1` → Selecciona el primer relé.
- `RELE_2` → Selecciona el segundo relé.
