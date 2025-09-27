package problems_set;
// public class T34 {
//     public int[] searchRange(int[] nums, int target) {
//         int n = nums.length, l = 0, r = n - 1;
//         int[] ans = new int[2];
//         while(l < r) {
//             int mid = (r - l) >> 1 + l;
//             int val = nums[mid];
//             if(val < target) {
//                 l = mid + 1;
//             }
//             else if(val > target) {
//                 r = mid - 1;
//             }
//             else {
//                 r = mid - 1;
//             }
//         }
//         ans[0] = l >= n ? -1 : nums[l] == target ? l : -1;
//         l = 0;
//         r = n - 1;
//         while(l < r) {
//             int mid = (r - l) >> 1 + l;
//             int val = nums[mid];
//             if(val < target) {
//                 l = mid + 1;
//             }
//             else if(val > target) {
//                 r = mid - 1;
//             }
//             else {
//                 l = mid + 1;
//             }
//         }
//         ans[1] = r < 0 ? -1 : nums[r] == target ? r : -1;
//         return ans;
//     }
// }

public class T34 {
    public int[] searchRange(int[] nums, int target) {
        int x = LowerBound(nums, target), n = nums.length;
        if(x == n || nums[x] != target) {
            return new int[] {-1, -1};
        }
        int y = LowerBound(nums, target + 1);
        return new int[] {x, y - 1};
    } 
    private int LowerBound(int[] nums, int target) {
        int n = nums.length, l = 0, r = n - 1;
        while(l <= r) {
            int mid = (r - l) / 2 + l;
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}