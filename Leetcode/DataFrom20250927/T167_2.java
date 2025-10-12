public class T167_2 {
    public int longestSubarray(int[] nums) {
        int ans = 2, n = nums.length;
        for (int i = 0;i + 1 < n;) {
            int j = i + 2;
            while(j < n && nums[j] == nums[j - 1] + nums[j - 2]) {
                ++ j;
            }
            int len = j - i;
            ans = Math.max(ans, len);
            i = j - 1;
        }   
        return ans;
    }
}
