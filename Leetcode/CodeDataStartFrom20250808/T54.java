import java.util.ArrayList;
import java.util.List;

public class T54 {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int m = matrix.length, n = matrix[0].length, i = 0, j = 0, cnt = 0, cir = 0;
        int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(cnt < n * m) {
            ans.add(matrix[i][j]);
            ++ cnt;
            matrix[i][j] = Integer.MIN_VALUE;
            if(cnt >= n * m)
                break;
            for (int index = 0;index < 3;index ++) {
                int nxt_i = i + dir[cir][0];
                int nxt_j = j + dir[cir][1];
                if(nxt_i >= m || nxt_i < 0 || nxt_j < 0 || nxt_j >= n || matrix[nxt_i][nxt_j] == Integer.MIN_VALUE) {
                    cir = (cir + 1) % 4;
                }
                else {
                    i = nxt_i;
                    j = nxt_j;
                    break;
                }
            }
        }
        return ans;
    }
}
