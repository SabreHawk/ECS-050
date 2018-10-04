#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cassert>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

struct pos{
    int x;
    int y;
    int x2;
};
int get_index(int,int,int);
pos get_pos(int,int);
int main(int argc,char** argv){
    vector<int> nums_a;
    vector<int> nums_b;
    ifstream infile; 
    infile.open(string(argv[1]).data()); 
    string s;
    while(getline(infile,s))
    {
        int tmp_int = 0;
        stringstream stream(s);  
        stream>>tmp_int;  
        nums_a.push_back(tmp_int);
    }
    infile.close(); 
    infile.open(string(argv[2]).data()); 
    while(getline(infile,s))
    {
        int tmp_int = 0;
        stringstream stream(s);  
        stream>>tmp_int;  
        nums_b.push_back(tmp_int);
    }
    infile.close(); 

    int N = nums_a[0];
    for(int i = 0 ;i < (1+N)*N/2;++ i){
        pos tmp_pos = get_pos(i,N);
        int Rij = 0;
        for(int k = tmp_pos.y;k < tmp_pos.y+tmp_pos.x2;++k ){
            Rij += nums_a[get_index(tmp_pos.y,k,N)]*nums_b[get_index(k,tmp_pos.x,N)];
        }
        cout << Rij << " ";
    }
}

int get_index(int _i,int _j,int _n){
    int tmp_index = 0;
    int tmp_n = _n;
    for(int i = 0;i < _i;++i){
        tmp_index += tmp_n--;
    }
    return tmp_index + _j - _i + 1;
}

pos get_pos(int _index,int _N){
    ++ _index;
    int y= 0;
    while(_index > _N){
        _index -= _N--;
        ++ y;
    }
    pos tmp;
    tmp.x = _index + y-1;
    tmp.y = y;
    tmp.x2 = _index;
    return tmp;
}

// pos get_pos(int,int);
// int main(int argc,char** argv){
//     vector<int> nums_a;
//     vector<int> nums_b;
//     string tmp_path = "";
//     string file1 = string(argv[1]);
//     string file2 = string(argv[2]);
//     ifstream infile; 
//     infile.open(file1.data()); 
//     string s;
//     while(getline(infile,s))
//     {
//         int tmp_int = 0;
//         stringstream stream(s);  
//         stream>>tmp_int;  
//         nums_a.push_back(tmp_int);
//     }
//     infile.close(); 
//     infile.open(file2.data()); 
//     while(getline(infile,s))
//     {
//         int tmp_int = 0;
//         stringstream stream(s);  
//         stream>>tmp_int;  
//         nums_b.push_back(tmp_int);
//     }
//     infile.close(); 
//     int N = nums_a[0];
//     for(int i = 0;i < N;++ i){
//         pos tmp_pos = get_pos(i,N);
//         int offset_on = N-tmp_pos.y+1;
//         int multi_num = tmp_pos.x;
//         int tmp_start_x = 1;
//         int tmp_n = N;
//         for(int ii = 0;ii < tmp_pos.y-1;++ ii){
//             tmp_start_x += tmp_n--;
//         }
//         int tmp_start_t_index = i;
//         int tmp_count = N - tmp_pos.y + 1;
//         while(tmp_start_t_index > N){
//             tmp_start_t_index -= tmp_count++;
//         }
//         int tmp_count = N-i;
//         for(int n =0;n < multi_num;++ n){
//             tmp_value += nums_a[tmp_start_x+n] * nums_b[tmp_start_t_index+];
//         }
//     }

// }

