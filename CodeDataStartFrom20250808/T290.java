import java.util.*;

public class T290 {
    public boolean wordPattern(String pattern, String s) {
        // 这个题的意思真莫名其妙
        // 字符串和字符之间的map对应
        // 必须学一下split怎么用，不然实在是太扯淡了
        Map<Character, String> ctos = new HashMap<>();
        Map<String, Character> stoc = new HashMap<>();
        int len = pattern.length(), j = 0, s_size = s.length();
        for (int i = 0;i < len;i ++) {
            char ch = pattern.charAt(i);
            StringBuilder tmp = new StringBuilder();
            while(j < s_size && s.charAt(j) == ' ') {
                ++ j;
            }
            while(j < s_size && s.charAt(j) != ' ') {
                char fk = s.charAt(j);
                ++ j;
                tmp.append(fk);
            }
            String fking = tmp.toString();
            if((ctos.containsKey(ch) && ctos.get(ch).equals(fking) == false) ||(stoc.containsKey(fking) && stoc.get(fking) != ch)) {
                return false;
            }
            if(fking.length() == 0)
                return false;
            ctos.put(ch, fking);
            stoc.put(fking, ch);
        }
        if(j != s_size)
            return false;
        return true;
    }
}
