package miscellaneous_problems;
public class T2327New {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        int record[] = new int[n + 1];
        record[1] = 1;
        record[2] = -1;
        long ans = 0;
        final int MOD = (int)1e9 + 7;
        for (int i = 1;i <= n;i ++) {
            // i + delay
            // i + forget
            if(i + delay <= n) {
                ++ record[i + delay];
            }
            if(i + forget <= n) {
                -- record[i + forget];
            }
        }
        for (int i = 1;i <= n;i ++) {
            record[i] = (record[i] + record[i - 1]) % MOD;
            // we should keep i + forget > n;
            // so i > n - forget
            if (i > n - forget) {
                ans = (ans + record[i]) % MOD;
            }
        }
        return (int) ans;
    }
}