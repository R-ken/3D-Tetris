#include <math.h>

using namespace std;

int currenttile = 693;
int xpos = 0;
int timerspeed = 1000;

//int gameround = 0;
// each vertice has x and y, so 22*21 vertex coordinates
int vertex[481] = {0};
int verCounter = 16;

//2D array used to check if a square is occupied
//used for stacking purposes
//call using the lower left vertex (x,y) to check if true or false
//true means it is in use
//false means it is not in use
bool check_occupied [694][364] = {false};

bool settled = false;


GLint setTiles[462] = {0};
int counter = 0;

void setxtile(int value)
{
	xpos = value;
}

void keepTile1() // keep tile I shape
{
	currenttile += 33;

	vertex[verCounter] = xpos;
	vertex[verCounter+4] = xpos;
	vertex[verCounter+8] = xpos;
	vertex[verCounter+12] = xpos;

	vertex[verCounter+1] = currenttile - 33;
	vertex[verCounter+5] = currenttile - 66;
	vertex[verCounter+9] = currenttile - 99;
	vertex[verCounter+13] = currenttile - 132;

	vertex[verCounter+2] = xpos + 33;
	vertex[verCounter+6] = xpos + 33;
	vertex[verCounter+10] = xpos + 33;
	vertex[verCounter+14] = xpos + 33;

	vertex[verCounter+3] = currenttile;
	vertex[verCounter+7] = currenttile - 33;
	vertex[verCounter+11] = currenttile - 66;
	vertex[verCounter+15] = currenttile - 99;

	verCounter += 16;
}

void keeptile2() // keep tile S Shape
{
	currenttile += 33;

	if(xpos == 33)
	{
		vertex[verCounter] = xpos;
		vertex[verCounter+4] = xpos;
		vertex[verCounter+8] = xpos + 33;
		vertex[verCounter+12] = xpos + 33;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 66;
		vertex[verCounter+9] = currenttile - 66;
		vertex[verCounter+13] = currenttile - 99;

		// upper right x vertex
		vertex[verCounter+2] = xpos + 33;
		vertex[verCounter+6] = xpos + 33;
		vertex[verCounter+10] = xpos + 66;
		vertex[verCounter+14] = xpos + 66;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile - 33;
		vertex[verCounter+11] = currenttile - 33;
		vertex[verCounter+15] = currenttile - 66;
	}
	else if (xpos == 330)
	{
		//lower left x vertex
		vertex[verCounter] = xpos-33;
		vertex[verCounter+4] = xpos-33;
		vertex[verCounter+8] = xpos;
		vertex[verCounter+12] = xpos;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 66;
		vertex[verCounter+9] = currenttile - 66;
		vertex[verCounter+13] = currenttile - 99;

		// upper right x vertex
		vertex[verCounter+2] = xpos;
		vertex[verCounter+6] = xpos;
		vertex[verCounter+10] = xpos + 33;
		vertex[verCounter+14] = xpos + 33;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile - 33;
		vertex[verCounter+11] = currenttile - 33;
		vertex[verCounter+15] = currenttile - 66;
	}
	else
	{
		//lower left x vertex
		vertex[verCounter] = xpos;
		vertex[verCounter+4] = xpos;
		vertex[verCounter+8] = xpos + 33;
		vertex[verCounter+12] = xpos + 33;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 66;
		vertex[verCounter+9] = currenttile - 66;
		vertex[verCounter+13] = currenttile - 99;

		// upper right x vertex
		vertex[verCounter+2] = xpos + 33;
		vertex[verCounter+6] = xpos + 33;
		vertex[verCounter+10] = xpos + 66;
		vertex[verCounter+14] = xpos + 66;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile - 33;
		vertex[verCounter+11] = currenttile - 33;
		vertex[verCounter+15] = currenttile - 66;
	}


	verCounter += 16;
}

void keeptile3()
{
	currenttile += 33;

	if(xpos == 33)
	{
		//lower left x vertex
		vertex[verCounter] = xpos;
		vertex[verCounter+4] = xpos;
		vertex[verCounter+8] = xpos + 33;
		vertex[verCounter+12] = xpos + 66;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 66;
		vertex[verCounter+9] = currenttile - 33;
		vertex[verCounter+13] = currenttile - 33;

		// upper right x vertex
		vertex[verCounter+2] = xpos + 33;
		vertex[verCounter+6] = xpos + 33;
		vertex[verCounter+10] = xpos + 66;
		vertex[verCounter+14] = xpos + 99;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile - 33;
		vertex[verCounter+11] = currenttile;
		vertex[verCounter+15] = currenttile;
	}
	else if (xpos == 330)
	{
		//lower left x vertex
		vertex[verCounter] = xpos-66;
		vertex[verCounter+4] = xpos-66;
		vertex[verCounter+8] = xpos-33;
		vertex[verCounter+12] = xpos;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 66;
		vertex[verCounter+9] = currenttile - 33;
		vertex[verCounter+13] = currenttile - 33;

		// upper right x vertex
		vertex[verCounter+2] = xpos-33;
		vertex[verCounter+6] = xpos-33;
		vertex[verCounter+10] = xpos;
		vertex[verCounter+14] = xpos + 33;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile - 33;
		vertex[verCounter+11] = currenttile;
		vertex[verCounter+15] = currenttile;
	}
	else if (xpos == 297)
	{
		//lower left x vertex
		vertex[verCounter] = xpos-33;
		vertex[verCounter+4] = xpos-33;
		vertex[verCounter+8] = xpos;
		vertex[verCounter+12] = xpos+33;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 66;
		vertex[verCounter+9] = currenttile - 33;
		vertex[verCounter+13] = currenttile - 33;

		// upper right x vertex
		vertex[verCounter+2] = xpos;
		vertex[verCounter+6] = xpos;
		vertex[verCounter+10] = xpos + 33;
		vertex[verCounter+14] = xpos + 66;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile - 33;
		vertex[verCounter+11] = currenttile;
		vertex[verCounter+15] = currenttile;
	}
	else
	{
		//lower left x vertex
		vertex[verCounter] = xpos;
		vertex[verCounter+4] = xpos;
		vertex[verCounter+8] = xpos + 33;
		vertex[verCounter+12] = xpos + 66;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 66;
		vertex[verCounter+9] = currenttile - 33;
		vertex[verCounter+13] = currenttile - 33;

		// upper right x vertex
		vertex[verCounter+2] = xpos + 33;
		vertex[verCounter+6] = xpos + 33;
		vertex[verCounter+10] = xpos + 66;
		vertex[verCounter+14] = xpos + 99;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile - 33;
		vertex[verCounter+11] = currenttile;
		vertex[verCounter+15] = currenttile;
	}

	verCounter += 16;
}

