#include "SimCity.h"
using namespace std;

SimCity::SimCity() // a constructor for the class to set all values essentially to one incase they arent read in right and wont cause an error
{
	ROW = 0;
	COLUMN = 0;
        regionname = " ";
        timeLimit = 0;
        refreshRate = 0;
        region = new char*[1];
        region[0] = new char[1];
        region[0][0] = ' ';
        Workers = 0;
        Goods = 0;
	};


void SimCity::LoadData()
{    
    string filename, info, info2; // Variables for holding the information, accessing the configuration file and place values to accurately read in the value
    int value;
    ifstream fin;

    cout << "Beginning simulation:" << endl;

    cout << "Enter the name of the configuration file: "; // Prompt for the configuration file name
    getline(cin, filename); // taking in the filename from the user

    fin.open(filename); // opening the file using the given filename of the user
    getline(fin, info); // taking in entire firstline of code to later use a string function to get the regionname
           
    value = info.find(":"); // using a string function .find() to find at what position the actual information in the string we want is located
    regionname = info.substr(value+1); // copying the string from the point of the the position found till the end of the string form the getline
          
    getline(fin, info); // taking in entire secondline of code to later use a string function to get the timeLimit
    value = info.find(":"); // copying the string from the point of the the position found to get the string timeLimit value
    info = info.substr(value+1); // string function to get the copy  from the point of the the position found till the end of the string form the getline
    stringstream convert(info);// holding onto the string stored in place and converts an embedded string function from the library <sstream> into a malleable int
    convert >> timeLimit;//push the time limit into the int variable
    
    getline(fin, info2); // same from what is above basically
    value = info2.find(":");
    info2 = info2.substr(value+1);
    stringstream convert1(info2);
    convert1 >> refreshRate; //push refreshrate ditto above
    fin.close();

    return;
};

void SimCity::LoadRegion() // The function for loading in the regionfile
{
        string info; // The string holding each line of code
        int row, column; // the int variables keeping track of the amount of row, columns
        ifstream fin; // To open and read in from a file

        row = 1; // so the if statement will be used on the second go around
        fin.open(regionname); // opeing the file taken from the config file

    while(getline(fin, info))  // while loop using getline until the end of the file
    {
        char **temp; // creating a temporary character dynamic array

        temp = new char*[row]; // allocating 1 row of characters


        if(row >1) // to only reload the info when the region array has actual information
        {
        for(int f = 0; f < row-1; f++) // nested for loop taking in the information from the region file to keep the old information
        {
            temp[f]= new char[((info.length()-1)/2)+1];//allocating the memory for the columns using an expression with the string length to not takein commas
            for(int d = 0; d < ((info.length()-1)/2)+1; d++)
            {
                temp[f][d] = region[f][d];
            }
        }
        }


            temp[row-1] = new char[((info.length()-1)/2)+1]; // allocating the added row of info with char column



            column = 0; // to increment in the if statment for manuvering in the dynamic array
            for(int d = 0; d < info.length(); d++)
            {
                if(info.at(d) != ',') // checking the string at every point not taking in commas
                {
                    temp[row-1][column] = info.at(d);
                    column++;
                }

            }

        delete [] region; // deleting the now too small dynamic region array


        region = new char*[row]; // reallocating and entering the new information into the region dynamic array
        for(int f = 0; f < row; f++)
        {
           region[f] = new char[((info.length()-1)/2)+1];
           for(int d = 0; d < ((info.length()-1)/2)+1; d++)
           {
             region[f][d] = temp[f][d];
           }
        }

        delete [] temp; // deleting the temporary array

    row++;    // incrementing for every new line taken in
    };
    ROW = --row; // initializing the row and column so it can be accessed from any function
    COLUMN = column;
    fin.close();
};

void SimCity::print() // print function
{
     
          cout << "Available workers: " << Workers << " Available Goods: " << Goods << endl;
          cout << setfill('-') << setw(((ROW-1)*3)-1); // setfill and setw to give the right amount of '-' on the top and bottom
          cout << "\n";

      for(int f = 0; f < ROW; f++) // printing out the info of the 2d character array from the unique characters
      {
          char c;
          printf("| ");
          for(int d = 0; d < COLUMN; d++) 
          {
            switch(region[f][d])
            {
                case 'q':
                            c = '1';
                            break;
                case 'v':
                            c = '5';
                            break;
                case 'f':
                            c = '5';
                            break;
				case 'w':
							c = '2';
							break;
				case 'y':
							c = '3';
							break;
				case 'u':
							c = '4';
							break;
                case 'a':
							c = '1';
							break;
				case 'b':
							c = '2';
							break;
				case 'd':
							c = '3';
							break;
				case 'e':
                            c = '4';
							break;
                default:
                            c = region[f][d];
                            break;
            };
            printf("%c", c);
	        printf(" ");
          }
          printf("|");
          printf("\n");
      }

          cout << setfill('-');
	  cout << setw(((ROW-1)*3)-1);
          cout << "\n";


          return;
};

        int SimCity::gettime() // returning refreshrate
        {
            return refreshRate;
        }

        void SimCity::printt() // printing out the bare information when wanted due to refreshrate
        {
            cout << "Available workers: " << Workers << " Available Goods: " << Goods << endl;
        }
        
        int SimCity::getlimit() // returning the timelimit
        {
            return timeLimit;
        }
