package miscellaneous_problems;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class T740 {
    public int deleteAndEarn(int[] nums) {
        List<Integer> store = new ArrayList<>(), val = new ArrayList<>();
        TreeMap<Integer, Integer> record = new TreeMap<>();
        int n = nums.length;
        for (int i = 0;i < n;i ++) {
            int x = nums[i];
            record.put(x, record.getOrDefault(x, 0) + 1);
        }
        for (Map.Entry<Integer, Integer> entry : record.entrySet()) {
            int key = entry.getKey(), value = entry.getValue();
            val.add(key);
            store.add(value * key);
        }
        int len = store.size();
        int[] f = new int [len];
        f[0] = store.get(0);
        for (int i = 1;i < len;i ++) {
            int cur_x = val.get(i), bf_x = val.get(i - 1);
            if(cur_x != bf_x + 1) {
                f[i] = f[i - 1] + store.get(i);
            }
            else {
                if(i >= 2)
                f[i] = Math.max(f[i - 2] + store.get(i), f[i - 1]);
                else 
                    f[i] = Math.max(f[i - 1], store.get(i));
            }
        }
        return Arrays.stream(f).max().getAsInt();
    }

}
