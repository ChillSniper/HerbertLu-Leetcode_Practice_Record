package problems_set;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class T15New {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        for (int i = 0;i < n - 2;i ++) {
            if(i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int a = nums[i], j = i + 1, k = n - 1;
            if(a + nums[i + 1] + nums[i + 2] > 0) {
                continue;
            }
            if(a + nums[n - 2] + nums[n - 1] < 0) {
                continue;
            }
            while(j < k) {
                if(a + nums[j] + nums[k] < 0) {
                    ++ j;
                }
                else if(a + nums[j] + nums[k] > 0) {
                    -- k;
                }
                else {
                    ans.add(Arrays.asList(a, nums[j], nums[k]));
                    for (++ j;j < k && nums[j] == nums[j - 1]; ++ j) {

                    }
                    for (-- k;k > j && nums[k] == nums[k + 1];-- k) {

                    }
                }
            }
        }
        return ans;
    }
}