void keeptile4()
{
	currenttile += 33;

	if(xpos == 33)
	{
		//lower left x vertex
		vertex[verCounter] = xpos;
		vertex[verCounter+4] = xpos + 33;
		vertex[verCounter+8] = xpos + 33;
		vertex[verCounter+12] = xpos + 66;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 33;
		vertex[verCounter+9] = currenttile - 66;
		vertex[verCounter+13] = currenttile - 33;

		// upper right x vertex
		vertex[verCounter+2] = xpos + 33;
		vertex[verCounter+6] = xpos + 66;
		vertex[verCounter+10] = xpos + 66;
		vertex[verCounter+14] = xpos + 99;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile;
		vertex[verCounter+11] = currenttile - 33;
		vertex[verCounter+15] = currenttile;
	}
	else if (xpos == 330)
	{
		//lower left x vertex
		vertex[verCounter] = xpos-66;
		vertex[verCounter+4] = xpos-33;
		vertex[verCounter+8] = xpos-33;
		vertex[verCounter+12] = xpos;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 33;
		vertex[verCounter+9] = currenttile - 66;
		vertex[verCounter+13] = currenttile - 33;

		// upper right x vertex
		vertex[verCounter+2] = xpos - 33;
		vertex[verCounter+6] = xpos;
		vertex[verCounter+10] = xpos;
		vertex[verCounter+14] = xpos + 33;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile;
		vertex[verCounter+11] = currenttile - 33;
		vertex[verCounter+15] = currenttile;
	}
	else if(xpos == 297)
	{
		//lower left x vertex
		vertex[verCounter] = xpos-33;
		vertex[verCounter+4] = xpos;
		vertex[verCounter+8] = xpos;
		vertex[verCounter+12] = xpos+33;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 33;
		vertex[verCounter+9] = currenttile - 66;
		vertex[verCounter+13] = currenttile - 33;

		// upper right x vertex
		vertex[verCounter+2] = xpos;
		vertex[verCounter+6] = xpos + 33;
		vertex[verCounter+10] = xpos + 33;
		vertex[verCounter+14] = xpos + 66;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile;
		vertex[verCounter+11] = currenttile - 33;
		vertex[verCounter+15] = currenttile;
	}
	else
	{
		//lower left x vertex
		vertex[verCounter] = xpos;
		vertex[verCounter+4] = xpos + 33;
		vertex[verCounter+8] = xpos + 33;
		vertex[verCounter+12] = xpos + 66;

		//lower left y vertex
		vertex[verCounter+1] = currenttile - 33;
		vertex[verCounter+5] = currenttile - 33;
		vertex[verCounter+9] = currenttile - 66;
		vertex[verCounter+13] = currenttile - 33;

		// upper right x vertex
		vertex[verCounter+2] = xpos + 33;
		vertex[verCounter+6] = xpos + 66;
		vertex[verCounter+10] = xpos + 66;
		vertex[verCounter+14] = xpos + 99;

		// upper right y vertex
		vertex[verCounter+3] = currenttile;
		vertex[verCounter+7] = currenttile;
		vertex[verCounter+11] = currenttile - 33;
		vertex[verCounter+15] = currenttile;
	}

	verCounter +=16;
}

void keepTile5()
{
	currenttile += 33;

	vertex[verCounter] = xpos-33;
	vertex[verCounter+4] = xpos;
	vertex[verCounter+8] = xpos+33;
	vertex[verCounter+12] = xpos+66;

	vertex[verCounter+1] = currenttile - 66;
	vertex[verCounter+5] = currenttile - 66;
	vertex[verCounter+9] = currenttile - 66;
	vertex[verCounter+13] = currenttile - 66;

	vertex[verCounter+2] = xpos;
	vertex[verCounter+6] = xpos + 33;
	vertex[verCounter+10] = xpos + 66;
	vertex[verCounter+14] = xpos + 99;

	vertex[verCounter+3] = currenttile - 33;
	vertex[verCounter+7] = currenttile - 33;
	vertex[verCounter+11] = currenttile - 33;
	vertex[verCounter+15] = currenttile - 33;

	verCounter += 16;
}

void keeptile6()
{
	currenttile += 33;

	//lower left x vertex
	vertex[verCounter] = xpos-33;
	vertex[verCounter+4] = xpos;
	vertex[verCounter+8] = xpos;
	vertex[verCounter+12] = xpos + 33;

	//lower left y vertex
	vertex[verCounter+1] = currenttile - 66;
	vertex[verCounter+5] = currenttile - 66;
	vertex[verCounter+9] = currenttile - 33;
	vertex[verCounter+13] = currenttile - 33;

	// upper right x vertex
	vertex[verCounter+2] = xpos;
	vertex[verCounter+6] = xpos + 33;
	vertex[verCounter+10] = xpos + 33;
	vertex[verCounter+14] = xpos + 66;

	// upper right y vertex
	vertex[verCounter+3] = currenttile - 33;
	vertex[verCounter+7] = currenttile - 33;
	vertex[verCounter+11] = currenttile;
	vertex[verCounter+15] = currenttile;

	verCounter +=16;
}

