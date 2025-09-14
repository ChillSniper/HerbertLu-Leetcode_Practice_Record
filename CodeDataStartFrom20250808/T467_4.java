public class T467_4 {
    public static void main(String[] args) {
        int[] nums = {7, 17, 7, 8};
        T467_4 t = new T467_4();
        int val = t.countStableSubsequences(nums);
        System.err.println(val);
    }
    public int countStableSubsequences(int[] nums) {
        // 奇偶
        // 奇奇
        // 偶奇
        // 偶偶
        // 或者自己单走
        // so how to calculate the ans ?
        // 如果当前是奇数
        // 可以计入到此前奇偶，偶奇，偶偶，然后对对应的状态改变
        // 或者单开，然后改变单位的数量
        long[][] f = new long[2][2];
        long[] k = new long[2];
        int n = nums.length;
        long ans = 0;
        final long MOD = (int)1e9 + 7;
        for (int i = 0;i < n;i ++) {
            int val = nums[i];
            if(val % 2 == 1) {
                ans = (ans + f[1][0]) % MOD;
                ans = (ans + f[0][1]) % MOD;
                ans = (ans + f[0][0]) % MOD;
                ans = (ans + k[0]) % MOD;
                ans = (ans + k[1]) % MOD;
                ans ++;
                long f_0_1 = (f[1][0] + f[0][0] + k[0]) % MOD;
                long f_1_1 = (f[0][1] + k[1]) % MOD;
                f[0][1] += f_0_1;
                f[1][1] += f_1_1;
                ++ k[1];
            }
            else {
                ans = (ans + f[1][0]) % MOD;
                ans = (ans + f[0][1]) % MOD;
                ans = (ans + f[1][1]) % MOD;
                ans = (ans + k[0]) % MOD;
                ans = (ans + k[1]) % MOD;
                ans ++;
                long f_0_0 = (f[1][0] + k[0]) % MOD;
                long f_1_0 = (f[0][1] + f[1][1] + k[1]) % MOD;
                f[0][0] += f_0_0;
                f[1][0] += f_1_0;
                ++ k[0];
            }
        }
        return (int)ans;
    }
}
