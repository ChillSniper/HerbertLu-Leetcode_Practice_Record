#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* PreHead = new ListNode(0, head);
        int dis = 0;
        ListNode* p = PreHead;
        while (p)
        {
            ListNode* q = p;
            dis = 0;
            while (q && dis < k)
            {
                q = q->next;
                dis ++;
            }
            if(dis < k || !q) break;
            else{
                ListNode* tmp = q->next;
                q = p->next;
                int valoflst, valoftmp, valofp, valofq;
                if(p)
                    valofp = p->val;
                if(q)
                    valofq = q->val;
                if(tmp)
                    valoftmp = tmp->val;
                ListNode* lst = Reverse(p, k);
                if(lst)
                    valoflst = lst->val;
                p->next = lst;
                q->next = tmp;
                p = q;
            }
        }
        return PreHead->next;
    }
private:
    ListNode* Reverse(ListNode* pre, int k){
        ListNode* q = pre->next;
        while (k --)
        {
            ListNode* r = nullptr;
            if(q) r = q->next;
            q->next = pre;
            pre = q;
            q = r;
        }
        return pre;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> arr = {1, 2, 3, 4, 5};
    int sz = arr.size();
    ListNode* head = new ListNode(0), *p = head;
    for(int i = 0;i < sz;i ++){
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    Solution s;
    s.reverseKGroup(head->next, 2);
    return 0;
}