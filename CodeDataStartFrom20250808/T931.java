public class T931 {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        if(n == 1) 
            return matrix[0][0];
        final int maxVal = Integer.MAX_VALUE / 100;
        for (int i = 1;i < n;i ++) {
            for (int j = 0;j < n;j ++) {
                int cur_val = matrix[i][j];
                int p = maxVal;
                if(j - 1 >= 0) {
                    p = Math.min(p, matrix[i - 1][j - 1]);
                }
                p = Math.min(p, matrix[i - 1][j]);
                if(j + 1 < n) {
                    p = Math.min(p, matrix[i - 1][j + 1]);
                }
                matrix[i][j] = cur_val + p;
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int j = 0;j < n;j ++) {
            ans = Math.min(ans, matrix[n - 1][j]);
        }
        return ans;
    }
}
