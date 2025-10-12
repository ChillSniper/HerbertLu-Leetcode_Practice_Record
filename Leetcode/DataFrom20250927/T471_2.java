
public class T471_2 {
    public int longestBalanced(String s) {
        int n = s.length(), ans = 0;
        int [][] cnt = new int[n + 1][26];
        for (int i = 0;i < n;i ++) {
            for (int k = 0;k < 26;k ++) {
                cnt[i + 1][k] = cnt[i][k];
            }
            cnt[i + 1][s.charAt(i) - 'a'] ++;
        }
        for (int i = 0;i < n;i ++) {
            for (int j = i;j < n;j ++) {
                
                boolean flag = check(i, j, cnt);
                if(flag) {
                    ans = Math.max(ans, j + 1 - i);
                }
            }
        }
        return ans;
    }
    private boolean check(int i, int j, int[][] cnt) {
        int val = 0;
        for (int k = 0;k < 26;k ++) {
            int t = cnt[j][k] - cnt[i - 1][k];
            if(t == 0)
                continue;
            if(t != 0 && val == 0)
                val = t;
            else if(t != 0 && val != 0 && val != t)
                return false;
        }   
        return true;
    }
}
