#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
//#define RecursiveWayOneTime
//#define RecursiveWayTwiceTime
#define IterateWay
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
    vector<int> findMode(TreeNode* root) {
        TreeNode* pre = nullptr, *cur = root;
        int MaxCnt = 0, cnt = 0;
        stack<TreeNode*> st;
        vector<int> result;
        while (!st.empty() || cur)
        {
            if(cur){
                st.push(cur); cur = cur->left;
            } else{
                cur = st.top(); st.pop();
                if(!pre || pre->val != cur->val){
                    cnt = 1;
                } else if(pre->val == cur->val){
                    cnt ++;
                }
                if(cnt == MaxCnt){
                    result.push_back(cur->val);
                }
                if(cnt > MaxCnt){
                    MaxCnt = cnt;
                    result.clear();
                    result.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return result;
    }
private:
};
#endif

#ifdef RecursiveWayOneTime
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        DFS(root);
        return result;
    }
private:
    void DFS(TreeNode* cur){
        if(!cur) return ;
        DFS(cur->left);
        if(!pre || pre->val != cur->val){
            cnt = 1;
        } else if(pre->val == cur->val){
            cnt ++;
        }
        if(cnt == MaxNum){
            result.push_back(cur->val);
        } else if(cnt > MaxNum){
            MaxNum = cnt;
            result.clear();
            result.push_back(cur->val);
        }
        pre = cur;
        DFS(cur->right);
    }
    int cnt = 0;
    int MaxNum = 0;
    TreeNode* pre = nullptr;
    vector<int> result;
};
#endif

#ifdef RecursiveWayTwiceTime
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans, arr;
        TreeNode* p = root;
        stack<TreeNode*> st;
        while (p || !st.empty())
        {
            if(p){
                st.push(p); p = p->left;
            } else{
                p = st.top(); st.pop();
                arr.push_back(p->val);
                p = p->right;
            }
        }
        int n = arr.size(), MaxLen = 0;
        int f, s;
        for(f = 0, s = 0;f < n && s < n;){
            if(arr[f] == arr[s]){
                f ++;
            } else{
                MaxLen = max(MaxLen, f - s);
                s = f;
            }
        }
        MaxLen = max(MaxLen, f - s);
        for(f = 0, s = 0;f < n && s < n;){
            if(arr[f] == arr[s]){
                f ++;
            } else{
                if((f - s) == MaxLen) ans.push_back(arr[f]);
                s = f;
            }
        }
        if((f - s) == MaxLen) ans.push_back(arr[s]);
        return ans;
    }
};
#endif

int main(){
    return 0;
}