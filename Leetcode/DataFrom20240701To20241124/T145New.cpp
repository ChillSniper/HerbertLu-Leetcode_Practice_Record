#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        if(p) st.push(p);
        while (!st.empty())
        {
            p = st.top(); st.pop();
            if(p){
                st.push(p);
                st.push(nullptr);
                if(p->right) st.push(p->right);
                if(p->left) st.push(p->left);
            } else {
                p = st.top(); st.pop();
                ans.push_back(p->val);
            }
        }
        return ans;
    }
private:
    vector<int> ans;
};