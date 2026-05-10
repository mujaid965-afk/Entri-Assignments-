# STM32 GPIO LED ASSIGNMENT

## OBJECTIVE
This assignment demonstrates GPIO driver development and GPIO interfacing using STM32 NUCLEO-F401RE board

The assignment is given as two tasks:
1. Button controlled onboard LED toggle
   ( Task 1: Button-Controlled LEDConfigure the onboard user button to toggle the onboard user LED .Pressing the button turns the LED on if off, or off if on. LED state persists after button release. Expected behavior: Single button press toggles LED state reliably without flickering.)
2. Alternating external LED blinking
   (Task 2: Alternating External LED BlinkSelect two GPIO pins as outputs (e.g., PA6 and PA7, or any available except onboard ones) and connect external LEDs.Blink the two LEDs alternately (one on while the other is off).Use a 500ms period per LED (250ms on, 250ms off each).Run this continuously in the main loop. Expected behavior: LEDs blink out of phase, creating a smooth alternating pattern)


# Components Used
- STM32 NUCLEO-F401RE
- 2 external leds
- 2 resistors
- jumper wires
- breadboard

# Pin Mapping 

| GPIO Pin | Function |
|----------|----------|
| PA5 | Onboard LED |
| PC13 | Onboard User Button |
| PA6 | External LED1 |
| PA7 | External LED2 |


---

# Task 1: Button controlled LED togggle 
## Description

The onboard user button (PC13) is used to toggle the onbaord LED (PA5)

- Pressing the button turns the LED ON if OFF
- Pressing the button turns the LED OFF if ON
- LED state remains after button release

---

# Task 2 : Alternaling External LED blinking

## Description

Two external LEDs connected to PA6 and PA7 blink alternately

- LED 1 ON -> LED2 OFF
- LED1 OFF -> LED2 ON

A delay function is used 

# External LED wiring 

- PA6 -> 220 ohm resistor -> LED1 anode
- PA6 -> 220 ohm resistor -> LED2 anode
- both LED cathode are connected to GND 

# GPIO driver APIs Used 

- GPIO_PeriClockControl()
- GPIO_Init()
- GPIO_ReadFromInputPin()
- GPIO_WriteToOutputPin()

---
# Delay 
A delay function named delay_ms was implemented using a for loop
```c
void delay_ms(uint32_t ms)
{
    uint32_t count = ms * 4000;

    for(uint32_t i = 0; i < count; i++);
}
```
Timers were not used as per assignment requirement 

# Observations
- Onboard LED toggles successfully using onboard user button
- External LEDs blink alternately
- GPIO driver functions successfully control GPIO peripherals

# IDE Used

STM32CubeIDE

# Board used

STM32 NUCLEO-F401RE





