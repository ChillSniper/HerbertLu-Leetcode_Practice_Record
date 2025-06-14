#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <vector>
#include <stack>
using namespace std;
//#define BruteForceMatching
#define DFS_SequenceMatching
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef DFS_SequenceMatching
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        GetSequence(root, text);
        GetSequence(subRoot, model);
        return KmpMatching();
    }
    void GetSequence(TreeNode* root, vector<int>& arr){
        if(!root){arr.push_back(MaxNum); return;}
        else arr.push_back(root->val);
        GetSequence(root->left, arr);
        GetSequence(root->right, arr);
    }
    bool KmpMatching(){
        int Next[3000] = {0};
        Next[0] = -1;
        const int TextLen = text.size(), ModelLen = model.size();
        for(int i = 0;i < ModelLen;i ++){
            int k = Next[i];
            while (k >= 0 && !TwoNodesEqual(model[i], model[k]))
            {
                k = Next[k];
            }
            Next[i + 1] = ++ k;
        }
        for(int i = 0, j = 0;i < TextLen && j < ModelLen;){
            if(j < 0 || TwoNodesEqual(text[i], model[j])){i ++; j ++;}
            if(j == ModelLen) return true;
            if(!TwoNodesEqual(text[i], model[j])){j = Next[j];}
        }
        return false;
    }
    bool TwoNodesEqual(int a, int b){
        return a == b;
    }
private:
    vector<int> text;
    vector<int> model;
    const int MaxNum = 1e4 + 10;
};
#endif

#ifdef BruteForceMatching
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        deque<TreeNode*> st;
        if(!root && !subRoot) return true;
        st.push_back(root);
        while (!st.empty())
        {
            int size = st.size();
            while (size --)
            {
                TreeNode* p = st.front(); st.pop_front();
                if(CompareTwoTree(p, subRoot)) return true;
                if(p->left) st.push_back(p->left);
                if(p->right) st.push_back(p->right);
            }
        }
        return false;
    }
    bool CompareTwoTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(p && !q || q && !p) return false;
        if(p->val != q->val) return false;
        bool a = CompareTwoTree(p->left, q->left);
        bool b = CompareTwoTree(p->right, q->right);
        return a && b;
    }
};
#endif

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    // TreeNode* test[10] = {0};
    // for(int i = 0;i < 10;i ++){
    //     if(!test[i]) printf("Y\n");
    // }
    return 0;
}