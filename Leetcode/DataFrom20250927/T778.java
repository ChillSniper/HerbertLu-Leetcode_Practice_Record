import java.util.*;

public class T778 {
    final private int[][] dir = new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int swimInWater(int[][] grid) {
        int n = grid.length, ans = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[0] - b[0];
        });  
        pq.add(new int[]{grid[0][0], 0, 0});
        grid[0][0] = -1;
        while(true) {
            int[] t = pq.poll();
            int val = t[0], i = t[1], j = t[2];
            ans = Math.max(ans, val);
            if(i == n - 1 && j == n - 1) {
                break;
            }
            for (int k = 0;k < 4;k ++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != -1) {
                    pq.add(new int[]{grid[x][y], x, y});
                    grid[x][y] = -1;
                }
            }
        }
        return ans;
    }
}
