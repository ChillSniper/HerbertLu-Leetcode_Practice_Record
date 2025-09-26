package problems_set;
public class T468_2 {
    public long maxTotalValue(int[] nums, int k) {
        int len = nums.length;
        int max_val = -1, min_val = Integer.MAX_VALUE;
        for (int i = 0;i < len;i ++) {
            max_val = Math.max(nums[i], max_val);
            min_val = Math.min(nums[i], min_val);
        }   
        long ans = (long)k * (long)(max_val - min_val);
        return ans;
    }
}
