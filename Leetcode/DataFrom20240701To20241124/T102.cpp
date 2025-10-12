#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

//  Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        if(root) dq.push_back(root);
        int Currentnum = 1;
        int NextNum = 0;
        while (!dq.empty())
        {
            vector<int> CurLevel;
            NextNum = 0;
            while (Currentnum --)
            {
                TreeNode* p = dq.front();
                dq.pop_front();
                CurLevel.push_back(p->val);
                if(p->left){dq.push_back(p->left); NextNum ++;}
                if(p->right){dq.push_back(p->right); NextNum ++;}
            }
            ans.push_back(CurLevel);
            Currentnum = NextNum;
        }
        return ans;
    }
private:
    vector<vector<int>> ans;
};