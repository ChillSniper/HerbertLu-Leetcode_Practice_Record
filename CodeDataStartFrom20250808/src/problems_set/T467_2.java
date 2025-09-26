package problems_set;
import java.util.*;

public class T467_2 {
    public int[] maxKDistinct(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length, cnt = 0, index = n - 1;
        List<Integer> ans = new ArrayList<>();
        ans.add(nums[index --]);
        ++ cnt;
        while(cnt < k && index >= 0) {
            if(nums[index] != nums[index + 1]) {
                ans.add(nums[index --]);
                ++ cnt;
            }
            else {
                -- index;
            }
        }
        int[] fk = new int[ans.size()];
        for (int i = 0;i < (int)ans.size();i ++) {
            fk[i] = ans.get(i);
        }
        return fk;
    }
}
