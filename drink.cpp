#include "drink.h"
#include<string>

using namespace std;

/*
    Default constructor that sets ounces to 0 and type to an empty string.
*/
drink::drink() {
    ounces = 0;
    type = " ";
}

/*
    Set ounces method, which sets the ounces of the drink.
*/
void drink::setOunces(float f) {
    ounces = f;
}

/*
    This method sets the type of the drink, taken in from the user.
*/
void drink::setType(string s) {
    type = s;
}

/*
    This method returns the ounces of the drink.
*/
float drink::getOunces() {
    return ounces;
}

/*
    This method returns the type of the drink.
*/
string drink::getType() {
    return type;
}
