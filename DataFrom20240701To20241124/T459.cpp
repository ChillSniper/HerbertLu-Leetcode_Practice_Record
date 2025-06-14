#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
#define Test
//#define Way1
//#define Way2
#define Review

class Solution {
public:
    #ifdef Review
    bool repeatedSubstringPattern(string s) {
        const int N = 1e4 + 10;
        int next[N], len = s.length();
        next[0] = -1;
        for(int i = 0;i < len;i ++){
            int k = next[i];
            while (k >= 0 && s[i] != s[k])
            {
                k = next[k];
            }
            next[i + 1] = ++k;
        }
        if(len % (len - next[len - 1]) == 0 && next[len - 1]) return true;
        else return false;
    }
    #endif
    #ifdef Way1
    bool repeatedSubstringPattern(string s) {
        #ifdef Way1
        return ((s + s).find(s, 1) != s.size()) ? true : false;
        #endif
        vector<int> Next(s.size());
        GetNext(&Next[0], s);
        
    }
    #endif
private:
    #ifdef Way2
    void GetNext( int* Next, string& str){
        int j = -1;
        Next[0] = j;
        for(int i = 1;i < str.size();i ++){
            while (j >= 0 && str[i] != str[j + 1])
            {  
                j = Next[j];
            }
            if(str[i] == str[j + 1]){
                j ++;
            }
            Next[i] = j;
        }
    }
    #endif
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    s.repeatedSubstringPattern("abab");
    return 0;
}