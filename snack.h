#pragma once
#ifndef SNACK
#define SNACK

#include<iostream>
#include<string>
#include "item.h"

using namespace std;

class snack : public item {
public:
    snack();
    void setWeight(float);
    void setContainsNuts(bool);
    float getWeight();
    bool getContainsNuts();

    friend ostream& operator << (ostream& out, snack& s) {
        out << "Snack Name: " << s.name << endl;
        out << "Calories: " << s.calories << endl;
        out << "Weight: " << s.weight << endl;
        if (s.containsNuts == true) {
            out << "Contains nuts" << endl;
        }
        else {
            out << "Does not contain nuts" << endl;
        }
        return out;
    }
private:
    float weight;
    bool containsNuts;
};

#endif
