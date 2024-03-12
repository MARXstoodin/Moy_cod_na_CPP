#include "snake.h"
#include <iostream>
#include <graphics.h>

int main()
{
	Board board(25,25);
	board.set(0, 0, 'X');
	board.print();
}
