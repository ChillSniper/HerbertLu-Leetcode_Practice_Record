#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define Test

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int sz = s.size();
        for(int i = 0;i < sz;i ++){
            if(!ump.count(s[i]) || i > ump[s[i]])
                ump[s[i]] = i;
        }
        int len = -1, j = ump[s[0]], st = 0;
        vector<int> ans;
        for(int i = 0;i < sz;){
            if(i > j){
                ans.push_back(j - st + 1);
                st = i;
                j = ump[s[i]];
            }
            else{
                j = max(j, ump[s[i]]);
            }
        }
        return ans;
    }
private:
    unordered_map<char,int> ump;
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}