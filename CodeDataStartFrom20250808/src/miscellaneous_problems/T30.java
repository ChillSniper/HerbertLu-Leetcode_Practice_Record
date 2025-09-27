package miscellaneous_problems;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class T30 {

    public static void main(String[] args) {
        String s = "wordgoodgoodgoodbestword";
        String[] words = new String[]{"word","good","best","good"};
        T30 obj = new T30();
        List<Integer> ans = obj.findSubstring(s, words);
        System.err.println(ans);
    }

    public List<Integer> findSubstring(String s, String[] words) {
        // 这题的解题思路本质上也是滑动窗口，但是对于细节的处理是值得注意的
        List<Integer> ans = new ArrayList<>();
        int word_len = words[0].length(), n = words.length, windows_len = n * word_len, len = s.length();        
        HashMap<String, Integer> record = new HashMap<>();

        for (String item: words) {
            record.put(item, record.getOrDefault(item, 0) + 1);
        }

        for (int i = 0;i < word_len;i ++) {
            // calculate what ?
            int args = 0;
            HashMap<String, Integer> tmp = new HashMap<>();
            for (int j = i + word_len;j <= len;j += word_len) {
                String item = s.substring(j - word_len, j);
                if (tmp.getOrDefault(item, 0).equals(record.getOrDefault(item, 0))) {
                    ++ args;
                }
                tmp.put(item, tmp.getOrDefault(item, 0) + 1);
                if(j - windows_len < 0) {
                    continue;
                }
                if(args == 0) {
                    ans.add(j - windows_len);
                }
                String del_s = s.substring(j - windows_len, j - windows_len + word_len);
                tmp.put(del_s, tmp.getOrDefault(del_s, 0) - 1);
                if(tmp.getOrDefault(del_s, 0).equals(record.getOrDefault(del_s, 0))) {
                    -- args;
                }
            }
        }
        return ans;
    }
}
