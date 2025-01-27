#include"Header_Button.h"
#pragma once

class Button {

private:
    sf::RectangleShape button;
    sf::Text buttonText;
    sf::Font font;
    

public:
    Button(const float x, const float y, const std::string& text, const sf::Color color, const sf::Color color_text , const sf::Vector2f size_button,const  int size_char) {
        button.setSize(size_button);
        button.setPosition(x, y);
        button.setFillColor(color);
        
        font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(size_char);
        buttonText.setFillColor(color_text);
        buttonText.setPosition(x + 10, y + 10);
    }

    void DrawWindow(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(buttonText);
        
    }
    void SetColor(sf::Color c) {
        button.setFillColor(c);
    }
    bool isMouseOver(sf::Vector2i mousePos) {
       
        return button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));  
    }


};