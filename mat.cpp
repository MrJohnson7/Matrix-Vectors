#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS421 File mat.cpp for HW2A Matrix Practice
// Your name: Nicholas Johnson
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry (vector) length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char x)
{ 
  int numConversion = int(x);  // take X and convert it to its ascii value
  int asciMath = numConversion - 109; // if m then = 109 need to equal 0. Minus 109
  return asciMath; //return this ascii value for the colums index
  // ** do a formula to convert m to 0, n to 1, o to 2 etc.
} 

int readTable()
{  int row, col;  // row and col numbers
   char col_c;     // column indicator
   ifstream fin ("lines.txt", ios::in); // this is how we get elements from the file
 
  // Read in the file into T
   while (fin >> row) // next line of file
     {
       fin >> col_c;
       col = convert(col_c);  // convert to a slot number
       vector<char> v;  // a vector to fill
       char c; // one char from the file

       for (int i = 0; i < VM; i++)        //   chars from the file (there are VM chars)
	 {
	   fin >> c; //taking in the chars one by one from the file
	   v.push_back(c); //pushing the chars onto Vector v
	 }
       for(int i = 0; i < VM; i++)
	 {
	   T[row][col].push_back(v[i]); // ** Put  v in T[row][col]
	 }
     }//end of while
   return 0; //need to return an int
}

// Displays a vector or "---" if the vector is empty
void showVector(vector<char> v)
{ if (v.size() == 0)  // empty entry
    for (int i = 1; i <= VM; i++) cout << "- "; //
  else
    for(int i = 0; i < VM; i++) cout << v[i] << " "; // show the content of v separated by blanks (e.g. "m n o")
      // cout << v[i] << " ";
}

// Displays T as a table, separating entries with "|" 
void displayTable()
{
  int numTracker = 1;
  for(int i = 0; i < VM; i++) // for loop 
    {
      cout << i << "| "; //cout the row number followed by |
      for(int j = 0; j < C; j++) // for loop 
	{
	  showVector(T[i][j]); // pass the vector at the specific location
	}

      cout << endl; // end of line
    }
  //space with rowa for loop// use columsto place vector  // ** display T nicely labeled with row numbers (col numbers not needed)
  //    by calling showVector 
}


// Driver
int main()
{
  cout << "Reading table from lines.txt..." << endl;
  readTable(); 
  displayTable();  
}//the end
