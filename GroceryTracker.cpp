/*
 * GroceryTracker.cpp
 * CIS210
 * Date: 8/10/23
 * Author: Justin Arruda
 */

#include <string>
#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
using namespace std;

class Inventory
{
public:
    void setInventoryList(string groceryItem);
    map<string, int> getInventoryList();
    void findSpecificItem(string groceryItem);  // function for menu option 1
    void printNumerical();                      // function for menu option 2
    void printHistogram();                      // function for menu option 3
    void storeGroceryList();                    // function to store data in formatted .dat file
private:
    map<string, int> inventoryList;
};

// constructor for class
Inventory GroceryInventory;

// set function for map values
void Inventory::setInventoryList(string groceryItem)
{
    inventoryList[groceryItem]++;   // add 1 to value if grocery item already exists, if not create new grocery item with value 1;
}

// get function for map
map<string,int> Inventory::getInventoryList()
{
    return inventoryList;           // return map
}

// function to make a string n size of c char for histogram and menu printing
string nCharString(size_t n, char c) {
    int i;
    string newString;

    // loop to add desired amount of chars to a single string
    for (i = 0; i < n; i++)
    {
        newString += c;
    }

    return newString;       // return constructed string
}

// function to print menu options
void printMenu()
{
    cout << nCharString(50, '=') << endl;
    cout << "Please enter an option 1 - 4" << endl;
    cout << nCharString(50, '-') << endl;
    cout << "1 - Input a specific item or word to search for." << endl;
    cout << "2 - Print a frequency list of all items purchased." << endl;
    cout << "3 - Print a histogram of all items purchased." << endl;
    cout << "4 - Exit program." << endl;
    cout << nCharString(50, '=') << endl;
}

// function to verify integer input
int validateInput()
{
    int inputValue;

    while (!(cin >> inputValue))        // loop until int value is entered
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid number!" << endl;
    }

    return inputValue;                  // return verified int value
}

// function to loop until 1-4 entered
int menuInput()
{
    bool validChoice = true;
    int menuChoice = 0;

    while (validChoice) // loop to get user to enter 1-4 with checks for number in range
    {
        printMenu();
        menuChoice = validateInput();   // function to validate int was entered and loop until int is entered
        if (menuChoice >= 1 && menuChoice <= 4) // user enters 1-4
        {
            validChoice = false;
        }
        else
        {                                       // user enters number not 1-4
            cout << "Please enter a valid menu option!" << endl;
        }
    }

    return menuChoice; // return valid menu option entered
}

// function to search map for grocery item and return quantity if item is found
void Inventory::findSpecificItem(string groceryItem)
{
    if (inventoryList.find(groceryItem) == inventoryList.end())                 // if statement to check if groceryItem is in map
    {
        cout << "No item of " << groceryItem << " found in list!" << endl;      // print error is no groceryItem found
    }
    else
    {
        cout << groceryItem << " " << inventoryList.at(groceryItem) << endl;    // print item and quantity if found
    }
}

// function to print entire list of grocery items and the quantity of each item
void Inventory::printNumerical()
{
    // create iterator to go through entire map
    map<string, int>::iterator i;

    // print descriptive title
    cout << "\nAll items and their frequencies: " << endl;

    for (i = inventoryList.begin(); i != inventoryList.end(); i++)      // loop to go through each item in map
    {
        cout << i->first << " " << i->second << endl;                   // print item name and quantity each line
    }
}

// function to print list of grocery items and quantity as a histogram using *'s
void Inventory::printHistogram()
{
    // create iterator to go through entire map
    map<string, int>::iterator i;

    // print descriptive title
    cout << "\nAll items and their frequencies as a histogram: " << endl;

    for (i = inventoryList.begin(); i != inventoryList.end(); i++)                          // loop to go through each item in map
    {
        cout << i->first << " " << nCharString(inventoryList.at(i->first), '*') << endl;    // print item name and call nchar function to print quantity of *s per item
    }
}

// function to save numerical list as .dat file
void Inventory::storeGroceryList()
{
    // create iterator to go through entire map
    map<string, int>::iterator i;

    // create new data file to store quantity of items
    ofstream QuantityList("frequency.dat");

    // using for loop to store each item in map with value associated
    for (i = inventoryList.begin(); i != inventoryList.end(); i++)      // loop to go through each item in map
    {
        QuantityList << i->first << " " << i->second << endl;                   // print item name and quantity each line
    }

    // close file after writing to it
    QuantityList.close();
}

// function to loop menu until exit is selected
void menuAction(int choice)
{
    if (choice == 1)                // search for keyword
    {
        string keyword;
        cout << "Please enter the specific item you are specifically looking for (case sensitive): " << endl;
        cin >> keyword;
        GroceryInventory.findSpecificItem(keyword);
        // for loop to iterate through list and count keyword
    }
    else if (choice == 2)           // print numerical list
    {
        GroceryInventory.printNumerical();
    }
    else if (choice == 3)           // print histogram
    {
        GroceryInventory.printHistogram();
    }
    else if (choice == 4)
    {
        // exit program
        cout << "Exiting program, thank you!" << endl;
        exit(0);                                // exits loop and closes program
    }
    menuAction(menuInput());                    // restart loop after performing action
}

int main()
{
    // declare variables needed
    string inventoryItem;

    // read input from text file
    ifstream ShoppingList("CS210_Project_Three_Input_File.txt");
    while (ShoppingList.good())
    {
        getline(ShoppingList, inventoryItem);               // read each line in txt file and store as string
        GroceryInventory.setInventoryList(inventoryItem);   // add string as item to map, if item already exists will increment quantity
    }
    // close file after reading data and creating array
    ShoppingList.close();

    // using function to store copy of formatted data to .dat file
    GroceryInventory.storeGroceryList();

    // enter the menuAction function to loop until user exits
    menuAction(menuInput());

}