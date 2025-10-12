#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define Test

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto item : wordDict){
            st.insert(item);
        }
        int s_sz = s.size();
        vector<int> f(s_sz, 0);
        for(int i = 0;i < s_sz;i ++){
            for(int j = -1;j < i;j ++){
                int len = (i - (j + 1)) + 1;
                string tmp = s.substr(j + 1, len);
                if(st.count(tmp)){
                    if(j != -1){
                        f[i] = f[i] | (f[j]);
                    }
                    else{
                        f[i] = 1;
                    }
                }
            }
        }
        return f[s_sz - 1] == 1;
    }
};

int main(){

    return 0;
}