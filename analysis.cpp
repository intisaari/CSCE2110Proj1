#include "SimCity.h"

void SimCity::analysis(int ** hey) //analysis function
{
    int x, y; //variables for coordinates
    int h, k;
    int res = 0;
    int ind = 0; //variables for zones
    int com = 0;
    int pol = 0;


    for(int i = 0; i < ROW; i++) //nested for loop that loops through region
    {
        for(int j = 0; j < COLUMN; j++)
        {
            pol += hey[i][j];
           switch(region[i][j]) //switch case that increments the zone variables depending on if the condition is met
				{
				case 'a':
							ind += 1;
							break;			
				case 'b':
							ind += 2;
							break;
				case 'd':
							ind += 3;
							break;
				case 'e':
							ind += 4;
							break;
				case 'f':
							ind += 5;
							break;
                case 'q':
							com += 1;
							break;			
				case 'w':
							com += 2;
							break;
				case 'y':
							com += 3;
							break;
				case 'u':
							com += 4;
							break;
				case 'v':
						    com += 5;
							break;
                case '1':
							res += 1;
							break;			
				case '2':
							res += 2;
							break;
				case '3':
							res += 3;
							break;
				case '4':
							res += 4;
							break;
				case '5':
						    res += 5;
							break;
				default: 
						continue;
						break;
			}; 
        }
    }

    cout << "\nThe total populations for the region are: \n"; //Output total population and pollution for the region
    cout << "Residential: " << res;
    cout << "\nIndustrial: " << ind;
    cout << "\nCommercial: " << com;
    cout << "\nThe total amount of pollution in the region is " << pol << "units.\n";

    res = 0; //reset zone variables to 0
    ind = 0;
    com = 0;
    pol = 0;

    cout << "Please enter the diagonal corners of the area you wish to have more information about: (MinX = 0, MinY = 0, MaxX = " << COLUMN-1 << ", MaxY = " << ROW-1 << ") \n"; //prompt user input for coordinates
    cout << "\nx1: "; 
    cin >> x;
    cout << "\ny1: "; 
    cin >> y;
    cout << "\nx2: "; 
    cin >> h;
    cout << "\ny2: "; 
    cin >> k;
    cout << endl;

    for(int i = y; i < k+1; i++) //nested for loop loops through region
    {
        for(int j = x; j < h+1; j++)
        {
            pol += hey[i][j];
           switch(region[i][j]) //switch statement increments each zone depending on if the condition is true
				{
				case 'a':
							ind += 1;
							break;			
				case 'b':
							ind += 2;
							break;
				case 'd':
							ind += 3;
							break;
				case 'e':
							ind += 4;
							break;
				case 'f':
							ind += 5;
							break;
                case 'q':
							com += 1;
							break;			
				case 'w':
							com += 2;
							break;
				case 'y':
							com += 3;
							break;
				case 'u':
							com += 4;
							break;
				case 'v':
						    com += 5;
							break;
                case '1':
							res += 1;
							break;			
				case '2':
							res += 2;
							break;
				case '3':
							res += 3;
							break;
				case '4':
							res += 4;
							break;
				case '5':
						    res += 5;
							break;
				default: 
                        break;
			}; 
        }
    }

    cout << "The total populations for the requested area are: \n";  //Output total population and pollution given the coordinates by the user
    cout << "Residential: " << res << endl;
    cout << "Industrial: " << ind << endl;
    cout << "Commercial: " << com << endl;
    cout << "\nThe total amount of pollution for the requested region is " << pol << "units.\n";

    return;
}