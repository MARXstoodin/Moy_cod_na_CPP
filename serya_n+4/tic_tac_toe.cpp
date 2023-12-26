#include<iostream>
#include "Board.h"

using namespace std;

int main(){
	Board alpha;
	
	int a;
	
	while(1){
		alpha.game_state();
		alpha.print();
		cin>>a;
		system("cls");
		try {
			alpha.set(a);
		}
		catch(string exeption){
			cout<<exeption<<"\n";
		}
	}
	return 0;
}
