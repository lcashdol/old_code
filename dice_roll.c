#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int
main (void)
{
  int max = 0;
  int x, i;
  double y, y1;
  int q;
  int input;
  int die_data[13];
  char die_board[13][101];

  for (x = 0; x < 13; x++)
    die_data[x] = 0;

  for (x = 0; x < 13; x++)
    {
      for (q = 0; q < 101; q++)
	{
	  die_board[x][q] = '.';
	}
    }

  printf ("Enter number of dice rolls: ");
  scanf ("%d", &input);
  srandom (time (NULL));
  for (x = 0; x < input; x++)
    {
      y = (random () % 6) + 1;
      y1 = (random () % 6) + 1;
      y = y + y1;
      die_data[(int) y]++;
      printf ("Roll %d is:%d\n", x + 1, (int) y);
    }
  printf ("[            Data        ]\n");
  for (x = 2; x <= 12; x++)
    {
      if (die_data[x] > max)
	max = die_data[x]; /*find out greatest element in the array, use this +5
                             as top end of graph height.*/
      printf ("%5d -> %d \n", x, die_data[x]);
    }
  printf ("[            Graph1        ]\n");
  for (i = 2; i <= 12; i++)
    {
      printf ("%5d %5d - ", i, die_data[i]);
      for (x = 0; x < die_data[i]; x++)
	{
	  if (die_data[i] > 0)
	    printf ("#");
	  else
	    printf (" ");
	}
      printf ("\n");
    }
  printf ("[            Graph2        ]\n");

/*Populate the graph and print the graph from the top down*/
  for (x = 2; x <= 12; x++)
    {
      for (q = 0; q <= die_data[x]; q++)
	{
	  die_board[x][q] = '#';
	}
    }
  for (q = max + 5; q > 0; q--)
    {
      printf ("%3d -", q);
      for (x = 2; x <= 12; x++)
	{
	  printf ("%c", die_board[x][q]);
	}
      printf ("\n");
    }
  printf ("     2          12\n");
}
