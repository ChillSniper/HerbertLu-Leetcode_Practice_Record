#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int szofP = p.size(), szofS = s.size(), differ = 0, num[26] = {0}, NumOfStirng[26] = {0};
        for(int i = 0;i < szofP;i ++) num[p[i] - 'a'] ++;
        for(int i = 0;i < szofS && i < szofP;i ++) NumOfStirng[s[i] - 'a'] ++;
        for(int i = 0;i < 26;i ++) if(num[i] != NumOfStirng[i]) differ ++;
        vector<int> ans;
        if(differ == 0) ans.push_back(0);
        for(int i = 0, j = szofP;i < j && j < szofS;i ++, j ++){
            int x = s[i] - 'a', y = s[j] - 'a';
            int originalx = NumOfStirng[x], originaly = NumOfStirng[y];
            NumOfStirng[x] --; NumOfStirng[y] ++;
            if(originalx != num[x] && NumOfStirng[x] == num[x]) differ --;
            if(originalx == num[x] && NumOfStirng[x] != num[x]) differ ++;
            if(originaly != num[y] && NumOfStirng[y] == num[y]) differ --;
            if(originaly == num[y] && NumOfStirng[y] != num[y]) differ ++;
            if(differ == 0) ans.push_back(i + 1);
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution example;
    string s = "bpaa", p = "aa";
    cout << example.findAnagrams(s, p).size();    
    return 0;
}