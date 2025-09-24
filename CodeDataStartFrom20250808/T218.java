import java.util.*;

public class T218 {
    public int longestConsecutive(int[] nums) {
        // 我都忘了这个什么时候写的了
        // 。。。
        Map<Integer, Integer> record = new HashMap<>();
        for (int x : nums) 
            record.merge(x, 1, Integer::sum);
        int ans = 0;
        for (Map.Entry<Integer, Integer> r : record.entrySet()) {
            int key = r.getKey(), val = r.getValue();
            if(val == -1)
                continue;
            r.setValue(-1);
            int cur_len = 1;
            while(record.containsKey(-- key)) {
                ++ cur_len;
                record.put(key, -1);
            }
            key = r.getKey();
            while(record.containsKey(++ key)) {
                ++ cur_len;
                record.put(key, -1);
            }
            ans = Math.max(ans, cur_len);
        }
        return ans;
    }
}
