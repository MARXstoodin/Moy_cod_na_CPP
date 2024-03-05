#include <iostream>
#include <thread>
#include <conio.h>
#include <mutex>

char matrix[11][11];
int curX = 5, curY = 5;

void print()
{
 system("cls");
 for (int x = 0; x < 11; x++)
 {
  for (int y = 0; y < 11; y++)
  {
   std::cout << " " << matrix[x][y];
  }
  std::cout << std::endl;
 }
}

void move()
{
 while (1)
 {
  switch (_getch())
  {
  case 'w':
    curY++;
   break;
  case 'a':
    curY--;
   break;
  case 's':
    curX++;
   break;
  case 'd':
    curX--;
   break;
  }
 }
}

int main(int argc, char *argv[])
{
 for (int x = 0; x < 11; x++)
 {
  for (int y = 0; y < 11; y++)
  {
   matrix[x][y] = ' ';
  }
 }
 matrix[5][5] = '0';

 std::thread thr1(print);
 move();

 return 0;
}
