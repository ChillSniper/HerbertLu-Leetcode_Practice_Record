
import java.util.Random;

public class T1317 {
    public int[] getNoZeroIntegers(int n) {
        int[] ans = new int[2];
        Random random = new Random();
        while(true) {
            int x = random.nextInt(n - 1) + 1;
            int y = n - x;
            boolean fx = Judge(x), fy = Judge(y);
            if(fx && fy) {
                ans[0] = x;
                ans[1] = y;
                break;
            }
        }
        return ans;
    }
    public boolean Judge(int x) {
        while(x != 0) {
            int val = x % 10;
            x /= 10;
            if(val == 0) {
                return false;
            }
        }
        return true;
    }
}
