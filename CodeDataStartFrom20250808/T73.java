package miscellaneous_problems;
public class T73 {
    public void setZeroes(int[][] matrix) {
        // 容易想到的处理方式是使用两个set记录，但这显然不是最优解
        // 看到了一个非常妙的做法，太妙了
        int m = matrix.length, n = matrix[0].length;
        boolean flag_first_row = false, flag_first_col = false;
        for (int i = 0;i < n;i ++) {
            if(matrix[0][i] == 0) {
                flag_first_row = true;
                break;
            }
        }
        for (int i = 0;i < m;i ++) {
            if(matrix[i][0] == 0) {
                flag_first_col = true;
                break;
            }
        }
        for (int i = 1;i < m;i ++) {
            for (int j = 1;j < n;j ++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1;i < m;i ++) {
            if(matrix[i][0] == 0) {
                for (int j = 0;j < n;j ++)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 1;j < n;j ++) {
            if(matrix[0][j] == 0) {
                for (int i = 0;i < m;i ++)
                    matrix[i][j] = 0;
            }
        }
        if(flag_first_col) {
            for (int i = 0;i < m;i ++)
                matrix[i][0] = 0;
        }
        if(flag_first_row) {
            for (int i = 0;i < n;i ++) 
                matrix[0][i] = 0;
        }
    }
}
