#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define Test

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int sz = wordDict.size();
        for(int i = 0;i < sz;i ++)
            st.insert(wordDict[i]);
        
        int string_sz = s.size();
        string tmp = " " + s;
        vector<int> f(string_sz + 1, 0);
        f[0] = 1;
        for(int i = 1;i <= string_sz;i ++){
            for(int j = 0;j < i;j ++){
                f[i] = f[j] && st.count(tmp.substr(j + 1, i - j));
                if(f[i])
                    break;  
            }
        }
        return f[string_sz];
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<string> word = {"cats","dog","sand","and","cat"};
    string s = "catsandog";
    Solution ex;
    ex.wordBreak(s, word);
    return 0;
}