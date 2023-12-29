#include<iostream>
#include<string>
#include "snack.h"

using namespace std;

/*
    Default constructor that sets weight to zero, and sets a boolean variable that checks if the snack contains nuts to false.
*/
snack::snack() {
    weight = 0;
    containsNuts = false;
}

/*
    Sets weight of snack.
*/
void snack::setWeight(float w) {
    weight = w;
}

/*
    If the snack contains nuts, set to true. If the snack doesn't contain nuts, set to false.
    Data taken by user.
*/
void snack::setContainsNuts(bool cN) {
    containsNuts = cN;
}

/*
    Returns the weight of the snack.
*/
float snack::getWeight() {
    return weight;
}

/*
    Returns either true or false, which depends on if the snack contains nuts or not.
*/
bool snack::getContainsNuts() {
    return containsNuts;
}
