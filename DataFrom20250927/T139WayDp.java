import java.util.*;

public class T139WayDp {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length(), maxLen = 0;
        Set<String> record = new HashSet<>(wordDict);
        for (String item : wordDict) {
            maxLen = Math.max(maxLen, item.length());
        }
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= Math.min(maxLen, i);j ++) {
                if(f[i - j] == 1 && record.contains(s.substring(i - j, i))) {
                    f[i] = 1;
                    break;
                }
            }
        }
        return f[n] == 1;
    }
}