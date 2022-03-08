//You must upload the .h, .cpp files, outdata file, picture of working program - jpg, png, bmp (upload all individual files same time, do not zip files)Your name must be in the code and remember comments.

#include<iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "CraftInv.h"
using namespace std;

// defining member functions
void displayMenu();
void display_contents(string);
void read_file(string);
bool is_file_exist(string);
void setter_function(vector<int>,vector<string>,vector<int>,vector<double>);
void clear_vectors(vector<int>, vector<string>, vector<int>, vector<double>);

// creating structs to hold data
struct Item
{
  vector<int> item_id;
  vector<string> item_name;
  vector<int> qty;
  vector<double> price;
};

struct Temp 
{
  int temp_id;
  string temp_name;
  int temp_qty;
  double temp_price;
};

struct New 
{
  int newID;
  string newName;
  int newQty;
  double newPrice;
};

int main()
{
 string fileName; // To hold the file name
 char choice; // To hold the choice variable
 ifstream file; // File stream object
 


cout << "Please enter an order text file to access the menu: ";
cin>> fileName; // asking user for file name before program



while (!is_file_exist(fileName)){ // input validation
    cout<<"Error opening the file. Please try again: ";

    cin>> fileName;
}

CraftInv order; // creating an instance of the CraftInv header class

// creating instances of our structs
struct Item p;
struct Temp t;
struct New n;

  // opening user file
  file.open(fileName, ios::in);

  if (file)
   {
      // storing file data in vectors
      while (file >> t.temp_id >> t.temp_name >> t.temp_qty >> t.temp_price)
      {
        p.item_id.push_back(t.temp_id);
        p.item_name.push_back(t.temp_name);
        p.qty.push_back(t.temp_qty);
        p.price.push_back(t.temp_price);
      }
   }
   else
   {
      // Display an error message.
      cout << "Error opening the file.";

      // Exit the program.
      exit(0);
   }
   file.close();

  // setting variables to class setter functions
   setter_function(p.item_id, p.item_name, p.qty, p.price); 

 do
 {
   
 // Displaying the menu and getting a valid selection.
 displayMenu();
 cin >> choice;
 while (toupper(choice) < 'A' || toupper(choice) > 'H')
 {
 cout << "Please make a choice in the range "
 << "of A through H:";
 cin >> choice;
 }

 // Processing the user's menu selection with a switch statement
 switch(choice)
 {
  case 'a':
  case 'A': cout << "          █▀█ █▀█ █░░ ▄▀█ █▄░█ █▀▄ ▀ █▀   █▄▄ ▄▀█ ▀█ ▄▀█ ▄▀█ █▀█" << endl;
    cout << "          █▀▄ █▄█ █▄▄ █▀█ █░▀█ █▄▀ ░ ▄█   █▄█ █▀█ █▄ █▀█ █▀█ █▀▄" << endl;
    cout << "\n\n";
    cout << setw(0) << "ItemID";
    cout << setw(8) << "Name";
    cout << setw(10) << "Qty";
    cout << setw(11) << "Price" << endl;
    
    cout << "-----------------------------------------\n";
    // calling a function to display the file contents
    display_contents(fileName);
    cout << "\n\n";
  break;
  case 'b':
  case 'B':
  cout << "\n\n";
  cout << "          █▀█ █▀█ █░░ ▄▀█ █▄░█ █▀▄ ▀ █▀   █▄▄ ▄▀█ ▀█ ▄▀█ ▄▀█ █▀█" << endl;
    cout << "          █▀▄ █▄█ █▄▄ █▀█ █░▀█ █▄▀ ░ ▄█   █▄█ █▀█ █▄ █▀█ █▀█ █▀▄" << endl;
    cout << "\n\n";
    order.totals(p.item_id, p.item_name, p.qty, p.price); // calling class function to compute totals
  break;
  case 'c':
  case 'C':
  // calling class functions to write receipt to out file and print on screen
  order.write_receipt(p.item_id, p.item_name, p.qty, p.price, fileName); 
  order.print_receipt(p.item_id, p.item_name, p.qty, p.price);
  break;
  case 'd':
  case 'D':
  cout << "\n"; 
  cout << "          █▀█ █▀█ █░░ ▄▀█ █▄░█ █▀▄ ▀ █▀   █▄▄ ▄▀█ ▀█ ▄▀█ ▄▀█ █▀█" << endl;
    cout << "          █▀▄ █▄█ █▄▄ █▀█ █░▀█ █▄▀ ░ ▄█   █▄█ █▀█ █▄ █▀█ █▀█ █▀▄" << endl;
  cout << "\n";
  // calling function to display inventory
  order.inventory(p.item_id, p.item_name, p.qty, p.price);
  cout << "\n";
  break;
  case 'e':
  case 'E': cout << "\n";
  // calling function to find a specific item based on order number
  order.find_item(p.item_id, p.item_name, p.qty, p.price);
  break;
   case 'f':
   case 'F': 
   // clearing vectors before taking new values from file 
   clear_vectors(p.item_id, p.item_name, p.qty, p.price);

   cout << "Please enter another text file order to start a new order: ";
  cin>> fileName;



while (!is_file_exist(fileName)){ // input validation
    cout<<"Error opening the file. Please try again: ";

    cin>> fileName;
}
// opening files and storing values
file.open(fileName, ios::in);

  if (file)
   {
      while (file >> t.temp_id >> t.temp_name >> t.temp_qty >> t.temp_price) // getline(inputFile, value)
      {
        p.item_id.push_back(t.temp_id);
        p.item_name.push_back(t.temp_name);
        p.qty.push_back(t.temp_qty);
        p.price.push_back(t.temp_price);
      }
   }
   else
   {
      // Display an error message.
      cout << "Error opening the file.";

      // Exit the program.
      exit(0);
   }
   file.close();

   setter_function(p.item_id, p.item_name, p.qty, p.price);

   break;

  case 'g':
  case 'G': 
      // adding new items to the inventory
      cout << "Add item number: ";
      cin >> n.newID;
      p.item_id.push_back (n.newID);
      cout << "Add item name: ";
      cin >> n.newName;
      p.item_name.push_back (n.newName);
      cout << "Add item quantity: ";
      cin >> n.newQty;
      p.qty.push_back(n.newQty);
      cout << "Add item price: $";
      cin >> n.newPrice;
      p.price.push_back(n.newQty);

 }
 } while (toupper(choice) != 'H');

 // Open the file.

 return 0;
 }

