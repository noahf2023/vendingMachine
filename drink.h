#pragma once
#ifndef DRINK
#define DRINK

#include<iostream>
#include<string>
#include "item.h"

using namespace std;

class drink : public item {
public:
    drink();
    void setOunces(float);
    void setType(string);
    float getOunces();
    string getType();

    friend ostream& operator << (ostream& out, drink& d) {
        out << "Drink name: " << d.name << endl;
        out << "Calories: " << d.calories << endl;
        out << "Ounces: " << d.ounces << endl;
        out << "Type: " << d.type << endl;
        return out;
    }
private:
    float ounces;
    string type;
};

#endif
