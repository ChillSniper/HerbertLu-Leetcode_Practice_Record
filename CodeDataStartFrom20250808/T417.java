import java.util.ArrayList;
import java.util.List;

public class T417 {
    int m, n;
    final private int[][] dir = new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        // 图论需要定期复习，不然全部忘掉了
        m = heights.length;
        n = heights[0].length;
        int[][] VisPacific = new int[m][n];
        int[][] VisAtlantic = new int[m][n];
        for (int i = 0;i < m;i ++)
            Dfs(heights, VisPacific, i, 0);
        for (int j = 0;j < n;j ++)
            Dfs(heights, VisPacific, 0, j);
        for (int i = 0;i < m;i ++) 
            Dfs(heights, VisAtlantic, i, n - 1);
        for (int j = 0;j < n;j ++)
            Dfs(heights, VisAtlantic, m - 1, j);
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0;i < m;i ++) {
            for (int j = 0;j < n;j ++) {
                if(VisAtlantic[i][j] == 1 && VisPacific[i][j] == 1) {
                    ans.add(List.of(i, j));
                }
            }
        }    
        return ans;
    }
    private void Dfs(int[][] heights, int[][] vis, int i, int j) {
        if(vis[i][j] == 1)
            return;
        vis[i][j] = 1;
        for (int index = 0;index < 4;index ++) {
            int ni = i + dir[index][0];
            int nj = j + dir[index][1];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && heights[ni][nj] >= heights[i][j] && vis[ni][nj] == 0) {
                Dfs(heights, vis, ni, nj);
            }
        }
    }
}
