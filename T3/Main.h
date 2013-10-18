#include <SFML/Graphics.hpp>
#include "Player.h"

class Main
{
private:
	sf::Texture tex_player;

public:
	void Startup();
	void LoadContent();
	void Update(sf::RenderWindow &renderWindow);
	void Draw(sf::RenderWindow &renderWindow);

	Player player;
};