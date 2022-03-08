#ifndef CRAFTINV_H_INCLUDED
#define CRAFTINV_H_INCLUDED
#include<iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class CraftInv
{
  // setting private variables
  private:

    int itemNumber;

    string itemName;

    int quantity;

    double cost;

    double totalCost;

    double tax;


 public:
     // setting private member variables to 0 in default constructor
     CraftInv()
     {
         itemNumber = 0;
         itemName = "";
         quantity = 0;
         cost = 0;
         totalCost= 0;
         tax = 0.0;
     }

     // setting constructor #2 that accepts an item’s number, cost, and quantity as arguments.
     CraftInv(int num, string nme, int qty, double prce)
     {
       itemNumber = num;
       itemName = nme;
       quantity = qty;
       cost = prce;
     }

     // Mutators
     void setItemNumber(int num)
     {
         itemNumber = num;
     }

     void setName(string nme)
     {
       itemName = nme;
     }

     void setQuantity(int qty)
     {
         quantity = qty;
     }

     void setCost(double prce)
     {
         cost = prce;
     }

     void setTotalCost(double t)
     {
         totalCost = t;
     }

     void setTax(double tx)
     {
         tax = tx;
     }

     // Accessors
     int getItemNumber()
     {
         return itemNumber;
     }

    string getName()
    {
      return itemName;
    }

     int getQuantity()
     {
         return quantity;
     }

     double getCost()
     {
         return cost;
     }

     double getTax()
     {
         tax = totalCost * 0.08875;
         return tax;
     }

      double getTotalCost()
     {
         totalCost = quantity*cost;
         return totalCost + tax;
     }

  void totals(vector<int> vectID, vector<string> vect_name, vector<int> vect_qty,
  vector<double> vect_prce) // function calculating totals
{
  CraftInv order;
  double grandTotalSum = 0;

   cout << "ItemID";
   cout << "\t\t" << "Name";
   cout << "\t\t" << "Qty";
   cout << "\t\t" << "Price";
   cout << "\t\t" << "Tax";
   cout << "\t\t" << "Total" << endl;
   cout << "------------------------------------------------------------\n";

   for(int i = 0; i < vectID.size(); i++) // iterating through the size of the name vector
   {
     order.setQuantity(vect_qty.at(i));
     order.setCost(vect_prce.at(i));

     grandTotalSum += order.getTotalCost();
    
    // printing values
     cout << vectID[i];
     cout << "\t\t" << vect_name[i];
     cout << "\t\t" << vect_qty[i];
     cout << "\t\t" << vect_prce[i];
     cout << "\t\t" << setprecision(2) << fixed << order.getTax(); 
     cout << "\t\t" << order.getTotalCost() << endl;


   }
     cout << "\n\t\t\t\t\t" << "GRAND TOTAL: $" << grandTotalSum << endl;
} 

void write_receipt(vector<int> vectID, vector<string> vect_name, vector<int> vect_qty,
  vector<double> vect_prce, string file_name) // function to write receipt to out file
{
     
  CraftInv order;
  double grandTotalSum = 0;
  ofstream MyFile("receipt.txt");

    MyFile << "\t\t\t\t█▀█ █▀▀ █▀▀ █▀▀ █ █▀█ ▀█▀" << endl;
    MyFile << "\t\t\t\t█▀▄ ██▄ █▄▄ ██▄ █ █▀▀ ░█░" << endl;
    MyFile << "--------------------------------------------" << endl;
    MyFile << "ItemID";
    MyFile << "\t\t" << "Name";
    MyFile << "\t\t" << "Qty";
    MyFile << "\t\t" << "Price";
    MyFile << "\t\t" << "Tax";
    MyFile << "\t\t" << "Total" << endl;
    MyFile << "--------------------------------------------\n";
     
    for(int i = 0; i < vectID.size(); i++) {
      order.setQuantity(vect_qty.at(i));
      order.setCost(vect_prce.at(i));
      grandTotalSum += order.getTotalCost();
      MyFile << vectID[i];
      MyFile << "\t\t" << vect_name[i];
      MyFile << "\t\t" << vect_qty[i];
      MyFile << "\t\t" << vect_prce[i];
      MyFile << "\t\t" << setprecision(2) << fixed << order.getTax();
      MyFile << "\t\t" << order.getTotalCost() << endl;
      
    }

  
  MyFile << "--------------------------------------------" << endl;
  MyFile << "\t\t\t\t\t\tGrand Total: $" << grandTotalSum << endl;

  MyFile.close();
} 

void print_receipt(vector<int> vectID, vector<string> vect_name, vector<int> vect_qty,
  vector<double> vect_prce) // function to print receipt on screen
{
     
  CraftInv order;
  double grandTotalSum = 0;

     // Create and open a text file

    cout << "\t\t\t\t█▀█ █▀▀ █▀▀ █▀▀ █ █▀█ ▀█▀" << endl;
    cout << "\t\t\t\t█▀▄ ██▄ █▄▄ ██▄ █ █▀▀ ░█░" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "ItemID";
    cout << "\t\t" << "Name";
    cout << "\t\t" << "Qty";
    cout << "\t\t" << "Price";
    cout << "\t\t" << "Tax";
    cout << "\t\t" << "Total" << endl;
    cout << "-----------------------------------------------------------\n";
     
    for(int i = 0; i < vectID.size(); i++) {
      order.setQuantity(vect_qty.at(i));
      order.setCost(vect_prce.at(i));
      cout << vectID[i];
      cout << "\t\t" << vect_name[i];
      cout << "\t\t" << vect_qty[i];
      cout << "\t\t" << vect_prce[i] << setprecision(2) << fixed;
      cout << "\t\t" << setprecision(2) << fixed << order.getTax();
      cout << "\t\t" << order.getTotalCost() << "\n" << endl;
      
    }
} 

  void getIndex(vector<int> vectID, vector<string> vect_name, vector<int> vect_qty,
  vector<double> vect_prce, int K) // function for getting the vector index of an element
  {
    CraftInv order;
      auto it = find(vectID.begin(), vectID.end(), K);
  
      // If element was found
      if (it != vectID.end())
      {
      
          // calculating the index
          // of K
          int index = it - vectID.begin();
          order.setItemNumber(vectID.at(index));
          order.setName(vect_name.at(index));
          order.setQuantity(vect_qty.at(index));
          order.setCost(vect_prce.at(index));

          cout << "\n" << endl;
          cout << "--------------------------------------\n";
          cout << "ItemID";
          cout << "\t\t" << "Name";
          cout << "\t\t" << "Qty";
          cout << "\t\t" << "Price" << endl;
          cout << "--------------------------------------\n";

          cout << order.getItemNumber();
          cout << "\t\t" << order.getName();
          cout << "\t\t" << order.getQuantity();
          cout << "\t\t" << order.getCost() << endl;
          cout << "--------------------------------------\n";
          cout << "\n";
      }
      else {
          cout << "Please enter a correct item number." << endl;
      }
  }

  // step E
  void find_item(vector<int> vectID, vector<string> vect_name, vector<int> vect_qty,
  vector<double> vect_prce) // finding vector element in order based on order number
  {
    CraftInv order;
    int itemNum;
    cout << "Please enter an item's order number: ";
    cin >> itemNum;
    order.getIndex(vectID, vect_name, vect_qty, vect_prce, itemNum);

  }

  void inventory(vector<int> vectID, vector<string> vect_name, vector<int> vect_qty,
  vector<double> vect_prce) // function to find and display inventory
{
  CraftInv order;

  cout << "\n" << endl;
  cout << "\t█ █▄░█ █░█ █▀▀ █▄░█ ▀█▀ █▀█ █▀█ █▄█" << endl;
  cout << "\t█ █░▀█ ▀▄▀ ██▄ █░▀█ ░█░ █▄█ █▀▄ ░█░" << endl;
  cout << "------------------------------------------" << endl;
  cout << "ItemID";
  cout << "\t\t" << "Name";
  cout << "\t\t" << "Qty";
  cout << "\t\t" << "Price" << endl;
  cout << "------------------------------------------\n";

   for(int i = 0; i < vectID.size(); i++)
   {
      order.setItemNumber(vectID.at(i));
      order.setName(vect_name.at(i));
      order.setQuantity(vect_qty.at(i));
      order.setCost(vect_prce.at(i));
      cout << vectID[i];
      cout << "\t\t" << vect_name[i];
      cout << "\t\t" << vect_qty[i];
      cout << "\t\t" << vect_prce[i] << endl;
    } 

}

};



#endif // CRAFTINV_H_INCLUDED
