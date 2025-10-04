public class T11 {
    public int maxArea(int[] height) {
        int ans = 0, n = height.length, i = 0, j = n - 1;
        // 为什么会想到从这个角度去贪心呢......
        for (;i < j && i < n && j >= 0;) {
            int val = Math.min(height[i], height[j]) * (j - i);
            ans = Math.max(ans, val);
            if(height[i] < height[j]) {
                ++ i; // 因为如果i不变，后面无论什么值都不会超过ans，height[i]限制了储量的增加
            }
            else {
                -- j;
            }
        }
        return ans;
    }
}
