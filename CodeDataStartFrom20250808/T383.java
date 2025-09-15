import java.util.HashMap;
import java.util.Map;

public class T383 {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> mag = new HashMap<>();
        Map<Character, Integer> ran = new HashMap<>();
        int m_len = magazine.length(), r_len = ransomNote.length();
        for (int i = 0;i < m_len;i ++) {
            char ch = magazine.charAt(i);
            mag.put(ch, mag.getOrDefault(ch, 0) + 1);
        }
        for (int i = 0;i < r_len;i ++) {
            char ch = ransomNote.charAt(i);
            ran.put(ch, ran.getOrDefault(ch, 0) + 1);
        }
        
        
        for (Map.Entry<Character, Integer> fk : ran.entrySet()) {
            char ch = fk.getKey();
            int val = fk.getValue();
            int p = mag.getOrDefault(ch, 0);
            if(p < val) {
                return false;
            }
        }
        return true;
    }
}
