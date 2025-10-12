#include <iostream>
#include <vector>
using namespace std;
//#define Way1
#define Way2
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        #ifdef Way1
        int SlowPointer = 0;
        int FastPointer = numbers.size() - 1;
        while (SlowPointer < FastPointer)
        {
            if(numbers[SlowPointer] + numbers[FastPointer] == target)
                return {SlowPointer + 1, FastPointer + 1};
            else if(numbers[SlowPointer] + numbers[FastPointer] < target)
                SlowPointer ++;
            else if(numbers[SlowPointer] + numbers[FastPointer] > target)
                FastPointer --;
        }
        return {0, 0};
        #endif

        #ifdef Way2
        for(int i = 0;i < numbers.size();i ++){
            int L = i + 1, r = numbers.size() - 1;
            while (L <= r){
                int mid = (L + r) >> 1;
                if(numbers[i] + numbers[mid] == target){
                    return {i + 1, mid  + 1};
                } else if(numbers[i] + numbers[mid] < target){
                    L = mid + 1;
                } else if(numbers[i] + numbers[mid] > target){
                    r = mid - 1;
                }
            }
        }
        return {-1, -1};
        #endif
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int N, target;
    cin >> N >> target;
    vector<int> a(N);
    for(int i = 0;i < N;i ++)
        scanf("%d", &a[i]);
    Solution s;
    vector<int> ans = s.twoSum(a, target);
    for(int i = 0;i < ans.size();i ++){
        printf("%d ", ans[i]);
    }
    return 0;
}