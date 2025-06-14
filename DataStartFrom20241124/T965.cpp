#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>
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
    bool isUnivalTree(TreeNode* root) {
        Dfs(root);
        return record.size() == 1;
    }
    void Dfs(TreeNode* root){
        if(!root) return ;
        if(!record.count(root->val)) record.insert(root->val);
        Dfs(root->left);
        Dfs(root->right);
    }
private:
    unordered_set<int> record;
};