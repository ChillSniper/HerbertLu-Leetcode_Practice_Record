#include <iostream>
#include <cstdio>
using namespace std;
#define Test

//  Definition for a binary tree node.
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
    int diameterOfBinaryTree(TreeNode* root) {
        // ��ν����ֱ����������·�����ֵ
        // ������·�����ֵ��ȡ�Ŀ��ǣ�ʵ������ѡȡ������������ + ������������
        // ����ע�⵽���սڵ��ѡȡ����һ���Ǹ��ڵ�
        MaxAns = currentAns = 0;
        Dfs(root);
        return MaxAns;
    }
    int Dfs(TreeNode* p){
        if(!p) return 0;
        int LeftDepth = Dfs(p->left);
        int RightDepth = Dfs(p->right);
        currentAns = LeftDepth + RightDepth;
        MaxAns = max(MaxAns, currentAns);
        return 1 + max(LeftDepth, RightDepth);
    }
private:
    int MaxAns = 0, currentAns;
};
int main(){
    return 0;
}