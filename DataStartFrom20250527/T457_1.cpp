#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
#define Test

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        // "electronics"¡¢"grocery"¡¢"pharmacy"¡¢"restaurant"
        vector<string> ans_ele, ans_gro, ans_pha, ans_res;
        int sz = code.size();
        for(int i = 0;i < sz;i ++){
            bool flag = IsValid(code[i]);
            if(!flag){
                continue;
            }
            if(isActive[i] == 0){
                continue;
            }
            if(businessLine[i] == "electronics"){
                ans_ele.emplace_back(code[i]);
            }
            else if(businessLine[i] == "grocery"){
                ans_gro.emplace_back(code[i]);
            }
            else if(businessLine[i] == "pharmacy"){
                ans_pha.emplace_back(code[i]);
            }
            else if(businessLine[i] == "restaurant"){
                ans_res.emplace_back(code[i]);
            }
        }
        sort(ans_ele.begin(), ans_ele.end());
        sort(ans_gro.begin(), ans_gro.end());
        sort(ans_pha.begin(), ans_pha.end());
        sort(ans_res.begin(), ans_res.end());
        vector<string> ans;
        for(auto item : ans_ele){
            ans.emplace_back(item);
        }
        for(auto item : ans_gro){
            ans.emplace_back(item);
        }
        for(auto item : ans_pha){
            ans.emplace_back(item);
        }
        for(auto item : ans_res){
            ans.emplace_back(item);
        }
        return ans;
    }
private:
    bool IsValid(string s){
        int sz = s.size();
        if(sz == 0){
            return false;
        }
        for(auto item : s){
            if(!((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z') || (item >= '0' && item <= '9') || item == '_')){
                return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}