public class T2327 {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        // 这个看题意应该是使用dp，怎么整呢
        // 应该从什么角度，去解决处理本题？
        // 有点无从下手之感    
        final int MOD = (int)1e9 + 7;
        int[] f = new int[n + 1];
        f[1] = 1;
        long ans = 0;
        for (int i = 1;i <= n;i ++) {
            // i + forget - 1 <= n
            // i <= n - forget + 1
            if(i <= n - forget + 1) {
                ans = (ans + f[i]) % MOD;
            }
            // [i + delay, i + forget - 1]
            for (int j = i + delay;j <= Math.min(n, i + forget - 1);j ++) {
                f[j] = (f[j] + f[i]) % MOD;
            }
        }
        return (int)ans;
    }
};