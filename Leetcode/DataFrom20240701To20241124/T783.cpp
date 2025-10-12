#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
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
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty())
        {
            if(p){
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                arr.push_back(p->val);
                p = p->right;
            }
        }
        int MinNum = 0x3f3f3f3f;
        for(int i = 0;i < arr.size() - 1;i ++){
            arr[i] = abs(arr[i + 1] - arr[i]);
            MinNum = min(MinNum, arr[i]);
        }
        return MinNum;
    }
};