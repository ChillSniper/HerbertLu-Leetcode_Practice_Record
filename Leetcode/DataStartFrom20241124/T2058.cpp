#include <iostream>
#include <cstdio>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* LastNode, *cur;
        int LastPostion, FirstPostion, CurPosition;
        LastNode = nullptr;
        LastPostion = FirstPostion = CurPosition = 0;
        cur = head;
        int minDistance = 0x3f3f3f3f, MaxDistance = -1;
        while (cur)
        {
            CurPosition ++;
            if(LastNode && cur->next && (cur->val > LastNode->val && cur->val > cur->next->val || cur->val < LastNode->val && cur->val < cur->next->val)){
                if(FirstPostion){
                    MaxDistance = CurPosition - FirstPostion;
                    minDistance = min(minDistance, CurPosition - LastPostion);
                } else{
                    FirstPostion = CurPosition;
                }
                LastPostion = CurPosition;
            }
            LastNode = cur;
            cur = cur->next;
        }
        minDistance = minDistance != 0x3f3f3f3f ? minDistance : -1;
        return {minDistance, MaxDistance};
    }
};