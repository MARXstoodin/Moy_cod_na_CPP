#include <iostream>
#include <thread>
#include <windows.h>

class Game{
	public:
		void render()
		{
			system("cls");
			for(int x = 0; x < 25; x++)
			{
				for(int y = 0; y < 48; y++)
				{
					std::cout<<" "<<board[x][y];
				}
				std::cout<<"\n";
			}
		}
		
		void simulate()
		{
			int curX = 5, curY = 10, spX = 1, spY = 1;
			
			while(true)
			{
				if(curY>45 || curY<3)
				{
					spY *= -1;
				}
				
				if(curX>22 || curX<3)
				{
					spX *= -1;
				}
				
				if(board[curX][curY+spY] == 'X')
				{
					spY *= -1;
				}
				
				board[curX][curY]=' ';
				curY+=spY;
				curX+=spX;
				board[curX][curY]='O';
				
				board[3][22] = '0';
				board[3][25] = '0';
				
				Sleep(100);
				render();
			}
		}
		
		void move()
		{
			int curX = 19, curY = 4, curX2 = 19, curY2 = 42;
			while(1)
		    {
		        if(GetKeyState(VK_NUMPAD7)< 0 && curX>3)
		        {
		        	board[curX][curY] = ' ';
		        	curX--;
		        	board[curX-3][curY] = 'X';
		        	Sleep(100);
				}
		            
		        if(GetKeyState(VK_NUMPAD1)< 0 && curX<24)
		        {
					board[curX-3][curY] = ' ';
		        	curX++;
		        	board[curX][curY] = 'X';
		        	Sleep(100);
				}
				
		        if(GetKeyState(VK_NUMPAD9)< 0 && curX2>3)
		        {
		        	board[curX2][curY2] = ' ';
		        	curX2--;
		        	board[curX2-3][curY2] = 'X';
		        	Sleep(100);
				}
		            
		        if(GetKeyState(VK_NUMPAD3)< 0 && curX2<24)
		        {
					board[curX2-3][curY2] = ' ';
		        	curX2++;
		        	board[curX2][curY2] = 'X';
		        	Sleep(100);
				}
			}
		}
		
		Game()
		{
			for(int x = 0; x < 25; x++)
			{
				for(int y = 0; y < 48; y++)
				{
					board[x][y]=' ';
					if(y==4 && x>15 && x<20)
						board[x][y]='X';
					if(y==42 && x>15 && x<20)
						board[x][y]='X';
				}
			}
			
			sim_thr = std::thread(&Game::simulate, this);
			move_thr = std::thread(&Game::move, this);
		}
		
		~Game()
		{
			sim_thr.join();
		}
		
	private:
		std::thread sim_thr;
		std::thread move_thr;
		char board[25][48];
		
};

int main()
{
	Game g;
	return 0;
}
