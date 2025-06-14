#include <bits/stdc++.h>
using namespace std;
#define Test

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
    ListNode* middleNode(ListNode* head) {
        ListNode* N(head);
        ListNode* f, *s;
        f = s = N;
        while (f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
};

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    ListNode* head = new ListNode();
    int n;
    scanf("%d", &n);
    return 0;
}