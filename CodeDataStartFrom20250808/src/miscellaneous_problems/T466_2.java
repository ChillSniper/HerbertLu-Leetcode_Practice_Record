package miscellaneous_problems;
import java.util.HashSet;

public class T466_2 {
    public int minOperations(String s) {
        int cnt = 0, n = s.length();
        HashSet<Character> record = new HashSet<>();
        for (int i = 0;i < n;i ++) {
            record.add(s.charAt(i));
        }
        for (char ch = 'b';ch <= 'z'; ++ ch) {
            if(record.contains(ch)) {
                ++ cnt;
                char f = (char)(ch + 1);
                record.add(f);
            }
        }
        return cnt;
    }
}
