package miscellaneous_problems;
public class T1304 {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        int idx = 0;
        if(n % 2 == 1) {
            ans[0] = 0;
            ++ idx;
        }
        for (int i = 1;i <= n / 2;i ++) {
            ans[idx ++] = i;
            ans[idx ++] = -i;
        }
        return ans;
    }
}
