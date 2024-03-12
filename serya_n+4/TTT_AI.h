#include <iostream>
#include "Board.h"

using namespace std;

class AI
{
	public:
		int ai_move(Board alpha)
		{
			char matrix[9] = alpha.matrix;
	   		int num = 0;
	   		
	   		alpha.move(2);
	   	
	   		
	   		/*for(int i = 0; i<9; i++)
			{
	   			if(matrix[i] != ' ')
				{
	   				if(alpha.move(i+1))
				}
		   	}*/
		}
};
