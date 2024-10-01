#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "GameLogic.h"

// Initialize the LCD (I2C address: 0x27, columns: 16, rows: 2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Game settings
const int paddleWidth = 1; // Paddle width
const int paddleHeight = 3; // Paddle height
int player1Y = 0; // Player 1 paddle Y position
int player2Y = 0; // Player 2 paddle Y position
int ballX = 8; // Ball X position
int ballY = 1; // Ball Y position
int ballDX = 1; // Ball direction X
int ballDY = 1; // Ball direction Y

void setup() {
    lcd.begin();
    lcd.backlight();
    pinMode(A0, INPUT); // Player 1 up button
    pinMode(A1, INPUT); // Player 1 down button
    pinMode(A2, INPUT); // Player 2 up button
    pinMode(A3, INPUT); // Player 2 down button
}

void loop() {
    // Control paddles
    if (digitalRead(A0) == HIGH && player1Y > 0) {
        player1Y--;
    }
    if (digitalRead(A1) == HIGH && player1Y < 2) {
        player1Y++;
    }
    if (digitalRead(A2) == HIGH && player2Y > 0) {
        player2Y--;
    }
    if (digitalRead(A3) == HIGH && player2Y < 2) {
        player2Y++;
    }

    // Move the ball
    ballX += ballDX;
    ballY += ballDY;

    // Ball collision with paddles
    if (ballX == 1 && ballY >= player1Y && ballY < player1Y + paddleHeight) {
        ballDX = -ballDX; // Bounce back
    }
    if (ballX == 14 && ballY >= player2Y && ballY < player2Y + paddleHeight) {
        ballDX = -ballDX; // Bounce back
    }

    // Ball collision with top and bottom walls
    if (ballY == 0 || ballY == 1) {
        ballDY = -ballDY; // Bounce
    }

    // Clear the LCD
    lcd.clear();
    
    // Draw paddles
    for (int i = 0; i < paddleHeight; i++) {
        if (player1Y + i < 2) {
            lcd.setCursor(0, player1Y + i);
            lcd.write(1); // Custom character for paddle 1
        }
        if (player2Y + i < 2) {
            lcd.setCursor(15, player2Y + i);
            lcd.write(1); // Custom character for paddle 2
        }
    }

    // Draw ball
    lcd.setCursor(ballX, ballY);
    lcd.write(2); // Custom character for the ball

    // Delay for a smooth game
    delay(200);
}
