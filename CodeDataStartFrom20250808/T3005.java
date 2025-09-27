package miscellaneous_problems;
import java.util.*;

public class T3005 {

    public int maxFrequencyElements(int[] nums) {
        TreeMap<Integer, Integer> record = new TreeMap<>();
        for (int x : nums) {
            record.put(x, record.getOrDefault(x, 0) + 1);
        }
        // int val = record.lastEntry().getValue();
        // 那么写实在是太蠢了
        List<Integer> g = new ArrayList<>(record.values());
        Collections.sort(g);
        int n = g.size(), val = g.get(n - 1), ans = val;
        for (int i = n - 2;i >= 0;i --) {
            int cur_val = g.get(i);
            if(cur_val != val)
                break;
            ans += val;
        }
        return ans;
    }
}