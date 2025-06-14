#include <bits/stdc++.h>
using namespace std;

  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* PreHead = new ListNode;
        PreHead->next = head;
        ListNode* Pre = PreHead;
        while (Pre->next)
        {
            if(Pre->next->val == val){
                Pre->next = Pre->next->next;
            }else {
                Pre = Pre->next;
            }
        }
        return PreHead->next;
    }
};