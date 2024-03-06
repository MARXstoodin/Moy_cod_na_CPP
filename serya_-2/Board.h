#include<iostream>
#include<vector>
#include<utility>

class Board
{
	public:
		Board(){}
		~Board(){}
		
		void setBoard(int x, int y)
		{
			boardX = x;
			boardY = y;
		}
		
		void setPoint(int x, int y)
		{
			
		}
		
		void print()
		{
			
		}
		
	private:
		std::vector<std::pair<int, int>*> points;
		int boardX, boardY;
};