bool is_file_exist(string fileName) // function to check if file exists
{
    std::ifstream infile(fileName);
    return infile.good();
}


void displayMenu() // user menu
{
  cout << "\n";
  cout << "           █▀▄▀█ █▀▀ █▄░█ █░█" << endl;
  cout << "           █░▀░█ ██▄ █░▀█ █▄█" << endl;
  cout << "-----------------------------------------\n";
  cout << "A) Read from a file the Items bought\n";
  cout << "B) Calculate each item's total, the sub-total, and tax\n";
  cout << "C) Write to an out file and screen with the sorted output\n";
  cout << "D) Print out current inventory\n";
  cout << "E) Find and display items ordered using Order #\n";
  cout << "F) New order\n";
  cout << "G) Add Inventory\n";
  cout << "H) Exit\n\n";
  cout << "Enter your choice:";
  cout << "\n\n";
}

void display_contents(string file) // function to display file contents
{
    string getcontent;
    ifstream openfile (file);
    if(openfile.is_open())
    {
        while(! openfile.eof())
        {
            getline(openfile, getcontent);
            cout << getcontent << endl;
        }
    }
}

void setter_function(vector<int> vectID, vector<string> vect_name, vector<int> vect_qty,
  vector<double> vect_prce) // function to set header accessors
{
  CraftInv order;
  for(int i = 0; i < vectID.size(); i++)
   {
     order.setItemNumber(vectID.at(i));
     order.setName(vect_name.at(i));
     order.setQuantity(vect_qty.at(i));
     order.setCost(vect_prce.at(i));
   }
}

void clear_vectors(vector<int>id, vector<string> name, vector<int> v_qty, vector<double> v_price) // function to clear vectors
 {
   id.clear();
   name.clear();
   v_qty.clear();
   v_price.clear();
 }