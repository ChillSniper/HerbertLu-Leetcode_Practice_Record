public class T3147 {
    public int maximumEnergy(int[] energy, int k) {
        // 这种题真的莫名其妙
        int n = energy.length, ans = Integer.MIN_VALUE;
        for (int i = n - 1;i >= n - k && i >= 0;i --) {
            int curval = 0, j = i;
            while(j >= 0) {
                curval += energy[j];
                j -= k;
                ans = Math.max(ans, curval);
            }
        }
        return ans;
    }
}
