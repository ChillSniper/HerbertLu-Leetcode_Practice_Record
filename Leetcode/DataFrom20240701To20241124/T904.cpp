#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int left = 0;
        int MaxLength = 0;
        for(int r = 0;r < fruits.size();r ++){
            cnt[fruits[r]] ++;
            while (cnt.size() > 2)
            {
                auto it = cnt.find(fruits[left]);
                it->second --;
                if(it->second == 0) cnt.erase(it);
                left ++;
            }
            
            MaxLength = max(r - left + 1, MaxLength);
        }
        return MaxLength;
    }
};

int main(){
    vector<int> fruits;
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int N;
    cin >> N;
    for(int i = 0;i < N;i ++){
        int temp;
        cin >> temp;
        fruits.push_back(temp);
    }
    Solution s;
    std::cout << s.totalFruit(fruits);
    return 0;
}