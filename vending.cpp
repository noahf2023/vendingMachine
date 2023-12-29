#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include <sstream>
#include "dataFile.h"
#include "vending.h"

using namespace std;

/*
    Constructor that takes in the vector of strings containing the items in the vending machine.
*/
vending::vending(vector<string> direct) {
    directory = direct;
    sizeOfSlots = d.parseData();
    types = d.parseString(direct);
}

/*
    Destructor that prints out the items, and number of items, in each queue.
    After the printing is done, each of the queues are cleared.
    After the end of the for-loop, the vector is cleared.
*/
vending::~vending() {

    //Index used in the print statement to show which queue is being printed
    //Also initializing any necessary vairables
    int index = 0;
    string type;
    int numOfItems = 0;
    int length = 0;
    string s;
    string item;
    
    cout << "DELETION HAS BEGUN: " << endl << endl;

    //This for loop goes through slots to print out each item
    for (vector<queue<string>>::iterator i = slots.begin(); i != slots.end(); i++) {
        cout << "QUEUE #" << index << " CONTAINS: " << endl;
            type = types.at(index);
            numOfItems = sizeOfSlots.at(index);
            s = directory.at(index);
            length = s.length();
            for (int i = 0; i < length; i++) {
                if (s[i] == ',') {
                    break;
                }
                else {
                    item += s[i];
                }
            }

            cout << type << ": (" << item << "): " << numOfItems << endl;

        //Sets a queue of strings equal to the current queue
        queue<string> currQueue = *i;

        //Prints out the data in the queue
        while (!currQueue.empty()){
            currQueue.pop();
        }

        //These two lines make sure the current queue is empty, since the printing is complete
        queue<string> empty;
        swap(currQueue, empty);

        //Checks if the queue is empty
        if (currQueue.empty()) {
            cout << "Queue #" << index << " is now empty." << endl;
        }

        cout << endl;

        ++index;
	item = "";
    }

    //Clears the slots vector
    slots.clear();

}

/*
    This method takes the passed vector of strings and loads each string, depending on the number of items, into a vector of queues called slots.
*/
void vending::loadItem(vector<string> v) {

    //Initializing the necessary variables
    string direct;
    queue<string> currQueue{};
    int size = 0;
    int index = 0;
    size_t checker = 0;
    char letter = ',';
    string type;

    //This for loop goes through the string vector and pushes the strings into a queue called currQueue.
    for (vector<string>::iterator i = v.begin(); i != v.end(); i++) {
        
        //Setting direct to equal the current string in the vector
        direct = *i;

        for (size_t i = 0; i < directory.size(); i++) {
            if ((directory.at(i) != direct)) {
                checker++;
            }
        }

        if (checker == directory.size()) {
            directory.push_back(direct);
            int sizeslot = 0;
            int directLength = direct.length();
            string::iterator o;
            o = direct.end();
            if (*(o) == ' ') {
                sizeslot = *(o)-'0';
            }
            else {
                sizeslot = *(o - 1) - '0';
            }
            sizeOfSlots.push_back(sizeslot);

            for (int k = 0; k < directLength; k++) {
                if (ispunct(direct[k])) {
                    k += 2;
                    do {
                        type += direct[k];
                        ++k;
                    } while (direct[k] != letter);
                    break;
                }
            }
            types.push_back(type);

        }



        //Gets the number of items using parseData()

        size = sizeOfSlots.at(index);

        //This for loop pushes the strings into in
        for (int j = 0; j < size; j++) {
            currQueue.push(direct);
        }

        //The queue of strings is pushed into slots
        slots.push_back(currQueue);

        //CurrQueue is made empty to make sure there's no overlap with the other strings in the vector
        currQueue = {};
        ++index;
    }
}

/*
    unloadItem removes an item from its queue
*/
void vending::unloadItem(int index) {

    //The numbers vector contains the similar indices 
    vector<int> numbers;
    numbers = findProduct(index);
    int currNumber = 0;
    
    //This for-loop traverses the numbers vector and removes an item from a queue if the slot size is more than one
    for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {

        //Sets the current number 
        currNumber = *i;

        //The size of the queue
        size_t size = slots.at(currNumber).size();

        //If-else statement that checks if the current queue is less than one
        if (size <= 1) {
            cout << "Queue is at 1 or less. Moving to next similar queue" << endl;
        }
        else{
            slots.at(currNumber).pop();
            --sizeOfSlots.at(currNumber);
            break;
        }
    }
}

/*
    This method is an overloaded method of unloadItem that takes in the input from the user
    After input is taken, the items are removed from their respective queue
*/
void vending::unloadItem(vector<int> input) {

    //Initializing necessary variables
    int num = 0;
    
    //A for-loop that traverses the passed vector of integers and unloads the items 
    for (vector<int>::iterator i = input.begin(); i != input.end(); i++){
        num = *i;
        unloadItem(num);
    }

}

/*
    This method returns a vector of ints that contain matching indices
*/
vector<int> vending::findProduct(int num) {

    //Index checking which strings match
    int index = 0;

    //Strings that are used to check if they're matches or not
    string match;
    string otherMatch = types.at(num);

    //The vector that contains the similar matches, or no matches
    vector<int> similarItems;

    //A for-loop that goes through the realDirectory, not the other directory, and searches for matches
    for (vector<string>::iterator i = types.begin(); i != types.end(); i++) {

        //the first string taken from realDirectory
        match = *i;

        //If statement that checks if both strings are matches
        //If they aren't, index is incremented by one
        if (otherMatch == match) {
            similarItems.push_back(index);
            ++index;
        }
        else {
            ++index;
        }
    }

    //The vector of ints containing similar indices is returned
    return similarItems;
}
