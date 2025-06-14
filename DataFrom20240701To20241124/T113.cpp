#include <iostream>
#include <cstdio>
#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        vector<int> tmp;
        if(!root) return {};
        DFS(root, tmp, targetSum);
        return ans;
    }
    void DFS(TreeNode* p, vector<int>& tmp, int current){
        if(!p) return;
        tmp.push_back(p->val);
        if(!p->left && !p->right && current == p->val){
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        if(p->left){ DFS(p->left, tmp, current - p->val);}
        if(p->right) {DFS(p->right, tmp, current - p->val);}
        tmp.pop_back();
    }
private:
    vector<vector<int>> ans;
    int target;
};