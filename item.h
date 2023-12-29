#pragma once
#ifndef ITEM
#define ITEM

#include<iostream>
#include<string>

using namespace std;

class item {
public:
    item();
    void setName(string);
    void setCalories(float);
    string getName();
    float getCalories();

protected:
    string name;
    float calories;
    string type;
};

#endif
