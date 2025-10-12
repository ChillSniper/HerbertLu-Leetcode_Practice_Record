#include <iostream>
#include <cstdio>
using namespace std;
//#define RecursiveWay
#define IterateWay
#include <deque>

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#ifdef IterateWay
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        deque<TreeNode*> dq;
        dq.push_back(root1); dq.push_back(root2);
        while (!dq.empty())
        {
            TreeNode* p1 = dq.front(); dq.pop_front();
            TreeNode* p2 = dq.front(); dq.pop_front();
            p1->val += p2->val;
            if(p1->left && p2->left){
                dq.push_back(p1->left);
                dq.push_back(p2->left);
            }
            if(p1->right && p2->right){
                dq.push_back(p1->right);
                dq.push_back(p2->right);
            }
            if(!p1->left && p2->left) p1->left = p2->left;
            if(!p1->right && p2->right) p1->right = p2->right;
        }
        return root1;
    }
};
#endif 

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
#endif