#include <iostream>
#define FR for(int i = 0; i<10 ; i++)
using namespace std;

int main()
{
	char a[255];
	cin >> a;
	int i2 = 0;
	for(int i = 0; i<255 ; i++)
	{
		if(a[i]==' ')
		{
			i2++;
			cout << i2 <<"\n";
		}
	}
	//int b[i2];
	system("pause");
	return 0;
}
