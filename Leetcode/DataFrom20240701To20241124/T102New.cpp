#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        if(!root) return {};
        vector<vector<int>> ans;
        dq.push_back(root);
        while (!dq.empty())
        {
            vector<int> tmp;
            int Len = dq.size();
            while (Len --)
            {
                TreeNode* p = dq.front(); dq.pop_front();
                tmp.push_back(p->val);
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};