#include<iostream>
#include<vector>

using namespace std;

class Figure {
	public:
		Figure(char symbol) {
			_symbol = symbol;
		}
 
		char getSymbol() {
			return _symbol;
		}
	private: 
		char _symbol;
};
 
 
class Cross : public Figure {
	public:
		Cross() : Figure('X') {}
};
 
class Nought : public Figure {
	public:
		Nought() : Figure('O') {}
};
 
class Board {
	private:
		std::vector<std::vector<char> >* _field;
 
	public:
		Board(int height, int width) {
			_field = new std::vector<std::vector<char> >(
				height,
				std::vector<char>(width, ' ')
			);
		}
 
		~Board() {
			delete _field;
		}
 
		void set(int x, int y, Figure figure) {
			this->getField()[x][y] = figure.getSymbol();
		}
 
		void print() {
			std::vector<std::vector<char> >& field = this->getField();
			for(int i = 0; i < field.size(); i++){
				for(int j = 0; j < field[i].size(); j++) {
					std::cout << field[i][j];
				}
				std::cout << std::endl;
			}
		}
 
	private:
		std::vector<std::vector<char> >& getField() {
			return *this->_field;
		}
};
