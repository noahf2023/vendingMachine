//Title: Driver.cpp
//Author: Matthew Parsons
//Date: 
//Description: Part of a Vending Machine project for UMBC CMSC341.
//             The Driver to initialize and run the vending machine program.
//
// Please notice there is one note at the bottom of that driver. 
// Dont' forget that I should also be able to add code to the end of the driver to manually remove or add items to the Vending machine. 
// (Without using the data files). So manually. 


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "vending.h"
#include "dataFile.h"
#include "item.h"
#include "snack.h"
#include "drink.h"

using namespace std;

int main() {
    //load data from file
    dataFile myData;

    //initialize Vending machine with loaded data
    vector<string> myVending = myData.loadDirectory();
    vector<int> mySelections = myData.loadSampleInput();
  

    vending myMachine(myVending);
    
    

    myMachine.loadItem(myVending);
    vector<string> l = { "Snack, Oreos, 220, 5, true, 2" };
    myMachine.loadItem(l);
    vector<int> f = {7};
cout << endl;
cout << "OVERLOADED COUT BEFORE UNLOADING: " << endl << endl;

cout << myMachine << endl;

    myMachine.unloadItem(mySelections);
    myMachine.unloadItem(f);

cout << endl;
cout << "OVERLOADED COUT AFTER UNLOADING: " << endl << endl;

cout << myMachine << endl;

    cout << endl;

    //Final output to display after removing
    //myMachine.displayItems(); //debug helper function, REALLY NEEDS overloaded cout <<

    /*****************/
    // Above DisplayItems() call is fine, but the Vending machine's deconstructor 
    // should call that function since it's the LAST operation. Notice it could be
    // done with a helper function that USES the overloaded cout <<
    // We will NOT call DisplayItems() in testing 
    /*****************/

    return 0;
}
