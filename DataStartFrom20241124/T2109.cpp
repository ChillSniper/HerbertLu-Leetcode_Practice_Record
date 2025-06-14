#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
#define Test
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_set<int> st;
        int sz_space = spaces.size();
        for(int i = 0;i < sz_space;i ++)
            st.insert(spaces[i]);
        
        string ans;
        int sz_s = s.size();
        for(int i = 0;i < sz_s;i ++){
            if(st.count(i))
                ans += " ";
            
            ans += s[i];
        }
        return ans;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}