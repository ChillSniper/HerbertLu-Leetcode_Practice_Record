#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        // yyyy-xx-dd
        int sz = date.size();
        string tmp, ans;
        for(int i = 0;i < sz;i ++){
            if(date[i] == '-'){
                tmp = "";
                ans += "-";
            } else {
                tmp += func(date[i]);
            }
            if(i == 3 || i == 6 || i == 9){
                int j = 0;
                while (tmp[j] == '0')
                {
                    j ++;
                }
                tmp.erase(0, j);
                ans += tmp;
            }
        }
        return ans;
    }
    string func(char x){
        switch (x)
        {
        case '0':
            return "0000";
            break;
        case '1':
            return "0001";
            break;
        case '2':
            return "0010";
            break;
        case '3':
            return "0011";
            break;
        case '4':
            return "0100";
            break;
        case '5':
            return "0101";
            break;
        case '6':
            return "0110";
            break;
        case '7':
            return "0111";
            break;
        case '8':
            return "1000";
            break;
        case '9':
            return "1001";
            break;
        default:
            break;
        }
        return "";
    }
    
};