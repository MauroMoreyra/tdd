# tdd
Test driven development

a) Listado de requerimientos funcionales de la librería sapi_oneWire

Debe manejar un bus de entrada / salida (gpio) para utilización de protocolo 1-Wire y comunicación con dispositivos del tipo iButton.
El bus debe ser configurable: se debe poder seleccionar cualquier GPIO provista en sAPI para EDU-CIAA-NXP, y también se debe poder seleccionar la velocidad del bus 1-Wire (velocidad standard o overdrive).
Debe proveer función leer y guardar los datos de ROM del dispositivo iButton.
La anterior función debe devolver el estado del bus 1-Wire.
Debe proveer función para detectar la presencia de un dispositivo iButton en el bus, devolviéndo 1 si hay presencia, 0 si no lo hay.


b) Listado de pruebas a realizar

1. Se puede configurar cualquier GPIO como master del bus 1-Wire.
2. Se puede configurar la velocidad del bus: standard o overdrive.
3. Se puede verificar si existe presencia de dispositivo iButton sobre el bus.
4. Se puede verificar si no existe presencia de dispositivo iButton sobre el bus.
5. Se pueden leer los datos de ROM de dispositivo iButton presente sobre el bus.


c) Creación del proyecto de Ceedling

En la carpeta del proyecto, se ejecutan los comandos:

$ ceedling new sapi_oneWire > creación del proyecto de Ceedling.
$ nano test/test_sapi_oneWire.c > creación del archivo de tests.

Generándose así:

Carpeta “vendor”: propio código de Ceedling.
Carpeta “test”: aca se deben poner los tests propios.
Archivo “project.yml”: en el que se pueden configurar opciones de Ceedling.

Además se indican los siguientes comandos de Ceedling que se usarán:

$ ceedling test:all > ejecuta todos los tests del proyecto.
$ ceedling clobber > limpia el proyecto.
$ ceedling gcov:all > genera reporte de coverage.

Otras consideraciones:

Todos los archivos y funciones de test deben comenzar con “test”.
