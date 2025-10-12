import java.util.*;

public class T516 {
    public int longestPalindromeSubseq(String s) {
        // 不是，这怎么搞
        // 我真服了，这种题一开始写的时候就压根没思路
        // 最后还是回归到使用记忆化搜索
        // 我一开始在想什么？两个指针都一开始放置在最左侧是行不通的
        // 因为这题搞的是回文串，所以得一个最左，一个最右
        char[] NewS = s.toCharArray();
        int n = s.length();
        int[][] memo = new int[n][n];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return Dfs(0, n - 1, NewS, memo);
    }
    private int Dfs(int i, int j, char[] s, int[][] memo) {
        if(i > j) 
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        if(i == j) {
            memo[i][j] = 1;
            return 1;
        }
        if(s[i] == s[j]) {
            return memo[i][j] = 2 + Dfs(i + 1, j - 1, s, memo);
        }
        return memo[i][j] = Math.max(Dfs(i, j - 1, s, memo), Dfs(i + 1, j, s, memo));
    }
}
