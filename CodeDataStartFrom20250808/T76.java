import java.util.HashMap;
import java.util.Objects;

public class T76 {
    public String minWindow(String s, String t) {
        int s_len = s.length(), t_len = t.length();
        HashMap<Character, Integer> record = new HashMap<>();
        String ans = "";
        for (int i = 0;i < t_len;i ++) {
            char ch = t.charAt(i);
            record.put(ch, record.getOrDefault(ch, 0) + 1);
        }
        int i = 0, j = 0, key_num = record.size(), cnt = 0;
        HashMap<Character, Integer> tmp = new HashMap<>();
        for (;i <= j && j < s_len;j ++) {
            char ch = s.charAt(j);
            // 现在还是不很熟悉语法格式
            // 问题在于收缩窗口
            tmp.put(ch, tmp.getOrDefault(ch, 0) + 1);
            if(Objects.equals(tmp.getOrDefault(ch, 0), record.getOrDefault(ch, 0)) 
            && record.getOrDefault(ch, 0) != 0) {
                ++ cnt;
            }
            if(cnt < key_num) {
                continue;
            }
            while(i < j && (record.getOrDefault(s.charAt(i), 0) == 0 
            || tmp.getOrDefault(s.charAt(i), 0) - 1 >= record.getOrDefault(s.charAt(i), 0))) {
                tmp.put(s.charAt(i), tmp.getOrDefault(s.charAt(i), 0) - 1);
                ++ i;
            }
            if(ans.length() == 0 || j - i + 1 < ans.length()) {
                ans = s.substring(i, j + 1);
            }
        }
        return ans;  
    }   
    
    public static void main(String[] args) {
        String s = "bba", t = "ab";
        T76 obj = new T76();
        String ans = obj.minWindow(s, t);
        System.out.println(ans);
    }
}
