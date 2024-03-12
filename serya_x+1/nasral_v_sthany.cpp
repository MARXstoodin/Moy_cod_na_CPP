#include <iostream>
#include <thread>
#include <windows.h>

int curX = 5, curY = 5;
char matrix[10][10];
	
void print()
{
	for(int y = 0; y < 10; y++)
	{
		for(int x = 0; x < 10; x++)
		{
			matrix[y][x] = ' ';
		}
	}
	
	matrix[curX][curY] = 'O';
	
	while(1)
	{
		for(int y = 0; y < 10; y++)
		{
			for(int x = 0; x < 10; x++)
			{
				std::cout<<" "<<matrix[y][x];
			}
			std::cout<<"\n";
		}
		std::system("cls");
	}
}

void move()
{	
	while(1)
    {
        if(GetKeyState(VK_LEFT)< 0)
        {
        	matrix[curX][curY] = ' ';
        	curY--;
        	matrix[curX][curY] = 'O';
        	Sleep(100);
		}
            
        if(GetKeyState(VK_RIGHT)< 0)
        {
        	matrix[curX][curY] = ' ';
        	curY++;
        	matrix[curX][curY] = 'O';
        	Sleep(100);
		}
            
        if(GetKeyState(VK_UP)< 0)
        {
        	matrix[curX][curY] = ' ';
        	curX--;
        	matrix[curX][curY] = 'O';
        	Sleep(100);
		}
            
        if(GetKeyState(VK_DOWN)< 0)
        {
        	matrix[curX][curY] = ' ';
        	curX++;
        	matrix[curX][curY] = 'O';
        	Sleep(100);
		}
	}
}

int main()
{
	std::thread t1(print);
	std::thread t2(move);
	t1.join();
	t2.join();
	return 0;
}
