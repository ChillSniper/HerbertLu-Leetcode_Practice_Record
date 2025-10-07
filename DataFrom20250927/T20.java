import java.util.*;
public class T20 {
    public boolean isValid(String s) {
        Deque<Character> dq = new ArrayDeque<>();
        char[] t = s.toCharArray();
        int n = s.length();
        int[] record = new int[300];
        record['('] = -1; record[')'] = 1;
        record['{'] = -2; record['}'] = 2;
        record['['] = -3; record[']'] = 3;
        for (int i = 0;i < n;i ++) {
            char ch = t[i];
            if(record[ch] < 0) {
                dq.addLast(ch);
            }
            else {
                if(dq.isEmpty())
                    return false;
                char fk = dq.pollLast();
                if(record[fk] + record[ch] != 0)
                    return false;
            }
        }
        return dq.isEmpty();
    }
}
