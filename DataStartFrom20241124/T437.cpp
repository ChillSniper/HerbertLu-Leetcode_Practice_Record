#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

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
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        unordered_map<long long, int> ump;
        ump[0] = 1;
        Dfs(root, 0, targetSum, ump);
        return ans;
    }
private:
    int ans;
    void Dfs(TreeNode* root, long long lastSum, int targetSum, unordered_map<long long, int>& ump){
        if(!root) return ;
        long long cur = lastSum + root->val;
        long long find_x = cur - targetSum;
        if(ump.count(find_x)){
            ans += ump[find_x];
        }
        ump[cur] ++;
        Dfs(root->left, cur, targetSum, ump);
        Dfs(root->right, cur, targetSum, ump);
        ump[cur] --;
    }
};