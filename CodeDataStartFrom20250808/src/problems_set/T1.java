package problems_set;
import java.util.*;

public class T1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> record = new HashMap<>();
        int val = 0, n = nums.length;
        int[] ans = new int[2];
        for (int x : nums) {
            record.merge(x, 1, Integer::sum);
        }
        int i = 0;
        for (;i < n;i ++) {
            int x = nums[i];
            record.merge(x, -1, Integer::sum);
            if(record.getOrDefault(target - x, 0) > 0) {
                val = target - x;
                ans[0] = i ++;
                break;
            }
        }
        for (;i < n;i ++) {
            if(nums[i] == val) {
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
}
