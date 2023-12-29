#pragma once
#ifndef VENDING
#define VENDING

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include "dataFile.h"

using namespace std;

class vending{
public:

    vending(vector<string>);
    ~vending();
    void loadItem(vector<string>);
    void unloadItem(int);
    void unloadItem(vector<int>);
    vector<int> findProduct(int);

    friend ostream& operator << (ostream& out, vending& v) {
        int index = 0;
        string type;
        int numOfItems = 0;
        string s;
        string item;
        for (vector<queue<string>>::iterator i = v.slots.begin(); i != v.slots.end(); i++) {
            type = v.types.at(index);
            numOfItems = v.sizeOfSlots.at(index);
            s = v.directory.at(index);
		size_t size = s.length();
            for (size_t i = 0; i < size; i++) {
                if (s[i] == ',') {
                    break;
                }
                else {
                    item += s[i];
                }
            }
            out << "QUEUE #" << index << " CONTAINS: " << endl;

            out << type << ": (" << item << "): " << numOfItems << endl;

            //Sets a queue of strings equal to the current queue
            //queue<string> currQueue = *i;

            //Prints out the data in the queue
            /*
            while (!currQueue.empty()) {
                out << currQueue.front() << " ";
                out << endl;
            }
            */

            out << endl;

            ++index;
		item = "";
        }
        return out;
    }

private: 
    vector<string> directory;
    vector<string> realDirectory;
    vector<string> types;
    vector<queue<string>> slots;
    vector<int> sizeOfSlots;
    dataFile d;
};

#endif
