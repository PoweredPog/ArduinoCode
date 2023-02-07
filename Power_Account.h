#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
class power_acc{
    public: 
        double watt_total, daysTotal, price;
    //Calculates(calc) the average wattage in both daily and monthly and eventually
    //will include saved price, only returns a print statment
    string to_string(){
        double avg = watt_total/daysTotal;
        double monthAvg = watt_total/(daysTotal/30);
        string value = 
        ("\n{\n\tTotal: " + convert(watt_total)
        + "\n\tDaily Average: " + convert(avg)
        + "\n\tMonthly Average: " + convert(monthAvg)
        + "\n\tMonthly Average bill $" + formComma(monthAvg*price/1000)
        + "\n}");
        return value;
    }
    //Intakes a value as a double and formates it as a money value, rounded to two digits
    string formComma(double val){
        string concat;
        string valString=string_precision(val,0);
        int tp=0;
        int count = valString.length();
        int cents = (val*100);
        cents = cents%100;
        string centsStr = "."+string_precision(cents,0);
        if(cents==0){
            centsStr="";
        }
        if(cents/10<1){
            centsStr=".0"+string_precision(cents,0);
        }
        int value = val;
        while(value>=1000){
            tp=value%1000;
            value/=1000;
            count-=3;
            concat+=","+valString.substr(count,3);
        }
        return (string_precision(value,0)+concat+centsStr);
    }
    //1 Way conversion into larger Order of Magnitudes(OOMs), only built for print
    //functions does not change initial value 
    string convert(double val){
        string suffix="w";
        if(val/1000000>1){
            val/=1000000;
            val=(int)(val*100+0.5);
            val/=100;
            suffix="mW";
        }else if(val/1000>1){
            val/=1000;
            val=(int)(val*100+.5);
            val/=100;
            suffix="kW";
        }
        return(string_precision(val,2)+suffix);
    }
    //Sets the double parameter the amount of decimals determined by int parameter
    //returns truncated string (Rounding not included in this function)
    string string_precision(double x, int y){
        ostringstream stream;
        stream<<fixed<<setprecision(y)<<x;
        return stream.str();
    }

    
};
