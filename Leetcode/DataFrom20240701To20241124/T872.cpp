#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        GetLeafSequence(arr1, root1);
        GetLeafSequence(arr2, root2);
        if(arr1.size() != arr2.size()) return false;
        for(int i = 0;i < arr1.size();i ++) 
            if(arr1[i] != arr2[i]) return false;
        return true;
    }
private:
    void GetLeafSequence(vector<int>& arr, TreeNode* root){
        stack<TreeNode*> st;
        if(!root) return ;
        TreeNode* p = root;
        while (p || !st.empty())
        {
            if(p){
                st.push(p);
                p = p->left;
            } else{
                p = st.top(); st.pop();
                if(!p->left && !p->right) arr.push_back(p->val);
                p = p->right;
            }
        }
    }
};
int main(){
    return 0;
}