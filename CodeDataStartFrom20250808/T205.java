import java.util.*;

public class T205 {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> table = new HashMap<>();
        Set<Character> r = new HashSet<>();
        int n = s.length();
        for (int i = 0;i < n;i ++) {
            char s_val = s.charAt(i);
            char t_val = t.charAt(i);
            if(table.containsKey(s_val) == false) {
                if(r.contains(t_val)) {
                    return false;
                }
                table.put(s_val, t_val);
                r.add(t_val);
            }
            else if(table.get(s_val) != t_val) {
                return false;
            }
        }
        return true;
    }
}
