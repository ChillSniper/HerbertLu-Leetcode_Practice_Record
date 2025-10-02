public class T1039dp {
    public int minScoreTriangulation(int[] values) {
        // 如果用dp做还真的是套三层循环
        int n = values.length;
        int[][] dp = new int[n][n];
        for (int len = 3;len <= n;len ++) {
            for (int i = 0;i + len - 1 < n;i ++) {
                dp[i][i + len - 1] = Integer.MAX_VALUE;
                for (int j = i + 1;j < i + len - 1;j ++) {
                    dp[i][i + len - 1] = Math.min(dp[i][i + len - 1], dp[i][j] + d[j][i + len - 1] + values[i] * values[i + len - 1] * values[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
