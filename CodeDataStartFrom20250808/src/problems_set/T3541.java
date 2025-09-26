package problems_set;
import java.util.*;

public class T3541 {
    public int maxFreqSum(String s) {
        int len = s.length();
        Map<Character, Integer> spe = new HashMap<>(), normal = new HashMap<>();
        for (int i = 0;i < len;i ++) {
            char ch = s.charAt(i);
            if(ch == 'i' || ch == 'o' || ch == 'a' || ch == 'e' || ch == 'u') {
                spe.put(ch, spe.getOrDefault(ch, 0) + 1);
            }
            else {
                normal.put(ch, normal.getOrDefault(ch, 0) + 1);
            }
        }
        int x = spe.isEmpty() ? 0 : Collections.max(spe.values());
        int y = normal.isEmpty() ? 0 : Collections.max(normal.values());
        return x + y;

    }       
}