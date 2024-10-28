// **********************************************************
// **********************************************************

/*                  GROUP MEMBERS                     */
/*
 
            Aliza Ibrahim    i21-0470
            Faiza Rehman     i21-0836
            Kalsoom Tariq    i21-2487
            Kissa Zahra      i21-0572
 
 */
// **********************************************************
// **********************************************************

#include"Header.h"
#include<fstream>

// **********************************************************
// **********************************************************

/*                  FUNCTION PROTOTYPE                      */

// **********************************************************
// **********************************************************

void Initialize(string*);
void call_SCC(string);

// **********************************************************
// **********************************************************

/*                      DRIVER CODE                          */

// **********************************************************
// **********************************************************

int main()
{
    //Initialize File names
    string* File_names=new string[2];
    
    Initialize(File_names);
    
    for(int i=0;i<2;i++)
    {
        call_SCC(File_names[i]);
    }
   
    return 0;
}

// **********************************************************
// **********************************************************

/*                  FUNCTION DEFINITIONS                      */

// **********************************************************
// **********************************************************

void Initialize(string* File_names)
{
    File_names[0]="/Users/HinataShoyo/Documents/DISCRETE/TRYINGGDESCRETE/File.txt";
    File_names[1]="/Users/HinataShoyo/Documents/DISCRETE/TRYINGGDESCRETE/twitter_combined.txt";
    
}

void call_SCC(string fname)
{
    // open file containing dataset using fstream object
    ifstream file;
    
    // Make an object of class Undirected graph of size found
    Undirected_Graph g;
    
    // Storing data points 1 and 2 in variables to be passed
    int v1=0;
    int v2=0;
   
    file.open(fname , ios::in);
    if(file.is_open())
    {
         while(file>>v1)
         {
             file>>v2;
             g.addEdge(v1, v2);
         }

    }
    file.close();
    
    // Displaying the size of largest Strongly Connected Component
    if(fname=="/Users/HinataShoyo/Documents/DISCRETE/TRYINGGDESCRETE/File.txt")
        cout<<"\nThe size of largest SCC in google dataset is: ";
    else
        cout<<"\nThe size of largest SCC in twitter dataset is: ";
    
    
    g.Size_of_LargestSCC();

}

// **********************************************************
// **********************************************************

/*                  PROGRAM END                      */

// **********************************************************
// **********************************************************
