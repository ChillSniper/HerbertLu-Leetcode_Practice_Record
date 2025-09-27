package miscellaneous_problems;
public class T3227 {
    public boolean doesAliceWin(String s) {
        int len = s.length();
        int cnt = 0;
        for (int i = 0;i < len;i ++) {
            char ch = s.charAt(i);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ++ cnt;
            }
        }
        return cnt > 0;
    }
}