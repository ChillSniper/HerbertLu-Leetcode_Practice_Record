#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#define NonRecursive
//#define Recursive
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

#ifdef Recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        if(root->left) preorderTraversal(root->left);
        if(root->right) preorderTraversal(root->right);
        return ans;
    }
private:
    vector<int> ans;
};
#endif

#ifdef NonRecursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        if(p) st.push(p);
        while (!st.empty())
        {
            p = st.top(); st.pop();
            if(p){
                if(p->right) st.push(p->right);
                if(p->left) st.push(p->left);
                st.push(p);
                st.push(nullptr);
            } else {
                p = st.top(); st.pop();
                ans.push_back(p->val);
            }
        }
        return ans;
    }
private:
    vector<int> ans;
};
#endif

int main(){

    return 0;
}