#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Test


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int szofa = 0, szofb = 0;
        ListNode* p = headA;
        for(;p;szofa ++, p = p->next) ;
        p = headB;
        for(;p;szofb ++, p = p->next) ;
        ListNode* q = nullptr;
        if(szofa >= szofb){
            p = headA;
            int x = szofa - szofb;
            for(;x > 0;p = p->next, x --) ;
            q = headB;
        } else{
            p = headB;
            int x = szofb - szofa;
            for(;x > 0;p = p->next, x --) ;
            q = headA;
        }
        for(;p && q && p != q; p = p->next, q = q->next) ;
        return p;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}