import java.util.ArrayList;
import java.util.List;

public class T300New {
    public int lengthOfLIS(int[] nums) {
        // 我终于想明白了一个事情
        // 对于LIS问题，我们使用“枚举选择哪个”思想去解题
        // 而这一点，在本题中的体现是：选择哪个前驱以构成最长递增子序列？
        // 所构造的g[]并非是形成的最终最长递增子序列，我们所构造的g[i]，实际上是长度为i + 1的数组的min(lastval)
        int n = nums.length;
        List<Integer> g = new ArrayList<>();
        for (int i = 0;i < n;i ++) {
            int r = lower_bound(g, nums[i]);
            if(r >= g.size()) {
                g.add(nums[i]);
            }
            else {
                g.set(r, nums[i]);
            }
        }
        return g.size();
    }
    private int lower_bound(List<Integer> g, int val) {
        int n = g.size(), l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(g.get(mid) < val) {
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return l;
    }
}
