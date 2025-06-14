#include <bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int L1 = 0, L2 = 0;
        for(ListNode* p = headA;p;p = p->next) L1 ++;
        for(ListNode* p = headB;p;p = p->next) L2 ++;
        ListNode* pa = headA, *pb = headB;
        if(L1 > L2){
            for(int i = 0;i < L1 - L2;i ++) pa = pa->next;
        } else if(L2 > L1){
            for(int i = 0;i < L2 - L1;i ++) pb = pb->next;
        }
        for(int i = 0;i < min(L1, L2);i ++){
            if(pa == pb) return pa;
            else pa = pa->next, pb = pb->next;
        }
        return nullptr;
    }
};