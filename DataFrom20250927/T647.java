import java.util.Arrays;

public class T647 {
    public static void main(String[] args) {
        String s = "aaa";
        T647 t = new T647();
        int ans = t.countSubstrings(s);
        System.out.println(ans);
    }
    public int countSubstrings(String s) {
        int n = s.length(), ans = 0;
        char[] sc = new char[2 * n + 3];
        Arrays.fill(sc, '#');
        sc[0] = '?';
        for (int i = 0;i < n;i ++) {
            sc[i * 2 + 2] = s.charAt(i);
        }
        sc[2 * n + 2] = '!';
        n = sc.length;
        for (int i = 1;i < n - 1;i ++) {
            int lf = i, ri = i;
            while(sc[lf] == sc[ri]) {
                if(sc[lf] != '#')
                    ++ ans;
                -- lf;
                ++ ri;
            }
        }        
        return ans;
    }
}
