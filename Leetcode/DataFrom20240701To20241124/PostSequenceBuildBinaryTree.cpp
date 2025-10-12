#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <stack>
using namespace std;

struct TreeNode{
    char val;
    TreeNode* left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(char v): val(v), left(nullptr), right(nullptr){}
    TreeNode(char v, TreeNode* l, TreeNode* r): val(v), left(l), right(r){}
};

class Solution{
public:
    TreeNode* BuildExp(char* s){
        int len = strlen(s);
        stack<TreeNode*> stk;
        for(int i = 0;i < len;i ++){
            TreeNode* node = new TreeNode(s[i]);
            if(!isalpha(s[i])){
                node->left = stk.top(); stk.pop();
                node->right = stk.top(); stk.pop();
            }
            stk.push(node);
        }
        return stk.top();
    }
    int CalculateExpTree(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val - '0';
        int ansL = CalculateExpTree(root->left);
        int ansR = CalculateExpTree(root->right);
        char ch = root->val;
        switch (ch)
        {
        case '+':
            return ansL + ansR;
            break;
        case '-':
            return ansL - ansR;
            break;
        case '*':
            return ansL * ansR;
            break;
        case '/':
            return ansL / ansR;
            break;
        default:
            break;
        }
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    return 0;
}