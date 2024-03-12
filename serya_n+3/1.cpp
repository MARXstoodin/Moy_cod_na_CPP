#include <iostream>
#include <typeinfo>

using namespace std;
/*
int add(int a, int b){
	return a + b;
}

double add(double a, double b){
	return a + b;
}

string add(string a, string b){
	return a + b;
}
*/
template <typename T>
T add(T a, T b){
	cout<<typeid(T).name()<<"\n";
	return a + b;
}

int main(){
	cout<<add(5, 2)<<" "<<add(0.5, 0.2)<<" "<<add<string>("5", "2");
}
