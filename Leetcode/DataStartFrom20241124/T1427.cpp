#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#define Test

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        store.push_back(homepage);
        index = 0;
        SizeOfSt = store.size();
    }
    
    void visit(string url) {
        index ++;
        int sz = store.size();
        if(index >= sz){
            store.push_back(url);
            sz = store.size();
            SizeOfSt = sz;
        } else{
            store[index] = url;
            SizeOfSt = index + 1;
        }
    }
    
    string back(int steps) {
        while (steps > 0)
        {
            steps --;
            index --;
        }
        index = index >= 0 ? index : 0;
        // SizeOfSt = index + 1;
        return store[index];
    }
    
    string forward(int steps) {
        while (steps > 0)
        {
            steps --;
            index ++;
        }
        index = index < SizeOfSt ? index : SizeOfSt - 1;
        // SizeOfSt = index + 1;
        return store[index];
    }
private:
    vector<string> store;
    unordered_map<string, int> ump;
    int index, SizeOfSt;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}