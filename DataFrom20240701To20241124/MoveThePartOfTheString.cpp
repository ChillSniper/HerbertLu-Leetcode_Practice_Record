#include <iostream>
#include <string>
#include <algorithm>
#define Test
using namespace std;

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string str;
    int k;
    std::cin >> k;
    getchar();
    getline(cin, str);
    k %= str.length();
    reverse(str.begin(), str.end());
    reverse(str.begin(), str.begin() + k);
    reverse(str.begin() + k, str.end());
    std::cout << str;
    return 0;
}