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
void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}
int main(){
    power_acc alpha;
    cout << "Enter account name: \n";
    cin >> alpha.acc_name;
    cout << "Please enter Total Energy in Watts, the amount of days, and the price per Kwh: \n";
    cin >> alpha.watt_total;
    cin >> alpha.daysTotal;
    cin >> alpha.price;
    clear();
    cout <<alpha.to_string();
}
