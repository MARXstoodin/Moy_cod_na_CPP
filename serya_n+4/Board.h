#include<iostream>

using namespace std;

class Board{
	public:
		void set(int num){
			
			if(9<num||num<1)
				throw string("INACCEPTABLE NUM");
				
			num--;
				
			if(matrix[num]!=' ')
				throw string("PLACE OCCUPIED");
			
				
			switch(turn){
				case true: matrix[num]='X';
					break;
				case false: matrix[num]='O';
					break;
			}
			
			turn=!turn;
		}
		
		void print(){
			for(int i = 8; i > 0; i-=3){
				cout<<matrix[i-2]<<"|"<<matrix[i-1]<<"|"<<matrix[i];
				cout<<"\n";
			}
		}
		
		void game_state(){
			bool isWin=false;
			for(int i = 0; i < 3; i++){
				if (matrix[i]!=' ' and matrix[i] == matrix[i+3] and matrix[i+3] == matrix[i+6])
					isWin = true;
					
				if (matrix[i]!=' ' and matrix[i] == matrix[i+1] and matrix[i+1] == matrix[i+2])
					isWin = true;
			}
			if (isWin){
				if (turn)
					cout<<"O wins!"<<"\n";
				else
					cout<<"X wins!"<<"\n";
			}
		}
		
	private:
		char matrix[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
		bool turn = true;
};
