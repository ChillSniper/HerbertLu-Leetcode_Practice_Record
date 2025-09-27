package problems_set;
class SolutionT11 {
    public int maxArea(int[] height) {
        // 我真的服了，刚刚那个贪心的做法一坨
        int n = height.length, l = 0, r = n - 1, ans = 0;
        while(l < r) {
            int area = (r - l) * Math.min(height[l], height[r]);
            ans = Math.max(ans, area);
            if(height[l] < height[r]) {
                ++ l;
            }
            else {
                -- r;
            }
        }
        return ans;
    }
}