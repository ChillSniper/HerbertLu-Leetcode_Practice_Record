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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fst = head, *slw = head;
        while (fst && slw)
        {
            if(fst->next) fst = fst->next->next;
            else fst = fst->next;
            slw = slw->next;
            if(fst == slw && fst) break;
        }
        if(!fst) return nullptr;
        fst = head;
        while (fst != slw)
        {
            fst = fst->next;
            slw = slw->next;
        }
        return fst;
    }
};

int main(){

    return 0;
}