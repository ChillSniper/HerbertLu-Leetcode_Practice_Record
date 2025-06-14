#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;
#define Test

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int sz = foods.size();
        for(int i = 0;i < sz;i ++){
            string& food = foods[i], &cursine = cuisines[i];
            int val = ratings[i];
            CursineForRate[cursine].insert(pair(-val, food));
            FoodToCursine[food] = make_pair(val, cursine);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [_original_val, cuisine] = FoodToCursine[food];
        CursineForRate[cuisine].erase(pair(-_original_val, food));
        CursineForRate[cuisine].insert(pair(-newRating, food));
        FoodToCursine[food] = make_pair(newRating, cuisine);
    }
    
    string highestRated(string cuisine) {
        return CursineForRate[cuisine].begin()->second;
    }
private:
    unordered_map<string, set<pair<int, string>>> CursineForRate;
    unordered_map<string, pair<int, string>> FoodToCursine;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}