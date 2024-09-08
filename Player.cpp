#include "Player.h"

Player::Player()
{
}

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    _Animation(texture, imageCount, switchTime)
{
    _Speed = speed;
    _JumpHeight = jumpHeight;
    _Row = 0;
    _FaceRight = true;

    // Definicion de un cubo que llamamos player
    _Body.setSize(sf::Vector2f(100.0f, 100.0f));
    
    // Centramos el "player" en medio de la pantalla
    _Body.setPosition(512.0f, 360.0f);
    // Vamos a cambiar el centro de pivode del objeto "player" al centro
    _Body.setOrigin(_Body.getSize() / 2.0f);
    // Añadimos una textura al player
    _Body.setTexture(texture);

}


void Player::Update(float deltaTime, sf::RenderWindow& window)
{
    // Sistema de input desde el teclado
    _Velocity.x = 0.5f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _Velocity.x -= _Speed;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _Velocity.x += _Speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _CanJump) {

        _CanJump = false;
        _Velocity.y = -sqrtf(2.0f * 981.0f * _JumpHeight);

    }

    _Velocity.y += 981.0f * deltaTime;

    if (_Velocity.x == 0.0f) {
        _Row = 0;
    }
    else {
        _Row = 1;

        if (_Velocity.x > 0.0f) _FaceRight = true;
        else _FaceRight = false;
    }

    _Animation.Update(_Row, deltaTime, _FaceRight);
    _Body.setTextureRect(_Animation.uvRect);
    _Body.move(_Velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(_Body);
}

void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f) { _Velocity.x = 0.0f; }
    else if (direction.x > 0.0f) { _Velocity.x = 0.0f; }

    if (direction.y <= 0.0f) { _Velocity.y = 0.0f; _CanJump = true; }
    else if (direction.y > 0.0f) { _Velocity.y = 0.0f; }
}
