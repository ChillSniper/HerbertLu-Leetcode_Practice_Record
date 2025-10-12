#include <bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* HalfNode = GetHalf(head);
        ListNode* Lst = ReverseList(HalfNode->next);
        ListNode* Frn = head;
        HalfNode->next = nullptr;
        while (Lst && Frn)
        {
            ListNode* Ftmp = Frn->next;
            ListNode* Ltmp = Lst->next;
            Frn->next = Lst;
            Lst->next = Ftmp;
            Frn = Ftmp;
            Lst = Ltmp;
        }
    }
    ListNode* GetHalf(ListNode* head){
        ListNode* f = head, *s = head;
        while (f && f->next && f->next->next)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
    ListNode* ReverseList(ListNode* head){
        ListNode* Lst = nullptr;
        ListNode* Cur = head;
        while (Cur)
        {
            ListNode* Nex = Cur->next;
            Cur->next = Lst;
            Lst = Cur; Cur = Nex;
        }
        return Lst;
    }
};