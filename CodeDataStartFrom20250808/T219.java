import java.util.*;

public class T219 {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> record = new HashMap<>();
        int n = nums.length;
        for (int i = 0;i < n;i ++) {
            int val = nums[i];
            if(!record.containsKey(val)) {
                record.put(val, i);
            }
            else {
                if(i - record.get(val) <= k)
                    return true;
                record.put(val, i);    
            }
        }
        return false;
    }
}
