package problems_set;

public class T221 {
    public int maximalSquare(char[][] matrix) {
        // 怎么做
        // 有点像那个动态规划，但是怎么列方程呢
        // 如何利用正方形的性质
        int n = matrix.length, ans = 0;
        int[][] f = new int[n][n];
        for (int i = 0;i < n;i ++) {
            for (int j = 0;j < n;j ++) {
                if(matrix[i][j] != '0') {
                    int minval = Integer.MAX_VALUE;
                    if(i == 0 || j == 0) {
                        minval = 0;
                    }
                    if(i - 1 > -1 && j - 1 > -1) {
                        minval = Math.min(minval, f[i - 1][j - 1]);
                    }
                    if(i - 1 > -1) {
                        minval = Math.min(minval, f[i - 1][j]);
                    }
                    if(j - 1 > -1) {
                        minval = Math.min(minval, f[i][j - 1]);
                    }
                    minval = (minval == Integer.MAX_VALUE) ? 0 : minval;
                    f[i][j] = minval + 1;
                }
                ans = Math.max(ans, f[i][j]);
            }
        }
        return ans * ans;
    }
}
