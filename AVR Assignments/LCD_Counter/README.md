# LCD Counter with Short Press and Long Press Detection

## Objective

Design and implement a counter system using an ATmega328P microcontroller and a 16x2 LCD.

### Requirements

* Display a 9-digit counter on the LCD.
* Short button press increments the counter.
* Long button press (2 seconds or more) resets the counter.
* Use internal pull-up resistor for the push button.
* Implement the LCD using 4-bit mode.
* Use modular programming.

---

## Hardware Used

* ATmega328P
* JHD162A 16x2 LCD
* Push Button
* 10k Potentiometer
* Breadboard
* Jumper Wires

---

## LCD Connections

| LCD Pin | Function | ATmega328P Pin      |
| ------- | -------- | ------------------- |
| 4       | RS       | PB0                 |
| 6       | EN       | PB1                 |
| 11      | D4       | PB2                 |
| 12      | D5       | PB3                 |
| 13      | D6       | PB4                 |
| 14      | D7       | PB5                 |
| 5       | RW       | GND                 |
| 1       | VSS      | GND                 |
| 2       | VDD      | +5V                 |
| 3       | VO       | Potentiometer Wiper |

### Potentiometer

* One end → +5V
* One end → GND
* Middle pin → LCD Pin 3 (VO)

---

## Push Button Connection

| Component      | Pin |
| -------------- | --- |
| Push Button    | PD2 |
| Other Terminal | GND |

Internal pull-up resistor is enabled in software.

---

## Project Structure

```text
LCD_Counter
│
├── main.c
├── lcd.c
├── lcd.h
└── README.md
```

---

## Working

### Initial Display

```text
000000000
```

### Short Press

Each short press increments the counter.

```text
000000001
000000002
000000003
```

### Long Press

Holding the button for 2 seconds or more resets the counter.

```text
000000157
```

becomes

```text
000000000
```

---

## Software Used

* Microchip Studio

---

## Concepts Used

* GPIO Programming
* LCD Interfacing (4-bit Mode)
* Internal Pull-Up Resistor
* Switch Debouncing
* Long Press Detection
* Modular Programming
* Embedded C




