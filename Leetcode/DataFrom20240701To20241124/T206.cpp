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
    ListNode* reverseList(ListNode* head) {
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
};