#include "SimCity.h"

bool SimCity::adjacentC(int x, int y) //Function to determine adjacency
{
	int a, b, c, d, e, f;
	a = 0;               
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	for(int i = x-1; i < x+2; i++) //nested for loop to loop through the region of the configuration file
	{
		for(int j = y-1; j < y+2; j++)
		{
			if((i >= 0)&&(i < ROW)&&(0 <= j)&&(j < COLUMN)) // if state, to hold the boundaries of the array
			{	
			if((&region[i][j] != &region[x][y])) // if state, to not look at the cell itself and only check the adjacent cells
			{
			switch(region[i][j]) //Check if the condition of adjacency is met
			{
				case 'T': 
							a++;
							break;
				case '#':
							a++;
							break;			
				case 'q':
							a++;
							b++;
							break;
				case 'w':
							a++;
							b++;
							c++;
							break;
				case 'y':
							a++;
							b++;
							c++;
							d++;
							break;
				case 'u':
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
		
	
	if(a==1 && region[x][y] == 'C') //reset the integer varibles to 0 if condition is true
	{
		a = 0;
		return true;
	}

	if(b==2 && region[x][y] == 'q')
	{
		b = 0;
		return true;
	}

	if(c==4 && region[x][y] == 'w')
	{
		c = 0;
		return true;
	}

	if(d==6 && region[x][y] == 'y')
	{
		d = 0;
		return true;
	}

	if(e==8 && region[x][y] == 'u')
	{
		e = 0;
		return true;
	}
		}
		
	}
	return false;
};






void SimCity::Commercial()
{
	char** temp = region; 
	int ** hey;
	hey = new int*[ROW];
	for(int i = 0; i < ROW; i++) //nested for loop to go through each region in the config file
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
			if(adjacentC(i, j) == true)
			{
				switch(temp[i][j]) //switch case in nested for loop to find each case from the temp array and switch the character in that region.
				{
				case 'C':
							hey[i][j] = 1;
							break;			
				case 'q':
							hey[i][j] = 2;
							break;
				case 'w':
							hey[i][j] = 3;
							break;
				case 'y':
							hey[i][j] = 4;
							break;
				case 'u':
							hey[i][j] = 5;
							break;
				default: 
						continue;
						break;
				};
				

			}
			
		}
	}
	region = changeC(temp, hey); //change function is called
};

char** SimCity::changeC(char** temp, int** hey) //ChangeC function
{

	for(int i = 0; i < ROW; i++) //nested for loop that loops through region in configuration file
	{
		for(int j = 0; j < COLUMN; j++)
		{
				switch(hey[i][j]) //fills temp arry with original/unchanged characters from the config file
				{
				case 1:
                            if(Workers >= 1 && Goods >= 1)
                            {
							temp[i][j] = 'q';
							Workers--;
                            Goods--;
                            }
							break;			
				case 2:
                            if(Workers >= 1 && Goods >= 1)
                            {
							temp[i][j] = 'w';
							Workers--;
                            Goods--;
                            }
							break;
				case 3:
                            if(Workers >= 1 && Goods >= 1)
                            {
							temp[i][j] = 'y';
							Workers--;
                            Goods--;
                            }
							break;
				case 4:
                            if(Workers >= 1 && Goods >= 1)
                            {
							temp[i][j] = 'u';
							Workers--;
                            Goods--;
                            }
							break;
				case 5:
                            if(Workers >= 1 && Goods >= 1)
                            {
							temp[i][j] = 'v';
							Workers--;
                            Goods--;
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