#include <Windows.h>

#include "game_state.h"
#include "main_menu.h"

game_state coreState; 
bool quitGame = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());

	// when window is open, run the program
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		coreState.Update();
		coreState.Render();

		window.display();

		if (quitGame)
		{
			window.close();
		}

		Sleep(5);
	}

	return 0;
}

