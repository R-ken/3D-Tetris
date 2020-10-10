#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "Board.h"

using namespace std;

// x and y values to resize the game window screen
int xwindowsize = 400;
int ywindowsize = 720;

int xtile = 33 * ((rand() % 10) + 1);
int tileshape = (rand() % 4) + 1;
int tilecolor = rand()%5 + 1;
int tilecolor2 = rand()%5 + 1;
int tilecolor3 = rand()%5 + 1;
int tilecolor4 = rand()%5 + 1;

float colorvec[100][3] = {0.0};
float colorvec2[100][3] = {0.0};
float colorvec3[100][3] = {0.0};
float colorvec4[100][3] = {0.0};
int allColor[661][331] = {0}; // keeps the tilecolor number for each square to check for elimination
int colorCount = 0;

bool gameOver = false;
int gameSession = 0;

bool paused = false;
int acc_speed = timerspeed;

bool setColor = false; //false means color is not chosen yet
bool setShape = false; //false means shape is not chosen yet
bool settleDown = false; //false means tile has not reached bottom
bool xposSet = false;  //false means starting x position not chosen yet

int srandCount = 1;

bool setRotate = false;

int k = 16; // used to set allColor in setTile function

void changeColor() // choose a color for the tile
{
	if (setColor == false)
	{
		tilecolor = rand()%5 + 1;
		if(tilecolor == 1)  //purple
		{
			colorvec[colorCount][0] = 128.0;
			colorvec[colorCount][1] = 0.0;
			colorvec[colorCount][2] = 128.0;
		}
		else if(tilecolor == 2)  //red
		{
			colorvec[colorCount][0] = 255.0;
			colorvec[colorCount][1] = 0.0;
			colorvec[colorCount][2] = 0.0;
		}
		else if(tilecolor == 3)  //yellow
		{
			colorvec[colorCount][0] = 1.0;
			colorvec[colorCount][1] = 1.0;
			colorvec[colorCount][2] = 0.5;
		}
		else if(tilecolor == 4)  //green
		{
			colorvec[colorCount][0] = 0.0;
			colorvec[colorCount][1] = 128.0;
			colorvec[colorCount][2] = 0.0;
		}
		else if(tilecolor == 5)  //orange
		{
			colorvec[colorCount][0] = 1.0;
			colorvec[colorCount][1] = 0.5;
			colorvec[colorCount][2] = 0.0;
		}

		tilecolor2 = rand()%5 + 1;
		if(tilecolor2 == 1)  //purple
		{
			colorvec2[colorCount][0] = 128.0;
			colorvec2[colorCount][1] = 0.0;
			colorvec2[colorCount][2] = 128.0;
		}
		else if(tilecolor2 == 2)  //red
		{
			colorvec2[colorCount][0] = 255.0;
			colorvec2[colorCount][1] = 0.0;
			colorvec2[colorCount][2] = 0.0;
		}
		else if(tilecolor2 == 3)  //yellow
		{
			colorvec2[colorCount][0] = 1.0;
			colorvec2[colorCount][1] = 1.0;
			colorvec2[colorCount][2] = 0.5;
		}
		else if(tilecolor2 == 4)  //green
		{
			colorvec2[colorCount][0] = 0.0;
			colorvec2[colorCount][1] = 128.0;
			colorvec2[colorCount][2] = 0.0;
		}
		else if(tilecolor2 == 5)  //orange
		{
			colorvec2[colorCount][0] = 1.0;
			colorvec2[colorCount][1] = 0.5;
			colorvec2[colorCount][2] = 0.0;
		}

		tilecolor3 = rand()%5 + 1;
		if(tilecolor3 == 1)  //purple
		{
			colorvec3[colorCount][0] = 128.0;
			colorvec3[colorCount][1] = 0.0;
			colorvec3[colorCount][2] = 128.0;
		}
		else if(tilecolor3 == 2)  //red
		{
			colorvec3[colorCount][0] = 255.0;
			colorvec3[colorCount][1] = 0.0;
			colorvec3[colorCount][2] = 0.0;
		}
		else if(tilecolor3 == 3)  //yellow
		{
			colorvec3[colorCount][0] = 1.0;
			colorvec3[colorCount][1] = 1.0;
			colorvec3[colorCount][2] = 0.5;
		}
		else if(tilecolor3 == 4)  //green
		{
			colorvec3[colorCount][0] = 0.0;
			colorvec3[colorCount][1] = 128.0;
			colorvec3[colorCount][2] = 0.0;
		}
		else if(tilecolor3 == 5)  //orange
		{
			colorvec3[colorCount][0] = 1.0;
			colorvec3[colorCount][1] = 0.5;
			colorvec3[colorCount][2] = 0.0;
		}

		tilecolor4 = rand()%5 + 1;
		if(tilecolor4 == 1)  //purple
		{
			colorvec4[colorCount][0] = 128.0;
			colorvec4[colorCount][1] = 0.0;
			colorvec4[colorCount][2] = 128.0;
		}
		else if(tilecolor4 == 2)  //red
		{
			colorvec4[colorCount][0] = 255.0;
			colorvec4[colorCount][1] = 0.0;
			colorvec4[colorCount][2] = 0.0;
		}
		else if(tilecolor4 == 3)  //yellow
		{
			colorvec4[colorCount][0] = 1.0;
			colorvec4[colorCount][1] = 1.0;
			colorvec4[colorCount][2] = 0.5;
		}
		else if(tilecolor4 == 4)  //green
		{
			colorvec4[colorCount][0] = 0.0;
			colorvec4[colorCount][1] = 128.0;
			colorvec4[colorCount][2] = 0.0;
		}
		else if(tilecolor4 == 5)  //orange
		{
			colorvec4[colorCount][0] = 1.0;
			colorvec4[colorCount][1] = 0.5;
			colorvec4[colorCount][2] = 0.0;
		}

		colorCount++;
		setColor = true;
	}
}

