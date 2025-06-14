#include <bits/stdc++.h>
using namespace std;
//#define Way1
#define Way2

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    #ifdef Way1
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Cur = head;
        int cnt = 0;
        while (Cur)
        {
            cnt ++;
            Cur = Cur->next;
        }
        n = cnt - n;
        ListNode* Prehead = new ListNode();
        Prehead->next = head;
        Cur = head;
        ListNode* Pre = Prehead;
        while (n >= 1)
        {
            Pre = Pre->next;
            Cur = Cur->next;
            n --;
        }
        Pre->next = Cur->next;
        return Prehead->next;
    }
    #endif

    #ifdef Way2
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Prehead = new ListNode(0, head);
        ListNode* FastNode = Prehead;
        ListNode* SlowNode = Prehead;
        while (n --)
        {
            FastNode = FastNode->next;
        }
        while (FastNode->next)
        {
            FastNode = FastNode->next;
            SlowNode = SlowNode->next;
        }
        SlowNode->next = SlowNode->next->next;
        head = Prehead->next;
        delete Prehead;
        return head;
    }
    #endif
};