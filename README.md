# Arduino Pong Game

## Description

A simple Pong game for Arduino using a 16x2 LCD.

## Hardware Requirements

- Arduino Uno
- 16x2 LCD with I2C
- Push buttons for paddle control (4 buttons)
- Resistors for buttons (optional)

## Connections

- Connect the LCD to the I2C pins (usually A4 for SDA and A5 for SCL).
- Connect the buttons to A0, A1 for Player 1 and A2, A3 for Player 2.

## How to Run

1. Upload the `PongGame.ino` file to your Arduino.
2. Press the buttons to control the paddles and play the game!

## Additional Notes

Ensure that you have the **LiquidCrystal_I2C** library installed in your Arduino IDE for LCD functionality.

You can expand the game with features like scoring, sound effects, and more.

The paddle and ball are represented using custom characters; you can modify their designs as desired.
