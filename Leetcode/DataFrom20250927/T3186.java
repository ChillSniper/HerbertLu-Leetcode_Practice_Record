import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class T3186 {
    public long maximumTotalDamage(int[] power) {
        // 仔细读题。。。
        // 问题是怎么去找那个下标
        Arrays.sort(power);
        int n = power.length;
        List<int[]> record = new ArrayList<>();
        for (int i = 0;i < n;i ++) {
            int j = i, val = power[i];
            while(j < n && power[j] == val)
                ++ j;
            int cnt = j - i;
            i = j - 1;
            record.add(new int[]{power[i], cnt});
        }
        n = record.size();
        int[][] nums = new int[n][2];
        for (int i = 0;i < n;i ++) 
            nums[i] = record.get(i);
        long[] dp = new long[n + 1];
        for (int i = 0;i < n;i ++) {
            int j = i;
            while(j >= 0 && nums[j][0] > nums[i][0] - 3)
                -- j;
            dp[i + 1] = Math.max(dp[j + 1] + (long)nums[i][0] * (long)nums[i][1], dp[i]);
        }
        return dp[n];
    }
}
