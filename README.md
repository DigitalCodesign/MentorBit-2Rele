
# MentorBit-2Rele

## Descripción

Esta librería está específicamente diseñada para ser utilizada junto con el módulo **MentorBit Rele de dos canales**.

El módulo **MentorBit Rele de dos canales** permite controlar dos relés independientemente. Puedes activar o desactivar cada relé según sea necesario utilizando los métodos proporcionados.

Puedes encontrar nuestro Módulo MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

## Métodos Principales

- `MentorBit2Rele` → Constructor de la clase, permite configurar los pines de conexión de los dos relés.
- `activarRele` → Activa la bobina de un relé seleccionado.
- `desactivarRele` → Desactiva la bobina de un relé seleccionado.

## Atributos

- `RELE_1` → Selecciona el primer relé.
- `RELE_2` → Selecciona el segundo relé.

## Constructor

```cpp
MentorBit2Rele miModuloReles(pin_rele1, pin_rele2);
```

Donde "pin_rele1" y "pin_rele2" son los puertos donde está conectado el Módulo de Relé de dos canales para controlarlos.

### Métodos

### `void activarRele(bool rele)`

Activa la bobina del relé seleccionado:
- `rele == true` → Activa el primer relé.
- `rele == false` → Activa el segundo relé.

### `void desactivarRele(bool rele)`

Desactiva la bobina del relé seleccionado:
- `rele == true` → Desactiva el primer relé.
- `rele == false` → Desactiva el segundo relé.
