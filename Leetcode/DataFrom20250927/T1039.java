import java.util.Arrays;
public class T1039{
    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int[][] memo = new int[n][n];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return Dfs(0, n - 1, memo, n, values);
    }
    private int Dfs(int l, int r, int[][] memo, int n, int[] v) {
        if(r - l == 1) 
            return 0;
        if(memo[l][r] != -1)
            return memo[l][r];
        
        int ans = Integer.MAX_VALUE;
        for (int i = l + 1;i < r;i ++) {
            int val = v[i] * v[l] * v[r] + Dfs(l, i, memo, n, v) + Dfs(i, r, memo, n, v);
            ans = Math.min(ans, val);
        }
        return memo[l][r] = ans;
    }
}