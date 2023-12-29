#include<iostream>
#include<string>
#include "item.h"

using namespace std;

/*
    Default constructor sets name to an empty string and calories to 0.
*/
item::item() {
    name = " ";
    calories = 0;
}

/*
    Sets name of item taken from user.
*/
void item::setName(string n) {
    name = n;
}

/*
    Sets calories of item taken from user.
*/
void item::setCalories(float cal) {
    calories = cal;
}

/*
    Returns name of item.
*/
string item::getName() {
    return name;
}

/*
    Returns the calories of the item
*/
float item::getCalories() {
    return calories;
}