void changeShape()
{
	if(setShape == false)
	{
		tileshape = (rand() % 4) + 1;

		setShape = true;
	}
}

int linearSearch(int x, int y)
{
	// begins at 16 because the first 16 are not used to keep tiles
	for(int i = 16; i<= 480; i++)
	{
		if (vertex[i] == x)
		{
			if(vertex[i+1] == y)
			{
				return i;
			}
		}
	}
}

void eliminate()
{
	//variables to hold the color in the square (3 in a row)
	int color1 = 0;
	int color2 = 0;
	int color3 = 0;
	// go through all values of allColor in a loop and check for three in a row
	//first check three in a row (horizontal)
	for (int i = 33; i <= 660; i += 33) // up to 594 because checking 3 in a row
	{
		for (int j = 33; j <= 264; j += 33)
		{
			if (allColor[i][j] != 0)
			{
				color1 = 0;
				color2 = 0;
				color3 = 0;
				color1 = allColor[i][j];
				color2 = allColor[i][j+33];
				color3 = allColor[i][j+66];

				if(color1 == color2 && color2 == color3)// if there are three matching colors horizontal
				{
					// check the squares above it and if it is occupied, move it down by one
					// then move onto the next eliminated square
					// all kept squares are stored in the "vertex" array variable 
					// but they are not kept in order...
					// the kept colors will also have to be modified

					int x = j;    // lower left vertex of current square
					int y = i;
					int y2 = i+33; //lower left vertex of square above
					int x3 = j+33;  // upper right vertex of current square
					int y3 = i+33;
					int y4 = i+66; //upper right vertex of square above
					int index = 0;
					int index2 = 0;
					int index3 = 0;
					int index4 = 0;

					// elminate first square of the three
					while(check_occupied[y2][x] == true)   // move the square above down while there is one above it
					{
						index = linearSearch(x,y);
						index2 = linearSearch(x,y2);

						index3 = linearSearch(x3,y3);
						index4 = linearSearch(x3,y4);

						// replace eliminated square with the one above it
						vertex[index] = vertex[index2];
						vertex[index+1] = vertex[index2+1];

						vertex[index3] = vertex[index4];
						vertex[index3+1] = vertex[index4+1];

						check_occupied[y][x] = true;

						y += 33;
						y2 += 33;
						y3 += 33;
						y4 += 33;

						//do the color changes
						if((index % 16) <= 3 && (index % 16) >= 0)
						{

						}
						else if((index % 16) <= 7 && (index % 16) >= 4)
						{

						}
						else if((index % 16) <= 11 && (index % 16) >= 8)
						{
							
						}
						else if((index % 16) <= 15 && (index % 16) >= 12)
						{
							
						}
					}


				 	// set the current j,i square to false occupied
					index = linearSearch(x,y);
					index3 = linearSearch(x3,y3);

					vertex[index] = 0;
					vertex[index+1] = 0;

					vertex[index3] = 0;
					vertex[index3+1] = 0;

					check_occupied[x][y] = false;
					


					 // cout << index << endl;
					 // cout << x << " " << y << endl;
					 // cout << vertex[index] << " " << vertex[index+1]<< endl;
				}
			}
		}
	}
}

