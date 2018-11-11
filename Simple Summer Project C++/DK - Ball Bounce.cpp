#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

	char ball[23][80];
	int coord[23][80];
	int origX;
	int origY;
	char mov1;
	char mov2;
	int x;
	int y;

	int x_Direction = 1 * 1;	//initially towards right
	int y_Direction = 1 * 1;	//initially towards down

	memset(ball, ' ', 80 * 23);

	cout << "Enter the X coordinate for the ball (between 0 and 79): ";
	//cin >> origX;
	origX = 20;
	cout << endl;
	cout << "Enter the Y coordinate for the ball (between 0 and 22): ";
	//cin >> origY;
	origY = 10;
	cout << endl;
	//cout << "Would you like the ball to move [u]p or [d]own? ";
	//cin >> mov1;
	cout << endl;
	//cout << "would you like the ball to move [l]eft or [r]ight? ";
	//cin >> mov2;
	cout << endl;

	x = origX;
	y = origY;


	ball[y][x] = 'O';


	/*if (mov1 == 'u')
	y--;

	if (mov1 == 'd')
	y++;

	if (mov2 == 'r')
	x++;

	if (mov2 == 'l')
	x--;*/


	//ball[x][y] = 'O';

	do
	{
		y += y_Direction;
		x += x_Direction;

		if (x >= 78 || x <= 0)
			x_Direction *= 1 * -1;	//reverse direction on the edges

		if (y >= 21 || y <= 0)
			y_Direction *= 1 * -1;	//reverse direction on the edges

									/*if (mov1 == 'u')
									y--;

									if (mov1 == 'd')
									y++;

									if (mov2 == 'r')
									x++;

									if (mov2 == 'l')
									x--;

									if (x == 79)
									x--;

									if (x == 0)
									x++;

									if (y == 22)
									y--;

									if (y == 0)
									y++;*/

		memset(ball, ' ', 80 * 23);

		ball[y][x] = 'O';

		//draw screen
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 79; j++)
				cout << ball[i][j];

			cout << endl;
		}


		system("CLS");
		//}while ((x != origX) && (y != origY));
	} while (1);

	cin.get();
	cin.get();

	return 0;
}