import java.util.*;

public class T452 {
    public int findMinArrowShots(int[][] points) {
        // 这个题有点像贪心
        int ans = 0, n = points.length;
        Arrays.sort(points, (a, b) -> {
            if(a[1] == b[1])
                return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });
        for (int i = 0;i < n;i ++) {
            int x = points[i][0], y = points[i][1];
            int j = i + 1;
            while(j < n && points[j][0] <= y) 
                ++ j;
            i = j - 1;
            ++ ans;
        }
        return ans;
    }
}
