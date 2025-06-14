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
    ListNode* sortList(ListNode* head) {
        if(!head || head->next == nullptr)
            return head;
        ListNode* PreHead = new ListNode(0, head);
        ListNode* fst = PreHead, *slw = PreHead;
        while (fst && fst->next && slw)
        {
            fst = fst->next->next;
            slw = slw->next;
        }
        ListNode* HeadB = slw->next;
        slw->next = nullptr;
        ListNode* HeadA = sortList(PreHead->next);
        HeadB = sortList(HeadB);
        return MergeList(HeadA, HeadB);
        
    }
private:
    ListNode* MergeList(ListNode* HeadA, ListNode* HeadB){
        ListNode* PreHead = new ListNode(0);
        ListNode* p = PreHead;
        while (HeadA && HeadB)
        {
            if(HeadA->val <= HeadB->val){
                p->next = HeadA;
                p = p->next;
                HeadA = HeadA->next;
            }
            else{
                p->next = HeadB;
                p = p->next;
                HeadB = HeadB->next;
            }
        }
        if(HeadA)
            p->next = HeadA;
        if(HeadB)
            p->next = HeadB;
        return PreHead->next;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> arr = {4, 2, 1, 3};
    ListNode* PreHead = new ListNode();
    ListNode* p = PreHead;
    int sz = arr.size();
    for(int i = 0;i < sz;i ++){
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    Solution s;
    s.sortList(PreHead->next);
    return 0;
}