void keeptile7()
{
	currenttile += 33;

	//lower left x vertex
	vertex[verCounter] = xpos+33;
	vertex[verCounter+4] = xpos+66;
	vertex[verCounter+8] = xpos+33;
	vertex[verCounter+12] = xpos+33;

	//lower left y vertex
	vertex[verCounter+1] = currenttile - 66;
	vertex[verCounter+5] = currenttile - 66;
	vertex[verCounter+9] = currenttile - 33;
	vertex[verCounter+13] = currenttile;

	// upper right x vertex
	vertex[verCounter+2] = xpos+66;
	vertex[verCounter+6] = xpos + 99;
	vertex[verCounter+10] = xpos + 66;
	vertex[verCounter+14] = xpos + 66;

	// upper right y vertex
	vertex[verCounter+3] = currenttile-33;
	vertex[verCounter+7] = currenttile - 33;
	vertex[verCounter+11] = currenttile;
	vertex[verCounter+15] = currenttile+33;

	verCounter += 16;
}

void keeptile8()
{
	currenttile += 33;

	//lower left x vertex
	vertex[verCounter] = xpos+66;
	vertex[verCounter+4] = xpos+66;
	vertex[verCounter+8] = xpos+33;
	vertex[verCounter+12] = xpos;

	//lower left y vertex
	vertex[verCounter+1] = currenttile-33;
	vertex[verCounter+5] = currenttile;
	vertex[verCounter+9] = currenttile - 33;
	vertex[verCounter+13] = currenttile - 33;

	// upper right x vertex
	vertex[verCounter+2] = xpos+99;
	vertex[verCounter+6] = xpos + 99;
	vertex[verCounter+10] = xpos + 66;
	vertex[verCounter+14] = xpos+33;

	// upper right y vertex
	vertex[verCounter+3] = currenttile;
	vertex[verCounter+7] = currenttile+33;
	vertex[verCounter+11] = currenttile;
	vertex[verCounter+15] = currenttile;

	verCounter +=16;
}

void keeptile9()
{
	currenttile += 33;

	//lower left x vertex
	vertex[verCounter] = xpos+33;
	vertex[verCounter+4] = xpos;
	vertex[verCounter+8] = xpos+33;
	vertex[verCounter+12] = xpos+33;

	//lower left y vertex
	vertex[verCounter+1] = currenttile;
	vertex[verCounter+5] = currenttile;
	vertex[verCounter+9] = currenttile - 33;
	vertex[verCounter+13] = currenttile - 66;

	// upper right x vertex
	vertex[verCounter+2] = xpos+66;
	vertex[verCounter+6] = xpos + 33;
	vertex[verCounter+10] = xpos + 66;
	vertex[verCounter+14] = xpos + 66;

	// upper right y vertex
	vertex[verCounter+3] = currenttile +33;
	vertex[verCounter+7] = currenttile+33;
	vertex[verCounter+11] = currenttile;
	vertex[verCounter+15] = currenttile-33;

	verCounter += 16;
}

void keeptile10()
{
	currenttile += 33;

	//lower left x vertex
	vertex[verCounter] = xpos+33;
	vertex[verCounter+4] = xpos+33;
	vertex[verCounter+8] = xpos+66;
	vertex[verCounter+12] = xpos+33;

	//lower left y vertex
	vertex[verCounter+1] = currenttile-66;
	vertex[verCounter+5] = currenttile-33;
	vertex[verCounter+9] = currenttile - 33;
	vertex[verCounter+13] = currenttile;

	// upper right x vertex
	vertex[verCounter+2] = xpos+66;
	vertex[verCounter+6] = xpos + 66;
	vertex[verCounter+10] = xpos + 99;
	vertex[verCounter+14] = xpos + 66;

	// upper right y vertex
	vertex[verCounter+3] = currenttile;
	vertex[verCounter+7] = currenttile;
	vertex[verCounter+11] = currenttile;
	vertex[verCounter+15] = currenttile+33;

	verCounter += 16;
}

void keeptile11()
{
	currenttile += 33;

	//lower left x vertex
	vertex[verCounter] = xpos+66;
	vertex[verCounter+4] = xpos+33;
	vertex[verCounter+8] = xpos+33;
	vertex[verCounter+12] = xpos;

	//lower left y vertex
	vertex[verCounter+1] = currenttile-33;
	vertex[verCounter+5] = currenttile-33;
	vertex[verCounter+9] = currenttile;
	vertex[verCounter+13] = currenttile-33;

	// upper right x vertex
	vertex[verCounter+2] = xpos+99;
	vertex[verCounter+6] = xpos + 66;
	vertex[verCounter+10] = xpos + 66;
	vertex[verCounter+14] = xpos + 33;

	// upper right y vertex
	vertex[verCounter+3] = currenttile;
	vertex[verCounter+7] = currenttile;
	vertex[verCounter+11] = currenttile+33;
	vertex[verCounter+15] = currenttile;

	verCounter += 16;
}

void keeptile12()
{
	currenttile += 33;

	//lower left x vertex
	vertex[verCounter] = xpos+33;
	vertex[verCounter+4] = xpos+33;
	vertex[verCounter+8] = xpos;
	vertex[verCounter+12] = xpos+33;

	//lower left y vertex
	vertex[verCounter+1] = currenttile;
	vertex[verCounter+5] = currenttile-33;
	vertex[verCounter+9] = currenttile-33;
	vertex[verCounter+13] = currenttile-66;

	// upper right x vertex
	vertex[verCounter+2] = xpos+66;
	vertex[verCounter+6] = xpos + 66;
	vertex[verCounter+10] = xpos + 33;
	vertex[verCounter+14] = xpos + 66;

	// upper right y vertex
	vertex[verCounter+3] = currenttile+33;
	vertex[verCounter+7] = currenttile;
	vertex[verCounter+11] = currenttile;
	vertex[verCounter+15] = currenttile-33;

	verCounter += 16;
}

