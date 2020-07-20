#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class SimCity // class that will access the region file and take in the information
{
    private:

        string regionname; // file name to be taken read in and accessed  
        int timeLimit, refreshRate, ROW, COLUMN, Workers, Goods; // int variables to take in the time limit refresh rate and to store the number of rows and columns in the 2d array
        char ** region; // making a 2 dimensional array to adjust the information taken in from the input file
	

    public:
        SimCity(); // Constructor of the class to give null values for the variables
        void LoadData(); // the load file that reads the configuration file
        void LoadRegion(); // loading in the region file using the name given
        void print(); // print function to output the 2 dimensional array
	    void Resident(); // resident evil takes in and processes the adjacent and change function
        bool adjacent(int x, int y); // checks for adjacent cells in resident  
        char** change(char** temp,int** hey); // changes cells based of int 2d array in resident
        void Industrial(); // industry to process the 
        bool adjacentI(int x, int y); // checks for adjacent cells in industrial
        char** changeI(char** temp,int** hey); // changes cells based of int 2d array in Industrial
        void Commercial(); // processing the commercial cells
        char** changeC(char** temp,int** hey); // changes cells based of int 2d array in commercial
        bool adjacentC(int x, int y); // checks for adjacent cells in commercial
        int gettime(); // get the refreshrate
        void printt(); // just printing out the info not 2d array
        int getlimit(); // get the time limit
        bool whilecheck(); // checking through to see if any changes can be had
        int** pollution();
        void decrem(int** hey, int x, int y);
        void analysis(int ** hey);
};

