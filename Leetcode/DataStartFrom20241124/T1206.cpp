#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define Test

const int MaxLevel = 32;
const int P_Random = 0.5;

struct SkipNode
{
    int val;
    vector<SkipNode*> Nxt;
    SkipNode(int __val, int __level = MaxLevel): 
    // 注意此处 __level数值应当直接赋值为MaxLevel!,这样统一了指针的高度，避免溢出！
    val(__val), Nxt(__level, nullptr){}
};

class Skiplist {
private:
    int level;
    SkipNode* Head;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
public:
    Skiplist(): level(0), Head(new SkipNode(-1)), dis(0, 1){
        
    }
    
    bool search(int target) {
        SkipNode* p = Head;
        for(int i = level - 1;i >= 0;i --){
            while (p->Nxt[i] && p->Nxt[i]->val < target)
            {
                p = p->Nxt[i];
            }
        }
        p = p->Nxt[0];
        if(p && p->val == target) return true;
        return false;   
    }
    
    void add(int num) {
        vector<SkipNode*> update(MaxLevel, Head);
        SkipNode* p = Head;
        for(int i = level - 1;i >= 0;i --){
            while (p->Nxt[i] && p->Nxt[i]->val < num)
            {
                p = p->Nxt[i];
            }
            update[i] = p;
        }
        
        int lv = GetLevel();
        level = max(level, lv);
        SkipNode* NewNode =  new SkipNode(num);
        for(int i = lv - 1;i >= 0;i --){
            // update[i]->Nxt[i] = NewNode->Nxt[i];
            // 就是这行该死的代码，一开始指反了，然后调试了好久...
            NewNode->Nxt[i] = update[i]->Nxt[i];
            update[i]->Nxt[i] = NewNode;
        }
    }
    
    bool erase(int num) {
        vector<SkipNode*> update(MaxLevel, Head);
        SkipNode* p = Head;
        for(int i = level - 1;i >= 0;i --){
            while (p->Nxt[i] && p->Nxt[i]->val < num)
            {
                p = p->Nxt[i];
            }
            update[i] = p;
        }
        p = p->Nxt[0];
        if((p && p->val > num) || !p) return false;
        for(int i = level - 1;i >= 0;i --){
            update[i]->Nxt[i] = p->Nxt[i];
        }
        delete p;
        p = nullptr;
        return true;
    }

    int GetLevel(){
        int lv = 1;
        while (lv < MaxLevel && dis(gen) < P_Random)
        {
            lv ++;
        }
        return lv;
    }

};
    
/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}