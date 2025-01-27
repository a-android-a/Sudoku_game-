#include"Header.h"
#include<iostream>

#define MAX_SHUFFLE_ITERATIONS 150;


class generator
{
	
private:
	
	void initializeMatrix(vector<vector<short>>& m) {
		short c = 0;
		for (short i = 0; i < m.size(); i++)
		{
			c = m[i][0];
			for (short j = 0; j < m[0].size(); j++)
			{
				if (c == 10) c = 1;
				m[i][j] = c;
				c++;
			}
		}
	}
	bool checkMatrixValidityVertically(vector<vector<short>>& m, short column) {
		unsigned short start = 0, end = 0;

		if (column == 1) { start = 0; end = 2; }
		if (column == 2) { start = 3; end = 5; }
		if (column == 3) { start = 6; end = 8; }

	}
	void flip_vertically(vector<vector<short>>& m) {
		
			unsigned const short random_column = rand() % (3 - 1 + 1) + 1;
			unsigned short start = 0, end = 0;
		
			if (random_column == 1) { start = 0; end = 2; }
			if (random_column == 2) { start = 3; end = 5; }
			if (random_column == 3) { start = 6; end = 8; }

			for (short i = 0; i < m.size(); i++)
			{
				swap(m[i][start], m[i][end]);
			}
		
	}
	void flip_horizontally(vector<vector<short>>& m) {

		unsigned const short random_strings = rand() % (3 - 1 + 1) + 1;
		unsigned short start = 0, end = 0;
		
		if (random_strings == 1) { start = 0; end = 2; }
		if (random_strings == 2) { start = 3; end = 5; }
		if (random_strings == 3) { start = 6; end = 8; }

		for (short i = 0; i < m.size(); i++)
		{
			swap(m[start][i], m[end][i]);
		}
	}
	void flip_horizontally_Block(vector<vector<short>>& m) {
		vector<short> temp(9);

		for (short j = 0; j <= 2; j++)
		{

			for (int i = 0; i < m[0].size(); i++)
			{
				temp[i] = m[0][i];
				
			}
			m.erase(m.begin());
			m.resize(9);
			for (short l = 0; l < temp.size(); l++)
			{
				m[m.size()-1].push_back(temp[l]);
			}

		}

	}
	void flip_vertically_Block(vector<vector<short>>& m) {
		
		vector<short> temp(9);
		for (short j = 0; j <= 2; j++)
		{

			for (int i = 0; i < m.size(); i++)
			{
				temp[i] = m[i][m.size() - 1];
				m[i].erase(m[i].end() - 1);
			}

			for (short l = 0; l < temp.size(); l++)
			{
				m[l].insert(m[l].begin(), temp[l]);
			}

		}
		
	}



public:
	void generate(filed_game &f) {
		srand(time(0));
		f.Clear();
		vector<vector<short>> matrix(9,vector<short>(9));
		
		matrix[0][0] = 1;
		matrix[1][0] = 4;
		matrix[2][0] = 7;
		matrix[3][0] = 2;
		matrix[4][0] = 5;
		matrix[5][0] = 8;
		matrix[6][0] = 3;
		matrix[7][0] = 6;
		matrix[8][0] = 9;
		initializeMatrix(matrix);
		
		unsigned short SHUFFLE_ITERATIONS = rand() % (200 - 50  + 2);
		unsigned short operation = 0;
	
		for (short i = 0; i < SHUFFLE_ITERATIONS; i++)
		{
			
		
		
		
			
			operation = rand() % (4 - 1 + 2);
			
		
				switch (operation) {
				
				case 1: flip_vertically(matrix);		 break;
				case 2: flip_horizontally(matrix);		 break;
				case 3: flip_horizontally_Block(matrix); break;
				case 4: flip_vertically_Block(matrix);	 break;
				}
				
		}
	
		
		
		for (short i = 0; i < matrix.size(); i++)
		{
			for (short j = 0; j < matrix[0].size(); j++)
			{
				f.SetValue(sf::Vector2f(j, i), matrix[i][j]);
			}
		}
	}
};

