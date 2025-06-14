#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
//#define DfsWay
#define IterateWay
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // TreeNode* currentSum
        stack<pair<TreeNode*, int>> st;
        if(!root) return false;
        st.push({root, root->val});
        while (!st.empty())
        {
            TreeNode* p = st.top().first;
            int currentsum = st.top().second;
            st.pop();
            if(!p->left && !p->right && currentsum == targetSum) return true;
            if(p->right) st.push({p->right, currentsum + p->right->val});
            if(p->left) st.push({p->left, currentsum + p->left->val});
        }
        return false;
    }
};
#endif
#ifdef DfsWay
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        sum += root->val;
        if(!root->left && !root->right){
            if(sum == targetSum) {sum -= root->val; return true;}
            else {sum -= root->val; return false;};
        }
        int res = 0;
        if(hasPathSum(root->left, targetSum)) res ++;
        if(hasPathSum(root->right, targetSum)) res ++;
        sum -= root->val;
        if(res) return true;
        else return false;
    }
private:
    int sum = 0;
};
#endif