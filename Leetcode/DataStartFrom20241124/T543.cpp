#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
    int diameterOfBinaryTree(TreeNode* root) {
        int cur = 0;
        Dfs(root, cur);
        return Max;
    }
private:
    int Dfs(TreeNode* root, int cur){
        if(!root) return cur;
        cur ++;
        int Lf = Dfs(root->left, cur);
        int Ri = Dfs(root->right, cur);
        Max = max(Max, Lf - cur + Ri - cur);
        Max = max(Max, Lf - 1);
        Max = max(Max, Ri - 1);
        return max(Lf, Ri);
    }
    int Max = 0;
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}