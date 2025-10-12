public class T300 {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        for (int i = 0;i < n;i ++) {
            dp[i + 1] = 1;
            for (int j = 0;j < i;j ++) {
                if(nums[i] > nums[j]) {
                    dp[i + 1] = Math.max(dp[j + 1] + 1, dp[i + 1]);
                }
            }
        }   
        int ans = 0;
        for (int i = 1;i <= n;i ++)
            ans = Math.max(ans, dp[i]);
        return ans;
    }
}
