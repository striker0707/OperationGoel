/** Food database
    Created by Group 3: Elton Vinh, Gordon , Joanne Trinh, Ethan Huang, Loc, */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//function prototypes
bool openFile (ofstream &dataFile);
void printToOutput(ofstream &outputFile, Hashtable hashtableobj); // Need hashtable obj that we will print out our memory to outputfile
void menu();

int main()
{
    ofstream dataFile;                    // Intializes outputFile
    
     // Check if input and output files successfully opened
    bool openFile(ofstream &dataFile);                    // Refers to the bool function below to check if files open
    
    if (openFile(dataFile)==false)       // Checks if both output and input are false
    {
        cout << "Unable to open data file" << endl;                      // If false, prints an error message
        cout << "Ending Program" << endl;
        return 1;   // Ends Program if the if statement is true
    }      // End if
    else    // When successful opening, program will print sucession
    {
        cout << "File opened successfully, file will have updated archive when program terminates" << endl;
    } // end if else

    while (foodname >> calories >> totalfat >> cholest >> sodium >> protein) // Reads file inputs continously until it runs out of inputs
    {
        foodobj(foodname, calories, totalfat, cholest, sodium, protein)   // Makes a foodobj with appropriate variables
        // Put into hashtable somehow..
        // Keys get assigned here or whatever.

    } // End while

    
  //fstream data; //open file for read AND write
  //data.open("Archive.txt")
  
    menu();
  
 // data.close();
 
    inputFile.close();      // Closes input file
    outputFile.close();     // Closes output file
  
    system("pause");//close database
    return 0;
}

void menu()
{
  char choice;
  while(ch != 9)
  {
    //menu text is taken directly from the project req
    //recommend we change or lsightly modify some of the names so more "user friendly"ish
    cout << "     MENU" << endl;
    cout << "1) Add new data" << endl;
    cout << "2) Delete data" << endl;
    cout << "3) Find and display one data record using the primary key" << endl; 
    cout << "4) List data in hash table sequence" << endl;
    cout << "5) List data in key sequence (sorted)" << endl;
    cout << "6) Print indented tree" << endl;
    cout << "7) Effeciency" << endl;
    cout << "8) SECRET MENU OPTION" << endl;
    cout << "9) Quit" << endl;
    
    cin >> choice
    
    //ENTER FUNCTION CALLS FOR EACH MODULE AS WE COMPLETE IT,
    //PLEASE COMMENT OUT YOUR FUNCTION CALL IF YOU COMMIT A CHANGE THAT IS NOT COMPILABLE
    switch(choice)
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9: //user quit case
      return 0;
      break;
    default:
    cout << "Invalid Option, please enter a valid option (1-9)." << endl;
    system("pause");
    break;
  }
}

// Bool used to see if input file successfully opened
bool openFile (ofstream &dataFile)
{
    string inputFileName = "Archive.txt";         // Declares variable for input name and assigns it to our data file
    
    dataFile.open(dataFile.c_str());                  // Opens input file with given name

    if (dataFile.fail())                                   // If the input file fails
    {
        return 0;                                           // End program if input file cannot open
    }
    else
    {
        return 1;                                           // Continues program if input file opens
    }

} // End bool

// This function is to print the payment table
void printToOutput(ofstream &dataFile, Hashtable hashtableobj)
{
    //This will ultimately depend on how the hashtable is made and used. Will be updated laters
 dataFile << hashtableobj;
}

