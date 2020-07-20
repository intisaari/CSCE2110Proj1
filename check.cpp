#include "SimCity.h"

bool SimCity::whilecheck()
{
    for(int i = 0; i < ROW; i++) //nested for loop to go through all regions 
    {
        for(int j = 0; j < COLUMN; j++)
        {
            if(adjacent(i,j) == true) // populates and checks adjacency conditions for residential region
            {
                return true;
            }
            else if (adjacentI(i,j) == true) // populates and checks adjacency conditions for industrial region
            {
                return true;
            }
            else if (adjacentC(i,j) == true) // populates and checks adjacency conditions for commercial region
            {
                return true;
            }
        }
    }
    return false; //returns false if conditions arent met for resedential, commercial, or industrial regions
}