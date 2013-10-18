#include "Projectile.h"

Projectile::Projectile()
{

}

Projectile::Projectile(sf::Texture &texture, sf::Vector2f startPosition, float moveSpeed, unsigned short damage)
{
	this->position = startPosition;
	this->moveSpeed = moveSpeed;
	this->damage = damage;

	sprite.setPosition(position);
	sprite.setTexture(texture);
}

void Projectile::LoadContent()
{

}

void Projectile::Update()
{
	// Projectile physics
	position += velocity;
	sprite.setPosition(position + velocity);
}

void Projectile::Draw(sf::RenderWindow &renderWindow)
{
	renderWindow.draw(sprite);
}

// Getters and Setters
// Angle
void Projectile::setAngle(float angle)
{
	this->angle = angle;
}

float Projectile::getAngle()
{
	return angle;
}

// Velocity
void Projectile::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

sf::Vector2f Projectile::getVelocity()
{
	return velocity;
}

// Move Speed
void Projectile::setMoveSpeed(float moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

float Projectile::getMoveSpeed()
{
	return moveSpeed;
}

// Sprite
sf::Sprite &Projectile::getSprite()
{
	return sprite;
}