void shape1()  // I Shape
{
	if(currenttile >= 165)
	{
		if(check_occupied[currenttile - 33][xpos] == false && check_occupied[currenttile - 66][xpos] == false && check_occupied[currenttile- 99][xpos] == false && check_occupied[currenttile-132][xpos] == false)
		{
			// glRecti (33,(currenttile-33),66,currenttile);
			// glRecti (33,(currenttile-66),66,(currenttile-33));
			// glRecti (33,(currenttile-99),66,(currenttile-66));
			// glRecti (33,(currenttile-132),66,(currenttile-99));
			vertex[0] = xpos;
			vertex[4] = xpos;
			vertex[8] = xpos;
			vertex[12] = xpos;

			vertex[1] = currenttile - 33;
			vertex[5] = currenttile - 66;
			vertex[9] = currenttile - 99;
			vertex[13] = currenttile - 132;

			vertex[2] = xpos + 33;
			vertex[6] = xpos + 33;
			vertex[10] = xpos + 33;
			vertex[14] = xpos + 33;

			vertex[3] = currenttile;
			vertex[7] = currenttile - 33;
			vertex[11] = currenttile - 66;
			vertex[15] = currenttile - 99;

			currenttile = currenttile - 33;

			//glutPostRedisplay();
			//glutTimerFunc(timerspeed,shape1,0);
		}
		else    // there is something in the way
		{
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile - 33][xpos] = true;
			check_occupied[currenttile - 66][xpos] = true;
			check_occupied[currenttile - 99][xpos] = true;
			settled = true;
			keepTile1();  // keeps the tile dropped in the grid
		}
	}
	else  //reached bottom of board
	{
		check_occupied[currenttile][xpos] = true;
		check_occupied[currenttile - 33][xpos] = true;
		check_occupied[currenttile - 66][xpos] = true;
		check_occupied[currenttile - 99][xpos] = true;
		settled = true;
		keepTile1();  // keeps the tile dropped in the grid
	}
}

void shape2()  // S shape
{
	if(currenttile >= 132)
	{
		if (xpos == 33) // if the position is at the left edge
		{
			if(check_occupied[currenttile - 33][xpos] == false && check_occupied[currenttile - 66][xpos] == false && check_occupied[currenttile- 66][xpos+33] == false && check_occupied[currenttile-99][xpos+33] == false)
			{	
				//lower left x vertex
				vertex[0] = xpos;
				vertex[4] = xpos;
				vertex[8] = xpos + 33;
				vertex[12] = xpos + 33;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 66;
				vertex[9] = currenttile - 66;
				vertex[13] = currenttile - 99;

				// upper right x vertex
				vertex[2] = xpos + 33;
				vertex[6] = xpos + 33;
				vertex[10] = xpos + 66;
				vertex[14] = xpos + 66;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile - 33;
				vertex[11] = currenttile - 33;
				vertex[15] = currenttile - 66;
			}
			else
			{
				check_occupied[currenttile][xpos] = true;
				check_occupied[currenttile - 33][xpos] = true;
				check_occupied[currenttile - 33][xpos+33] = true;
				check_occupied[currenttile - 66][xpos+33] = true;
				settled = true;
				keeptile2();
			}
		}
		else if (xpos == 330) // if the position is at the right edge
		{
			if(check_occupied[currenttile - 33][xpos-33] == false && check_occupied[currenttile - 66][xpos-33] == false && check_occupied[currenttile- 66][xpos] == false && check_occupied[currenttile-99][xpos] == false)
			{
				//lower left x vertex
				vertex[0] = xpos-33;
				vertex[4] = xpos-33;
				vertex[8] = xpos;
				vertex[12] = xpos;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 66;
				vertex[9] = currenttile - 66;
				vertex[13] = currenttile - 99;

				// upper right x vertex
				vertex[2] = xpos;
				vertex[6] = xpos;
				vertex[10] = xpos + 33;
				vertex[14] = xpos + 33;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile - 33;
				vertex[11] = currenttile - 33;
				vertex[15] = currenttile - 66;
			}
			else
			{
				check_occupied[currenttile][xpos-33] = true;
				check_occupied[currenttile - 33][xpos-33] = true;
				check_occupied[currenttile - 33][xpos] = true;
				check_occupied[currenttile - 66][xpos] = true;
				settled = true;
				keeptile2();
			}
		}
		else
		{
			if(check_occupied[currenttile - 33][xpos] == false && check_occupied[currenttile - 66][xpos] == false && check_occupied[currenttile- 66][xpos+33] == false && check_occupied[currenttile-99][xpos+33] == false)
			{
				//lower left x vertex
				vertex[0] = xpos;
				vertex[4] = xpos;
				vertex[8] = xpos + 33;
				vertex[12] = xpos + 33;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 66;
				vertex[9] = currenttile - 66;
				vertex[13] = currenttile - 99;

				// upper right x vertex
				vertex[2] = xpos + 33;
				vertex[6] = xpos + 33;
				vertex[10] = xpos + 66;
				vertex[14] = xpos + 66;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile - 33;
				vertex[11] = currenttile - 33;
				vertex[15] = currenttile - 66;
			}
			else
			{
				check_occupied[currenttile][xpos] = true;
				check_occupied[currenttile - 33][xpos] = true;
				check_occupied[currenttile - 33][xpos+33] = true;
				check_occupied[currenttile - 66][xpos+33] = true;
				settled = true;
				keeptile2();
			}
				
		}
		currenttile = currenttile - 33;
	}
	else // reached the bottom
	{
		if(xpos == 33)
		{
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile - 33][xpos] = true;
			check_occupied[currenttile - 33][xpos+33] = true;
			check_occupied[currenttile - 66][xpos+33] = true;
		}
		else if(xpos == 330)
		{
			check_occupied[currenttile][xpos-33] = true;
			check_occupied[currenttile - 33][xpos-33] = true;
			check_occupied[currenttile - 33][xpos] = true;
			check_occupied[currenttile - 66][xpos] = true;
		}
		else
		{
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile - 33][xpos] = true;
			check_occupied[currenttile - 33][xpos+33] = true;
			check_occupied[currenttile - 66][xpos+33] = true;
		}
		settled = true;
		keeptile2();
	}

}

