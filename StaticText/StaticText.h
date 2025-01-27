#include <SFML/Graphics.hpp>
#include<string>
#pragma once

class StaticText
{
private:
	sf::Text text;
	std::string st;
	sf::Font font;
public:
	StaticText(unsigned const short size_char,const std::string str ,sf::Color color, sf::Vector2f pos,const std::string path ) {
	
		font.loadFromFile(path);
		text.setFillColor(color);
		text.setCharacterSize(size_char);
		text.setPosition(pos);
		text.setFont(font);
		st = str;
	}
	void DrawWindow(sf::RenderWindow &w) {
		text.setString(st);	
		w.draw(text);
	}

};

