package problems_set;
import java.util.HashSet;

public class T3{
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), i = 0, j = 0, ans = 0;
        HashSet<Character> record = new HashSet<>();
        for (;i <= j && j < n;++ j) {
            char ch = s.charAt(j);
            while(record.contains(ch)) {
                record.remove(s.charAt(i));
                ++ i;
            }
            record.add(ch);
            ans = Math.max(ans, j - i + 1);
        }
        return ans;
    }
};