package problems_set;
public class T5 {
    public String longestPalindrome(String s) {
        // 甚至我感到很奇怪，这道题为什么不是贪心，而是动态规划
        // 时间复杂度估计是O(n^2)
        // 好像想起来了，列的是展开的动态方程

        // 1. dp解法
        // 枚举需要耗费O(n^2)的时间
        // 由此的，判定字符串是否为回文的时间限制为O(1)
        char[] sc = s.toCharArray();
        int ans = 1, lf = 0, ri = 0, n = sc.length;
        for (int i = 0;i < n;i ++) {
            int l = i, r = i;
            while(l - 1 >= 0 && r + 1 < n && sc[l - 1] == sc[r + 1]) {
                -- l;
                ++ r;
            }
            if(r - l + 1 > ans) {
                ans = r - l + 1;
                lf = l;
                ri = r;
            }
        }
        for (int i = 0;i < n - 1;i ++) {
            int l = i, r = i + 1;
            if(sc[l] == sc[r]) {
                while(l - 1 >= 0 && r + 1 < n && sc[l - 1] == sc[r + 1]) {
                    -- l;
                    ++ r;
                }
                if(r - l + 1 > ans) {
                    ans = r - l + 1;
                    lf = l;
                    ri = r;
                }
            }
        }
        return s.substring(lf, ri + 1);
    }
}