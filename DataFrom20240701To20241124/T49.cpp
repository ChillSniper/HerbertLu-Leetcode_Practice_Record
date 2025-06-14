#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string& str: strs){
            string Temp = str;
            sort(Temp.begin(), Temp.end());
            mp[Temp].emplace_back(str);
        }
        vector<vector<string>> result;
        for(const auto& pair: mp){
            result.emplace_back(pair.second);
        }
        return result;
    }
};