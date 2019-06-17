#pragma once
#include "Action.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>

class Game{
	Action action;
	sf::RenderWindow mWindow;
	sf::RectangleShape rect;
	sf::Texture rabbit;
	sf::Sprite sRabbit;
	sf::Texture wolf;
	sf::Sprite sWolf;
	sf::Texture wolfess;
	sf::Sprite sWolfess;
	sf::Texture reklama;
	sf::Sprite sReklama;
public:
	Game():mWindow(sf::VideoMode(1366, 768), "Wolf Island 2") {
		action;
		mWindow.setFramerateLimit(1);
		if (!reklama.loadFromFile("reklama.png")) {
		//handle it!
		}
				if (!rabbit.loadFromFile("rabbit.png")) {
					// Handle loading error
				}
				if (!wolf.loadFromFile("wolf.png")) {
					// Handle loading error
				}
				if (!wolfess.loadFromFile("wolfess.png")) {
					// Handle loading error
				}
				this->sReklama.setTexture(reklama);
				this->sReklama.setPosition(1000, 350);
				this->sRabbit.setTexture(rabbit);
				this->sWolf.setTexture(wolf);
				this->sWolfess.setTexture(wolfess);
	}

	void run() {

		while (mWindow.isOpen()) {

			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter)) {
					do {
						continue;
					} while (!(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter));

				}
				if (event.type == sf::Event::Closed)
					mWindow.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					do {
						continue;
					} while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
				}
				
					action.do_action();
					this->draw_map();
			
					if (this->action.ending())
						system("Pause");

			}
		}
	}


	void draw_map() {
	mWindow.clear();
		sf::RectangleShape rect(sf::Vector2f(35, 35));
		rect.setFillColor(sf::Color::White);
		rect.setOutlineThickness(3);
		rect.setOutlineColor(sf::Color::Black);
		mWindow.draw(sReklama);

		for (int i = 203; i <= 868; i += 35) {
			for (int k = 3; k <= 668; k += 35) {
		rect.setPosition(i, k);
				mWindow.draw(rect);
			}
		}
		
		draw_animals();
		sf::Font font;	
		font.loadFromFile("fixedsys.ttf");
		sf::Text text_one("", font, 40);
		text_one.setFillColor(sf::Color::Cyan);
		sf::Text text_two("", font, 40);
		text_two.setFillColor(sf::Color::Blue);
		sf::Text text_three("", font, 40);
		text_three.setFillColor(sf::Color::Magenta);
		std::ostringstream bunz;
		std::ostringstream wolfss;
		std::ostringstream g_wolfs;
		bunz<< action.map.return_bunnies();
		text_one.setString("Bunnies:"+ bunz.str());
		text_one.setPosition(930, 3);
		mWindow.draw(text_one);
		wolfss << action.map.return_wolfes();
		text_two.setString("Wolfs:" + wolfss.str());
		text_two.setPosition(930, 45);
		mWindow.draw(text_two);
		g_wolfs << action.map.return_wolfess();
		text_three.setString("Girl-wolfes:" + g_wolfs.str());
		text_three.setPosition(930, 87);
		mWindow.draw(text_three);

		mWindow.display();
	}

	void draw_animals() {
		this->action.map.counting();
		sf::Font font_one;
		font_one.loadFromFile("fixedsys.ttf");

		sf::Text count("", font_one, 35);
		count.setFillColor(sf::Color::Blue);
		
		for (int i = 1; i < 21; i++) {
			for (int k = 1; k < 21; k++) {
					if (action.bunny_here_2(i, k)) {
				sRabbit.setPosition(203 + 35 * (i - 1), 3 + 35 * (k - 1));
				mWindow.draw(sRabbit);	
				if (action.map.return_count_bunnies(i, k) == 0)
					continue;
				std::ostringstream count_buns;
				count_buns << action.map.return_count_bunnies(i, k);
				count.setString(count_buns.str());
				count.setPosition(203 + 35 * (i - 1), 3 + 35 * (k - 1));
				mWindow.draw(count);

		}		
				if (action.wolf_here_2(i, k)) {
					sWolf.setPosition(203 + 35 * (i - 1), 3 + 35 * (k - 1));
					mWindow.draw(sWolf);
					
				}
				if (action.wolfess_here_2(i, k)) {
					sWolfess.setPosition(203 + 35 * (i - 1), 3 + 35 * (k - 1));
					mWindow.draw(sWolfess);
					
				}
			}

		}

		
	}


};