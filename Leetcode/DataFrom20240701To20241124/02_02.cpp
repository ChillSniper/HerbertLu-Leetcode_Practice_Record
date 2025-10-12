#include <bits/stdc++.h>
using namespace std;
#define Test

  //Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode *f, *s;
        f = s = head;
        
    }
};

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    Solution s;
    ListNode* head = new ListNode(0);
    int AllNumber;
    scanf("%d", &AllNumber);
    ListNode* p = head;
    for(int i = 0;i < AllNumber;i ++){
        int x;
        scanf("%d", &x);
        ListNode* k = new ListNode(x);
        p->next = k;
        p = k;
    }

    // for(ListNode* i = head->next;i;i = i->next){
    //     printf("%d ", i->val);
    // }

    return 0;
}