package problems_set;
public class T468_1 {
    public int evenNumberBitwiseORs(int[] nums) {
        int n = nums.length, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans |= nums[i];
            }
        }
        return ans;
    }
}