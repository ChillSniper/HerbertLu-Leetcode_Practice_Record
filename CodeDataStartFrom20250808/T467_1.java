
public class T467_1 {
        public int earliestTime(int[][] tasks) {
            int ans = Integer.MAX_VALUE, n = tasks.length;
            for (int i = 0;i < n;i ++) {
                int t = tasks[i][0] + tasks[i][1];
                ans = Math.min(ans, t);
            }
            return ans;
    }
}
