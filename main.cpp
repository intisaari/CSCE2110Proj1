#include "SimCity.h"

int main()
{
    int i = 1;
    char** temp; //Holds unchanged values (as characters) from configuration file 
    int** hey; //Holds changed values (as integers) from configuration file
    SimCity pop;

    pop.LoadData(); //gets file name, refresh rate, time limit
    pop.LoadRegion(); //Loads region files
    cout << "intial state: \n";
    pop.print(); //prints out info of the 2 dimensional array from the unique characters

    int j = pop.gettime(); //refresh rate 
    int x = 0;

    while(pop.getlimit() >= i) //loops through all regions (commercial, resedential, industrial) and prints regions for each time step
    {
        x++;
        if( j != x) 
        {
            cout << "Time step: " << i++ << endl;
            pop.Resident();
            pop.Commercial();
            pop.Industrial();
            pop.printt();
            
        }

        if(j == x)
        {
            x = 0;
            cout << "Time step: " << i++ << endl;
            pop.Resident();
            pop.Commercial();
            pop.Industrial();
            pop.print();

        }

        if(pop.whilecheck() == false)
        {
            cout << "\nFinal Region: \n";
            pop.print();
            hey = pop.pollution(); //decreases values in array after calling pollution function
            return 0;
        }
    };

    if(pop.whilecheck() != false)
    {
        cout << "\nFinal Region: \n";
        pop.print();
        hey = pop.pollution(); 
    }

    pop.analysis(hey); //gets region populations
    return 0;
}

