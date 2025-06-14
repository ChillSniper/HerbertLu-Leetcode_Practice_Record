#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test
// #define MyWay
#define DivideConqueror
#define PriorityQueue

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    #ifdef DivideConqueror
    ListNode* mergeKLists(vector<ListNode*>& lists){
        int sz = lists.size();
        return MergeK(lists, 0, sz - 1);
    }
    ListNode* MergeK(vector<ListNode*>& Lists, int l, int r){
        if(l > r) return nullptr;
        if(l == r) return Lists[l];
        int mid = l + (r - l) / 2;
        return MergeTwoList(MergeK(Lists, l, mid), MergeK(Lists, mid + 1, r));
    }
    #endif
    #ifdef MyWay
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        if(sz == 0) return nullptr;
        if(sz == 1) return lists[0];
        vector<ListNode*> Ans;
        for(int i = 0;i < sz;){
            if(i + 1 < sz){
                ListNode* result = MergeTwoList(lists[i], lists[i + 1]);
                i += 2;
                Ans.push_back(result);
            } else{
                Ans.push_back(lists[i]);
                ++ i;
            }
        }
        return mergeKLists(Ans);
    }
    #endif
private:
    ListNode* MergeTwoList(ListNode* HeadA, ListNode* HeadB){
        ListNode* PreHead = new ListNode();
        ListNode* p = PreHead;
        while (HeadA && HeadB)
        {
            if(HeadA->val <= HeadB->val){
                p->next = HeadA;
                HeadA = HeadA->next;
                p = p->next;
            } else{
                p->next = HeadB;
                HeadB = HeadB->next;
                p = p->next;
            }
        }
        if(HeadA) p->next = HeadA;
        if(HeadB) p->next = HeadB;
        return PreHead->next;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}