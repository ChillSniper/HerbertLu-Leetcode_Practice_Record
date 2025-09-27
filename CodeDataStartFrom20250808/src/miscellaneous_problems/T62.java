package miscellaneous_problems;
public class T62 {
    public int uniquePaths(int m, int n) {
        return C(m - 1, m + n - 2);
    }
    private int C(int m, int n) {
        int p = n - m;
        if(m > p) {
            int t = m;
            m = p;
            p = t;
        }
        long val = 1;
        for (int i = p + 1;i <= n;i ++) {
            long t = val * i / (i - p);
            val = t;
        }
        return (int)val;
    }
}
