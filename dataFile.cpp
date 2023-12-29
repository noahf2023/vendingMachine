#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include "dataFile.h"

using namespace std;

/*
    This method creates a vector of strings, and the strings comes directly from a file called "directory.txt"
    The vector of strings is returned.
*/
vector<string> dataFile::loadDirectory() {

    //This block of code creates the necessary variables
    ifstream infile;
    string a;

    //This vector of strings, called direct, will contain the strings obtained from the file, and will be returned
    vector<string> direct;

    //Opens the directory.txt file
    infile.open("directory.txt", ios_base::in);

    //Checks if the file is opened or not. If the file isn't opened, the program will terminate
    if (infile.fail()) {
        cout << "File could not be opened" << endl;
        exit(1);
    }

    //Goes through the strings in "directory.txt" and pushes the strings into a vector
    while (getline(infile, a)) {
        direct.push_back(a);
    }

    //Closes the file
    infile.close();

    //The vector, now with the strings obtained from "directory.txt," is returned
    return direct;
}

/*
    This method, called loadSampleInput, returns a vector of ints obtained from the input.txt file
    The vector of ints will contain the input from the vending machine
*/
vector<int> dataFile::loadSampleInput() {

    //The necessary variables for this method are created in this block of code
    int num;
    ifstream infile;

    //This vector will contain the ints that will be returned
    vector<int> input;

    //This line of code opens the "input.txt" file
    infile.open("input.txt", ios_base::in);

    //Checks if the file is opened or not
    if (infile.fail()) {
        cout << "File could not be opened" << endl;
        exit(1);
    }

    //Pushes each integer in the "input.txt" file into a vector of ints
    while (infile >> num) {
        input.push_back(num);
    }

    //Closes the file
    infile.close();

    //Returns the vector of ints
    return input;
}

/*
    This method will parse the strings of the vector passed in
    The purpose of this method is to find the type of item in the vending machine, like drinks or snacks
*/
vector<string> dataFile::parseString(vector<string> directory) {

    //The necessary variables are initialized in this block of code
    ifstream infile;
    string a;
    string b;
    string c;

    //This vector will contain the strings that will be parsed
    vector<string> realDirectory;

    //Opens "directory.txt"
    infile.open("directory.txt", ios_base::in);

    //An if statement that checks if the "directory.txt" file is opened or not
    if (infile.fail()) {
        cout << "File could not be opened" << endl;
        exit(1);
    }

    //A for loop that traverses the passed vector of strings
    //The strings contained in the directory vector are parsed in this for loop
    //What matters here is the type of drink or snack. This is what the for-loop is searching for.
    for (vector<string>::iterator k = directory.begin(); k != directory.end(); k++) {
        getline(infile, b, ',');
        getline(infile, c, ',');
        getline(infile, a);
        realDirectory.push_back(c);
    }

    //Closes the file
    infile.close();

    //Returns the realDirectory vector of strings, now having the types of snacks and drinks pushed in
    return realDirectory;
}

/*
    This method parses data obtained from "directory.txt" to find out how many items the queue, created in vending machine, will have
*/
vector<int> dataFile::parseData() {

//Initializing the necessary variables
    int numOfItems = 0;
    string a;

//This vector will be returned. It contains the numbers of the items.
    vector<int> numbers;

//Opens the file
    ifstream infile;
    infile.open("directory.txt", ios_base::in);

//Checks if the file has failed
    if (infile.fail()) {
        cout << "File could not be opened" << endl;
        exit(1);
    }

//String iterator which will be used to find the last part of the string
	string::iterator it;

//Goes through "directory.txt" to find the number of items
    while (getline(infile, a)) {
        it = a.end();
        if (*(it) == ' ') {
            numOfItems = *(it) - '0';
        }
        else {
            numOfItems = *(it - 1) - '0';
        }
        numbers.push_back(numOfItems);
    }


//Closes the file
    infile.close();

//Returns a vector of ints that contain the numbers of items
    return numbers;
}