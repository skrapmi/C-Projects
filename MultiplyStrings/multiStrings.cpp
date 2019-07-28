#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) { 
        if(num1 == "0" || num2 == "0")
            return "0";
        int min_length, max_length;
        if(num1.length() < num2.length()){
            string temp = num2;
            num2 = num1;
            num1 = temp;         
        }    
        cout << num1 << " " << num2 << " Mult function" << endl;
        max_length = num1.length() - 1;
        min_length = num2.length() - 1;
        string newNum = "";
        int yzero = 0;
        int xzero = 0;
        for(int y = min_length ; y >= 0; y--, yzero++){
            for(int x = max_length; x >= 0; x--, xzero++){
                int newTotal = multiTwo( int(num1.at(x)) - 48 , int(num2.at(y)) - 48 );
                newNum = addStrings(newTotal, xzero, newNum, yzero);
                
            }
        }
        return newNum;
    }
    
    int multiTwo(int num1, int num2){
        cout << num1 << " " << num2 << " Two Function" << endl;
        return int(num1) * int(num2);    
    }
    
    string addStrings(int newTotal, int xzero, string num1, int yzero){
        cout << "newTotal = " << newTotal << endl;
        cout << "xzero = " << xzero << endl;
        cout << "num1 = " << num1 << endl;
        cout << "yzero = " << yzero << endl;
        string num2 = "";
        num2.insert(num2.end(), yzero, '0');
        cout << "num2 = " << num2 << endl;
        num2.insert(0, to_string(newTotal));
        cout << "num2 = " << num2 << endl << endl;
        if(num2.length() > num1.length()){
            string temp = num1;
            num1 = num2;
            num2 = temp;         
        }
        
        
        
        
        return num1; //newTotal;
    }
    
};

int main(){
    
    Solution ans;
    cout << ans.multiply("10","3");
    cout << " done\n";
    return 0;
}