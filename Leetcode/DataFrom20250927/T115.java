
import java.util.Arrays;

public class T115 {
    public int numDistinct(String s, String t) {
        // remember the before...
        // so what the decision next step ?
        // let me thought it.
        // dp comes from recursive.
        int s_len = s.length(), t_len = t.length();   
        int[][] memo = new int[s_len][t_len];
        for (int[] row : memo) 
            Arrays.fill(row, -1);
        return Dfs(s_len - 1, t_len - 1, memo, s.toCharArray(), t.toCharArray());
    }
    private int Dfs(int i, int j, int[][] memo, char[] s, char[] t) {
        if(j < 0)
            // it is important !
            return 1;
        if(i < j)
            return memo[i][j] = 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        if(s[i] == t[j])
            return memo[i][j] = Dfs(i - 1, j - 1, memo, s, t) + Dfs(i - 1, j, memo, s, t);
        return memo[i][j] = Dfs(i - 1, j, memo, s, t);
    }
}
