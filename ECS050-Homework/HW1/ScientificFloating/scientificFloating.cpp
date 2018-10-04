#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> digits;
    float f;
    cout << "Please enter a float: ";
    cin >> f;
    if(f==0){
        cout << "0E0";
        return 0;
    }
    unsigned int float_int = *((unsigned int*)&f);
    // cout << float_int << endl;
    while(float_int>0){
        digits.push_back(float_int%2);
        float_int/=2;
    }
    // cout << digits.size()<<endl;
    for(int i = digits.size();i<32;++i){
        digits.push_back(0);
    }
    reverse(digits.begin(),digits.end());
    // for(auto digit:digits){
    //     cout << digit;
    // }cout << endl;
    int exponent = 0;
    for(int i =1;i < 9;++ i){
        exponent += digits[i] * pow(2,8-i);
    }
    exponent -= 127;
    // cout << exponent << endl;
    int end_index = digits.size()-1;
    for(int i = end_index;i >=0;--i){
        if (digits[i]==1){
            end_index = i;
            break;
        }
    }
    if (f<0){
        cout << '-';
    }
    cout << 1;
    if(end_index>=9){
        cout << '.';
    }
    for(int i = 9;i <= end_index;++ i){
        cout << digits[i];
    }
    cout << "E" << exponent;
}