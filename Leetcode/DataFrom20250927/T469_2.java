public class T469_2 {
    public long splitArray(int[] nums) {
        // 先反向判断是否严格递增
        long Ans; 
        int n = nums.length;
        boolean[] enable = new boolean[n];
        enable[n - 1] = true;
        int index = n - 2;
        while(index >= 0 && nums[index] > nums[index + 1]) {
            enable[index] = true;
            -- index;
        }
        long[] Pre = new long[n], suf = new long[n];
        Pre[0] = nums[0];
        for (int i = 1;i < n;i ++)
            Pre[i] = Pre[i - 1] + nums[i];
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2;i >= 0;i --) 
            suf[i] = suf[i + 1] + nums[i];
        Ans = enable[1] ? Math.abs(Pre[0] - suf[1]) : Long.MAX_VALUE;
        for (int i = 1;i < n - 1;i ++) {
            if(nums[i] <= nums[i - 1]) 
                break;
            if(enable[i + 1]) {
                Ans = Math.min(Ans, Math.abs(Pre[i] - suf[i + 1]));
            }
        }
        return Ans != Long.MAX_VALUE ? Ans : -1;
    }
}
