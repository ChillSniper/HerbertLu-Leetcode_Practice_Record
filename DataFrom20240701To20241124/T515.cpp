#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty())
        {
            int size = dq.size();
            int MaxNum = dq.front()->val;
            while (size --)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                MaxNum = max(MaxNum, node->val);
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
            }
            ans.push_back(MaxNum);
        }
        return ans;
    }
};