void shape3() // L Shape
{
	if(currenttile >= 99)
	{
		if (xpos == 33) // if the position is at the left edge
		{
			if(check_occupied[currenttile - 33][xpos] == false && check_occupied[currenttile - 66][xpos] == false && check_occupied[currenttile- 33][xpos+33] == false && check_occupied[currenttile-33][xpos+66] == false)
			{
				//lower left x vertex
				vertex[0] = xpos;
				vertex[4] = xpos;
				vertex[8] = xpos + 33;
				vertex[12] = xpos + 66;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 66;
				vertex[9] = currenttile - 33;
				vertex[13] = currenttile - 33;

				// upper right x vertex
				vertex[2] = xpos + 33;
				vertex[6] = xpos + 33;
				vertex[10] = xpos + 66;
				vertex[14] = xpos + 99;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile - 33;
				vertex[11] = currenttile;
				vertex[15] = currenttile;
			}
			else
			{
				check_occupied[currenttile][xpos] = true;
				check_occupied[currenttile - 33][xpos] = true;
				check_occupied[currenttile][xpos+33] = true;
				check_occupied[currenttile][xpos+66] = true;
				settled = true;
				keeptile3();
			}
		}
		else if (xpos == 330) // if the position is at the right edge
		{
			if(check_occupied[currenttile - 33][xpos-66] == false && check_occupied[currenttile - 66][xpos-66] == false && check_occupied[currenttile- 33][xpos-33] == false && check_occupied[currenttile-33][xpos] == false)
			{
				//lower left x vertex
				vertex[0] = xpos-66;
				vertex[4] = xpos-66;
				vertex[8] = xpos-33;
				vertex[12] = xpos;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 66;
				vertex[9] = currenttile - 33;
				vertex[13] = currenttile - 33;

				// upper right x vertex
				vertex[2] = xpos-33;
				vertex[6] = xpos-33;
				vertex[10] = xpos;
				vertex[14] = xpos + 33;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile - 33;
				vertex[11] = currenttile;
				vertex[15] = currenttile;
			}
			else
			{
				check_occupied[currenttile][xpos-66] = true;
				check_occupied[currenttile - 33][xpos-66] = true;
				check_occupied[currenttile][xpos-33] = true;
				check_occupied[currenttile][xpos] = true;
				settled = true;
				keeptile3();
			}
		}
		else if (xpos == 297)
		{
			if(check_occupied[currenttile - 33][xpos-33] == false && check_occupied[currenttile - 66][xpos-33] == false && check_occupied[currenttile- 33][xpos] == false && check_occupied[currenttile-33][xpos+33] == false)
			{
				//lower left x vertex
				vertex[0] = xpos-33;
				vertex[4] = xpos-33;
				vertex[8] = xpos;
				vertex[12] = xpos+33;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 66;
				vertex[9] = currenttile - 33;
				vertex[13] = currenttile - 33;

				// upper right x vertex
				vertex[2] = xpos;
				vertex[6] = xpos;
				vertex[10] = xpos + 33;
				vertex[14] = xpos + 66;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile - 33;
				vertex[11] = currenttile;
				vertex[15] = currenttile;
			}	
			else
			{
				check_occupied[currenttile][xpos-33] = true;
				check_occupied[currenttile - 33][xpos-33] = true;
				check_occupied[currenttile][xpos] = true;
				check_occupied[currenttile][xpos+33] = true;
				settled = true;
				keeptile3();
			}
		}
		else
		{
			if(check_occupied[currenttile - 33][xpos] == false && check_occupied[currenttile - 66][xpos] == false && check_occupied[currenttile- 33][xpos+33] == false && check_occupied[currenttile-33][xpos+66] == false)
			{
				//lower left x vertex
				vertex[0] = xpos;
				vertex[4] = xpos;
				vertex[8] = xpos + 33;
				vertex[12] = xpos + 66;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 66;
				vertex[9] = currenttile - 33;
				vertex[13] = currenttile - 33;

				// upper right x vertex
				vertex[2] = xpos + 33;
				vertex[6] = xpos + 33;
				vertex[10] = xpos + 66;
				vertex[14] = xpos + 99;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile - 33;
				vertex[11] = currenttile;
				vertex[15] = currenttile;		
			}
			else
			{
				check_occupied[currenttile][xpos] = true;
				check_occupied[currenttile - 33][xpos] = true;
				check_occupied[currenttile][xpos+33] = true;
				check_occupied[currenttile][xpos+66] = true;
				settled = true;
				keeptile3();
			}
		}
		currenttile = currenttile - 33;
	}
	else  // reached the bottom of grid
	{
		if (xpos == 330)
		{
			check_occupied[currenttile][xpos-66] = true;
			check_occupied[currenttile - 33][xpos-66] = true;
			check_occupied[currenttile][xpos-33] = true;
			check_occupied[currenttile][xpos] = true;
		}
		else if (xpos == 297)
		{
			check_occupied[currenttile][xpos-33] = true;
			check_occupied[currenttile - 33][xpos-33] = true;
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile][xpos+33] = true;
		}
		else
		{
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile - 33][xpos] = true;
			check_occupied[currenttile][xpos+33] = true;
			check_occupied[currenttile][xpos+66] = true;
		}
		settled = true;
		keeptile3();
	}
}

void shape4()  // T Shape
{
	if(currenttile >= 99)
	{
		if (xpos == 33) // if the position is at the left edge
		{
			if(check_occupied[currenttile - 33][xpos] == false && check_occupied[currenttile - 33][xpos+33] == false && check_occupied[currenttile- 66][xpos+33] == false && check_occupied[currenttile-33][xpos+66] == false)
			{
				//lower left x vertex
				vertex[0] = xpos;
				vertex[4] = xpos + 33;
				vertex[8] = xpos + 33;
				vertex[12] = xpos + 66;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 33;
				vertex[9] = currenttile - 66;
				vertex[13] = currenttile - 33;

				// upper right x vertex
				vertex[2] = xpos + 33;
				vertex[6] = xpos + 66;
				vertex[10] = xpos + 66;
				vertex[14] = xpos + 99;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile;
				vertex[11] = currenttile - 33;
				vertex[15] = currenttile;
			}
			else
			{
				check_occupied[currenttile][xpos] = true;
				check_occupied[currenttile][xpos+33] = true;
				check_occupied[currenttile-33][xpos+33] = true;
				check_occupied[currenttile][xpos+66] = true;
				settled = true;
				keeptile4();
			}

		}
		else if (xpos == 330) // if the position is at the right edge
		{
			if(check_occupied[currenttile - 33][xpos-66] == false && check_occupied[currenttile - 33][xpos-33] == false && check_occupied[currenttile- 66][xpos-33] == false && check_occupied[currenttile-33][xpos] == false)
			{
				//lower left x vertex
				vertex[0] = xpos-66;
				vertex[4] = xpos-33;
				vertex[8] = xpos-33;
				vertex[12] = xpos;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 33;
				vertex[9] = currenttile - 66;
				vertex[13] = currenttile - 33;

				// upper right x vertex
				vertex[2] = xpos - 33;
				vertex[6] = xpos;
				vertex[10] = xpos;
				vertex[14] = xpos + 33;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile;
				vertex[11] = currenttile - 33;
				vertex[15] = currenttile;
			}
			else
			{
				check_occupied[currenttile][xpos-66] = true;
				check_occupied[currenttile][xpos-33] = true;
				check_occupied[currenttile-33][xpos-33] = true;
				check_occupied[currenttile][xpos] = true;
				settled = true;
				keeptile4();
			}
		}
		else if(xpos == 297)
		{
			if(check_occupied[currenttile - 33][xpos-33] == false && check_occupied[currenttile - 33][xpos] == false && check_occupied[currenttile- 66][xpos] == false && check_occupied[currenttile-33][xpos+33] == false)
			{
				//lower left x vertex
				vertex[0] = xpos-33;
				vertex[4] = xpos;
				vertex[8] = xpos;
				vertex[12] = xpos+33;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 33;
				vertex[9] = currenttile - 66;
				vertex[13] = currenttile - 33;

				// upper right x vertex
				vertex[2] = xpos;
				vertex[6] = xpos + 33;
				vertex[10] = xpos + 33;
				vertex[14] = xpos + 66;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile;
				vertex[11] = currenttile - 33;
				vertex[15] = currenttile;
			}
			else
			{
				check_occupied[currenttile][xpos-33] = true;
				check_occupied[currenttile][xpos] = true;
				check_occupied[currenttile-33][xpos] = true;
				check_occupied[currenttile][xpos+33] = true;
				settled = true;
				keeptile4();
			}
		}
		else
		{
			if(check_occupied[currenttile - 33][xpos] == false && check_occupied[currenttile - 33][xpos+33] == false && check_occupied[currenttile- 66][xpos+33] == false && check_occupied[currenttile-33][xpos+66] == false)
			{
				//lower left x vertex
				vertex[0] = xpos;
				vertex[4] = xpos + 33;
				vertex[8] = xpos + 33;
				vertex[12] = xpos + 66;

				//lower left y vertex
				vertex[1] = currenttile - 33;
				vertex[5] = currenttile - 33;
				vertex[9] = currenttile - 66;
				vertex[13] = currenttile - 33;

				// upper right x vertex
				vertex[2] = xpos + 33;
				vertex[6] = xpos + 66;
				vertex[10] = xpos + 66;
				vertex[14] = xpos + 99;

				// upper right y vertex
				vertex[3] = currenttile;
				vertex[7] = currenttile;
				vertex[11] = currenttile - 33;
				vertex[15] = currenttile;
			}
			else
			{
				check_occupied[currenttile][xpos] = true;
				check_occupied[currenttile][xpos+33] = true;
				check_occupied[currenttile-33][xpos+33] = true;
				check_occupied[currenttile][xpos+66] = true;
				settled = true;
				keeptile4();
			}
				
		}
		currenttile = currenttile - 33;
	}
	else
	{
		if (xpos == 330)
		{
			check_occupied[currenttile][xpos-66] = true;
			check_occupied[currenttile][xpos-33] = true;
			check_occupied[currenttile-33][xpos-33] = true;
			check_occupied[currenttile][xpos] = true;
		}
		else if(xpos == 297)
		{
			check_occupied[currenttile][xpos-33] = true;
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile-33][xpos] = true;
			check_occupied[currenttile][xpos+33] = true;
		}
		else
		{
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile][xpos+33] = true;
			check_occupied[currenttile-33][xpos+33] = true;
			check_occupied[currenttile][xpos+66] = true;
		}
		settled = true;
		keeptile4();
	}

}

void shape5()
{
	if(currenttile >= 99)
	{
		if(check_occupied[currenttile - 66][xpos-33] == false && check_occupied[currenttile - 66][xpos] == false && check_occupied[currenttile- 66][xpos+33] == false && check_occupied[currenttile-66][xpos+66] == false)
		{
			vertex[0] = xpos-33;
			vertex[4] = xpos;
			vertex[8] = xpos+33;
			vertex[12] = xpos+66;

			vertex[1] = currenttile - 66;
			vertex[5] = currenttile - 66;
			vertex[9] = currenttile - 66;
			vertex[13] = currenttile - 66;

			vertex[2] = xpos;
			vertex[6] = xpos + 33;
			vertex[10] = xpos + 66;
			vertex[14] = xpos + 99;

			vertex[3] = currenttile - 33;
			vertex[7] = currenttile - 33;
			vertex[11] = currenttile - 33;
			vertex[15] = currenttile - 33;

			currenttile = currenttile - 33;
		}
		else    // there is something in the way
		{
			check_occupied[currenttile -33][xpos-33] = true;
			check_occupied[currenttile - 33][xpos] = true;
			check_occupied[currenttile - 33][xpos+33] = true;
			check_occupied[currenttile - 33][xpos+66] = true;
			settled = true;
			keepTile5();  // keeps the tile dropped in the grid
		}
	}
	else  //reached bottom of board
	{
		check_occupied[currenttile - 33][xpos-33] = true;
		check_occupied[currenttile - 33][xpos] = true;
		check_occupied[currenttile - 33][xpos+33] = true;
		check_occupied[currenttile - 33][xpos+66] = true;
		settled = true;
		keepTile5();  // keeps the tile dropped in the grid
	}
}

