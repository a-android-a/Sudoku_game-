#include"Header.h"
#include<Windows.h>
constexpr auto FPS_LIM = 15;;
using namespace std;
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 659), "Sudoku", sf::Style::Titlebar  | sf::Style::Close);
    window.setFramerateLimit(FPS_LIM);
    window.setVerticalSyncEnabled(0);
    lockWindowSize(window.getSystemHandle());
       
    filed_game fg;
    generator g;
    fg.init_window(window);
    g.generate(fg);
    fg.hideRandomCells(90);

    Button hintButton(650, 0, "Hint", sf::Color(255, 215, 0), sf::Color::White, sf::Vector2f(135, 50), 24);
    Button GenerateButton(650, 50, "Generate",sf::Color(0, 128, 128), sf::Color::White, sf::Vector2f(135, 50), 24);
    Button EasyButton(650,100,"Easy",sf::Color(0, 128, 0),sf::Color ::White, sf::Vector2f(135,50),24);
    Button MediumButton(650, 150, "Mediu", sf::Color(255, 165, 0), sf::Color::White, sf::Vector2f(135, 50), 24);
    Button HardButton(650, 200, "Hard", sf::Color(139, 0, 0), sf::Color::White, sf::Vector2f(135, 50), 24);

    Counter time_counter(0,sf::Vector2f(730,500),35,sf::Color::White,string("C:\\Windows\\Fonts\\arial.ttf"));
    StaticText text(35, "time:" , sf::Color::White, sf::Vector2f(650, 500), "C:\\Windows\\Fonts\\arial.ttf");
    StaticText text_sec(15, "seconds", sf::Color::White, sf::Vector2f(700, 550), "C:\\Windows\\Fonts\\arial.ttf");
    
    
    sf::Vector2f block_position;
 
    unsigned short counter_fps = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                
                if (event.key.code >= sf::Keyboard::Num1 && event.key.code <= sf::Keyboard::Num9) {
                   
                    if (!fg.SetValue(sf::Vector2f(block_position), (event.key.code - sf::Keyboard::Num1 + 1))) fg.set_color_block(block_position, sf::Color(180, 89, 73)); else
                    {
                        fg.set_color_block(block_position, sf::Color(197,250,207));
                        

                    }
                }
                
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    if(block_position.y>0 )block_position.y--;
                    fg.set_color_block(block_position, sf::Color(100,100,100));
                    break;
                case sf::Keyboard::Down:
                    if (block_position.y < 8)block_position.y++;
                    fg.set_color_block(block_position, sf::Color(100, 100, 100));
                    break;
                case sf::Keyboard::Left:
                    if (block_position.x > 0)block_position.x--;
                    fg.set_color_block(block_position, sf::Color(100, 100, 100));
                    break;
                case sf::Keyboard::Right:
                    if (block_position.x < 8)block_position.x++;
                    fg.set_color_block(block_position, sf::Color(100, 100, 100));
                    break;
                default:
                    break;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (hintButton.isMouseOver(mousePos)) {
                        fg.SetValue(block_position, fg.GetValue(block_position));
                        fg.set_color_block(block_position, sf::Color(255, 215, 0));
                    }
                    if (GenerateButton.isMouseOver(mousePos)) {
                      
                        g.generate(fg);
                        fg.hideRandomCells(60);
                        time_counter.ResetTimer();
                      
                    }
                    if (EasyButton.isMouseOver(mousePos)) {
                        fg.hideRandomCells(23);
                    }
                    if (MediumButton.isMouseOver(mousePos)) {
                        fg.hideRandomCells(46);
                    }
                    if (HardButton.isMouseOver(mousePos)) {
                        fg.hideRandomCells(78);
                    }
                  
                }
            }

           
            

        }
        if (!fg.GetStatus()) {


            if (counter_fps == FPS_LIM) {
                time_counter.Increase();
                counter_fps = 0;
            }
            else
            {
                counter_fps++;
            }
        }
        else
        {
           
      
            MessageBox(window.getSystemHandle(), L"slove", L"Message", MB_OK | MB_ICONASTERISK);
            g.generate(fg);
            fg.hideRandomCells(30);
            time_counter.ResetTimer();
        }


        window.clear();
        fg.DrawWindow(window);
        GenerateButton.DrawWindow(window);
        hintButton.DrawWindow(window);
        EasyButton.DrawWindow(window);
        MediumButton.DrawWindow(window);
        HardButton.DrawWindow(window);
        time_counter.DrawWindow(window);
        text.DrawWindow(window);
        text_sec.DrawWindow(window);
        
        window.display();
    }
    
    return EXIT_SUCCESS;
}