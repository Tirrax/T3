#include "Player.h"

Player::Player()
{

}

Player::Player(sf::Texture &texture, sf::Vector2f position)
{
	this->position = position;
	this->width = texture.getSize().x;
	this->height = texture.getSize().y;
	this->origin = sf::Vector2f(position.x + (width / 2), position.y + (height / 2));

	sprite.setTexture(texture);
	sprite.setPosition(position);

	moveSpeed = 7.0f;
}

void Player::LoadContent()
{
	tex_cbolt.loadFromFile("Data/Textures/tex_cbolt.png");
}

void Player::Update(sf::RenderWindow &renderWindow)
{
	KeyboardInput();
	MouseInput(renderWindow);

	origin = sf::Vector2f(position.x + (width / 2), position.y + (height / 2));

	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Update();
	}
}

void Player::KeyboardInput()
{
	movement = sf::Vector2f(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x = 1;
	}

	lastMovement = moveSpeed * movement;
	sf::Vector2f newPos = position + (moveSpeed * movement);
	position = newPos;
	sprite.setPosition(newPos);
}

void Player::MouseInput(sf::RenderWindow &renderWindow)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(renderWindow).x), static_cast<float>(sf::Mouse::getPosition(renderWindow).y));
	sf::Vector2f aimDirection = mousePos - origin;
	aimAngle = static_cast<float>(atan2(aimDirection.x, -aimDirection.y));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		// Create projectile.
		Projectile projectile(tex_cbolt, origin, 72, 12);
		projectile.setAngle(aimAngle * (180 / PI));
		float _cos = cos(aimAngle - (PI / 2));
		float _sin = sin(aimAngle - (PI / 2));
		projectile.setVelocity(sf::Vector2f(_cos, _sin) * projectile.getMoveSpeed());
		projectile.getSprite().setRotation(projectile.getAngle());
		projectiles.push_back(projectile);
	}
}

void Player::Draw(sf::RenderWindow &renderWindow)
{
	renderWindow.draw(sprite);
	for (int i = 0; i < projectiles.size(); i++)
	{
		renderWindow.draw(projectiles[i].getSprite());
	}
}