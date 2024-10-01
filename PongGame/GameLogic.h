#include "GameLogic.h"

// Function to initialize custom characters
void initCustomCharacters() {
    lcd.createChar(1, paddleChar);
    lcd.createChar(2, ballChar);
}
