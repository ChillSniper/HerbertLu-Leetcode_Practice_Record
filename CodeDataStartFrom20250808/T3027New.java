package miscellaneous_problems;
import java.util.*;

public class T3027New {
    public int numberOfPairs(int[][] points) {
        int ans = 0;
        int n = points.length;
        Arrays.sort(points, (a, b) -> {
            return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
        });
        for (int i = 0;i < n;i ++) {
            int MaxVal = Integer.MIN_VALUE, cur = points[i][1];
            for (int j = i + 1;j < n;j ++) {
                if(points[j][1] <= cur && points[j][1] > MaxVal) {
                    MaxVal = points[j][1];
                    ++ ans;
                }
            }
        }
        return ans;
    }
}
