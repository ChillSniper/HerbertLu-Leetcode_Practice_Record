public class T72 {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        
        for (int j = 1;j <= n;j ++)
            dp[0][j] = j;

        for (int i = 0;i < m;i ++) {

            dp[i + 1][0] = i + 1;

            for (int j = 0;j < n;j ++) {
                char a = word1.charAt(i), b = word2.charAt(j);
                if(a == b) {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else {
                    dp[i + 1][j + 1] = Math.min(dp[i][j], Math.min(dp[i + 1][j], dp[i][j + 1])) + 1;
                }
            }
        }   
        return dp[m][n];
    }
}
