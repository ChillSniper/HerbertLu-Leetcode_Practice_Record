package miscellaneous_problems;
public class T466_1 {
    public int minOperations(int[] nums) {
        int n = nums.length, x = nums[0], flag = 1;
        for (int i = 1;i < n;i ++) {
            if(nums[i] != x) {
                flag = 0;
                break;
            }
        }   
        if(flag == 1) {
            return 0;
        }
        return 1;
    }
}
