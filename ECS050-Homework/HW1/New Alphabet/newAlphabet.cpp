#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int tmp_num = 0;
int tmp2 = 67108864;
int tmp3 = 67108863;
string tmp_answer = "";

void get_string(int);
int main(int argc,char** argv) {
    for (int i = 0; i < argc; ++i)
        get_string(atoi(argv[i]));

    cout << "You entered the word: " << tmp_answer.c_str();
}

void get_string(int _num) {
	int is_cap = 0;
	if ((_num&tmp2) != 0) {
		is_cap = 'A' - 'a';
		_num = (_num&tmp3);
	}

	for (int i = 0; i < 26; ++i) {
		if (_num - pow(2, i) == 0) {
			tmp_answer += (char)('a' + is_cap + i);
		}
	}
}