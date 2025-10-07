public class T72New {
    public int minDistance(String word1, String word2) {
        char[] s = word1.toCharArray();
        char[] t = word2.toCharArray();
        int m = s.length, n = t.length;
        int[][] dp = new int[2][n + 1];
        for (int i = 0;i < n;i ++)
            dp[0][i + 1] = i + 1;
        for (int i = 0;i < m;i ++) {
            dp[(i + 1) % 2][0] = i + 1;
            for (int j = 0;j < n;j ++) {
                dp[(i + 1) % 2][j + 1] = s[i] == t[j] ? dp[i % 2][j] : Math.min(Math.min(dp[i % 2][j], dp[(i + 1) % 2][j]), dp[i % 2][j + 1]) + 1;
            }
        }
        return dp[m % 2][n];
    }
}
