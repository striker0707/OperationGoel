/** Food database
    Created by Group 3: Elton Vinh, Gordon , Joanne Trinh, Ethan Huang, Loc, Rama. */

#include <iostream>
#include <string>

using namespace std;

//function prototypes
void menu();

int main()
{
  menu();
  
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
