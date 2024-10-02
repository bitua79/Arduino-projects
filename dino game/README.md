# Dino Game on LCD - Arduino

This Arduino project is a simple Dino game inspired by the Chrome browser's offline dinosaur game. The game uses an LCD screen to display a dinosaur, bird, and tree, while the player dodges obstacles by pressing a button. The player's health and score are tracked, and an LED indicator displays the health status.

## Components

- Arduino board
- 16x2 LCD display
- Button
- 3 LEDs
- Resistors (for LEDs and button)
- Jumper wires

## How It Works

The game simulates a dino running across the screen, avoiding trees and birds. The dino can jump by pressing a button connected to pin 13. The player starts with 3 health points, and each time they hit a bird or tree, they lose health. Once health reaches zero, the game restarts. The player's score increases over time, and LEDs connected to pins 6, 7, and 9 indicate health status.

## Pin Configuration

- **LCD**: Connected to pins `12, 11, 5, 4, 3, 2` for control and data signals.
- **Button**: Connected to pin `13`.
- **LEDs**: Connected to pins `6, 7, 9` to display health status.
- **Analog pin**: Pin `A0` used for random seed generation.

## Setup Instructions

1. **Wiring**: Connect the LCD, button, and LEDs to the respective pins.
2. **Upload Code**: Upload the provided Arduino code to your Arduino board.
3. **Start Game**: The game will start automatically with the dino running and obstacles moving.

## Game Logic

1. **Dino Movement**: The dino's position changes when the button is pressed.
2. **Obstacles**: Birds and trees spawn randomly and move from right to left on the screen.
3. **Collision**: If the dino hits an obstacle, health is reduced. If health drops to zero, the game is over, and the player’s final score is displayed.
4. **Restart**: The game restarts automatically after a game over.

## Functions

- **start()**: Initializes game variables, positions of obstacles, and game speed.
- **led()**: Updates the LEDs based on the player's health.
- **loop()**: The main game loop that handles rendering the dino, obstacles, detecting collisions, and updating the score.

## Display

- **LCD Characters**: Custom characters for the dino, bird, and tree are created and displayed using the `lcd.createChar()` function.
- **Score**: Displayed at the top right corner of the LCD screen.
  
## Gameplay Instructions

1. Press the button to jump and avoid obstacles.
2. Monitor the health through the LEDs.
3. The game speeds up as time progresses, so react quickly!

Enjoy the game!
