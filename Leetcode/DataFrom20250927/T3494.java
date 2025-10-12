public class T3494 {
    public long minTime(int[] skill, int[] mana) {
        // 这什么b题，一点思路没有
        // 这道题和时间顺序有关，所以该联系到什么算法上去呢？
        // 难道是dp？
        // 这题是真的逆天
        int n = skill.length, m = mana.length;
        long[] record = new long[n];
        for (int i = 0;i < m;i ++) {
            long sumTime = 0;
            for (int j = 0;j < n;j ++) {
                sumTime = Math.max(record[j], sumTime) + skill[j] * mana[i];
            }
            for (int j = n - 1;j >= 0;j --) {
                record[j] = sumTime;
                sumTime -= skill[j] * mana[i];
            }
        }
        return record[n - 1];
    }
}
