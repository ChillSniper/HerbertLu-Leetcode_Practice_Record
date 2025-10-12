#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz = nums.size();
        return Dfs(nums, 0, sz - 1);
    }
private:
    TreeNode* Dfs(vector<int>& Num, int l, int r){
        if(l > r) return nullptr;
        if(l == r){
            TreeNode* p = new TreeNode(Num[l]);
            return p;
        }
        int mid = l + (r - l) / 2;
        TreeNode* p = new TreeNode(Num[mid]);
        p->left = Dfs(Num, l, mid - 1);
        p->right = Dfs(Num, mid + 1, r);
        return p;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}