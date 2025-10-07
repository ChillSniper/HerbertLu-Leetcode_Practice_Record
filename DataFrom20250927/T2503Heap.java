import java.util.*;

public class T2503Heap {
    final int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int[] maxPoints(int[][] grid, int[] queries) {
        int cnt = 0, q_len = queries.length, m = grid.length, n = grid[0].length;
        int[] ans = new int[q_len];
        Integer[] q = new Integer[q_len];
        for (int i = 0;i < q_len;i ++)
            q[i] = i;
        Arrays.sort(q, (a, b) -> queries[a] - queries[b]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{grid[0][0], 0, 0});
        grid[0][0] = -1;
        for (int i = 0;i < q_len;i ++) {
            int idx = q[i], q_val = queries[idx];
            while(!pq.isEmpty() && pq.peek()[0] < q_val) {
                int[] tmp = pq.poll();
                int x = tmp[1], y = tmp[2];
                for (int k = 0;k < 4;k ++) {
                    int nx = x + dir[k][0];
                    int ny = y + dir[k][1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != -1) {
                        pq.add(new int[]{grid[nx][ny], nx, ny});
                        grid[nx][ny] = -1;
                    }
                }
                ++ cnt;
            }
            ans[idx] = cnt;
        }
        return ans;
    }
}
