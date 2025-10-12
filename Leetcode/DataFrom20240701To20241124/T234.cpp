#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* HalfOfList = GetHalf(head);
        ListNode* Lst = ReverseList(HalfOfList->next);
        ListNode* Fro = head;
        bool Flag = true;
        while (Fro && Lst)
        {
            if(Fro->val != Lst->val){
                Flag = false;
                break;
            }
            Fro = Fro->next;
            Lst = Lst->next;
        }
        ReverseList(HalfOfList->next);
        return Flag;
    }
    ListNode* ReverseList(ListNode* head){
        ListNode* Lst = nullptr;
        ListNode* Cur = head;
        while (Cur)
        {
            ListNode* tmp = Cur->next;
            Cur->next = Lst;
            Lst = Cur;
            Cur = tmp;
        }
        return Lst;
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
};