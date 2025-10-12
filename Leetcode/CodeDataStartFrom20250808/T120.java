import java.util.List;

public class T120 {
    public int minimumTotal(List<List<Integer>> triangle) {
        // *
        // **
        // ***
        // ****
        // *****
        int n = triangle.size();
        for (int i = 1;i < n;i ++) {
            int ori_first_val = triangle.get(i).get(0);
            triangle.get(i).set(0, triangle.get(i - 1).get(0) + ori_first_val);
            for (int j = 1;j <= i - 1;j ++) {
                int orival = triangle.get(i).get(j);
                int fk_a = triangle.get(i - 1).get(j - 1);
                int fk_b = triangle.get(i - 1).get(j);
                triangle.get(i).set(j, Math.min(fk_a, fk_b) + orival);
            }
            ori_first_val = triangle.get(i).get(i);
            triangle.get(i).set(i, ori_first_val + triangle.get(i - 1).get(i - 1));
        }   
        int ans = Integer.MAX_VALUE;
        for (int j = 0;j < n;j ++) {
            ans = Math.min(ans, triangle.get(n - 1).get(j));
        }
        return ans;
    }
}
