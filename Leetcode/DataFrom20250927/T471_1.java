import java.util.*;

public class T471_1 {
    public int sumDivisibleByK(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> record = new HashMap<>();
        for (int num : nums) {
            record.merge(num, 1, Integer::sum);
        }
        int ans = 0;
        
        for (Map.Entry<Integer, Integer> en : record.entrySet()) {
            int val = en.getKey();
            int cnt = en.getValue();
            if(cnt % k == 0) 
                ans += (val * cnt);
        }
        return ans;
    }

}  
