#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

const int N = 30;

struct Node{
    int val;
    Node* nxt[N];
    Node(): val(0){
        for(int i = 0;i < N;i ++)
            nxt[i] = nullptr;
    }
    Node(int x): val(x){
        for(int i = 0;i < N;i ++)
            nxt[i] = nullptr;
    }
};

class Trie {
public:
    Trie() {
        trie = new Node();
    }
    
    void insert(string word) {
        int sz = word.size();
        Node* p = trie;
        for(int i = 0;i < sz;i ++){
            int x = word[i] - 'a';
            if(!p->nxt[x])
                p->nxt[x] = new Node(1);
            p = p->nxt[x];
        }
        p->val = 2;
    }
    
    bool search(string word) {
        int sz = word.size();
        Node* p = trie;
        for(int i = 0;i < sz;i ++){
            int x = word[i] - 'a';
            if(!p->nxt[x] || p->nxt[x]->val == 0)
                return false;
            p = p->nxt[x];
        }
        return p->val == 2;
    }
    
    bool startsWith(string prefix) {
        int sz = prefix.size();
        Node* p = trie;
        for(int i = 0;i < sz;i ++){
            int x = prefix[i] - 'a';
            if(!p->nxt[x] || p->nxt[x]->val == 0)
                return false;
            p = p->nxt[x];
        }
        return true;
    }

private:
    Node* trie;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}