void shape6()
{
	if(currenttile >= 99)
	{
		if(check_occupied[currenttile - 66][xpos-33] == false && check_occupied[currenttile - 66][xpos] == false && check_occupied[currenttile- 33][xpos] == false && check_occupied[currenttile-33][xpos+33] == false)
		{
			//lower left x vertex
			vertex[0] = xpos-33;
			vertex[4] = xpos;
			vertex[8] = xpos;
			vertex[12] = xpos + 33;

			//lower left y vertex
			vertex[1] = currenttile - 66;
			vertex[5] = currenttile - 66;
			vertex[9] = currenttile - 33;
			vertex[13] = currenttile - 33;

			// upper right x vertex
			vertex[2] = xpos;
			vertex[6] = xpos + 33;
			vertex[10] = xpos + 33;
			vertex[14] = xpos + 66;

			// upper right y vertex
			vertex[3] = currenttile - 33;
			vertex[7] = currenttile - 33;
			vertex[11] = currenttile;
			vertex[15] = currenttile;
		}
		else
		{
			check_occupied[currenttile-33][xpos-33] = true;
			check_occupied[currenttile - 33][xpos] = true;
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile][xpos+33] = true;
			settled = true;
			keeptile6();
		}
			
		currenttile = currenttile - 33;
	}
	else // reached the bottom
	{
		check_occupied[currenttile-33][xpos-33] = true;
		check_occupied[currenttile - 33][xpos] = true;
		check_occupied[currenttile][xpos] = true;
		check_occupied[currenttile][xpos+33] = true;

		settled = true;
		keeptile6();
	}

}

void shape7()
{
	if(currenttile >= 99)
	{
		if(check_occupied[currenttile - 66][xpos+33] == false && check_occupied[currenttile - 66][xpos+66] == false && check_occupied[currenttile- 33][xpos+33] == false && check_occupied[currenttile][xpos+33] == false)
		{
			//lower left x vertex
			vertex[0] = xpos+33;
			vertex[4] = xpos+66;
			vertex[8] = xpos+33;
			vertex[12] = xpos+33;

			//lower left y vertex
			vertex[1] = currenttile - 66;
			vertex[5] = currenttile - 66;
			vertex[9] = currenttile - 33;
			vertex[13] = currenttile;

			// upper right x vertex
			vertex[2] = xpos+66;
			vertex[6] = xpos + 99;
			vertex[10] = xpos + 66;
			vertex[14] = xpos + 66;

			// upper right y vertex
			vertex[3] = currenttile-33;
			vertex[7] = currenttile - 33;
			vertex[11] = currenttile;
			vertex[15] = currenttile+33;
		}
		else
		{
			check_occupied[currenttile-33][xpos+33] = true;
			check_occupied[currenttile - 33][xpos+66] = true;
			check_occupied[currenttile][xpos+33] = true;
			check_occupied[currenttile+33][xpos+33] = true;
			settled = true;
			keeptile7();
		}
			
		currenttile = currenttile - 33;
	}
	else // reached the bottom
	{
		check_occupied[currenttile-33][xpos+33] = true;
		check_occupied[currenttile - 33][xpos+66] = true;
		check_occupied[currenttile][xpos+33] = true;
		check_occupied[currenttile+33][xpos+33] = true;

		settled = true;
		keeptile7();
	}
}

void shape8()
{
	if(currenttile >= 66)
	{
		if(check_occupied[currenttile-33][xpos+66] == false && check_occupied[currenttile][xpos+66] == false && check_occupied[currenttile- 33][xpos+33] == false && check_occupied[currenttile-33][xpos] == false)
		{
			//lower left x vertex
			vertex[0] = xpos+66;
			vertex[4] = xpos+66;
			vertex[8] = xpos+33;
			vertex[12] = xpos;

			//lower left y vertex
			vertex[1] = currenttile-33;
			vertex[5] = currenttile;
			vertex[9] = currenttile - 33;
			vertex[13] = currenttile - 33;

			// upper right x vertex
			vertex[2] = xpos+99;
			vertex[6] = xpos + 99;
			vertex[10] = xpos + 66;
			vertex[14] = xpos+33;

			// upper right y vertex
			vertex[3] = currenttile;
			vertex[7] = currenttile+33;
			vertex[11] = currenttile;
			vertex[15] = currenttile;
		}
		else
		{
			check_occupied[currenttile][xpos+66] = true;
			check_occupied[currenttile+33][xpos+66] = true;
			check_occupied[currenttile][xpos+33] = true;
			check_occupied[currenttile][xpos] = true;
			settled = true;
			keeptile8();
		}
			
		currenttile = currenttile - 33;
	}
	else // reached the bottom
	{
		check_occupied[currenttile][xpos+66] = true;
		check_occupied[currenttile+33][xpos+66] = true;
		check_occupied[currenttile][xpos+33] = true;
		check_occupied[currenttile][xpos] = true;

		settled = true;
		keeptile8();
	}
}

