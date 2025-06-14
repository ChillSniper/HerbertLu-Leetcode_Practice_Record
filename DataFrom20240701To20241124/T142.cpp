#include <bits/stdc++.h>
using namespace std;
//#define Way1
#define Way2
  struct Node {
      int val;
      Node *next;
      Node(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    Node *detectCycle(Node *head) {
        Node *f = head, *s = head;
        while(f && f->next){
            f = f->next->next;
            s = s->next;
            if(f == s){
                f = head;
                for(;f != s;f = f->next, s = s->next);
                if(f == s)  return f;
            }
        }
        return nullptr;
    }
};