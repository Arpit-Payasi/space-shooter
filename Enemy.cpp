#include "Enemy.h"
#include<cmath>

void Enemy::initVariables() {
    this->pointCount = rand() % 8 + 3;
    this->speed = float(this->pointCount) / 4;
    this->hpMax = int(this->pointCount * 2.5);
    this->hp = this->hpMax;
    this->damage = int(this->pointCount);
    this->points = int(this->pointCount);
}

void Enemy::initShape() {
    float radius = float(this->pointCount * 5);

    // Main shape
    this->shape.setRadius(radius);
    this->shape.setPointCount(30);
    this->shape.setFillColor(Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
    this->shape.setOrigin(radius, radius);

    // Glow aura
    this->aura.setRadius(radius + 10.f);
    this->aura.setPointCount(30);
    this->aura.setFillColor(Color(
        this->shape.getFillColor().r,
        this->shape.getFillColor().g,
        this->shape.getFillColor().b,
        60
    ));
    this->aura.setOrigin(this->aura.getRadius(), this->aura.getRadius());

    // Eyes
    this->eye1.setRadius(3.f);
    this->eye1.setFillColor(Color::Black);
    this->eye1.setOrigin(3.f, 3.f);

    this->eye2.setRadius(3.f);
    this->eye2.setFillColor(Color::Black);
    this->eye2.setOrigin(3.f, 3.f);
}

Enemy::Enemy(float posX, float posY) {
    this->initVariables();
    this->initShape();

    this->shape.setPosition(posX, posY);
    this->aura.setPosition(posX, posY);
    this->eye1.setPosition(posX - 5.f, posY - 5.f);
    this->eye2.setPosition(posX + 5.f, posY - 5.f);
}

Enemy::~Enemy() = default;

FloatRect Enemy::getBounds() const {
    return this->shape.getGlobalBounds();
}

int Enemy::getPoints() const {
    return this->points;
}

int Enemy::getDamage() const {
    return this->damage;
}

int Enemy::getHp() const {
    return this->hp;
}

int Enemy::getHpMax() const {
    return this->hpMax;
}

void Enemy::loseHP(int value) {
    this->hp -= value;
    if (this->hp < 0)
        this->hp = 0;
}

void Enemy::setTransparent(int transparent) {
    Color current = this->shape.getFillColor();
    this->shape.setFillColor(Color(current.r, current.g, current.b, transparent));
}

void Enemy::update() {
    float elapsed = this->pulseClock.getElapsedTime().asSeconds();
    float scale = 1.f + 0.05f * sin(elapsed * 4.f); // pulse animation

    this->shape.setScale(scale, scale);
    this->aura.setScale(scale * 1.1f, scale * 1.1f);

    this->shape.move(0.f, this->speed);
    this->aura.move(0.f, this->speed);
    this->eye1.move(0.f, this->speed);
    this->eye2.move(0.f, this->speed);
}

void Enemy::render(RenderTarget* target) {
    target->draw(this->aura);    // Glow first
    target->draw(this->shape);   // Main shape
    target->draw(this->eye1);    // Eyes
    target->draw(this->eye2);
}
