#include <iostream>
using namespace std;


int
main (void)
{

  int array[100][100];
  int x, y, num;
  cout << "Enter a number up to 25:" << endl;
  cin >> num;
  for (x = 0; x <= num; x++)
    {
      for (y = 0; y <= num; y++)
	{
	  array[x][y] = x + y;
	}
    }
  for (x = 1; x <= num; x++)
    {
      for (y = 1; y <= num; y++)
	{
	  array[x][y] = array[(x - 1)][y - 1] + array[x - 1][(y)];
	}
    }

  for (x = 0; x <= num; x++)
    {
      for (y = 0; y <= num; y++)
	{
	  cout << array[x][y] << " ";
	}
      cout << endl;
    }
}
