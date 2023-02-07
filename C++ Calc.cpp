#include <iostream>
#include <iomanip>
#include <sstream>
#include "Power_Account.h"
//removes the use of "std::" to increase readablity 
using namespace std;

//Sets the double parameter the amount of decimals determined by int parameter
//returns truncated string (Rounding not included in this function)
string string_precision(double x, int y){
    ostringstream stream;
    stream<<fixed<<setprecision(y)<<x;
    return stream.str();
}
int main(){
    double pvTot,dayRange,priceKwh; 
    string acc;
    cout << "Enter account name: \n";
    cin >> acc;
    power_acc alpha;
    cout << "Please enter Total Energy in Watts, the amount of days, and the price per Kwh: \n";
    cin >> alpha.watt_total;
    cin >> alpha.daysTotal;
    cin >> alpha.price;
    cout << alpha.to_string();
}
