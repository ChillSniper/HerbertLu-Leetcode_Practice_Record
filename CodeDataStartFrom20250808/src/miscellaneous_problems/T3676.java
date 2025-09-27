package problems_set;
import java.util.ArrayDeque;
import java.util.Deque;

public class T3676 {
    public long bowlSubarrays(int[] nums) {
        // 这题在赛时想到要用单调栈去处理，但是根本不知从何下手，思路非常混乱
        // 刚刚看了一下题解才知道还得分类讨论
        // 只能说自己太菜了，功力还不够，这玩意真想不出来，还得继续加训
        long ans = 0;
        int n = nums.length;
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 0;i < n;i ++) {
            int x = nums[i];
            while (!st.isEmpty() && nums[st.peek()] <= x) { 
                int val = st.pop();
                if(i - val + 1 >= 3) {
                    ++ ans;
                }
            }
            if (!st.isEmpty() && nums[st.peek()] > x) {
                int val = st.peek();
                if(i - val + 1 >= 3) {
                    ++ ans;
                }
            }
            st.push(i);
        }
        return ans;
    }
}
