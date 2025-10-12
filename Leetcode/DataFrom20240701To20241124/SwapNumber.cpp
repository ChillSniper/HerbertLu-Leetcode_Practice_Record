#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#define Test
using namespace std;

void SwapNumber(string& str);

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string str;
    cin >> str;
    SwapNumber(str);
    return 0;
}

void SwapNumber(string& str){
    for(int i = 0;i < str.length();i ++){
        if(!isalpha(str[i])){
            printf("number");
        } else {
            printf("%c", str[i]);
        }
    }
}