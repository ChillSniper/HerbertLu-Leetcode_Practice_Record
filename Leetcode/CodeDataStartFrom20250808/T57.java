import java.util.*;

public class T57 {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length, a = newInterval[0], b = newInterval[1];
        List<int[]> r = new ArrayList<>();
        boolean isEnter = false;
        for (int i = 0;i < n;i ++) {
            int x = intervals[i][0], y = intervals[i][1];
            if(b < x) {
                if(!isEnter) {
                    r.add(new int[]{a, b});
                    isEnter = true;
                }
                r.add(intervals[i]);
            }
            else if(a <= y) {
                a = Math.min(a, x);
                b = Math.max(b, y);
            }
            else if(a > y) {
                r.add(intervals[i]);
            }
        }
        if(!isEnter) {
            r.add(new int[]{a, b});
        }
        int[][] ans = new int[r.size()][2];
        for (int i = 0;i < r.size();i ++)
            ans[i] = r.get(i);
        return ans;
    }
}
