#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
//#define IterateWayOfMyself
#define IterateWayBetter
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef IterateWayBetter
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        stack<TreeNode*> st;
        while (cur || !st.empty())
        {
            if(cur){
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if(pre && pre->val >= cur->val) return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};
#endif

#ifdef IterateWayOfMyself
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* p = root;
        vector<int> arr;
        stack<TreeNode*> st;
        while (p || !st.empty())
        {
            if(p){
                st.push(p);
                p = p->left;
            } else{
                p = st.top();
                st.pop();
                arr.push_back(p->val);
                p = p->right;
            }
        }
        for(int i = 0;i < arr.size() - 1;i ++){
            if(arr[i + 1] <= arr[i]) return false;
        }
        return true;
    }
};
#endif