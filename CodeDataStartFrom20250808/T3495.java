package miscellaneous_problems;
public class T3495 {
    public long minOperations(int[][] queries) {
        // 这种题新的知识点很多，要耐心下来看懂……
        // 算了，我觉得这种题还是自己想过去最好
        int n = queries.length;
        long ans = 0;
        for (int i = 0;i < n;i ++) {
            int a = queries[i][0], b = queries[i][1];
            ans += (f(b) - f(a - 1) + 1) / 2;
        }
        return ans;
    }
    private long f(int x) {
        int m = 32 - Integer.numberOfLeadingZeros(x);
        long res = 0;
        for (int i = 1;i < m;i ++) {
            res += (long)(i + 1) / 2 << (i - 1);
        }
        res += (long)(m + 1) / 2 * (x + 1 - (1 << (m - 1)));
        return res;
    }
}
