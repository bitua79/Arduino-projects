# Arduino Projects

This repository contains a collection of Arduino projects that explore a range of embedded systems concepts and utilize various sensors, displays, and other hardware components to build interactive applications.

## Projects Overview

### 1. **Dino Game on LCD**
This project is a simple version of the Chrome Dino Game, where a player controls a dinosaur to jump and avoid obstacles such as trees and birds. The game is displayed on a 16x2 LCD, and the player interacts via a button. Health is tracked using LEDs, and the score increases over time as the player survives.

- **Components Used**: LCD, Button, LEDs
- **Gameplay**: Dodge obstacles by pressing the button to jump.
- **Detailed Information**: A detailed README is available in the `dino_game/` directory.

### 2. **Snake Game on LCD**
This project replicates the classic Snake game on an LCD. The player controls the snake’s direction using buttons, trying to eat "food" and grow the snake while avoiding collisions with the walls or the snake’s body. The game displays the snake's movement and score on an LCD screen.

- **Components Used**: LCD, Buttons
- **Gameplay**: Move the snake to eat food and grow while avoiding obstacles.
- **Detailed Information**: A detailed README is available in the `snake_game/` directory.


## Repository Structure

```
arduino-projects/
│
├── dino_game/
│   ├── DinoGame.ino
│   └── README.md  # Detailed description for Dino Game
│
├── snake_game/
│   ├── SnakeGame.ino
│   └── README.md  # Detailed description for Snake Game
│
└── other_project_directories/
```

Each project is contained in its folder with a dedicated `README.md` file explaining its specific details and how to set it up.
