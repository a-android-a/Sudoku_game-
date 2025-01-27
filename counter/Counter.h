#pragma once
#include"Header_time_counter.h"
#include<iostream>
class Counter
{
private:
	unsigned long int counter = 0;
	sf::Vector2f pos_window;
	unsigned int  SizeText = 0;
	sf::Color cl;
	sf::Font font;
	sf::Text text;
public:
	Counter(const unsigned int t, const sf::Vector2f pos, const unsigned int  size_text, const sf::Color c, const std::string path) {
		counter = t;
		pos_window = pos;
		cl = c;
		SizeText = size_text;
		if (!font.loadFromFile(path)) {
			std::cerr << "font installation error\n";
		}
		else
		{


			text.setFont(font);
			text.setFillColor(cl);
			text.setPosition(pos);
			text.setCharacterSize(SizeText);
			
		}
		
		
	}
	void Increase() { counter++;}
	void ResetTimer() { counter = 0;}
	int GetCurrentTime() const { return counter; }
	void DrawWindow(sf::RenderWindow& w) {
		text.setString(std::to_string(counter));
		w.draw(text);
	}
};

