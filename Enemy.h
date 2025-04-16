#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy {
private:
    // Private member variables
    int pointCount;
    float speed;
    int hpMax;
    int hp;
    int damage;
    int points;

    // Private visual components
    CircleShape shape;
    CircleShape aura;
    CircleShape eye1;
    CircleShape eye2;

    // Clock for the pulse animation
    Clock pulseClock;

    // Private functions
    void initVariables();
    void initShape();

public:
    // Constructor / Destructor
    Enemy(float posX, float posY);
    ~Enemy();

    // Getter for bounds of the enemy
    FloatRect getBounds() const;

    // Getter for points associated with the enemy
    int getPoints() const;

    // Getter for the damage the enemy can deal
    int getDamage() const;

    // Getter for the current HP of the enemy
    int getHp() const;

    // Getter for the maximum HP of the enemy
    int getHpMax() const;

    // Function to lose health
    void loseHP(int value);

    // Function to change transparency of the enemy
    void setTransparent(int transparent);

    // Function to update the enemy's logic
    void update();

    // Function to render the enemy
    void render(RenderTarget* target);
};

#endif // ENEMY_H
