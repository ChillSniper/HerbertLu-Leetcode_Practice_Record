package miscellaneous_problems;
import java.util.HashSet;
import java.util.Set;

public class T202 {
    public boolean isHappy(int n) {
        Set<Integer>record = new HashSet<>();

        while(!record.contains(n)) {
            if(n == 1)
                return true;
            record.add(n);
            n = f(n);
        }
        return false;

    }
    private int f(int x) {
        int res = 0;
        while(x > 0) {
            int p = x % 10;
            x /= 10;
            res += Math.pow(p, 2);
        }
        return res;
    }
}
