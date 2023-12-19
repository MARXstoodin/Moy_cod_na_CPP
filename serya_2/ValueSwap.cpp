#include <iostream>
using namespace std;

void smartSwap(void* a, void* b, size_t size)
{
	char* ac = (char*)a;
	char* bc = (char*)b;
	char cc[size];
	for(int i = 0; i < size ; i++)
	{
		cc[i] = ac[i];
		ac[i] = bc[i];
		bc[i] = cc[i];
	}
}
int main()
{
	int****jopa;
	cout << jopa << "\n";
	cout << &jopa << "\n";
	cout << (&)&jopa << "\n";
	cout << &jopa << "\n";
	int a;
	int b;
	cin >> a >> b;
	cout << "a=" << a << " b=" << b << "\n";
	smartSwap(&a, &b, sizeof(a));
	cout << "a=" << a << " b=" << b;
	return 0;
}
