import java.util.*;

public class T167_3 {
    public static void main(String[] args) {
        String s = "bc";
        T167_3 t = new T167_3();
        int ans = t.longestBalanced(s);
        System.out.println(ans);
    }
    public int longestBalanced(String s) {
        // abbac
        Map<Long, Integer> record = new HashMap<>();
        int ans = 0;
        int n = s.length();
        int[] cnt = new int[3];
        record.put(0l, -1);
        for (int i = 0;i < n;i ++) {
            char ch = s.charAt(i);
            cnt[ch - 'a'] ++;
            int minVal = Math.min(cnt[0], Math.min(cnt[1], cnt[2]));
            long fa = cnt[0] - minVal, fb = cnt[1] - minVal, fc = cnt[2] - minVal;
            long flag = (fa << 32) + (fb << 16) + fc;
            if(record.containsKey(flag)) {
                int p = record.get(flag), t = i - p;
                ans = Math.max(ans, t);
            }
            else {
                record.put(flag, i);
            }
            // cnta = cntb, ctn c = 0;
            if((cnt[0] == cnt[1] && cnt[2] == 0) || (cnt[0] == cnt[2] && cnt[1] == 0) || (cnt[1] == cnt[2] && cnt[0] == 0) 
                || (cnt[1] == 0 && cnt[2] == 0) || (cnt[0] == 0 && cnt[2] == 0) || (cnt[0] == 0 && cnt[1] == 0)) {
                    ans = Math.max(ans, i + 1);
            }
            if(cnt[0] == 0 && cnt[1] != 0 && cnt[2] != 0) {
                int minval = Math.min(cnt[1], cnt[2]);
                
            }
            if(cnt[1] == 0 && cnt[0] != 0 && cnt[2] != 0) {

            }
            if(cnt[2] == 0 && cnt[0] != 0 && cnt[1] != 0) {

            }
        }
        return ans;
    }
}
