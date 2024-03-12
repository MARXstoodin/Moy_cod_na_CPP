#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
 	Board a; 
	int n;
	bool t = true;
	
 	while(1)
	{
  		a.print();
  		
	  	if(a.game_state())
	   		break;
	   	
	   	if(t)
	   	{
	  		cin>>n;
	   		try 
			{
		   		a.move(n);
	  		}
	  		catch(string exeption)
			{
	   			cout<<exeption<<"\n";
	  		}
		}
	  	else
	  		a.ai_move();
	  	t=!t;
	  	system("cls");
	  	
 	}
 	return 0;
}
