#include<iostream>

class a
{
	public:
		virtual int foo()
		{
			return 1;
		}
};

class b:a
{
	public:
		int foo()
		{
			return 2;
		}
};

int main(){
	a alpha;
	b beta;
	std::cout<<alpha.foo();
	std::cout<<beta.foo();
	return 0;
}
