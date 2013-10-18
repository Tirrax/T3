#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include <cmath>
#define PI 3.14159

class Player
{
private:
	sf::Sprite sprite;
	sf::Vector2f position, movement;
	sf::Vector2f lastMovement;
	float moveSpeed;
	float aimAngle; // Used to determine the position which the player is aiming at.
	std::vector<Projectile> projectiles;

	sf::Texture tex_cbolt;

	sf::Vector2f origin;
	unsigned short width, height;

public:
	Player();
	Player(sf::Texture &texture, sf::Vector2f position);
	void LoadContent();
	void Update(sf::RenderWindow &renderWindow);
	void Draw(sf::RenderWindow &renderWindow);

	void KeyboardInput();
	void MouseInput(sf::RenderWindow &renderWindow);
};