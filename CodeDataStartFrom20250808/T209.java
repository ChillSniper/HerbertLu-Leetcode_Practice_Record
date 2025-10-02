public class T209 {
    public int minSubArrayLen(int target, int[] nums) {
        // 注意此题的题目条件。。。是大于等于而不是等于
        
        int n = nums.length, ans = n + 1, cur = 0;
        for (int i = 0, j = 0;j < n;++ j) {
            cur += nums[j];
            if(cur < target) {
                continue;
            }
            while(cur >= target && i <= j) {
                cur -= nums[i ++];
            }
            ans = Math.min(ans, j - i + 2);
        }
        return ans == n + 1 ? 0 : ans;
    }
}
