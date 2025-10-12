#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr(26);
        for(int i = 0;i < magazine.size();i ++){
            arr[magazine[i] - 'a'] ++;
        }
        for(int i = 0;i < ransomNote.size();i ++){
            arr[ransomNote[i] - 'a'] --;
        }
        for(int i = 0;i < 26;i ++){
            if(arr[i] < 0) return false;
        }
        return true;
    }
};