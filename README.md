# Amirmobil – Amphibious Vehicle (Legacy Code)

**Arduino-based RC car + boat hybrid**  
*Older version – manual control without Bluetooth*

---

## About this project

**Amirmobil** is an amphibious vehicle I built.  
It has:

- **Wheels** for driving on land  
- **Propellers / fins** for moving in water  
- **Two servos** that switch modes:  
  - On land: wheels down → propellers up  
  - In water: wheels up → propellers down  

The switch is done manually (based on where you place the vehicle) or via a sensor (not implemented in this version).

The vehicle is controlled by a **joystick** (two axes: X and Y) that drives two DC motors (left and right tracks / wheels).

This is the **legacy code** – messy but working.  
The new version uses Bluetooth. This one is raw, direct, and no‑nonsense.

---

## Features

- **Joystick control** (analog X/Y) with variable speed (5 levels + stop)  
- **Two motor controllers** (L298N or similar)  
- **Mode switching servos** (land ↔ water)  
- **Status LED**  
- **Serial debug output** (for tuning)

---

## Hardware (simplified)

| Component        | Pin(s)                     |
|------------------|----------------------------|
| Servo 1 (mode)   | 10                         |
| Servo 2 (mode)   | 9                          |
| Motor A (right)  | in1=3, in2=4, en1=5        |
| Motor B (left)   | in3=6, in4=7, en2=8        |
| Joystick X       | A1                         |
| Joystick Y       | A0                         |
| Mode trigger     | A5 (digital, for servos)   |
| LED indicator    | 13                         |

---

## How it works (code logic)

1. **Servo mode switching**  
   - When `A5 == HIGH` → both servos go to `180°` (water mode)  
   - When `A5 == LOW` → both servos go to `0°` (land mode)

2. **Joystick → motor control**  
   The joystick position (X, Y) is read as an analog value (0–1023).  
   The code maps the stick into five speed zones for each direction:

   | Direction | Speed level | Analog range (Y or X) |
   |-----------|-------------|------------------------|
   | Forward   | a (slowest) | 388–485                |
   |           | b           | 291–388                |
   |           | c           | 194–291                |
   |           | d           | 97–194                 |
   |           | e (fastest) | < 97                   |
   | Backward  | a … e       | 485–540, 540–550, 550–700, 700–800, 800–900, >900 |
   | Stop      | 0           | 485–540 (X and Y in center zone) |

   Almost the same logic is applied to **forward/backward and left/right turning** by mixing X and Y values.

3. **LED control**  
   - Button on `A4` toggles an LED on/off (pins 11, 12).

---

## Code status

- **Messy** – many nested `if/else`, large duplicated blocks, unused commented loops.  
- **But it works** – the vehicle drives and switches modes.  
- **No Bluetooth** – this is the raw, manual version. The new version is cleaner and wireless.

---

## Why I keep this code

It’s a reminder of where I started with embedded systems:  
- No libraries, no clean architecture.  
- Just hardware, a joystick, and a lot of trial & error.

**Amirmobil taught me:**  
- How to read analog sensors  
- How to control DC motors with PWM  
- How to use servos for mechanical switching  
- That messy code can still move a machine

---

## See also

- [ASR – Amirali Smart Room](https://github.com/amiraligrr/ASR) – my smart room control system  
- [Smart Trash Can](https://github.com/amiraligrr/smart-trash-can) – servo‑based trash can  
- [ZP-lang-Framework](https://github.com/amiraligrr/ZP-lang-Framework) – code in your mother tongue  
- [amirali-dev](https://github.com/amiraligrr/amirali-dev) – my personal portfolio
- https://amiraligrr.ir

---

**Built by Amirali – 16 years old. Wheels or water, I build both.**
