import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
public class T2197 {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        Deque<Integer> stack = new ArrayDeque<>();
        int n = nums.length;
        for (int i = 0;i < n;i ++) {
            long val = nums[i];
            while(!stack.isEmpty()) {
                long a = stack.peek();
                BigInteger x = BigInteger.valueOf(a);
                BigInteger y = BigInteger.valueOf(val);
                long z = x.gcd(y).longValue();
                if(z == 1) {
                    break;
                }
                stack.pop();
                val = a * val / z;
            }
            stack.push((int)val);
        }
        while(!stack.isEmpty()) {
            int val = stack.getLast();
            stack.pollLast();
            ans.add(val);
        }
        return ans;
    }
}