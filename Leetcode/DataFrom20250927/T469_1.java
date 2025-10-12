import java.util.*;

public class T469_1 {
    public int[] decimalRepresentation(int n) {
        List<Integer> tmp = new ArrayList<>();
        int p = 1;
        while(n > 0) {
            int t = n % 10;
            n /= 10;
            if(t != 0) {
                tmp.add(t * p);
            }
            p *= 10;
        }
        int sz = tmp.size();
        int[] ans = new int[sz];
        for (int i = 0;i < sz;i ++) {
            ans[i] = tmp.get(sz - 1 - i);
        }
        return ans;
    }
}
