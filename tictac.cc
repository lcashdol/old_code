/*larry cashdollar tic tac toe
  for dave's hwk help. 11/7/2012*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std; 

char board[3][3];
int game_won (char b[3][3]);
void print_board (char b[3][3]);

int
main (void)
{
  int x = 0, y = 0, p1, p2, turn = 1;
  char player;
  for (x = 0; x < 3; x++)
    {
      for (y = 0; y < 3; y++)
	{
	  board[x][y] = '.';
	}
    }
  while (1)
    {
      print_board (board);
      if (turn % 2)
	player = 'O';
      else
	player = 'X';
    cout << "############################\nTurn :"<< turn<<endl;
      cout<< "Enter a X coordinate for player "<< player<<endl;
      cin>>p1;
      cout <<"Enter an Y coordinate for player "<< player<<endl;
      cin>>p2;
      if (board[p1][p2] == '.' && p1 <=2 && p1 >= 0 && p2 <= 2 && p2 >= 0)
	board[p1][p2] = player;
      turn++;
      if (game_won (board))
	{
	  print_board (board);
	   cout <<endl<<"-= Game Over =-"<<endl;
	  exit (0);
	}
    }
}

void
print_board (char b[3][3])
{
  int x, y;
  cout<<"##############################"<<endl;
  for (x = 0; x < 3; x++)
    {
      for (y = 0; y < 3; y++)
	{ if (y>0)cout <<"|";
	  cout<<b[x][y];

	}
      cout<<endl<<"-+-+-+"<<endl;
    }
}

int
game_won (char b[3][3])
{
  int x, y;
  int xwin = 0;
  int owin = 0;
  int uxwin = 0;
  int uowin = 0;

  for (x = 0; x <= 2; x++)
    {
      for (y = 0; y <= 2; y++)
	{
	  if (b[x][y] == 'X')
	    xwin++;
	  if (b[x][y] == 'O')
	    owin++;
	  if (b[y][x] == 'X')
	    uxwin++;
	  if (b[y][x] == 'O')
	    uowin++;
	}
  /*print the win stat matrix */
 // cout << setfill('-')<<setw(20)<<endl;
  cout << setw(2)<< xwin<< setw(2)<< owin<< setw(2)<< uxwin << setw(2) <<uowin<<endl;

  if (xwin == 3 || uxwin == 3)
    {
      cout <<"Player X has won with a straight win!"<<endl;
      return (1);
    }
  if (owin == 3 || uowin == 3)
    {
      cout<< "Player O has won with a straight win!"<<endl;
      return (1);
    }

      xwin = 0, owin = 0, uxwin = 0, uowin = 0;
    }
  xwin = 0;
  owin = 0;

  for (x = 0; x <= 2; x++)
    {
      if (b[x][x] == 'X')
	xwin++;
      if (b[x][x] == 'O')
	owin++;
    }
  if (xwin == 3)
    {
      cout<< "Player X has won with a diagonal win!"<<endl;
      return (1);
    }
  if (owin == 3)
    {
      cout << "Player O has won with a diagonal win!"<<endl;
      return (1);
    }
  xwin = 0;
  owin = 0;
  y = 2;
  for (x = 0; x <= 2; x++)
    {
      if (b[x][y] == 'X')
	xwin++;
      if (b[x][y] == 'O')
	owin++;
      y--;
    }
  if (xwin == 3)
    {
      cout << "Player X has won with a diagonal win!"<<endl;
      return (1);
    }
  if (owin == 3)
    {
      cout << "Player O has won with a diagonal win!"<<endl;
      return (1);
    }
  return (0);

}
