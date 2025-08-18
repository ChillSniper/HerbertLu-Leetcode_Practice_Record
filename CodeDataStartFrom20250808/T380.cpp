#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        sz = 0;
    }
    
    bool insert(int val) {
        if(st.count(val)) {
            return false;
        }
        st.insert(val);
        ++ sz;
        return true;
    }
    
    bool remove(int val) {
        if(st.count(val)) {
            st.erase(val);
            -- sz;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int p = rand() % sz;
        
    }
private:
    unordered_set<int> st;
    int sz;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */