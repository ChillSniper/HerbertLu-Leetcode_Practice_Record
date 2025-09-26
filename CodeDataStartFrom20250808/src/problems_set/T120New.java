package problems_set;
import java.util.List;

public class T120New {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        for (int i = n - 2;i >= 0;i --) {
            for (int j = 0;j <= i;j ++) {
                triangle.get(i).set(j, triangle.get(i).get(j) + Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1)));
            }
        }
        return triangle.get(0).get(0);
    }
}
