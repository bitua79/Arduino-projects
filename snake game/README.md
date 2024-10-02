# Snake Game for 16x2 LCD with Arduino

## Overview
This is an implementation of the classic Snake game designed to run on an Arduino with a 16x2 LiquidCrystal display. The snake moves across a grid that spans both rows of the LCD, collecting points and avoiding collisions with walls or itself. The game features multiple levels with different wall configurations and allows the user to control the snake using hardware buttons.

## Hardware Requirements
- Arduino board (e.g., Uno, Nano)
- 16x2 LiquidCrystal display
- 5 push-buttons for controlling direction and selecting options
- Optional: LED for score feedback
- Resistors for buttons and LED

## Features
- **Snake Movement**: Control the snake's movement with 4 directional buttons.
- **Multiple Levels**: Select from 4 predefined levels, each with different wall configurations.
- **Scoring System**: Points are awarded for collecting items, and the game speed increases as the score rises.
- **Collision Detection**: Game ends if the snake collides with walls or itself.
- **Custom LCD Characters**: The snake and walls are drawn using custom characters on the LCD.

## Controls
- **Button 1**: Move up
- **Button 2**: Move down
- **Button 3**: Move left
- **Button 4**: Move right
- **Button 5**: Select options (e.g., start game, choose level)

## Code Breakdown
- **Snake Representation**: The snake is stored as a linked list where each node represents a segment of the snake.
- **Movement**: The snake's head moves based on user input, and the rest of the body follows.
- **Collision Logic**: The game checks for collisions with the walls and the snake's body to determine if the game is over.
- **Levels**: Levels are defined in the `levelz` array, where `true` values represent walls.
- **LCD Output**: Custom characters for the snake and obstacles are rendered on the 16x2 LCD using `lcd.createChar()`.

## Setup
1. **Button Pin Mapping**:
   - Pin 6: Right
   - Pin 7: Up
   - Pin 8: Down
   - Pin 9: Left
   - Pin 10: Select/Confirm
   - Pin 13: LED (optional)

2. **LCD Pin Mapping**:
   - Pin 12: RS
   - Pin 11: Enable
   - Pins 5, 4, 3, 2: Data pins D4-D7

## Getting Started
1. Connect the hardware components as described in the "Setup" section.
2. Load the code onto your Arduino board using the Arduino IDE.
3. Start the game by selecting a level using the directional buttons and the select button.
4. Control the snake using the directional buttons to collect points and avoid collisions.

## Functions
- **`drawMatrix()`**: Renders the current game state on the LCD, including the snake, walls, and points.
- **`moveHead()`**: Moves the snake's head in the current direction.
- **`moveAll()`**: Updates the entire snake's position on the grid.
- **`newPoint()`**: Randomly generates a new point for the snake to collect.
- **`createSnake()`**: Initializes the snake's starting position and size.
- **`gameOverFunction()`**: Displays the "Game Over" message and score when the game ends.
- **`startF()`**: Resets the game and displays the level selection screen.

## Customization
You can add more levels by modifying the `levelz` array. Each level consists of two rows (for the two rows of the LCD), and you can define walls by setting array values to `true`.

## Notes
- Ensure debouncing for the buttons is properly handled using delays.
- Game speed increases as the player collects more points, making the game progressively harder.
