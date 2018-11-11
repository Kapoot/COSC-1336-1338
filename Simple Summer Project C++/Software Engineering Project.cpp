/*	
	Dylan Kapustka
	Software Engineering Project - Bouncing Ball
	7-10-2018
*/

//Pre-processor Directive
#include <iostream> 
#include <string> //Used for strings
#include <windows.h> //Used for system command
using namespace std; //std library

// Global Declarations
void dframe(int xi, int yi); //Void function used to draw the frame 
void initialize(int xi, int yi); //Initialize or reset the x/y array
string xy[1000][1000]; //array used to store value for xy, 1000 1000 just used to prevent overflow
string frame; //will be used to hold frame

//Begin Main

int main()
{

//Variable Declarations

int xindex = 80; //spaces across the screen horizontally
int yindex = 23; //spaces across the screen vertically
int ballx = 10; //inital x position of ball
int bally = 10; //initial y position of ball
int ballxmem; //holds previous x position of ball
int ballymem; // holds previous y position of ball
bool xstate = true; //bool/switch used to determine which way the ball should be going in x direction
bool ystate = true; //bool/switch used to determine which way the ball should be going in y direction

	//initializes 2d "xy" array with " " spaces
	initialize(xindex, yindex);

	//Begin While-Loop
	
	while (true)
	{
		//If-Statements begin
		//Used to determine physics of the ball
		if (ballx == 0)
		{
			xstate = true;
		}
		if (bally == 0)
		{

			ystate = true;
		}
		if (bally == yindex - 1)
		{

			ystate = false;

		}
		if (ballx == xindex - 1)
		{

			xstate = false;
		}
		if (xstate)
		{
			ballxmem = ballx;
			ballx++;

		}
		else {
			ballxmem = ballx;
			ballx--;
		}
		if (ystate)
		{
			ballymem = bally;
			bally++;
		}
		else {
			ballymem = bally;
			bally--;
		}
		//Takes the previous position of the ball and replaces it with a " " to stop artifacts/tracers.
		xy[ballxmem][ballymem] = " ";
		//Sets the new xy coordinates for the ball
		xy[ballx][bally] = "O";
		//Clearscreen
		system("cls");
		//Uses the values stored in the "xy" array to draw the frame
		dframe(xindex, yindex);
		//Add a sleep timer of 80ms to keep a limit on the program's speed 
		Sleep(80);
	}
	//End
	return 0;

}
//Void Function for initalizing and resetting the frame to its blank state
void initialize(int xi, int yi)
{
	for (int y = 0; y<yi; y++)
	{
		for (int x = 0; x<xi; x++)
		{
			xy[x][y] = " ";


		}
	}


}

//Void Function to read values of the xy array and appends them to a frame variable, then prints it. 
void dframe(int xi, int yi)
{
	frame = "";

	for (int y = 0; y<yi; y++)
	{

		for (int x = 0; x<xi; x++)
		{
			frame = frame + xy[x][y];


		}
		frame = frame + "\n";
	}

	cout << frame;

}

//Fin