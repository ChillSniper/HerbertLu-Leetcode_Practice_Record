import java.util.*;
import java.util.stream.IntStream;

public class T2503 {
    final private int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int[] sz, father;
    public int[] maxPoints(int[][] grid, int[] queries) {
        // 使用并查集的话，时间复杂度受排序而限制
        // 这题采用了离线查询+并查集的方法
        // 初步认识了离线查询这种操作
        int m = grid.length, n = grid[0].length, all = m * n;
        sz = new int[all];
        father = new int[all];
        Arrays.fill(sz, 1);
        for (int i = 0;i < all;i ++) 
            father[i] = i;
        int index = 0;
        int[][] record = new int[all][3];
        for (int i = 0;i < m;i ++) 
            for (int j = 0;j < n;j ++) {
                record[i * n + j] = new int[]{grid[i][j], i, j};
            }
        Arrays.sort(record, (a, b) -> a[0] - b[0]);
        int q_len = queries.length;
        // 这一行谁他妈的记得住啊
        Integer[] q = IntStream.range(0, q_len).boxed().toArray(Integer[]::new);
        int[] ans = new int[q_len];
        Arrays.sort(q, (a, b) -> queries[a] - queries[b]);
        for (int f = 0;f < q_len;f ++) {
            int idx = q[f], q_val = queries[idx];
            for (;index < all && record[index][0] < q_val;++ index) {
                int i = record[index][1], j = record[index][2];
                for (int k = 0;k < 4;k ++) {
                    int ni = i + dir[k][0], nj = j + dir[k][1];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] < q_val) {
                        Merge(i * n + j, ni * n + nj);
                    }
                }
            }
            if(grid[0][0] < q_val) {
                ans[idx] = sz[FindFather(0)];
            }
        }
        return ans;
    }
    private int FindFather(int x) {
        if(father[x] == x)
            return x;
        return father[x] = FindFather(father[x]);
    }
    private void Merge(int x, int y) {
        int fx = FindFather(x);
        int fy = FindFather(y);
        if(fx == fy)
            return ;
        sz[fx] += sz[fy];
        father[fy] = fx;
    }
}
