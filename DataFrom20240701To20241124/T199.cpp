#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        deque<TreeNode*> st;
        if(!root) return ans;
        st.push_back(root);
        while (!st.empty())
        {
            int Len = st.size();
            TreeNode* node = nullptr;
            while (Len --)
            {
                node = st.front();
                st.pop_front();
                if(node->left) st.push_back(node->left);
                if(node->right) st.push_back(node->right);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};