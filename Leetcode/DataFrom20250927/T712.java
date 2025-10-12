public class T712 {
    public int minimumDeleteSum(String s1, String s2) {
        // 这题怎么这么奇怪
        // 转换题面含义，是找两个字符串的最长公共子序列！
        int s1_len = s1.length(), s2_len = s2.length();
        int[][] dp = new int[s1_len + 1][s2_len + 1];
        for (int i = 1;i <= s1_len;i ++) 
            dp[i][0] = dp[i - 1][0] + s1.charAt(i - 1);
        for (int j = 1;j <= s2_len;j ++)
            dp[0][j] = dp[0][j - 1] + s2.charAt(j - 1);
        for (int i = 1;i <= s1_len;i ++) {
            for (int j = 1;j <= s2_len;j ++) {
                dp[i][j] = s1.charAt(i - 1) == s2.charAt(j - 1) ?
                dp[i - 1][j - 1] : Math.min(dp[i - 1][j] + s1.charAt(i - 1), dp[i][j - 1] + s2.charAt(j - 1));
            }
        }
        return dp[s1_len][s2_len];
    }
}
