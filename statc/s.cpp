#include <iostream>

using namespace std;

void foo()
{
	static int a = 5;
	cout<<a<<"\n";
	a++;
}

int* goo()
{
	static int* a = new int;
	*a = 99;
	cout<<*a<<"\n";
	*a++;
	return a;
}

int main()
{
	int* b = goo();
	
	cout<<b<<" "<<*b<<"\n";
	
	goo();
	
	cout<<b<<" "<<*b<<"\n";
	return 0;
}
