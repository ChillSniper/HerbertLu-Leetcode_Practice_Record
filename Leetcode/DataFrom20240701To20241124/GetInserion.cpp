#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> Stored;
        ListNode* Tmp = headA;
        while (Tmp)
        {
            Stored.insert(Tmp);
            Tmp = Tmp->next;
        }
        Tmp = headB;
        while (Tmp)
        {
            if(Stored.count(Tmp)){
                return Tmp;
            }
        }
        return nullptr;
    }
};