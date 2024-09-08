#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
public:
	Player();
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);

	void Update(float deltaTime, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return _Body.getPosition(); }
	Collider GetCollider() { return Collider(_Body); }

private:
	sf::RectangleShape _Body;
	Animation _Animation;
	unsigned int _Row;
	float _Speed;
	bool _FaceRight;

	sf::Vector2f _Velocity;
	bool _CanJump;
	float _JumpHeight;
};

