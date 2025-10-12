#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define RecursiveWay
//#define HeapWay
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#ifdef RecursiveWay
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        GetArr(root);
        return arr[k - 1];
    }
private:
    void GetArr(TreeNode* root){
        if(!root) return ;
        GetArr(root->left);
        arr.push_back(root->val);
        GetArr(root->right);
    }
    vector<int> arr;
};
#endif

#ifdef HeapWay
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 构建一个大根堆，堆的个数为k

    }
    void Up(int idx){
        while (idx / 2 >= 1 && Heap[idx] > Heap[idx / 2])
        {
            swap(Heap[idx], Heap[idx / 2]);
            idx /= 2;
        }
    }
    void Down(int idx){
        while (idx <= heap_size)
        {
            int t = idx;
            if(idx * 2 <= heap_size && Heap[idx * 2] < Heap[t]) t = idx * 2;
            if(idx * 2 + 1 <= heap_size && Heap[idx * 2 + 1] < Heap[t]) t = idx * 2 + 1;
            if(t != idx){
                swap(Heap[t], Heap[idx]);
                idx = t;
            } else{
                break;
            }
        }  
    }
private:
    static const int N = 1e4 + 10;
    int Heap[N] = {0};
    int heap_size;
};
#endif

int main(){
    return 0;
}
