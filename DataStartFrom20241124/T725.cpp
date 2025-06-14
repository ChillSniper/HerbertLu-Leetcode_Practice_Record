#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int Len = 0;
        ListNode* cur = head;
        while (cur)
        {
            Len ++;
            cur = cur->next;
        }
        int AveSize = Len / k, BesidesSize = Len - AveSize * k;
        int index = 0;
        vector<ListNode*> ans;
        ListNode* pre = nullptr;
        while (head)
        {
            if(index == 0){
                if(pre) pre->next = nullptr;
                ans.push_back(head);
                BesidesSize --;
            }
            pre = head;
            head = head->next;
            if(BesidesSize >= 0) index = (index + 1) % (1 + AveSize);
            else index = (index + 1) % AveSize;
        }
        int n = ans.size();
        while (n < k)
        {
            ans.push_back(nullptr);
            n ++;
        }
        
        return ans;
    }
};