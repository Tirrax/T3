#include "Main.h"

int main()
{
	Main main;
	main.Startup();
	return EXIT_SUCCESS;
}

void Main::Startup()
{
	sf::RenderWindow renderWindow(sf::VideoMode(1600, 900), "T6: The Triple Threat Time Travelling Thief");
	renderWindow.setFramerateLimit(60);

	LoadContent();

    while (renderWindow.isOpen())
    {
        sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }

		Update(renderWindow);
        Draw(renderWindow);
    }
}
//C:\Users\Stefan\Documents\visual studio 2012\Projects\T3
void Main::LoadContent()
{
	tex_player.loadFromFile("Data/Textures/tex_player.png");
	player = Player(tex_player, sf::Vector2f(100, 100));
	player.LoadContent();
}

void Main::Update(sf::RenderWindow &renderWindow)
{
	player.Update(renderWindow);
}

void Main::Draw(sf::RenderWindow &renderWindow)
{
	renderWindow.clear(sf::Color(115, 115, 115));
	player.Draw(renderWindow);
    renderWindow.display();
}