# Teclado 75 DataBlack

![teclado75](https://i.imgur.com/placeholder.png) <!-- Reemplaza esto con una imagen de tu teclado -->

Un teclado mecánico custom 75% con distribución ISO, basado en el microcontrolador STM32F401 (Blackpill) y con retroiluminación RGB Matrix completa (75 LEDs WS2812).

* **Keyboard Maintainer:** [Atomik0](https://github.com/Atomik0)
* **Hardware Supported:** PCB Teclado 75, Controlador STM32F401 (Blackpill)
* **Características:**
  * Distribución 75% ISO
  * 75 LEDs RGB individuales (WS2812)
  * Soporte completo para VIA y RAW HID
  * Efectos RGB Matrix avanzados

## Compilar el Firmware

Asegúrate de tener el entorno de QMK configurado. Para compilar el firmware por defecto para este teclado, ejecuta:

```bash
make teclado75:default
```

## Flashear el Firmware

Para flashear el firmware compilado en tu teclado, ejecuta el siguiente comando y pon tu teclado en modo bootloader cuando se te solicite:

```bash
make teclado75:default:flash
```

## Entrar al modo Bootloader (DFU)

Puedes entrar al bootloader de las siguientes maneras:

* **Bootmagic reset**: Mantén presionada la tecla en la posición (0,0) de la matriz (usualmente la tecla de Escape) mientras conectas el teclado por USB.
* **Botón físico de reset**: Presiona brevemente el botón `BOOT0` y luego el botón `NRST` en la placa Blackpill, o usa el botón de reset de la PCB si está disponible.
* **Código de tecla (Keycode)**: Si tienes la tecla `QK_BOOT` asignada en tu mapa de teclas, presiónala.

## Soporte VIA

Este teclado soporta configuración en tiempo real a través de [VIA](https://usevia.app/). Asegúrate de cargar el archivo `via.json` (ubicado en la raíz de este repositorio) en la pestaña "Design" de VIA si la placa aún no ha sido aprobada en el repositorio principal de VIA.
