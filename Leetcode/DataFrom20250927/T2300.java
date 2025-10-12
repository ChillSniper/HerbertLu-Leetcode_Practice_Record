import java.util.*;

public class T2300 {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        // 二分查找
        // 先sort一下
        int n = spells.length;
        int[] ans = new int[n];
        Arrays.sort(potions);
        for (int i = 0;i < n;i ++) {
            long x = spells[i];
            ans[i] = Get(potions, x, success);
        }
        return ans;
    }
    private int Get(int[] potions, long x, long success) {
        int n = potions.length, l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if((long)potions[mid] * x < success) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l >= n ? 0 : n - l;
    }
}
