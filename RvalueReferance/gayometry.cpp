#include<iostream>

class shape
{
	public:
		int area(int a, int b)
		{
			return a*b;
		}
	
	protected:
		shape()
		{
			
		};
};

class square:public shape
{
	public:
		
		square():shape()
		{
			
		};
	
		int a, b;
};

int main()
{
	//shape nasral;
	square* a = new square;
	a->a = 11;
	a->b = 4;
	std::cout<<a->area(a->a,a->b);
	return 0;
}
