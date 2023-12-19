#include <iostream>
using namespace std;

void increment(int* a)
{
	*a += 1;
}

int main()
{
	int a;
	cin >> a;
	cout << "a=" << a << "\n";
	increment(&a);
	cout << "a=" << a;
	return 0;
}
