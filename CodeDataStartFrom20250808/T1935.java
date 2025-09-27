package miscellaneous_problems;
public class T1935 {
    public int canBeTypedWords(String text, String brokenLetters) {
        char[] record = new char[26];
        int text_len = text.length(), bro_len = brokenLetters.length();      
        for (int i = 0;i < bro_len;i ++) {
            char ch = brokenLetters.charAt(i);
            record[ch - 'a'] = 1;
        }
        
        int ans = 0;
        for (int i = 0;i < text_len;) {
            boolean flag = true;
            int j = i;
            while(j < text_len && text.charAt(j) != ' ') {
                char ch = text.charAt(j);
                if(record[ch - 'a'] == 1) {
                    flag = false;
                }
                ++ j;
            }
            i = j + 1;
            if(flag) {
                ++ ans;
            }
        }
        return ans;
    }
}