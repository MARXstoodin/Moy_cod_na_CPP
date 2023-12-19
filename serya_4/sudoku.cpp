#include <iostream>
using namespace std;

/*void createBoard(int* board[9][9])
{
	for(int x = 0; x<9; x++)
	{
		for(int y = 0; y<9; y++)
		{
			*board[x][y] = 0;
		}
	}
}*/

void renderBoard(int board[9][9])
{
	for(int x = 0; x<9; x++)
	{
		cout<<" ";
		for(int y = 0; y<9; y++)
		{
			cout<<board[x][y]<<" | ";
		}
		if(x!=8)
		{
			
		}
		cout<<"\n------------------------------------\n";
	}
}

int main()
{
	int board[9][9];
	for(int x = 0; x<9; x++)
	{
		for(int y = 0; y<9; y++)
		{
			board[x][y] = 0;
		}
	}
	renderBoard(board);
	return 0;
}
