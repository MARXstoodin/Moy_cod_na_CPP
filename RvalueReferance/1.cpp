#include<iostream>

void foo(int& a)
{
	a+=1;
}

int main()
{
	int a = 8;
	std::cout<<a<<"\n";
	foo(a);
	std::cout<<a<<"\n";
}
