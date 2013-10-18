#include <SFML/Graphics.hpp>

class Projectile
{
private:
	sf::Sprite sprite;
	sf::Vector2f position, velocity;
	float moveSpeed;
	unsigned short damage;
	float angle;

public:
	Projectile();
	Projectile(sf::Texture &texture, sf::Vector2f startPosition, float moveSpeed, unsigned short damage);
	void LoadContent();
	void Update();
	void Draw(sf::RenderWindow &renderWindow);

	void setAngle(float angle);
	float getAngle();

	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity();

	void setMoveSpeed(float moveSpeed);
	float getMoveSpeed();

	sf::Sprite &getSprite();
};