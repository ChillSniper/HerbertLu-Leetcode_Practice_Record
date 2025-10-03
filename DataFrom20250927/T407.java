import java.util.*;
public class T407 {
    
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length, n = heightMap[0].length, ans = 0;
        PriorityQueue<int[]> t = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        
        for (int i = 0;i < m;i ++) 
            for (int j = 0;j < n;j ++)
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    t.add(new int[]{heightMap[i][j], i, j});
                    heightMap[i][j] = -1;
                }
        int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    
        while(!t.isEmpty()) {
            int[] f = t.poll();
            int minval = f[0], i = f[1], j = f[2];
            for (int k = 0;k < 4;k ++) {
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && heightMap[ni][nj] >= 0) {
                    ans += heightMap[ni][nj] >= minval ? 0 : minval - heightMap[ni][nj];
                    t.add(new int[]{Math.max(minval, heightMap[ni][nj]), ni, nj});
                    heightMap[ni][nj] = -1;
                }
            }
        }
        return ans;
    }
}
