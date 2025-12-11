# TM4C123 SUPERSTAR LCD — Rajinikanth Tribute

Bare-metal C demo for the **TM4C123GH6PM** (Tiva C) that runs a cinematic “SUPERSTAR RAJINIKANTH” intro on a 16x2 LCD.

## Features
- 8-bit parallel LCD (mixed GPIO ports A/B/D/E)
- Custom `Printdata()` bit-to-pin mapping
- Animated slow-reveal and right-to-left sliding text
- Bare-metal, no HAL libraries

## Wiring (summary)
Key mapping used in code:
- RS = PD0, RW = PD1, EN = PD2
- D0 = PA7, D1 = PA6, D2 = PA5
- D3 = PB4, D4 = PE5, D5 = PE4, D6 = PB1, D7 = PB0

## Build & Flash
### Code Composer Studio (CCS)
1. Create a new CCS project for TM4C123GH6PM.
2. Add `src/`, `inc/` to project.
3. Build and load via debug/Flash in CCS.


---
