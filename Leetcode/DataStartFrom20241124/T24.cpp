#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* Pre = new ListNode(0, head);
        ListNode* fst = Pre, *slw = Pre;
        while (fst && slw)
        {
            if(!fst->next || !fst->next->next)
                break;
            ListNode* PreTmp = fst;
            ListNode* LstTmp = fst->next->next->next;
            fst = fst->next->next;
            slw = slw->next;
            PreTmp->next = fst;
            fst->next = slw;
            slw->next = LstTmp;
            fst = fst->next;
        }
        return Pre->next;
    }
};

int main(){
    return 0;
}