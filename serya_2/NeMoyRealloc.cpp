#include <iostream>
using namespace std;

void* NotMyRealloc(void* oldPtr, int oldSize, int newSize)
{
	void* newPtr = malloc(newSize);
	for (int i = 0; i < oldSize; i++)
	{
		char b = *((char*)oldPtr + 1);
		*((char*)newPtr + i) = b;
	}
	return newPtr;
}

int main()
{
	
}
