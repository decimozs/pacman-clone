#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace sf;

void main() {

	RenderWindow MENU(VideoMode(960, 720), "Pacman", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	Texture Maintexture;
	Maintexture.loadFromFile("Pacman/background.jpg");
	background.setTexture(&Maintexture);

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MENU.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{ 
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return) {
					RenderWindow Play(VideoMode(960, 720), "Lets go Pac Man!");
					RenderWindow OPTIONS(VideoMode(960, 720), "Options");
					RenderWindow ABOUT(VideoMode(960, 720), "About");

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (Play.isOpen())
						{
							Event aevent;
							while (Play.pollEvent(aevent)) {
								if (aevent.type == Event::Closed)
								{
									Play.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Play.close();
									}
								}
							}

							OPTIONS.close();
							ABOUT.close();
							Play.clear();
							Play.display();
						}
					}

					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							Event aevent;
							while (OPTIONS.pollEvent(aevent)) {
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										OPTIONS.close();
									}
								}
							}

							Play.close();
							OPTIONS.clear();
							ABOUT.close();

							OPTIONS.display();
						}
					}
					if (x == 2)
					{
						while (ABOUT.isOpen())
						{
							Event aevent;
							while (ABOUT.pollEvent(aevent)) {
								if (aevent.type == Event::Closed)
								{
									ABOUT.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										ABOUT.close();
									}
								}
							}

							Play.close();
							OPTIONS.clear();
							ABOUT.clear();
							ABOUT.display();
						}
					}
					if (x == 3)
						MENU.close();
					break;

				}
			}
		}

		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();

	}
}
