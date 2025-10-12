
public class T115DP {
    public int numDistinct(String s, String t) {
        // remember the before...
        // so what the decision next step ?
        // let me thought it.
        // dp comes from recursive.
        int s_len = s.length(), t_len = t.length();   
        int[][] dp = new int[s_len + 1][t_len + 1];
        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();
        dp[0][0] = 1;
        for (int i = 0;i < s_len;i ++) {
            // this base is important!
            dp[i + 1][0] = 1;
            for (int j = 0;j < Math.min(t_len, i + 1);j ++) {
                if(sc[i] == tc[j]) 
                    dp[i + 1][j + 1] += (dp[i][j] + dp[i][j + 1]);
                else 
                    dp[i + 1][j + 1] += dp[i][j + 1];
            }
        }
        return dp[s_len][t_len];
    }
}
