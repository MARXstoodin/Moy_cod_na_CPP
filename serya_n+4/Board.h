
using namespace std;

class Board
{
	public:
  		
		void move(int num)
		{
   			if(9<num||num<1)
	    		throw string("INACCEPTABLE NUM");
	    
	   		num--;
	    
	   		if(matrix[num]!=' ')
	    		throw string("PLACE OCCUPIED");
	   
	    
		   switch(turn)
		   {
			    case true:
					matrix[num]='X';
			    break;
			    case false:
					matrix[num]='O';
			    break;
		   }
   
		   turn=!turn;
		}
  
		void print()
		{
	   		for(int i = 8; i > 0; i-=3)
			{
	    		cout<<matrix[i-2]<<"|"<<matrix[i-1]<<"|"<<matrix[i];
	    		cout<<"\n";
	   		}
	  	}
		  
  		bool game_state()
		{
   			bool isWin=false;
   			
   			for(int i = 0; i < 3; i++)
			{
    			if (matrix[i]!=' ' && matrix[i] == matrix[i+3] && matrix[i+3] == matrix[i+6])
     				isWin = true;
     
    			if (matrix[i*3]!=' ' && matrix[i*3] == matrix[i*3+1] && matrix[i*3+1] == matrix[i*3+2])
     				isWin = true;
   			}
   			
   			if (matrix[0]!=' ' && matrix[0] == matrix[4] && matrix[4] == matrix[8])
    			isWin = true;
   			if (matrix[6]!=' ' && matrix[6] == matrix[4] && matrix[4] == matrix[2])
    			isWin = true;
    			
   			if (isWin)
			{
   				if (turn)
     				cout<<"O wins!"<<"\n";
    			else
     				cout<<"X wins!"<<"\n";
    			return true;
   			}
   			
   			for(int i = 0; i < 9 ;i++)
			{
   				if (matrix[i]==' ')
   					return false;
				else if (i==8 && !isWin)
				{
					cout<<"Draw!"<<"\n";
    				return true;
				}
			}
   			return false;
  		}
  		
  		int ai_move()
		{
	   		for(int i = 0; i<9; i++)
			{
	   			if(matrix[i] == ' ')
				{
					move(i+1);
						if(game_state())
						{
							cout<<i+1;
							return i+1;
						}
					matrix[i] = ' ';
					turn=!turn;
				}
		   	}
		   	
		   	for(int i = 0; i<9; i++)
			{
	   			if(matrix[i] == ' ')
				{
					return i+1;
				}
		   	}
		}
	
	private:
  		char matrix[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  		bool turn = true;
};