void setTile()
{
	if (settleDown == false)
	{
		setxtile(xtile);
		if (tileshape == 1) // if tile chosen is I shape
		{
			shape1();
		}
		else if (tileshape == 2) // S shape
		{
			shape2();
		}
		else if (tileshape == 3) // L Shape
		{
			shape3();
		}
		else if(tileshape == 4)//T Shape
		{
			shape4();
		}
		else if(tileshape == 5)
		{
			shape5();
		}
		else if(tileshape == 6)
		{
			shape6();
		}
		else if(tileshape == 7)
		{
			shape7();
		}
		else if(tileshape == 8)
		{
			shape8();
		}
		else if(tileshape == 9)
		{
			shape9();
		}
		else if(tileshape == 10)
		{
			shape10();
		}
		else if(tileshape == 11)
		{
			shape11();
		}
		else if(tileshape == 12)
		{
			shape12();
		}

		if(settled == true)
		{
			settleDown = true;
		}
	}
	else
	{
		//keep track of the tilecolor for each square in allColor
		allColor[vertex[k+1]][vertex[k]] = tilecolor;
		allColor[vertex[k+5]][vertex[k+4]] = tilecolor2;
		allColor[vertex[k+9]][vertex[k+8]] = tilecolor3;
		allColor[vertex[k+13]][vertex[k+12]] = tilecolor4;
		k += 16;

		//eliminate();

		setColor = false;
		setShape = false;
		currenttile = 693;
		xtile = 33 * ((rand() % 10) + 1);
		settleDown = false;
		settled = false;

		timerspeed = acc_speed;
	}
}

bool checkGameOver()
{
	if(verCounter > 462)
	{
		gameOver = true;
	}

	for(int i = 33; i <=330; i+=33)
	{
		if (check_occupied[693][i] == true)
		{
			gameOver = true;
		}
	}
	return gameOver;
}

void checkRotate()
{
	if(setRotate == true && tileshape == 1) // if shape is I and want to rotate
	{
		if(xtile != 33)  //if xtile is 33,297, or 330: do not rotate
		{
			if(xtile != 330)
			{
				if(xtile != 297)
				{
					tileshape = 5; // special tileshape case, rotate I
				}
			}
		}
	}  
	else if (setRotate == true && tileshape == 5) // if shape is I and rotated, rotate back
	{
		tileshape = 1;
	}
	else if (setRotate == true && tileshape == 2)
	{
		if(xtile != 33)
		{
			if(xtile != 330)
			{
				tileshape = 6;
			}
		}
	}
	else if (setRotate == true && tileshape == 6)
	{
		tileshape = 2;
	}
	else if (setRotate == true && tileshape == 3)
	{
		if (xtile == 297 || xtile == 330)
		{
			xtile = 264;
			tileshape = 7;
		}
		else
		{
			tileshape = 7;
		}
	}
	else if (setRotate == true && tileshape == 7)
	{
		if (xtile == 33)
		{
			tileshape = 7;
		}
		else if (xtile == 330)
		{
			xtile = 297;
			tileshape = 8;
		}
		else
		{
			tileshape = 8;
		}
	}
	else if(setRotate == true && tileshape == 8)
	{
		tileshape = 9;
	}
	else if(setRotate == true && tileshape == 9)
	{
		tileshape = 3;
	}
	else if(setRotate == true && tileshape == 4)
	{
		if(xtile == 330)
		{
			xtile -= 66;
			tileshape = 10;
		}
		else if(xtile == 297)
		{
			xtile -= 33;
			tileshape = 10;
		}
		else
		{
			tileshape = 10;
		}
	}
	else if(setRotate == true && tileshape == 10)
	{
		tileshape = 11;
	}
	else if(setRotate == true && tileshape == 11)
	{
		tileshape = 12;
	}
	else if(setRotate == true && tileshape == 12)
	{
		tileshape = 4;
	}

	setRotate = false;
}

