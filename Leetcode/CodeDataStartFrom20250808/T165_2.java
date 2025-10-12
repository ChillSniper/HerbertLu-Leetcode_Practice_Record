import java.util.*;

public class T165_2 {
    public int minArrivalsToDiscard(int[] arrivals, int w, int m) {
        int ans = 0, n = arrivals.length, l = 0, r = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        int[] IsThrow = new int[n];
        for (;l <= r && r < n;) {
            int cur_len = r - l + 1;
            while(cur_len > w) {
                int left_val = arrivals[l];
                if(IsThrow[l] == 0) {
                    mp.put(left_val, mp.getOrDefault(left_val, 0) - 1);
                }
                ++ l;
                cur_len = r - l + 1;
            }
            int val = arrivals[r];
            if(mp.getOrDefault(val, 0) >= m) {
                ++ ans;
                IsThrow[r] = 1;
            }
            else {
                mp.put(val, mp.getOrDefault(val, 0) + 1);
            }
            ++ r;
        }
        return ans;
    }
}
