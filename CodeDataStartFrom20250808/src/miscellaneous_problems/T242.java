package miscellaneous_problems;
public class T242 {
    public boolean isAnagram(String s, String t) {
        int[] cnt = new int[26];
        int s_len = s.length(), t_len = t.length();
        for (int i = 0;i < s_len;i ++) {
            char ch = s.charAt(i);
            ++ cnt[ch - 'a'];
        }   
        for (int i = 0;i < t_len;i ++) {
            char ch = t.charAt(i);
            if(-- cnt[ch - 'a'] < 0) 
                return false;
        }
        for (int i = 0;i < 26;i ++) {
            if(cnt[i] != 0)
                return false;
        }
        return true;
    }
}
