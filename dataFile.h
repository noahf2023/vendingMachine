#pragma once
#ifndef DATA_FILE
#define DATA_FILE

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>

using namespace std;

struct dataFile {
    vector<string> loadDirectory();
    vector<int> loadSampleInput();
    vector<string> parseString(vector<string>);
    vector<int> parseData();
};

#endif
