#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length() < p.length()) return ans;
        const int N = 26;
        vector<int> Tarr(N);
        int DifferentNum = 0;
        for(int i = 0;i < p.length();i ++){
            Tarr[p[i] - 'a']--;
            Tarr[s[i] - 'a']++;
        }
        for(int i = 0;i < N;i ++){
            if(Tarr[i]) DifferentNum ++;
        }
        if(!DifferentNum) ans.emplace_back(0);
        for(int i = 0;i < s.length() - p.length();i ++){
            if(Tarr[s[i] - 'a'] == 1) DifferentNum --;
            if(Tarr[s[i] - 'a'] == 0) DifferentNum ++;
            -- Tarr[s[i] - 'a'];
            if(Tarr[s[i + p.length()]- 'a'] == 0) DifferentNum ++;
            if(Tarr[s[i + p.length()] - 'a'] == -1) DifferentNum --;
            ++ Tarr[s[i] + p.length() - 'a'];
            if(!DifferentNum) ans.emplace_back(i + 1);
        }
        return ans;
    }   
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    string str1, str2;
    Solution s;
    cin >> str1 >> str2;
    vector<int> ans = s.findAnagrams(str1, str2);
    for(auto i : ans) printf("%d ", i);
    return 0;
}