void newGame()
{
	// Current Idea
	// choose a random square by choosing a random x-pixel value (in steps of 33 to 330)
	// depending on the x value chosen, we would then choose a random block shape (1,2,3,or 4 for the I,S,L,T)
	// then color in the blocks accordingly to the pixel values
	// also choose a random color of the "fruits"
	// would also need to check if the blocks would generate past the edges of the board
	// blocks would then stop at the bottom

	if(!checkGameOver())
	{
		changeColor();
		changeShape();
		checkRotate();
		setTile();
	}
	else
	{
		cout << "Game Over. Press r to restart or q to exit" << endl;
	}
}

void grid() {
	glClear(GL_COLOR_BUFFER_BIT); //gets the assigned window color displayed to the values in glClearColor

	// set squares and  colors
	for (int i = 0; i <= 480; i += 16)
	{
		glRecti (vertex[i],vertex[i+1], vertex[i+2], vertex[i+3]);
		glRecti (vertex[i+4],vertex[i+5], vertex[i+6], vertex[i+7]);
		glRecti (vertex[i+8],vertex[i+9], vertex[i+10], vertex[i+11]);
		glRecti (vertex[i+12],vertex[i+13], vertex[i+14], vertex[i+15]);
	}

	// only color the ones falling from the top
	glColor3f (colorvec[colorCount-1][0], colorvec[colorCount-1][1], colorvec[colorCount-1][2]);
	glRecti (vertex[0],vertex[1], vertex[2], vertex[3]);

	glColor3f (colorvec2[colorCount-1][0], colorvec2[colorCount-1][1], colorvec2[colorCount-1][2]);
	glRecti (vertex[4],vertex[5], vertex[6], vertex[7]);

	glColor3f (colorvec3[colorCount-1][0], colorvec3[colorCount-1][1], colorvec3[colorCount-1][2]);
	glRecti (vertex[8],vertex[9], vertex[10], vertex[11]);

	glColor3f (colorvec4[colorCount-1][0], colorvec4[colorCount-1][1], colorvec4[colorCount-1][2]);
	glRecti (vertex[12],vertex[13], vertex[14], vertex[15]);

	// keep the colors of the tiles that are already set
	int k = 16;
	for (int j = 0; j <= 99 ; j++)
	{
		if (k <= 480)
		{
			glColor3f (colorvec[j][0], colorvec[j][1], colorvec[j][2]);
			glRecti (vertex[k],vertex[k+1], vertex[k+2], vertex[k+3]);

			glColor3f (colorvec2[j][0], colorvec2[j][1], colorvec2[j][2]);
			glRecti (vertex[k+4],vertex[k+5], vertex[k+6], vertex[k+7]);

			glColor3f (colorvec3[j][0], colorvec3[j][1], colorvec3[j][2]);
			glRecti (vertex[k+8],vertex[k+9], vertex[k+10], vertex[k+11]);

			glColor3f (colorvec4[j][0], colorvec4[j][1], colorvec4[j][2]);
			glRecti (vertex[k+12],vertex[k+13], vertex[k+14], vertex[k+15]);

			k += 16;
		}
	}

	// set the lines after the square so the lines are not covered by the squares
	glColor3f(1.0, 1.0, 1.0);  //choose a variety of color schemes for the objects we want to display in a scene
	glBegin(GL_LINES);	//argument in Begin is used to identify the kinf of output primitive that is to be displayed

		//draw all vertical lines first
		for(int i = 33; i <= 363; i += 33)
		{
			glVertex2i (i, 33);
			glVertex2i (i, 693);
		}

		//draw all horizontal lines
		for (int i = 33; i <= 726; i+= 33)
		{
			glVertex2i (33, i);
			glVertex2i (363, i);
		}

	glEnd();

	glutPostRedisplay();
	glutSwapBuffers();
}

void Timer (int i){
	if(i != gameSession)
	{
		return;
	}

	if(!gameOver && !paused)
	{
		newGame();
	}

	glutTimerFunc(timerspeed, Timer, gameSession);
}

void idle(void)
{
	glutPostRedisplay();
}

void init() {	// places all initializations and related one-time paramter settings 
	glClearColor(0.0, 0.0, 0.0, 0.0);  //sets background color
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 396.0, 0.0, 726.0); //these two commands creates a 2D plane and pastes the picture onto the window
										//with x values from 0 - 200 and y values 0 -150 (the size of the plane)
}

