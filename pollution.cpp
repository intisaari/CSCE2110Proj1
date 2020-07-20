#include "SimCity.h"

int** SimCity::pollution()
{
   	int ** hey;
    int s = 0;
    
	hey = new int*[ROW];
	for(int i = 0; i < ROW; i++) //nested for loop to go theough each region of hey array 
	{
		hey[i] = new int[COLUMN]; //integer version of region array
		for(int j = 0; j < COLUMN; j++)
		{
			hey[i][j] = 0;
		}
	}

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COLUMN; j++)
		{
				switch(region[i][j]) //switch case to populate hey array with the integers (instead of characters) from region array
				{
				case 'a':
							hey[i][j] = 1;
							break;			
				case 'b':
							hey[i][j] = 2;
							break;
				case 'd':
							hey[i][j] = 3;
							break;
				case 'e':
							hey[i][j] = 4;
							break;
				case 'f':
							hey[i][j] = 5;
							break;
				default: 
						continue;
						break;
				};
			
		}
	} 

    for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COLUMN; j++)
		{
            decrem(hey, i, j);
		}
	}
    
    cout << "pollution: \n";
    cout << setfill('-') << setw(((ROW-1)*3)-1); // setfill and setw to give the right amount of '-' on the top and bottom
    cout << "\n";

    for(int i = 0; i < ROW; i++)
	{
        printf("| ");
		for(int j = 0; j < COLUMN; j++)
		{
            cout << hey[i][j] << " ";
        }
        printf("| \n");
    }

    cout << setfill('-');
	cout << setw(((ROW-1)*3)-1);
    cout << "\n";

    return hey;
}

void SimCity::decrem(int** hey, int x, int y)
{
    int s = 0; //replaces value from integers in hey array to the new value after decrem function is ran
    for(int i = x-1; i < x+2; i++)
    {
        for(int j = y-1; j < y+2; j++)
        {
            if((i >= 0)&&(i < ROW)&&(0 <= j)&&(j < COLUMN))
            {    
                s = hey[x][y];
                if(hey[i][j] < s-1) // looks at adjacent region cells in industrial region
                {    
                    hey[i][j] = s-1; //Decrements adjacent cells to region to fufil condition:  pollution spreads to all adjacent cells at a rate of one less unit of pollution per cell away from the source 
                }
            }
        }
    }
    return;
}