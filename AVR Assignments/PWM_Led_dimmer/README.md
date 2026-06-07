# AVR PWM LED Brightness Control Using Timer0 (ATmega328P)

## Overview

This project demonstrates the use of the ATmega328P's hardware PWM feature to control LED brightness using Timer0 in Fast PWM mode. A push button is used to cycle through different PWM duty cycles, allowing the LED brightness to be adjusted without using software delays for PWM generation.

## Features

* Hardware PWM generation using Timer0
* Fast PWM mode configuration
* PWM output on OC0A (PD6)
* Push-button controlled brightness levels
* Five operating states:

  * 25% Duty Cycle
  * 50% Duty Cycle
  * 75% Duty Cycle
  * 100% Duty Cycle
  * OFF
* Modular design using a dedicated PWM update function

## Hardware Requirements

* ATmega328P Microcontroller
* LED
* 220 Ω Resistor
* Push Button
* Breadboard and Jumper Wires
* 5V Power Supply

## Circuit Connections

### LED Connection

PD6 (OC0A) → 220 Ω Resistor → LED → GND

### Push Button Connection

PD2 → Push Button → GND

Internal pull-up resistor is enabled in software.

## Working Principle

Timer0 is configured in Fast PWM mode. The PWM signal is generated on the OC0A pin (PD6). The duty cycle is controlled by modifying the Output Compare Register (OCR0A).

At startup, the LED operates at 25% brightness.

Each button press advances the duty cycle through the following sequence:

25% → 50% → 75% → 100% → OFF → Repeat

A dedicated function updates the OCR0A register according to the selected brightness level.

## Duty Cycle Values

| Brightness Level | OCR0A Value |
| ---------------- | ----------- |
| 25%              | 64          |
| 50%              | 128         |
| 75%              | 191         |
| 100%             | 255         |
| OFF              | 0           |

## Concepts Practiced

* AVR Register-Level Programming
* Timer0 Configuration
* Fast PWM Mode
* Hardware PWM Generation
* Duty Cycle Control
* Push Button Interfacing
* Embedded C Programming
* ATmega328P Peripheral Configuration

## Development Environment

* Microcontroller: ATmega328P
* IDE: Microchip Studio
* Language: Embedded C


## Learning Outcomes

Through this project, I gained hands-on experience with hardware PWM generation, timer configuration, and efficient brightness control using the ATmega328P. The project highlights how hardware peripherals can perform repetitive timing tasks independently, reducing CPU workload and improving system efficiency.
