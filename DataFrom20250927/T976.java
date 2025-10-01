import java.util.*;

public class T976 {
    public int largestPerimeter(int[] nums) {
        int n = nums.length;
        // 为什么今天这个题一点思路没有
        Arrays.sort(nums);
        for (int i = n - 3;i >= 0;-- i) {
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];
            if(a + b > c) {
                return a + b + c;
            }
        }
        return 0;
    }
}
