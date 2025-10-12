#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
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
    int pathSum(TreeNode* root, int targetSum) {
        // 暴力dfs显然不可取，时间复杂度达到O(n^2)
        // 本题正解为前缀和
        // 但是问题在于节点的前缀和到底保存的是什么玩意，这也是本题的难点所在
        mp[0] = 1;
        return Dfs(root, targetSum, 0);
    }
private:
    int Dfs(TreeNode* p, int TargetSum, long long curSum){
        if(!p) return 0;
        curSum += p->val;
        mp[curSum] ++;
        int res = 0;
        if(mp.count(curSum - TargetSum))
            res += mp[curSum - TargetSum];
        res += Dfs(p->left, TargetSum, curSum);
        res += Dfs(p->right, TargetSum, curSum);
        mp[curSum] --;
        return res;
    }
    unordered_map<long long, int> mp;
};

int main(){
    return 0;
}