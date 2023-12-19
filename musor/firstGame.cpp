#include <iostream>

using namespace std;

void fill(char board[25][48])
{
	for(int x = 0; x < 25; x++)
	{
		for(int y = 0; y < 48; y++)
		{
			board[x][y]=' ';
		}
	}
}

void render(char board[25][48])
{
	system("cls");
	for(int x = 0; x < 25; x++)
	{
		for(int y = 0; y < 48; y++)
		{
			cout<<" "<<board[x][y];
		}
		cout<<"\n";
	}
}

void simulate(char board[25][48])
{
	int curX = 5, curY = 10, spX = 1, spY = 1, g = 0;
	while(true)
	{
		g++;
		board[curX][curY]=' ';
		
		
		if(curY>=47 || curY<=0)
		{
			spY *= -1;
		}
		curY+=spY;
		if(curX>=24 || curX<=0)
		{
			spX *= -1;
			g=0;
		}
		curX+=spX + g/10;
		board[curX][curY]='O';
		render(board);
	}
}

void prikol(char* board)
{
	for(int i = 0; 1; i++)
	{	
		*(board+i%25) = char(i);
		system("cls");
		for(int x = 0; x < 25; x++)
		{
			for(int y = 0; y < 25; y++)
			{
				cout<<" "<<*(board+x*y);
			}
			cout<<"\n";
		}	
	}
}

int main()
{
	char board[25][48];
	fill(board);
	render(board);
	simulate(board);
	//prikol(&board[0][0]);
	return 0;
}
