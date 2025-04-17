
# Space Shooter

# Space Shooter Game

A 2D space shooter game developed in **C++ using SFML**, featuring smooth player controls, bullet firing, enemy generation with visual effects, collision handling, scoring system, and game over UI.

---

## Features

- **Player spaceship** movement with keyboard input (WASD).
- **Smooth rotation** on movement for immersive gameplay.
- **Bullet shooting** with cooldown system.
- **Randomized enemies** with health, damage, and unique colors.
- **Enemy aura effects** and animated pulse behavior.
- **Collision detection** between bullets and enemies.
- **Dynamic scoring** based on enemy defeat.
- **Player HP bar** (GUI) and **Game Over** screen when HP reaches zero.
- **Modular object-oriented structure** for future expansions.

---

## Controls

| Action       | Key         |
|--------------|-------------|
| Move         | Arrow Keys / WASD |
| Shoot        | Spacebar    |
| Exit Game    | Escape      |

---

## Modifications we did
- Enemy shape enhanced made it circular and added aura on the outer sides and enemy glows up sinusoidally.
- A 10 degrees tilt either on left or right side when move in left or right.
- Earliar spaceship used to get outside the diplay screen but now we have fixed it and it do not go out of bounds.
- Also background image also changed to a more realistic version.

## Code Structure

The project follows a modular design with the following key files:

- **Game.cpp / .h**: Contains the main game logic such as the update loop, rendering, collision handling, and overall game state.
- **Player.cpp / .h**: Manages player attributes, movement, shooting mechanics, and input handling.
- **Enemy.cpp / .h**: Handles enemy creation, movement, health, damage, and visual effects.
- **Bullet.cpp / .h**: Manages bullet properties like position, direction, movement, damage, and rendering.
- **main.cpp**: The entry point of the program where the game is initialized and started.
- **Resources/**: Directory containing assets like textures, fonts, and other media files.
- **README.md**: This documentation file that provides an overview of the project.

---

## How It Works

### Player Movement
The player can move in all directions. The sprite rotates slightly left/right depending on the direction to simulate aircraft dynamics. Movement is restricted within the screen boundaries (1000x800).

### Shooting System
The player can fire bullets only if the cooldown allows it (`canAttack()` logic). This prevents bullet spamming.

### Bullet Mechanics
Each bullet has direction, speed, and damage. Bullets move continuously and are removed upon off-screen exit or collision.

### Enemy System
Enemies are spawned with:
- Random shape size (based on `pointCount`)
- Colorful aura and pulsing animation
- Health and damage based on shape
- Eyes for a more realistic feel

### Collision Handling
When a bullet hits an enemy:
- Enemy takes damage (`loseHP`)
- Becomes semi-transparent if hit
- Is deleted if HP reaches zero
- Player score increases

### GUI
- Player HP bar
- Real-time score
- Game Over message

---

## Dependencies

- **SFML 2.5+**
  - Install SFML from [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)

---

## Screen shots before and after modifications
![Screenshot 2025-04-17 123217](https://github.com/user-attachments/assets/66ea1fe1-b30c-41b8-b74e-5a14bdc6735e)


![WhatsApp Image 2025-04-17 at 12 24 00 PM](https://github.com/user-attachments/assets/9e0f40f3-b182-413f-bd31-6d53e94893ac)



## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## How to Run

### 1. Clone the Repo
```bash
git clone https://github.com/Arpit-Payasi/space-shooter.git
cd space-shooter

g++ -o game.exe *.cpp -lsfml-graphics -lsfml-window -lsfml-system
./spaceshooter.exe
