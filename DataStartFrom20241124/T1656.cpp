#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        ptr = 1;
        for(int i = 0;i <= n;i ++) store.push_back("");
    }
    
    vector<string> insert(int idKey, string value) {
        store[idKey] = value;
        vector<string> ans;
        while(store[ptr] != ""){
            ans.push_back(store[ptr ++]);
        }
        return ans;
    }
private:
    int ptr;
    vector<string> store;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */