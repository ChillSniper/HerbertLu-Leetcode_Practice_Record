#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
// Definition for a binary tree node.
//#define RecursiveAlgorithm
#define Non_RecursiveAlgorithm

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#ifdef RecursiveAlgorithm
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }        
        return ans;
    }
private:
    vector<int> ans;
};
#endif

#ifdef Non_RecursiveAlgorithm
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (1)
        {
            while (p)
            {
                ans.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if(s.empty()) return ans;
            p = s.top()->right;
            s.pop();
        }
    }
private:
    vector<int> ans;
};
#endif