#include "SimCity.h"


bool SimCity::adjacentI(int x, int y) //Function to determine adjacency
{
	int a, b, c, d, e, f;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	for(int i = x-1; i < x+2; i++) //nested for loop that loops through region
	{
		for(int j = y-1; j < y+2; j++)
		{
			if((i >= 0)&&(i < ROW)&&(0 <= j)&&(j < COLUMN)) // if state, to hold the boundaries of the array
			{	
			if((&region[i][j] != &region[x][y])) // if state, to not look at the cell itself and only check the adjacent cells
			{
			switch(region[i][j]) //Switch statement that checks the adjacency of the cells 
			{
				case 'T':
							a++;
							break;
				case '#':
							a++;
							break;			
				case 'a':
							a++;
							b++;
							break;
				case 'b':
							a++;
							b++;
							c++;
							break;
				case 'd':
							a++;
							b++;
							c++;
							d++;
							break;
				case 'e':
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
		
	
	if(a==1 && region[x][y] == 'I') //resets integer variables to 0 if condition is met
	{
		a = 0;
		return true;
	}

	if(b==2 && region[x][y] == 'a')
	{
		b = 0;
		return true;
	}

	if(c==4 && region[x][y] == 'b')
	{
		c = 0;
		return true;
	}

	if(d==6 && region[x][y] == 'd')
	{
		d = 0;
		return true;
	}

	if(e==8 && region[x][y] == 'e')
	{
		e = 0;
		return true;
	}
		}
		
	}
	return false;
};


void SimCity::Industrial() //Industrial function
{
	char** temp = region;
	int ** hey;
	hey = new int*[ROW];
	for(int i = 0; i < ROW; i++) //loops through 
	{
		hey[i] = new int[COLUMN];
		for(int j = 0; j < COLUMN; j++)
		{
			hey[i][j] = 0;
		}
	}

	for(int i = 0; i < ROW; i++)  
	{
		for(int j = 0; j < COLUMN; j++)
		{
			if(adjacentI(i, j) == true)
			{
				switch(temp[i][j]) //switch statement tht find's each case from the temp array and switches the character in that region.
				{
				case 'I':
							hey[i][j] = 1;
							break;			
				case 'a':
							hey[i][j] = 2;
							break;
				case 'b':
							hey[i][j] = 3;
							break;
				case 'd':
							hey[i][j] = 4;
							break;
				case 'e':
							hey[i][j] = 5;
							break;
				default: 
						continue;
						break;
				};
				

			}
			
		}
	}
	region = changeI(temp, hey); //change function is called
};

char** SimCity::changeI(char** temp, int** hey) //ChangeI function
{

	for(int i = 0; i < ROW; i++) //Nested for loop that goes through the regions in the config file
	{
		for(int j = 0; j < COLUMN; j++)
		{
				switch(hey[i][j]) //switch case that fills the temp array with original/unchanged characters given from the config file
				{
				case 1:
							
							if(Workers >= 2)
							{
							temp[i][j] = 'a';
							Workers -= 2;
							Goods++;
							}
							break;			
				case 2:
							
							if(Workers >= 2)
							{
							temp[i][j] = 'b';
							Workers -= 2;
							Goods++;
							}
							break;
				case 3:
							
							if(Workers >= 2)
							{
							temp[i][j] = 'd';
							Workers -= 2;
							Goods++;
							}
							break;
				case 4:
							
							if(Workers >= 2)
							{
							temp[i][j] = 'e';
							Workers -= 2;
							Goods++;
							}
							break;
				case 5:
							
							if(Workers >= 2)
							{
							temp[i][j] = 'f';
							Workers -= 2;
							Goods++;
							}
							break;
				default: 
						continue;
						break;
				};
		}
	}
	
	return temp;
};