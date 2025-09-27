package miscellaneous_problems;
import java.util.*;

public class T2785 {
    public String sortVowels(String s) {
        Set<Character> table = new HashSet<>(Set.of('a', 'e', 'i', 'o', 'u', 
        'A', 'E', 'I', 'O', 'U'));
        List<Character> record = new ArrayList<>();
        int n = s.length();
        for (int i = 0;i < n;i ++) {
            char ch = s.charAt(i);
            if(table.contains(ch)) {
                record.add(ch);
            }
        }
        StringBuilder sb = new StringBuilder(s);
        Collections.sort(record);
        int idx = 0;
        for (int i = 0;i < n;i ++) {
            char ch = s.charAt(i);
            if(table.contains(ch)) {
                sb.setCharAt(i, record.get(idx ++));
            }
        }
        String ans = sb.toString();
        return ans;
    }
}