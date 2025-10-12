#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
//#define BFSWay
#define DFSWay
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#ifdef DFSWay
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        DFS(0, root);
        return result;
    }
    void DFS(int depth, TreeNode* p){
        if(!p) return;
        if(!p->left && !p->right && depth > MaxDepth){
            result = p->val;
            MaxDepth = depth;
        }
        if(p->left) DFS(depth + 1, p->left);
        if(p->right) DFS(depth + 1, p->right);
    }
private:
    int MaxDepth = -1;
    int result = 0;
};
#endif
#ifdef BFSWay
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        deque<TreeNode*> dq;
        TreeNode* p = root;
        TreeNode* ans;
        dq.push_back(p);
        while (!dq.empty())
        {
            ans = dq.front();
            int size = dq.size();
            while (size --)
            {
                p = dq.front(); dq.pop_front();
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
        }
        return ans->val;
    }
};
#endif