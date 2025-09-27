package miscellaneous_problems;
import java.util.*;
public class T165_4 {
    public int maxXorSubsequences(int[] nums) {
        // init = 0
        // 这个不太像dp
        // 有点难顶
        // 如果是dp的话，当前状态不会影响此后的状态，但是这边位运算会影响
        // cnmd
        // 那怎么整呢
        // 也许可以sort一下
        // 我忽然想到，如果按照从大到小异或的话，后者所有位加起来都没前者高
        // 所以前者的位要进行保留！
        Arrays.sort(nums);
        int n = nums.length, val = 0;
        for (int i = n - 1;i >= 0;i --) {
            int cur = nums[i];
            if((val ^ cur) >= val) {
                val ^= cur;
            }
        }
        return val;
    }
}
