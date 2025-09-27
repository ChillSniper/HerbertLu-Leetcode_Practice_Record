package problems_set;
import java.util.Arrays;;

public class T3025 {
    public int numberOfPairs(int[][] points) {
        // 这种题真的莫名其妙
        // 不得不说，他这个题解的思路真的妙
        // 我一开始的排序思路是错的，对横坐标的处理是正确的，
        // 但是对纵坐标的处理没有考虑到对x值相同时的处理情况
        int m = points.length;
        Arrays.sort(points, (a, b) -> {return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];});
        int ans = 0;
        for (int i = 0;i < m;i ++) {
            // 这个记录两点区间之间坐标的最大值的处理方式很妙
            int Max_Y = Integer.MIN_VALUE, y_h = points[i][1];

            for (int j = i + 1;j < m;j ++) {
                int cur_y = points[j][1];
                if(cur_y <= y_h && cur_y > Max_Y) {
                    ++ ans;
                    Max_Y = cur_y;
                }
            }
        }
        return ans;
    }
}
