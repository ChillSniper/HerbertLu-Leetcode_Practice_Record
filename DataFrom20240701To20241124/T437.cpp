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
        // ����dfs��Ȼ����ȡ��ʱ�临�ӶȴﵽO(n^2)
        // ��������Ϊǰ׺��
        // �����������ڽڵ��ǰ׺�͵��ױ������ʲô���⣬��Ҳ�Ǳ�����ѵ�����
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