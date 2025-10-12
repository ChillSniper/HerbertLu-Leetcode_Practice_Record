public class T673 {
    public int findNumberOfLIS(int[] nums) {
        // 先把n^2的做法想出来
        int n = nums.length;
        int[] dp = new int[n + 1], cnt = new int[n + 1];
        // no base init
        for (int i = 0;i < n;i ++) {
            dp[i + 1] = 1;
            cnt[i + 1] = 1;
            for (int j = 0;j < i;j ++) {
                if(nums[j] < nums[i] && dp[j + 1] + 1 > dp[i + 1]) {
                    dp[i + 1] = dp[j + 1] + 1;
                    cnt[i + 1] = cnt[j + 1];
                }
                else if(nums[j] < nums[i] && dp[j + 1] + 1 == dp[i + 1]) {
                    cnt[i + 1] += cnt[j + 1];
                }
            }
        }
        int ans_len = 0, ans = 0;
        for (int i = 1;i <= n;i ++) {
            if(dp[i] > ans_len) {
                ans_len = dp[i];
                ans = cnt[i];
            }
            else if(dp[i] == ans_len) {
                ans += cnt[i];
            }
            System.out.println(cnt[i] + " ");
        }
        return ans;
    }
}
