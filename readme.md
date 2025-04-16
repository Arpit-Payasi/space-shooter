
# Space Shooter

## Description

Space Shooter is an exciting 2D arcade game where the player controls a spaceship to fight off waves of enemy ships. The goal is to survive as long as possible by shooting enemies and dodging their attacks. The game includes a score system, increasing difficulty, and smooth controls, making it an engaging space combat experience.

## Features

- Player-controlled spaceship with movement and shooting
- Increasing difficulty and score tracking
- Smooth SFML graphics rendering
- Score and game-over screen

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Arpit-Payasi/space-shooter.git
   ```

2. Install SFML on your system. Find installation instructions [here](https://www.sfml-dev.org/download.php).

3. Compile the project:
   ```bash
   g++ -o space-shooter main.cpp Bullet.cpp Enemy.cpp Game.cpp Player.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```

4. Run the game:
   ```bash
   ./space-shooter
   ```

## Controls

- **Arrow keys** to move
- **right click** to shoot
- **Esc** to quit

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