void restart()
{
	xtile = 33 * ((rand() % 10) + 1);
	tileshape = (rand() % 4) + 1;
	tilecolor = rand()%5 + 1;
	tilecolor2 = rand()%5 + 1;
	tilecolor3 = rand()%5 + 1;
	tilecolor4 = rand()%5 + 1;

	setColor = false;
	setShape = false; 
	settleDown = false; 
	xposSet = false;  

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			colorvec[i][j] = {0.0};
			colorvec2[i][j] = {0.0};
			colorvec3[i][j] = {0.0};
			colorvec4[i][j] = {0.0};
		}
	}
	colorCount = 0;

	gameOver = false;
	gameSession = 0;

	srandCount = 1;

	currenttile = 693;
	xpos = 0;
	timerspeed = 1000;

	for (int i = 0; i < 481; i++)
	{
		vertex[i] = {0};
	}
	verCounter = 16;

	for (int i = 0; i < 694; i++)
	{
		for (int j = 0; j < 364; j++)
		{
			check_occupied [i][j] = {false};
		}
	}

	for ( int i = 0; i <= 660; i++)
	{
		for ( int j = 0; j <= 330; j++)
		{
			allColor[i][j] = 0;
		}
	}

	settled = false;
}

void arrow(int key, int x, int y)
{

	switch(key)
	{
		case GLUT_KEY_UP:  //rotate counterclockwise
			setRotate = true;
			//rotate();
			break;
		case GLUT_KEY_LEFT: //move left 1 tile
			if(tileshape == 5)
			{
				if(xtile != 66)
				{
					xtile -= 33;
				}
			}
			if(tileshape == 7)
			{
				if(xtile != 0)
				{
					xtile -= 33;
				}
			}
			else if(tileshape == 10)
			{
				if(xtile != 0)
				{
					xtile -= 33;
				}
			}
			else
			{
				if(xtile != 33)
				{
					xtile -= 33;
				}
			}
			break;
		case GLUT_KEY_RIGHT: // move right one tile
			if(tileshape == 5)
			{
				if(xtile != 264)
				{
					xtile += 33;
				}
			}
			else if(tileshape == 7)
			{
				if(xtile != 264)
				{
					xtile +=33;
				}
			}
			else if(tileshape == 8)
			{
				if(xtile != 264)
				{
					xtile +=33;
				}
			}
			else if(tileshape == 9)
			{
				if(xtile != 297)
				{
					xtile += 33;
				}
			}
			else if(tileshape == 10 || tileshape == 11)
			{
				if(xtile != 264)
				{
					xtile += 33;
				}
			}
			else if(tileshape == 12)
			{
				if(xtile != 297)
				{
					xtile += 33;
				}
			}
			else
			{
				if(xtile != 330)
				{
					xtile += 33;
				}
			}
			break;
		case GLUT_KEY_DOWN: // speed up the current tile but reset speed after it is set
			if(timerspeed >= 150)
			{
				timerspeed -= 100;
			}
			break;
	}
}

void extra(unsigned char key, int x, int y)
{

	switch(key)
	{
		case 'a':  //accelerate game
			if(timerspeed >= 150)
			{
				timerspeed -= 100;
			}
			acc_speed = timerspeed;
			break;
		case 'r': //restart game
			restart();
			break;
		case 'q':
			exit (EXIT_SUCCESS);
			break;
		case 'p':
			if(paused == false)
			{
				paused = true;
			}
			else
			{
				paused = false;
			}
			break;
	}

	glutPostRedisplay();
}

int main (int argc, char** argv) {	//contains the GLUT functions for setting up the display window and getting our line segment onto the screen
	if(srandCount == 1)
	{
		srand(time(NULL));
		srandCount++;
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(680, 178); // 680 pixels from the left/right of screen and 178 pixels from the top/bottom of screen
	glutInitWindowSize(xwindowsize, ywindowsize); //resize the window (x,y)
	glutCreateWindow("Falling Fruits Tetris");
	init();

	glutDisplayFunc(grid);
	glutSpecialFunc(arrow);
	glutKeyboardFunc(extra);
	glutTimerFunc(timerspeed, Timer, gameSession);
	glutIdleFunc(idle);
	glutMainLoop(); //It displays the initial graphics
					//and puts the program into an infinite loop that checks for input from devices such
					//as a mouse or keyboard

	return 0;
}
