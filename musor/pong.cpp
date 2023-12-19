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
	
	/**(board+45) = 'V';
	*(board+46) = 'D';*/
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
	int curX = 5, curY = 10, spX = 1, spY = 1;
	while(true)
	{
		if(curY==45 || curY==0)
		{
			spY *= -1;
		}
		if(curX==24 || curX==0)
		{
			spX *= -1;
		}
		board[curX][curY]=' ';
		board[curX][curY+1]=' ';
		board[curX][curY+2]=' ';
		curY+=spY;
		curX+=spX;
		board[curX][curY]='D';
		board[curX][curY+1]='V';
		board[curX][curY+2]='D';
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
