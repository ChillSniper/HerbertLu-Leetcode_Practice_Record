#include <iostream>
#include <cstdio>
#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        Dfs(root, targetSum);
        return ans;
    }
private:
    void Dfs(TreeNode* p, int targetSum){
        if(!p) return ;
        tmp.push_back(p->val);
        if(!p->left && !p->right && p->val == targetSum)
            ans.push_back(tmp);
        Dfs(p->left, targetSum - p->val);
        Dfs(p->right, targetSum - p->val);
        tmp.pop_back();
    }
    vector<int> tmp;
    vector<vector<int>> ans;
};