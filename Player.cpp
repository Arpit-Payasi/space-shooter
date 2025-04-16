#include "Player.h"

void Player::initVariables() {
    this->movementSpeed = 7.5f;
    this->attackCoolDownMax = 5.f;
    this->attackCoolDown = this->attackCoolDownMax;
    this->hpMax = 100;
    this->hp = this->hpMax;
    this->sprite.setPosition(380.f, 500.f);
}

void Player::initTexture() {
    if (!this->texture.loadFromFile("Textures/ship.png"))
        std::cout << "ERROR::PLAYER::TEXTURE LOADING FAIL!!!" << std::endl;
}

void Player::initSprite() {
    this->sprite.setTexture(this->texture);
    ///resize
    this->sprite.scale(0.1f, 0.1f);
}

Player::Player() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
}

Player::~Player() = default;

Vector2f Player::getPos() const {
    return this->sprite.getPosition();
}

FloatRect Player::getBounds() {
    return this->sprite.getGlobalBounds();
}

int Player::getHP() const {
    return this->hp;
}

int Player::getHPMax() const {
    return this->hpMax;
}

Vector2f Player::getSize() const {
    return this->sprite.getOrigin();
}

void Player::setPosition(const Vector2f pos) {
    this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Player::setHP(int HP) {
    this->hp = HP;
}

void Player::loseHp(int value) {
    this->hp -= value;
    if (this->hp < 0)
        this->hp = 0;
}

void Player::move(const float x, const float y) {
    this->sprite.move(this->movementSpeed * x, this->movementSpeed * y);

    // Rotate based on movement direction
    if (x < 0) {
        this->sprite.setRotation(-10.f); // Rotate left
    } else if (x > 0) {
        this->sprite.setRotation(10.f); // Rotate right
    } else {
        this->sprite.setRotation(0.f); // Reset rotation when no horizontal movement
    }

    // Screen boundary enforcement (assuming window size is 1000x800)
    sf::Vector2f pos = this->sprite.getPosition();
    sf::FloatRect bounds = this->sprite.getGlobalBounds();

    if (pos.x < 0.f)
        pos.x = 0.f;
    if (pos.y < 0.f)
        pos.y = 0.f;
    if (pos.x + bounds.width > 1000.f)
        pos.x = 1000.f - bounds.width;
    if (pos.y + bounds.height > 800.f)
        pos.y = 800.f - bounds.height;

    this->sprite.setPosition(pos);
}

bool Player::canAttack() const {
    if (this->attackCoolDown >= this->attackCoolDownMax)
        return true;
    return false;
}

void Player::updateAttack() {
    if (this->attackCoolDown >= this->attackCoolDownMax)
        this->attackCoolDown = 0.f;
    if (this->attackCoolDown < this->attackCoolDownMax)
        this->attackCoolDown += 2.f;
}

void Player::update() {
    this->updateAttack();
}

void Player::render(RenderTarget *target) {
    target->draw(this->sprite);
}