void shape9()
{
	if(currenttile >= 99)
	{
		if(check_occupied[currenttile][xpos+33] == false && check_occupied[currenttile][xpos] == false && check_occupied[currenttile- 33][xpos+33] == false && check_occupied[currenttile-66][xpos+33] == false)
		{
			//lower left x vertex
			vertex[0] = xpos+33;
			vertex[4] = xpos;
			vertex[8] = xpos+33;
			vertex[12] = xpos+33;

			//lower left y vertex
			vertex[1] = currenttile;
			vertex[5] = currenttile;
			vertex[9] = currenttile - 33;
			vertex[13] = currenttile - 66;

			// upper right x vertex
			vertex[2] = xpos+66;
			vertex[6] = xpos + 33;
			vertex[10] = xpos + 66;
			vertex[14] = xpos + 66;

			// upper right y vertex
			vertex[3] = currenttile +33;
			vertex[7] = currenttile+33;
			vertex[11] = currenttile;
			vertex[15] = currenttile-33;
		}
		else
		{
			check_occupied[currenttile+33][xpos+33] = true;
			check_occupied[currenttile+33][xpos] = true;
			check_occupied[currenttile][xpos+33] = true;
			check_occupied[currenttile-33][xpos+33] = true;
			settled = true;
			keeptile9();
		}
			
		currenttile = currenttile - 33;
	}
	else // reached the bottom
	{
		check_occupied[currenttile+33][xpos+33] = true;
		check_occupied[currenttile+33][xpos] = true;
		check_occupied[currenttile][xpos+33] = true;
		check_occupied[currenttile-33][xpos+33] = true;

		settled = true;
		keeptile9();
	}
}

void shape10()
{
	if(currenttile >= 99)
	{
		if(check_occupied[currenttile-66][xpos+33] == false && check_occupied[currenttile-33][xpos+33] == false && check_occupied[currenttile- 33][xpos+66] == false && check_occupied[currenttile][xpos+33] == false)
		{
			//lower left x vertex
			vertex[0] = xpos+33;
			vertex[4] = xpos+33;
			vertex[8] = xpos+66;
			vertex[12] = xpos+33;

			//lower left y vertex
			vertex[1] = currenttile-66;
			vertex[5] = currenttile-33;
			vertex[9] = currenttile - 33;
			vertex[13] = currenttile;

			// upper right x vertex
			vertex[2] = xpos+66;
			vertex[6] = xpos + 66;
			vertex[10] = xpos + 99;
			vertex[14] = xpos + 66;

			// upper right y vertex
			vertex[3] = currenttile;
			vertex[7] = currenttile;
			vertex[11] = currenttile;
			vertex[15] = currenttile+33;
		}
		else
		{
			check_occupied[currenttile-33][xpos+33] = true;
			check_occupied[currenttile][xpos+33] = true;
			check_occupied[currenttile][xpos+66] = true;
			check_occupied[currenttile+33][xpos+33] = true;
			settled = true;
			keeptile10();
		}
			
		currenttile = currenttile - 33;
	}
	else // reached the bottom
	{
		check_occupied[currenttile-33][xpos+33] = true;
		check_occupied[currenttile][xpos+33] = true;
		check_occupied[currenttile][xpos+66] = true;
		check_occupied[currenttile+33][xpos+33] = true;

		settled = true;
		keeptile10();
	}
}

void shape11()
{
	if(currenttile >= 66)
	{
		if(check_occupied[currenttile-33][xpos+66] == false && check_occupied[currenttile-33][xpos+33] == false && check_occupied[currenttile][xpos+33] == false && check_occupied[currenttile-33][xpos] == false)
		{
			//lower left x vertex
			vertex[0] = xpos+66;
			vertex[4] = xpos+33;
			vertex[8] = xpos+33;
			vertex[12] = xpos;

			//lower left y vertex
			vertex[1] = currenttile-33;
			vertex[5] = currenttile-33;
			vertex[9] = currenttile;
			vertex[13] = currenttile-33;

			// upper right x vertex
			vertex[2] = xpos+99;
			vertex[6] = xpos + 66;
			vertex[10] = xpos + 66;
			vertex[14] = xpos + 33;

			// upper right y vertex
			vertex[3] = currenttile;
			vertex[7] = currenttile;
			vertex[11] = currenttile+33;
			vertex[15] = currenttile;
		}
		else
		{
			check_occupied[currenttile][xpos+66] = true;
			check_occupied[currenttile][xpos+33] = true;
			check_occupied[currenttile+33][xpos+33] = true;
			check_occupied[currenttile][xpos] = true;
			settled = true;
			keeptile11();
		}
			
		currenttile = currenttile - 33;
	}
	else // reached the bottom
	{
		check_occupied[currenttile][xpos+66] = true;
		check_occupied[currenttile][xpos+33] = true;
		check_occupied[currenttile+33][xpos+33] = true;
		check_occupied[currenttile][xpos] = true;

		settled = true;
		keeptile11();
	}
}

void shape12()
{
	if(currenttile >= 99)
	{
		if(check_occupied[currenttile][xpos+33] == false && check_occupied[currenttile-33][xpos+33] == false && check_occupied[currenttile-33][xpos] == false && check_occupied[currenttile-66][xpos+33] == false)
		{
			//lower left x vertex
			vertex[0] = xpos+33;
			vertex[4] = xpos+33;
			vertex[8] = xpos;
			vertex[12] = xpos+33;

			//lower left y vertex
			vertex[1] = currenttile;
			vertex[5] = currenttile-33;
			vertex[9] = currenttile-33;
			vertex[13] = currenttile-66;

			// upper right x vertex
			vertex[2] = xpos+66;
			vertex[6] = xpos + 66;
			vertex[10] = xpos + 33;
			vertex[14] = xpos + 66;

			// upper right y vertex
			vertex[3] = currenttile+33;
			vertex[7] = currenttile;
			vertex[11] = currenttile;
			vertex[15] = currenttile-33;
		}
		else
		{
			check_occupied[currenttile+33][xpos+33] = true;
			check_occupied[currenttile][xpos+33] = true;
			check_occupied[currenttile][xpos] = true;
			check_occupied[currenttile-33][xpos+33] = true;
			settled = true;
			keeptile12();
		}
			
		currenttile = currenttile - 33;
	}
	else // reached the bottom
	{
		check_occupied[currenttile+33][xpos+33] = true;
		check_occupied[currenttile][xpos+33] = true;
		check_occupied[currenttile][xpos] = true;
		check_occupied[currenttile-33][xpos+33] = true;

		settled = true;
		keeptile12();
	}
}