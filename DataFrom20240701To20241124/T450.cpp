#include <iostream>
#include <cstdio>
//#define RecursiveWay
#define IterateWay
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#ifdef IterateWay
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* p = root, *pre = nullptr;
        //  д����ô����뻹��û���׸�����ָ������ú�ʵ������ ʵ���ϣ�ǰһ��ָ��ָ�����ָ�루������ṹ��ĵ�ַ��
        // ���ǣ�����ṹ������û�ˣ������һ���µ�ֵ�����ܻ���ͬ���ͣ�
        while (p)
        {
            if(p->val == key){
                if(!p->left && !p->right){ delete p; p = nullptr;}
                else if(p->left && !p->right){ TreeNode* tmp = p->left; delete p; p = tmp;}
                else if(!p->left && p->right){ TreeNode* tmp = p->right; delete p; p = tmp;}
                else if(p->left && p->right){
                    TreeNode* tmp = p->left;
                    while (tmp->right)
                    {
                        tmp = tmp->right;
                    }
                    tmp->right = p->right;
                    tmp = p->left;
                    delete p;
                    p = tmp;
                }
                if(pre){
                    if(pre->val > key) pre->left = p;
                    else pre->right = p;
                } else {
                    root = p;
                }
                break;
            } 
            else if(p->val > key) pre = p, p = p->left;
            else if(p->val < key) pre = p, p = p->right;
        }
        return root;
    }
};
#endif

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        if(root->val == key){
            if(!root->left && !root->right){
                root = nullptr;
            } else if(root->left && !root->right){
                root = root->left;
            } else if(!root->left && root->right){
                root = root->right;
            } else{
                TreeNode* p = root->left;
                while (p->right)
                {
                    p = p->right;
                }
                p->right = root->right;
                root->right = nullptr;
                root = root->left;
            }
        }
        return root;
    }
};
#endif

int main(){
    return 0;
}