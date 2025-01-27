#pragma once
#include"headers.h"
#define BLOCK_SPACING 5;

using namespace std;

class filed_game
{
private:
	const sf::Vector2f size{ 9,9 };
	sf::Font Font;
	bool initialization_flag, initialization_flag_winodw = 0;
	vector<vector<unsigned short>> matrix;
	void matrix_initialization(vector<vector<unsigned short>>& m) {
		initialization_flag = 1;
		matrix.resize(size.y);
		for (int i = 0; i < size.y; i++)
		{
			matrix[i].resize(size.x);
		}
	}
	vector<vector<sf::RectangleShape>> RS;
	vector<vector< sf::Text >> text;
	vector<sf::Vector2f> hiddenCellsCoordinates;
	unsigned short deletedCount;
	sf::Vector2f coordinates_selected_block;

public:
	bool SetValue(sf::Vector2f coordinates, unsigned const short v) {
		if (!initialization_flag) matrix_initialization(matrix);
		if (coordinates.x < size.x and coordinates.y < size.y and coordinates.x >= 0 and coordinates.y >= 0) {

			if (matrix[coordinates.y][coordinates.x] == v or matrix[coordinates.y][coordinates.x] == 0) {
				matrix[coordinates.y][coordinates.x] = v;

				for (short i = 0; i < hiddenCellsCoordinates.size(); i++)
				{
					if (hiddenCellsCoordinates[i].x == coordinates.x and hiddenCellsCoordinates[i].y == coordinates.y)hiddenCellsCoordinates.erase(hiddenCellsCoordinates.begin() + i);
				}

				return 1;
			}
		}
		return 0;
	}
	void Clear()
	{
		hiddenCellsCoordinates.clear();
		for (short i = 0; i < size.y; i++)
		{
			for (short j = 0; j < size.x; j++)
			{
				matrix[i][j] = 0;
			}
		}
		
	}
	 short GetValue(sf::Vector2f coordinates) {
		if (!initialization_flag) matrix_initialization(matrix);
		if (coordinates.x < size.x and coordinates.y < size.y and coordinates.x>=0 and coordinates.y>=0) { return matrix[coordinates.y][coordinates.x]; }
	
		return -1;
	 }
	 short GetHideCells() { return deletedCount; }
	sf::Vector2f GetSizeFiled() {
		if (!initialization_flag) matrix_initialization(matrix);
		return size;
	}

	void DrawWindow(sf::RenderWindow &w) {
		sf::String str;
		bool p = 0;
		for (short i = 0; i < 9; i++)
		{
			for (short j = 0; j < 9; j++)
			{
				w.draw(RS[i][j]);
				for (short l = 0; l < hiddenCellsCoordinates.size(); l++)
				{
					if (hiddenCellsCoordinates[l] == sf::Vector2f(j, i)) p = 1;
				}
				if (!p) {
					str = to_string(matrix[i][j]);
					text[i][j].setString(str);
				}
				else
				{
					str = ' ';
					text[i][j].setString(str);
				}
				p = 0;
				
				w.draw(text[i][j]);
			}
		}
	}

	void init_window(const sf::RenderWindow &w) {
		if (!initialization_flag_winodw) {
			RS.resize(9);
			text.resize(9);
			matrix_initialization(matrix);
			for (short i = 0; i < 9; i++)
			{
				RS[i].resize(9);
				text[i].resize(9);
			}


			if (!Font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
				abort();
			}
			

			sf::Vector2u size_window = w.getSize();
			const float size_rectangle_shape = (size_window.x - 200) / 9;
			float x = 0, y = 10;
			int cnt_x = 1, cnt_y = 1;
			for (short i = 0; i < 9; i++)
			{
				for (short j = 0; j < 9; j++)
				{
					RS[i][j].setSize(sf::Vector2f(size_rectangle_shape, size_rectangle_shape));
					RS[i][j].setPosition(sf::Vector2f(x, y));
					RS[i][j].setFillColor(sf::Color::White);

					text[i][j].setFont(Font);
					text[i][j].setFillColor(sf::Color::Black);
					text[i][j].setCharacterSize(50);
					text[i][j].setPosition(sf::Vector2f(x, y));
					
					x += BLOCK_SPACING;
					if (cnt_x % 3 == 0)x += BLOCK_SPACING;;
					x += size_rectangle_shape;
					cnt_x++;
				}
				x = 0;
				y += BLOCK_SPACING;
				if (cnt_y % 3 == 0)y += BLOCK_SPACING;;
				cnt_y++;
				y += size_rectangle_shape;
			}
			initialization_flag_winodw = 1;
		}
	}

	void hideRandomCells(const short n) {
		deletedCount = n; 
		hiddenCellsCoordinates.clear();
		hiddenCellsCoordinates.resize(n);
		srand(time(0));
		
		for (short i = 0; i < n; i++)
		{
			hiddenCellsCoordinates[i] = sf::Vector2f(rand() % (8 - 1 + 2), rand() % (8 - 1 + 2));
		}
	}
	bool GetStatus() {
		if (hiddenCellsCoordinates.size() == 0) return 1; else
		{
			return 0;
		}
	}
	void set_color_block(sf::Vector2f pos, sf::Color c) {
		RS[coordinates_selected_block.y ][coordinates_selected_block.x].setFillColor(sf::Color::White);
		if((pos.x>=0 and pos.x<=8) and pos.y>=0 and pos.y<=8) 	coordinates_selected_block = pos;
		RS[coordinates_selected_block.y][coordinates_selected_block.x].setFillColor(c);
		
	}
	
};

