#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<char> digits;
    int num_base = 0;
    cout << "Please enter the number's base: ";
    cin >> num_base;
    string in_num = "";
    cout << "Please enter the number: ";
    cin >> in_num;
    int target_base = 0;
    cout << "Please enter the new base: ";
    cin >> target_base;

    int mid_dec = 0;
    int tmp_digit = 0;
    for (int i = in_num.size() - 1; i >= 0; --i) {
        int tmp_num = 0;
        if (in_num[i] >= 'A' && in_num[i] <= 'Z') {
            tmp_num = in_num[i] - 'A' + 10;
        } else {
            tmp_num = in_num[i] - '1' + 1;
        }
        mid_dec += tmp_num * pow(num_base, tmp_digit++);
    }
    // cout << "mid:" << mid_dec << endl;
    while (mid_dec > 0) {
        int tmp_num = mid_dec % target_base;
        if (tmp_num >= 10) {
            digits.push_back('A' + tmp_num - 10);
        } else {
            digits.push_back('1' + tmp_num - 1);
        }
        mid_dec /= target_base;
    }
    reverse(digits.begin(), digits.end());
    cout << in_num << " base " << num_base << " is ";
    for (auto digit : digits) {
        cout << digit;
    }
    cout << " base " << target_base << endl;
}