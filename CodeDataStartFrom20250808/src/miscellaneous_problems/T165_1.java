package miscellaneous_problems;
import java.util.*;

public class T165_1 {
    public int smallestAbsent(int[] nums) {
        int n = nums.length;
        int avg = 0;
        Set<Integer> record = new HashSet<>();
        for (int item : nums) {
            record.add(item);
            avg += item;
        }
        avg /= n;
        int low = Math.max(avg + 1, 1);
        while(record.contains(low)) {
            ++ low;
        }
        return low;
    }
}
