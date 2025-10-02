import java.util.*;

// public class T611 {
//     public int triangleNumber(int[] nums) {
//         // 这个应该是O(n * n * logn)
//         Arrays.sort(nums);
//         int ans = 0, n = nums.length, i = 0;
//         // 得了，手写二分好了
//         // (a - b, a + b)
//         Arrays.sort(nums);
//         while(i < n && nums[i] == 0) 
//             ++ i;
//         for (;i < n;i ++) {
//             for (int j = i + 1;j < n;j ++) {
//                 int a = nums[i], b = nums[j];
//                 // 
//                 int lf = Lower_Bound(nums, b - a + 1, j + 1, n - 1);
//                 int ri = Lower_Bound(nums, a + b, j + 1, n - 1);
//                 ans += (ri - lf);
                
//             }
//         }
//         return ans;
//     }   

//     private int Lower_Bound(int[] nums, int target, int l, int r) {
//         while(l <= r) {
//             int mid = (r - l) / 2 + l;
//             if(nums[mid] >= target) {
//                 r = mid - 1;
//             }
//             else {
//                 l = mid + 1;
//             }
//         }
//         // val < target true l
//         // val = target true l
//         // val > target l
//         return l;
//     }
// 
// }

// 原来这题有O(n^2)的做法，可以引入两个指针，使得对O(n)的时间充分化

public class T611 {
    public int triangleNumber(int[] nums) {
        int n = nums.length, ans = 0;
        Arrays.sort(nums);
        int TrueL = 0;
        while(TrueL < n && nums[TrueL] == 0) 
            ++ TrueL;
        for (int k = TrueL + 2;k < n;k ++) {
            int c = nums[k];
            int i = TrueL, j = k - 1;
            while(i < j) {
                if(nums[i] + nums[j] > c) {
                    ans += (j - i);
                    -- j;
                }
                else {
                    ++ i;
                }
            }
        }    
        return ans;
    }
}