#include "SimCity.h"

bool SimCity::adjacent(int x, int y)
{
	int a, b, c, d, e, f; //variables to represent adjacency condtions
	a = 0; //If a cell has a population of 0 and is adjacent to a powerline 
	b = 0; //If a cell has a population of 0 and is adjacent to at least one cell with a population of at least 1
	c = 0; //If a cell has a population of 1 and is adjacent to at least two cells with a population of at least 1
	d = 0; //If a cell has a population of 2 and is adjacent to at least four cells with a population of at least 2
	e = 0; //If a cell has a population of 3 and is adjacent to at least six cells with a population of at least 3
	f = 0; //If a cell has a population of 4 and is adjacent to at least eight cells with a population of at least 4, 
	for(int i = x-1; i < x+2; i++)
	{
		for(int j = y-1; j < y+2; j++)
		{
			if((i >= 0)&&(i < ROW)&&(0 <= j)&&(j < COLUMN)) // if state, to hold the boundaries of the array
			{	
			if((&region[i][j] != &region[x][y])) // if state, to not look at the cell itself and only check the adjacent cells
			{
			switch(region[i][j]) //Switch case to increment ajacency variables when adjaceny condition is met for a specific case
			{
				case 'T': 
							a++;
							break;
				case '#':
							a++;
							break;			
				case '1':
							a++;
							b++;
							break;
				case '2':
							a++;
							b++;
							c++;
							break;
				case '3':
							a++;
							b++;
							c++;
							d++;
							break;
				case '4':
							a++;
							b++;
							c++;
							d++;
							e++;
							break;
				default: 
						continue;
						break;
			};
			}
			}
		
	// Resets ajacency variables to 0 after each variable has reached the max number cells the population is adjacent to
	if(a==1 && region[x][y] == 'R') //After being adjacent to 1 cell a resets to 0
	{
		a = 0;
		return true;
	}

	if(b==2 && region[x][y] == '1') //After being adjacent to 2 cells b resets to 0
	{
		b = 0;
		return true;
	}

	if(c==4 && region[x][y] == '2') //After being adjacent to 4 cells c resets to 0
	{
		c = 0;
		return true;
	}

	if(d==6 && region[x][y] == '3') //After being adjacent to 6 cells d resets to 0
	{
		d = 0;
		return true;
	}

	if(e==8 && region[x][y] == '4') //After being adjacent to 8 cells e resets to 0
	{
		e = 0;
		return true;
	}
		}
		
	}
	return false;
};






void SimCity::Resident()
{
	char** temp = region;
	int ** hey;
	hey = new int*[ROW];
	for(int i = 0; i < ROW; i++)
	{
		hey[i] = new int[COLUMN];
		for(int j = 0; j < COLUMN; j++)
		{
			hey[i][j] = 0;
		}
	}

	//Nested for loop to loop through each resendential region
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COLUMN; j++)
		{
			if(adjacent(i, j) == true)
			{
				switch(temp[i][j]) 
				{
				case 'R':
							hey[i][j] = 1; //changes regions that are 'R' to 1s 
							break;			
				case '1':
							hey[i][j] = 2; //changes regions that are '1' to 2s
							break;
				case '2':
							hey[i][j] = 3; //changes regions that are '2' to 3s
							break;
				case '3':
							hey[i][j] = 4; //changes regions that are '3' to 4s
							break;
				case '4':
							hey[i][j] = 5; //changes regions that are '4' to 5s
							break;
				default: 
						continue;
						break;
				};
				

			}
			
		}
	}
	region = change(temp, hey);
};

char** SimCity::change(char** temp, int** hey)
{
	//Nested for loop to loop through each resedential region
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COLUMN; j++)
		{
				switch(hey[i][j]) // switch case to populate temp with characters (based on integers populated in array hey)
				{
				case 1: 
							temp[i][j] = '1'; 
							Workers++;
							break;			
				case 2:
							temp[i][j] = '2';
							Workers++;
							break;
				case 3:
							temp[i][j] = '3';
							Workers++;
							break;
				case 4:
							temp[i][j] = '4';
							Workers++;
							break;
				case 5:
							temp[i][j] = '5';
							Workers++;
							break;
				default: 
						continue;
						break;
				};
		}
	}
	
	return temp;
};