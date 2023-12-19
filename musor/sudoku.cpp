#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

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

void renderBoard(char board[9][9])
{
	for(int x = 0; x<9; x++)
	{
		cout<<" ";
		for(int y = 0; y<9; y++)
		{
			cout<<board[x][y]<<" | ";
		}
		cout<<"\n------------------------------------\n";
	}
}

void solveBoard(char board[9][9])
{
	//char ER = ' ';
	//char save[9][9];
	//int s=0;
	for(int c = 0, lastC = 0, min = 1; min<10;)
	{
		//ER = ' ';
	for(int x = 0; x<9; x++)
	{
		for(int y = 0; y<9; y++)
		{
			if (board[x][y]==' ')
			{
				char guess[] = {'1','2','3','4','5','6','7','8','9'};
				char otvet = ' ';
				
				for(int z = 0; z<9; z++)
				{
					//cout<<" (";
					/*
					for(int w = 0; w<9; w++)
					{
						if (guess[z]==board[w][y] || guess[z]==board[x][w])
						{
							guess[z] = ' ';
						}
						for (int q = 0; q<3; q++)
						{
							if (guess[z]==board[x-x%3+q%3][y-y%3+w%3])
							{
								guess[z] = ' ';
							}
							s++;
						}
					}
					*/
					//cout<<") ";
					if (board[z][y]!=' ' && find(&guess[0], &guess[9], ('%c',board[z][y]))!=NULL)
					{
						*find(&guess[0], &guess[9], ('%c',board[z][y])) = ' ';
					}
					if (board[x][z]!=' ' && find(&guess[0], &guess[9], ('%c',board[x][z]))!=NULL)
					{
						*find(&guess[0], &guess[9], ('%c',board[x][z])) = ' ';
					}
					//s++;
				}
				
				for(int z = 0; z<3; z++)
				{
					for (int q = 0; q<3; q++)
					{
						if (find(&guess[0], &guess[9], ('%c',board[x-x%3+q%3][y-y%3+z%3]))!=NULL)
						{
							*find(&guess[0], &guess[9], ('%c',board[x-x%3+q%3][y-y%3+z%3])) = ' ';							
						}
						//s++;
					}
				}
				
				for(int z = 0; z<9; z++)
				{
					for(int q = 0; q<3; q++)
					{
						for(int w = 0; w<3; w++)
						{
							for(int j = 0; j<9; j++)
							{
								if(!(x-x%3+w%3!=x && y-y%3+q%3!=y))
								{
									cout<<"a";
									if (board[x-x%3+w%3][j]!=' ' && find(&guess[0], &guess[9], ('%c',board[x-x%3+w%3][j]))==NULL)
									{
										*find(&guess[0], &guess[9], ('%c',board[x-x%3+w%3][j])) = ' ';
									}
									if (board[j][y-y%3+q%3]!=' ' && find(&guess[0], &guess[9], ('%c',board[j][y-y%3+q%3]))==NULL)
									{
										*find(&guess[0], &guess[9], ('%c',board[j][y-y%3+q%3])) = ' ';
									}
								}
							}	
						}
					}
				}
				
				for(int z = 0, t=0; z<9; z++)
				{
					if (guess[z]!=' ')
					{
						otvet=guess[z];
						t++;
					}
					if(t>min)
					{
						/*
						if(t>minGuess)
						{
							minGuess=t;
						}
						*/
						otvet=' ';
						break;
						
					}
					if(t==0 && z==8)
					{
						cout<<"Error!";
						//ER = 'E';
						//return;
					}
				}
				if (otvet!=' ')
				{
					board[x][y]=otvet;
					cout<<"otved";
					min=1;
				}
				else
				{
					c++;
				}
				for(int z = 0; z<9; z++)
				{
					cout<<guess[z]<<" ";
				}
				cout<<"| ";
			}
		}
	}
	if(c==lastC)
	{
		cout<<"s";
		min++;
	}
	/*
	if(min==1 && ER!='E')
	{
		copy(&board[0][0], &board[0][0]+9*9,&save[0][0]);
	}
	else
	{
		copy(&save[0][0], &save[0][0]+9*9,&board[0][0]);
	}
	*/
	lastC=c;
	c=0;
	cout<<"\n"<<"min="<<min<<"\n";
	//cout<<"\n"<<s<<"\n";
	renderBoard(board);
	}
}

int main()
{
	/*
	char board[9][9]={
	{'9','3','6',' ','2','5',' ','1','4'},
	{' ','1','7',' ','3','4','9','2','8'},
	{'8',' ',' ',' ','9','7',' ',' ',' '},
	{' ',' ','3','4',' ',' ','5','9',' '},
	{'6',' ',' ',' ','1',' ',' ',' ',' '},
	{' ',' ',' ','3','8',' ',' ','7','1'},
	{' ',' ',' ','9',' ',' ',' ',' ','5'},
	{' ','5','1',' ','4',' ',' ',' ',' '},
	{'4','6',' ',' ',' ',' ','1','8',' '},
	};
	*/
	
	char board[9][9]={
	{'4','3','7','8',' ','5',' ',' ','2'},
	{'9','1',' ','4',' ',' ',' ','3',' '},
	{' ','8',' ',' ',' ','1','4','7','9'},
	{' ','9','1','3',' ',' ',' ',' ',' '},
	{' ',' ',' ','5','1',' ',' ','8','7'},
	{' ',' ','5',' ',' ',' ','9',' ','3'},
	{' ','2','9',' ','7','8',' ',' ','5'},
	{'1',' ',' ','9','4','3',' ','2',' '},
	{' ',' ',' ',' ','5',' ','8',' ','1'},
	};
	
	/*
	for(int x = 0; x<9; x++)
	{
		for(int y = 0; y<9; y++)
		{
			board[x][y] = ' ';
		}
	}
	board[5][5] = '9';
	*/
	//cout<<find(&board[0][0], &board[9][9], ('%c',i))<<"\n";
	renderBoard(board);
	cout<<"\n";
	solveBoard(board);
	return 0;
}
